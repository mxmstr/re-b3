/*
00000000 struct __attribute__((packed)) GtMatrix3x4 // sizeof=0x30
00000000 {                                       // XREF: B4VehicleDeform/r
00000000                                         // B4VehicleData/r ...
00000000     float m[3][4];
00000030 };

00000000 struct GtV3d // sizeof=0x10
00000000 {                                       // XREF: B4CollidingBody/r
00000000                                         // B4CollidingBody/r ...
00000000     float x;
00000004     float y;
00000008     float z;                            // XREF: _ChangeFileTime__11RealmcIfaceGQ26Realmc8DateTime+34/o
0000000C     float w;                            // XREF: RemoveVehiclesDetachedBodyParts__17CB4PhysicsManagerP17CB4VehiclePhysics+1C/o
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

00000000 struct __attribute__((packed)) GtTextureSubDefinition // sizeof=0x10
00000000 {
00000000     unsigned int sub_def_flags;
00000004     void *pPixelDataForSubDef_offset;
00000008     unsigned __int8 sub_def_padding[8];
00000010 };

00000000 struct __attribute__((packed)) B4ConvexHull // sizeof=0x340
00000000 {                                       // XREF: B4VehicleData/r
00000000                                         // B4VehiclePhysics/r ...
00000000     unsigned int m_offsetFaces;
00000004     unsigned int m_offsetPlanes;
00000008     unsigned int m_offsetVertices;
0000000C     unsigned int m_offsetEdges;
00000010     unsigned int m_offsetDeformData;
00000014     unsigned int m_flags;
00000018     unsigned __int8 m_numVertices;
00000019     unsigned __int8 m_numPlanes;
0000001A     unsigned __int8 m_numEdges;
0000001B     unsigned __int8 m_padding_or_unused1B;
0000001C     unsigned __int8 m_faceData[68];     // XREF: DrawPropCOM__22CB4PhysicsManagerDebug+50/o
0000001C                                         // Update__12CB4CrashRampPfT1i+58/o
00000060     unsigned __int8 m_planeData[224];
00000140     unsigned __int8 m_vertexData[256];
00000240     unsigned __int8 m_edgeData[56];
00000278     unsigned __int8 m_deformData[200];
00000340 };

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

00000000 struct __attribute__((packed)) GtTexture // sizeof=0xA8
00000000 {                                       // XREF: GtDictionaryEntry/r
00000000     void *pPixelData_offset;
00000004     void *pClutData_offset;
00000008     void *pMipmapData_offset;
0000000C     unsigned __int8 unknown_data_0C_to_23[24];
00000024     GtTextureSubDefinition *pSubDefinitions_offset;
00000028     unsigned __int8 unknown_data_0x28_to_0x6B[68];
0000006C     char *pTextureName_offset;
00000070     void *pGsRamClutPtrs_offset[7];
0000008C     char pad_8C[24];
000000A4     void *unk_A4;
000000A8 };

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

*/

// CB4SoundESMGraphStruct::FixUp(void)
__int64 __fastcall FixUp__22CB4SoundESMGraphStruct(B4SoundESMGraphStruct *a1)
{
  __int64 pGraphDataPoints_offset; // $v0
  bool v2; // dc
  __int64 result; // $v0

  pGraphDataPoints_offset = a1->pGraphDataPoints_offset;
  v2 = pGraphDataPoints_offset == 0;
  result = (a1 + pGraphDataPoints_offset);
  if ( !v2 )
    a1->pGraphDataPoints_offset = result;
  return result;
}

