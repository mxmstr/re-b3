// ======== Start of new content for src/B4PhysicsTypes.h ========
#pragma once

#include "GtMath.h"
#include "B4ConvexHull.h" // Needed for B4ConvexHull members like m_offsetVertices
#include <cmath>         // For std::sqrt, std::abs
#include <algorithm>     // For std::max, std::min (scalar versions)

// Forward declarations
class CB4CollidingBody;
// Note: B4ConvexHull is included above. GtMath types are from GtMath.h.

// --- CB4Triangle Definition ---
struct CB4Triangle {
    GtMathPs2::CGtV3d v0, v1, v2;
    // TODO: Add material index or pointer if triangles have materials
    // unsigned int m_materialId;

    CB4Triangle() : v0(0.f,0.f,0.f,1.f), v1(0.f,0.f,0.f,1.f), v2(0.f,0.f,0.f,1.f) {}
};

// --- CB4CollisionResult Definition ---
// Moved before CB4AccHullParams as AddCollision might take it as a parameter.
struct CB4CollisionResult {
    bool                m_collided;
    GtMathPs2::CGtV3d   m_contactPointWorld;
    GtMathPs2::CGtV3d   m_penetrationNormalWorld;
    float               m_penetrationDepth;
    // TODO: Add material properties if available from collision
    // unsigned int        m_material1;
    // unsigned int        m_material2;


    CB4CollisionResult() { Reset(); }
    void Reset() {
        m_collided = false;
        m_contactPointWorld = GtMathPs2::CGtV3d(0.f,0.f,0.f,1.f);
        m_penetrationNormalWorld = GtMathPs2::CGtV3d(0.f,0.f,0.f,0.f); // Typically normalized vector, (0,0,0,0) if no collision
        m_penetrationDepth = 0.0f;
        // m_material1 = 0;
        // m_material2 = 0;
    }
};

// --- CB4AccHullParams Definition and Implementation ---
struct CB4AccHullParams {
    GtMathPs2::CGtV3d m_accumulatedContactPoint; // Weighted sum or similar for averaging
    GtMathPs2::CGtV3d m_accumulatedNormal;     // Weighted sum of normals for averaging
    float       m_maxPenetrationDepth;
    float       m_totalPenetrationDepth;     // Sum of depths for averaging (if needed)
    int         m_collisionCount;
    bool        m_hasCollision;
    // TODO: Add material accumulation if needed
    // unsigned int m_accumulatedMaterial1;
    // unsigned int m_accumulatedMaterial2;


    CB4AccHullParams() { Prepare(); }

    void Prepare() {
        m_accumulatedContactPoint = GtMathPs2::CGtV3d(0.f, 0.f, 0.f, 1.f);
        m_accumulatedNormal = GtMathPs2::CGtV3d(0.f, 0.f, 0.f, 0.f);
        m_maxPenetrationDepth = 0.0f;
        m_totalPenetrationDepth = 0.0f;
        m_collisionCount = 0;
        m_hasCollision = false;
        // m_accumulatedMaterial1 = 0;
        // m_accumulatedMaterial2 = 0;
    }

    void Reset() { Prepare(); }

    // Main AddCollision overload used by CollideConcaveVehicleWithWorld's placeholder
    void AddCollision(const GtMathPs2::CGtV3d& point, const GtMathPs2::CGtV3d& normal, float depth, unsigned int material1 = 0, unsigned int material2 = 0) {
        if (!m_hasCollision || depth > m_maxPenetrationDepth) { // Simplistic: deepest collision "wins" for point/normal
            m_maxPenetrationDepth = depth;
            m_accumulatedContactPoint = point;
            m_accumulatedNormal = normal;
        } else if (m_hasCollision && depth == m_maxPenetrationDepth) { // If same depth, average normal and point
            m_accumulatedContactPoint = GtMathPs2::Add(m_accumulatedContactPoint, point);
            m_accumulatedContactPoint = GtMathPs2::MultiplyScalar(m_accumulatedContactPoint, 0.5f);
            m_accumulatedNormal = GtMathPs2::Add(m_accumulatedNormal, normal);
            // Normal will be re-normalized in GetAverageNormal
        }
        m_totalPenetrationDepth += depth;
        m_collisionCount++;
        m_hasCollision = true;
        // TODO: Accumulate materials (e.g., if materials differ, apply rule)
        // if (m_collisionCount == 1) { m_accumulatedMaterial1 = material1; m_accumulatedMaterial2 = material2; }
    }

    // Overload for taking a CB4CollisionResult, used by other concave functions
    void AddCollision(const CB4CollisionResult& result) {
        if (result.m_collided) {
            // Assuming result.m_material1 and m_material2 would exist if materials were handled
            AddCollision(result.m_contactPointWorld, result.m_penetrationNormalWorld, result.m_penetrationDepth);
        }
    }

    GtMathPs2::CGtV3d GetAverageContactPoint() const {
        if (!m_hasCollision) return GtMathPs2::CGtV3d(0.f,0.f,0.f,1.f); // Default if no collision
        // The current AddCollision keeps the point of deepest penetration, not an average.
        return m_accumulatedContactPoint;
    }

