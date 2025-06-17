/*
00000000 struct B4CollidingBody__mGlobalWorldTriangleCache // sizeof=0x18D0
00000000 {                                       // XREF: .bss:_16CB4CollidingBody$_mGlobalWorldTriangleCache/r
00000000     int num_triangles;                  // XREF: Construct__16CB4CollidingBody+2C/w
00000000                                         // Prepare__16CB4CollidingBody+204/w ...
00000004     void *p_triangle_vertex_data_start; // XREF: Construct__16CB4CollidingBody+34/w
00000004                                         // Prepare__16CB4CollidingBody+34C/w
00000008     void *p_triangle_material_ids_start;
00000008                                         // XREF: Construct__16CB4CollidingBody+28/w
00000008                                         // Prepare__16CB4CollidingBody+344/w
0000000C     int unk_C;
00000010     unsigned __int8 triangle_vertex_buffer[6144];
00000010                                         // XREF: Construct__16CB4CollidingBody+1C/o
00000010                                         // Prepare__16CB4CollidingBody+2AC/o
00001810     unsigned __int8 triangle_material_buffer[192];
00001810                                         // XREF: Construct__16CB4CollidingBody+14/o
00001810                                         // Prepare__16CB4CollidingBody+294/o
000018D0 };

00000000 struct B4CollisionShapeData // sizeof=0x40
00000000 {
00000000     GtMatrix3x4_Pad transform;
00000040 };

00000000 struct __attribute__((packed)) B4Wheel // sizeof=0xB8
00000000 {                                       // XREF: B4VehiclePhysics/r
00000000                                         // B4CollidingBody/r
00000000     GtV3d m_worldPosition;
00000010     GtV3d m_contactPoint_world;
00000020     GtV3d m_contactNormal_world;
00000030     GtV3d m_suspensionForce_world;
00000040     GtV3d m_localOffset;
00000050     float m_radius;
00000054     int m_flags_or_state_0x54;
00000058     int m_flags_or_state_0x58;
0000005C     int m_flags_or_state_0x5C;
00000060     int m_flags_or_state_0x60;
00000064     int m_flags_or_state_0x64;
00000068     int m_flags_or_state_0x68;
0000006C     float m_steeringAngle;
00000070     float m_suspensionCompressionRatio;
00000074     float m_spinVelocity;
00000078     float m_suspensionTravel;
0000007C     int m_flags_or_state_0x7C;
00000080     int m_wheelEffects;
00000084     int unk_84;
00000088     unsigned __int8 m_effects_placeholder[40];
000000B0     char m_surfaceMaterialID_at_B0;
000000B1     char padding_B1;
000000B2     char m_skidAmount_at_B2;
000000B3     char m_onGroundFlag_at_B3;
000000B4     char m_burnoutAmount_at_B4;
000000B5     char m_lastContactFlag_at_B5;
000000B6     unsigned __int8 m_padding_B6_to_end[2];
000000B8 };

00000000 struct __attribute__((packed)) B4CollidingBody::CollisionDetail // sizeof=0x10
00000000 {                                       // XREF: B4CollidingBody/r
00000000     int collision_tag_or_surface_type;
00000004     float impulse_magnitude_or_penetration;
00000008     int contact_status_flags;
0000000C     float unknown_collision_float_18C;
00000010 };

00000000 struct __attribute__((packed)) B4ModelData::SubMeshData // sizeof=0x8
00000000 {                                       // XREF: B4ModelData/r
00000000     int pVertices_offset;
00000004     int pIndices_offset;
00000008 };

00000000 struct __attribute__((packed)) B4ModelData // sizeof=0x10
00000000 {
00000000     int numSubMeshes;
00000004     int pSubMeshes_offset;
00000008     struct B4ModelData::SubMeshData m_subMeshes[1];
00000010 };

00000000 struct __attribute__((packed)) B4VehicleLODDataBase // sizeof=0x30
00000000 {
00000000     B4ModelData *pMainModel_offset;
00000004     B4ModelData *pWheelModels_offset[8];
00000024     B4ModelData *pGlassModels_offset[3];
00000030 };

00000000 struct __attribute__((packed)) B4VehiclePayloadSet // sizeof=0xC
00000000 {
00000000     int m_payloadType;
00000004     int m_numAttachmentPoints;
00000008     void *pAttachmentPointsData_offset;
0000000C };

00000000 struct B4SoundESMGraphStruct // sizeof=0x8
00000000 {
00000000     float *pGraphDataPoints_offset;
00000004     int numDataPoints;
00000008 };

00000000 struct B4SoundESMPartialStruct // sizeof=0x10
00000000 {
00000000     unsigned __int8 unknown_partial_data[8];
00000008     B4SoundESMGraphStruct *pGraphs_offset;
0000000C     unsigned __int8 numGraphs;
0000000D     unsigned __int8 unk_D;
0000000E     unsigned __int8 unk_E;
0000000F     unsigned __int8 unk_F;
00000010 };

00000000 struct __attribute__((packed)) B4SoundESMStruct // sizeof=0x44
00000000 {
00000000     unsigned __int8 unknown_header_data[60];
0000003C     B4SoundESMPartialStruct *pPartials_offset;
00000040     unsigned __int8 numPartials;
00000041     unsigned __int8 unk_41;
00000042     unsigned __int8 unk_42;
00000043     unsigned __int8 unk_43;
00000044 };

00000000 struct __attribute__((packed)) B4VehicleData // sizeof=0x2179
00000000 {                                       // XREF: B4VehicleRenderer/r
00000000     int m_vehicleID_or_Type;
00000004     int m_unknown_int_4;
00000008     unsigned __int8 m_numWheels;
00000009     unsigned __int8 m_numHingedParts;
0000000A     unsigned __int8 m_numBodyParts;
0000000B     unsigned __int8 m_numPayloadAttachmentPoints;
0000000C     float m_boundingSphereRadius;
00000010     unsigned __int8 unknown_data_0x10_to_0x4B[60];
0000004C     B4VehicleLODDataBase *m_vehicleLODs[5];
00000060     GtTexture *m_pLiveryTexture;
00000064     GtTexture *m_pDamageTexture;
00000068     B4ModelData *m_pMainBodyModelData;
0000006C     B4ModelData *m_pBodyPartsModelData;
00000070     GtMatrix3x4 m_mainBody_DefaultLocalBoneTransforms[19];
00000400     unsigned __int8 unknown_data_0x70_to_0xC1F[1840];
00000B30     char unk_B30;
00000B31     unsigned __int8 unknown_data_0x70_to_0xC20[239];
00000C20     GtMatrix3x4 m_bodyParts_DefaultLocalBoneTransforms[6][3];
00000F80     unsigned __int8 unknown_data_0xC20_to_0x16DF[112];
00000FF0     char unk_FF0;
00000FF1     unsigned __int8 unknown_data_0xC20_to_0x16E0[1775];
000016E0     float m_mainBody_BoneLengths[19];
0000172C     unsigned __int8 padding_to_body_part_bone_lengths1[16];
0000173C     int unk_173C[2];
00001744     int unk_1744[6][3];
0000178C     char pad_178C[20];
000017A0     int m_bodyPart_isDeformable[6];
000017B8     int m_bodyPart_Types[6];
000017D0     unsigned __int8 padding_to_hinged_part_data1[40];
000017F8     unsigned __int8 unk_17F8[6][2];
00001804     float m_hingedPart_DefaultAngles[8];
00001824     unsigned __int8 padding_to_convex_hull[192];
000018E4     unsigned __int8 unk_18E4[6][8];
00001914     unsigned __int8 padding_to_convex_hull2[908];
00001CA0     GtV3d m_AABBMin;
00001CB0     unsigned __int8 padding_to_convex_hull3[16];
00001CC0     unsigned __int8 unk_1CC0[8][32];
00001DC0     B4ConvexHull m_physicsConvexHullData;
00002100     int unk_2100;
00002104     void *m_unknownPointers_at_8452[11];
00002130     int unk_2130;
00002134     int pad[6];
0000214C     unsigned __int8 padding_to_payload_data[11];
00002157     unsigned __int8 unk_2157;
00002158     unsigned __int8 padding_to_payload_data2[8];
00002160     B4VehiclePayloadSet *m_pPayloadSetsArray;
00002164     void *m_pUnknownData_8548;
00002168     unsigned __int8 m_numPayloadSets;
00002169     unsigned __int8 unk_2169;
0000216A     unsigned __int8 unk_216A;
0000216B     unsigned __int8 unk_216B;
0000216C     B4SoundESMStruct *m_pSoundESM[2];
00002174     void *m_pSomeFinalData;
00002178     unsigned __int8 pad_2178[1];
00002179 };

00000000 struct __attribute__((packed)) B4VehicleEssentialParams // sizeof=0x64
00000000 {
00000000     GtMatrix3x4_Pad m_worldTransform;
00000040     B4VehicleData *pVehicleData;
00000044     float m_steerAngleNormRight;
00000048     float m_steerAngleNormLeft;
0000004C     float m_throttleNorm;
00000050     float m_brakeNorm;
00000054     unsigned __int8 m_unknown_flag_0x54;
00000055     unsigned __int8 m_unknown_flag_0x55;
00000056     unsigned __int8 m_unknown_flag_0x56;
00000057     unsigned __int8 m_unknown_flag_0x57;
00000058     unsigned __int8 m_vehicleLightFlags;
00000059     unsigned __int8 m_vehicleTextureIndex;
0000005A     char m_streamedTrackUnitIndex;
0000005B     unsigned __int8 m_isVisibleInFrustumFlag;
0000005C     GtIrradianceMap *pIrradianceMap;
00000060     GtTexture *pReflectionMapTexture;
00000064 };

00000000 struct __attribute__((packed)) B4VehicleDeform // sizeof=0x1D20
00000000 {                                       // XREF: B4VehicleParams/r
00000000     GtMatrix3x4 m_boneMatrices_working_copy[8];
00000180     char pad_180[128];
00000200     B4VehicleBoneRig m_boneRig;
00000204     B4VehicleDeformParams m_deformParams;
00000240     B4VehicleEssentialParams *m_pEssentialParams;
00000244     B4VehicleParams *m_pVehicleParams;
00000248     B4VehicleData *m_pVehicleData;
0000024C     B4VehiclePhysics2 *m_pVehiclePhysics;
00000250     float m_accumulatedDamageWithoutRepair;
00000254     float m_roadRageDeformationAmount;
00000258     char pad_258[32];
00000278     char unk_278;
00000279     char unk_279;
0000027A     char unk_27A;
0000027B     char unk_27B;
0000027C     char unk_27C[6];
00000282     char unk_282[10];
0000028C     float m_someDeformPropertyArray[6];
000002A4     float m_wheelRadii[6];
000002BC     char unk_73C[36];
000002E0     GtMatrix3x4 m_mainBodyBoneMatrices_VehicleSpace[19];
00000670     GtMatrix3x4 m_bodyPartBoneMatrices_VehicleSpace[6][3];
000009D0     unsigned __int8 unknown_data_post_bones[2191];
0000125F     char unk_125F;
00001260     char unk_12E0[8][192];
00001860     unsigned __int8 unknown_data_up_to_8078[684];
00001B0C     float m_mainBodyBoneDeformParams[19][7];
00001D20 };

00000000 struct __attribute__((packed)) B4VehicleParams // sizeof=0x23A3
00000000 {                                       // XREF: B4RaceCar/r
00000000                                         // B4TrafficSystem/r ...
00000000     unsigned __int8 unknown_data_0to383[48];
00000030     unsigned __int8 unk_30;
00000031     unsigned __int8 unknown_data_0to383_1[15];
00000040     unsigned __int8 unknown_data_0to383_2[64];
00000080     unsigned __int8 unknown_data_0to383_3[256];
00000180     char m_hingedParts1[16];
00000190     char m_hingedParts2[16];
000001A0     char m_hingedParts3[480];
00000380     char m_hingedParts4[256];
00000480     B4VehicleDeform m_vehicleDeform;
000021A0     float m_hingedPartCurrentAngles[15];
000021DC     float m_hingedPartTargetAngles[8];
000021FC     int unk_21FC;
00002200     int unk_2200;
00002204     unsigned __int8 unknown_data_up_to_8832[124];
00002280     float m_someOtherDeformFloats1[6];
00002298     int m_bodyPartStates[6];
000022B0     int unk_22B0;
000022B4     int unk_22B4;
000022B8     int unk_22B8[6];
000022D0     unsigned __int8 padding_to_9056[144];
00002360     float m_vehicleTotalMass;
00002364     int unk_2364;
00002368     int unk_2368;
0000236C     unsigned __int8 m_unknown_flag_9068;
0000236D     unsigned __int8 m_engineFlagsOrDamageState;
0000236E     unsigned __int8 m_unknown_flag_9070;
0000236F     unsigned __int8 m_byte_array_9071[8];
00002377     unsigned __int8 m_byte_array_9079[8];
0000237F     unsigned __int8 m_unknown_flag_9087;
00002380     unsigned __int8 m_unknown_flag_9088;
00002381     unsigned __int8 m_unknown_flag_9089;
00002382     unsigned __int8 m_unknown_flag_9090;
00002383     unsigned __int8 m_isDeformed;
00002384     unsigned __int8 m_bodyPartIsActiveFlags[8];
0000238C     unsigned __int8 m_isBadlyDamagedFlag;
0000238D     unsigned __int8 m_isPayloadAttached;
0000238E     unsigned __int8 padding_to_9104[2];
00002390     B4VehiclePayloadSet *pPayloadSet;
00002394     int m_currentGearIndex;
00002398     int m_engineRPM;
0000239C     char m_airTimeFrames;
0000239D     char m_boostCharge;
0000239E     char m_perfectStartBonus_flag;
0000239F     char m_bBurnoutActive;
000023A0     char unk_23A0;
000023A1     char unk_23A1;
000023A2     char unk_23A2;
000023A3 };

00000000 struct __attribute__((packed)) B4CollidingBody // sizeof=0x9FC
00000000 {                                       // XREF: B4VehiclePhysics/r
00000000                                         // B4BodyPartPhysics/r ...
00000000     GtV3d m_worldInvInertiaTensor_Row0;
00000010     GtV3d m_worldInvInertiaTensor_Row1;
00000020     GtV3d m_worldInvInertiaTensor_Row2;
00000030     GtV3d m_localInvInertiaPrincipalX;
00000040     GtV3d m_localInvInertiaPrincipalY;
00000050     GtV3d m_localInvInertiaPrincipalZ;
00000060     GtV3d m_initialMatrix_Row0;
00000070     GtV3d m_initialMatrix_Row1;
00000080     GtV3d m_initialMatrix_Row2;
00000090     GtV3d m_initialCenterOfMass_world;
000000A0     GtV3d m_linearVelocity;
000000B0     GtV3d m_angularMomentum_or_QuatDelta;
000000C0     GtV3d m_angularVelocity;
000000D0     GtV3d m_accumulatedTorque;
000000E0     GtV3d m_accumulatedForce;
000000F0     GtV3d m_torqueFromAppliedForces;
00000100     GtV3d m_accumulatedImpulse_Force;
00000110     GtV3d m_accumulatedImpulse_Torque;
00000120     GtV3d m_totalTranslationAppliedThisStep;
00000130     GtV3d m_collisionResponse_PositionDelta;
00000140     GtV3d m_collisionResponse_ForceDirection;
00000150     GtV3d m_collisionPoint_world;
00000160     GtV3d m_collisionNormal_world;
00000170     GtV3d m_collision_impulse_vector_raw;
00000180     B4CollidingBody::CollisionDetail m_collision_detail;
00000190     GtV3d m_collision_contact_point_other_obj;
000001A0     GtV3d m_collision_adjusted_impulse;
000001B0     GtV3d m_boundingSphere_center;
000001C0     GtV3d m_aabbMin_world;
000001D0     GtV3d m_aabbMax_world;
000001E0     float m_mass;
000001E4     float m_frictionCoefficient;
000001E8     float m_restitutionCoefficient;
000001EC     float m_linearDamping;
000001F0     B4CollidingBody__mGlobalWorldTriangleCache *m_pGlobalWorldTriangleCache;
000001F4     B4CollisionShapeData *m_pCollisionShapeData;
000001F8     int m_collisionGroupID;
000001FC     unsigned __int8 m_collisionFilterMask1;
000001FD     unsigned __int8 m_collisionFilterMask2;
000001FE     unsigned __int8 m_collisionFilterMask3;
000001FF     unsigned __int8 m_collisionFilterMask4;
00000200     unsigned __int8 m_bIsStaticOrKinematic;
00000201     unsigned __int8 m_bHasMoved;
00000202     unsigned __int8 m_bCollidedThisFrame;
00000203     unsigned __int8 m_collisionSurfaceMaterialID;
00000204     unsigned __int8 m_bodyType;
00000205     unsigned __int8 m_trackCollisionResult;
00000206     unsigned __int8 m_streamedTrackPlayerID;
00000207     unsigned __int8 unk_207;
00000208     char m_streamedTrackUnitIndex;
00000209     unsigned __int8 unk_209;
0000020A     unsigned __int8 m_crashSeverityFlags;
0000020B     unsigned __int8 m_padding_20B;
0000020C     void *vtable;
00000210     B4ConvexHull m_convexHull;
00000550     B4Wheel m_wheels[6];
000009A0     unsigned __int8 pad_9A0[48];
000009D0     float m_suspFront_attachHeight_runtime;
000009D4     float m_suspFront_springDamping_runtime;
000009D8     float m_suspFront_springForce_runtime;
000009DC     float m_suspFront_springLength_runtime;
000009E0     float m_suspRear_attachHeight_runtime;
000009E4     float m_suspRear_springDamping_runtime;
000009E8     float m_suspRear_springForce_runtime;
000009EC     float m_suspRear_springLength_runtime;
000009F0     float m_suspension_bounciness_runtime;
000009F4     B4VehicleEssentialParams *m_pEssentialParams;
000009F8     B4VehicleParams *m_pFullParams;
000009FC };
*/

