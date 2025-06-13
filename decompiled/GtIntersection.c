/*
00000000 struct GtPolygonSoup // sizeof=0x3C
00000000 {
00000000     GtPolygonSoupHeader header;
0000003C };

00000000 struct GtPolygonSoup16 // sizeof=0x3C
00000000 {
00000000     GtPolygonSoupHeader header;
0000003C };

00000000 struct GtPolygonSoupHeader // sizeof=0x3C
00000000 {                                       // XREF: GtPolygonSoup/r
00000000                                         // GtPolygonSoup16/r
00000000     const void *pIndexData;
00000004     const void *pVertexData;
00000008     int unknown_offset_8;
0000000C     int unknown_offset_C;
00000010     int unknown_offset_10;
00000014     int unknown_offset_14;
00000018     int unknown_offset_18;
0000001C     int unknown_offset_1C;
00000020     int unknown_offset_20;
00000024     int unknown_offset_24;
00000028     float boundingBoxMinX;
0000002C     float boundingBoxMinY;
00000030     float boundingBoxMinZ;
00000034     int numPolygons_or_stride;
00000038     int numVertices_or_count;
0000003C };

00000000 struct GtPolygonIntersectionResult // sizeof=0x6C
00000000 {
00000000     GtV3d intersectionPoint;
00000010     GtV3d surfaceNormal;
00000020     unsigned __int8 padding_or_other_data[48];
00000050     float intersection_t;
00000054     float barycentric_u;
00000058     float barycentric_v;
0000005C     unsigned __int8 padding2[4];
00000060     const void *pPolygonIndices;
00000064     int subPolygonIndex;
00000068     const void *pVertexBase;
0000006C };

00000000 struct GtAxisAlignedBox // sizeof=0x20
00000000 {
00000000     GtV3d minPoint;
00000010     GtV3d maxPoint;
00000020 };

00000000 struct GtExtrudedBox // sizeof=0x40
00000000 {
00000000     GtV3d baseCenterOrCorner;
00000010     GtV3d baseHalfExtentsOrEdge1;
00000020     GtV3d extrusionVectorOrBaseEdge2;
00000030     GtV3d extrusionParamsOrOther;
00000040 };

00000000 struct GtOrthogonalBox // sizeof=0x40
00000000 {
00000000     GtV3d center;
00000010     GtV3d basisAxisX;
00000020     GtV3d basisAxisY;
00000030     GtV3d halfExtents;
00000040 };

00000000 struct GtSimpleOrientedBox // sizeof=0x80
00000000 {
00000000     GtV3d corners[8];
00000080 };

00000000 struct GtFrustum // sizeof=0x60
00000000 {
00000000     GtV3d planes[6];
00000060 };

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
*/

// GtIntersection::IntersectSphereTriangle(GtMathPs2::CGtSphere, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d *)
__int64 __fastcall IntersectSphereTriangle__14GtIntersectionGQ29GtMathPs29CGtSphereGQ29GtMathPs26CGtV3dN22PQ29GtMathPs26CGtV3d(
        __int64 _$A0,
        __int64 _$A1,
        __int64 _$A2,
        __int64 _$A3)
{
  __int64 v10; // $ra
  __int64 v13; // $v0
  int *Chan; // $v0
  __int64 result; // $v0
  int v33; // [sp+Ch] [-D4h]
  __int128 v34; // [sp+20h] [-C0h] BYREF
  __int128 v35; // [sp+30h] [-B0h] BYREF
  unsigned int v36; // [sp+40h] [-A0h]
  unsigned int v37; // [sp+44h] [-9Ch]
  unsigned int v38; // [sp+50h] [-90h]
  unsigned int v39; // [sp+54h] [-8Ch]
  unsigned int v40; // [sp+60h] [-80h]
  unsigned int v41; // [sp+64h] [-7Ch]
  __int64 v42; // [sp+70h] [-70h]

  __asm
  {
    sq           $s0, 0xE0+var_10($sp)
    sq           $s1, 0xE0+var_20($sp)
    sq           $s2, 0xE0+var_30($sp)
    sq           $s3, 0xE0+var_40($sp)
    sq           $s4, 0xE0+var_50($sp)
  }
  _$S3 = &v35;
  __asm { sq           $s5, 0xE0+var_60($sp) }
  _$S4 = &v34;
  v42 = v10;
  __asm
  {
    sq           $a0, 0xE0+var_C0($sp)
    sq           $a1, 0xE0+var_A0($sp)
    sq           $a2, 0xE0+var_90($sp)
    sq           $a3, 0xE0+var_80($sp)
  }
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v13 = 1LL;
    }
    else
    {
      v13 = 0LL;
    }
    _$S4 = &v34;
    _$S3 = &v35;
    if ( v13 )
    {
      do
        Chan = sceDmaGetChan(0LL);
      while ( sceDmaSync(Chan, 1LL) );
    }
  }
  __asm
  {
    lqc2         $vf1, 0xE0+var_C0($sp)
    vmulw.w      $vf1, $vf1, $vf1
    lqc2         $vf2, 0xE0+var_B0($sp)
    sqc2         $vf1, 0xE0+var_E0($sp)
  }
  _$V0 = v33;
  _$V1 = v33;
  __asm
  {
    qmtc2        $v0, $vf1
    qmtc2        $v1, $vf3
    vaddx.x      $vf2, $vf0, $vf1
  }
  _$V0 = v33;
  __asm
  {
    vmove.xyzw   $vf26, $vf2
    qmtc2        $v0, $vf1
    vaddx.y      $vf26, $vf0, $vf3
    sqc2         $vf2, 0xE0+var_B0($sp)
    sqc2         $vf26, 0xE0+var_B0($sp)
    vaddx.z      $vf26, $vf0, $vf1
    sqc2         $vf26, 0xE0+var_B0($sp)
    lqc2         $vf2, 0($s4)
    lqc2         $vf3, 0($s3)
  }
  _$A1 = (v37 << 32) | v36;
  __asm
  {
    pcpyld       $a0, $a1
    qmtc2        $a0, $vf4
  }
  _$A1 = (v39 << 32) | v38;
  __asm
  {
    pcpyld       $a0, $a1
    qmtc2        $a0, $vf5
  }
  _$A1 = (v41 << 32) | v40;
  __asm
  {
    pcpyld       $a0, $a1
    qmtc2        $a0, $vf6
    cop2         0x338
    cfc2         $v1, $vi1, 1
    qmfc2        $v0, $vf8
    sq           $v0, 0($s5)
    lq           $s0, 0xE0+var_10($sp)
    lq           $s1, 0xE0+var_20($sp)
  }
  result = _$V1 != 0LL;
  __asm
  {
    lq           $s2, 0xE0+var_30($sp)
    lq           $s3, 0xE0+var_40($sp)
    lq           $s4, 0xE0+var_50($sp)
    lq           $s5, 0xE0+var_60($sp)
  }
  return result;
}