// CB4SoundESMPartialStruct::FixUp(void)
__int64 __fastcall FixUp__24CB4SoundESMPartialStruct(B4SoundESMPartialStruct *a1)
{
  __int64 pGraphs_offset; // $v0
  bool v5; // dc
  __int64 result; // $v0
  __int64 numGraphs; // $v1
  __int64 v8; // $s0
  B4SoundESMGraphStruct *i; // $v0
  int v10; // $a0

  __asm
  {
    sq           $s1, 0x30+var_20($sp)
    sq           $s0, 0x30+var_10($sp)
  }
  pGraphs_offset = a1->pGraphs_offset;
  v5 = pGraphs_offset == 0;
  result = &a1->unknown_partial_data[pGraphs_offset];
  if ( !v5 )
  {
    numGraphs = a1->numGraphs;
    a1->pGraphs_offset = result;
    LODWORD(v8) = 0;
    if ( numGraphs )
    {
      for ( i = a1->pGraphs_offset; ; i = a1->pGraphs_offset )
      {
        v10 = v8;
        v8 = v8 + 1;
        FixUp__22CB4SoundESMGraphStruct(&i[v10]);
        result = v8 < a1->numGraphs;
        if ( v8 >= a1->numGraphs )
          break;
      }
    }
  }
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    lq           $s1, 0x30+var_20($sp)
  }
  return result;
}

// CB4SoundESMStruct::FixUp(void)
__int64 __fastcall FixUp__17CB4SoundESMStruct(B4SoundESMStruct *pSoundESMStruct)
{
  __int64 pPartials_offset; // $v0
  bool v5; // dc
  __int64 result; // $v0
  __int64 numPartials; // $v1
  __int64 v8; // $s0
  B4SoundESMPartialStruct *i; // $v0
  int v10; // $a0

  __asm
  {
    sq           $s1, 0x30+var_20($sp)
    sq           $s0, 0x30+var_10($sp)
  }
  pPartials_offset = pSoundESMStruct->pPartials_offset;
  v5 = pPartials_offset == 0;
  result = &pSoundESMStruct->unknown_header_data[pPartials_offset];
  if ( !v5 )
  {
    numPartials = pSoundESMStruct->numPartials;
    pSoundESMStruct->pPartials_offset = result;
    LODWORD(v8) = 0;
    if ( numPartials )
    {
      for ( i = pSoundESMStruct->pPartials_offset; ; i = pSoundESMStruct->pPartials_offset )
      {
        v10 = v8;
        v8 = v8 + 1;
        FixUp__24CB4SoundESMPartialStruct(&i[v10]);
        result = v8 < pSoundESMStruct->numPartials;
        if ( v8 >= pSoundESMStruct->numPartials )
          break;
      }
    }
  }
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    lq           $s1, 0x30+var_20($sp)
  }
  return result;
}

// CB4ConvexHull::Fixup(void)
__int64 __fastcall Fixup__13CB4ConvexHull(B4ConvexHull *pConvexHull)
{
  unsigned int v1; // $a1
  unsigned int m_offsetDeformData; // $v0
  unsigned int v3; // $a3
  unsigned int v4; // $a2
  __int64 result; // $v0

  v1 = pConvexHull + pConvexHull->m_offsetPlanes;
  m_offsetDeformData = pConvexHull->m_offsetDeformData;
  v3 = pConvexHull + pConvexHull->m_offsetVertices;
  v4 = pConvexHull + pConvexHull->m_offsetEdges;
  pConvexHull->m_offsetFaces += pConvexHull;
  result = (pConvexHull + m_offsetDeformData);
  pConvexHull->m_offsetPlanes = v1;
  pConvexHull->m_offsetDeformData = result;
  pConvexHull->m_offsetVertices = v3;
  pConvexHull->m_offsetEdges = v4;
  return result;
}

// CB4VehiclePayloadSet::FixUp(void)
__int64 __fastcall FixUp__20CB4VehiclePayloadSet(B4VehiclePayloadSet *pVehiclePayloadSet)
{
  __int64 result; // $v0

  result = (pVehiclePayloadSet->pAttachmentPointsData_offset + pVehiclePayloadSet);
  pVehiclePayloadSet->pAttachmentPointsData_offset = result;
  return result;
}