// CB4CollidingBody::CB4CollidingBody(void)
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall _16CB4CollidingBody(B4CollidingBody *a1)
{
  __int64 result; // $v0

  result = *&a1;
  a1->vtable = vt_16CB4CollidingBody;
  return result;
}

// CB4CollidingBody::Construct(void)
__int64 __fastcall Construct__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  pCollidingBody->m_bodyType = 0;
  pCollidingBody->m_pCollisionShapeData = 0;
  *&pCollidingBody->m_streamedTrackUnitIndex = 0;
  pCollidingBody->m_pGlobalWorldTriangleCache = &16CB4CollidingBody__mGlobalWorldTriangleCache;
  16CB4CollidingBody__mGlobalWorldTriangleCache.p_triangle_material_ids_start = 16CB4CollidingBody__mGlobalWorldTriangleCache.triangle_material_buffer;
  16CB4CollidingBody__mGlobalWorldTriangleCache.num_triangles = 0;
  16CB4CollidingBody__mGlobalWorldTriangleCache.p_triangle_vertex_data_start = 16CB4CollidingBody__mGlobalWorldTriangleCache.triangle_vertex_buffer;
  return Prepare__16CB4CollidingBody(pCollidingBody);
}

// CB4CollidingBody::Prepare(void)
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall Prepare__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  __int64 v6; // $ra
  float v7; // $f20
  float v8; // $f21
  float v13; // $f21
  float v16; // $f21
  __int64 result; // $v0
  float v20; // $f21
  __int128 v26; // [sp+0h] [-150h] BYREF
  float v29; // [sp+30h] [-120h] BYREF
  float v30; // [sp+34h] [-11Ch]
  float v31; // [sp+38h] [-118h]
  __int64 v36; // [sp+E0h] [-70h]
  float v42; // [sp+140h] [-10h]
  float v43; // [sp+148h] [-8h]

  __asm { sq           $s0, 0x150+var_20($sp) }
  *&_$S0 = *&pCollidingBody;
  v43 = v8;
  __asm
  {
    sq           $s1, 0x150+var_30($sp)
    sq           $s2, 0x150+var_40($sp)
    sq           $s3, 0x150+var_50($sp)
  }
  _$S2 = &pCollidingBody->m_localInvInertiaPrincipalX;
  __asm { sq           $s4, 0x150+var_60($sp) }
  v36 = v6;
  v42 = v7;
  memset(&v26, 0, 0x30uLL);
  __asm
  {
    vadd.xyz     $vf7, $vf0, $vf0
    lq           $v0, 0x150+var_120($sp)
    sq           $v0, 0x150+var_150($sp)
    lq           $v0, 0x150+var_120($sp)
  }
  v29 = 0.0;
  __asm { sq           $v0, 0x150+var_140($sp) }
  v30 = 0.0;
  v31 = v13;
  __asm
  {
    sqc2         $vf7, 0x150+var_80($sp)
    lq           $v0, 0x150+var_120($sp)
    sq           $v0, 0x150+var_130($sp)
  }
  memset(*&_$S0, 0, 0x30uLL);
  memset(&_$S0->m_localInvInertiaPrincipalX, 0, 0x30uLL);
  __asm
  {
    lqc2         $vf12, 0x150+var_B0($sp)
    vsub.xyz     $vf21, $vf0, $vf0
    vsub.xyz     $vf23, $vf0, $vf0
    vsub.xyz     $vf24, $vf0, $vf0
    vsub.xyz     $vf22, $vf0, $vf0
    vaddw.x      $vf21, $vf0, $vf0
    vaddw.y      $vf23, $vf0, $vf0
    vaddw.z      $vf24, $vf0, $vf0
    lqc2         $vf14, 0x150+var_A0($sp)
    lqc2         $vf13, 0x150+var_90($sp)
    vsub.xyzw    $vf20, $vf0, $vf0
    lqc2         $vf11, 0x150+var_150($sp)
    vaddx.x      $vf12, $vf0, $vf11
    vaddz.x      $vf13, $vf0, $vf11
    vaddy.x      $vf14, $vf0, $vf11
    lqc2         $vf6, 0x150+var_140($sp)
    vmove.xyzw   $vf18, $vf14
    vmove.xyzw   $vf17, $vf12
    vaddy.y      $vf18, $vf0, $vf6
    vmove.xyzw   $vf19, $vf13
    vaddx.y      $vf17, $vf0, $vf6
    vaddz.y      $vf19, $vf0, $vf6
    lqc2         $vf4, 0x150+var_130($sp)
    vmove.xyzw   $vf8, $vf17
    vmove.xyzw   $vf9, $vf18
    vaddx.z      $vf8, $vf0, $vf4
    vmove.xyzw   $vf10, $vf19
    vaddy.z      $vf9, $vf0, $vf4
    lqc2         $vf3, 0($s0)
    vaddz.z      $vf10, $vf0, $vf4
    lqc2         $vf2, 0x10($s0)
    lqc2         $vf1, 0x20($s0)
    vmulax.xyz   $A, $vf3, $vf8
    vmadday.xyz  $A, $vf2, $vf8
    vmaddz.xyz   $vf5, $vf1, $vf8
    vmulax.xyz   $A, $vf3, $vf9
    vmadday.xyz  $A, $vf2, $vf9
    vmaddz.xyz   $vf16, $vf1, $vf9
    vmulax.xyz   $A, $vf3, $vf10
    vmadday.xyz  $A, $vf2, $vf10
    vmaddz.xyz   $vf15, $vf1, $vf10
    sqc2         $vf12, 0x150+var_B0($sp)
    sqc2         $vf16, 0x40($s0)
    sqc2         $vf15, 0x50($s0)
    sqc2         $vf5, 0x30($s0)
    sqc2         $vf13, 0x150+var_90($sp)
    sqc2         $vf14, 0x150+var_A0($sp)
    lqc2         $vf2, 0x20($s2)
    sqc2         $vf17, 0x150+var_B0($sp)
    sqc2         $vf18, 0x150+var_A0($sp)
    sqc2         $vf19, 0x150+var_90($sp)
    lqc2         $vf1, 0x10($s2)
    vmulax.xyz   $A, $vf11, $vf5
    vmadday.xyz  $A, $vf6, $vf5
    vmaddz.xyz   $vf3, $vf4, $vf5
    vmulax.xyz   $A, $vf11, $vf1
    vmadday.xyz  $A, $vf6, $vf1
    vmaddz.xyz   $vf12, $vf4, $vf1
    vmulax.xyz   $A, $vf11, $vf2
    vmadday.xyz  $A, $vf6, $vf2
    vmaddz.xyz   $vf13, $vf4, $vf2
    sqc2         $vf8, 0x150+var_B0($sp)
    sqc2         $vf9, 0x150+var_A0($sp)
    sqc2         $vf10, 0x150+var_90($sp)
    sqc2         $vf15, 0x150+var_F0($sp)
    sqc2         $vf3, 0x150+var_F0($sp)
    sqc2         $vf8, 0x150+var_E0($sp)
    sqc2         $vf9, 0x150+var_D0($sp)
    sqc2         $vf10, 0x150+var_C0($sp)
    sqc2         $vf5, 0x150+var_B0($sp)
    sqc2         $vf16, 0x150+var_A0($sp)
    sqc2         $vf15, 0x150+var_90($sp)
    sqc2         $vf5, 0x150+var_110($sp)
    sqc2         $vf16, 0x150+var_100($sp)
    sqc2         $vf12, 0x150+var_E0($sp)
    sqc2         $vf3, 0x30($s0)
    sqc2         $vf12, 0x40($s0)
    sqc2         $vf13, 0x50($s0)
  }
  _$S0->m_pGlobalWorldTriangleCache = &16CB4CollidingBody__mGlobalWorldTriangleCache;
  16CB4CollidingBody__mGlobalWorldTriangleCache.num_triangles = 0;
  __asm
  {
    sqc2         $vf21, 0x60($s0)
    sqc2         $vf3, 0x150+var_120($sp)
    sqc2         $vf13, 0x150+var_D0($sp)
    sqc2         $vf12, 0x150+var_110($sp)
    sqc2         $vf13, 0x150+var_100($sp)
    sqc2         $vf22, 0x30($v0)
    sqc2         $vf23, 0x10($v0)
    sqc2         $vf24, 0x20($v0)
    sqc2         $vf20, 0x150+var_120($sp)
    sqc2         $vf20, 0xA0($s0)
    lqc2         $vf7, 0x150+var_80($sp)
    lq           $v1, 0x150+var_120($sp)
    sqc2         $vf7, 0x150+var_120($sp)
  }
  v29 = v16;
  v30 = 0.0;
  v31 = 0.0;
  __asm
  {
    sq           $v1, 0xB0($s0)
    lq           $v0, 0x150+var_120($sp)
    sqc2         $vf7, 0xC0($s0)
    sqc2         $vf7, 0xD0($s0)
    sqc2         $vf7, 0xE0($s0)
    sqc2         $vf7, 0xF0($s0)
    sqc2         $vf7, 0x100($s0)
    sqc2         $vf7, 0x110($s0)
    sq           $v0, 0x130($s0)
    sqc2         $vf7, 0x120($s0)
  }
  _$S0->m_pCollisionShapeData = 0;
  __asm { sqc2         $vf7, 0x150+var_80($sp) }
  memset(&_$S0->m_collisionPoint_world, 0, 0x60uLL);
  __asm { lqc2         $vf7, 0x150+var_80($sp) }
  _$V0 = COERCE_INT(0.0);
  __asm
  {
    qmtc2        $v0, $vf3
    sqc2         $vf7, 0x150+var_120($sp)
  }
  result = 1LL;
  __asm
  {
    lqc2         $vf1, 0x150+var_120($sp)
    lqc2         $vf2, 0x1B0($s0)
    vadd.xyz     $vf2, $vf0, $vf1
    sqc2         $vf7, 0x1C0($s0)
    vmove.xyzw   $vf1, $vf2
  }
  _$S0->m_frictionCoefficient = 0.0;
  __asm { vsubw.w      $vf1, $vf0, $vf0 }
  _$S0->m_restitutionCoefficient = 0.1;
  __asm
  {
    sqc2         $vf1, 0x1B0($s0)
    vaddx.w      $vf1, $vf1, $vf3
  }
  _$S0->m_linearDamping = v20;
  __asm
  {
    sqc2         $vf1, 0x1B0($s0)
    sqc2         $vf7, 0x150($s0)
    sqc2         $vf7, 0x160($s0)
  }
  _$S0->m_collision_detail.impulse_magnitude_or_penetration = 0.0;
  __asm
  {
    sqc2         $vf7, 0x140($s0)
    sqc2         $vf7, 0x1D0($s0)
  }
  LOWORD(_$S0->m_collision_detail.collision_tag_or_surface_type) = 0;
  _$S0->m_collision_detail.contact_status_flags = 0;
  _$S0->m_collisionFilterMask1 = 0;
  _$S0->m_collisionGroupID = 0;
  __asm { sqc2         $vf7, 0x150+var_120($sp) }
  _$S0->m_mass = v20;
  _$S0->m_collisionFilterMask2 = 0;
  _$S0->m_collisionFilterMask3 = 0;
  _$S0->m_collisionFilterMask4 = 0;
  _$S0->m_bIsStaticOrKinematic = 0;
  _$S0->m_bHasMoved = 0;
  _$S0->m_bCollidedThisFrame = 0;
  _$S0->m_collisionSurfaceMaterialID = 0;
  _$S0->m_trackCollisionResult = 0;
  _$S0->m_streamedTrackPlayerID = 0;
  _$S0->unk_207 = 15;
  16CB4CollidingBody__mGlobalWorldTriangleCache.p_triangle_material_ids_start = 16CB4CollidingBody__mGlobalWorldTriangleCache.triangle_material_buffer;
  16CB4CollidingBody__mGlobalWorldTriangleCache.num_triangles = 0;
  16CB4CollidingBody__mGlobalWorldTriangleCache.p_triangle_vertex_data_start = 16CB4CollidingBody__mGlobalWorldTriangleCache.triangle_vertex_buffer;
  *&_$S0->m_streamedTrackUnitIndex = 0;
  __asm
  {
    lq           $s0, 0x150+var_20($sp)
    lq           $s1, 0x150+var_30($sp)
    lq           $s2, 0x150+var_40($sp)
    lq           $s3, 0x150+var_50($sp)
    lq           $s4, 0x150+var_60($sp)
  }
  return result;
}

