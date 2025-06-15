// src/B4CollisionDetector.cpp

#include "B4CollisionDetector.h"
// #include "B4ConvexHull.h" // B4ConvexHull.h is already included in B4CollisionDetector.h
#include "B4PhysicsTypes.h"  // For CB4HullWorldTriCollideParams, CB4CollidingBody, CB4HullCollideParams, CB4ConvexHullCollideInfo
#include "GtMath.h"          // For GtMathPs2::CGtV3d
#include <cstring> // For memcpy
#include <cstdint> // For uintptr_t
#include <vector> // For std::vector in ClipEdgesByHull
#include <limits> // For std::numeric_limits
#include <cmath>  // For std::abs

// File-scope static for s_hullColInfo, as in C.
// CB4ConvexHullCollideInfo should be defined in B4PhysicsTypes.h or another included header.
static CB4ConvexHullCollideInfo s_hullColInfo;

B4CollisionDetector::B4CollisionDetector() {
    // Constructor
}

B4CollisionDetector::~B4CollisionDetector() {
    // Destructor
}

void B4CollisionDetector::Construct() {
    ConstructConcave();
}

bool B4CollisionDetector::Prepare() {
    return PrepareConcave();
}

void B4CollisionDetector::ConstructConcave() {
    for (int i = 0; i < 2; ++i) {
        m_vehicleFrontHulls[i].Construct();
        m_vehicleMiddleHulls[i].Construct();
        m_vehicleRearHulls[i].Construct();
    }
}

// --- Implementation of GetHullPenetration ---
float B4CollisionDetector::GetHullPenetration(
    const B4ConvexHull* hull,
    GtMathPs2::CGtV3d pointOnHull,
    GtMathPs2::CGtV3d collisionNormal)
{
    if (!hull || !hull->m_offsetPlanes || hull->m_numPlanes == 0) {
        return 0.0f;
    }

    const float initialMaxPenetration = 100.0f;
    GtMathPs2::CGtV3d testPoint = GtMathPs2::Add(pointOnHull, GtMathPs2::MultiplyScalar(collisionNormal, initialMaxPenetration));

    const GtMathPs2::CGtPlane* planes = static_cast<const GtMathPs2::CGtPlane*>(hull->m_offsetPlanes);

    for (unsigned int i = 0; i < hull->m_numPlanes; ++i) {
        const GtMathPs2::CGtPlane& plane = planes[i];

        // Assuming GtPlane stores normal (m_normal) and distance D (m_dist) such that Dot(N,X) + D = 0 is on the plane.
        // Dot(N,X) + D > 0 is "outside" or "in_front".
        // Dot(N,X) + D < 0 is "inside" or "behind".
        float distTestPointToPlane = GtMathPs2::Dot(plane.m_normal, testPoint) + plane.m_dist;
        float distPohToPlane = GtMathPs2::Dot(plane.m_normal, pointOnHull) + plane.m_dist;

        // If testPoint is behind the plane and pointOnHull is in front or on the plane
        if (distTestPointToPlane < 0.0f && distPohToPlane >= 0.0f) {
            float denominator = distPohToPlane - distTestPointToPlane;
            if (std::abs(denominator) > 1e-6f) { // Avoid division by zero or very small numbers
                float t = distPohToPlane / denominator;
                GtMathPs2::CGtV3d segmentDirection = GtMathPs2::Subtract(testPoint, pointOnHull);
                testPoint = GtMathPs2::Add(pointOnHull, GtMathPs2::MultiplyScalar(segmentDirection, t));
            } else {
                // Points are co-planar or segment is parallel to plane; effectively no change to testPoint along this plane.
                // Or, pointOnHull is on the plane, testPoint is also on plane (or very close on other side).
                // If distPohToPlane is 0, t becomes 0, testPoint remains pointOnHull relative to this plane.
            }
        }
    }

    GtMathPs2::CGtV3d penetrationVector = GtMathPs2::Subtract(pointOnHull, testPoint);
    return GtMathPs2::Length(penetrationVector);
}

// --- Implementation of GetCollisionPlane ---
int B4CollisionDetector::GetCollisionPlane(
    CB4HullCollideHullParams* params,
    GtMathPs2::CGtV3d contactPoint,
    GtMathPs2::CGtV3d separatingAxis)
{
    if (!params || !params->m_hullReference) {
        return -1;
    }
    const B4ConvexHull* hull = params->m_hullReference;
    if (!hull->m_offsetPlanes || hull->m_numPlanes == 0) {
        return -1;
    }

    int bestPlaneIndex = -1;
    // We are looking for the plane whose normal is most anti-parallel to the separatingAxis.
    // So, Dot(plane.normal, separatingAxis) should be minimized (most negative).
    float minDotProduct = std::numeric_limits<float>::max();

    const GtMathPs2::CGtPlane* planes = static_cast<const GtMathPs2::CGtPlane*>(hull->m_offsetPlanes);

    for (unsigned int i = 0; i < hull->m_numPlanes; ++i) {
        // In C, IsValidPlane was `params->field_8C[i>>3] & (1 << (i&7))`.
        // Assuming a method `IsValidPlane(index)` exists on CB4HullCollideHullParams for simplicity.
        // If not, this logic would need to be inlined or params would need to expose the raw bitfield.
        if (params->m_validPlaneBitfield && !params->IsValidPlane(i)) { // Check m_validPlaneBitfield exists
            continue;
        }
        const GtMathPs2::CGtPlane& currentPlane = planes[i];

        float N_dot_Axis = GtMathPs2::Dot(currentPlane.m_normal, separatingAxis);

        if (N_dot_Axis < minDotProduct) {
            minDotProduct = N_dot_Axis;
            bestPlaneIndex = static_cast<int>(i);
        }
    }
    // The original C code also involved intersecting a line segment with the chosen plane
    // to find the closest point on the plane. This part is omitted for now as per instructions.
    // If bestPlaneIndex is still -1 (e.g. no valid planes), it will be returned.
    return bestPlaneIndex;
}

// --- Implementation of ClipEdgesByHull ---
unsigned int B4CollisionDetector::ClipEdgesByHull(
    GtMathPs2::CGtV3d* outClippedEdges, int maxOutEdges,
    GtMathPs2::CGtV3d* inVertices, unsigned int numInVertices, // Changed from numInEdgeVertices to numInVertices for clarity
    GtMathPs2::CGtPlane* hullPlanes, unsigned int numHullPlanes)
{
    if (!outClippedEdges || !inVertices || !hullPlanes || maxOutEdges <= 0) {
        return 0;
    }
    if (numInVertices < 2) return 0; // Need at least one edge (meaning at least 2 vertices for a degenerate polygon, 3 for a triangle)

    // Max possible vertices after clipping a convex polygon by N planes is roughly initial_verts + N.
    // Using a generous size for temp buffers.
    std::vector<GtMathPs2::CGtV3d> tempBuffer1(numInVertices + numHullPlanes + 12); // Add margin
    std::vector<GtMathPs2::CGtV3d> tempBuffer2(numInVertices + numHullPlanes + 12);

    GtMathPs2::CGtV3d* currentInputVerts = tempBuffer1.data();
    // Check if inVertices could be tempBuffer1.data() in a recursive call (not the case here but good to be aware of for memcpy)
    if (inVertices != currentInputVerts) {
       memcpy(currentInputVerts, inVertices, numInVertices * sizeof(GtMathPs2::CGtV3d));
    }
    unsigned int currentNumVerts = numInVertices;

    GtMathPs2::CGtV3d* currentOutputVerts = tempBuffer2.data();

    for (unsigned int i = 0; i < numHullPlanes; ++i) {
        if (currentNumVerts < 2) break; // Not enough vertices to form edges for further clipping

        currentNumVerts = ClipEdgesByPlane(currentOutputVerts, currentInputVerts, currentNumVerts, hullPlanes[i]);

        // Swap buffers for next iteration: output of this stage is input to next.
        std::swap(currentInputVerts, currentOutputVerts);
    }

    // After loop, currentInputVerts holds the final polygon vertices.
    unsigned int numToCopy = std::min(currentNumVerts, static_cast<unsigned int>(maxOutEdges));
    if (numToCopy > 0) {
        memcpy(outClippedEdges, currentInputVerts, numToCopy * sizeof(GtMathPs2::CGtV3d));
    }

    return numToCopy;
}