// CB4VehicleLODDataBase::FixUp(void)
unsigned __int64 __fastcall FixUp__21CB4VehicleLODDataBase(B4VehicleLODDataBase *pVehicleLODData)
{
  B4ModelData *pMainModel_offset; // $v0
  B4ModelData **pGlassModels_offset; // $a6
  unsigned int v4; // $a1
  __int64 v5; // $a2
  __int64 v6; // $v1
  int i; // $a0
  int v8; // $v1
  unsigned int v9; // $a0
  __int64 v10; // $v1
  B4ModelData **pWheelModels_offset; // $a4
  __int64 v12; // $a3
  int v13; // $v0
  char *v14; // $a1
  __int64 v15; // $a2
  __int64 v16; // $v1
  int j; // $a0
  int v18; // $v1
  _DWORD *v19; // $a0
  __int64 v20; // $v1
  __int64 v21; // $a3
  unsigned __int64 result; // $v0
  _DWORD *v23; // $v1
  __int64 v24; // $v0
  char *v25; // $a1
  __int64 v26; // $a2
  __int64 v27; // $v1
  int k; // $a0
  int v29; // $v1
  _DWORD *v30; // $a0
  __int64 v31; // $v1

  pMainModel_offset = pVehicleLODData->pMainModel_offset;
  pGlassModels_offset = pVehicleLODData->pGlassModels_offset;
  if ( pVehicleLODData->pMainModel_offset )
  {
    v4 = pVehicleLODData + pMainModel_offset;
    LODWORD(v5) = 0;
    pVehicleLODData->pMainModel_offset = (pVehicleLODData + pMainModel_offset);
    v6 = *(&pVehicleLODData->pMainModel_offset + pMainModel_offset);
    *(pVehicleLODData->pWheelModels_offset + pMainModel_offset) = (*(pVehicleLODData->pWheelModels_offset
                                                                   + pMainModel_offset)
                                                                 + pVehicleLODData
                                                                 + pMainModel_offset);
    if ( v6 > 0 )
    {
      for ( i = *(v4 + 4); ; i = *(v4 + 4) )
      {
        v8 = 16 * v5;
        v5 = v5 + 1;
        v9 = v8 + i;
        v10 = *(v9 + 4);
        *v9 += v9;
        if ( v10 )
          *(v9 + 4) = v10 + v9;
        if ( v5 >= *v4 )
          break;
      }
      pGlassModels_offset = pVehicleLODData->pGlassModels_offset;
    }
  }
  pWheelModels_offset = pVehicleLODData->pWheelModels_offset;
  LODWORD(v12) = 7;
  do
  {
    v13 = *pWheelModels_offset;
    if ( *pWheelModels_offset )
    {
      v14 = pVehicleLODData + v13;
      LODWORD(v15) = 0;
      *pWheelModels_offset = (pVehicleLODData + v13);
      v16 = *(&pVehicleLODData->pMainModel_offset + v13);
      *(pVehicleLODData->pWheelModels_offset + v13) = (*(pVehicleLODData->pWheelModels_offset + v13)
                                                     + pVehicleLODData
                                                     + v13);
      if ( v16 > 0 )
      {
        for ( j = *(v14 + 1); ; j = *(v14 + 1) )
        {
          v18 = 16 * v15;
          v15 = v15 + 1;
          v19 = (v18 + j);
          v20 = v19[1];
          *v19 += v19;
          if ( v20 )
            v19[1] = v19 + v20;
          if ( v15 >= *v14 )
            break;
        }
      }
      v12 = v12 - 1;
    }
    else
    {
      v12 = v12 - 1;
    }
    ++pWheelModels_offset;
  }
  while ( v12 >= 0 );
  LODWORD(v21) = 0;
  LODWORD(result) = 0;
  do
  {
    v23 = &pGlassModels_offset[result / 4];
    v24 = pGlassModels_offset[result / 4];
    v21 = v21 + 1;
    if ( v24 )
    {
      v25 = pVehicleLODData + v24;
      LODWORD(v26) = 0;
      *v23 = pVehicleLODData + v24;
      v27 = *(&pVehicleLODData->pMainModel_offset + v24);
      *(pVehicleLODData->pWheelModels_offset + v24) = (*(pVehicleLODData->pWheelModels_offset + v24)
                                                     + pVehicleLODData
                                                     + v24);
      if ( v27 > 0 )
      {
        for ( k = *(v25 + 1); ; k = *(v25 + 1) )
        {
          v29 = 16 * v26;
          v26 = v26 + 1;
          v30 = (v29 + k);
          v31 = v30[1];
          *v30 += v30;
          if ( v31 )
            v30[1] = v30 + v31;
          if ( v26 >= *v25 )
            break;
        }
      }
    }
    result = 4 * v21;
  }
  while ( v21 < 3 );
  return result;
}