// CB4CollidingBody::Update(float)
__int64 __usercall Update__16CB4CollidingBodyf@<$v0>(B4CollidingBody *pCollidingBody@<$a0>, float a2@<$f12>)
{
  __int64 v3; // $ra
  float m_mass; // $f0
  __int64 result; // $v0
  float v14[4]; // [sp+0h] [-40h] BYREF
  __int128 v15; // [sp+10h] [-30h] BYREF
  __int64 v16; // [sp+20h] [-20h]

  __asm { sq           $s0, 0x40+var_10($sp) }
  _$S0 = pCollidingBody;
  v16 = v3;
  _$V0 = &kGravity;
  m_mass = pCollidingBody->m_mass;
  v14[0] = 1.0;
  v14[1] = m_mass;
  v14[2] = 1.0;
  __asm
  {
    lqc2         $vf5, (kGravity - 0x1CB94E0)($v0)
    lqc2         $vf1, 0x40+var_40($sp)
    vmul.xyz     $vf5, $vf5, $vf1
  }
  if ( pCollidingBody->m_collisionFilterMask4 )
  {
    _$V1 = pCollidingBody->m_pCollisionShapeData;
LABEL_6:
    __asm { qmfc2        $a3, $vf5 }
    _$V0 = SLODWORD(pCollidingBody->m_frictionCoefficient);
    __asm
    {
      lqc2         $vf2, 0x10($v1)
      qmtc2        $v0, $vf3
      lqc2         $vf1, 0xE0($s0)
      lqc2         $vf4, 0x30($v1)
      vmulx.xyz    $vf2, $vf2, $vf3
      vadd.xyz     $vf1, $vf1, $vf5
      vadd.xyz     $vf2, $vf2, $vf4
      qmfc2        $a2, $vf2
      sqc2         $vf1, 0xE0($s0)
    }
    CalculateTorqueFromPositionedForce__16CB4CollidingBodyPQ29GtMathPs26CGtV3dGQ29GtMathPs26CGtV3dT2(
      pCollidingBody,
      &v15,
      _$A2,
      _$A3);
    __asm
    {
      lqc2         $vf1, 0xF0($s0)
      lqc2         $vf2, 0x40+var_30($sp)
      vadd.xyz     $vf1, $vf1, $vf2
      sqc2         $vf1, 0xF0($s0)
    }
    goto LABEL_7;
  }
  if ( pCollidingBody->m_bodyType == 7LL )
  {
    _$V1 = pCollidingBody->m_pCollisionShapeData;
    goto LABEL_6;
  }
  __asm
  {
    lqc2         $vf1, 0xE0($s0)
    vadd.xyz     $vf1, $vf1, $vf5
    sqc2         $vf1, 0xE0($s0)
  }
LABEL_7:
  result = Integrate__16CB4CollidingBodyf(_$S0, a2);
  __asm { lq           $s0, 0x40+var_10($sp) }
  return result;
}

// CB4CollidingBody::Integrate(float)
__int64 __usercall Integrate__16CB4CollidingBodyf@<$v0>(B4CollidingBody *_$A0@<$a0>, float a2@<$f12>)
{
  __int64 result; // $v0
  float v32; // [sp+30h] [-A0h] BYREF
  float v33; // [sp+34h] [-9Ch]
  float v34; // [sp+38h] [-98h]

  v32 = a2;
  v33 = a2;
  v34 = a2;
  __asm { lqc2         $vf6, 0xD0+var_A0($sp) }
  if ( _$A0->m_bIsStaticOrKinematic )
    _$A0->m_collisionFilterMask2 = 0;
  __asm { vadd.xyz     $vf9, $vf0, $vf0 }
  if ( _$A0->m_collisionFilterMask2 )
  {
    __asm
    {
      vsub.xyzw    $vf1, $vf0, $vf0
      sqc2         $vf9, 0xC0($a0)
      sqc2         $vf1, 0xA0($a0)
      sqc2         $vf1, 0xD0+var_A0($sp)
      sqc2         $vf9, 0xD0($a0)
    }
    _$V0 = _$A0->m_pCollisionShapeData;
    __asm
    {
      lq           $v1, 0x20($v0)
      sqc2         $vf9, 0xE0($a0)
      sq           $v1, 0xB0($a0)
      sqc2         $vf9, 0xF0($a0)
      sqc2         $vf9, 0x100($a0)
      sqc2         $vf9, 0x110($a0)
      sqc2         $vf9, 0xD0+var_A0($sp)
      sqc2         $vf9, 0x120($a0)
    }
    _$A0->m_collision_detail.impulse_magnitude_or_penetration = 0.0;
    _$A0->m_collision_detail.contact_status_flags = 0;
    _$A0->m_bHasMoved = 0;
    _$A0->m_bCollidedThisFrame = 0;
    __asm { lqc2         $vf2, 0xE0($a0) }
  }
  else
  {
    __asm { lqc2         $vf2, 0xE0($a0) }
  }
  __asm
  {
    lqc2         $vf3, 0x100($a0)
    vmul.xyz     $vf2, $vf2, $vf6
    vadd.xyz     $vf3, $vf3, $vf2
    sqc2         $vf9, 0xD0+var_A0($sp)
  }
  _$F3 = 1.0;
  __asm { lqc2         $vf2, 0xA0($a0) }
  _$V0 = COERCE_INT(1.0 / _$A0->m_mass);
  __asm
  {
    qmtc2        $v0, $vf1
    vmulx.xyz    $vf1, $vf3, $vf1
    vmove.xyzw   $vf4, $vf2
    vadd.xyz     $vf1, $vf2, $vf1
    vadd.xyz     $vf4, $vf0, $vf1
    sqc2         $vf4, 0xD0+var_A0($sp)
    lqc2         $vf2, 0xF0($a0)
    lqc2         $vf1, 0x110($a0)
    vmul.xyz     $vf2, $vf2, $vf6
    vadd.xyz     $vf1, $vf1, $vf2
    sqc2         $vf1, 0x110($a0)
    sqc2         $vf9, 0xE0($a0)
    sqc2         $vf9, 0xF0($a0)
    sqc2         $vf4, 0xA0($a0)
    sqc2         $vf9, 0x100($a0)
  }
  if ( v33 > 120.0 )
  {
    _$V0 = COERCE_INT(120.0);
    __asm
    {
      vmove.xyzw   $vf1, $vf4
      qmtc2        $v0, $vf2
      vaddx.y      $vf1, $vf0, $vf2
      vadd.xyz     $vf4, $vf0, $vf1
      sqc2         $vf4, 0xA0($a0)
    }
  }
  __asm
  {
    lqc2         $vf1, 0x110($a0)
    lqc2         $vf5, 0xD0($a0)
    vaddw.x      $vf4, $vf0, $vf0
    sqc2         $vf9, 0xD0+var_A0($sp)
    vadd.xyz     $vf5, $vf5, $vf1
    sqc2         $vf5, 0xD0($a0)
  }
  _$A3 = &_$A0->m_localInvInertiaPrincipalX;
  __asm
  {
    sqc2         $vf9, 0x110($a0)
    lqc2         $vf3, 0x30($a0)
    vmove.xyzw   $vf14, $vf4
    lqc2         $vf1, 0x20($v0)
    lqc2         $vf2, 0x10($v0)
    vmulax.xyz   $A, $vf3, $vf5
    vmadday.xyz  $A, $vf2, $vf5
    vmaddz.xyz   $vf2, $vf1, $vf5
    vmul.xyz     $vf1, $vf2, $vf2
    sqc2         $vf2, 0xC0($a0)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf4, $vf1
    qmfc2        $v0, $vf1
  }
  if ( *&_$V0 > 10000.0 )
  {
    __asm
    {
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf1.x
      vwaitq
      vmulq.xyz    $vf2, $vf2, $Q
      rsqrt        $f0, $f3
      vmove.xyzw   $vf1, $vf2
    }
    _$V0 = COERCE_INT(0.94999999);
    _$V1 = COERCE_INT(_$F0 * 100.0);
    __asm
    {
      sqc2         $vf1, 0xC0($a0)
      qmtc2        $v0, $vf3
      qmtc2        $v1, $vf2
      vmulx.xyz    $vf5, $vf5, $vf3
      vmulx.xyz    $vf1, $vf1, $vf2
      sqc2         $vf5, 0xD0($a0)
      sqc2         $vf1, 0xC0($a0)
    }
  }
  _$V0 = _$A0->m_pCollisionShapeData;
  __asm
  {
    lqc2         $vf1, 0xA0($a0)
    lqc2         $vf2, 0x30($v0)
    vmul.xyz     $vf1, $vf1, $vf6
    vadd.xyz     $vf2, $vf2, $vf1
    sqc2         $vf2, 0x30($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf3, 0xC0($a0)
    lqc2         $vf1, 0x20($v1)
    vmul.xyz     $vf3, $vf3, $vf6
    vopmula      $A, $vf1, $vf3
    vopmsub      $vf2, $vf3, $vf1
    vsub.xyz     $vf1, $vf1, $vf2
    sqc2         $vf1, 0x20($v1)
    lqc2         $vf1, 0x10($v0)
    vopmula      $A, $vf1, $vf3
    vopmsub      $vf2, $vf3, $vf1
    vsub.xyz     $vf1, $vf1, $vf2
    sqc2         $vf1, 0x10($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf1, 0($v1)
    vopmula      $A, $vf1, $vf3
    vopmsub      $vf3, $vf3, $vf1
    vsub.xyz     $vf1, $vf1, $vf3
    sqc2         $vf1, 0($v1)
    lqc2         $vf3, 0($v1)
    lqc2         $vf4, 0x10($v1)
    vmul.xyz     $vf1, $vf3, $vf3
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf14, $vf1
    lqc2         $vf5, 0x20($v1)
    vmove.xyzw   $vf7, $vf3
    vmul.xyz     $vf2, $vf4, $vf4
    vnop
    vnop
    vnop
    vrsqrt       $Q, $vf0.w, $vf1.x
    qmfc2        $v0, $vf1
  }
  _$V0 = COERCE_INT(_sqrtf(*&_$V0));
  __asm
  {
    qmtc2        $v0, $vf6
    vwaitq
    vmulq.xyz    $vf7, $vf7, $Q
    vmove.xyzw   $vf8, $vf4
    vadday.x     $A, $vf2, $vf2
    vmaddz.x     $vf2, $vf14, $vf2
    vmul.xyz     $vf1, $vf5, $vf5
    vmove.xyzw   $vf4, $vf11
    vnop
    vnop
    vnop
    vrsqrt       $Q, $vf0.w, $vf2.x
    qmfc2        $v0, $vf2
  }
  _$V0 = COERCE_INT(_sqrtf(*&_$V0));
  __asm
  {
    qmtc2        $v0, $vf3
    vwaitq
    vmulq.xyz    $vf8, $vf8, $Q
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf14, $vf1
    vaddx.x      $vf4, $vf0, $vf6
    vnop
    vnop
    vnop
    vrsqrt       $Q, $vf0.w, $vf1.x
    qmfc2        $v0, $vf1
  }
  _$V0 = COERCE_INT(_sqrtf(*&_$V0));
  __asm
  {
    qmtc2        $v0, $vf2
    vwaitq
    vmulq.xyz    $vf5, $vf5, $Q
    vaddx.y      $vf4, $vf0, $vf3
    vaddx.z      $vf4, $vf0, $vf2
    vmove.xyzw   $vf1, $vf5
    qmfc2        $v0, $vf4
    sqc2         $vf7, 0($v1)
    sqc2         $vf8, 0x10($v1)
    sqc2         $vf1, 0x20($v1)
  }
  if ( *&_$V0 > 0.0 )
  {
    __asm { sqc2         $vf4, 0xD0+var_A0($sp) }
    if ( v33 <= 0.0 )
    {
      __asm { lqc2         $vf1, 0($v1) }
LABEL_23:
      __asm
      {
        lqc2         $vf3, 0x20($v1)
        vopmula      $A, $vf3, $vf1
        vopmsub      $vf1, $vf1, $vf3
        vmul.xyz     $vf2, $vf1, $vf1
        sqc2         $vf1, 0x10($v1)
        vadday.x     $A, $vf2, $vf2
        vmaddz.x     $vf2, $vf14, $vf2
        vnop
        vnop
        vnop
        vrsqrt       $Q, $vf0.w, $vf2.x
        vwaitq
        vmulq.xyz    $vf1, $vf1, $Q
        vopmula      $A, $vf1, $vf3
        vopmsub      $vf3, $vf3, $vf1
        sqc2         $vf1, 0x10($v1)
        vmul.xyz     $vf2, $vf3, $vf3
        sqc2         $vf3, 0($v1)
        vadday.x     $A, $vf2, $vf2
        vmaddz.x     $vf2, $vf14, $vf2
        vnop
        vnop
        vnop
        vrsqrt       $Q, $vf0.w, $vf2.x
        vwaitq
        vmulq.xyz    $vf3, $vf3, $Q
        sqc2         $vf3, 0($v1)
      }
      goto LABEL_25;
    }
    __asm { sqc2         $vf4, 0xD0+var_A0($sp) }
    if ( v34 > 0.0 )
    {
      __asm
      {
        lqc2         $vf5, 0x10($v1)
        vaddw.x      $vf4, $vf0, $vf0
        lqc2         $vf3, 0x20($v1)
        lqc2         $vf2, 0($v1)
        vmul.xyz     $vf1, $vf5, $vf3
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf4, $vf1
        vmul.xyz     $vf3, $vf3, $vf2
        vaddx.x      $vf10, $vf0, $vf1
        vmul.xyz     $vf2, $vf2, $vf5
        vadday.x     $A, $vf3, $vf3
        vmaddz.x     $vf3, $vf4, $vf3
        vadday.x     $A, $vf2, $vf2
        vmaddz.x     $vf2, $vf4, $vf2
        vaddx.y      $vf10, $vf0, $vf3
        vaddx.z      $vf10, $vf0, $vf2
        vabs.xyz     $vf2, $vf10
        vmove.xyzw   $vf1, $vf2
        qmfc2        $v0, $vf1
        sqc2         $vf1, 0xD0+var_A0($sp)
      }
      if ( *&_$V0 >= v33 )
      {
        __asm
        {
          sqc2         $vf2, 0xD0+var_A0($sp)
          sqc2         $vf2, 0xD0+var_A0($sp)
        }
        if ( v33 < v34 )
        {
          __asm { lqc2         $vf1, 0($v1) }
          goto LABEL_23;
        }
        __asm { lqc2         $vf1, 0x10($v1) }
      }
      else
      {
        __asm { sqc2         $vf1, 0xD0+var_A0($sp) }
        if ( *&_$V0 < v34 )
        {
          __asm
          {
            lqc2         $vf1, 0x20($v1)
            lqc2         $vf3, 0x10($v1)
            vopmula      $A, $vf3, $vf1
            vopmsub      $vf1, $vf1, $vf3
            vmul.xyz     $vf2, $vf1, $vf1
            sqc2         $vf1, 0($v1)
            vadday.x     $A, $vf2, $vf2
            vmaddz.x     $vf2, $vf14, $vf2
            vnop
            vnop
            vnop
            vrsqrt       $Q, $vf0.w, $vf2.x
            vwaitq
            vmulq.xyz    $vf1, $vf1, $Q
            vopmula      $A, $vf1, $vf3
            vopmsub      $vf3, $vf3, $vf1
            sqc2         $vf1, 0($v1)
            vmul.xyz     $vf2, $vf3, $vf3
            sqc2         $vf3, 0x20($v1)
            vadday.x     $A, $vf2, $vf2
            vmaddz.x     $vf2, $vf14, $vf2
            vnop
            vnop
            vnop
            vrsqrt       $Q, $vf0.w, $vf2.x
            vwaitq
            vmulq.xyz    $vf3, $vf3, $Q
            sqc2         $vf3, 0x20($v1)
          }
          goto LABEL_25;
        }
        __asm { lqc2         $vf1, 0x10($v1) }
      }
    }
    else
    {
      __asm { lqc2         $vf1, 0x10($v1) }
    }
    __asm
    {
      lqc2         $vf3, 0($v1)
      vopmula      $A, $vf3, $vf1
      vopmsub      $vf1, $vf1, $vf3
      vmul.xyz     $vf2, $vf1, $vf1
      sqc2         $vf1, 0x20($v1)
      vadday.x     $A, $vf2, $vf2
      vmaddz.x     $vf2, $vf14, $vf2
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf2.x
      vwaitq
      vmulq.xyz    $vf1, $vf1, $Q
      vopmula      $A, $vf1, $vf3
      vopmsub      $vf3, $vf3, $vf1
      sqc2         $vf1, 0x20($v1)
      vmul.xyz     $vf2, $vf3, $vf3
      sqc2         $vf3, 0x10($v1)
      vadday.x     $A, $vf2, $vf2
      vmaddz.x     $vf2, $vf14, $vf2
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf2.x
      vwaitq
      vmulq.xyz    $vf3, $vf3, $Q
      sqc2         $vf3, 0x10($v1)
    }
    goto LABEL_25;
  }
  __asm
  {
    vopmula      $A, $vf8, $vf1
    vopmsub      $vf2, $vf1, $vf8
    vmul.xyz     $vf1, $vf2, $vf2
    sqc2         $vf2, 0($v1)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf14, $vf1
    vnop
    vnop
    vnop
    vrsqrt       $Q, $vf0.w, $vf1.x
    vwaitq
    vmulq.xyz    $vf2, $vf2, $Q
    vopmula      $A, $vf2, $vf8
    vopmsub      $vf3, $vf8, $vf2
    sqc2         $vf2, 0($v1)
    vmul.xyz     $vf1, $vf3, $vf3
    sqc2         $vf3, 0x20($v1)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf14, $vf1
    vnop
    vnop
    vnop
    vrsqrt       $Q, $vf0.w, $vf1.x
    vwaitq
    vmulq.xyz    $vf3, $vf3, $Q
    sqc2         $vf3, 0x20($v1)
  }
LABEL_25:
  _$V0 = _$A0->m_pCollisionShapeData;
  _$V1 = &_$A0->m_initialMatrix_Row0;
  __asm
  {
    lqc2         $vf2, 0x120($a0)
    lqc2         $vf1, 0x30($v0)
    vadd.xyz     $vf1, $vf1, $vf2
    sqc2         $vf1, 0x30($v0)
    sqc2         $vf9, 0x120($a0)
    sqc2         $vf9, 0xD0+var_A0($sp)
    lqc2         $vf1, 0xD0+var_30($sp)
    lqc2         $vf2, 0xD0+var_20($sp)
    lqc2         $vf10, 0($v0)
    vaddx.x      $vf1, $vf0, $vf10
    vaddy.x      $vf2, $vf0, $vf10
    lqc2         $vf9, 0x10($v0)
    lqc2         $vf7, 0x20($v0)
    lqc2         $vf6, 0xD0+var_10($sp)
    vmove.xyzw   $vf3, $vf1
    vaddz.x      $vf6, $vf0, $vf10
    vmove.xyzw   $vf11, $vf2
    vaddx.y      $vf3, $vf0, $vf9
    sqc2         $vf1, 0xD0+var_30($sp)
    vaddy.y      $vf11, $vf0, $vf9
    sqc2         $vf2, 0xD0+var_20($sp)
    sqc2         $vf3, 0xD0+var_30($sp)
    sqc2         $vf11, 0xD0+var_20($sp)
    sqc2         $vf6, 0xD0+var_10($sp)
    vmove.xyzw   $vf13, $vf6
    vaddz.y      $vf13, $vf0, $vf9
    vmove.xyzw   $vf8, $vf3
    vmove.xyzw   $vf4, $vf11
    vaddx.z      $vf8, $vf0, $vf7
    vmove.xyzw   $vf5, $vf13
    vaddy.z      $vf4, $vf0, $vf7
    lqc2         $vf2, 0x10($a0)
    vaddz.z      $vf5, $vf0, $vf7
    lqc2         $vf1, 0x20($a0)
    lqc2         $vf3, 0($a0)
    vmulax.xyz   $A, $vf3, $vf8
    vmadday.xyz  $A, $vf2, $vf8
    vmaddz.xyz   $vf6, $vf1, $vf8
    vmulax.xyz   $A, $vf3, $vf4
    vmadday.xyz  $A, $vf2, $vf4
    vmaddz.xyz   $vf11, $vf1, $vf4
    vmulax.xyz   $A, $vf3, $vf5
    vmadday.xyz  $A, $vf2, $vf5
    vmaddz.xyz   $vf12, $vf1, $vf5
    sqc2         $vf8, 0xD0+var_30($sp)
    sqc2         $vf4, 0xD0+var_20($sp)
    sqc2         $vf13, 0xD0+var_10($sp)
    sqc2         $vf9, 0xD0+var_C0($sp)
    sqc2         $vf7, 0xD0+var_B0($sp)
    sqc2         $vf5, 0xD0+var_10($sp)
    sqc2         $vf8, 0xD0+var_60($sp)
    sqc2         $vf4, 0xD0+var_50($sp)
    sqc2         $vf5, 0xD0+var_40($sp)
    sqc2         $vf6, 0xD0+var_30($sp)
    sqc2         $vf10, 0xD0+var_D0($sp)
    sqc2         $vf11, 0xD0+var_20($sp)
    sqc2         $vf12, 0xD0+var_10($sp)
    sqc2         $vf6, 0x30($a0)
    sqc2         $vf11, 0x40($a0)
    sqc2         $vf12, 0x50($a0)
    sqc2         $vf6, 0xD0+var_90($sp)
    lqc2         $vf2, 0x20($a3)
    lqc2         $vf1, 0x10($a3)
    sqc2         $vf11, 0xD0+var_80($sp)
    vmulax.xyz   $A, $vf10, $vf6
    vmadday.xyz  $A, $vf9, $vf6
    vmaddz.xyz   $vf3, $vf7, $vf6
    vmulax.xyz   $A, $vf10, $vf1
    vmadday.xyz  $A, $vf9, $vf1
    vmaddz.xyz   $vf4, $vf7, $vf1
    vmulax.xyz   $A, $vf10, $vf2
    vmadday.xyz  $A, $vf9, $vf2
    vmaddz.xyz   $vf5, $vf7, $vf2
    sqc2         $vf12, 0xD0+var_70($sp)
    sqc2         $vf4, 0x40($a0)
    sqc2         $vf5, 0x50($a0)
    sqc2         $vf3, 0x30($a0)
    sqc2         $vf4, 0xD0+var_60($sp)
    sqc2         $vf5, 0xD0+var_50($sp)
    sqc2         $vf4, 0xD0+var_90($sp)
    sqc2         $vf5, 0xD0+var_80($sp)
    sqc2         $vf3, 0xD0+var_70($sp)
    sqc2         $vf3, 0xD0+var_A0($sp)
    lqc2         $vf3, 0($v0)
    sqc2         $vf3, 0x60($a0)
    vmove.xyzw   $vf4, $vf3
    lqc2         $vf1, 0x10($v0)
    sqc2         $vf1, 0x70($a0)
    vmove.xyzw   $vf9, $vf1
    vaddy.x      $vf9, $vf0, $vf3
    lqc2         $vf2, 0x20($v0)
    vmove.xyzw   $vf7, $vf9
    sqc2         $vf2, 0x80($a0)
    vmove.xyzw   $vf8, $vf2
    vaddz.x      $vf8, $vf0, $vf3
    lqc2         $vf3, 0x30($v0)
    vmove.xyzw   $vf6, $vf8
    sqc2         $vf3, 0x90($a0)
    lqc2         $vf2, 0x10($v1)
    vaddx.y      $vf4, $vf0, $vf2
    lqc2         $vf1, 0x20($v1)
    vmove.xyzw   $vf5, $vf4
    vaddy.z      $vf7, $vf0, $vf1
    vaddz.y      $vf6, $vf0, $vf2
    vaddx.z      $vf5, $vf0, $vf1
    vmuly.xyz    $vf2, $vf7, $vf3
    vmulx.xyz    $vf1, $vf5, $vf3
    vmulz.xyz    $vf3, $vf6, $vf3
    vadd.xyz     $vf1, $vf1, $vf2
    sqc2         $vf4, 0x60($a0)
    vadd.xyz     $vf1, $vf1, $vf3
    sqc2         $vf9, 0x70($a0)
    vsub.xyz     $vf1, $vf0, $vf1
    sqc2         $vf8, 0x80($a0)
    sqc2         $vf5, 0x60($a0)
    sqc2         $vf7, 0x70($a0)
    sqc2         $vf6, 0x80($a0)
    sqc2         $vf1, 0x30($v1)
    lqc2         $vf3, 0xA0($a0)
    vmul.xyz     $vf1, $vf3, $vf3
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf14, $vf1
    qmfc2        $v0, $vf1
    vmove.xyzw   $vf2, $vf3
    vadd.xyz     $vf2, $vf0, $vf2
    sqc2         $vf2, 0xA0($a0)
  }
  if ( *&_$V0 >= 2.3283064e-10 )
  {
    __asm
    {
      vmul.xyz     $vf1, $vf3, $vf3
      sqc2         $vf3, 0xB0($a0)
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf14, $vf1
      lqc2         $vf4, 0xA0($a0)
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf1.x
      qmfc2        $v0, $vf1
    }
    _$V0 = COERCE_INT(_sqrtf(*&_$V0));
    __asm
    {
      qmtc2        $v0, $vf2
      vwaitq
      vmulq.xyz    $vf3, $vf3, $Q
      qmfc2        $v1, $vf2
      sqc2         $vf3, 0xB0($a0)
    }
    result = _$V1;
    __asm
    {
      qmtc2        $v0, $vf1
      vmr32.w      $vf4, $vf1
      sqc2         $vf4, 0xA0($a0)
    }
  }
  else
  {
    _$V0 = COERCE_INT(0.0);
    __asm
    {
      lqc2         $vf1, 0xA0($a0)
      qmtc2        $v0, $vf2
    }
    _$V1 = _$A0->m_pCollisionShapeData;
    __asm
    {
      vmr32.w      $vf1, $vf2
      sqc2         $vf1, 0xA0($a0)
      lq           $v0, 0x20($v1)
      sq           $v0, 0xB0($a0)
    }
  }
  return result;
}

// CB4CollidingBody::ApplyTotalTranslation(void)
__int64 __fastcall ApplyTotalTranslation__16CB4CollidingBody(B4CollidingBody *_$A0)
{
  __int64 result; // $v0

  LODWORD(result) = _$A0->m_pCollisionShapeData;
  __asm
  {
    vadd.xyz     $vf3, $vf0, $vf0
    lqc2         $vf2, 0x120($a0)
    lqc2         $vf1, 0x30($v0)
  }
  _$V1 = &_$A0->m_initialMatrix_Row0;
  __asm
  {
    vadd.xyz     $vf1, $vf1, $vf2
    sqc2         $vf1, 0x30($v0)
    sqc2         $vf3, 0x120($a0)
    sqc2         $vf3, 0x10+var_10($sp)
  }
  result = result;
  __asm
  {
    lqc2         $vf3, 0($v0)
    sqc2         $vf3, 0x60($a0)
    vmove.xyzw   $vf4, $vf3
    lqc2         $vf1, 0x10($v0)
    sqc2         $vf1, 0x70($a0)
    vmove.xyzw   $vf9, $vf1
    vaddy.x      $vf9, $vf0, $vf3
    lqc2         $vf2, 0x20($v0)
    vmove.xyzw   $vf7, $vf9
    sqc2         $vf2, 0x80($a0)
    vmove.xyzw   $vf8, $vf2
    vaddz.x      $vf8, $vf0, $vf3
    lqc2         $vf3, 0x30($v0)
    vmove.xyzw   $vf5, $vf8
    sqc2         $vf3, 0x90($a0)
    lqc2         $vf2, 0x10($v1)
    vaddx.y      $vf4, $vf0, $vf2
    lqc2         $vf1, 0x20($v1)
    vmove.xyzw   $vf6, $vf4
    vaddy.z      $vf7, $vf0, $vf1
    vaddz.y      $vf5, $vf0, $vf2
    vaddx.z      $vf6, $vf0, $vf1
    vmulx.xyz    $vf1, $vf6, $vf3
    vmuly.xyz    $vf2, $vf7, $vf3
    vmulz.xyz    $vf3, $vf5, $vf3
    vadd.xyz     $vf1, $vf1, $vf2
    sqc2         $vf4, 0x60($a0)
    vadd.xyz     $vf1, $vf1, $vf3
    sqc2         $vf9, 0x70($a0)
    vsub.xyz     $vf1, $vf0, $vf1
    sqc2         $vf8, 0x80($a0)
    sqc2         $vf5, 0x80($a0)
    sqc2         $vf6, 0x60($a0)
    sqc2         $vf7, 0x70($a0)
    sqc2         $vf1, 0x30($v1)
  }
  return result;
}

void __fastcall Release__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  *&pCollidingBody->m_streamedTrackUnitIndex = 0;
}

void __fastcall Destruct__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  *&pCollidingBody->m_streamedTrackUnitIndex = 0;
}

