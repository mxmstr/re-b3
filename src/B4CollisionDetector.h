#ifndef B4_COLLISION_DETECTOR_H
#define B4_COLLISION_DETECTOR_H

#include "B4ConvexHull.h"
#include "B4PhysicsTypes.h" // Assuming this will contain forward declarations or stubs for CB4* types
#include "GtMath.h"

// Forward declarations for types that might be in B4PhysicsTypes.h or other headers
// If not already handled by B4PhysicsTypes.h, these ensure this header can compile.
struct CB4AccHullParams;
struct CB4HullCollideParams;
struct CB4HullCollideHullParams;
class CB4CollidingBody;
class CB4VehiclePhysics;
class CB4ActiveBody;
struct CB4HullWorldTriCollideParams;
struct CB4ConvexHullCollideInfo;
// GtMath.h should provide: GtMathPs2::CGtV3d, GtMathPs2::CGtMatrix3x4, GtMathPs2::CGtPlane, CGtAxisAlignedBox
// Forward declare GtMathPs2 types if not implicitly handled by GtMath.h including GtMathPs2 namespace
namespace GtMathPs2 {
    class CGtV3d;
    class CGtMatrix3x4;
    class CGtPlane;
}
class CGtAxisAlignedBox;


class B4CollisionDetector {
public:
    B4CollisionDetector();
    ~B4CollisionDetector();

    void Construct();
    bool Prepare();

    void SetupParams(CB4HullCollideParams* params, CB4CollidingBody* body1, CB4CollidingBody* body2, bool flag);
    void SetupParams(CB4HullCollideParams* params, CB4VehiclePhysics* vehicle, CB4ActiveBody* activeBody, bool flag);

    bool CollideVehicleWithActiveBody(CB4HullCollideParams* params, CB4VehiclePhysics* vehicle, CB4ActiveBody* activeBody, bool flag);
    bool CollideVehicles(CB4HullCollideParams* params, CB4VehiclePhysics* vehicle1, CB4VehiclePhysics* vehicle2, bool flag);
    bool CollideBodyHulls(CB4HullCollideParams* params, CB4CollidingBody* body1, CB4CollidingBody* body2, bool flag);
    bool CollideBodyHullWithWorld(CB4HullWorldTriCollideParams* params, CB4CollidingBody* body);

    void ConstructConcave();
    bool PrepareConcave();

    bool CollideConcaveVehicleWithWorld(CB4HullWorldTriCollideParams* params, CB4VehiclePhysics* vehicle);
    bool CollideConcaveVehicleWithConvexHull(CB4HullCollideParams* params, bool useSecondSetOfHulls);
    bool CollideConcaveVehicles(CB4HullCollideParams* params);

    void SetupVehicleHulls(int hullSetIndex, const B4ConvexHull* vehicleHullDataSource);

    bool CollideBodyConvexHullWithWorld(CB4HullWorldTriCollideParams* params, CB4CollidingBody* body);
    bool CollideConvexHulls(CB4HullCollideParams* params);
    bool DoCollideConvexHullToHull(CB4HullCollideParams* params);

    void BuildClippedEdgeList(GtMathPs2::CGtV3d* outEdgePoints, unsigned int* outNumEdgePoints, GtMathPs2::CGtV3d clipPlaneNormal, const B4ConvexHull* hull, GtMathPs2::CGtV3d* hullVertices);
    void GetAveragePoint(GtMathPs2::CGtV3d* outAvgPoint, const GtMathPs2::CGtV3d* points, int numPoints);
    void GetAveragePoint(GtMathPs2::CGtV3d* outAvgPoint, GtMathPs2::CGtV3d* outMinBounds, GtMathPs2::CGtV3d* outMaxBounds, const GtMathPs2::CGtV3d* points, int numPoints);

    bool DoCollideHullTriangles(CB4HullWorldTriCollideParams* params, CB4ConvexHullCollideInfo* collInfo);
    float GetHullPenetration(const B4ConvexHull* hull, GtMathPs2::CGtV3d pointOnHull, GtMathPs2::CGtV3d collisionNormal);
    int GetCollisionPlane(CB4HullCollideHullParams* params, GtMathPs2::CGtV3d contactPoint, GtMathPs2::CGtV3d separatingAxis);

    unsigned int ClipEdgesByHull(GtMathPs2::CGtV3d* outClippedEdges, int maxOutEdges, GtMathPs2::CGtV3d* inEdges, unsigned int numInEdges, GtMathPs2::CGtPlane* hullPlanes, unsigned int numHullPlanes);
    unsigned int ClipEdgesByPlane(GtMathPs2::CGtV3d* outClippedEdges, GtMathPs2::CGtV3d* inEdges, unsigned int numInEdges, const GtMathPs2::CGtPlane& clipPlane);

    static bool BoxBoxCollision(const CGtAxisAlignedBox& box1, const GtMathPs2::CGtMatrix3x4& transform1,
                                const CGtAxisAlignedBox& box2, const GtMathPs2::CGtMatrix3x4& transform2,
                                const GtMathPs2::CGtMatrix3x4* relativeTransform,
                                float* outOverlap, GtMathPs2::CGtV3d* outMTV, GtMathPs2::CGtV3d* outNormal);

private:
    B4ConvexHull m_vehicleFrontHulls[2];
    B4ConvexHull m_vehicleMiddleHulls[2];
    B4ConvexHull m_vehicleRearHulls[2];
};

#endif // B4_COLLISION_DETECTOR_H