// CGtTexture::FixUp(void)
__int64 __fastcall FixUp__10CGtTexture(GtTexture *pTexture)
{
  __int64 pUnknown1_Offset; // $v0
  bool isNullOffset; // dc
  char *pUnknown1_Fixed; // $v0
  __int64 pUnknown2_Offset; // $v0
  char *pUnknown2_Fixed; // $v0
  __int64 pEntryList_Offset; // $v0
  GtTextureSubDefinition *pEntryList_Fixed; // $v0
  __int64 pPalette_Offset; // $v0
  char *pPalette_Fixed; // $v0
  void **mipmapOffsetPtr; // $v1
  unsigned __int64 mipmapIndex; // $a2
  void **mipmapFixedPtr; // $a1
  __int64 currentMipmapOffset; // $v0
  char *fixedMipmapPtr; // $v0
  __int64 fixedRecordPtr; // $v0
  unsigned __int64 recordIndex; // $a2
  unsigned __int64 recordCount; // $a3
  int currentRecordBase; // $a1
  int recordFieldAddr; // $a1

  if ( pTexture->pPixelData_offset )
    pTexture->pPixelData_offset = pTexture->pPixelData_offset + pTexture;
  pUnknown1_Offset = pTexture->pClutData_offset;
  isNullOffset = pUnknown1_Offset == 0;
  pUnknown1_Fixed = pTexture + pUnknown1_Offset;
  if ( !isNullOffset )
    pTexture->pClutData_offset = pUnknown1_Fixed;
  pUnknown2_Offset = pTexture->pMipmapData_offset;
  isNullOffset = pUnknown2_Offset == 0;
  pUnknown2_Fixed = pTexture + pUnknown2_Offset;
  if ( !isNullOffset )
    pTexture->pMipmapData_offset = pUnknown2_Fixed;
  pEntryList_Offset = pTexture->pSubDefinitions_offset;
  isNullOffset = pEntryList_Offset == 0;
  pEntryList_Fixed = (pTexture + pEntryList_Offset);
  if ( !isNullOffset )
    pTexture->pSubDefinitions_offset = pEntryList_Fixed;
  pPalette_Offset = pTexture->pTextureName_offset;
  isNullOffset = pPalette_Offset == 0;
  pPalette_Fixed = pTexture + pPalette_Offset;
  if ( !isNullOffset )
    pTexture->pTextureName_offset = pPalette_Fixed;
  mipmapOffsetPtr = pTexture->pGsRamClutPtrs_offset;
  LODWORD(mipmapIndex) = 0;
  mipmapFixedPtr = pTexture->pGsRamClutPtrs_offset;
  do
  {
    currentMipmapOffset = *mipmapOffsetPtr;
    isNullOffset = currentMipmapOffset == 0;
    fixedMipmapPtr = pTexture + currentMipmapOffset;
    if ( !isNullOffset )
      *mipmapFixedPtr = fixedMipmapPtr;
    mipmapIndex = mipmapIndex + 1;
    ++mipmapFixedPtr;
    ++mipmapOffsetPtr;
  }
  while ( mipmapIndex < 7 );
  fixedRecordPtr = pTexture->pSubDefinitions_offset;
  LODWORD(recordIndex) = 0;
  recordCount = pTexture->pSubDefinitions_offset->sub_def_flags;
  currentRecordBase = fixedRecordPtr + 16;
  if ( pTexture->pSubDefinitions_offset->sub_def_flags )
  {
    do
    {
      recordFieldAddr = currentRecordBase + 48;
      recordIndex = recordIndex + 1;
      fixedRecordPtr = pTexture + *(recordFieldAddr + 4);
      *(recordFieldAddr + 4) = fixedRecordPtr;
      currentRecordBase = recordFieldAddr + 16;
    }
    while ( recordIndex < recordCount );
  }
  return fixedRecordPtr;
}