// --- Implementation of ClipEdgesByPlane ---
// This implements Sutherland-Hodgman polygon clipping against a single plane.
// Input is a polygon defined by vertices (inVertices). Output is a new list of vertices (outClippedVertices).
unsigned int B4CollisionDetector::ClipEdgesByPlane(
    GtMathPs2::CGtV3d* outClippedVertices,
    GtMathPs2::CGtV3d* inVertices,
    unsigned int numInVertices,
    const GtMathPs2::CGtPlane& clipPlane)
{
    if (!outClippedVertices || !inVertices || numInVertices == 0) {
        return 0;
    }
    // If numInVertices is 1, it's a point, not a polygon. If 2, it's a line.
    // Sutherland-Hodgman expects a polygon (at least 3 vertices for non-degenerate).
    // However, the C code structure suggests it might process degenerate cases too.
    // For safety, let's proceed even with <3 vertices, as the logic should handle it.

    unsigned int numOutVertices = 0;
    const float epsilon = 1e-5f; // Small epsilon for floating point comparisons: "on the plane"

    // Iterate through edges of the input polygon (currentPoint to nextPoint)
    for (unsigned int i = 0; i < numInVertices; ++i) {
        const GtMathPs2::CGtV3d& currentPoint = inVertices[i];
        const GtMathPs2::CGtV3d& nextPoint = inVertices[(i + 1) % numInVertices]; // Wrap around for the last edge

        // Calculate signed distance from plane. Positive is "inside" (or on positive side of plane).
        float distCurrent = GtMathPs2::Dot(clipPlane.m_normal, currentPoint) + clipPlane.m_dist;
        float distNext = GtMathPs2::Dot(clipPlane.m_normal, nextPoint) + clipPlane.m_dist;

        bool currentInside = distCurrent >= -epsilon; // Treat points very close to plane as inside
        bool nextInside = distNext >= -epsilon;

        // Case 1: Current point inside, Next point inside
        // Add S.E's E (Next Point) to output list
        if (currentInside && nextInside) {
            // Ensure we don't exceed buffer, though caller of ClipEdgesByHull should provide large enough temp.
            // This function itself doesn't know maxOutEdges of the final buffer.
            outClippedVertices[numOutVertices++] = nextPoint;
        }
        // Case 2: Current point inside, Next point outside (Edge crosses from inside to outside)
        // Add intersection point to output list
        else if (currentInside && !nextInside) {
            float denominator = distCurrent - distNext;
            if (std::abs(denominator) > 1e-6f) { // Avoid division by zero
                float t = distCurrent / denominator; // t should be [0,1]
                t = std::max(0.0f, std::min(1.0f, t)); // Clamp t to ensure intersection is on segment
                outClippedVertices[numOutVertices++] = GtMathPs2::Add(currentPoint, GtMathPs2::MultiplyScalar(GtMathPs2::Subtract(nextPoint, currentPoint), t));
            } else {
                // Edge is parallel to plane or very short. If current is inside, technically no intersection to add.
                // Or, if current is inside and next is outside but dists are ~equal, something is odd.
                // Standard SH doesn't add here.
            }
        }
        // Case 3: Current point outside, Next point inside (Edge crosses from outside to inside)
        // Add intersection point, then add S.E's E (Next Point)
        else if (!currentInside && nextInside) {
            float denominator = distCurrent - distNext;
             if (std::abs(denominator) > 1e-6f) {
                float t = distCurrent / denominator; // t should be [0,1]
                t = std::max(0.0f, std::min(1.0f, t)); // Clamp t
                outClippedVertices[numOutVertices++] = GtMathPs2::Add(currentPoint, GtMathPs2::MultiplyScalar(GtMathPs2::Subtract(nextPoint, currentPoint), t));
             }
            outClippedVertices[numOutVertices++] = nextPoint;
        }
        // Case 4: Both points outside - Add nothing
    }
    return numOutVertices;
}

// --- Implementation of SetupParams (Overload 1: CB4CollidingBody, CB4CollidingBody) ---
void B4CollisionDetector::SetupParams(CB4HullCollideParams* params, CB4CollidingBody* body1, CB4CollidingBody* body2, bool flag) {
    if (!params || !body1 || !body2) return;

    // Hull 1 (from body1)
    if (params->m_hull1Params) { // Ensure the container for hull1's params exists
        if (body1->GetHull()) {
            params->m_hull1Params->m_hull = body1->GetHull();
            params->m_hull1Params->m_transform = body1->GetTransform(); // Assumes GetTransform() returns const GtMathPs2::CGtMatrix3x4& or by value
            params->m_hull1Params->m_radius = body1->GetBoundingRadius();
            params->m_hull1Params->m_hullTypeFlags = 0; // Default for generic body
            if (params->m_hull1Params->m_hull && params->m_hull1Params->m_hull->m_numVertices > 0) {
                 params->m_hull1Params->CalculateBounds(); // Assumed method on CB4HullCollideHullParams
            }
        } else {
            params->m_hull1Params->m_hull = nullptr; // Explicitly nullify if body has no hull
        }
    }


    // Hull 2 (from body2)
    if (params->m_hull2Params) { // Ensure the container for hull2's params exists
        if (body2->GetHull()) {
            params->m_hull2Params->m_hull = body2->GetHull();
            params->m_hull2Params->m_transform = body2->GetTransform();
            params->m_hull2Params->m_radius = body2->GetBoundingRadius();
            params->m_hull2Params->m_hullTypeFlags = 0; // Default for generic body
            if (params->m_hull2Params->m_hull && params->m_hull2Params->m_hull->m_numVertices > 0) {
                params->m_hull2Params->CalculateBounds();
            }
        } else {
            params->m_hull2Params->m_hull = nullptr; // Explicitly nullify
        }
    }

    params->m_collisionFlags = flag ? 1 : 0;
    params->m_collidingBody1 = body1;
    params->m_collidingBody2 = body2;
    if (params->m_collisionResult) {
        params->m_collisionResult->m_collided = false;
    }
}

// --- Implementation of SetupParams (Overload 2: CB4VehiclePhysics, CB4ActiveBody) ---
void B4CollisionDetector::SetupParams(CB4HullCollideParams* params, CB4VehiclePhysics* vehicle, CB4ActiveBody* activeBody, bool flag) {
    if (!params || !vehicle || !activeBody) return;

    // Hull 1 (from vehicle)
    if (params->m_hull1Params) {
        if (vehicle->GetHull()) {
            params->m_hull1Params->m_hull = vehicle->GetHull();
            params->m_hull1Params->m_transform = vehicle->GetTransform();
            params->m_hull1Params->m_radius = vehicle->GetBoundingRadius();
            params->m_hull1Params->m_hullTypeFlags = vehicle->GetHullTypeSpecificFlags(); // Assumed method
            if (params->m_hull1Params->m_hull && params->m_hull1Params->m_hull->m_numVertices > 0) {
                params->m_hull1Params->CalculateBounds();
            }
        } else {
            params->m_hull1Params->m_hull = nullptr;
        }
    }


    // Hull 2 (from activeBody)
    if (params->m_hull2Params) {
        if (activeBody->GetConvexHull()) { // ActiveBody might specifically use GetConvexHull
            params->m_hull2Params->m_hull = activeBody->GetConvexHull();
            params->m_hull2Params->m_transform = activeBody->GetTransform();
            params->m_hull2Params->m_radius = activeBody->GetBoundingRadius();
            params->m_hull2Params->m_hullTypeFlags = 0; // Active bodies might not have special type flags here
            if (params->m_hull2Params->m_hull && params->m_hull2Params->m_hull->m_numVertices > 0) {
                params->m_hull2Params->CalculateBounds();
            }
        } else {
             params->m_hull2Params->m_hull = nullptr;
        }
    }

    params->m_collisionFlags = flag ? 1 : 0;
    // Store original types if needed, or just upcast to CB4CollidingBody
    params->m_collidingBody1 = static_cast<CB4CollidingBody*>(vehicle);
    params->m_collidingBody2 = static_cast<CB4CollidingBody*>(activeBody);
    if (params->m_collisionResult) {
        params->m_collisionResult->m_collided = false;
    }
}