// GtIntersection::IntersectLineNearest(const CGtLine &, const CGtPolygonSoup &, CGtPolygonIntersectionResult *)
__int64 __fastcall IntersectLineNearest__14GtIntersectionRC7CGtLineRC16CGtPolygonSoup16P28CGtPolygonIntersectionResult(
        int a1,
        int *a2,
        int a3)
{
  __int64 v12; // $ra
  float v13; // $f20
  float v14; // $f21
  __int64 v17; // $v0
  bool v18; // dc
  int v19; // $v1
  int v20; // $a0
  float v21; // $f1
  unsigned __int64 v22; // $fp
  int v23; // $s6
  int v24; // $v1
  float v25; // $f2
  unsigned __int64 v28; // $s2
  float v29; // $f21
  unsigned __int64 v30; // $s7
  unsigned __int64 v31; // $s0
  float v32; // $f22
  float v33; // $f20
  int v34; // $s1
  __int64 v35; // $v0
  unsigned __int64 v36; // $a5
  int *Chan; // $v0
  __int64 v38; // $a7
  int v41; // $v1
  __int64 v49; // $a6
  int v50; // $a0
  int v51; // $v1
  int v52; // $a1
  int v53; // $v1
  __int64 v65; // $a6
  int v66; // $a0
  int v67; // $v1
  int v68; // $a1
  int v69; // $v1
  __int64 result; // $v0
  int v87; // $v1
  float v100; // [sp+30h] [-140h]
  float v101; // [sp+34h] [-13Ch]
  float v102; // [sp+38h] [-138h]
  float v107[4]; // [sp+80h] [-F0h] BYREF
  __int16 v108; // [sp+90h] [-E0h]
  __int16 v109; // [sp+92h] [-DEh]
  __int16 v110; // [sp+94h] [-DCh]
  int v111; // [sp+98h] [-D8h]
  int v112; // [sp+9Ch] [-D4h]
  __int64 v115; // [sp+C0h] [-B0h]
  float v125; // [sp+160h] [-10h]
  float v126; // [sp+168h] [-8h]

  __asm
  {
    sq           $s3, 0x170+var_50($sp)
    sq           $s4, 0x170+var_60($sp)
    sq           $s0, 0x170+var_20($sp)
  }
  _$S4 = a1;
  __asm
  {
    sq           $s1, 0x170+var_30($sp)
    sq           $s2, 0x170+var_40($sp)
    sq           $s5, 0x170+var_70($sp)
    sq           $s6, 0x170+var_80($sp)
    sq           $s7, 0x170+var_90($sp)
    sq           $fp, 0x170+var_A0($sp)
  }
  v115 = v12;
  v126 = v14;
  v125 = v13;
  v17 = 1LL;
  do
  {
    v18 = v17 != -1;
    v17 = v17 - 1;
  }
  while ( v18 );
  v19 = *(a2 + 11);
  v20 = *(a2 + 10);
  v111 = 0;
  v21 = v19;
  v22 = 0LL;
  v23 = *(a2 + 13);
  v24 = *(a2 + 14);
  v25 = *(a2 + 12);
  v107[0] = v20;
  v107[1] = v21;
  v107[2] = v25;
  _$V0 = COERCE_INT(500.0);
  v112 = 0;
  __asm
  {
    qmtc2        $v0, $vf1
    lq           $v0, 0x170+var_F0($sp)
  }
  v28 = *a2;
  __asm { sq           $v0, 0x170+var_D0($sp) }
  v29 = 0.0;
  v30 = v28 + v23 * v24;
  __asm { lqc2         $vf2, 0x170+var_D0($sp) }
  v31 = v28;
  __asm
  {
    vmulx.xyz    $vf2, $vf2, $vf1
    sqc2         $vf2, 0x170+var_D0($sp)
  }
  v32 = 0.0;
  v33 = *(a3 + 80);
  v34 = a2[1];
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code == gacGtIntsecVu0Code )
    goto LABEL_9;
  17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
  if ( gacGtIntsecVu0Code )
  {
    MEMORY[0x10008020] = 0;
    MEMORY[0x10008030] = gacGtIntsecVu0Code;
    MEMORY[0x10008000] = 325;
    v35 = 1LL;
  }
  else
  {
    v35 = 0LL;
  }
  v36 = v28;
  if ( v35 )
  {
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
LABEL_9:
    v36 = v28;
  }
  __asm
  {
    lqc2         $vf1, 0x170+var_C0($sp)
    lqc2         $vf2, 0x170+var_D0($sp)
  }
  LODWORD(v38) = 0;
  __asm
  {
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0x170+var_C0($sp)
  }
  _$A1 = COERCE_INT(0.015258789);
  __asm
  {
    qmtc2        $a1, $vf1
    lqc2         $vf2, 0x170+var_C0($sp)
    vmr32.w      $vf2, $vf1
    sqc2         $vf2, 0x170+var_C0($sp)
  }
  LODWORD(_$A1) = v34 + 6 * *(v36 + 1);
  _$V0 = v34 + 6 * *v36;
  v41 = v34 + 6 * *(v36 + 2);
  __asm
  {
    lq           $a4, 0x170+var_C0($sp)
    ctc2         $v0, $vi0, 1
    lqc2         $vf2, 0($s4)
    lqc2         $vf4, 0x10($s4)
    qmtc2        $a4, $vf23
  }
  _$A2 = (*(_$V0 + 2) << 32) | *(v34 + 6 * *v36);
  __asm
  {
    pcpyld       $a3, $a2
    qmtc2        $a3, $vf5
  }
  _$A2 = (*(_$A1 + 2) << 32) | *_$A1;
  __asm
  {
    pcpyld       $a3, $a2
    qmtc2        $a3, $vf6
  }
  _$A2 = (*(v41 + 2) << 32) | *v41;
  __asm
  {
    pcpyld       $a3, $a2
    qmtc2        $a3, $vf7
    cop2         0x1C78
  }
  v108 = v34 + 6 * *(v36 + 2);
  v49 = 1LL;
  if ( *(v36 + 3) != 255LL )
    goto LABEL_29;
  v49 = 0LL;
  v50 = 0;
  v51 = 2;
  v31 = v36 + v23;
  while ( v31 < v30 )
  {
    v52 = v34 + 6 * *(v31 + 1);
    v53 = v34 + 6 * *(v31 + v51);
    _$A2 = (*(v34 + 6 * *(v31 + v50) + 2) << 32) | *(v34 + 6 * *(v31 + v50));
    __asm
    {
      pcpyld       $a4, $a2
      qmtc2        $a4, $vf8
    }
    _$A2 = (*(v52 + 2) << 32) | *v52;
    __asm
    {
      pcpyld       $a4, $a2
      qmtc2        $a4, $vf9
    }
    _$A2 = (*(v53 + 2) << 32) | *v53;
    __asm
    {
      pcpyld       $a4, $a2
      qmtc2        $a4, $vf10
      cop2         0x2AB8
      cfc2         $a3, $vi1
      sqc2         $vf5, 0x170+var_170($sp)
      sqc2         $vf6, 0x170+var_160($sp)
      sqc2         $vf7, 0x170+var_150($sp)
      sqc2         $vf24, 0x170+var_140($sp)
      sqc2         $vf25, 0x170+var_130($sp)
    }
    v109 = _$A3;
    v112 = 1;
    if ( _$A3 )
    {
      if ( v100 < v33 )
      {
        __asm { lq           $a1, 0x170+var_170($sp) }
        v22 = v36;
        __asm { lq           $v1, 0x170+var_160($sp) }
        v33 = v100;
        __asm { lq           $a0, 0x170+var_150($sp) }
        v32 = v101;
        v29 = v102;
        __asm { lq           $v0, 0x170+var_130($sp) }
        v111 = v38;
        __asm
        {
          sq           $a1, 0x170+var_120($sp)
          por          $s5, $zero, $v0
          sq           $v1, 0x170+var_110($sp)
          sq           $a0, 0x170+var_100($sp)
        }
      }
      v38 = v49;
    }
    else
    {
      v38 = v49;
    }
    v36 = v31;
    if ( v38 || (v65 = 1LL, *(v31 + 3) == 255LL) )
    {
      v65 = 0LL;
      v66 = 0;
      v67 = 2;
      v31 = v31 + v23;
    }
    else
    {
      v66 = 2;
      v67 = 3;
    }
    if ( v31 >= v30 )
      break;
    v68 = v34 + 6 * *(v31 + 1);
    v69 = v34 + 6 * *(v31 + v67);
    _$A2 = (*(v34 + 6 * *(v31 + v66) + 2) << 32) | *(v34 + 6 * *(v31 + v66));
    __asm
    {
      pcpyld       $a4, $a2
      qmtc2        $a4, $vf5
    }
    _$A2 = (*(v68 + 2) << 32) | *v68;
    __asm
    {
      pcpyld       $a4, $a2
      qmtc2        $a4, $vf6
    }
    _$A2 = (*(v69 + 2) << 32) | *v69;
    __asm
    {
      pcpyld       $a4, $a2
      qmtc2        $a4, $vf7
      cop2         0x1CB8
      cfc2         $a3, $vi2
      sqc2         $vf8, 0x170+var_170($sp)
      sqc2         $vf9, 0x170+var_160($sp)
      sqc2         $vf10, 0x170+var_150($sp)
      sqc2         $vf26, 0x170+var_140($sp)
      sqc2         $vf27, 0x170+var_130($sp)
    }
    v112 = 0;
    v110 = _$A3;
    if ( _$A3 )
    {
      if ( v100 < v33 )
      {
        __asm { lq           $a1, 0x170+var_170($sp) }
        v22 = v36;
        __asm { lq           $v1, 0x170+var_160($sp) }
        v33 = v100;
        __asm { lq           $a0, 0x170+var_150($sp) }
        v32 = v101;
        v29 = v102;
        __asm { lq           $v0, 0x170+var_130($sp) }
        v111 = v38;
        __asm
        {
          sq           $a1, 0x170+var_120($sp)
          por          $s5, $zero, $v0
          sq           $v1, 0x170+var_110($sp)
          sq           $a0, 0x170+var_100($sp)
        }
      }
      v38 = v65;
    }
    else
    {
      v38 = v65;
    }
    v36 = v31;
    if ( v38 || (v49 = 1LL, *(v31 + 3) == 255LL) )
    {
      v49 = 0LL;
      v50 = 0;
      v51 = 2;
      v31 = v31 + v23;
    }
    else
    {
LABEL_29:
      v50 = 2;
      v51 = 3;
    }
  }
  if ( v112 )
  {
    __asm
    {
      cfc2         $v0, $vi2, 1
      sqc2         $vf8, 0x170+var_170($sp)
      sqc2         $vf9, 0x170+var_160($sp)
      sqc2         $vf10, 0x170+var_150($sp)
      sqc2         $vf26, 0x170+var_140($sp)
      sqc2         $vf27, 0x170+var_130($sp)
    }
  }
  else
  {
    __asm
    {
      cfc2         $v0, $vi1, 1
      sqc2         $vf5, 0x170+var_170($sp)
      sqc2         $vf6, 0x170+var_160($sp)
      sqc2         $vf7, 0x170+var_150($sp)
      sqc2         $vf24, 0x170+var_140($sp)
      sqc2         $vf25, 0x170+var_130($sp)
    }
  }
  v110 = _$V0;
  if ( _$V0 && v100 < v33 )
  {
    __asm { lq           $a1, 0x170+var_170($sp) }
    v22 = v36;
    __asm { lq           $v1, 0x170+var_160($sp) }
    v33 = v100;
    __asm { lq           $a0, 0x170+var_150($sp) }
    v32 = v101;
    v29 = v102;
    __asm { lq           $v0, 0x170+var_130($sp) }
    v111 = v38;
    __asm
    {
      sq           $a1, 0x170+var_120($sp)
      por          $s5, $zero, $v0
      sq           $v1, 0x170+var_110($sp)
      sq           $a0, 0x170+var_100($sp)
    }
  }
  __asm { lqc2         $vf3, 0x170+var_120($sp) }
  if ( v22 )
  {
    __asm
    {
      vaddw.x      $vf4, $vf0, $vf0
      lqc2         $vf2, 0x170+var_110($sp)
    }
    result = 1LL;
    __asm
    {
      lqc2         $vf1, 0x170+var_100($sp)
      vsub.xyz     $vf2, $vf2, $vf3
      vsub.xyz     $vf1, $vf1, $vf3
    }
    *(a3 + 88) = v29;
    __asm
    {
      vopmula      $A, $vf2, $vf1
      vopmsub      $vf2, $vf1, $vf2
      sq           $s5, 0($s3)
      vmul.xyz     $vf1, $vf2, $vf2
    }
    *(a3 + 80) = v33;
    __asm
    {
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf4, $vf1
    }
    *(a3 + 96) = v22;
    __asm
    {
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf1.x
      vwaitq
      vmulq.xyz    $vf2, $vf2, $Q
    }
    *(a3 + 104) = v34;
    __asm { sqc2         $vf2, 0x10($s3) }
    v87 = v111;
    *(a3 + 84) = v32;
    *(a3 + 100) = v87;
  }
  else
  {
    result = 0LL;
  }
  __asm
  {
    lq           $s0, 0x170+var_20($sp)
    lq           $s1, 0x170+var_30($sp)
    lq           $s2, 0x170+var_40($sp)
    lq           $s3, 0x170+var_50($sp)
    lq           $s4, 0x170+var_60($sp)
    lq           $s5, 0x170+var_70($sp)
    lq           $s6, 0x170+var_80($sp)
    lq           $s7, 0x170+var_90($sp)
    lq           $fp, 0x170+var_A0($sp)
  }
  return result;
}

// GtIntersection::IntersectLine(const CGtLine &, const CGtPolygonSoup &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *)
__int64 __fastcall IntersectLine__14GtIntersectionRC7CGtLineRC14CGtPolygonSoupPFRC28CGtPolygonIntersectionResultPv_bPv(
        int a1,
        int *a2,
        __int64 (__fastcall *a3)(_QWORD, _QWORD),
        int a4)
{
  __int64 v13; // $ra
  __int64 v15; // $v0
  bool v16; // dc
  int v17; // $fp
  unsigned __int64 v18; // $s0
  int v19; // $v1
  int v20; // $s2
  int v21; // $s5
  unsigned __int64 v22; // $s7
  __int64 v23; // $v0
  __int64 result; // $v0
  __int64 v25; // $v0
  int *Chan; // $v0
  unsigned __int8 *v27; // $v0
  int v28; // $a1
  int v30; // $a0
  __int64 v39; // $v0
  float v41; // $f2
  float v42; // $f0
  float v43; // $f2
  float v44; // $f0
  float v45; // $f0
  float v46; // $f2
  int v47; // $s6
  float v57; // [sp+0h] [-160h]
  float v58; // [sp+4h] [-15Ch]
  float v59; // [sp+8h] [-158h]
  __int128 v60; // [sp+10h] [-150h] BYREF
  float v61; // [sp+60h] [-100h]
  float v62; // [sp+64h] [-FCh]
  float v63; // [sp+68h] [-F8h]
  int v64; // [sp+70h] [-F0h]
  int v65; // [sp+74h] [-ECh]
  __int16 v66; // [sp+80h] [-E0h]
  float v67; // [sp+A0h] [-C0h] BYREF
  float v68; // [sp+A4h] [-BCh]
  float v69; // [sp+A8h] [-B8h]
  __int64 (__fastcall *v70)(_QWORD, _QWORD); // [sp+B0h] [-B0h]
  int v71; // [sp+B4h] [-ACh]
  int v72; // [sp+B8h] [-A8h]
  int v73; // [sp+BCh] [-A4h]
  __int64 v74; // [sp+C0h] [-A0h]

  __asm { sq           $s3, 0x160+var_40($sp) }
  _$S3 = a1;
  __asm
  {
    sq           $s0, 0x160+var_10($sp)
    sq           $s1, 0x160+var_20($sp)
    sq           $s2, 0x160+var_30($sp)
    sq           $s4, 0x160+var_50($sp)
    sq           $s5, 0x160+var_60($sp)
    sq           $s6, 0x160+var_70($sp)
    sq           $s7, 0x160+var_80($sp)
    sq           $fp, 0x160+var_90($sp)
  }
  v74 = v13;
  v70 = a3;
  v71 = a4;
  v72 = 0;
  v15 = 1LL;
  do
  {
    v16 = v15 != -1;
    v15 = v15 - 1;
  }
  while ( v16 );
  v17 = *(a2 + 12);
  v18 = *a2;
  v19 = v17 * *(a2 + 13);
  v20 = a2[1];
  v21 = 2;
  v73 = 0;
  v22 = v18 + v19;
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v23 = 1LL;
    }
    else
    {
      v23 = 0LL;
    }
    v16 = v23 == 0;
    v25 = v18 < v22;
    if ( v16 )
      goto LABEL_11;
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
  }
  v25 = v18 < v22;