// CB4CollidingBody::SetRealisticMomentsOfInertia(void)
__int64 __fastcall SetRealisticMomentsOfInertia__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  float m_mass; // $f4
  float v4; // $f3
  float v14; // [sp+4h] [-Ch]
  float v15; // [sp+8h] [-8h]

  _$V1 = pCollidingBody;
  __asm
  {
    lqc2         $vf1, 0x1D0($v1)
    lqc2         $vf2, 0x1C0($v1)
    vsuby.y      $vf3, $vf2, $vf1
    vsubz.z      $vf4, $vf2, $vf1
    sqc2         $vf3, 0x10+var_10($sp)
    vsubx.x      $vf2, $vf2, $vf1
    qmfc2        $v0, $vf2
    vmove.xyzw   $vf1, $vf5
  }
  m_mass = pCollidingBody->m_mass;
  __asm { sqc2         $vf4, 0x10+var_10($sp) }
  v4 = (*&_$V0 * *&_$V0) + (v15 * v15);
  _$A1 = COERCE_INT(((m_mass * ((*&_$V0 * *&_$V0) + (v14 * v14))) * 0.083333001) * 6.0);
  __asm { qmtc2        $a1, $vf4 }
  _$V0 = COERCE_INT(((m_mass * ((v14 * v14) + (v15 * v15))) * 0.083333001) * 6.0);
  __asm { qmtc2        $v0, $vf2 }
  _$V1 = COERCE_INT(((m_mass * v4) * 0.083333001) * 6.0);
  __asm
  {
    vaddx.x      $vf1, $vf0, $vf2
    qmtc2        $v1, $vf3
    qmfc2        $v0, $vf1
  }
  _$V0 = COERCE_INT(1.0 / *&_$V0);
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.x      $vf1, $vf0, $vf2
    vaddx.y      $vf1, $vf0, $vf3
    sqc2         $vf1, 0x10+var_10($sp)
  }
  _$V0 = COERCE_INT(1.0 / v14);
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    vaddx.z      $vf1, $vf0, $vf4
    sqc2         $vf1, 0x10+var_10($sp)
  }
  _$V0 = COERCE_INT(1.0 / v15);
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x10+var_10($sp)
    qmfc2        $v0, $vf1
    sqc2         $vf1, 0x10+var_10($sp)
  }
  return SetMomentOfInertia__16CB4CollidingBodyfff(pCollidingBody, _$A1, v15);
}

// CB4CollidingBody::CacheWorldTriangles(void)
__int64 __fastcall CacheWorldTriangles__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  _$V0 = pCollidingBody;
  _$V1 = pCollidingBody->m_pCollisionShapeData;
  __asm
  {
    lqc2         $vf1, 0x1B0($v0)
    vmove.w      $vf3, $vf1
    lqc2         $vf2, 0x30($v1)
    vadd.xyz     $vf3, $vf0, $vf2
    qmfc2        $a1, $vf3
  }
  return CacheWorldTriangles__16CB4CollidingBodyGQ29GtMathPs29CGtSphere(pCollidingBody, _$A1);
}