// CB4VehicleData::FixUp(void)
__int64 __fastcall FixUp__14CB4VehicleData(B4VehicleData *pVehicleData)
{
  __int64 m_pLiveryTexture; // $v0
  bool v9; // dc
  GtTexture *v10; // $v0
  __int64 m_pDamageTexture; // $v0
  GtTexture *v12; // $v0
  B4VehicleLODDataBase **m_vehicleLODs; // $s0
  __int64 v14; // $s2
  __int64 v15; // $v0
  B4VehicleLODDataBase *v16; // $v0
  B4ModelData *m_pMainBodyModelData; // $v0
  __int64 m_pBodyPartsModelData; // $v0
  char *v19; // $a1
  __int64 v20; // $a2
  __int64 v21; // $v1
  int i; // $v1
  _DWORD *v23; // $v1
  __int64 v24; // $a0
  void **m_unknownPointers_at_8452; // $v1
  char *v26; // $a1
  __int64 v27; // $a2
  __int64 v28; // $v1
  int j; // $v1
  _DWORD *v30; // $v1
  __int64 v31; // $a0
  __int64 v32; // $s2
  __int64 v33; // $v0
  char *v34; // $v0
  __int64 m_pUnknownData_8548; // $v0
  char *v36; // $v0
  __int64 m_pPayloadSetsArray; // $v0
  B4VehiclePayloadSet *v38; // $v0
  __int64 m_numPayloadSets; // $v1
  __int64 v40; // $s2
  int v41; // $s0
  B4SoundESMStruct **m_pSoundESM; // $s0
  __int64 v43; // $s2
  __int64 v44; // $v0
  B4SoundESMStruct *v45; // $v0
  __int64 m_pSomeFinalData; // $v0
  __int64 result; // $v0

  __asm
  {
    sq           $s1, 0x70+var_20($sp)
    sq           $s0, 0x70+var_10($sp)
    sq           $s2, 0x70+var_30($sp)
    sq           $s3, 0x70+var_40($sp)
    sq           $s4, 0x70+var_50($sp)
    sq           $s5, 0x70+var_60($sp)
  }
  m_pLiveryTexture = pVehicleData->m_pLiveryTexture;
  v9 = m_pLiveryTexture == 0;
  v10 = (pVehicleData + m_pLiveryTexture);
  if ( !v9 )
  {
    pVehicleData->m_pLiveryTexture = v10;
    FixUp__10CGtTexture(v10);
  }
  m_pDamageTexture = pVehicleData->m_pDamageTexture;
  v9 = m_pDamageTexture == 0;
  v12 = (pVehicleData + m_pDamageTexture);
  if ( !v9 )
  {
    pVehicleData->m_pDamageTexture = v12;
    FixUp__10CGtTexture(v12);
  }
  m_vehicleLODs = pVehicleData->m_vehicleLODs;
  LODWORD(v14) = 4;
  do
  {
    v15 = *m_vehicleLODs;
    v9 = v15 == 0;
    v16 = (pVehicleData + v15);
    if ( !v9 )
    {
      *m_vehicleLODs = v16;
      FixUp__21CB4VehicleLODDataBase(v16);
    }
    v14 = v14 - 1;
    ++m_vehicleLODs;
  }
  while ( v14 >= 0 );
  m_pMainBodyModelData = pVehicleData->m_pMainBodyModelData;
  if ( m_pMainBodyModelData )
  {
    v19 = pVehicleData + m_pMainBodyModelData;
    LODWORD(v20) = 0;
    pVehicleData->m_pMainBodyModelData = (pVehicleData + m_pMainBodyModelData);
    v21 = *(&pVehicleData->m_vehicleID_or_Type + m_pMainBodyModelData);
    *(&pVehicleData->m_unknown_int_4 + m_pMainBodyModelData) += pVehicleData + m_pMainBodyModelData;
    if ( v21 > 0 )
    {
      for ( i = *(v19 + 1); ; i = *(v19 + 1) )
      {
        v23 = (16 * v20 + i);
        v24 = v23[1];
        *v23 += v23;
        if ( v24 )
          v23[1] = v23 + v24;
        v20 = v20 + 1;
        if ( v20 >= *v19 )
          break;
      }
    }
    m_pBodyPartsModelData = pVehicleData->m_pBodyPartsModelData;
  }
  else
  {
    m_pBodyPartsModelData = pVehicleData->m_pBodyPartsModelData;
  }
  m_unknownPointers_at_8452 = pVehicleData->m_unknownPointers_at_8452;
  if ( m_pBodyPartsModelData )
  {
    v26 = pVehicleData + m_pBodyPartsModelData;
    LODWORD(v27) = 0;
    pVehicleData->m_pBodyPartsModelData = (pVehicleData + m_pBodyPartsModelData);
    v28 = *(&pVehicleData->m_vehicleID_or_Type + m_pBodyPartsModelData);
    *(&pVehicleData->m_unknown_int_4 + m_pBodyPartsModelData) += pVehicleData + m_pBodyPartsModelData;
    if ( v28 > 0 )
    {
      for ( j = *(v26 + 1); ; j = *(v26 + 1) )
      {
        v30 = (16 * v27 + j);
        v31 = v30[1];
        *v30 += v30;
        if ( v31 )
          v30[1] = v30 + v31;
        v27 = v27 + 1;
        if ( v27 >= *v26 )
          break;
      }
    }
    m_unknownPointers_at_8452 = pVehicleData->m_unknownPointers_at_8452;
  }
  LODWORD(v32) = 17;
  do
  {
    v33 = *m_unknownPointers_at_8452;
    v9 = v33 == 0;
    v34 = pVehicleData + v33;
    if ( !v9 )
      *m_unknownPointers_at_8452 = v34;
    v32 = v32 - 1;
    ++m_unknownPointers_at_8452;
  }
  while ( v32 >= 0 );
  m_pUnknownData_8548 = pVehicleData->m_pUnknownData_8548;
  v9 = m_pUnknownData_8548 == 0;
  v36 = pVehicleData + m_pUnknownData_8548;
  if ( !v9 )
    pVehicleData->m_pUnknownData_8548 = v36;
  m_pPayloadSetsArray = pVehicleData->m_pPayloadSetsArray;
  v9 = m_pPayloadSetsArray == 0;
  v38 = (pVehicleData + m_pPayloadSetsArray);
  if ( !v9 )
  {
    m_numPayloadSets = pVehicleData->m_numPayloadSets;
    pVehicleData->m_pPayloadSetsArray = v38;
    LODWORD(v40) = 0;
    if ( m_numPayloadSets > 0 )
    {
      v41 = 0;
      do
      {
        v40 = v40 + 1;
        FixUp__20CB4VehiclePayloadSet(&pVehicleData->m_pPayloadSetsArray[v41++]);
      }
      while ( v40 < pVehicleData->m_numPayloadSets );
    }
  }
  m_pSoundESM = pVehicleData->m_pSoundESM;
  Fixup__13CB4ConvexHull(&pVehicleData->m_physicsConvexHullData);
  LODWORD(v43) = 1;
  do
  {
    v44 = *m_pSoundESM;
    v9 = v44 == 0;
    v45 = (pVehicleData + v44);
    if ( !v9 )
    {
      *m_pSoundESM = v45;
      FixUp__17CB4SoundESMStruct(v45);
    }
    v43 = v43 - 1;
    ++m_pSoundESM;
  }
  while ( v43 >= 0 );
  m_pSomeFinalData = pVehicleData->m_pSomeFinalData;
  v9 = m_pSomeFinalData == 0;
  result = (pVehicleData + m_pSomeFinalData);
  if ( !v9 )
    pVehicleData->m_pSomeFinalData = result;
  __asm
  {
    lq           $s0, 0x70+var_10($sp)
    lq           $s1, 0x70+var_20($sp)
    lq           $s2, 0x70+var_30($sp)
    lq           $s3, 0x70+var_40($sp)
    lq           $s4, 0x70+var_50($sp)
    lq           $s5, 0x70+var_60($sp)
  }
  return result;
}