LABEL_11:
  if ( !v25 )
  {
LABEL_23:
    result = v72;
    goto LABEL_24;
  }
  v27 = v18;
  while ( 1 )
  {
    v28 = 12 * *v27;
    _$V1 = v28 + v20;
    v30 = 12 * *(v18 + v21) + v20;
    __asm
    {
      ctc2         $v1, $vi0, 1
      lqc2         $vf2, 0($s3)
      lqc2         $vf4, 0x10($s3)
    }
    _$A1 = (*(_$V1 + 4) << 32) | *(v28 + v20);
    __asm
    {
      pcpyld       $a2, $a1
      qmtc2        $a2, $vf5
    }
    _$A1 = (*(12 * *(v18 + 1) + v20 + 4) << 32) | *(12 * *(v18 + 1) + v20);
    __asm
    {
      pcpyld       $a2, $a1
      qmtc2        $a2, $vf6
    }
    _$A1 = (*(v30 + 4) << 32) | *v30;
    __asm
    {
      pcpyld       $a2, $a1
      qmtc2        $a2, $vf7
      cop2         0x1EF8
      cfc2         $v1, $vi1, 1
      qmfc2        $a3, $vf24
    }
    v66 = _$V1;
    __asm
    {
      sq           $a3, 0x160+var_160($sp)
      sq           $a3, 0x160+var_D0($sp)
    }
    v39 = v73;
    if ( !_$V1 )
      goto LABEL_16;
    _$V0 = SLODWORD(v57);
    __asm
    {
      lqc2         $vf1, 0x10($s3)
      lqc2         $vf2, 0($s3)
      qmtc2        $v0, $vf3
      vaddax.xyz   $A, $vf2, $vf0
      vmsubax.xyz  $A, $vf2, $vf3
      vmaddx.xyz   $vf2, $vf1, $vf3
    }
    v61 = v57;
    __asm
    {
      sqc2         $vf2, 0x160+var_150($sp)
      vaddw.x      $vf4, $vf0, $vf0
    }
    LODWORD(_$V0) = 12 * *v18 + v20;
    v41 = *(_$V0 + 8);
    v42 = *(_$V0 + 4);
    v67 = *_$V0;
    v68 = v42;
    v69 = v41;
    __asm { lqc2         $vf3, 0x160+var_C0($sp) }
    LODWORD(_$V0) = 12 * *(v18 + 1) + v20;
    v43 = *(_$V0 + 8);
    v44 = *(_$V0 + 4);
    v67 = *_$V0;
    v68 = v44;
    v69 = v43;
    __asm
    {
      lqc2         $vf2, 0x160+var_C0($sp)
      vsub.xyz     $vf2, $vf2, $vf3
    }
    LODWORD(_$V0) = 12 * *(v18 + 2) + v20;
    v45 = *(_$V0 + 4);
    v46 = *(_$V0 + 8);
    v67 = *_$V0;
    v68 = v45;
    v69 = v46;
    v64 = v18;
    __asm
    {
      lqc2         $vf1, 0x160+var_C0($sp)
      vsub.xyz     $vf1, $vf1, $vf3
      vopmula      $A, $vf2, $vf1
      vopmsub      $vf2, $vf1, $vf2
      vmul.xyz     $vf1, $vf2, $vf2
    }
    v62 = v58;
    __asm
    {
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf4, $vf1
    }
    v65 = 0;
    __asm
    {
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf1.x
      vwaitq
      vmulq.xyz    $vf2, $vf2, $Q
      sqc2         $vf2, 0x160+var_140($sp)
    }
    v63 = v59;
    if ( !v70(&v60, v71) )
      break;
    v72 = 1;
    v39 = v73;
LABEL_16:
    if ( v39 )
    {
      v73 = 0;
LABEL_21:
      v47 = 0;
      v21 = 2;
      v18 = v18 + v17;
      goto LABEL_22;
    }
    if ( *(v18 + 3) == 255LL )
    {
      v73 = 0;
      goto LABEL_21;
    }
    v47 = 2;
    v73 = 1;
    v21 = 3;
LABEL_22:
    v27 = (v18 + v47);
    if ( v18 >= v22 )
      goto LABEL_23;
  }
  result = 0LL;
LABEL_24:
  __asm
  {
    lq           $s0, 0x160+var_10($sp)
    lq           $s1, 0x160+var_20($sp)
    lq           $s2, 0x160+var_30($sp)
    lq           $s3, 0x160+var_40($sp)
    lq           $s4, 0x160+var_50($sp)
    lq           $s5, 0x160+var_60($sp)
    lq           $s6, 0x160+var_70($sp)
    lq           $s7, 0x160+var_80($sp)
    lq           $fp, 0x160+var_90($sp)
  }
  return result;
}

// GtIntersection::IntersectLine(const CGtLine &, GtMathPs2::CGtV3d, const CGtAxisAlignedBox &)
__int64 __fastcall IntersectLine__14GtIntersectionRC7CGtLineGQ29GtMathPs26CGtV3dRC17CGtAxisAlignedBox(
        int a1,
        __int64 _$A1,
        int a3)
{
  __int64 v9; // $v0
  int *Chan; // $v0

  __asm
  {
    sq           $s0, 0x50+var_10($sp)
    sq           $s1, 0x50+var_20($sp)
    sq           $s2, 0x50+var_30($sp)
    por          $s0, $zero, $a1
  }
  _$S2 = a1;
  _$S1 = a3;
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code == gacGtIntsecVu0Code )
    goto LABEL_8;
  17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
  if ( gacGtIntsecVu0Code )
  {
    MEMORY[0x10008020] = 0;
    MEMORY[0x10008030] = gacGtIntsecVu0Code;
    MEMORY[0x10008000] = 325;
    v9 = 1LL;
  }
  else
  {
    v9 = 0LL;
  }
  if ( v9 )
  {
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
LABEL_8:
    __asm { lq           $v0, 0x10($s1) }
    goto LABEL_9;
  }
  __asm { lq           $v0, 0x10($s1) }
LABEL_9:
  __asm
  {
    lq           $a1, 0x10($s2)
    lq           $a0, 0($s1)
    lq           $v1, 0($s2)
    qmtc2        $v1, $vf1
    qmtc2        $a1, $vf2
    qmtc2        $s0, $vf3
    qmtc2        $v0, $vf4
    qmtc2        $a0, $vf5
    cop2         0x3878
    cfc2         $v1, $vi1, 1
    lq           $s1, 0x50+var_20($sp)
    lq           $s0, 0x50+var_10($sp)
    lq           $s2, 0x50+var_30($sp)
  }
  return _$V1;
}

// GtIntersection::IntersectSphere(GtMathPs2::CGtSphere, const CGtPolygonSoup &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *)
__int64 __fastcall IntersectSphere__14GtIntersectionGQ29GtMathPs29CGtSphereRC14CGtPolygonSoupPFRC28CGtPolygonIntersectionResultPv_bPv(
        __int64 _$A0,
        int *a2,
        __int64 (__fastcall *a3)(_QWORD, __int64),
        __int64 a4)
{
  __int64 v13; // $ra
  __int64 v16; // $v0
  bool v17; // dc
  int v18; // $fp
  unsigned __int64 v19; // $s2
  int v20; // $s3
  unsigned __int64 v21; // $s7
  __int64 v22; // $v0
  __int64 result; // $v0
  int *Chan; // $v0
  int i; // $a0
  int v31; // $v1
  int v40; // $v1
  _BYTE v58[16]; // [sp+0h] [-160h] BYREF
  int v59; // [sp+60h] [-100h]
  int v60; // [sp+64h] [-FCh]
  int v61; // [sp+68h] [-F8h]
  __int128 v62; // [sp+70h] [-F0h]
  __int16 v63; // [sp+80h] [-E0h]
  __int16 v64; // [sp+82h] [-DEh]
  __int128 v65; // [sp+90h] [-D0h] BYREF
  __int128 v66; // [sp+A0h] [-C0h] BYREF
  int v67; // [sp+B0h] [-B0h]
  __int64 v68; // [sp+C0h] [-A0h]

  __asm
  {
    sq           $s0, 0x160+var_10($sp)
    sq           $s5, 0x160+var_60($sp)
    sq           $s6, 0x160+var_70($sp)
    sq           $a0, 0x160+var_D0($sp)
    sq           $s1, 0x160+var_20($sp)
    sq           $s2, 0x160+var_30($sp)
    sq           $s3, 0x160+var_40($sp)
    sq           $s4, 0x160+var_50($sp)
    sq           $s7, 0x160+var_80($sp)
    sq           $fp, 0x160+var_90($sp)
  }
  v68 = v13;
  v67 = 0;
  v16 = 1LL;
  do
  {
    v17 = v16 != -1;
    v16 = v16 - 1;
  }
  while ( v17 );
  v18 = *(a2 + 12);
  v19 = *a2;
  v20 = a2[1];
  v21 = (v19 + v18 * *(a2 + 13));
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v22 = 1LL;
    }
    else
    {
      v22 = 0LL;
    }
    __asm { lqc2         $vf1, 0x160+var_D0($sp) }
    if ( !v22 )
      goto LABEL_11;
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
  }
  __asm { lqc2         $vf1, 0x160+var_D0($sp) }