// CB4CollidingBody::CacheWorldTriangles(GtMathPs2::CGtSphere)
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall CacheWorldTriangles__16CB4CollidingBodyGQ29GtMathPs29CGtSphere(
        B4CollidingBody *pCollidingBody,
        __int64 _$A1)
{
  signed __int8 v11; // $v0
  __int64 m_trackCollisionResult; // $a1
  signed __int8 v14; // $v0
  __int64 result; // $v0

  __asm
  {
    sq           $s0, 0x60+var_10($sp)
    sq           $s1, 0x60+var_20($sp)
    sq           $s2, 0x60+var_30($sp)
    sq           $s3, 0x60+var_40($sp)
    sq           $s4, 0x60+var_50($sp)
    por          $s1, $zero, $a1
  }
  pCollidingBody->m_pGlobalWorldTriangleCache->num_triangles = 0;
  16CB4CollidingBody__mbCacheOverflowed = 0;
  _$V0 = pCollidingBody->m_pCollisionShapeData;
  __asm { lq           $a1, 0x30($v0) }
  v11 = TestPosition__16CB4StreamedTrackGQ29GtMathPs26CGtV3d(
          gWorld.m_StreamedTrackPlayers[pCollidingBody->m_streamedTrackPlayerID],
          _$A1);
  pCollidingBody->m_trackCollisionResult = v11;
  if ( v11 == -1LL && pCollidingBody->m_bodyType != 1LL )
  {
    if ( gGame.stagePtr != &gGame.twoPlayerStage )
    {
      m_trackCollisionResult = pCollidingBody->m_trackCollisionResult;
      goto LABEL_7;
    }
    _$V1 = pCollidingBody->m_pCollisionShapeData;
    v14 = 1 - pCollidingBody->m_streamedTrackPlayerID;
    pCollidingBody->m_streamedTrackPlayerID = v14;
    __asm { lq           $a1, 0x30($v1) }
    pCollidingBody->m_trackCollisionResult = TestPosition__16CB4StreamedTrackGQ29GtMathPs26CGtV3d(
                                               gWorld.m_StreamedTrackPlayers[v14],
                                               _$A1);
  }
  m_trackCollisionResult = pCollidingBody->m_trackCollisionResult;
LABEL_7:
  result = 504LL;
  if ( m_trackCollisionResult >= 0 )
  {
    __asm { por          $a2, $zero, $s1 }
    result = IntersectSphereWithUnit__16CB4StreamedTrackUiGQ29GtMathPs29CGtSpherePFRC28CGtPolygonIntersectionResultPv_bPv(
               gWorld.m_StreamedTrackPlayers[pCollidingBody->m_streamedTrackPlayerID],
               m_trackCollisionResult,
               _$A2,
               CacheCallback__FRC28CGtPolygonIntersectionResultPv,
               *&pCollidingBody);
  }
  __asm
  {
    lq           $s0, 0x60+var_10($sp)
    lq           $s1, 0x60+var_20($sp)
    lq           $s2, 0x60+var_30($sp)
    lq           $s3, 0x60+var_40($sp)
    lq           $s4, 0x60+var_50($sp)
  }
  return result;
}

// CB4CollidingBody::HasFallenThroughWorld(void)
__int64 __fastcall HasFallenThroughWorld__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  __int64 result; // $v0
  __int64 v5; // $v0
  bool v6; // dc
  float v8; // [sp+4h] [-9Ch]
  __int128 v9; // [sp+10h] [-90h] BYREF
  _BYTE v10[112]; // [sp+30h] [-70h] BYREF

  _$V1 = pCollidingBody->m_pCollisionShapeData;
  __asm
  {
    lq           $v0, 0x30($v1)
    sq           $v0, 0xA0+var_A0($sp)
  }
  result = 0LL;
  if ( v8 >= -1000.0 )
    return result;
  _$A3 = pCollidingBody->m_pCollisionShapeData;
  v5 = 1LL;
  do
  {
    v6 = v5 != -1;
    v5 = v5 - 1;
  }
  while ( v6 );
  __asm { lqc2         $vf2, 0x30($a3) }
  _$V0 = COERCE_INT(1000.0);
  __asm
  {
    qmtc2        $v0, $vf1
    sqc2         $vf2, 0xA0+var_80($sp)
    vsubx.y      $vf1, $vf2, $vf1
    sqc2         $vf2, 0xA0+var_90($sp)
    vaddy.y      $vf2, $vf0, $vf1
    sqc2         $vf2, 0xA0+var_80($sp)
  }
  return IntersectLineNearestWithWorld__16CB4StreamedTrackRC7CGtLineP28CGtPolygonIntersectionResult(
           gWorld.m_StreamedTrackPlayers[pCollidingBody->m_streamedTrackPlayerID],
           &v9,
           v10) ^ 1u;
}

// CB4CollidingBody::StartCrashing(unsigned char, CB4CrashStartInfo *)
__int64 __fastcall StartCrashing__16CB4CollidingBodyUcP17CB4CrashStartInfo(
        B4CollidingBody *pCollidingBody,
        uint8_t crashStartInfo)
{
  __int64 result; // $v0

  result = pCollidingBody->m_collisionFilterMask4;
  if ( pCollidingBody->m_collisionFilterMask4 )
    return result;
  result = 1LL;
  pCollidingBody->unk_207 = crashStartInfo;
  pCollidingBody->m_collisionFilterMask4 = 1;
  pCollidingBody->m_collisionFilterMask2 = 0;
  return result;
}

// CB4CollidingBody::StopCrashing(void)
__int64 __fastcall StopCrashing__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  __int64 result; // $v0

  __asm { sq           $s0, 0x30+var_10($sp) }
  pCollidingBody->m_collisionFilterMask4 = 0;
  pCollidingBody->m_collisionFilterMask2 = 0;
  pCollidingBody->unk_207 = 15;
  result = memset(&pCollidingBody->m_collisionPoint_world, 0, 0x60uLL);
  __asm { vadd.xyz     $vf1, $vf0, $vf0 }
  LOWORD(pCollidingBody->m_collision_detail.collision_tag_or_surface_type) = 0;
  __asm
  {
    sqc2         $vf1, 0x140($s0)
    sqc2         $vf1, 0x150($s0)
    sqc2         $vf1, 0x160($s0)
  }
  pCollidingBody->m_collision_detail.impulse_magnitude_or_penetration = 0.0;
  pCollidingBody->m_collision_detail.contact_status_flags = 0;
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    sqc2         $vf1, 0x30+var_30($sp)
  }
  return result;
}

// CB4CollidingBody::CalculateEnergyFromCollisionImpulse(CB4CollidingBody *, CB4CollidingBody *, GtMathPs2::CGtV3d, float)
// local variable allocation has failed, the output may be wrong!
float __usercall CalculateEnergyFromCollisionImpulse__16CB4CollidingBodyP16CB4CollidingBodyT1GQ29GtMathPs26CGtV3df@<$f0>(
        B4CollidingBody *_$A0@<$a0>,
        B4CollidingBody *_$A1@<$a1>,
        __int64 _$A2@<$a2>,
        float a4@<$f12>)
{
  _$V0 = _$A0->m_pCollisionShapeData;
  __asm
  {
    qmtc2        $a2, $vf5
    lqc2         $vf3, 0xC0($a0)
    lqc2         $vf1, 0x30($v0)
    vsub.xyz     $vf1, $vf5, $vf1
    lqc2         $vf2, 0xA0($a0)
    vopmula      $A, $vf3, $vf1
    vopmsub      $vf4, $vf1, $vf3
    vadd.xyz     $vf4, $vf4, $vf2
  }
  if ( *&_$A1 )
  {
    _$V0 = _$A1->m_pCollisionShapeData;
    __asm
    {
      lqc2         $vf3, 0xC0($a1)
      lqc2         $vf1, 0x30($v0)
      vsub.xyz     $vf1, $vf5, $vf1
      lqc2         $vf2, 0xA0($a1)
      vopmula      $A, $vf3, $vf1
      vopmsub      $vf1, $vf1, $vf3
      vadd.xyz     $vf1, $vf1, $vf2
    }
  }
  else
  {
    __asm
    {
      vadd.xyz     $vf1, $vf0, $vf0
      sqc2         $vf1, 0x10+var_10($sp)
    }
  }
  __asm
  {
    vsub.xyz     $vf1, $vf1, $vf4
    vaddw.x      $vf2, $vf0, $vf0
    vmul.xyz     $vf1, $vf1, $vf1
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf2, $vf1
  }
  _$V0 = COERCE_INT(a4 * 0.5);
  __asm
  {
    vnop
    vnop
    vnop
    vsqrt        $Q, $vf1.x
    vaddw.x      $vf1, $vf0, $vf0
    vwaitq
    vmulq.x      $vf1, $vf1, $Q
    qmtc2        $v0, $vf2
    vmulx.x      $vf1, $vf1, $vf2
    qmfc2        $v0, $vf1
  }
  return *&_$V0;
}