// --- Implementation of CollideVehicleWithActiveBody ---
bool B4CollisionDetector::CollideVehicleWithActiveBody(CB4HullCollideParams* params, CB4VehiclePhysics* vehicle, CB4ActiveBody* activeBody, bool flag) {
    if (!params || !vehicle || !activeBody) return false;

    SetupParams(params, vehicle, activeBody, flag);

    // Check if hulls were actually set up (e.g. if GetHull() returned null)
    if (!params->m_hull1Params || !params->m_hull1Params->m_hull || !params->m_hull2Params || !params->m_hull2Params->m_hull) {
        if (params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    if (vehicle->IsConcave()) {
        return CollideConcaveVehicleWithConvexHull(params, true); // Vehicle is Hull1, assumed concave. ActiveBody is Hull2, assumed convex.
                                                                  // 'true' means vehicle (concave) is the first hull in params.
    } else {
        return CollideConvexHulls(params); // Both treated as convex
    }
}

// --- Implementation of CollideVehicles ---
bool B4CollisionDetector::CollideVehicles(CB4HullCollideParams* params, CB4VehiclePhysics* vehicle1, CB4VehiclePhysics* vehicle2, bool flag) {
    if (!params || !vehicle1 || !vehicle2) return false;

    SetupParams(params, static_cast<CB4CollidingBody*>(vehicle1), static_cast<CB4CollidingBody*>(vehicle2), flag);

    if (!params->m_hull1Params || !params->m_hull1Params->m_hull || !params->m_hull2Params || !params->m_hull2Params->m_hull) {
        if (params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    bool v1_is_concave = vehicle1->IsConcave();
    bool v2_is_concave = vehicle2->IsConcave();

    if (v1_is_concave && v2_is_concave) {
        return CollideConcaveVehicles(params);
    } else if (v1_is_concave && !v2_is_concave) {
        // vehicle1 is Hull1 (concave), vehicle2 is Hull2 (convex)
        return CollideConcaveVehicleWithConvexHull(params, true);
    } else if (!v1_is_concave && v2_is_concave) {
        // vehicle1 is Hull1 (convex), vehicle2 is Hull2 (concave)
        // Need to ensure CollideConcaveVehicleWithConvexHull handles which hull is concave.
        // The boolean flag 'useSecondSetOfHulls' might be about which *vehicle* uses its alternate set.
        // Let's assume CollideConcaveVehicleWithConvexHull expects the *first* param hull (m_hull1Params) to be the concave one.
        // If not, we might need to swap them or have a more flexible function.
        // For now, sticking to the pattern: if the second vehicle is the concave one, we tell the function.
        // This implies CollideConcaveVehicleWithConvexHull might internally swap if its 'vehicle' is hull2.
        // Or, the boolean flag indicates which of its *internal* hull arrays to use for *the* vehicle it knows about.
        // The provided signature of CollideConcaveVehicleWithConvexHull is (params, bool useSecondSetOfHulls)
        // This suggests params->m_hull1Params is the vehicle, and params->m_hull2Params is the convex hull.
        // So if vehicle2 is concave, we need to swap them in params before calling.
        // This is getting complex. Let's simplify: assume CollideConcaveVehicleWithConvexHull(params, bool)
        // means: if params->m_hull1 is concave, call with some_flag. If params->m_hull2 is concave, then this function signature is insufficient.
        // Re-evaluating: CollideConcaveVehicleWithConvexHull likely assumes vehicle is hull1.
        // So, if vehicle2 is concave and vehicle1 is not, we need to swap them in the params.
        // This is not ideal. A better approach would be a function like CollideHullPair(hullA, transformA, isConcaveA, hullB, transformB, isConcaveB).
        // Given current structure:
        SetupParams(params, static_cast<CB4CollidingBody*>(vehicle2), static_cast<CB4CollidingBody*>(vehicle1), flag); // vehicle2 (concave) is now hull1
        return CollideConcaveVehicleWithConvexHull(params, true); // vehicle2 (now hull1) is concave.
    } else { // Both convex
        return CollideConvexHulls(params);
    }
}

// --- Implementation of CollideBodyHulls ---
bool B4CollisionDetector::CollideBodyHulls(CB4HullCollideParams* params, CB4CollidingBody* body1, CB4CollidingBody* body2, bool flag) {
    if (!params || !body1 || !body2) return false;

    // Check for vehicle-vehicle case first, as it has specific logic in CollideVehicles
    if (body1->IsVehicleType() && body2->IsVehicleType()) {
        return CollideVehicles(params, static_cast<CB4VehiclePhysics*>(body1), static_cast<CB4VehiclePhysics*>(body2), flag);
    }

    // General setup for other cases (vehicle vs non-vehicle, non-vehicle vs non-vehicle)
    SetupParams(params, body1, body2, flag);

    if (!params->m_hull1Params || !params->m_hull1Params->m_hull || !params->m_hull2Params || !params->m_hull2Params->m_hull) {
         if (params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    bool b1_is_concave = body1->IsVehicleType() ? static_cast<CB4VehiclePhysics*>(body1)->IsConcave() : false;
    bool b2_is_concave = body2->IsVehicleType() ? static_cast<CB4VehiclePhysics*>(body2)->IsConcave() : false;

    if (b1_is_concave && !b2_is_concave) { // Body1 is concave (must be vehicle), Body2 is convex
        return CollideConcaveVehicleWithConvexHull(params, true); // Body1 (vehicle) is Hull1
    } else if (!b1_is_concave && b2_is_concave) { // Body1 is convex, Body2 is concave (must be vehicle)
        // Swap body1 and body2 in params so that the concave one (body2) is Hull1
        SetupParams(params, body2, body1, flag); // body2 (concave) is now Hull1
        return CollideConcaveVehicleWithConvexHull(params, true); // Body2 (now Hull1) is concave
    } else if (b1_is_concave && b2_is_concave) {
        // Both are concave. This implies both are vehicles, which should have been caught by the first 'if'.
        // If it reaches here, it's an unusual case or one/both are not vehicles but flagged as concave.
        // Defaulting to CollideConcaveVehicles, which assumes vehicle-specific structures.
        return CollideConcaveVehicles(params);
    } else { // Both convex (or treated as such)
        return CollideConvexHulls(params);
    }
}

// --- Implementation of CollideBodyHullWithWorld ---
bool B4CollisionDetector::CollideBodyHullWithWorld(CB4HullWorldTriCollideParams* worldParams, CB4CollidingBody* body) {
    if (!worldParams || !body) return false;

    // Populate the hull-specific part of worldParams from body
    if (worldParams->m_hullParams) { // m_hullParams is like one half of CB4HullCollideParams
        if (body->GetHull()) {
            worldParams->m_hullParams->m_hull = body->GetHull();
            worldParams->m_hullParams->m_transform = body->GetTransform();
            worldParams->m_hullParams->m_radius = body->GetBoundingRadius(); // Assuming this is useful for world collisions too
            if (body->IsVehicleType()) {
                 worldParams->m_hullParams->m_hullTypeFlags = static_cast<CB4VehiclePhysics*>(body)->GetHullTypeSpecificFlags();
            } else {
                worldParams->m_hullParams->m_hullTypeFlags = 0;
            }
            if (worldParams->m_hullParams->m_hull && worldParams->m_hullParams->m_hull->m_numVertices > 0) {
                worldParams->m_hullParams->CalculateBounds();
            }
        } else {
            worldParams->m_hullParams->m_hull = nullptr;
            if(worldParams->m_collisionResult) worldParams->m_collisionResult->m_collided = false; // No hull, no collision
            return false;
        }
    } else {
        // m_hullParams itself is null, cannot proceed
        if(worldParams->m_collisionResult) worldParams->m_collisionResult->m_collided = false;
        return false;
    }

    bool is_concave_vehicle = false;
    if (body->IsVehicleType()) {
        if (static_cast<CB4VehiclePhysics*>(body)->IsConcave()) {
            is_concave_vehicle = true;
        }
    }

    if (is_concave_vehicle) {
        return CollideConcaveVehicleWithWorld(worldParams, static_cast<CB4VehiclePhysics*>(body));
    } else {
        // This function was already implemented in a previous step.
        return CollideBodyConvexHullWithWorld(worldParams, body);
    }
}

// --- Implementation of BoxBoxCollision (static) ---
bool B4CollisionDetector::BoxBoxCollision(
    const CGtAxisAlignedBox& box1, const GtMathPs2::CGtMatrix3x4& transform1,
    const CGtAxisAlignedBox& box2, const GtMathPs2::CGtMatrix3x4& transform2,
    const GtMathPs2::CGtMatrix3x4* relativeTransform,
    float* outOverlap, GtMathPs2::CGtV3d* outMTV, GtMathPs2::CGtV3d* outNormal)
{
    // Stub: returns false (no collision) to allow main collision logic path.
    // Full SAT OBB-OBB is complex.
    if (outOverlap) *outOverlap = 0.0f;
    if (outMTV) *outMTV = GtMathPs2::CGtV3d(0.f,0.f,0.f,0.f); // Default to zero vector
    if (outNormal) *outNormal = GtMathPs2::CGtV3d(0.f,1.f,0.f,0.f); // Default to Y-axis
    return false;
}

// --- Implementation of DoCollideHullTriangles ---
bool B4CollisionDetector::DoCollideHullTriangles(CB4HullWorldTriCollideParams* params, CB4ConvexHullCollideInfo* collInfo) {
    if (!params || !collInfo || !params->m_hullParams || !params->m_hullParams->m_hull || !params->m_triangles) {
        if (collInfo) collInfo->Reset(); // Ensure collInfo is reset even on early exit
        return false;
    }

    const B4ConvexHull* hull = params->m_hullParams->m_hull;
    collInfo->Reset(); // Assuming a Reset method that zeros out members

    bool anyCollisionOverall = false;

    for (unsigned int i = 0; i < params->m_numTriangles; ++i) {
        // Construct triangle vertices (assuming GtTriנג is available or similar structure)
        // For now, directly using params->m_triangles[i].v0, v1, v2
        const GtMathPs2::CGtV3d triangleVerts[3] = {
            params->m_triangles[i].v0,
            params->m_triangles[i].v1,
            params->m_triangles[i].v2,
        };

        // TODO: Placeholder for actual Triangle vs Convex Hull intersection test.
        // The C code calls GtIntersection::ClipPolyWithConvexHull.
        // This is a complex function. For now, we'll simulate a simplified check.

        bool currentTriangleCollided = false;
        GtMathPs2::CGtV3d contactPointAvgOnTriangle; // Point on triangle
        float penetrationDepthFromTriangle = 0.0f;
        GtMathPs2::CGtV3d collisionNormalFromHull;   // Normal of the hull at point of impact

        // Simplified placeholder: Check if triangle's centroid is "inside" the hull using planes
        // This is NOT a correct collision test but a placeholder for the clipping + penetration logic.
        GtMathPs2::CGtV3d centroid = GtMathPs2::MultiplyScalar(GtMathPs2::Add(GtMathPs2::Add(triangleVerts[0], triangleVerts[1]), triangleVerts[2]), 1.0f/3.0f);

        bool potentiallyColliding = true; // Assume potential collision to enter more detailed (but still placeholder) checks

        // Check against hull AABB as a broad phase (if m_hullParams->m_aabb is reliable)
        if (!params->m_hullParams->m_aabb.Contains(centroid)) {
            potentiallyColliding = false;
        }

        if (potentiallyColliding) {
            // More refined placeholder: Check centroid against hull planes
            // A real implementation would clip the triangle polygon against the hull.
            // For now, if centroid is inside all planes, we simulate a collision.
            bool insideAllPlanes = true;
            const GtMathPs2::CGtPlane* hullPlanes = static_cast<const GtMathPs2::CGtPlane*>(hull->m_offsetPlanes);
            if (!hullPlanes) insideAllPlanes = false;

            for (unsigned int planeIdx = 0; hullPlanes && planeIdx < hull->m_numPlanes; ++planeIdx) {
                if ( (GtMathPs2::Dot(hullPlanes[planeIdx].m_normal, centroid) + hullPlanes[planeIdx].m_dist) < -1e-4f) { // Small epsilon
                    insideAllPlanes = false;
                    break;
                }
            }

            if (insideAllPlanes) {
                currentTriangleCollided = true;
                contactPointAvgOnTriangle = centroid;

                // Find closest plane of hull to this contact point to define normal and depth (very simplified)
                float minDistToPlane = std::numeric_limits<float>::max();
                int closestPlaneIdx = -1;

                for (unsigned int planeIdx = 0; hullPlanes && planeIdx < hull->m_numPlanes; ++planeIdx) {
                    float dist = GtMathPs2::Dot(hullPlanes[planeIdx].m_normal, contactPointAvgOnTriangle) + hullPlanes[planeIdx].m_dist;
                    if (dist < minDistToPlane) { // Point is "most behind" this plane or least in front
                        minDistToPlane = dist;
                        closestPlaneIdx = planeIdx;
                    }
                }
                if (closestPlaneIdx != -1) {
                    collisionNormalFromHull = hullPlanes[closestPlaneIdx].m_normal; // Hull's plane normal
                    penetrationDepthFromTriangle = -minDistToPlane; // Penetration is how much "behind" it is
                    if (penetrationDepthFromTriangle < 0.0f) penetrationDepthFromTriangle = 0.0f; // clamp if it's not actually penetrating
                } else { // Should not happen if insideAllPlanes and numPlanes > 0
                     currentTriangleCollided = false; // No valid plane found
                }

                // Use provided effective hull normal if overridden
                if (params->m_hullNormalOverridden) {
                    collisionNormalFromHull = params->m_effectiveHullNormal;
                    // Penetration depth along this normal would require projecting contactPointAvgOnTriangle onto a plane
                    // defined by m_effectiveHullNormal and some point on hull. This is getting too complex for placeholder.
                    // So, if normal is overridden, the depth calculation above might be inconsistent.
                }
            }
        }


        if (currentTriangleCollided && penetrationDepthFromTriangle > 0.0f) {
            anyCollisionOverall = true;
            // Accumulate into collInfo
            if (penetrationDepthFromTriangle > collInfo->m_deepestPenetration) {
                collInfo->m_deepestPenetration = penetrationDepthFromTriangle;
                collInfo->m_contactPointWorld = contactPointAvgOnTriangle;
                collInfo->m_penetrationNormalWorld = collisionNormalFromHull;
                // collInfo->m_triangleIndex = i; // If needed
            }
            collInfo->m_numContactPoints++;
        }
    }

    if (anyCollisionOverall) {
        // Populate params with results from collInfo
        params->m_finalContactPoint = collInfo->m_contactPointWorld; // This should be in world space
        params->m_finalPenetrationNormal = collInfo->m_penetrationNormalWorld; // World space
        params->m_finalPenetrationDepth = collInfo->m_deepestPenetration;
        // params->m_material1 = hull->m_material; // Or however material is obtained
        // params->m_material2 = params->m_triangles[collInfo->m_triangleIndex].m_material; // If triangle has material
        if(params->m_collisionResult) params->m_collisionResult->m_collided = true; // If CB4HullWorldTriCollideParams has a result struct
        return true;
    }

    if(params->m_collisionResult) params->m_collisionResult->m_collided = false;
    return false;
}

// --- Implementation of CollideConcaveVehicleWithWorld ---
bool B4CollisionDetector::CollideConcaveVehicleWithWorld(CB4HullWorldTriCollideParams* params, CB4VehiclePhysics* vehicle) {
    if (!params || !vehicle || !vehicle->GetHullDefinition() || !params->m_hullParams ) {
        if(params && params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    CB4AccHullParams accResults;
    accResults.Reset();

    SetupVehicleHulls(0, vehicle->GetHullDefinition()); // Vehicle uses hull set 0

    B4ConvexHull* vehicleParts[] = {
        &m_vehicleFrontHulls[0],
        &m_vehicleMiddleHulls[0],
        &m_vehicleRearHulls[0]
    };

    bool anyPartCollided = false;
    CB4CollidingBody* vehicleAsCollidingBody = static_cast<CB4CollidingBody*>(vehicle);

    // Store original hull params from input, to restore if they are changed by CollideBodyConvexHullWithWorld
    // B4ConvexHull* originalHullInParams = params->m_hullParams->m_hull;
    // GtMathPs2::CGtMatrix3x4 originalTransformInParams = params->m_hullParams->m_transform;
    // float originalRadiusInParams = params->m_hullParams->m_radius;
    // unsigned int originalFlagsInParams = params->m_hullParams->m_hullTypeFlags;
    // CGtAABB originalAABBInParams = params->m_hullParams->m_aabb;


    for (int i = 0; i < 3; ++i) {
        params->m_hullParams->m_hull = vehicleParts[i];
        // Transform for individual parts might be relative to vehicle's main transform.
        // For now, SetupVehicleHulls sets m_transform on parts to be same as definition.
        // If parts have their own transforms relative to vehicle root, this needs adjustment.
        // We assume CollideBodyConvexHullWithWorld uses params->m_hullParams->m_transform for the hull.
        // And vehicle's GetTransform() for the body.
        // If vehicleParts[i]->m_transform is absolute, then it should be fine.
        // If vehicleParts[i]->m_transform is relative to vehicle, then body's transform should be identity or part transform made absolute.
        // For now, assume SetupVehicleHulls sets absolute transforms on parts if they differ from main body transform.
        // Or, that vehicle->GetTransform() is the one that matters and part geometry is already in that space.
        params->m_hullParams->m_transform = vehicle->GetTransform(); // Use main vehicle transform for all parts
        params->m_hullParams->m_radius = vehicleParts[i]->m_radius; // Use part's specific radius
        params->m_hullParams->m_hullTypeFlags = vehicle->GetHullTypeSpecificFlags(); // Main vehicle flags

        if (params->m_hullParams->m_hull && params->m_hullParams->m_hull->m_numVertices > 0) {
             params->m_hullParams->CalculateBounds();
        } else {
            continue; // Skip part if hull is invalid
        }

        if (CollideBodyConvexHullWithWorld(params, vehicleAsCollidingBody)) { // Pass the main vehicle body
            anyPartCollided = true;
            accResults.AddCollision(params->m_finalContactPoint, params->m_finalPenetrationNormal, params->m_finalPenetrationDepth, params->m_material1, params->m_material2);
        }
    }

    // Restore original values to params->m_hullParams if they were changed and need restoration
    // params->m_hullParams->m_hull = originalHullInParams;
    // params->m_hullParams->m_transform = originalTransformInParams;
    // params->m_hullParams->m_radius = originalRadiusInParams;
    // params->m_hullParams->m_hullTypeFlags = originalFlagsInParams;
    // params->m_hullParams->m_aabb = originalAABBInParams;
    // params->m_hullParams->CalculateBounds(); // if needed


    if (anyPartCollided) {
        params->m_finalContactPoint = accResults.GetAverageContactPoint();
        params->m_finalPenetrationNormal = accResults.GetAverageNormal();
        params->m_finalPenetrationDepth = accResults.GetMaxPenetration();
        // params->m_material1 = accResults.GetMaterial1(); // Or however combined material is decided
        // params->m_material2 = accResults.GetMaterial2();
        if(params->m_collisionResult) params->m_collisionResult->m_collided = true;
        return true;
    }

    if(params->m_collisionResult) params->m_collisionResult->m_collided = false;
    return false;
}

// --- Implementation of CollideConcaveVehicleWithConvexHull ---
bool B4CollisionDetector::CollideConcaveVehicleWithConvexHull(CB4HullCollideParams* params, bool firstHullIsTheConcaveVehicle) {
    if (!params || !params->m_hull1Params || !params->m_hull2Params || !params->m_collidingBody1 || !params->m_collidingBody2) {
         if(params && params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    CB4VehiclePhysics* concaveVehicle = nullptr;
    CB4HullCollideHullParams* vehicleHullParams = nullptr;
    CB4HullCollideHullParams* convexTargetParams = nullptr;
    int vehicleHullSetIndex = 0;

    if (firstHullIsTheConcaveVehicle) {
        if (!params->m_collidingBody1->IsVehicleType()) return false;
        concaveVehicle = static_cast<CB4VehiclePhysics*>(params->m_collidingBody1);
        vehicleHullParams = params->m_hull1Params;
        convexTargetParams = params->m_hull2Params;
        vehicleHullSetIndex = 0; // Vehicle in m_hull1Params uses set 0
    } else { // Second hull is the concave vehicle
        if (!params->m_collidingBody2->IsVehicleType()) return false;
        concaveVehicle = static_cast<CB4VehiclePhysics*>(params->m_collidingBody2);
        vehicleHullParams = params->m_hull2Params; // Vehicle parts will be set here
        convexTargetParams = params->m_hull1Params; // Convex target is here
        vehicleHullSetIndex = 1; // Vehicle in m_hull2Params uses set 1
    }

    if (!concaveVehicle || !concaveVehicle->GetHullDefinition() || !convexTargetParams->m_hull) {
        if(params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    SetupVehicleHulls(vehicleHullSetIndex, concaveVehicle->GetHullDefinition());

    B4ConvexHull* vehicleParts[] = {
        &m_vehicleFrontHulls[vehicleHullSetIndex],
        &m_vehicleMiddleHulls[vehicleHullSetIndex],
        &m_vehicleRearHulls[vehicleHullSetIndex]
    };

    const B4ConvexHull* originalVehicleHullPtr = vehicleHullParams->m_hull; // Store original full hull
    // The transform and radius on vehicleHullParams should remain that of the overall vehicle.
    // The CalculateBounds will use the geometry of the part with the overall vehicle's transform.

    bool anyPartCollided = false;
    CB4AccHullParams accResults;
    accResults.Reset();

    for (int i = 0; i < 3; ++i) {
        vehicleHullParams->m_hull = vehicleParts[i]; // Set current vehicle part
        if (vehicleHullParams->m_hull && vehicleHullParams->m_hull->m_numVertices > 0) {
            vehicleHullParams->CalculateBounds(); // Recalculate bounds for this specific part using vehicle's main transform
        } else {
            continue; // Skip invalid part
        }

        // Ensure convexTargetParams bounds are up-to-date (usually set once at SetupParams)
        // convexTargetParams->CalculateBounds(); // This should have been done in SetupParams

        if (CollideConvexHulls(params)) {
            anyPartCollided = true;
            accResults.AddCollision(*params->m_collisionResult); // Assuming AddCollision takes CB4CollisionResult
        }
    }

    vehicleHullParams->m_hull = originalVehicleHullPtr; // Restore original hull pointer
    // vehicleHullParams->CalculateBounds(); // Optionally recalculate for original full hull

    if (anyPartCollided) {
        if(params->m_collisionResult) {
            params->m_collisionResult->m_collided = true;
            // Finalize overall collision from accResults into params->m_collisionResult
            params->m_collisionResult->m_contactPoint = accResults.GetAverageContactPoint();
            params->m_collisionResult->m_normal = accResults.GetAverageNormal();
            params->m_collisionResult->m_depth = accResults.GetMaxPenetration();
            // params->m_collisionResult->m_material1 = accResults.GetMaterial1();
            // params->m_collisionResult->m_material2 = accResults.GetMaterial2();
        }
        return true;
    }

    if(params->m_collisionResult) params->m_collisionResult->m_collided = false;
    return false;
}

// --- Implementation of CollideConcaveVehicles ---
bool B4CollisionDetector::CollideConcaveVehicles(CB4HullCollideParams* params) {
    if (!params || !params->m_collidingBody1 || !params->m_collidingBody2 ||
        !params->m_collidingBody1->IsVehicleType() || !params->m_collidingBody2->IsVehicleType() ||
        !params->m_hull1Params || !params->m_hull2Params) {
        if(params && params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    CB4VehiclePhysics* vehicle1 = static_cast<CB4VehiclePhysics*>(params->m_collidingBody1);
    CB4VehiclePhysics* vehicle2 = static_cast<CB4VehiclePhysics*>(params->m_collidingBody2);

    if (!vehicle1->GetHullDefinition() || !vehicle2->GetHullDefinition()){
        if(params->m_collisionResult) params->m_collisionResult->m_collided = false;
        return false;
    }

    SetupVehicleHulls(0, vehicle1->GetHullDefinition());
    SetupVehicleHulls(1, vehicle2->GetHullDefinition());

    B4ConvexHull* vehicle1Parts[] = { &m_vehicleFrontHulls[0], &m_vehicleMiddleHulls[0], &m_vehicleRearHulls[0] };
    B4ConvexHull* vehicle2Parts[] = { &m_vehicleFrontHulls[1], &m_vehicleMiddleHulls[1], &m_vehicleRearHulls[1] };

    const B4ConvexHull* originalHull1 = params->m_hull1Params->m_hull;
    const B4ConvexHull* originalHull2 = params->m_hull2Params->m_hull;

    bool anyCollision = false;
    CB4AccHullParams accResults;
    accResults.Reset();

    for (int i = 0; i < 3; ++i) {
        params->m_hull1Params->m_hull = vehicle1Parts[i];
        if (params->m_hull1Params->m_hull && params->m_hull1Params->m_hull->m_numVertices > 0) {
            params->m_hull1Params->CalculateBounds();
        } else {
            continue; // Skip invalid part for vehicle1
        }

        for (int j = 0; j < 3; ++j) {
            params->m_hull2Params->m_hull = vehicle2Parts[j];
            if (params->m_hull2Params->m_hull && params->m_hull2Params->m_hull->m_numVertices > 0) {
                params->m_hull2Params->CalculateBounds();
            } else {
                continue; // Skip invalid part for vehicle2
            }

            if (CollideConvexHulls(params)) {
                anyCollision = true;
                accResults.AddCollision(*params->m_collisionResult);
            }
        }
    }

    params->m_hull1Params->m_hull = originalHull1;
    params->m_hull2Params->m_hull = originalHull2;
    // if (originalHull1) params->m_hull1Params->CalculateBounds();
    // if (originalHull2) params->m_hull2Params->CalculateBounds();


    if (anyCollision) {
        if(params->m_collisionResult) {
            params->m_collisionResult->m_collided = true;
            params->m_collisionResult->m_contactPoint = accResults.GetAverageContactPoint();
            params->m_collisionResult->m_normal = accResults.GetAverageNormal();
            params->m_collisionResult->m_depth = accResults.GetMaxPenetration();
            // params->m_collisionResult->m_material1 = accResults.GetMaterial1();
            // params->m_collisionResult->m_material2 = accResults.GetMaterial2();
        }
        return true;
    }

    if(params->m_collisionResult) params->m_collisionResult->m_collided = false;
    return false;
}

bool B4CollisionDetector::PrepareConcave() {
    for (int i = 0; i < 2; ++i) {
        B4ConvexHull* frontHull = &m_vehicleFrontHulls[i];
        B4ConvexHull* middleHull = &m_vehicleMiddleHulls[i];
        B4ConvexHull* rearHull = &m_vehicleRearHulls[i];

        frontHull->Prepare();
        middleHull->Prepare();
        rearHull->Prepare();

        frontHull->m_numVertices = 8;
        frontHull->m_numEdges = 12;
        frontHull->m_numPlanes = 6;

        unsigned char c_face_data[] = {
            0,2,3,1, 4,0,1,5, 4,6,2,0,
            1,3,7,5, 2,6,7,3, 5,7,6,4
        };
        // Assuming m_offsetFaces is a pointer to a buffer of sufficient size.
        // The task description implies B4ConvexHull::Prepare() would allocate this.
        if (frontHull->m_offsetFaces) {
            memcpy(frontHull->m_offsetFaces, c_face_data, sizeof(c_face_data));
        }

        unsigned char c_edge_data[] = {
            0,1,  5,4,  4,0,  5,1,  2,3,  7,6,
            6,2,  7,3,  2,0,  3,1,  6,4,  7,5
        };
        // Assuming m_offsetEdges is a pointer to a buffer of sufficient size.
        if (frontHull->m_offsetEdges) {
            memcpy(frontHull->m_offsetEdges, c_edge_data, sizeof(c_edge_data));
        }

        // Copy face data to middle and rear hulls
        if (frontHull->m_offsetFaces && middleHull->m_offsetFaces && rearHull->m_offsetFaces) {
            memcpy(middleHull->m_offsetFaces, frontHull->m_offsetFaces, sizeof(c_face_data));
            memcpy(rearHull->m_offsetFaces, frontHull->m_offsetFaces, sizeof(c_face_data));
        }

        // Copy edge data to middle and rear hulls
        if (frontHull->m_offsetEdges && middleHull->m_offsetEdges && rearHull->m_offsetEdges) {
            memcpy(middleHull->m_offsetEdges, frontHull->m_offsetEdges, sizeof(c_edge_data));
            memcpy(rearHull->m_offsetEdges, frontHull->m_offsetEdges, sizeof(c_edge_data));
        }

        middleHull->m_numVertices = 8;
        middleHull->m_numEdges = 12;
        middleHull->m_numPlanes = 6;

        rearHull->m_numVertices = 8;
        rearHull->m_numEdges = 12;
        rearHull->m_numPlanes = 6;
    }
    return true;
}

// --- Implementation of SetupVehicleHulls ---
void B4CollisionDetector::SetupVehicleHulls(int hullSetIndex, const B4ConvexHull* vehicleHullDataSourceDefinition) {
    if (hullSetIndex < 0 || hullSetIndex >= 2 || !vehicleHullDataSourceDefinition) {
        // It's good practice to handle invalid input, though original C might not.
        return;
    }

    B4ConvexHull* destHullParts[] = {
        &m_vehicleFrontHulls[hullSetIndex],
        &m_vehicleMiddleHulls[hullSetIndex],
        &m_vehicleRearHulls[hullSetIndex]
    };

    const void* sourceVerticesBuffer = vehicleHullDataSourceDefinition->m_offsetVertices;
    const void* sourcePlanesDefinitionBuffer = vehicleHullDataSourceDefinition->m_offsetPlanes; // Base pointer for planes from definition

    // These are byte offsets. For m_offsetPlanes, it's an offset to the *pointer value* itself if planes were contiguous.
    // However, the decompiled code suggests vehicleHullDataSourceWords[2] is the direct pointer for the first hull part's planes.
    // And for subsequent parts, it's likely an offset *from that initial pointer*.
    // If vehicleHullDataSourceDefinition->m_offsetPlanes points to the start of plane data for the *entire vehicle model definition*,
    // then these offsets are into that block of plane data.
    const size_t vertexOffsets[] = {0, 64, 128}; // Byte offsets into sourceVerticesBuffer (assuming CGtV3d is 16 bytes, 8 vertices per part = 128 bytes, so 64 is for 4 vertices if sizes differ)
                                                 // The original C decompiled code implies these are direct offsets for memcpy.
                                                 // Given 8 vertices * 16 bytes/vertex = 128 bytes per hull part.
                                                 // If sourceVerticesBuffer points to a contiguous block for 3x8 vertices:
                                                 // Front: offset 0
                                                 // Middle: offset 128 (8*16)
                                                 // Rear: offset 256 (16*16)
                                                 // The provided 0, 64, 128 are unusual if each part has 8 vertices.
                                                 // Let's assume 8 vertices for now as per PrepareConcave and adjust if B4ConvexHull structure dictates otherwise.
                                                 // For now, using the provided 0, 64, 128 byte offsets.

    const size_t planePointerOffsets[] = {0, 48, 96}; // Byte offsets to adjust the sourcePlanesDefinitionBuffer pointer
                                                    // GtPlane is 16 bytes. If each hull has 6 planes, this is 6*16 = 96 bytes per hull.
                                                    // Front: offset 0
                                                    // Middle: offset 96 (6*16)
                                                    // Rear: offset 192 (12*16)
                                                    // The provided 0, 48, 96 are unusual if each part has 6 planes.
                                                    // These might be indices or dword offsets in the original _DWORD* access.
                                                    // Let's assume these are byte offsets into a contiguous block of GtPlanes.

    // Assuming 8 vertices (GtMathPs2::CGtV3d is typically 16 bytes on PS2 due to VEC component)
    const size_t verticesBlockSize = 8 * sizeof(GtMathPs2::CGtV3d); // = 8 * 16 = 128 bytes

    for (int i = 0; i < 3; ++i) { // 0:Front, 1:Middle, 2:Rear
        B4ConvexHull* currentDestHull = destHullParts[i];

        // Copy GtTransform, GtAABB, and radius directly from the source definition.
        // This implies these are for the whole vehicle, or the front part, and shared.
        currentDestHull->m_transform = vehicleHullDataSourceDefinition->m_transform;
        currentDestHull->m_aabb = vehicleHullDataSourceDefinition->m_aabb;
        currentDestHull->m_radius = vehicleHullDataSourceDefinition->m_radius;

        // The m_offsetPlanes for each destination hull part (front, middle, rear)
        // becomes a pointer that is offset from the source definition's m_offsetPlanes.
        currentDestHull->m_offsetPlanes = (void*)( (uintptr_t)sourcePlanesDefinitionBuffer + planePointerOffsets[i] );

        // Copy the actual vertex data from the large source buffer into this specific hull part's vertex buffer.
        // It's assumed m_offsetVertices in each destHullPart points to an allocated buffer of at least verticesBlockSize.
        if (currentDestHull->m_offsetVertices && sourceVerticesBuffer) {
            memcpy(currentDestHull->m_offsetVertices,
                   static_cast<const unsigned char*>(sourceVerticesBuffer) + vertexOffsets[i],
                   verticesBlockSize); // Assuming each part has 8 vertices and thus needs 128 bytes.
        } else {
            // Error: Destination or source vertex buffer is null.
        }

        // Call CalculatePlaneData for the hull part with specific index/flag
        // The flags (0 and 5) are based on decompiled analysis and might represent specific calculation modes.
        if (i == 0) { // Front hull
            currentDestHull->CalculatePlaneData(5);
        } else if (i == 1) { // Middle hull
            currentDestHull->CalculatePlaneData(0);
            currentDestHull->CalculatePlaneData(5);
        } else { // Rear hull (i == 2)
            currentDestHull->CalculatePlaneData(0);
        }
    }
}

// --- Implementation of CollideBodyConvexHullWithWorld ---
bool B4CollisionDetector::CollideBodyConvexHullWithWorld(CB4HullWorldTriCollideParams* params, CB4CollidingBody* body) {
    if (!params || !body) {
        return false;
    }

    // These struct member names (m_useAlternateNormal, m_effectiveHullNormal, etc.) are assumed based on plan.
    // Actual names must match definitions in B4PhysicsTypes.h.
    if (body->m_useAlternateNormal) {
        params->m_effectiveHullNormal = params->m_hullNormalSourceVec;
    } else {
        // Original C: _$V0 = body->field_500 (m_physicsObjectData);
        //             lqc2 $vf1, 0x20($v0);       // load vector from m_physicsObjectData + 0x20
        //             vsub.xyz $vf1, $vf0, $vf1;  // negate it (vf0 is zero vector)
        //             sqc2 $vf1, params->field_140 (m_effectiveHullNormal)
        // This complex logic depends on the unknown structure of body->m_physicsObjectData.
        // It's commented out because it cannot be accurately translated yet.
        // A robust implementation would require B4CollidingBody and its related types to be defined.
        /*
        if (body->m_physicsObjectData) {
            // Conceptual:
            // GtMathPs2::CGtV3d* vecFromBody = reinterpret_cast<GtMathPs2::CGtV3d*>(static_cast<char*>(body->m_physicsObjectData) + 0x20);
            // params->m_effectiveHullNormal = GtMathPs2::Negate(*vecFromBody); // Or -(*vecFromBody) if operator- is defined
        } else {
            // Fallback if m_physicsObjectData is null, or if the above logic is too complex for now
            // params->m_effectiveHullNormal = GtMathPs2::CGtV3d(0.0f, 0.0f, 0.0f); // Or some other default
        }
        */
       // For now, if not using alternate normal, we might set a default or leave it as is,
       // depending on how m_effectiveHullNormal is initialized or used later.
       // The original code implies it *is* set, so a placeholder might be needed if the real logic is deferred.
       // Let's assume it's default-initialized or handled by DoCollideHullTriangles if not overridden.
    }

    params->m_hullNormalOverridden = body->m_useAlternateNormal;

    // s_hullColInfo needs to be reset or initialized if it carries state between calls,
    // but typically such static structs are used as temporary output/input for a single call.
    // memset(&s_hullColInfo, 0, sizeof(CB4ConvexHullCollideInfo)); // Optional: clear before use
    return DoCollideHullTriangles(params, &s_hullColInfo);
}

// --- Implementation of CollideConvexHulls ---
bool B4CollisionDetector::CollideConvexHulls(CB4HullCollideParams* params) {
    if (!params) {
        return false;
    }

    // The original C code includes debug paths using gDebugManager and BoxBoxCollision
    // as an early out. These are omitted here for initial implementation simplicity.
    // The non-debug path directly calls DoCollideConvexHullToHull.
    return DoCollideConvexHullToHull(params);
}

// --- Implementation of DoCollideConvexHullToHull (Stub) ---
bool B4CollisionDetector::DoCollideConvexHullToHull(CB4HullCollideParams* params) {
    if (!params) {
        // Or handle error appropriately
        return false;
    }

    // TODO: Full implementation of Separating Axis Theorem (SAT) and contact manifold generation.
    // This function is highly complex and involves detailed geometric calculations,
    // vertex transformations, axis projections, and potentially clipping algorithms
    // (which call helpers like BuildClippedEdgeList, ClipEdgesByHull).
    // For now, it returns false, indicating no collision.
    // A proper implementation will be a significant undertaking.

    // Example of what would be needed:
    // 1. Access hulls and transforms from params:
    //    const B4ConvexHull* hull1 = nullptr; // params->GetHull1(); // Assuming getter methods
    //    const B4ConvexHull* hull2 = nullptr; // params->GetHull2();
    //    const GtMathPs2::CGtMatrix3x4 transform1; // = params->GetTransform1();
    //    const GtMathPs2::CGtMatrix3x4 transform2; // = params->GetTransform2();
    //
    // 2. Transform hull vertices into a common space or work with relative transforms.
    //
    // 3. Iterate through potential separating axes:
    //    - Face normals of hull1
    //    - Face normals of hull2
    //    - Cross products of edges from hull1 and hull2
    //
    // 4. For each axis:
    //    - Project both hulls onto the axis.
    //    - If the projected intervals do not overlap, a separating axis is found; return false.
    //
    // 5. If no separating axis is found, hulls are colliding.
    //    - Calculate penetration depth and axis.
    //    - Determine contact points/manifold (this is where clipping often occurs).
    //    - Populate collision result fields in 'params'.
    //    - Return true.

    return false; // Stub implementation
}

// --- Implementation of BuildClippedEdgeList ---
void B4CollisionDetector::BuildClippedEdgeList(
    GtMathPs2::CGtV3d* outEdgePoints, unsigned int* outNumEdgePoints,
    GtMathPs2::CGtV3d clipPlaneNormal,
    const B4ConvexHull* hull,
    GtMathPs2::CGtV3d* hullVerticesTransformed)
{
    if (!outEdgePoints || !outNumEdgePoints || !hull || !hullVerticesTransformed) {
        if (outNumEdgePoints) *outNumEdgePoints = 0;
        return;
    }

    *outNumEdgePoints = 0;
    // Epsilon for floating point comparisons related to being "on the plane"
    const float epsilon = -1e-6f; // Use a small negative epsilon if "inside" means dot_product >= 0

    // Ensure hull has vertices and m_offsetVertices is valid (though hullVerticesTransformed is used directly)
    if (hull->m_numVertices == 0 || !hull->m_offsetEdges) { // Also check m_offsetEdges
        return;
    }

    // Dynamically sized array or std::vector would be safer if MAX_VERTICES is not reliable/available.
    // For now, assuming hull->m_numVertices is reasonably small for a stack array.
    // Max typical vertices for a simple hull part might be small (e.g., 8-32).
    // Using a fixed reasonably sized array for dot products on stack.
    // If hull->m_numVertices can be very large, this needs to be dynamic.
    if (hull->m_numVertices > 256) { /* Potentially too many vertices for stack allocation, consider heap or error */ return; }
    float dotProducts[256]; // Max 256 vertices for dot product temp storage. Ensure this is safe.


    for (unsigned int i = 0; i < hull->m_numVertices; ++i) {
        // Assuming hullVerticesTransformed is already populated with vertices in the correct space.
        dotProducts[i] = GtMathPs2::Dot(clipPlaneNormal, hullVerticesTransformed[i]);
    }

    const unsigned char* edges = static_cast<const unsigned char*>(hull->m_offsetEdges);

    for (unsigned int i = 0; i < hull->m_numEdges; ++i) {
        unsigned char idx1 = edges[i * 2 + 0];
        unsigned char idx2 = edges[i * 2 + 1];

        if (idx1 >= hull->m_numVertices || idx2 >= hull->m_numVertices) {
            // Invalid edge indices, skip.
            continue;
        }

        float d1 = dotProducts[idx1];
        float d2 = dotProducts[idx2];

        // Original C logic: if (d1 >= 0.0f || d2 >= 0.0f).
        // This keeps edges if at least one vertex is on the positive side of the plane or on the plane.
        // Using epsilon to handle floating point inaccuracies near the plane.
        if (d1 >= epsilon || d2 >= epsilon) {
            // Assuming outEdgePoints has enough space.
            // Max possible output is hull->m_numEdges * 2 points.
            // The C code used gaTempEdgePoints which had a fixed size (14*2 CGtV3ds).
            // Let's use a practical limit for safety, e.g., 28 points (14 edges * 2 points/edge).
            // This check should ideally use a passed-in max size for outEdgePoints.
            if (*outNumEdgePoints < (14 * 2 - 1)) { // Max 14 edges -> 28 points. Check for space for 2 points.
                                                    // Ensure we don't write past outEdgePoints[27]
                outEdgePoints[*outNumEdgePoints] = hullVerticesTransformed[idx1];
                (*outNumEdgePoints)++;
                outEdgePoints[*outNumEdgePoints] = hullVerticesTransformed[idx2];
                (*outNumEdgePoints)++;
            } else {
                // Output buffer for edge points is full. Stop adding more.
                break;
            }
        }
    }
}

// --- Implementation of GetAveragePoint (Overload 1) ---
void B4CollisionDetector::GetAveragePoint(
    GtMathPs2::CGtV3d* outAvgPoint,
    const GtMathPs2::CGtV3d* points,
    int numPoints)
{
    if (!outAvgPoint || !points || numPoints <= 0) {
        if (outAvgPoint) *outAvgPoint = GtMathPs2::CGtV3d(0.f, 0.f, 0.f, 1.f); // Default to zero vector (w=1 for points)
        return;
    }

    // Initialize with the first point.
    // These will store the component-wise min/max.
    GtMathPs2::CGtV3d minPoint = points[0];
    GtMathPs2::CGtV3d maxPoint = points[0];

    for (int i = 1; i < numPoints; ++i) {
        // Assuming GtMathPs2::Min and ::Max perform component-wise operations for CGtV3d
        // E.g., minPoint.x = std::min(minPoint.x, points[i].x), etc. for y, z
        minPoint = GtMathPs2::Min(minPoint, points[i]);
        maxPoint = GtMathPs2::Max(maxPoint, points[i]);
    }

    *outAvgPoint = GtMathPs2::Add(minPoint, maxPoint);
    *outAvgPoint = GtMathPs2::MultiplyScalar(*outAvgPoint, 0.5f);
}

// --- Implementation of GetAveragePoint (Overload 2) ---
void B4CollisionDetector::GetAveragePoint(
    GtMathPs2::CGtV3d* outAvgPoint,
    GtMathPs2::CGtV3d* outMinBounds,
    GtMathPs2::CGtV3d* outMaxBounds,
    const GtMathPs2::CGtV3d* points,
    int numPoints)
{
    if (!points || numPoints <= 0) {
        if (outAvgPoint) *outAvgPoint = GtMathPs2::CGtV3d(0.f, 0.f, 0.f, 1.f);
        if (outMinBounds) *outMinBounds = GtMathPs2::CGtV3d(0.f, 0.f, 0.f, 1.f);
        if (outMaxBounds) *outMaxBounds = GtMathPs2::CGtV3d(0.f, 0.f, 0.f, 1.f);
        return;
    }

    // Initialize with the first point.
    GtMathPs2::CGtV3d minP = points[0];
    GtMathPs2::CGtV3d maxP = points[0];

    for (int i = 1; i < numPoints; ++i) {
        minP = GtMathPs2::Min(minP, points[i]);
        maxP = GtMathPs2::Max(maxP, points[i]);
    }

    if (outMinBounds) {
        *outMinBounds = minP;
    }
    if (outMaxBounds) {
        *outMaxBounds = maxP;
    }
    if (outAvgPoint) {
        *outAvgPoint = GtMathPs2::Add(minP, maxP);
        *outAvgPoint = GtMathPs2::MultiplyScalar(*outAvgPoint, 0.5f);
    }
}