LABEL_11:
  __asm
  {
    vmulw.w      $vf1, $vf1, $vf1
    lqc2         $vf2, 0x160+var_C0($sp)
    sqc2         $vf1, 0x160+var_F0($sp)
  }
  _$V0 = SHIDWORD(v62);
  _$V1 = SHIDWORD(v62);
  __asm
  {
    qmtc2        $v0, $vf1
    qmtc2        $v1, $vf3
    vaddx.x      $vf2, $vf0, $vf1
  }
  _$V0 = SHIDWORD(v62);
  __asm
  {
    vmove.xyzw   $vf1, $vf2
    vaddx.y      $vf1, $vf0, $vf3
    sqc2         $vf2, 0x160+var_C0($sp)
    sqc2         $vf1, 0x160+var_C0($sp)
    qmtc2        $v0, $vf3
    vaddx.z      $vf1, $vf0, $vf3
    sqc2         $vf1, 0x160+var_C0($sp)
  }
  if ( v19 >= v21 )
  {
LABEL_24:
    result = v67;
    goto LABEL_25;
  }
  _$S1 = &v65;
  _$S0 = &v66;
  for ( i = *v19; ; i = *v19 )
  {
    v31 = 12 * *(v19 + 1) + v20;
    __asm
    {
      lqc2         $vf2, 0($s1)
      lqc2         $vf3, 0($s0)
    }
    _$A4 = (*(12 * i + v20 + 4) << 32) | *(12 * i + v20);
    __asm
    {
      pcpyld       $a1, $a4
      qmtc2        $a1, $vf4
    }
    _$A4 = (*(v31 + 4) << 32) | *v31;
    __asm
    {
      pcpyld       $a1, $a4
      qmtc2        $a1, $vf5
    }
    _$A4 = (*(12 * *(v19 + 2) + v20 + 4) << 32) | *(12 * *(v19 + 2) + v20);
    __asm
    {
      pcpyld       $a1, $a4
      qmtc2        $a1, $vf6
      cop2         0x338
      cfc2         $a0, $vi1, 1
      qmfc2        $a2, $vf8
    }
    v63 = _$A0;
    if ( _$A0 )
    {
      __asm { sq           $a2, 0x160+var_150($sp) }
      v59 = v19;
      v61 = v20;
      v60 = 0;
      if ( !a3(v58, a4) )
        goto LABEL_6;
      v67 = 1;
    }
    if ( *(v19 + 3) == 255LL )
    {
      v19 = v19 + v18;
      goto LABEL_22;
    }
    v40 = 12 * *(v19 + 1) + v20;
    __asm
    {
      lqc2         $vf2, 0($s1)
      lqc2         $vf3, 0($s0)
    }
    _$A4 = (*(12 * *(v19 + 2) + v20 + 4) << 32) | *(12 * *(v19 + 2) + v20);
    __asm
    {
      pcpyld       $a1, $a4
      qmtc2        $a1, $vf4
    }
    _$A4 = (*(v40 + 4) << 32) | *v40;
    __asm
    {
      pcpyld       $a1, $a4
      qmtc2        $a1, $vf5
    }
    _$A4 = (*(12 * *(v19 + 3) + v20 + 4) << 32) | *(12 * *(v19 + 3) + v20);
    __asm
    {
      pcpyld       $a1, $a4
      qmtc2        $a1, $vf6
      cop2         0x338
      cfc2         $a0, $vi1, 1
      qmfc2        $a2, $vf8
    }
    v64 = _$A0;
    if ( _$A0 )
      break;
LABEL_21:
    v19 = v19 + v18;
LABEL_22:
    if ( v19 >= v21 )
      goto LABEL_24;
  }
  __asm { sq           $a2, 0x160+var_150($sp) }
  v59 = v19;
  v61 = v20;
  v60 = 1;
  if ( a3(v58, a4) )
  {
    v67 = 1;
    goto LABEL_21;
  }
LABEL_6:
  result = 0LL;
LABEL_25:
  __asm
  {
    lq           $s0, 0x160+var_10($sp)
    lq           $s1, 0x160+var_20($sp)
    lq           $s2, 0x160+var_30($sp)
    lq           $s3, 0x160+var_40($sp)
    lq           $s4, 0x160+var_50($sp)
    lq           $s5, 0x160+var_60($sp)
    lq           $s6, 0x160+var_70($sp)
    lq           $s7, 0x160+var_80($sp)
    lq           $fp, 0x160+var_90($sp)
  }
  return result;
}

// GtIntersection::IntersectSphere(GtMathPs2::CGtSphere, const CGtAxisAlignedBox &)
__int64 __fastcall IntersectSphere__14GtIntersectionGQ29GtMathPs29CGtSphereRC17CGtAxisAlignedBox(
        __int64 _$A0,
        int _$A1)
{
  bool v4; // dc
  __int64 result; // $v0
  __int64 v12; // $v1
  float v13[4]; // [sp+0h] [-10h] BYREF

  __asm { lqc2         $vf1, 0x10($a1) }
  v13[0] = 1.0;
  __asm { qmtc2        $a0, $vf8 }
  v13[1] = 1.0;
  __asm
  {
    vsub.xyz     $vf10, $vf8, $vf1
    vadd.xyz     $vf7, $vf0, $vf0
    lqc2         $vf1, 0($a1)
  }
  _$V0 = COERCE_INT(3.4028235e38);
  __asm
  {
    vmove.xyzw   $vf4, $vf10
    vsub.xyz     $vf9, $vf8, $vf1
  }
  v13[2] = 1.0;
  __asm
  {
    vmini.xyz    $vf1, $vf4, $vf7
    qmtc2        $v0, $vf3
    vmove.xyzw   $vf2, $vf9
    vabs.xyz     $vf1, $vf1
    lqc2         $vf6, 0x10+var_10($sp)
    vmax.xyz     $vf5, $vf2, $vf7
    vmulx.xyz    $vf1, $vf1, $vf3
    vmulx.xyz    $vf5, $vf5, $vf3
    vmini.xyz    $vf1, $vf1, $vf6
    vmul.xyz     $vf4, $vf4, $vf4
    vmini.xyz    $vf5, $vf5, $vf6
    vmul.xyz     $vf4, $vf4, $vf1
    vmul.xyz     $vf2, $vf2, $vf2
    vmove.xyzw   $vf3, $vf7
    vmul.xyz     $vf2, $vf2, $vf5
    vadd.xyz     $vf3, $vf3, $vf4
    sqc2         $vf7, 0x10+var_10($sp)
    vadd.xyz     $vf3, $vf3, $vf2
    vmulw.w      $vf2, $vf8, $vf8
    vaddy.x      $vf1, $vf3, $vf3
    sqc2         $vf2, 0x10+var_10($sp)
    vaddz.x      $vf1, $vf1, $vf3
    qmfc2        $v0, $vf1
  }
  v4 = v13[3] <= *&_$V0;
  result = 0LL;
  if ( v4 )
    return result;
  __asm
  {
    vsubw.xyz    $vf1, $vf10, $vf8
    vsub.xyzw    $vf3, $vf0, $vf0
    vaddw.w      $vf1, $vf0, $vf0
    vaddw.xyz    $vf2, $vf9, $vf8
    vsubw.w      $vf2, $vf3, $vf0
    qmfc2        $v0, $vf1
    psraw        $v1, $v0, 0x1F
    qmfc2        $a0, $vf2
    psraw        $v0, $a0, 0x1F
    sqc2         $vf3, 0x10+var_10($sp)
    pcpyud       $a0, $v1, $zero
    pcpyud       $a1, $v0, $zero
  }
  v12 = _$V1 | _$A0;
  v4 = (_$V0 & _$A1) == 0;
  result = 1LL;
  if ( v4 )
    return result;
  result = 2LL;
  if ( v12 )
    return 1LL;
  return result;
}

// GtIntersection::IntersectLineTriangle(const CGtLine &, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, float *, float *, float *)
__int64 __fastcall IntersectLineTriangle__14GtIntersectionRC7CGtLineGQ29GtMathPs26CGtV3dN22PfN25(
        int a1,
        __int64 _$A1,
        __int64 _$A2,
        __int64 _$A3,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7)
{
  __int64 v21; // $v0
  int *Chan; // $v0
  __int64 result; // $v0
  int v35; // [sp+0h] [-B0h]
  int v36; // [sp+4h] [-ACh]
  int v37; // [sp+8h] [-A8h]

  __asm
  {
    sq           $s0, 0xB0+var_10($sp)
    sq           $s1, 0xB0+var_20($sp)
    sq           $s2, 0xB0+var_30($sp)
    por          $s1, $zero, $a2
    sq           $s3, 0xB0+var_40($sp)
    por          $s2, $zero, $a1
    sq           $s4, 0xB0+var_50($sp)
  }
  _$S3 = a1;
  __asm
  {
    sq           $s5, 0xB0+var_60($sp)
    por          $s0, $zero, $a3
    sq           $s6, 0xB0+var_70($sp)
  }
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v21 = 1LL;
    }
    else
    {
      v21 = 0LL;
    }
    if ( !v21 )
    {
      __asm { lq           $v1, 0x10($s3) }
      goto LABEL_9;
    }
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
  }
  __asm { lq           $v1, 0x10($s3) }
LABEL_9:
  __asm
  {
    lq           $v0, 0($s3)
    qmtc2        $v0, $vf2, 1
    qmtc2        $v1, $vf4
    qmtc2        $s2, $vf5
    qmtc2        $s1, $vf6
    qmtc2        $s0, $vf7
    cop2         0x1EF8
    cfc2         $v0, $vi1, 1
    qmfc2        $a0, $vf24
    sq           $a0, 0xB0+var_B0($sp)
    sq           $a0, 0xB0+var_90($sp)
  }
  if ( _$V0 )
  {
    result = 1LL;
    *a5 = v35;
    *a6 = v36;
    *a7 = v37;
  }
  else
  {
    result = 0LL;
  }
  __asm
  {
    lq           $s0, 0xB0+var_10($sp)
    lq           $s1, 0xB0+var_20($sp)
    lq           $s2, 0xB0+var_30($sp)
    lq           $s3, 0xB0+var_40($sp)
    lq           $s4, 0xB0+var_50($sp)
    lq           $s5, 0xB0+var_60($sp)
    lq           $s6, 0xB0+var_70($sp)
  }
  return result;
}

// GtIntersection::IntersectFrustum(const CGtFrustum &, const CGtSimpleOrientedBox &)
__int64 __fastcall IntersectFrustum__14GtIntersectionRC10CGtFrustumRC20CGtSimpleOrientedBox(int a1, int a2)
{
  __int64 v4; // $ra
  __int64 v7; // $v0
  int *Chan; // $v0
  __int64 v35; // [sp+90h] [-30h]

  __asm
  {
    sq           $s0, 0xC0+var_10($sp)
    sq           $s1, 0xC0+var_20($sp)
  }
  _$S1 = a1;
  v35 = v4;
  _$S0 = a2;
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code == gacGtIntsecVu0Code )
    goto LABEL_8;
  17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
  if ( gacGtIntsecVu0Code )
  {
    MEMORY[0x10008020] = 0;
    MEMORY[0x10008030] = gacGtIntsecVu0Code;
    MEMORY[0x10008000] = 325;
    v7 = 1LL;
  }
  else
  {
    v7 = 0LL;
  }
  if ( v7 )
  {
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
LABEL_8:
    __asm { lq           $v0, 0($s0) }
    goto LABEL_9;
  }
  __asm { lq           $v0, 0($s0) }