// CB4CollidingBody::CollideWithWorld(int)
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall CollideWithWorld__16CB4CollidingBodyi(B4CollidingBody *pCollidingBody)
{
  __int64 v3; // $ra
  B4CollidingBody__mGlobalWorldTriangleCache *m_pGlobalWorldTriangleCache; // $a3
  __int64 result; // $v0
  unsigned __int8 v7; // $v0
  unsigned __int8 v9; // $a5
  __int16 v12; // $a6
  float v19; // $f0
  float v21; // $f20
  __int64 m_bodyType; // $v1
  bool v23; // $a0
  float v26; // $f20
  float v27; // $f0
  B4VehicleParams *m_pFullParams; // $a0
  float v30; // $f0
  float v31; // $f1
  int v40; // $f1
  __int64 v47; // $v1
  float v60; // $f0
  __int64 v63; // $v1
  __int64 v68; // $v0
  float v73; // $f0
  __int64 v74; // $a1
  float v76; // $f4
  __int64 v77; // $v1
  float v78; // $f3
  __int64 v79; // $a0
  bool v80; // $v1
  __int64 v82; // $v0
  B4HullCollideHullParams v86; // [sp+10h] [-2B0h] BYREF
  __int16 v88; // [sp+F0h] [-1D0h]
  unsigned __int8 v90; // [sp+160h] [-160h]
  __int128 v93; // [sp+1B0h] [-110h] BYREF
  float v94; // [sp+1D0h] [-F0h]
  float v95; // [sp+1D4h] [-ECh]
  int v96; // [sp+1D8h] [-E8h]
  char v97; // [sp+1DCh] [-E4h]
  __int128 v101; // [sp+220h] [-A0h] BYREF
  __int128 v102; // [sp+230h] [-90h] BYREF
  __int64 v108; // [sp+290h] [-30h]

  __asm { sq           $s0, 0x2C0+var_10($sp) }
  *&_$S0 = *&pCollidingBody;
  __asm { sq           $s1, 0x2C0+var_20($sp) }
  v108 = v3;
  _24CB4HullCollideHullParams(&v86);
  m_pGlobalWorldTriangleCache = _$S0->m_pGlobalWorldTriangleCache;
  _$S0->m_bCollidedThisFrame = 0;
  result = m_pGlobalWorldTriangleCache->num_triangles;
  if ( !m_pGlobalWorldTriangleCache->num_triangles )
  {
    _$S0->m_collision_detail.impulse_magnitude_or_penetration = 0.0;
    _$S0->m_bHasMoved = 0;
LABEL_53:
    _$S0->m_collision_detail.contact_status_flags = 0;
    goto LABEL_54;
  }
  if ( _$S0->m_collisionFilterMask1 == 1LL && gDebugManager.physicsDebug[21] )
  {
    _$S0->m_bHasMoved = BoxWorldCollision__FRC17CGtAxisAlignedBoxRCQ29GtMathPs212CGtMatrix3x4T1P25CB4WorldTriangleCacheBasePQ29GtMathPs26CGtV3dT4P15CB4CollisionTagT4N24(
                          &_$S0->m_aabbMin_world,
                          _$S0->m_pCollisionShapeData,
                          &_$S0->m_initialMatrix_Row0,
                          &m_pGlobalWorldTriangleCache->num_triangles,
                          &_$S0->m_collisionPoint_world,
                          &_$S0->m_collisionNormal_world,
                          &_$S0->m_collision_detail,
                          &_$S0->m_collision_contact_point_other_obj,
                          &_$S0->m_collision_adjusted_impulse);
  }
  else
  {
    v7 = CollideBodyHullWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP16CB4CollidingBody(&v86, _$S0);
    __asm { lq           $v1, 0x2C0+var_170($sp) }
    v9 = v90;
    __asm
    {
      lq           $a0, 0x2C0+var_200($sp)
      lq           $a1, 0x2C0+var_1F0($sp)
    }
    v12 = v88;
    __asm
    {
      lq           $a2, 0x2C0+var_150($sp)
      lq           $a3, 0x2C0+var_140($sp)
      lq           $a4, 0x2C0+var_1E0($sp)
    }
    _$S0->m_bHasMoved = v7;
    __asm { sq           $v1, 0x130($s0) }
    _$S0->m_collisionSurfaceMaterialID = v9;
    __asm
    {
      sq           $a0, 0x150($s0)
      sq           $a1, 0x160($s0)
    }
    LOWORD(_$S0->m_collision_detail.collision_tag_or_surface_type) = v12;
    __asm
    {
      sq           $a2, 0x190($s0)
      sq           $a3, 0x1A0($s0)
      sq           $a4, 0x2C0+var_C0($sp)
    }
  }
  result = _$S0->m_bHasMoved;
  if ( !_$S0->m_bHasMoved )
  {
    _$S0->m_collision_detail.impulse_magnitude_or_penetration = 0.0;
    goto LABEL_53;
  }
  _$V0 = _$S0->m_pCollisionShapeData;
  __asm
  {
    lqc2         $vf4, 0x150($s0)
    lqc2         $vf1, 0x30($v0)
    lqc2         $vf2, 0xC0($s0)
    vsub.xyz     $vf1, $vf4, $vf1
    vopmula      $A, $vf2, $vf1
    vopmsub      $vf3, $vf1, $vf2
    qmfc2        $a1, $vf4
    sqc2         $vf3, 0x2C0+var_80($sp)
    lqc2         $vf3, 0xA0($s0)
    lqc2         $vf1, 0x2C0+var_80($sp)
    vadd.xyz     $vf1, $vf1, $vf3
    sqc2         $vf1, 0x2C0+var_80($sp)
    lq           $a3, 0x160($s0)
    lq           $a2, 0x2C0+var_80($sp)
  }
  CalculateCollisionImpulseWithInanimateObject__16CB4CollidingBodyGQ29GtMathPs26CGtV3dN21fPQ29GtMathPs26CGtV3d(
    _$S0,
    _$A1,
    _$A2,
    _$A3,
    _$S0->m_restitutionCoefficient);
  v21 = v19;
  if ( v19 > 0.0 )
  {
    m_bodyType = _$S0->m_bodyType;
    v23 = 0;
    if ( _$S0->m_bodyType && m_bodyType != 7 )
      v23 = m_bodyType != 8;
    __asm
    {
      vaddw.x      $vf2, $vf0, $vf0
      vaddw.x      $vf3, $vf0, $vf0
      sqc2         $vf2, 0x2C0+var_60($sp)
      sqc2         $vf3, 0x2C0+var_50($sp)
    }
    if ( v23 && _$S0->m_collisionFilterMask4 )
    {
      __asm { lqc2         $vf2, 0x2C0+var_B0($sp) }
      _$V0 = SLODWORD(krImpulseScalar_9499);
      __asm { lq           $a2, 0x150($s0) }
      v26 = v19 * krImpulseScalar_9499;
      __asm
      {
        qmtc2        $v0, $vf1
        vmulx.xyz    $vf2, $vf2, $vf1
        sqc2         $vf2, 0x2C0+var_B0($sp)
      }
      v27 = CalculateEnergyFromCollisionImpulse__16CB4CollidingBodyP16CB4CollidingBodyT1GQ29GtMathPs26CGtV3df(
              _$S0,
              0,
              _$A2,
              v19 * krImpulseScalar_9499);
      __asm
      {
        lqc2         $vf1, 0x150($s0)
        lq           $v0, 0x160($s0)
      }
      m_pFullParams = _$S0->m_pFullParams;
      __asm
      {
        lqc2         $vf2, 0x2C0+var_C0($sp)
        vsub.xyz     $vf1, $vf1, $vf2
      }
      v96 = 1;
      __asm
      {
        sqc2         $vf1, 0x2C0+var_110($sp)
        sq           $v0, 0x2C0+var_100($sp)
      }
      v95 = v26;
      v94 = v27;
      v97 = 0;
      Impact__16CB4VehicleDeformP21CB4VehicleDeformInput(&m_pFullParams->m_vehicleDeform, &v93);
      __asm
      {
        lqc2         $vf3, 0x2C0+var_E0($sp)
        lqc2         $vf2, 0x2C0+var_110($sp)
        vsub.xyz     $vf2, $vf2, $vf3
        lqc2         $vf1, 0x2C0+var_C0($sp)
        lqc2         $vf3, 0x2C0+var_50($sp)
        vmul.xyz     $vf1, $vf1, $vf1
        lqc2         $vf4, 0x160($s0)
        vsub.xyz     $vf4, $vf0, $vf4
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf3, $vf1
        lqc2         $vf3, 0x2C0+var_60($sp)
        vmul.xyz     $vf2, $vf2, $vf4
      }
      v31 = ((1.0 - v30) * (1.0 - v30)) * ((1.0 - v30) * (1.0 - v30));
      _$V0 = COERCE_INT(0.5);
      __asm
      {
        vadday.x     $A, $vf2, $vf2
        vmaddz.x     $vf2, $vf3, $vf2
        qmtc2        $v0, $vf3
        vnop
        vnop
        vnop
        vsqrt        $Q, $vf1.x
        vaddw.x      $vf1, $vf0, $vf0
        vwaitq
        vmulq.x      $vf1, $vf1, $Q
        vmulx.x      $vf1, $vf1, $vf3
        qmfc2        $v0, $vf2
        qmfc2        $v1, $vf1
      }
      _$F2 = 0.0;
      _$F3 = *&_$V1;
      __asm
      {
        max          $f0, $f2
        min          $f0, $f3
      }
      _$V0 = _$F0;
      __asm
      {
        qmtc2        $v0, $vf2
        lqc2         $vf1, 0x120($s0)
        vmulx.xyz    $vf4, $vf4, $vf2
        lqc2         $vf3, 0x2C0+var_B0($sp)
        vadd.xyz     $vf1, $vf1, $vf4
      }
      *&v40 = (((v31 * v31) * (v31 * v31)) * 0.94999999) + 0.050000001;
      __asm { sqc2         $vf1, 0x120($s0) }
      _$V0 = v40;
      __asm
      {
        qmtc2        $v0, $vf1
        vmulx.xyz    $vf3, $vf3, $vf1
      }
      v21 = v26 * *&v40;
      __asm { sqc2         $vf3, 0x2C0+var_B0($sp) }
    }
    __asm
    {
      lq           $v0, 0x2C0+var_B0($sp)
      sq           $v0, 0x2C0+var_70($sp)
      qmtc2        $v0, $vf2
      lqc2         $vf1, 0x100($s0)
      vadd.xyz     $vf1, $vf1, $vf2
      lqc2         $vf2, 0x150($s0)
      sqc2         $vf1, 0x100($s0)
      sqc2         $vf2, 0x2C0+var_40($sp)
    }
    _$V0 = GetPosition__C16CB4CollidingBody(_$S0);
    __asm
    {
      lqc2         $vf2, 0x2C0+var_40($sp)
      qmtc2        $v0, $vf3
      vsub.xyz     $vf2, $vf2, $vf3
      lqc2         $vf1, 0x110($s0)
      lqc2         $vf3, 0x2C0+var_70($sp)
      vopmula      $A, $vf2, $vf3
      vopmsub      $vf2, $vf3, $vf2
    }
    _$S0->m_collision_detail.impulse_magnitude_or_penetration = v21;
    __asm { vadd.xyz     $vf1, $vf1, $vf2 }
    _$S0->m_bCollidedThisFrame = 1;
    __asm { sqc2         $vf1, 0x110($s0) }
  }
  else
  {
    _$S0->m_collision_detail.impulse_magnitude_or_penetration = 0.0;
    __asm
    {
      vaddw.x      $vf1, $vf0, $vf0
      vaddw.x      $vf2, $vf0, $vf0
      sqc2         $vf1, 0x2C0+var_60($sp)
      sqc2         $vf2, 0x2C0+var_50($sp)
    }
  }
  __asm
  {
    lqc2         $vf2, 0x160($s0)
    lqc2         $vf3, 0x2C0+var_80($sp)
    vmul.xyz     $vf1, $vf3, $vf2
    lqc2         $vf3, 0x2C0+var_60($sp)
  }
  _$V0 = COERCE_INT(_$S0->m_mass);
  __asm
  {
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf3, $vf1
    qmfc2        $v1, $vf1
    qmtc2        $v0, $vf3
  }
  _$V0 = _$V1;
  v47 = _$S0->m_bodyType;
  __asm
  {
    qmtc2        $v0, $vf1
    vmulx.xyz    $vf2, $vf2, $vf1
    lqc2         $vf1, 0x2C0+var_80($sp)
    vsub.xyz     $vf1, $vf1, $vf2
    vmulx.xyz    $vf3, $vf1, $vf3
    vmove.xyzw   $vf2, $vf3
  }
  if ( v47 == 1 || v47 == 2 || v47 == 3 )
  {
    __asm
    {
      lqc2         $vf3, 0x2C0+var_50($sp)
      vmul.xyz     $vf1, $vf1, $vf1
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf3, $vf1
    }
    _$F1 = 0.0;
    __asm
    {
      vnop
      vnop
      vnop
      vsqrt        $Q, $vf1.x
      vaddw.x      $vf1, $vf0, $vf0
      vwaitq
      vmulq.x      $vf1, $vf1, $Q
    }
    _$F2 = 1.0;
    __asm
    {
      qmfc2        $v0, $vf1
      lqc2         $vf3, 0xE0($s0)
      lq           $a2, 0x150($s0)
      max          $f0, $f1
      min          $f0, $f2
    }
    _$V0 = COERCE_INT(-_$F0);
    __asm
    {
      qmtc2        $v0, $vf1
      vmulx.xyz    $vf2, $vf2, $vf1
      vadd.xyz     $vf3, $vf3, $vf2
      qmfc2        $a3, $vf2
      sqc2         $vf3, 0xE0($s0)
    }
    CalculateTorqueFromPositionedForce__16CB4CollidingBodyPQ29GtMathPs26CGtV3dGQ29GtMathPs26CGtV3dT2(
      _$S0,
      &v101,
      _$A2,
      _$A3);
    __asm
    {
      lqc2         $vf1, 0xF0($s0)
      lqc2         $vf2, 0x2C0+var_A0($sp)
    }
LABEL_23:
    __asm
    {
      vadd.xyz     $vf1, $vf1, $vf2
      sqc2         $vf1, 0xF0($s0)
    }
    goto LABEL_29;
  }
  _$V0 = COERCE_INT(-0.60000002);
  __asm
  {
    qmtc2        $v0, $vf2
    vmulx.xyz    $vf3, $vf3, $vf2
    vmove.xyzw   $vf2, $vf3
    vmul.xyz     $vf1, $vf2, $vf2
    lqc2         $vf3, 0x2C0+var_50($sp)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf3, $vf1
    qmfc2        $v0, $vf1
  }
  if ( *&_$V0 > 1440000.0 )
  {
    __asm
    {
      lqc2         $vf1, 0xE0($s0)
      vadd.xyz     $vf1, $vf1, $vf2
      lq           $a2, 0x150($s0)
      qmfc2        $a3, $vf2
      sqc2         $vf1, 0xE0($s0)
    }
    CalculateTorqueFromPositionedForce__16CB4CollidingBodyPQ29GtMathPs26CGtV3dGQ29GtMathPs26CGtV3dT2(
      _$S0,
      &v102,
      _$A2,
      _$A3);
    __asm
    {
      lqc2         $vf1, 0xF0($s0)
      lqc2         $vf2, 0x2C0+var_90($sp)
    }
    goto LABEL_23;
  }
  if ( v47 == 7 )
  {
    v60 = 0.69999999;
  }
  else
  {
    v60 = 0.875;
    if ( v47 == 8 )
      v60 = 0.89999998;
  }
  _$V0 = SLODWORD(v60);
  __asm
  {
    lqc2         $vf1, 0xA0($s0)
    qmtc2        $v0, $vf2
  }
  _$V1 = SLODWORD(v60);
  __asm
  {
    vmulx.xyz    $vf2, $vf1, $vf2
    qmtc2        $v1, $vf3
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0xA0($s0)
    vmulx.w      $vf3, $vf1, $vf3
    vmove.w      $vf1, $vf3
    sqc2         $vf1, 0xA0($s0)
  }
LABEL_29:
  v63 = _$S0->m_bodyType;
  if ( v63 == 7 || v63 == 8 )
  {
    _$V0 = COERCE_INT(0.94999999);
    __asm
    {
      lqc2         $vf2, 0xA0($s0)
      qmtc2        $v0, $vf1
    }
    _$V1 = COERCE_INT(0.94999999);
    __asm
    {
      vmulx.xyz    $vf1, $vf2, $vf1
      qmtc2        $v1, $vf3
      vadd.xyz     $vf2, $vf0, $vf1
    }
    _$V0 = COERCE_INT(0.94999999);
    __asm
    {
      lqc2         $vf1, 0xD0($s0)
      qmtc2        $v0, $vf4
      sqc2         $vf2, 0xA0($s0)
      vmulx.w      $vf3, $vf2, $vf3
      vmulx.xyz    $vf1, $vf1, $vf4
      vmove.w      $vf2, $vf3
      sqc2         $vf1, 0xD0($s0)
      sqc2         $vf2, 0xA0($s0)
      lq           $v0, 0xA0($s0)
    }
  }
  else
  {
    __asm { lq           $v0, 0xA0($s0) }
  }
  __asm { sq           $v0, 0x2C0+var_110($sp) }
  v68 = 0LL;
  if ( *(&v93 + 3) < 5.0 )
  {
    _$V1 = _$S0->m_pCollisionShapeData;
    __asm
    {
      lqc2         $vf2, 0x160($s0)
      lqc2         $vf1, 0x10($v1)
      vmul.xyz     $vf1, $vf2, $vf1
      lqc2         $vf3, 0x2C0+var_60($sp)
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf3, $vf1
      qmfc2        $v0, $vf1
    }
    if ( fabsf(*&_$V0) > 0.96600002 )
      goto LABEL_37;
    __asm
    {
      lqc2         $vf1, 0x20($v1)
      vmul.xyz     $vf1, $vf2, $vf1
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf3, $vf1
      qmfc2        $v0, $vf1
    }
    if ( fabsf(*&_$V0) > 0.96600002 )
      goto LABEL_37;
    __asm
    {
      lqc2         $vf1, 0($v1)
      vmul.xyz     $vf1, $vf2, $vf1
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf3, $vf1
      qmfc2        $v0, $vf1
    }
    v73 = fabsf(*&_$V0);
    v68 = 0LL;
    if ( v73 > 0.96600002 )
LABEL_37:
      v68 = 1LL;
  }
  v74 = 0LL;
  if ( !v68 )
    goto LABEL_51;
  _$V0 = COERCE_INT(0.94999999);
  __asm
  {
    lqc2         $vf1, 0xD0($s0)
    qmtc2        $v0, $vf2
  }
  v76 = 0.0;
  __asm { vmulx.xyz    $vf1, $vf1, $vf2 }
  v77 = _$S0->m_bodyType;
  __asm { sqc2         $vf1, 0xD0($s0) }
  v78 = 0.0;
  v79 = 0LL;
  if ( v77 == 7 )
  {
    v74 = *&_$S0;
    if ( (*&_$S0->m_convexHull.m_offsetPlanes + 0.5) < gWorld.m_Timer.deltaTime )
    {
      v78 = 0.80000001;
      v76 = 0.48999998;
      v79 = 1LL;
    }
  }
  else if ( v77 == 8 )
  {
    v78 = 0.5;
    v79 = 1LL;
    v76 = 0.090000004;
  }
  v80 = 0;
  if ( !v79 )
    goto LABEL_47;
  __asm
  {
    lq           $v0, 0xA0($s0)
    sq           $v0, 0x2C0+var_110($sp)
  }
  v82 = 0LL;
  if ( *(&v93 + 3) < v78 )
  {
    __asm
    {
      lqc2         $vf1, 0xC0($s0)
      vmul.xyz     $vf1, $vf1, $vf1
      lqc2         $vf2, 0x2C0+var_50($sp)
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf2, $vf1
      qmfc2        $v0, $vf1
    }
    v80 = *&_$V0 < v76;
LABEL_47:
    v82 = v80;
  }
  if ( v82 )
  {
    _$S0->m_collisionFilterMask2 = 1;
    if ( v74 )
      MakePropStatic__17CB4PhysicsManagerP14CB4PropPhysics(gWorld.m_PhysicsManager, v74);
  }
LABEL_51:
  __asm { lqc2         $vf1, 0x2C0+var_C0($sp) }
  result = 1LL;
  __asm
  {
    lqc2         $vf2, 0x120($s0)
    vadd.xyz     $vf2, $vf2, $vf1
  }
  _$S0->m_collision_detail.contact_status_flags = 1;
  __asm
  {
    sqc2         $vf2, 0x120($s0)
    sqc2         $vf1, 0x170($s0)
  }
LABEL_54:
  __asm
  {
    lq           $s0, 0x2C0+var_10($sp)
    lq           $s1, 0x2C0+var_20($sp)
  }
  return result;
}

// CB4CollidingBody::SetInitialMatrix(const GtMathPs2::CGtMatrix3x4 &)
__int64 __fastcall SetInitialMatrix__16CB4CollidingBodyRCQ29GtMathPs212CGtMatrix3x4(
        B4CollidingBody *pCollidingBody,
        int _$A1)
{
  __int64 result; // $v0

  __asm { lq           $v1, 0($a1) }
  _$A3 = &pCollidingBody->m_initialMatrix_Row0;
  __asm
  {
    sq           $v1, 0($a2)
    lq           $v0, 0x10($a1)
    sq           $v0, 0x10($a2)
    lq           $v1, 0x20($a1)
    sq           $v1, 0x20($a2)
    lq           $v0, 0x30($a1)
    sq           $v0, 0x30($a2)
    lqc2         $vf3, 0($a1)
    sqc2         $vf3, 0x60($a0)
    vmove.xyzw   $vf4, $vf3
    lqc2         $vf1, 0x10($a1)
    sqc2         $vf1, 0x70($a0)
    vmove.xyzw   $vf9, $vf1
    vaddy.x      $vf9, $vf0, $vf3
    lqc2         $vf2, 0x20($a1)
    vmove.xyzw   $vf7, $vf9
    sqc2         $vf2, 0x80($a0)
    vmove.xyzw   $vf8, $vf2
    vaddz.x      $vf8, $vf0, $vf3
    lqc2         $vf3, 0x30($a1)
    vmove.xyzw   $vf5, $vf8
    sqc2         $vf3, 0x90($a0)
    lqc2         $vf2, 0x10($a3)
    vaddx.y      $vf4, $vf0, $vf2
    lqc2         $vf1, 0x20($a3)
    vmove.xyzw   $vf6, $vf4
    vaddy.z      $vf7, $vf0, $vf1
    vaddz.y      $vf5, $vf0, $vf2
    vaddx.z      $vf6, $vf0, $vf1
    vmulx.xyz    $vf1, $vf6, $vf3
    vmuly.xyz    $vf2, $vf7, $vf3
    vmulz.xyz    $vf3, $vf5, $vf3
    vadd.xyz     $vf1, $vf1, $vf2
    sqc2         $vf4, 0x60($a0)
    vadd.xyz     $vf1, $vf1, $vf3
    sqc2         $vf9, 0x70($a0)
    vsub.xyz     $vf1, $vf0, $vf1
    sqc2         $vf8, 0x80($a0)
    sqc2         $vf5, 0x80($a0)
    sqc2         $vf6, 0x60($a0)
    sqc2         $vf7, 0x70($a0)
    sqc2         $vf1, 0x30($a3)
  }
  return result;
}