    GtMathPs2::CGtV3d GetAverageNormal() const {
        if (!m_hasCollision) return GtMathPs2::CGtV3d(0.f,1.f,0.f,0.f); // Default to Y-up if no collision
        GtMathPs2::CGtV3d norm = m_accumulatedNormal;
        GtMathPs2::Normalize(norm); // Ensure it's a unit vector
        return norm;
    }

    float GetMaxPenetration() const { return m_maxPenetrationDepth; }
    // unsigned int GetMaterial1() const { return m_accumulatedMaterial1; }
    // unsigned int GetMaterial2() const { return m_accumulatedMaterial2; }
};

// --- CB4HullCollideHullParams Definition and Implementation ---
struct CB4HullCollideHullParams {
    const B4ConvexHull*     m_hull;
    GtMathPs2::CGtMatrix3x4 m_transform;
    float                   m_radius;
    CGtAxisAlignedBox       m_aabb;           // World space AABB of the hull

    GtMathPs2::CGtV3d       m_centerWorld;    // World space center of the hull (average of vertices)
    GtMathPs2::CGtV3d       m_minBoundsLocal; // Local space min bounds of vertices
    GtMathPs2::CGtV3d       m_maxBoundsLocal; // Local space max bounds of vertices

    unsigned int            m_hullTypeFlags;  // For filtering planes (e.g. in vehicles)
    const B4ConvexHull*     m_originalHull;   // Pointer to original hull definition if m_hull is temporary (e.g. a part)
    unsigned char*          m_validPlaneBitfield; // Bitfield for IsValidPlane, if applicable. Size depends on max planes.

    CB4HullCollideHullParams() : m_hull(nullptr), m_radius(0.0f), m_hullTypeFlags(0), m_originalHull(nullptr), m_validPlaneBitfield(nullptr) {}

    void CalculateBounds() {
        if (!m_hull || !m_hull->m_offsetVertices || m_hull->m_numVertices == 0) {
            m_minBoundsLocal = GtMathPs2::CGtV3d(0.f,0.f,0.f,1.f);
            m_maxBoundsLocal = GtMathPs2::CGtV3d(0.f,0.f,0.f,1.f);
            m_centerWorld = GtMathPs2::TransformPoint(GtMathPs2::CGtV3d(0.f,0.f,0.f,1.f), m_transform);
            m_radius = 0.0f;
            m_aabb.m_min = m_centerWorld;
            m_aabb.m_max = m_centerWorld;
            return;
        }

        const GtMathPs2::CGtV3d* vertices = static_cast<const GtMathPs2::CGtV3d*>(m_hull->m_offsetVertices);

        m_minBoundsLocal = vertices[0];
        m_maxBoundsLocal = vertices[0];
        GtMathPs2::CGtV3d sumOfLocalVertices = vertices[0];

        for (unsigned int i = 1; i < m_hull->m_numVertices; ++i) {
            m_minBoundsLocal = GtMathPs2::Min(m_minBoundsLocal, vertices[i]);
            m_maxBoundsLocal = GtMathPs2::Max(m_maxBoundsLocal, vertices[i]);
            sumOfLocalVertices = GtMathPs2::Add(sumOfLocalVertices, vertices[i]);
        }

        GtMathPs2::CGtV3d localCenter = GtMathPs2::MultiplyScalar(sumOfLocalVertices, 1.0f / m_hull->m_numVertices);
        m_centerWorld = GtMathPs2::TransformPoint(localCenter, m_transform);

        // Calculate world AABB
        GtMathPs2::CGtV3d worldTransformedVertex = GtMathPs2::TransformPoint(vertices[0], m_transform);
        m_aabb.m_min = worldTransformedVertex;
        m_aabb.m_max = worldTransformedVertex;

        for (unsigned int i = 1; i < m_hull->m_numVertices; ++i) {
            worldTransformedVertex = GtMathPs2::TransformPoint(vertices[i], m_transform);
            m_aabb.m_min = GtMathPs2::Min(m_aabb.m_min, worldTransformedVertex);
            m_aabb.m_max = GtMathPs2::Max(m_aabb.m_max, worldTransformedVertex);
        }

        // Calculate radius based on local vertices from local center
        float maxDistSq = 0.0f;
        for (unsigned int i = 0; i < m_hull->m_numVertices; ++i) {
            GtMathPs2::CGtV3d diff = GtMathPs2::Subtract(vertices[i], localCenter);
            maxDistSq = std::max(maxDistSq, GtMathPs2::LengthSq(diff));
        }
        // Radius should be scaled if transform has non-uniform scale. Assuming uniform scale or no scale.
        // For simplicity, using local radius. A more robust radius would consider transform scaling.
        m_radius = std::sqrt(maxDistSq);
    }