LABEL_9:
  __asm
  {
    lq           $v1, 0x10($s0)
    lq           $a1, 0x30($s0)
    lq           $a2, 0x40($s0)
    lq           $a3, 0x50($s0)
    lq           $a4, 0x60($s0)
    lq           $a5, 0x70($s0)
    lq           $a0, 0x20($s0)
    sq           $v0, 0xC0+var_C0($sp)
    sq           $v1, 0xC0+var_B0($sp)
    sq           $a0, 0xC0+var_A0($sp)
    sq           $a1, 0xC0+var_90($sp)
    sq           $a2, 0xC0+var_80($sp)
    sq           $a3, 0xC0+var_70($sp)
    sq           $a4, 0xC0+var_60($sp)
    sq           $a5, 0xC0+var_50($sp)
    lq           $a4, 0x10($s1)
    lq           $a3, 0x20($s1)
    lq           $a2, 0x30($s1)
    lq           $a1, 0x40($s1)
    lq           $v1, 0x50($s1)
    lq           $v0, 0($s1)
    lqc2         $vf1, 0xC0+var_C0($sp)
    lqc2         $vf2, 0xC0+var_B0($sp)
    lqc2         $vf3, 0xC0+var_A0($sp)
    lqc2         $vf4, 0xC0+var_90($sp)
    lqc2         $vf5, 0xC0+var_80($sp)
    lqc2         $vf6, 0xC0+var_70($sp)
    lqc2         $vf7, 0xC0+var_60($sp)
    lqc2         $vf8, 0xC0+var_50($sp)
    qmtc2        $a3, $vf9
    qmtc2        $a2, $vf10
    qmtc2        $a1, $vf11
    qmtc2        $v1, $vf12
    qmtc2        $v0, $vf13
    qmtc2        $a4, $vf14
    cop2         0x4438
    cfc2         $a0, $vi1, 1
    lq           $s0, 0xC0+var_10($sp)
    lq           $s1, 0xC0+var_20($sp)
  }
  return _$A0;
}

// GtIntersection::IntersectFrustum(const CGtFrustum &, const CGtOrthogonalBox &)
__int64 __fastcall IntersectFrustum__14GtIntersectionRC10CGtFrustumRC16CGtOrthogonalBox(int a1, int a2)
{
  __int64 v6; // $v0
  int *Chan; // $v0
  __int64 result; // $v0

  __asm
  {
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
  }
  _$S1 = a1;
  _$S0 = a2;
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v6 = 1LL;
    }
    else
    {
      v6 = 0LL;
    }
    if ( v6 )
    {
      do
        Chan = sceDmaGetChan(0LL);
      while ( sceDmaSync(Chan, 1LL) );
    }
  }
  __asm
  {
    lqc2         $vf1, 0x30($s0)
    lqc2         $vf6, 0x20($s0)
    lqc2         $vf7, 0($s0)
    lqc2         $vf8, 0x10($s0)
    lqc2         $vf9, 0x20($s1)
    lqc2         $vf10, 0x30($s1)
    lqc2         $vf11, 0x40($s1)
    lqc2         $vf12, 0x50($s1)
    lqc2         $vf13, 0($s1)
    lqc2         $vf14, 0x10($s1)
    cop2         0x50F8
    cfc2         $v0, $vi1, 1
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
  }
  return result;
}

// GtIntersection::IntersectFrustum(const CGtFrustum &, const CGtExtrudedBox &)
__int64 __fastcall IntersectFrustum__14GtIntersectionRC10CGtFrustumRC14CGtExtrudedBox(int a1, int a2)
{
  __int64 v6; // $v0
  int *Chan; // $v0
  __int64 result; // $v0

  __asm
  {
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
  }
  _$S1 = a1;
  _$S0 = a2;
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v6 = 1LL;
    }
    else
    {
      v6 = 0LL;
    }
    if ( v6 )
    {
      do
        Chan = sceDmaGetChan(0LL);
      while ( sceDmaSync(Chan, 1LL) );
    }
  }
  __asm
  {
    lqc2         $vf1, 0($s0)
    lqc2         $vf2, 0x10($s0)
    lqc2         $vf3, 0x20($s0)
    lqc2         $vf4, 0x30($s0)
    lqc2         $vf9, 0x20($s1)
    lqc2         $vf10, 0x30($s1)
    lqc2         $vf11, 0x40($s1)
    lqc2         $vf12, 0x50($s1)
    lqc2         $vf13, 0($s1)
    lqc2         $vf14, 0x10($s1)
    cop2         0x52B8
    cfc2         $v0, $vi1, 1
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
  }
  return result;
}

// GtIntersection::IntersectLineNearest(const CGtLine &, const CGtPolygonSoup16 &, CGtPolygonIntersectionResult *)
__int64 __fastcall IntersectLineNearest__14GtIntersectionRC7CGtLineRC14CGtPolygonSoupP28CGtPolygonIntersectionResult(
        int a1,
        int *a2,
        int a3)
{
  __int64 v12; // $ra
  float v13; // $f20
  float v14; // $f21
  unsigned __int64 v16; // $s5
  __int64 v18; // $s7
  __int64 v19; // $fp
  float v20; // $f21
  int v21; // $s3
  float v22; // $f22
  unsigned __int64 v23; // $s0
  int v24; // $s1
  float v25; // $f20
  unsigned __int64 v26; // $s4
  __int64 v27; // $v0
  unsigned __int64 i; // $a3
  int *Chan; // $v0
  unsigned __int64 v30; // $a4
  __int64 v31; // $a6
  int v33; // $a0
  __int64 v41; // $a2
  int v42; // $a0
  int v43; // $v1
  unsigned __int64 v52; // $a4
  __int64 v53; // $a2
  int v54; // $a0
  int v55; // $v1
  unsigned __int8 *v56; // $v0
  int v57; // $a0
  __int64 result; // $v0
  float *v71; // $v0
  float v72; // $f2
  float v73; // $f0
  int v74; // $a1
  float v75; // $f2
  float v76; // $f0
  int v77; // $v0
  float *v78; // $v0
  float v79; // $f2
  float v80; // $f0
  int v81; // $a1
  float v82; // $f2
  float v83; // $f0
  float v84; // $f2
  float v85; // $f0
  float v95; // [sp+0h] [-130h]
  float v96; // [sp+4h] [-12Ch]
  float v97; // [sp+8h] [-128h]
  float v98; // [sp+70h] [-C0h] BYREF
  float v99; // [sp+74h] [-BCh]
  float v100; // [sp+78h] [-B8h]
  __int64 v101; // [sp+80h] [-B0h]
  float v111; // [sp+120h] [-10h]
  float v112; // [sp+128h] [-8h]

  __asm
  {
    sq           $s2, 0x130+var_40($sp)
    sq           $s4, 0x130+var_60($sp)
    sq           $s5, 0x130+var_70($sp)
    sq           $s6, 0x130+var_80($sp)
  }
  v16 = 0LL;
  __asm { sq           $s7, 0x130+var_90($sp) }
  _$S6 = a1;
  __asm { sq           $fp, 0x130+var_A0($sp) }
  v18 = 0LL;
  v19 = 0LL;
  v112 = v14;
  v111 = v13;
  __asm
  {
    sq           $s0, 0x130+var_20($sp)
    sq           $s1, 0x130+var_30($sp)
    sq           $s3, 0x130+var_50($sp)
  }
  v101 = v12;
  v20 = 0.0;
  v21 = *(a2 + 12);
  v22 = 0.0;
  v23 = *a2;
  v24 = a2[1];
  v25 = 1.0;
  v26 = (v23 + v21 * *(a2 + 13));
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code == gacGtIntsecVu0Code )
    goto LABEL_7;
  17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
  if ( gacGtIntsecVu0Code )
  {
    MEMORY[0x10008020] = 0;
    MEMORY[0x10008030] = gacGtIntsecVu0Code;
    MEMORY[0x10008000] = 325;
    v27 = 1LL;
  }
  else
  {
    v27 = 0LL;
  }
  i = v23;
  if ( v27 )
  {
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
LABEL_7:
    i = v23;
  }
  v30 = i;
  v31 = 0LL;
  _$V1 = 12 * *i + v24;
  v33 = 12 * *(i + 1) + v24;
  _$A1 = 12 * *(i + 2);
  __asm
  {
    ctc2         $v1, $vi0, 1
    lqc2         $vf2, 0($s6)
    lqc2         $vf4, 0x10($s6)
  }
  _$A5 = (*(_$V1 + 4) << 32) | *(12 * *i + v24);
  __asm
  {
    pcpyld       $a2, $a5
    qmtc2        $a2, $vf5
  }
  _$A5 = (*(v33 + 4) << 32) | *v33;
  __asm
  {
    pcpyld       $a2, $a5
    qmtc2        $a2, $vf6
  }
  _$A5 = (*(_$A1 + v24 + 4) << 32) | *(_$A1 + v24);
  __asm
  {
    pcpyld       $a2, $a5
    qmtc2        $a2, $vf7
    cop2         0x1EF8
    sq           $a1, 0x130+var_130($sp)
    sq           $a1, 0x130+var_110($sp)
  }
  v41 = 1LL;
  if ( *(i + 3) == 255LL )
  {
    v41 = 0LL;
    v42 = 0;
    v43 = 2;
    v23 = i + v21;
  }
  else
  {
    v42 = 2;
    v43 = 3;
  }
  if ( v23 < v26 )
  {
    for ( i = v23; ; i = v23 )
    {
      _$T4 = (*(12 * *(i + v42) + v24 + 4) << 32) | *(12 * *(i + v42) + v24);
      __asm
      {
        pcpyld       $a7, $t4
        qmtc2        $a7, $vf8
      }
      _$T4 = (*(12 * *(i + 1) + v24 + 4) << 32) | *(12 * *(i + 1) + v24);
      __asm
      {
        pcpyld       $a7, $t4
        qmtc2        $a7, $vf9
      }
      _$T4 = (*(12 * *(i + v43) + v24 + 4) << 32) | *(12 * *(i + v43) + v24);
      __asm
      {
        pcpyld       $a7, $t4
        qmtc2        $a7, $vf10
        cop2         0x2CF8
        cfc2         $v1, $vi1
        qmfc2        $a1, $vf24
      }
      v18 = 1LL;
      __asm
      {
        sq           $a1, 0x130+var_130($sp)
        sq           $a1, 0x130+var_F0($sp)
      }
      if ( _$V1 )
      {
        if ( v95 < v25 )
        {
          v22 = v96;
          v16 = v30;
          v20 = v97;
          v25 = v95;
          v19 = v31;
        }
        v31 = v41;
      }
      else
      {
        v31 = v41;
      }
      v52 = v23;
      if ( v31 || (v53 = 1LL, *(v23 + 3) == 255LL) )
      {
        v53 = 0LL;
        v54 = 0;
        v55 = 2;
        v23 = v23 + v21;
      }
      else
      {
        v54 = 2;
        v55 = 3;
      }
      v56 = (v23 + v54);
      if ( v23 >= v26 )
        break;
      i = v23;
      v57 = 12 * *(v23 + v55) + v24;
      _$T4 = (*(12 * *v56 + v24 + 4) << 32) | *(12 * *v56 + v24);
      __asm
      {
        pcpyld       $a7, $t4
        qmtc2        $a7, $vf5
      }
      _$T4 = (*(12 * *(v23 + 1) + v24 + 4) << 32) | *(12 * *(v23 + 1) + v24);
      __asm
      {
        pcpyld       $a7, $t4
        qmtc2        $a7, $vf6
      }
      _$T4 = (*(v57 + 4) << 32) | *v57;
      __asm
      {
        pcpyld       $a7, $t4
        qmtc2        $a7, $vf7
        cop2         0x1F38
        cfc2         $v1, $vi2
        qmfc2        $a1, $vf26
      }
      v18 = 0LL;
      __asm
      {
        sq           $a1, 0x130+var_130($sp)
        sq           $a1, 0x130+var_D0($sp)
      }
      if ( _$V1 && v95 < v25 )
      {
        v22 = v96;
        v16 = v52;
        v20 = v97;
        v25 = v95;
        v19 = v31;
      }
      v30 = v23;
      if ( v53 || (v41 = 1LL, *(v23 + 3) == 255LL) )
      {
        v41 = 0LL;
        v42 = 0;
        v43 = 2;
        v23 = v23 + v21;
      }
      else
      {
        v42 = 2;
        v43 = 3;
      }
      if ( v23 >= v26 )
        break;
    }
  }
  if ( v18 )
  {
    __asm
    {
      cfc2         $v0, $vi2, 1
      qmfc2        $v1, $vf8, 1
      sq           $v1, 0x130+var_130($sp)
    }
    _$V0 = _$V0;
    __asm { sq           $v1, 0x130+var_D0($sp) }
  }
  else
  {
    __asm
    {
      cfc2         $v0, $vi1, 1
      qmfc2        $v1, $vf5, 1
      sq           $v1, 0x130+var_130($sp)
      sq           $v1, 0x130+var_D0($sp)
    }
    _$V0 = _$V0;
  }
  if ( _$V0 && v95 < v25 )
  {
    v22 = v96;
    v16 = i;
    v20 = v97;
    v25 = v95;
    v19 = v31;
  }
  result = 0LL;
  if ( v16 )
  {
    _$V0 = SLODWORD(v25);
    __asm
    {
      lqc2         $vf3, 0x10($s6)
      lqc2         $vf1, 0($s6)
      qmtc2        $v0, $vf2
      vaddax.xyz   $A, $vf1, $vf0
      vmsubax.xyz  $A, $vf1, $vf2
      vmaddx.xyz   $vf1, $vf3, $vf2
      sqc2         $vf1, 0($s2)
    }
    if ( v19 )
    {
      __asm { vaddw.x      $vf4, $vf0, $vf0 }
      v78 = (12 * *(v16 + 2) + v24);
      v79 = v78[2];
      v80 = v78[1];
      v98 = *v78;
      v99 = v80;
      v100 = v79;
      __asm { lqc2         $vf2, 0x130+var_C0($sp) }
      v81 = 12 * *(v16 + 1);
      v82 = *(v81 + v24 + 8);
      v83 = *(v81 + v24 + 4);
      v98 = *(v81 + v24);
      v99 = v83;
      v100 = v82;
      v77 = *(v16 + 3);
    }
    else
    {
      __asm { vaddw.x      $vf4, $vf0, $vf0 }
      v71 = (12 * *v16 + v24);
      v72 = v71[2];
      v73 = v71[1];
      v98 = *v71;
      v99 = v73;
      v100 = v72;
      __asm { lqc2         $vf2, 0x130+var_C0($sp) }
      v74 = 12 * *(v16 + 1);
      v75 = *(v74 + v24 + 8);
      v76 = *(v74 + v24 + 4);
      v98 = *(v74 + v24);
      v99 = v76;
      v100 = v75;
      v77 = *(v16 + 2);
    }
    __asm
    {
      lqc2         $vf3, 0x130+var_C0($sp)
      vsub.xyz     $vf3, $vf3, $vf2
    }
    v84 = *(12 * v77 + v24 + 8);
    v85 = *(12 * v77 + v24 + 4);
    v98 = *(12 * v77 + v24);
    v99 = v85;
    v100 = v84;
    __asm
    {
      lqc2         $vf1, 0x130+var_C0($sp)
      vsub.xyz     $vf1, $vf1, $vf2
      vopmula      $A, $vf3, $vf1
      vopmsub      $vf3, $vf1, $vf3
      vmul.xyz     $vf2, $vf3, $vf3
      vadday.x     $A, $vf2, $vf2
      vmaddz.x     $vf2, $vf4, $vf2
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf2.x
      vwaitq
      vmulq.xyz    $vf3, $vf3, $Q
      sqc2         $vf3, 0x10($s2)
    }
    *(a3 + 88) = v20;
    result = 1LL;
    *(a3 + 80) = v25;
    *(a3 + 96) = v16;
    *(a3 + 104) = v24;
    *(a3 + 100) = v19;
    *(a3 + 84) = v22;
  }
  __asm
  {
    lq           $s0, 0x130+var_20($sp)
    lq           $s1, 0x130+var_30($sp)
    lq           $s2, 0x130+var_40($sp)
    lq           $s3, 0x130+var_50($sp)
    lq           $s4, 0x130+var_60($sp)
    lq           $s5, 0x130+var_70($sp)
    lq           $s6, 0x130+var_80($sp)
    lq           $s7, 0x130+var_90($sp)
    lq           $fp, 0x130+var_A0($sp)
  }
  return result;
}