// CB4CollidingBody::CalculateCollisionImpulseWithTraffic(CB4TrafficVehicle *, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, float, GtMathPs2::CGtV3d *)
__int64 __usercall CalculateCollisionImpulseWithTraffic__16CB4CollidingBodyP17CB4TrafficVehicleGQ29GtMathPs26CGtV3dN22fPQ29GtMathPs26CGtV3d@<$v0>(
        B4CollidingBody *_$A0@<$a0>,
        B4TrafficVehicle *_$A1@<$a1>,
        __int64 _$A2@<$a2>,
        __int64 _$A3@<$a3>,
        __int64 _$A4@<$a4>,
        float a6@<$f12>)
{
  float inertia; // $f4
  float v18; // $f5
  float v19; // $f0
  __int64 result; // $v0
  float v25; // [sp+30h] [-100h] BYREF
  float v26; // [sp+34h] [-FCh]
  float v27; // [sp+38h] [-F8h]

  __asm
  {
    lqc2         $vf2, 0x1C0($a0)
    lqc2         $vf1, 0x1D0($a0)
    vsub.y       $vf3, $vf0, $vf1
    vsub.z       $vf4, $vf0, $vf1
    sqc2         $vf2, 0x130+var_100($sp)
    vsub.x       $vf1, $vf0, $vf1
    qmfc2        $v1, $vf2
    qmfc2        $v0, $vf1
  }
  _$F1 = *&_$V0;
  __asm
  {
    max          $f3, $f1
    sqc2         $vf3, 0x130+var_100($sp)
    qmtc2        $a4, $vf18
    qmtc2        $a3, $vf1
  }
  _$F2 = v26;
  __asm { vaddw.x      $vf20, $vf0, $vf0 }
  inertia = _$A1->inertia;
  __asm
  {
    max          $f0, $f2
    sqc2         $vf2, 0x130+var_100($sp)
    vmul.xyz     $vf2, $vf18, $vf1
    vadday.x     $A, $vf2, $vf2
    vmaddz.x     $vf2, $vf20, $vf2
    sqc2         $vf4, 0x130+var_100($sp)
  }
  _$V0 = COERCE_INT(-(a6 + 1.0));
  __asm
  {
    qmtc2        $a2, $vf19
    qmtc2        $v0, $vf1
  }
  _$F2 = v27;
  __asm
  {
    vmulx.x      $vf2, $vf2, $vf1
    max          $f1, $f2
  }
  LODWORD(_$V1) = _$A0->m_pCollisionShapeData;
  __asm { qmfc2        $v0, $vf2 }
  _$A2 = &_$A0->m_localInvInertiaPrincipalX;
  v18 = (inertia * ((_$F3 * _$F3) + (_$F0 * _$F0))) * 0.5;
  v19 = *&_$V0;
  __asm
  {
    lq           $v0, 0x130+var_100($sp)
    sq           $v0, 0x130+var_90($sp)
    lq           $v0, 0x130+var_100($sp)
  }
  v25 = 0.0;
  __asm { sq           $v0, 0x130+var_80($sp) }
  v26 = 0.0;
  v27 = 1.0 / v18;
  __asm
  {
    lqc2         $vf11, 0x130+var_100($sp)
    sqc2         $vf11, 0x130+var_70($sp)
    lqc2         $vf5, 0($v1)
    sqc2         $vf5, 0x130+var_F0($sp)
    vmove.xyzw   $vf12, $vf5
    lqc2         $vf4, 0x10($v1)
    vaddx.y      $vf12, $vf0, $vf4
    vmove.xyzw   $vf14, $vf12
    sqc2         $vf4, 0x130+var_E0($sp)
    vmove.xyzw   $vf10, $vf4
    vaddy.x      $vf10, $vf0, $vf5
    lqc2         $vf3, 0x20($v1)
    vmove.xyzw   $vf15, $vf10
    vaddx.z      $vf14, $vf0, $vf3
    vaddy.z      $vf15, $vf0, $vf3
    sqc2         $vf3, 0x130+var_D0($sp)
    sqc2         $vf5, 0x130+var_C0($sp)
    vmove.xyzw   $vf8, $vf3
    sqc2         $vf4, 0x130+var_B0($sp)
    vaddz.x      $vf8, $vf0, $vf5
    sqc2         $vf3, 0x130+var_A0($sp)
    vmove.xyzw   $vf13, $vf8
    vaddz.y      $vf13, $vf0, $vf4
    lqc2         $vf2, 0x130+var_90($sp)
    lqc2         $vf1, 0x130+var_80($sp)
    vmulax.xyz   $A, $vf2, $vf14
    vmadday.xyz  $A, $vf1, $vf14
    vmaddz.xyz   $vf6, $vf11, $vf14
    vmulax.xyz   $A, $vf2, $vf15
    vmadday.xyz  $A, $vf1, $vf15
    vmaddz.xyz   $vf7, $vf11, $vf15
    vmulax.xyz   $A, $vf2, $vf13
    vmadday.xyz  $A, $vf1, $vf13
    vmaddz.xyz   $vf9, $vf11, $vf13
    vmulax.xyz   $A, $vf5, $vf6
    vmadday.xyz  $A, $vf4, $vf6
    vmaddz.xyz   $vf17, $vf3, $vf6
    vmulax.xyz   $A, $vf5, $vf7
    vmadday.xyz  $A, $vf4, $vf7
    vmaddz.xyz   $vf16, $vf3, $vf7
    vmulax.xyz   $A, $vf5, $vf9
    vmadday.xyz  $A, $vf4, $vf9
    vmaddz.xyz   $vf11, $vf3, $vf9
    sqc2         $vf8, 0x130+var_A0($sp)
    sqc2         $vf12, 0x130+var_C0($sp)
    sqc2         $vf10, 0x130+var_B0($sp)
    sqc2         $vf6, 0x130+var_30($sp)
    sqc2         $vf7, 0x130+var_20($sp)
    sqc2         $vf9, 0x130+var_10($sp)
    sqc2         $vf6, 0x130+var_60($sp)
    sqc2         $vf7, 0x130+var_50($sp)
    sqc2         $vf9, 0x130+var_40($sp)
  }
  _$V0 = COERCE_INT((1.0 / _$A0->m_mass) + (1.0 / inertia));
  __asm
  {
    sqc2         $vf6, 0x130+var_130($sp)
    qmtc2        $v0, $vf8
    sqc2         $vf7, 0x130+var_120($sp)
    sqc2         $vf9, 0x130+var_110($sp)
    sqc2         $vf14, 0x130+var_C0($sp)
    sqc2         $vf15, 0x130+var_B0($sp)
    sqc2         $vf13, 0x130+var_A0($sp)
    sqc2         $vf17, 0x130+var_30($sp)
    sqc2         $vf16, 0x130+var_20($sp)
    sqc2         $vf11, 0x130+var_10($sp)
    sqc2         $vf17, 0x130+var_60($sp)
    sqc2         $vf16, 0x130+var_50($sp)
    sqc2         $vf11, 0x130+var_40($sp)
    sqc2         $vf17, 0x130+var_130($sp)
    sqc2         $vf16, 0x130+var_120($sp)
    sqc2         $vf11, 0x130+var_110($sp)
    lqc2         $vf4, 0xA0($a1)
    lqc2         $vf1, 0x30($v1)
    vsub.xyz     $vf4, $vf19, $vf4
    vsub.xyz     $vf19, $vf19, $vf1
    lqc2         $vf6, 0x20($a2)
    lqc2         $vf5, 0x30($a0)
    vopmula      $A, $vf19, $vf18
    vopmsub      $vf1, $vf18, $vf19
    lqc2         $vf3, 0x10($a2)
    vopmula      $A, $vf4, $vf18
    vopmsub      $vf2, $vf18, $vf4
    vmulax.xyz   $A, $vf5, $vf1
    vmadday.xyz  $A, $vf3, $vf1
    vmaddz.xyz   $vf1, $vf6, $vf1
    vmulax.xyz   $A, $vf17, $vf2
    vmadday.xyz  $A, $vf16, $vf2
    vmaddz.xyz   $vf2, $vf11, $vf2
    vopmula      $A, $vf1, $vf19
    vopmsub      $vf1, $vf19, $vf1
    vopmula      $A, $vf2, $vf4
    vopmsub      $vf2, $vf4, $vf2
    vadd.xyz     $vf1, $vf1, $vf2
    vmul.xyz     $vf1, $vf1, $vf18
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf20, $vf1
    vaddx.x      $vf1, $vf1, $vf8
    qmfc2        $v0, $vf1
  }
  result = COERCE_INT(-fabsf(v19 / *&_$V0));
  __asm
  {
    qmtc2        $v0, $vf1
    vmulx.xyz    $vf18, $vf18, $vf1
    sqc2         $vf18, 0($a5)
  }
  return result;
}

// CB4CollidingBody::AddCachedWorldTriangle(const CGtPolygonIntersectionResult &)
__int64 __fastcall AddCachedWorldTriangle__16CB4CollidingBodyRC28CGtPolygonIntersectionResult(
        B4CollidingBody *pCollidingBody,
        GtPolygonIntersectionResult *a2)
{
  __int64 num_triangles; // $a4
  __int64 result; // $v0

  _$A2 = a2;
  if ( 16CB4CollidingBody__mbCacheOverflowed
    || (num_triangles = pCollidingBody->m_pGlobalWorldTriangleCache->num_triangles, num_triangles >= 96) )
  {
    result = 0LL;
    16CB4CollidingBody__mbCacheOverflowed = 1;
  }
  else
  {
    __asm
    {
      lq           $v0, 0x20($a2)
      sq           $v0, 0($a1)
    }
    result = 1LL;
    __asm
    {
      lq           $v1, 0x30($a2)
      sq           $v1, 0x10($a1)
      lq           $a0, 0x40($a2)
      sq           $a0, 0x20($a1)
      lq           $v1, 0x10($a2)
      sq           $v1, 0x30($a1)
    }
    *(pCollidingBody->m_pGlobalWorldTriangleCache->p_triangle_material_ids_start + num_triangles) = *(a2->pPolygonIndices + 2);
    pCollidingBody->m_pGlobalWorldTriangleCache->num_triangles = num_triangles + 1;
  }
  return result;
}

// CB4CollidingBody::StopImmediately(void)
__int64 __fastcall StopImmediately__16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  __int64 result; // $v0

  __asm
  {
    vadd.xyz     $vf1, $vf0, $vf0
    vsub.xyzw    $vf2, $vf0, $vf0
    sqc2         $vf1, 0xC0($a0)
    sqc2         $vf2, 0xA0($a0)
    sqc2         $vf2, 0x10+var_10($sp)
    sqc2         $vf1, 0xD0($a0)
  }
  result = pCollidingBody->m_pCollisionShapeData;
  __asm
  {
    lq           $v1, 0x20($v0)
    sqc2         $vf1, 0x120($a0)
    sq           $v1, 0xB0($a0)
    sqc2         $vf1, 0xE0($a0)
    sqc2         $vf1, 0xF0($a0)
    sqc2         $vf1, 0x100($a0)
    sqc2         $vf1, 0x110($a0)
    sqc2         $vf1, 0x10+var_10($sp)
  }
  return result;
}

void ClearAccumulatedValues__16CB4CollidingBody()
{
  __asm
  {
    vadd.xyz     $vf1, $vf0, $vf0
    sqc2         $vf1, 0x120($a0)
    sqc2         $vf1, 0xE0($a0)
    sqc2         $vf1, 0xF0($a0)
    sqc2         $vf1, 0x100($a0)
    sqc2         $vf1, 0x110($a0)
    sqc2         $vf1, 0x10+var_10($sp)
  }
}

// CB4CollidingBody::CalculateCollisionImpulseWithBody(CB4CollidingBody &, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, float, GtMathPs2::CGtV3d *)
__int64 __usercall CalculateCollisionImpulseWithBody__16CB4CollidingBodyR16CB4CollidingBodyGQ29GtMathPs26CGtV3dN32fPQ29GtMathPs26CGtV3d@<$v0>(
        B4CollidingBody *_$A0@<$a0>,
        B4CollidingBody *_$A1@<$a1>,
        __int64 _$A2@<$a2>,
        __int64 _$A3@<$a3>,
        __int64 _$A4@<$a4>,
        __int64 _$A5@<$a5>,
        float a7@<$f12>)
{
  __int64 result; // $v0

  __asm { qmtc2        $a5, $vf6 }
  _$V1 = _$A0->m_pCollisionShapeData;
  __asm
  {
    qmtc2        $a4, $vf1
    vmul.xyz     $vf8, $vf6, $vf1
    qmtc2        $a2, $vf3
    lqc2         $vf1, 0x30($v1)
  }
  _$V0 = _$A1->m_pCollisionShapeData;
  __asm
  {
    vsub.xyz     $vf9, $vf3, $vf1
    qmtc2        $a3, $vf1
    lqc2         $vf2, 0x30($v0)
  }
  _$A5 = &_$A0->m_localInvInertiaPrincipalX;
  __asm { vsub.xyz     $vf11, $vf1, $vf2 }
  _$A7 = &_$A1->m_localInvInertiaPrincipalX;
  __asm
  {
    lqc2         $vf4, 0x10($a5)
    lqc2         $vf3, 0x10($a7)
    vopmula      $A, $vf9, $vf6
    vopmsub      $vf1, $vf6, $vf9
    lqc2         $vf10, 0x20($a5)
    vopmula      $A, $vf11, $vf6
    vopmsub      $vf2, $vf6, $vf11
    lqc2         $vf12, 0x20($a7)
    lqc2         $vf7, 0x30($a0)
    lqc2         $vf5, 0x30($a1)
    vmulax.xyz   $A, $vf7, $vf1
    vmadday.xyz  $A, $vf4, $vf1
    vmaddz.xyz   $vf1, $vf10, $vf1
    vmulax.xyz   $A, $vf5, $vf2
    vmadday.xyz  $A, $vf3, $vf2
    vmaddz.xyz   $vf2, $vf12, $vf2
    vopmula      $A, $vf1, $vf9
    vopmsub      $vf1, $vf9, $vf1
    vopmula      $A, $vf2, $vf11
    vopmsub      $vf2, $vf11, $vf2
  }
  _$V1 = COERCE_INT((1.0 / _$A0->m_mass) + (1.0 / _$A1->m_mass));
  __asm { vadd.xyz     $vf1, $vf1, $vf2 }
  _$V0 = COERCE_INT(-(a7 + 1.0));
  __asm
  {
    vmul.xyz     $vf1, $vf1, $vf6
    vaddw.x      $vf2, $vf0, $vf0
    qmtc2        $v0, $vf4
    qmtc2        $v1, $vf3
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf2, $vf1
    vadday.x     $A, $vf8, $vf8
    vmaddz.x     $vf8, $vf2, $vf8
    vaddx.x      $vf1, $vf1, $vf3
    vmulx.x      $vf8, $vf8, $vf4
    qmfc2        $v0, $vf8
    qmfc2        $v1, $vf1
  }
  result = COERCE_INT(-fabsf(*&_$V0 / *&_$V1));
  __asm
  {
    qmtc2        $v0, $vf1
    vmulx.xyz    $vf6, $vf6, $vf1
    sqc2         $vf6, 0($a6)
  }
  return result;
}

