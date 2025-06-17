#ifndef B4COLLIDINGBODY_H
#define B4COLLIDINGBODY_H

// Forward declarations for external types (placeholders)
struct GtV3d;
struct GtMatrix3x4_Pad;
struct GtMatrix3x4; // Added this as it's used in B4VehicleData
struct GtTexture;
struct GtIrradianceMap;
struct B4ConvexHull;
struct B4CollisionShapeData;
struct B4VehicleEssentialParams;
struct B4VehicleParams;
struct B4VehicleData; // Used by B4VehicleEssentialParams and B4CollidingBody
struct B4Wheel;
struct CB4CrashStartInfo;
struct B4TrafficVehicle;
struct GtPolygonIntersectionResult;
struct GtSphere; // Used by CacheWorldTriangles method

// Placeholder definitions for complex structs that are members or deeply used
// These would ideally be in their own headers.

// From B4CollidingBody_Decomp.c (comments indicate original decompiled source)
// struct B4CollidingBody__mGlobalWorldTriangleCache // sizeof=0x18D0
struct B4CollidingBody__mGlobalWorldTriangleCache {
    int num_triangles;
    void *p_triangle_vertex_data_start;
    void *p_triangle_material_ids_start;
    int unk_C;
    unsigned char triangle_vertex_buffer[6144];
    unsigned char triangle_material_buffer[192];
};

// struct B4CollisionShapeData // sizeof=0x40
struct B4CollisionShapeData {
    // GtMatrix3x4_Pad transform; // Assuming GtMatrix3x4_Pad is defined elsewhere or is complex
    unsigned char placeholder[0x40]; // Placeholder size
};

// struct __attribute__((packed)) B4Wheel // sizeof=0xB8
#pragma pack(push, 1)
struct B4Wheel {
    // GtV3d m_worldPosition;
    // GtV3d m_contactPoint_world;
    // GtV3d m_contactNormal_world;
    // GtV3d m_suspensionForce_world;
    // GtV3d m_localOffset;
    unsigned char gtV3d_placeholders[5 * 16]; // Assuming GtV3d might be 16 bytes (vec3 + padding)
    float m_radius;
    int m_flags_or_state_0x54;
    int m_flags_or_state_0x58;
    int m_flags_or_state_0x5C;
    int m_flags_or_state_0x60;
    int m_flags_or_state_0x64;
    int m_flags_or_state_0x68;
    float m_steeringAngle;
    float m_suspensionCompressionRatio;
    float m_spinVelocity;
    float m_suspensionTravel;
    int m_flags_or_state_0x7C;
    int m_wheelEffects;
    int unk_84;
    unsigned char m_effects_placeholder[40];
    char m_surfaceMaterialID_at_B0;
    char padding_B1;
    char m_skidAmount_at_B2;
    char m_onGroundFlag_at_B3;
    char m_burnoutAmount_at_B4;
    char m_lastContactFlag_at_B5;
    unsigned char m_padding_B6_to_end[2];
};
#pragma pack(pop)

// struct B4ConvexHull // sizeof=0x340 (based on B4CollidingBody member size)
struct B4ConvexHull {
    // This is a complex structure, using a placeholder size for now
    unsigned char placeholder[0x340]; // Size from B4CollidingBody: 0x0550 - 0x0210 = 0x340
};


// Define GtV3d and GtMatrix3x4_Pad if they are simple enough, otherwise keep as forward declared
// For now, creating simple placeholders to allow compilation
struct GtV3d {
    float x, y, z, w; // Assuming a 4-float vector for padding/alignment
};

struct GtMatrix3x4_Pad {
    float m[3][4];
    // Padding to 0x40 if necessary, but using placeholder in B4CollisionShapeData
};
struct GtMatrix3x4 {
    float m[3][4];
};


// struct __attribute__((packed)) B4CollidingBody // sizeof=0x9FC
#pragma pack(push, 1)
class B4CollidingBody {
public:
    // Nested struct B4CollidingBody::CollisionDetail // sizeof=0x10
    struct CollisionDetail {
        int collision_tag_or_surface_type;
        float impulse_magnitude_or_penetration;
        int contact_status_flags;
        float unknown_collision_float_18C;
    };

    GtV3d m_worldInvInertiaTensor_Row0;
    GtV3d m_worldInvInertiaTensor_Row1;
    GtV3d m_worldInvInertiaTensor_Row2;
    GtV3d m_localInvInertiaPrincipalX;
    GtV3d m_localInvInertiaPrincipalY;
    GtV3d m_localInvInertiaPrincipalZ;
    GtV3d m_initialMatrix_Row0; // Effectively a GtMatrix3x4
    GtV3d m_initialMatrix_Row1;
    GtV3d m_initialMatrix_Row2;
    GtV3d m_initialCenterOfMass_world;
    GtV3d m_linearVelocity;
    GtV3d m_angularMomentum_or_QuatDelta;
    GtV3d m_angularVelocity;
    GtV3d m_accumulatedTorque;
    GtV3d m_accumulatedForce;
    GtV3d m_torqueFromAppliedForces;
    GtV3d m_accumulatedImpulse_Force;
    GtV3d m_accumulatedImpulse_Torque;
    GtV3d m_totalTranslationAppliedThisStep;
    GtV3d m_collisionResponse_PositionDelta;
    GtV3d m_collisionResponse_ForceDirection;
    GtV3d m_collisionPoint_world;
    GtV3d m_collisionNormal_world;
    GtV3d m_collision_impulse_vector_raw;
    CollisionDetail m_collision_detail;
    GtV3d m_collision_contact_point_other_obj;
    GtV3d m_collision_adjusted_impulse;
    GtV3d m_boundingSphere_center; // This seems to be part of a GtSphere
    // float m_boundingSphere_radius; // This is implicitly part of GtSphere usually.
                                     // The C struct has m_boundingSphere_center then m_aabbMin_world
                                     // For now, GtV3d m_boundingSphere_center is kept.
                                     // If GtSphere is `center, radius`, radius might be separate or implicit.