// GtIntersection::IntersectLine(const CGtLine &, const CGtPolygonSoup16 &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *)
__int64 __fastcall IntersectLine__14GtIntersectionRC7CGtLineRC16CGtPolygonSoup16PFRC28CGtPolygonIntersectionResultPv_bPv(
        int a1,
        int *a2,
        __int64 (__fastcall *a3)(_QWORD, _QWORD),
        int a4)
{
  __int64 v13; // $ra
  __int64 v16; // $v0
  bool v17; // dc
  float v18; // $f1
  float v19; // $f0
  float v20; // $f2
  int v21; // $v1
  unsigned __int64 v24; // $s0
  __int64 v25; // $v0
  __int64 result; // $v0
  int *Chan; // $v0
  __int64 v43; // $a1
  float v46; // $f4
  float v47; // $f3
  int v48; // $a4
  int v49; // $v1
  float v50; // $f2
  int v52; // $v1
  int v54; // $f0
  int v55; // $a3
  unsigned __int16 *v57; // $a2
  int v60; // $a3
  int v61; // $a4
  float v77; // [sp+0h] [-1C0h]
  float v78; // [sp+4h] [-1BCh]
  float v79; // [sp+8h] [-1B8h]
  __int128 v80; // [sp+10h] [-1B0h] BYREF
  float v81; // [sp+60h] [-160h]
  float v82; // [sp+64h] [-15Ch]
  float v83; // [sp+68h] [-158h]
  int v84; // [sp+70h] [-150h]
  int v85; // [sp+74h] [-14Ch]
  float v86; // [sp+80h] [-140h] BYREF
  float v87; // [sp+84h] [-13Ch]
  float v88; // [sp+88h] [-138h]
  __int16 v89; // [sp+90h] [-130h]
  __int64 (__fastcall *v90)(_QWORD, _QWORD); // [sp+B0h] [-110h]
  int v91; // [sp+B4h] [-10Ch]
  int v92; // [sp+B8h] [-108h]
  int v93; // [sp+BCh] [-104h]
  int v94; // [sp+C0h] [-100h]
  int v95; // [sp+C4h] [-FCh]
  int v96; // [sp+C8h] [-F8h]
  __int64 v102; // [sp+120h] [-A0h]

  __asm
  {
    sq           $s2, 0x1C0+var_30($sp)
    sq           $s3, 0x1C0+var_40($sp)
    sq           $s5, 0x1C0+var_60($sp)
  }
  v90 = a3;
  _$S5 = a1;
  __asm
  {
    sq           $s0, 0x1C0+var_10($sp)
    sq           $s1, 0x1C0+var_20($sp)
    sq           $s4, 0x1C0+var_50($sp)
    sq           $s6, 0x1C0+var_70($sp)
    sq           $s7, 0x1C0+var_80($sp)
    sq           $fp, 0x1C0+var_90($sp)
  }
  v102 = v13;
  v91 = a4;
  v92 = 0;
  v16 = 1LL;
  do
  {
    v17 = v16 != -1;
    v16 = v16 - 1;
  }
  while ( v17 );
  v18 = *(a2 + 11);
  v19 = *(a2 + 10);
  v20 = *(a2 + 12);
  v94 = *(a2 + 13);
  v21 = *(a2 + 14);
  v86 = v19;
  v87 = v18;
  _$V0 = COERCE_INT(500.0);
  v88 = v20;
  __asm { qmtc2        $v0, $vf1 }
  v96 = 0;
  __asm { lq           $v0, 0x1C0+var_140($sp) }
  v24 = *a2;
  __asm
  {
    sq           $v0, 0x1C0+var_F0($sp)
    lqc2         $vf2, 0x1C0+var_F0($sp)
    vmulx.xyz    $vf2, $vf2, $vf1
  }
  v95 = v24 + v94 * v21;
  __asm { sqc2         $vf2, 0x1C0+var_F0($sp) }
  v93 = a2[1];
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v25 = 1LL;
    }
    else
    {
      v25 = 0LL;
    }
    __asm { lqc2         $vf2, 0x1C0+var_F0($sp) }
    if ( !v25 )
      goto LABEL_11;
    do
    {
      __asm
      {
        sqc2         $vf24, 0x1C0+var_D0($sp)
        sqc2         $vf25, 0x1C0+var_C0($sp)
        sqc2         $vf26, 0x1C0+var_B0($sp)
      }
      Chan = sceDmaGetChan(0LL);
      __asm
      {
        lqc2         $vf24, 0x1C0+var_D0($sp)
        lqc2         $vf25, 0x1C0+var_C0($sp)
        lqc2         $vf26, 0x1C0+var_B0($sp)
      }
    }
    while ( sceDmaSync(Chan, 1LL) );
  }
  __asm { lqc2         $vf2, 0x1C0+var_F0($sp) }