// CB4CollidingBody::CalculateCollisionImpulseWithInanimateObject(GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, float, GtMathPs2::CGtV3d *)
__int64 __usercall CalculateCollisionImpulseWithInanimateObject__16CB4CollidingBodyGQ29GtMathPs26CGtV3dN21fPQ29GtMathPs26CGtV3d@<$v0>(
        B4CollidingBody *_$A0@<$a0>,
        __int64 _$A1@<$a1>,
        __int64 _$A2@<$a2>,
        __int64 _$A3@<$a3>,
        float a5@<$f12>)
{
  __int64 result; // $v0

  __asm { qmtc2        $a3, $vf5 }
  _$V0 = _$A0->m_pCollisionShapeData;
  __asm
  {
    qmtc2        $a2, $vf2
    vmul.xyz     $vf4, $vf5, $vf2
    lqc2         $vf1, 0x30($v0)
    qmtc2        $a1, $vf2
  }
  _$V1 = &_$A0->m_localInvInertiaPrincipalX;
  __asm
  {
    vsub.xyz     $vf6, $vf2, $vf1
    lqc2         $vf7, 0x20($v1)
    lqc2         $vf2, 0x10($v1)
    lqc2         $vf3, 0x30($a0)
    vopmula      $A, $vf6, $vf5
    vopmsub      $vf1, $vf5, $vf6
    vmulax.xyz   $A, $vf3, $vf1
    vmadday.xyz  $A, $vf2, $vf1
    vmaddz.xyz   $vf1, $vf7, $vf1
    vopmula      $A, $vf1, $vf6
    vopmsub      $vf1, $vf6, $vf1
    vaddw.x      $vf2, $vf0, $vf0
    vmul.xyz     $vf1, $vf1, $vf5
  }
  _$V0 = COERCE_INT(1.0 / _$A0->m_mass);
  _$V1 = COERCE_INT(-(a5 + 1.0));
  __asm
  {
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf2, $vf1
    vadday.x     $A, $vf4, $vf4
    vmaddz.x     $vf4, $vf2, $vf4
    qmtc2        $v1, $vf3
    qmtc2        $v0, $vf2
    vmulx.x      $vf4, $vf4, $vf3
    vaddx.x      $vf1, $vf1, $vf2
    qmfc2        $v0, $vf4
    qmfc2        $v1, $vf1
  }
  result = COERCE_INT(fabsf(*&_$V0 / *&_$V1));
  __asm
  {
    qmtc2        $v0, $vf1
    vmulx.xyz    $vf5, $vf5, $vf1
    sqc2         $vf5, 0($a4)
  }
  return result;
}

// CB4CollidingBody::SetMomentOfInertia(float, float, float)
__int64 __fastcall SetMomentOfInertia__16CB4CollidingBodyfff(B4CollidingBody *pCollidingBody, __int64 a2, float a3)
{
  __int64 result; // $v0
  _DWORD v5[4]; // [sp+60h] [-70h] BYREF

  _$V1 = &pCollidingBody->m_localInvInertiaPrincipalX;
  __asm
  {
    lqc2         $vf15, 0xD0+var_70($sp)
    sqc2         $vf15, 0($a0)
    lqc2         $vf14, 0xD0+var_70($sp)
  }
  v5[0] = 0.0;
  *&v5[1] = 0.0;
  *&v5[2] = a3;
  __asm { sqc2         $vf14, 0x10($a0) }
  result = pCollidingBody->m_pCollisionShapeData;
  __asm
  {
    lqc2         $vf13, 0xD0+var_70($sp)
    sqc2         $vf13, 0x20($a0)
    lqc2         $vf8, 0($v0)
    sqc2         $vf8, 0xD0+var_D0($sp)
    vmove.xyzw   $vf10, $vf8
    lqc2         $vf7, 0x10($v0)
    vaddx.y      $vf10, $vf0, $vf7
    vmove.xyzw   $vf4, $vf10
    sqc2         $vf7, 0xD0+var_C0($sp)
    vmove.xyzw   $vf3, $vf7
    vaddy.x      $vf3, $vf0, $vf8
    lqc2         $vf5, 0x20($v0)
    vmove.xyzw   $vf6, $vf3
    vaddx.z      $vf4, $vf0, $vf5
    vaddy.z      $vf6, $vf0, $vf5
    sqc2         $vf8, 0xD0+var_A0($sp)
    vmove.xyzw   $vf1, $vf5
    vaddz.x      $vf1, $vf0, $vf8
    sqc2         $vf7, 0xD0+var_90($sp)
    vmove.xyzw   $vf2, $vf1
    vaddz.y      $vf2, $vf0, $vf7
    sqc2         $vf5, 0xD0+var_80($sp)
    vmulax.xyz   $A, $vf15, $vf4
    vmadday.xyz  $A, $vf14, $vf4
    vmaddz.xyz   $vf9, $vf13, $vf4
    vmulax.xyz   $A, $vf15, $vf6
    vmadday.xyz  $A, $vf14, $vf6
    vmaddz.xyz   $vf11, $vf13, $vf6
    vmulax.xyz   $A, $vf15, $vf2
    vmadday.xyz  $A, $vf14, $vf2
    vmaddz.xyz   $vf12, $vf13, $vf2
    sqc2         $vf3, 0xD0+var_90($sp)
    sqc2         $vf1, 0xD0+var_80($sp)
    sqc2         $vf10, 0xD0+var_A0($sp)
    sqc2         $vf4, 0xD0+var_A0($sp)
    sqc2         $vf6, 0xD0+var_90($sp)
    sqc2         $vf2, 0xD0+var_80($sp)
    sqc2         $vf5, 0xD0+var_B0($sp)
    sqc2         $vf9, 0xD0+var_30($sp)
    sqc2         $vf11, 0xD0+var_20($sp)
    sqc2         $vf12, 0xD0+var_10($sp)
    sqc2         $vf11, 0x40($a0)
    sqc2         $vf12, 0x50($a0)
    sqc2         $vf9, 0xD0+var_60($sp)
    sqc2         $vf11, 0xD0+var_50($sp)
    sqc2         $vf12, 0xD0+var_40($sp)
    sqc2         $vf9, 0x30($a0)
    lqc2         $vf2, 0x20($v1)
    lqc2         $vf1, 0x10($v1)
    vmulax.xyz   $A, $vf8, $vf9
    vmadday.xyz  $A, $vf7, $vf9
    vmaddz.xyz   $vf3, $vf5, $vf9
    vmulax.xyz   $A, $vf8, $vf1
    vmadday.xyz  $A, $vf7, $vf1
    vmaddz.xyz   $vf4, $vf5, $vf1
    vmulax.xyz   $A, $vf8, $vf2
    vmadday.xyz  $A, $vf7, $vf2
    vmaddz.xyz   $vf6, $vf5, $vf2
    sqc2         $vf6, 0x50($a0)
    sqc2         $vf3, 0x30($a0)
    sqc2         $vf4, 0x40($a0)
    sqc2         $vf3, 0xD0+var_40($sp)
    sqc2         $vf4, 0xD0+var_30($sp)
    sqc2         $vf6, 0xD0+var_20($sp)
    sqc2         $vf3, 0xD0+var_70($sp)
    sqc2         $vf4, 0xD0+var_60($sp)
    sqc2         $vf6, 0xD0+var_50($sp)
  }
  return result;
}

// CB4CollisionDetector::SetupParams(CB4HullCollideParams *, CB4CollidingBody *, CB4CollidingBody *, bool)
__int64 __fastcall SetupParams__20CB4CollisionDetectorP20CB4HullCollideParamsP16CB4CollidingBodyT2b(
        unsigned int a1,
        int _$A1,
        int a3,
        void *a4)
{
  __int64 result; // $v0

  _$A5 = _$A1 + 96;
  __asm
  {
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
    sq           $s2, 0x40+var_30($sp)
  }
  _$S1 = a3;
  _$A4 = *(_$A1 + 500);
  __asm
  {
    lq           $v1, 0($a4)
    sq           $v1, 0x30($s0)
    lq           $v0, 0x10($a4)
    sq           $v0, 0x40($s0)
    lq           $v1, 0x20($a4)
    sq           $v1, 0x50($s0)
    lq           $v0, 0x30($a4)
    sq           $v0, 0x60($s0)
    lq           $v1, 0x60($a1)
    sq           $v1, 0x70($s0)
    lq           $v0, 0x10($a5)
    sq           $v0, 0x80($s0)
    lq           $v1, 0x20($a5)
    sq           $v1, 0x90($s0)
    lq           $v0, 0x30($a5)
    sq           $v0, 0xA0($s0)
  }
  *a1 = *(_$A1 + 504);
  __asm
  {
    lq           $v0, 0xA0($a1)
    sq           $v0, 0x10($s0)
    lq           $v1, 0xC0($a1)
  }
  *(a1 + 288) = 0;
  __asm { sq           $v1, 0x20($s0) }
  CalculateBounds__24CB4HullCollideHullParams(a1);
  _$A1 = *(_$S1 + 500);
  _$A2 = _$S1 + 96;
  __asm
  {
    lq           $v1, 0($a1)
    sq           $v1, 0x160($s0)
    lq           $v0, 0x10($a1)
    sq           $v0, 0x170($s0)
    lq           $v1, 0x20($a1)
    sq           $v1, 0x180($s0)
    lq           $v0, 0x30($a1)
    sq           $v0, 0x190($s0)
    lq           $v1, 0x60($s1)
    sq           $v1, 0x1A0($s0)
    lq           $v0, 0x10($a2)
    sq           $v0, 0x1B0($s0)
    lq           $v1, 0x20($a2)
    sq           $v1, 0x1C0($s0)
    lq           $v0, 0x30($a2)
    sq           $v0, 0x1D0($s0)
  }
  *(a1 + 304) = *(_$S1 + 504);
  __asm
  {
    lq           $v0, 0xA0($s1)
    sq           $v0, 0x140($s0)
    lq           $v1, 0xC0($s1)
    sq           $v1, 0x150($s0)
  }
  *(a1 + 592) = 0;
  result = CalculateBounds__24CB4HullCollideHullParams((a1 + 304));
  *(a1 + 608) = a4;
  *(a1 + 612) = 0;
  __asm
  {
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return result;
}

// CB4CollisionDetector::CollideBodyHulls(CB4HullCollideParams *, CB4CollidingBody *, CB4CollidingBody *, bool)
__int64 __fastcall CollideBodyHulls__20CB4CollisionDetectorP20CB4HullCollideParamsP16CB4CollidingBodyT2b(
        unsigned int a1,
        int a2,
        int a3,
        void *a4)
{
  __int64 v7; // $v1
  bool v8; // $a0
  __int64 v9; // $v1
  bool v10; // $a0
  __int64 result; // $v0
  __int64 v13; // $s0

  __asm
  {
    sq           $s1, 0x30+var_20($sp)
    sq           $s0, 0x30+var_10($sp)
  }
  v7 = *(a2 + 516);
  v8 = 0;
  if ( *(a2 + 516) && v7 != 7 )
    v8 = v7 != 8;
  if ( !v8 )
  {
    SetupParams__20CB4CollisionDetectorP20CB4HullCollideParamsP16CB4CollidingBodyT2b(a1, a2, a3, a4);
    goto LABEL_14;
  }
  v9 = *(a3 + 516);
  v10 = 0;
  if ( *(a3 + 516) && v9 != 7 )
    v10 = v9 != 8;
  if ( !v10 )
  {
    v13 = *(*(a2 + 2552) + 9091) ^ 1LL;
    SetupParams__20CB4CollisionDetectorP20CB4HullCollideParamsP16CB4CollidingBodyT2b(a1, a2, a3, a4);
    if ( !v13 )
    {
      result = CollideConcaveVehicleWithConvexHull__20CB4CollisionDetectorP20CB4HullCollideParamsb(a1, 1LL);
      __asm { lq           $s0, 0x30+var_10($sp) }
      goto LABEL_15;
    }
LABEL_14:
    result = CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(a1);
    __asm { lq           $s0, 0x30+var_10($sp) }
    goto LABEL_15;
  }
  result = CollideVehicles__20CB4CollisionDetectorP20CB4HullCollideParamsP17CB4VehiclePhysicsT2b(a1, a2, a3, a4);
  __asm { lq           $s0, 0x30+var_10($sp) }
LABEL_15:
  __asm { lq           $s1, 0x30+var_20($sp) }
  return result;
}

//  CB4CollisionDetector::CollideBodyHullWithWorld(CB4HullWorldTriCollideParams *, CB4CollidingBody *)
__int64 __fastcall CollideBodyHullWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP16CB4CollidingBody(
        unsigned int a1,
        int a2)
{
  __int64 v16; // $v1
  bool v17; // $a4

  _$A3 = a2;
  _$A1 = a2 + 96;
  *a1 = *(_$A3 + 504);
  _$A0 = *(_$A3 + 500);
  __asm
  {
    lq           $v0, 0($a0)
    sq           $v0, 0x30($a2)
    lq           $v1, 0x10($a0)
    sq           $v1, 0x40($a2)
    lq           $v0, 0x20($a0)
    sq           $v0, 0x50($a2)
    lq           $v1, 0x30($a0)
    sq           $v1, 0x60($a2)
    lq           $v0, 0x60($a3)
    sq           $v0, 0x70($a2)
    lq           $v1, 0x10($a1)
    sq           $v1, 0x80($a2)
    lq           $v0, 0x20($a1)
    sq           $v0, 0x90($a2)
    lq           $v1, 0x30($a1)
    sq           $v1, 0xA0($a2)
  }
  *(a1 + 304) = *(_$A3 + 496);
  __asm
  {
    lq           $v0, 0xA0($a3)
    sq           $v0, 0x180($a2)
    lq           $v1, 0xB0($a3)
    sq           $v1, 0x190($a2)
  }
  v16 = *(_$A3 + 516);
  v17 = 0;
  if ( *(_$A3 + 516) && v16 != 7 )
    v17 = v16 != 8;
  if ( v17 && *(*(_$A3 + 2552) + 9091) )
    return CollideConcaveVehicleWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP17CB4VehiclePhysics(
             a1,
             _$A3);
  else
    return CollideBodyConvexHullWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP16CB4CollidingBody(
             a1,
             _$A3);
}

// CB4CollisionDetector::CollideConcaveVehicleWithConvexHull(CB4HullCollideParams *, bool)
__int64 __fastcall CollideBodyConvexHullWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP16CB4CollidingBody(
        unsigned int a1,
        int _$A1)
{
  if ( *(_$A1 + 515) )
  {
    __asm
    {
      lq           $v0, 0x130($a1)
      sq           $v0, 0x140($v1)
    }
  }
  else
  {
    _$V0 = *(_$A1 + 500);
    __asm
    {
      lqc2         $vf1, 0x20($v0)
      vsub.xyz     $vf1, $vf0, $vf1
      sqc2         $vf1, 0x140($v1)
    }
  }
  *(a1 + 336) = *(_$A1 + 515);
  return DoCollideHullTriangles__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP24CB4ConvexHullCollideInfo(
           a1,
           &gHullColInfo);
}

// CB4CollidingBody::IsOutsideCollision(void) const
__int64 __fastcall IsOutsideCollision__C16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  return pCollidingBody->m_trackCollisionResult == -1LL;
}

// CB4CollidingBody::CalculateTorqueFromPositionedForce(GtMathPs2::CGtV3d *, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d)
__int64 __fastcall CalculateTorqueFromPositionedForce__16CB4CollidingBodyPQ29GtMathPs26CGtV3dGQ29GtMathPs26CGtV3dT2(
        B4CollidingBody *pCollidingBody,
        __int64 a2,
        __int64 _$A2,
        __int64 _$A3)
{
  __int64 result; // $v0

  __asm
  {
    qmtc2        $a2, $vf1
    sq           $s0, 0x40+var_10($sp)
    sq           $a3, 0x40+var_40($sp)
    sqc2         $vf1, 0x40+var_30($sp)
  }
  result = GetPosition__C16CB4CollidingBody(pCollidingBody);
  __asm
  {
    lqc2         $vf1, 0x40+var_30($sp)
    qmtc2        $v0, $vf2
    vsub.xyz     $vf1, $vf1, $vf2
    lqc2         $vf2, 0x40+var_40($sp)
    vopmula      $A, $vf1, $vf2
    vopmsub      $vf1, $vf2, $vf1
    sqc2         $vf1, 0($s0)
    lq           $s0, 0x40+var_10($sp)
  }
  return result;
}

// CB4CollidingBody::GetPosition(void) const
__int64 __fastcall GetPosition__C16CB4CollidingBody(B4CollidingBody *pCollidingBody)
{
  __int64 result; // $v0

  _$V1 = pCollidingBody->m_pCollisionShapeData;
  __asm { lq           $v0, 0x30($v1) }
  return result;
}