    GtV3d m_aabbMin_world;
    GtV3d m_aabbMax_world;
    float m_mass;
    float m_frictionCoefficient;
    float m_restitutionCoefficient;
    float m_linearDamping;
    B4CollidingBody__mGlobalWorldTriangleCache *m_pGlobalWorldTriangleCache;
    B4CollisionShapeData *m_pCollisionShapeData;
    int m_collisionGroupID;
    unsigned char m_collisionFilterMask1;
    unsigned char m_collisionFilterMask2;
    unsigned char m_collisionFilterMask3;
    unsigned char m_collisionFilterMask4;
    unsigned char m_bIsStaticOrKinematic;
    unsigned char m_bHasMoved;
    unsigned char m_bCollidedThisFrame;
    unsigned char m_collisionSurfaceMaterialID;
    unsigned char m_bodyType;
    unsigned char m_trackCollisionResult;
    unsigned char m_streamedTrackPlayerID;
    unsigned char unk_207;
    char m_streamedTrackUnitIndex;
    unsigned char unk_209;
    unsigned char m_crashSeverityFlags;
    unsigned char m_padding_20B;
    // void *vtable; // Implicit in C++
    B4ConvexHull m_convexHull; // Placeholder struct
    B4Wheel m_wheels[6];       // Placeholder struct B4Wheel
    unsigned char pad_9A0[48];
    float m_suspFront_attachHeight_runtime;
    float m_suspFront_springDamping_runtime;
    float m_suspFront_springForce_runtime;
    float m_suspFront_springLength_runtime;
    float m_suspRear_attachHeight_runtime;
    float m_suspRear_springDamping_runtime;
    float m_suspRear_springForce_runtime;
    float m_suspRear_springLength_runtime;
    float m_suspension_bounciness_runtime;
    B4VehicleEssentialParams *m_pEssentialParams; // Forward declared
    B4VehicleParams *m_pFullParams;               // Forward declared

    // Constructor
    B4CollidingBody();

    // Destructor
    virtual ~B4CollidingBody();

    // Methods based on decompiled functions
    void Construct(); // Helper for constructor logic
    void Prepare();   // Helper for constructor logic

    virtual void Update(float deltaTime);
    void Integrate(float deltaTime); // Note: Original was __usercall, implies it might not be virtual if not overridden by derived types. Making it non-virtual for now.
    void ApplyTotalTranslation();
    virtual void Release();

    void SetRealisticMomentsOfInertia();
    void CacheWorldTriangles(); // Simpler version
    void CacheWorldTriangles(GtSphere& sphere); // Version with parameter

    bool HasFallenThroughWorld();
    void StartCrashing(unsigned char crashType, CB4CrashStartInfo* crashStartInfo);
    void StopCrashing();

    float CalculateEnergyFromCollisionImpulse(B4CollidingBody* otherBody, GtV3d& impulse, float impulseMag);

    void CollideWithWorld(int flags); // param was unnamed int

    void SetInitialMatrix(const GtMatrix3x4_Pad& matrix);

    float CalculateCollisionImpulseWithTraffic(B4TrafficVehicle* traffic,
                                               GtV3d& collisionNormal,
                                               GtV3d& contactPointWorld,
                                               GtV3d& relativeVelocity,
                                               float restitution,
                                               GtV3d* resultingImpulse);

    void AddCachedWorldTriangle(const GtPolygonIntersectionResult& intersectionResult);
    void StopImmediately();
    void ClearAccumulatedValues();

    float CalculateCollisionImpulseWithBody(B4CollidingBody& otherBody,
                                            GtV3d& collisionNormal,
                                            GtV3d& contactPointSelf,
                                            GtV3d& contactPointOther,
                                            GtV3d& relativeVelocity,
                                            float restitution,
                                            GtV3d* resultingImpulse);

    float CalculateCollisionImpulseWithInanimateObject(GtV3d& collisionNormal,
                                                       GtV3d& contactPointWorld,
                                                       GtV3d& relativeVelocity,
                                                       float restitution,
                                                       GtV3d* resultingImpulse);

    void SetMomentOfInertia(float ix, float iy, float iz);

    bool IsOutsideCollision() const;
    GtV3d GetPosition() const;
    void CalculateTorqueFromPositionedForce(GtV3d* outTorque, const GtV3d& forcePositionWorld, const GtV3d& forceVectorWorld);

};
#pragma pack(pop)

#endif // B4COLLIDINGBODY_H