LABEL_11:
  __asm
  {
    lqc2         $vf1, 0x1C0+var_E0($sp)
    vadd.xyz     $vf1, $vf0, $vf2
    qmfc2        $s1, $vf1
  }
  _$V0 = COERCE_INT(0.015258789);
  __asm
  {
    qmtc2        $s1, $vf2
    qmtc2        $v0, $vf1
    vmr32.w      $vf2, $vf1
    qmfc2        $s1, $vf2
  }
  if ( v24 >= v95 )
  {
LABEL_21:
    result = v92;
    goto LABEL_22;
  }
  _$S6 = 6LL;
  while ( 1 )
  {
    __asm
    {
      madd         $v1, $s6
      madd         $a0, $s6
      madd         $v0, $s6
      ctc2         $v1, $vi0, 1
      lqc2         $vf2, 0($s5)
      lqc2         $vf4, 0x10($s5)
      qmtc2        $s1, $vf23
    }
    _$A1 = (*(_$V1 + 2) << 32) | *_$V1;
    __asm
    {
      pcpyld       $a2, $a1
      qmtc2        $a2, $vf5
    }
    _$A1 = (*(_$V0 + 2) << 32) | *_$V0;
    __asm
    {
      pcpyld       $a2, $a1
      qmtc2        $a2, $vf6
    }
    _$A1 = (*(_$A0 + 2) << 32) | *_$A0;
    __asm
    {
      pcpyld       $a2, $a1
      qmtc2        $a2, $vf7
      cop2         0x1C78
      cfc2         $v1, $vi1, 1
      qmfc2        $a3, $vf24
    }
    v89 = _$V1;
    __asm
    {
      sq           $a3, 0x1C0+var_1C0($sp)
      sq           $a3, 0x1C0+var_120($sp)
    }
    v43 = v96;
    if ( !_$V1 )
      goto LABEL_16;
    _$V0 = SLODWORD(v77);
    __asm
    {
      lqc2         $vf1, 0x10($s5)
      lqc2         $vf2, 0($s5)
      qmtc2        $v0, $vf3
      vaddax.xyz   $A, $vf2, $vf0
      vmsubax.xyz  $A, $vf2, $vf3
      vmaddx.xyz   $vf2, $vf1, $vf3
    }
    v81 = v77;
    __asm
    {
      sqc2         $vf2, 0x1C0+var_1B0($sp)
      vaddw.x      $vf9, $vf0, $vf0
    }
    _$T4 = COERCE_INT(500.0);
    v46 = *(a2 + 10);
    v47 = *(a2 + 11);
    v48 = a2[1];
    v49 = 6 * *v24;
    v50 = *(a2 + 12);
    v86 = v46;
    v87 = v47;
    _$V0 = COERCE_INT(0.000015258789);
    __asm { qmtc2        $v0, $vf6 }
    v88 = v50;
    v52 = v49 + v48;
    __asm { lqc2         $vf8, 0x1C0+var_140($sp) }
    _$A7 = COERCE_INT(*(v52 + 4));
    *&v54 = *v52;
    v55 = *(v52 + 2);
    LODWORD(_$V0) = 6 * *(v24 + 1);
    v86 = v46;
    v87 = v47;
    _$V1 = v54;
    v88 = v50;
    __asm
    {
      qmtc2        $v1, $vf1
      qmtc2        $a7, $vf4
    }
    v57 = (_$V0 + v48);
    _$V0 = COERCE_INT(v55);
    __asm
    {
      qmtc2        $v0, $vf2
      lqc2         $vf7, 0x1C0+var_140($sp)
    }
    _$A6 = COERCE_INT(v57[2]);
    __asm
    {
      vaddx.x      $vf24, $vf0, $vf1
      vaddx.y      $vf24, $vf0, $vf2
      vaddx.z      $vf24, $vf0, $vf4
      qmtc2        $a6, $vf2
    }
    v60 = 6 * *(v24 + 2) + v48;
    LODWORD(_$V0) = *v57;
    v61 = v57[1];
    v86 = v46;
    v87 = v47;
    _$V0 = COERCE_INT(_$V0);
    v88 = v50;
    _$V1 = COERCE_INT(v61);
    __asm
    {
      qmtc2        $v0, $vf1
      qmtc2        $v1, $vf5
      vaddx.x      $vf26, $vf0, $vf1
    }
    _$V0 = COERCE_INT(*v60);
    __asm { qmtc2        $v0, $vf1 }
    _$V1 = COERCE_INT(*(v60 + 2));
    __asm { qmtc2        $v1, $vf3 }
    _$V0 = COERCE_INT(*(v60 + 4));
    __asm
    {
      vaddx.x      $vf25, $vf0, $vf1
      qmtc2        $v0, $vf1
      vaddx.y      $vf25, $vf0, $vf3
      vaddx.z      $vf25, $vf0, $vf1
      vaddx.y      $vf26, $vf0, $vf5
      vaddx.z      $vf26, $vf0, $vf2
      vmulx.xyz    $vf5, $vf25, $vf6
      vmulx.xyz    $vf1, $vf24, $vf6
    }
    _$V0 = COERCE_INT(1000.0);
    __asm
    {
      qmtc2        $t4, $vf2
      qmtc2        $v0, $vf3
      lqc2         $vf4, 0x1C0+var_140($sp)
      vmulx.xyz    $vf6, $vf26, $vf6
      vmulx.xyz    $vf5, $vf5, $vf3
      vmulx.xyz    $vf4, $vf4, $vf2
      vmulx.xyz    $vf8, $vf8, $vf2
      vmulx.xyz    $vf1, $vf1, $vf3
      vmulx.xyz    $vf7, $vf7, $vf2
      vmulx.xyz    $vf6, $vf6, $vf3
      vadd.xyz     $vf1, $vf1, $vf8
      vadd.xyz     $vf6, $vf6, $vf7
      vadd.xyz     $vf5, $vf5, $vf4
      vmove.xyzw   $vf24, $vf1
      vmove.xyzw   $vf26, $vf6
      vmove.xyzw   $vf25, $vf5
      vsub.xyz     $vf3, $vf26, $vf24
      vsub.xyz     $vf2, $vf25, $vf24
      vopmula      $A, $vf3, $vf2
      vopmsub      $vf3, $vf2, $vf3
      vmul.xyz     $vf1, $vf3, $vf3
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf9, $vf1
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf1.x
      vwaitq
      vmulq.xyz    $vf3, $vf3, $Q
      sqc2         $vf3, 0x1C0+var_1A0($sp)
    }
    v84 = v24;
    __asm
    {
      sqc2         $vf24, 0x1C0+var_D0($sp)
      sqc2         $vf25, 0x1C0+var_C0($sp)
      sqc2         $vf26, 0x1C0+var_B0($sp)
    }
    v82 = v78;
    v83 = v79;
    v85 = 0;
    __asm
    {
      lqc2         $vf24, 0x1C0+var_D0($sp)
      lqc2         $vf25, 0x1C0+var_C0($sp)
      lqc2         $vf26, 0x1C0+var_B0($sp)
    }
    if ( !v90(&v80, v91) )
      break;
    v92 = 1;
    v43 = v96;
LABEL_16:
    if ( v43 || *(v24 + 3) == 255LL )
    {
      v96 = 0;
      v24 = v24 + v94;
    }
    else
    {
      v96 = 1;
    }
    if ( v24 >= v95 )
      goto LABEL_21;
  }
  result = 0LL;
LABEL_22:
  __asm
  {
    lq           $s0, 0x1C0+var_10($sp)
    lq           $s1, 0x1C0+var_20($sp)
    lq           $s2, 0x1C0+var_30($sp)
    lq           $s3, 0x1C0+var_40($sp)
    lq           $s4, 0x1C0+var_50($sp)
    lq           $s5, 0x1C0+var_60($sp)
    lq           $s6, 0x1C0+var_70($sp)
    lq           $s7, 0x1C0+var_80($sp)
    lq           $fp, 0x1C0+var_90($sp)
  }
  return result;
}

// GtIntersection::IntersectSphere(GtMathPs2::CGtSphere, const CGtPolygonSoup16 &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *)
__int64 __fastcall IntersectSphere__14GtIntersectionGQ29GtMathPs29CGtSphereRC16CGtPolygonSoup16PFRC28CGtPolygonIntersectionResultPv_bPv(
        __int64 _$A0,
        int *a2,
        __int64 (__fastcall *a3)(_QWORD, _QWORD),
        int a4)
{
  __int64 v13; // $ra
  __int64 v15; // $fp
  __int64 v16; // $v0
  bool v17; // dc
  int v18; // $s7
  unsigned __int64 v19; // $s2
  __int64 v20; // $s5
  int v21; // $s4
  unsigned __int64 v22; // $s6
  __int64 v23; // $v0
  __int64 result; // $v0
  int *Chan; // $v0
  float v29; // $f0
  float v30; // $f1
  int v36; // $a0
  int v37; // $v0
  _BYTE v58[96]; // [sp+20h] [-150h] BYREF
  int v59; // [sp+80h] [-F0h]
  int v60; // [sp+84h] [-ECh]
  int v61; // [sp+88h] [-E8h]
  float v62[3]; // [sp+90h] [-E0h] BYREF
  int v63; // [sp+9Ch] [-D4h]
  __int16 v64; // [sp+A0h] [-D0h]
  __int128 v65; // [sp+B0h] [-C0h] BYREF
  __int64 (__fastcall *v66)(_QWORD, _QWORD); // [sp+C0h] [-B0h]
  int v67; // [sp+C4h] [-ACh]
  __int64 v68; // [sp+D0h] [-A0h]

  __asm
  {
    sq           $s0, 0x170+var_10($sp)
    sq           $s1, 0x170+var_20($sp)
    sq           $fp, 0x170+var_90($sp)
    sq           $a0, 0x170+var_C0($sp)
  }
  v15 = 0LL;
  __asm
  {
    sq           $s2, 0x170+var_30($sp)
    sq           $s3, 0x170+var_40($sp)
    sq           $s4, 0x170+var_50($sp)
    sq           $s5, 0x170+var_60($sp)
    sq           $s6, 0x170+var_70($sp)
    sq           $s7, 0x170+var_80($sp)
  }
  v68 = v13;
  v66 = a3;
  v67 = a4;
  v16 = 1LL;
  do
  {
    v17 = v16 != -1;
    v16 = v16 - 1;
  }
  while ( v17 );
  v18 = *(a2 + 13);
  v19 = *a2;
  v20 = 0LL;
  v21 = a2[1];
  v22 = (v19 + v18 * *(a2 + 14));
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v23 = 1LL;
    }
    else
    {
      v23 = 0LL;
    }
    __asm { lqc2         $vf1, 0x170+var_C0($sp) }
    if ( !v23 )
      goto LABEL_11;
    do
      Chan = sceDmaGetChan(0LL);
    while ( sceDmaSync(Chan, 1LL) );
  }
  __asm { lqc2         $vf1, 0x170+var_C0($sp) }