    // IsValidPlane now uses m_hullTypeFlags.
    // This was simplified in B4CollisionDetector::GetCollisionPlane.
    // The bitfield logic from C (`params->field_8C[i>>3] & (1 << (i&7))`) is more complex
    // and would require m_validPlaneBitfield to be properly sized and populated.
    // For now, using the m_hullTypeFlags approach.
    bool IsValidPlane(int planeIndex) const {
        // m_hullTypeFlags: 0=default/all valid, 1=NoPlane5, 2=NoPlane0&5, 3=NoPlane0
        // This interpretation of m_hullTypeFlags is based on observed patterns.
        if (planeIndex < 0 || planeIndex >= static_cast<int>(m_hull->m_numPlanes)) return false;

        switch (m_hullTypeFlags) {
            case 0: return true; // All planes are valid
            case 1: return planeIndex != 5; // Plane 5 is invalid
            case 2: return (planeIndex != 0 && planeIndex != 5); // Planes 0 and 5 are invalid
            case 3: return planeIndex != 0; // Plane 0 is invalid
            // Add more cases if other flags are identified
            default: return true; // Default to all valid if flag is unknown
        }
    }
};


// --- CB4HullCollideParams Definition ---
struct CB4HullCollideParams {
    CB4HullCollideHullParams m_hull1Params;
    CB4HullCollideHullParams m_hull2Params;

    CB4CollidingBody* m_collidingBody1;
    CB4CollidingBody* m_collidingBody2;

    unsigned int m_collisionFlags; // General purpose flags for collision query
    CB4CollisionResult* m_collisionResult; // Pointer to a result struct to be filled

    CB4HullCollideParams() : m_collidingBody1(nullptr), m_collidingBody2(nullptr), m_collisionFlags(0), m_collisionResult(nullptr) {}
};

// --- CB4HullWorldTriCollideParams Definition ---
// This struct is used for colliding a single hull against a list of world triangles.
struct CB4HullWorldTriCollideParams {
    CB4HullCollideHullParams m_hullParams; // The hull that is colliding with the world triangles.

    const CB4Triangle*    m_triangles;    // Pointer to an array of world triangles
    unsigned int          m_numTriangles; // Number of triangles in the array

    // Output parameters filled by DoCollideHullTriangles
    GtMathPs2::CGtV3d     m_finalContactPoint;      // World space contact point
    GtMathPs2::CGtV3d     m_finalPenetrationNormal; // World space normal of penetration (points out of the hull)
    float                 m_finalPenetrationDepth;
    unsigned int          m_material1; // Material of the hull
    unsigned int          m_material2; // Material of the triangle hit

    // Input parameters for controlling collision normal behavior
    bool                  m_hullNormalOverridden;   // If true, m_effectiveHullNormal is used instead of calculated one
    GtMathPs2::CGtV3d     m_effectiveHullNormal;  // The normal to use if overridden
    GtMathPs2::CGtV3d     m_hullNormalSourceVec;  // Source vector for m_effectiveHullNormal if needed by specific logic

    CB4CollisionResult*   m_collisionResult; // Optional: if underlying functions populate this.
                                           // DoCollideHullTriangles populates direct members above.

    CB4HullWorldTriCollideParams() : m_triangles(nullptr), m_numTriangles(0),
                                   m_finalPenetrationDepth(0.0f),
                                   m_material1(0), m_material2(0),
                                   m_hullNormalOverridden(false),
                                   m_collisionResult(nullptr) {}
};

// --- CB4ConvexHullCollideInfo Definition ---
// Used as an accumulator/temporary storage within DoCollideHullTriangles
struct CB4ConvexHullCollideInfo {
    GtMathPs2::CGtV3d   m_contactPointWorld;
    GtMathPs2::CGtV3d   m_penetrationNormalWorld;
    float               m_deepestPenetration;
    int                 m_numContactPoints;       // Count of distinct contact patches or features
    bool                m_isValid;                // Whether any collision was found and data is valid
    // int                 m_triangleIndex; // Index of the triangle that caused the deepest penetration, if needed

    CB4ConvexHullCollideInfo() { Reset(); }
    void Reset() {
        m_contactPointWorld = GtMathPs2::CGtV3d(0.f,0.f,0.f,1.f);
        m_penetrationNormalWorld = GtMathPs2::CGtV3d(0.f,0.f,0.f,0.f);
        m_deepestPenetration = 0.0f;
        m_numContactPoints = 0;
        m_isValid = false;
        // m_triangleIndex = -1;
    }
};

// ======== End of new content. Original content of B4PhysicsTypes.h follows. ========
enum class EActiveBodyType : unsigned char {
    Type0 = 0,
    Type1 = 1,
    Type2 = 2,
    Type3 = 3,
    Type4 = 4,
    Type5 = 5,
    Type6 = 6,
    Type7 = 7,
    Type8 = 8
};

// Add these declarations at the end of the file, after EActiveBodyType
extern bool kaabCanFatal[100];      // Assumed bool, size 10x10
extern int  kaaePhysicsType[400];   // Assumed int, size 10x10 with strides of 40 and 4