LABEL_11:
  __asm
  {
    vmulw.w      $vf1, $vf1, $vf1
    lqc2         $vf2, 0x170+var_170($sp)
    sqc2         $vf1, 0x170+var_E0($sp)
  }
  _$V0 = v63;
  _$V1 = v63;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    qmtc2        $v1, $vf3
    vmove.xyzw   $vf1, $vf2
    vaddx.y      $vf1, $vf0, $vf3
    sqc2         $vf2, 0x170+var_170($sp)
  }
  _$V0 = v63;
  __asm
  {
    sqc2         $vf1, 0x170+var_170($sp)
    qmtc2        $v0, $vf3
  }
  v29 = *(a2 + 11);
  __asm { vaddx.z      $vf1, $vf0, $vf3 }
  v30 = *(a2 + 12);
  v62[0] = *(a2 + 10);
  __asm { sqc2         $vf1, 0x170+var_170($sp) }
  v62[1] = v29;
  v62[2] = v30;
  _$V0 = COERCE_INT(500.0);
  __asm
  {
    lqc2         $vf2, 0x170+var_E0($sp)
    qmtc2        $v0, $vf3
    lqc2         $vf1, 0x170+var_160($sp)
    vmulx.xyz    $vf2, $vf2, $vf3
    vadd.xyz     $vf1, $vf0, $vf2
  }
  _$V0 = COERCE_INT(0.015258789);
  __asm
  {
    sqc2         $vf1, 0x170+var_160($sp)
    qmtc2        $v0, $vf2
    vmr32.w      $vf1, $vf2
    sqc2         $vf1, 0x170+var_160($sp)
  }
  if ( v19 >= v22 )
  {
LABEL_25:
    result = v15;
    goto LABEL_26;
  }
  _$S1 = v58;
  _$S0 = &v65;
  while ( 1 )
  {
    if ( v20 )
    {
      __asm
      {
        lqc2         $vf2, 0($s0)
        lqc2         $vf3, 0x170+var_170($sp)
        lqc2         $vf1, 0x170+var_160($sp)
        lqc2         $vf4, 0x40($s1)
      }
      _$A0 = (*(6 * *(v19 + 3) + v21 + 2) << 32) | *(6 * *(v19 + 3) + v21);
      __asm
      {
        lqc2         $vf5, 0x30($s1)
        pcpyld       $a1, $a0
        qmtc2        $a1, $vf6
        cop2         0x38  # '8'
        cfc2         $v1, $vi1, 1
        sqc2         $vf8, 0x10($s1)
        sqc2         $vf4, 0x20($s1)
        sqc2         $vf5, 0x30($s1)
        sqc2         $vf6, 0x40($s1)
      }
    }
    else
    {
      _$A1 = 6 * *v19 + v21;
      v36 = 6 * *(v19 + 1) + v21;
      v37 = 6 * *(v19 + 2) + v21;
      __asm
      {
        ctc2         $a1, $vi0, 1
        lqc2         $vf2, 0($s0)
        lqc2         $vf3, 0x170+var_170($sp)
        lqc2         $vf1, 0x170+var_160($sp)
      }
      _$A3 = (*(_$A1 + 2) << 32) | *(6 * *v19 + v21);
      __asm
      {
        pcpyld       $a2, $a3
        qmtc2        $a2, $vf4
      }
      _$A3 = (*(v36 + 2) << 32) | *v36;
      __asm
      {
        pcpyld       $a2, $a3
        qmtc2        $a2, $vf5
      }
      _$A3 = (*(v37 + 2) << 32) | *v37;
      __asm
      {
        pcpyld       $a2, $a3
        qmtc2        $a2, $vf6
        cop2         0x178
        cfc2         $v1, $vi1, 1
        sqc2         $vf8, 0x10($s1)
        sqc2         $vf4, 0x20($s1)
        sqc2         $vf5, 0x30($s1)
        sqc2         $vf6, 0x40($s1)
      }
    }
    v64 = _$V1;
    if ( _$V1 )
    {
      v59 = v19;
      v61 = v21;
      v60 = v20;
      v15 = 1LL;
      if ( !v66(v58, v67) )
        break;
    }
    if ( *(v19 + 3) == 255LL )
    {
      v19 = v19 + v18;
LABEL_23:
      v20 = 0LL;
      goto LABEL_24;
    }
    if ( v20 )
    {
      v19 = v19 + v18;
      goto LABEL_23;
    }
    v20 = 1LL;
LABEL_24:
    if ( v19 >= v22 )
      goto LABEL_25;
  }
  result = 0LL;
LABEL_26:
  __asm
  {
    lq           $s0, 0x170+var_10($sp)
    lq           $s1, 0x170+var_20($sp)
    lq           $s2, 0x170+var_30($sp)
    lq           $s3, 0x170+var_40($sp)
    lq           $s4, 0x170+var_50($sp)
    lq           $s5, 0x170+var_60($sp)
    lq           $s6, 0x170+var_70($sp)
    lq           $s7, 0x170+var_80($sp)
    lq           $fp, 0x170+var_90($sp)
  }
  return result;
}

// GtIntersection::ClipPolyWithConvexHull(const GtMathPs2::CGtV3d *, int, const CGtConvexHull &, GtMathPs2::CGtV3d *, GtMathPs2::CGtV3d *)
__int64 __fastcall ClipPolyWithConvexHull__14GtIntersectionPCQ29GtMathPs26CGtV3diRC13CGtConvexHullPQ29GtMathPs26CGtV3dT4(
        int a1,
        __int64 a2,
        int *a3,
        int a4,
        __int64 a5)
{
  __int64 v16; // $s0
  __int64 v17; // $v0
  __int64 result; // $v0
  int *Chan; // $v0
  __int64 v21; // $a0
  int v25; // $a3
  __int64 i; // $a0

  __asm
  {
    sq           $s0, 0x80+var_10($sp)
    sq           $s1, 0x80+var_20($sp)
    sq           $s2, 0x80+var_30($sp)
    por          $s1, $zero, $zero
    sq           $s3, 0x80+var_40($sp)
    sq           $s4, 0x80+var_50($sp)
  }
  _$S3 = a1;
  __asm { sq           $s5, 0x80+var_60($sp) }
  v16 = 0LL;
  if ( 17CGtVu0CodeManager_gmpCurrentVu0Code != gacGtIntsecVu0Code )
  {
    17CGtVu0CodeManager_gmpCurrentVu0Code = gacGtIntsecVu0Code;
    if ( gacGtIntsecVu0Code )
    {
      MEMORY[0x10008020] = 0;
      MEMORY[0x10008030] = gacGtIntsecVu0Code;
      MEMORY[0x10008000] = 325;
      v17 = 1LL;
    }
    else
    {
      v17 = 0LL;
    }
    if ( v17 )
    {
      do
        Chan = sceDmaGetChan(0LL);
      while ( sceDmaSync(Chan, 1LL) );
    }
  }
  __asm
  {
    lqc2         $vf1, 0($s3)
    lqc2         $vf2, 0x10($s3)
    lqc2         $vf3, 0x20($s3)
    cop2         0x54B8
    cfc2         $zero, $vi0, 1
  }
  LODWORD(v21) = 0;
  if ( *a3 <= 0LL )
  {
LABEL_12:
    __asm { qmtc2        $s1, $vf2 }
    if ( a5 )
    {
      __asm
      {
        vwaitq
        vmulq.xyz    $vf1, $vf2, $Q
        sqc2         $vf1, 0($s4)
      }
    }
    v25 = a4;
    __asm
    {
      cop2         0x6D78
      cfc2         $zero, $vi0, 1
      sqc2         $vf1, 0($a3)
      sqc2         $vf2, 0x10($a3)
      sqc2         $vf3, 0x20($a3)
    }
    for ( i = 3LL; ; i = i + 3 )
    {
      v25 += 48;
      if ( i >= v16 - 2 )
        break;
      __asm
      {
        cop2         0x6EB8
        cfc2         $zero, $vi0, 1
        sqc2         $vf1, 0($a3)
        sqc2         $vf2, 0x10($a3)
        sqc2         $vf3, 0x20($a3)
      }
    }
    result = v16;
    if ( i < v16 )
    {
      LODWORD(i) = v16 - i;
      do
      {
        __asm
        {
          cop2         0x6FF8
          cfc2         $zero, $vi0, 1
          sqc2         $vf1, 0($a3)
        }
        i = i - 1;
        v25 += 16;
      }
      while ( i );
      result = v16;
    }
  }
  else
  {
    _$A2 = a3[1];
    while ( 1 )
    {
      __asm
      {
        lq           $v0, 0($a2)
        qmtc2        $v0, $vf1
        cop2         0x56F8
        cfc2         $v0, $vi6, 1
        qmfc2        $s1, $vf2
      }
      v16 = _$V0;
      v21 = v21 + 1;
      if ( _$V0 < 3LL )
        break;
      _$A2 += 16;
      if ( v21 >= *a3 )
        goto LABEL_12;
    }
    result = 0LL;
  }
  __asm
  {
    lq           $s0, 0x80+var_10($sp)
    lq           $s1, 0x80+var_20($sp)
    lq           $s2, 0x80+var_30($sp)
    lq           $s3, 0x80+var_40($sp)
    lq           $s4, 0x80+var_50($sp)
    lq           $s5, 0x80+var_60($sp)
  }
  return result;
}

// GtIntersection::IntersectSphere(GtMathPs2::CGtSphere, const CGtFrustum &)
__int64 __fastcall IntersectSphere__14GtIntersectionGQ29GtMathPs29CGtSphereRC10CGtFrustum(__int64 _$A0, int _$A1)
{
  __int64 v2; // $a2
  float v5; // $f0
  bool v6; // dc
  __int64 result; // $v0
  __int64 v16; // $a0
  float v17; // [sp+Ch] [-4h]

  __asm
  {
    qmtc2        $a0, $vf7
    sqc2         $vf7, 0x10+var_10($sp)
  }
  v2 = 2LL;
  __asm { vmove.xyzw   $vf4, $vf7 }
  LODWORD(_$A0) = 0;
  __asm { vaddw.x      $vf3, $vf0, $vf0 }
  _$V1 = _$A1;
  while ( 1 )
  {
    __asm
    {
      lqc2         $vf1, 0($v1)
      vmul.xyz     $vf2, $vf4, $vf1
      vadday.x     $A, $vf2, $vf2
      vmaddz.x     $vf2, $vf3, $vf2
      vsubw.x      $vf2, $vf2, $vf1
      qmfc2        $v0, $vf2
    }
    v5 = *&_$V0;
    v6 = v17 < *&_$V0;
    result = 0LL;
    if ( v6 )
      break;
    if ( -v17 < v5 )
      v2 = 1LL;
    _$A0 = _$A0 + 1;
    _$V1 += 16;
    if ( _$A0 >= 2 )
    {
      _$V0 = SLODWORD(v17);
      _$V1 = COERCE_INT(-v17);
      __asm
      {
        qmtc2        $v0, $vf1
        qmtc2        $v1, $vf2
        vmulx.w      $vf5, $vf0, $vf1
        vmulx.w      $vf6, $vf0, $vf2
        lqc2         $vf4, 0x50($a1)
        vaddw.xyz    $vf5, $vf0, $vf5
        lqc2         $vf3, 0x20($a1)
        vaddw.xyz    $vf6, $vf0, $vf6
        lqc2         $vf2, 0x30($a1)
        lqc2         $vf1, 0x40($a1)
        vmulaw.xyzw  $A, $vf4, $vf0
        vmsubax.xyzw $A, $vf3, $vf7
        vmsubay.xyzw $A, $vf2, $vf7
        vmsubaz.xyzw $A, $vf1, $vf7
        vmsubw.xyzw  $vf8, $vf6, $vf0
        vmsubw.xyzw  $vf9, $vf5, $vf0
        qmfc2        $v1, $vf8
        qmfc2        $v0, $vf9
        psraw        $v1, 0x1F
        psraw        $v0, 0x1F
        pcpyud       $a1, $v1, $zero
        pcpyud       $a0, $v0, $zero
      }
      v16 = _$V0 | _$A0;
      if ( _$V1 | _$A1 )
        return 0LL;
      result = 1LL;
      if ( !v16 )
        return v2;
      return result;
    }
  }
  return result;
}




