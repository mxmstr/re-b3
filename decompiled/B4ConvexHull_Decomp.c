/*
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

// CB4ConvexHull::Construct(void)
void __fastcall Construct__13CB4ConvexHull(B4ConvexHull *pConvexHull)
{
  pConvexHull->m_numEdges = 0;
  pConvexHull->m_numVertices = 0;
  pConvexHull->m_numPlanes = 0;
}

// CB4ConvexHull::Prepare(void)
void __fastcall Prepare__13CB4ConvexHull(B4ConvexHull *pConvexHull)
{
  pConvexHull->m_numEdges = 0;
  pConvexHull->m_numVertices = 0;
  pConvexHull->m_numPlanes = 0;
}

// CB4ConvexHull::CalculatePlaneData(int)
__int64 __fastcall CalculatePlaneData__13CB4ConvexHulli(B4ConvexHull *pConvexHull, int a2)
{
  unsigned int m_offsetVertices; // $a3
  unsigned int v5; // $v0
  int v11; // $a6
  unsigned int v12; // $a3
  unsigned int v13; // $v0
  __int64 result; // $v0

  m_offsetVertices = pConvexHull->m_offsetVertices;
  __asm { vaddw.x      $vf5, $vf0, $vf0 }
  v5 = 4 * a2 + pConvexHull->m_offsetFaces;
  __asm { vmove.xyzw   $vf6, $vf5 }
  _$A0 = 16 * *v5 + m_offsetVertices;
  _$V1 = 16 * *(v5 + 2) + m_offsetVertices;
  _$A1 = 16 * *(v5 + 3) + m_offsetVertices;
  _$A2 = 16 * *(v5 + 1) + m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0($v1)
    lqc2         $vf4, 0($a2)
    lqc2         $vf3, 0($a0)
    lqc2         $vf2, 0($a1)
    vsub.xyz     $vf3, $vf3, $vf1
    vsub.xyz     $vf2, $vf2, $vf4
    vopmula      $A, $vf2, $vf3
    vopmsub      $vf4, $vf3, $vf2
    vmul.xyz     $vf1, $vf4, $vf4
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf5, $vf1
    qmfc2        $v0, $vf1
  }
  v11 = 4 * a2;
  if ( *&_$V0 < 2.3283064e-10 )
  {
    v12 = pConvexHull->m_offsetVertices;
    v13 = v11 + pConvexHull->m_offsetFaces;
    _$V1 = 16 * *(v13 + 1) + v12;
    _$A0 = 16 * *v13 + v12;
    __asm
    {
      lqc2         $vf1, 0($v1)
      lqc2         $vf3, 0($a0)
    }
    _$A2 = 16 * *(v13 + 2) + v12;
    __asm { vadd.xyz     $vf3, $vf3, $vf1 }
    _$A1 = 16 * *(v13 + 3) + v12;
    __asm
    {
      lqc2         $vf1, 0($a2)
      vadd.xyz     $vf3, $vf3, $vf1
      lqc2         $vf2, 0($a1)
      vadd.xyz     $vf4, $vf3, $vf2
    }
  }
  __asm
  {
    vmul.xyz     $vf2, $vf4, $vf4
    vaddw.x      $vf3, $vf0, $vf0
  }
  _$V1 = 16 * a2 + pConvexHull->m_offsetPlanes;
  __asm
  {
    vadday.x     $A, $vf2, $vf2
    vmaddz.x     $vf2, $vf6, $vf2
    lqc2         $vf1, 0($v1)
    vnop
    vnop
    vnop
    vrsqrt       $Q, $vf0.w, $vf2.x
    vwaitq
    vmulq.xyz    $vf4, $vf4, $Q
    vadd.xyz     $vf1, $vf0, $vf4
    sqc2         $vf1, 0($v1)
  }
  result = v11 + pConvexHull->m_offsetFaces;
  _$A0 = _$V1;
  __asm
  {
    lqc2         $vf2, 0($a0)
    vsubw.w      $vf2, $vf0, $vf0
  }
  _$V1 = 16 * *(v11 + pConvexHull->m_offsetFaces) + pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0($v1)
    vmul.xyz     $vf1, $vf4, $vf1
    sqc2         $vf2, 0($a0)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf3, $vf1
    vaddx.w      $vf2, $vf2, $vf1
    sqc2         $vf2, 0($a0)
  }
  return result;
}

//  CB4ConvexHull::MakeBoxFromBoundingBox(GtMathPs2::CGtV3d, GtMathPs2::CGtV3d)
__int64 __fastcall MakeBoxFromBoundingBox__13CB4ConvexHullGQ29GtMathPs26CGtV3dT1(
        B4ConvexHull *pConvexHull,
        __int64 _$A1,
        __int64 _$A2)
{
  unsigned int m_offsetFaces; // $v1
  unsigned int v28; // $v0
  unsigned int v29; // $v1
  unsigned int v30; // $v0
  unsigned int v31; // $v1
  unsigned int v32; // $v0
  unsigned int m_offsetEdges; // $v1
  unsigned int v34; // $v0
  unsigned int v35; // $v1
  unsigned int v36; // $v0
  unsigned int v37; // $v1
  unsigned int v38; // $v0
  unsigned int v39; // $v1
  unsigned int v41; // $v0
  unsigned int v43; // $v1
  unsigned int v44; // $v0
  unsigned int v46; // $v1
  __int64 result; // $v0

  __asm
  {
    qmtc2        $a1, $vf3
    sq           $s0, 0x50+var_10($sp)
    qmtc2        $a2, $vf4
    sq           $s1, 0x50+var_20($sp)
    sq           $s2, 0x50+var_30($sp)
  }
  _$A1 = &kBodyFront;
  __asm
  {
    sq           $s3, 0x50+var_40($sp)
    sq           $s4, 0x50+var_50($sp)
  }
  pConvexHull->m_flags = 0;
  _$A4 = &kBodyTop;
  _$V0 = pConvexHull->m_offsetVertices;
  _$A2 = &kBodyLeft;
  __asm { lqc2         $vf1, 0($v0) }
  _$A3 = &kBodyRight;
  __asm
  {
    vaddx.x      $vf1, $vf0, $vf3
    vmove.xyzw   $vf2, $vf1
  }
  _$A5 = &kBodyBottom;
  __asm
  {
    vaddy.y      $vf2, $vf0, $vf4
    sqc2         $vf2, 0($v0)
  }
  _$A6 = &kBodyBack;
  __asm
  {
    vaddz.z      $vf2, $vf0, $vf4
    vsub.x       $vf5, $vf0, $vf3
    sqc2         $vf2, 0($v0)
    vsub.y       $vf6, $vf0, $vf3
    vsub.z       $vf7, $vf0, $vf3
    lqc2         $vf1, 0x10($v0)
    vaddx.x      $vf1, $vf0, $vf4
    vmove.xyzw   $vf2, $vf1
    vaddy.y      $vf2, $vf0, $vf4
    sqc2         $vf2, 0x10($v0)
    vaddz.z      $vf2, $vf0, $vf4
    sqc2         $vf2, 0x10($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf2, 0x20($v1)
    vaddx.x      $vf2, $vf0, $vf3
    vmove.xyzw   $vf1, $vf2
    vaddy.y      $vf1, $vf0, $vf3
    sqc2         $vf1, 0x20($v1)
    vaddz.z      $vf1, $vf0, $vf4
    sqc2         $vf1, 0x20($v1)
  }
  _$V0 = _$V1;
  __asm
  {
    lqc2         $vf1, 0x30($v0)
    vaddx.x      $vf1, $vf0, $vf4
    vmove.xyzw   $vf2, $vf1
    vaddy.y      $vf2, $vf0, $vf3
    sqc2         $vf2, 0x30($v0)
    vaddz.z      $vf2, $vf0, $vf4
    sqc2         $vf2, 0x30($v0)
    lqc2         $vf1, 0x40($v1)
    vaddx.x      $vf1, $vf0, $vf3
    vmove.xyzw   $vf2, $vf1
    vaddy.y      $vf2, $vf0, $vf4
    sqc2         $vf2, 0x40($v1)
    vaddz.z      $vf2, $vf0, $vf3
    sqc2         $vf2, 0x40($v1)
  }
  _$V0 = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x50($v0)
    vaddx.x      $vf1, $vf0, $vf4
    vmove.xyzw   $vf2, $vf1
    vaddy.y      $vf2, $vf0, $vf4
    sqc2         $vf2, 0x50($v0)
    vaddz.z      $vf2, $vf0, $vf3
    sqc2         $vf2, 0x50($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf1, 0x60($v1)
    vaddx.x      $vf1, $vf0, $vf3
    vmove.xyzw   $vf2, $vf1
    vaddy.y      $vf2, $vf0, $vf3
    sqc2         $vf2, 0x60($v1)
    vaddz.z      $vf2, $vf0, $vf3
    sqc2         $vf2, 0x60($v1)
    lqc2         $vf1, 0x70($v0)
    vaddx.x      $vf1, $vf0, $vf4
    vmove.xyzw   $vf2, $vf1
    vaddy.y      $vf2, $vf0, $vf3
    sqc2         $vf2, 0x70($v0)
    vaddz.z      $vf2, $vf0, $vf3
    sqc2         $vf2, 0x70($v0)
  }
  pConvexHull->m_numVertices = 8;
  _$V0 = pConvexHull->m_offsetPlanes;
  __asm
  {
    lqc2         $vf2, (kBodyFront - 0x1CB94B0)($a1)
    lqc2         $vf1, 0($v0)
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf2, (kBodyTop - 0x1CB94C0)($a4)
    lqc2         $vf1, 0x10($v1)
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0x10($v1)
    lqc2         $vf2, (kBodyLeft - 0x1CB94A0)($a2)
    lqc2         $vf1, 0x20($v0)
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0x20($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf2, (kBodyRight - 0x1CB9490)($a3)
    lqc2         $vf1, 0x30($v1)
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0x30($v1)
  }
  _$V0 = _$V1;
  __asm
  {
    lqc2         $vf2, (kBodyBottom - 0x1CB94D0)($a5)
    lqc2         $vf1, 0x40($v0)
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0x40($v0)
    lqc2         $vf2, (kBodyBack - 0x1CB9480)($a6)
    lqc2         $vf1, 0x50($v1)
    vadd.xyz     $vf1, $vf0, $vf2
    sqc2         $vf1, 0x50($v1)
  }
  _$V0 = pConvexHull->m_offsetPlanes;
  __asm
  {
    lqc2         $vf1, 0($v0)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0($v0)
    vaddz.w      $vf1, $vf1, $vf4
    sqc2         $vf1, 0($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf1, 0x10($v1)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0x10($v1)
    vaddy.w      $vf1, $vf1, $vf4
    sqc2         $vf1, 0x10($v1)
    lqc2         $vf1, 0x20($v0)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0x20($v0)
    vaddx.w      $vf1, $vf1, $vf5
    sqc2         $vf1, 0x20($v0)
  }
  _$V1 = _$V0;
  __asm
  {
    lqc2         $vf1, 0x30($v1)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0x30($v1)
    vaddx.w      $vf1, $vf1, $vf4
    sqc2         $vf1, 0x30($v1)
  }
  _$V0 = _$V1;
  __asm
  {
    lqc2         $vf1, 0x40($v0)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0x40($v0)
    vaddy.w      $vf1, $vf1, $vf6
    sqc2         $vf1, 0x40($v0)
    lqc2         $vf1, 0x50($v1)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0x50($v1)
    vaddz.w      $vf1, $vf1, $vf7
    sqc2         $vf1, 0x50($v1)
  }
  pConvexHull->m_numPlanes = 6;
  m_offsetFaces = pConvexHull->m_offsetFaces;
  *(pConvexHull->m_offsetFaces + 3) = 1;
  *(m_offsetFaces + 1) = 2;
  *(m_offsetFaces + 2) = 3;
  *m_offsetFaces = 0;
  v28 = pConvexHull->m_offsetFaces;
  *(pConvexHull->m_offsetFaces + 4) = 4;
  v28 += 4;
  *(v28 + 3) = 5;
  *(v28 + 2) = 1;
  *(v28 + 1) = 0;
  v29 = pConvexHull->m_offsetFaces;
  *(pConvexHull->m_offsetFaces + 8) = 4;
  v29 += 8;
  *(v29 + 1) = 6;
  *(v29 + 2) = 2;
  *(v29 + 3) = 0;
  v30 = pConvexHull->m_offsetFaces;
  *(pConvexHull->m_offsetFaces + 12) = 1;
  v30 += 12;
  *(v30 + 3) = 5;
  *(v30 + 1) = 3;
  *(v30 + 2) = 7;
  v31 = pConvexHull->m_offsetFaces;
  *(pConvexHull->m_offsetFaces + 16) = 2;
  v31 += 16;
  *(v31 + 3) = 3;
  *(v31 + 1) = 6;
  *(v31 + 2) = 7;
  v32 = pConvexHull->m_offsetFaces;
  *(pConvexHull->m_offsetFaces + 20) = 5;
  v32 += 20;
  *(v32 + 3) = 4;
  *(v32 + 1) = 7;
  *(v32 + 2) = 6;
  m_offsetEdges = pConvexHull->m_offsetEdges;
  *(m_offsetEdges + 1) = 1;
  *m_offsetEdges = 0;
  v34 = pConvexHull->m_offsetEdges;
  *(v34 + 3) = 4;
  *(v34 + 2) = 5;
  v35 = pConvexHull->m_offsetEdges;
  *(v35 + 4) = 4;
  *(v35 + 5) = 0;
  v36 = pConvexHull->m_offsetEdges;
  *(v36 + 7) = 1;
  *(v36 + 6) = 5;
  v37 = pConvexHull->m_offsetEdges;
  *(v37 + 9) = 3;
  *(v37 + 8) = 2;
  v38 = pConvexHull->m_offsetEdges;
  *(v38 + 10) = 7;
  *(v38 + 11) = 6;
  v39 = pConvexHull->m_offsetEdges;
  *(v39 + 13) = 2;
  *(v39 + 12) = 6;
  __asm { lq           $s2, 0x50+var_30($sp) }
  v41 = pConvexHull->m_offsetEdges;
  __asm { lq           $s3, 0x50+var_40($sp) }
  *(v41 + 15) = 3;
  *(v41 + 14) = 7;
  v43 = pConvexHull->m_offsetEdges;
  *(v43 + 16) = 2;
  *(v43 + 17) = 0;
  v44 = pConvexHull->m_offsetEdges;
  *(v44 + 18) = 3;
  *(v44 + 19) = 1;
  __asm { lq           $s0, 0x50+var_10($sp) }
  v46 = pConvexHull->m_offsetEdges;
  *(v46 + 21) = 4;
  *(v46 + 20) = 6;
  result = pConvexHull->m_offsetEdges;
  *(result + 23) = 5;
  *(result + 22) = 7;
  pConvexHull->m_numEdges = 12;
  __asm
  {
    lq           $s1, 0x50+var_20($sp)
    lq           $s4, 0x50+var_50($sp)
  }
  return result;
}

// CB4ConvexHull::MakeFromBoundingBox(GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, EB4HullShape)
void __fastcall MakeFromBoundingBox__13CB4ConvexHullGQ29GtMathPs26CGtV3dT112EB4HullShape(
        B4ConvexHull *pConvexHull,
        __int64 a2,
        __int64 a3,
        __int64 hullShape)
{
  if ( hullShape == 1 )
  {
    MakeConeFromBoundingBox__13CB4ConvexHullGQ29GtMathPs26CGtV3dT1();
  }
  else if ( hullShape >= 2 )
  {
    if ( hullShape == 2 )
      MakeBoatFromBoundingBox__13CB4ConvexHullGQ29GtMathPs26CGtV3dT1();
  }
  else if ( !hullShape )
  {
    MakeBoxFromBoundingBox__13CB4ConvexHullGQ29GtMathPs26CGtV3dT1(pConvexHull, a2, a3);
  }
}

// CB4ConvexHull::DeformHullVerts(GtMathPs2::CGtV3d *, GtMathPs2::CGtV3d, const GtMathPs2::CGtMatrix3x4 &, GtMathPs2::CGtMatrix3x4 *, const CB4ConvexHull *)
__int64 __fastcall DeformHullVerts__13CB4ConvexHullPQ29GtMathPs26CGtV3dGQ29GtMathPs26CGtV3dRCQ29GtMathPs212CGtMatrix3x4PQ29GtMathPs212CGtMatrix3x4PC13CB4ConvexHull(
        B4ConvexHull *pConvexHull,
        __int64 a2,
        __int64 _$A2,
        int a4,
        int a5,
        B4ConvexHull *a6)
{
  __int64 v10; // $ra
  __int64 v15; // $v0
  bool v16; // dc
  __int64 result; // $v0
  int v18; // $a2
  int v19; // $a3
  unsigned int m_offsetDeformData; // $v1
  __int64 v21; // $a1
  float *v22; // $a0
  int v23; // $a3
  float v24; // $f1
  int v25; // $a6
  int v26; // $v0
  float v28; // $f0
  __int64 v34; // $a1
  float v35; // $f1
  unsigned __int64 v36; // $a2
  unsigned int m_offsetVertices; // $a4
  unsigned __int64 m_numVertices; // $a3
  int v39; // $v0
  unsigned __int64 v44; // $a2
  int v45; // $v0
  __int128 v54; // [sp+0h] [-260h] BYREF
  _OWORD v62[21]; // [sp+B0h] [-1B0h] BYREF
  __int64 v63; // [sp+210h] [-50h]

  __asm
  {
    sq           $s0, 0x260+var_10($sp)
    sq           $s1, 0x260+var_20($sp)
    sq           $s2, 0x260+var_30($sp)
  }
  _$S1 = a4;
  __asm
  {
    sq           $s3, 0x260+var_40($sp)
    por          $s2, $zero, $a2
  }
  v63 = v10;
  v15 = 14LL;
  do
  {
    v16 = v15 != -1;
    v15 = v15 - 1;
  }
  while ( v16 );
  if ( a2 )
    __asm { sq           $s2, 0($s3) }
  if ( (pConvexHull->m_flags & 2LL) != 0 )
  {
    __asm
    {
      vsub.xyz     $vf1, $vf0, $vf0
      vsub.xyz     $vf2, $vf0, $vf0
      vsub.xyz     $vf3, $vf0, $vf0
      vsub.xyz     $vf4, $vf0, $vf0
      vaddw.x      $vf1, $vf0, $vf0
      vaddw.y      $vf2, $vf0, $vf0
      vaddw.z      $vf3, $vf0, $vf0
      sqc2         $vf1, 0x260+var_1E0($sp)
    }
    v18 = 0;
    __asm
    {
      sqc2         $vf2, 0x260+var_1D0($sp)
      sqc2         $vf3, 0x260+var_1C0($sp)
      sqc2         $vf4, 0x260+var_1B0($sp)
    }
    if ( pConvexHull->m_numVertices )
    {
      __asm { vadd.xyz     $vf10, $vf0, $vf0 }
      v19 = 0;
      do
      {
        m_offsetDeformData = pConvexHull->m_offsetDeformData;
        LODWORD(v21) = 0;
        __asm
        {
          sqc2         $vf10, 0x260+var_220($sp)
          sqc2         $vf10, 0x260+var_210($sp)
        }
        v22 = (v19 + m_offsetDeformData);
        __asm
        {
          sqc2         $vf10, 0x260+var_200($sp)
          sqc2         $vf10, 0x260+var_60($sp)
        }
        v23 = 16 * v18;
        __asm { sqc2         $vf10, 0x260+var_1F0($sp) }
        v24 = 0.0;
        v25 = 12 * v18 + m_offsetDeformData + 8;
        LOBYTE(v18) = v18 + 1;
        do
        {
          __asm { lqc2         $vf9, 0x260+var_220($sp) }
          v26 = *(v25 + v21);
          v21 = v21 + 1;
          __asm
          {
            lqc2         $vf8, 0x260+var_210($sp)
            lqc2         $vf6, 0x260+var_200($sp)
          }
          _$V0 = (v26 << 6) + a5;
          __asm
          {
            lqc2         $vf7, 0x260+var_1F0($sp)
            lqc2         $vf5, 0x30($v0)
            lqc2         $vf2, 0($v0)
            lqc2         $vf3, 0x10($v0)
            lqc2         $vf4, 0x20($v0)
            sqc2         $vf2, 0x260+var_260($sp)
            sqc2         $vf3, 0x260+var_250($sp)
            sqc2         $vf4, 0x260+var_240($sp)
            sqc2         $vf5, 0x260+var_230($sp)
          }
          v28 = *v22;
          _$V0 = *v22++;
          __asm { qmtc2        $v0, $vf1 }
          v24 = v24 + v28;
          __asm
          {
            vmulx.xyz    $vf5, $vf5, $vf1
            vmulx.xyz    $vf2, $vf2, $vf1
            vmulx.xyz    $vf3, $vf3, $vf1
            vmulx.xyz    $vf4, $vf4, $vf1
            vadd.xyz     $vf9, $vf9, $vf2
            vadd.xyz     $vf8, $vf8, $vf3
            vadd.xyz     $vf6, $vf6, $vf4
            vadd.xyz     $vf7, $vf7, $vf5
            sqc2         $vf9, 0x260+var_220($sp)
            sqc2         $vf8, 0x260+var_210($sp)
            sqc2         $vf6, 0x260+var_200($sp)
            sqc2         $vf7, 0x260+var_1F0($sp)
          }
        }
        while ( v21 < 2 );
        __asm { lqc2         $vf5, 0x260+var_1E0($sp) }
        _$V0 = COERCE_INT(1.0 - v24);
        __asm
        {
          lqc2         $vf4, 0x260+var_1D0($sp)
          qmtc2        $v0, $vf1
          lqc2         $vf2, 0x260+var_1C0($sp)
          lqc2         $vf3, 0x260+var_1B0($sp)
          vmulx.xyz    $vf5, $vf5, $vf1
          vmulx.xyz    $vf3, $vf3, $vf1
          vmulx.xyz    $vf4, $vf4, $vf1
          vmulx.xyz    $vf2, $vf2, $vf1
          vadd.xyz     $vf9, $vf9, $vf5
          vadd.xyz     $vf8, $vf8, $vf4
          vadd.xyz     $vf6, $vf6, $vf2
          vadd.xyz     $vf7, $vf7, $vf3
          sqc2         $vf9, 0x260+var_220($sp)
        }
        _$A0 = v23 + pConvexHull->m_offsetVertices;
        __asm
        {
          sqc2         $vf8, 0x260+var_210($sp)
          sqc2         $vf6, 0x260+var_200($sp)
        }
        v18 = v18;
        __asm
        {
          sqc2         $vf7, 0x260+var_1F0($sp)
          lq           $v0, 0($a0)
          sq           $v0, 0xC0($a1)
        }
        _$V1 = v23 + a6->m_offsetVertices;
        __asm
        {
          lqc2         $vf2, 0($v1)
          lqc2         $vf5, 0x260+var_220($sp)
          lqc2         $vf4, 0x260+var_210($sp)
          lqc2         $vf3, 0x260+var_200($sp)
          lqc2         $vf1, 0x260+var_1F0($sp)
          vmulax.xyz   $A, $vf5, $vf2
          vmadday.xyz  $A, $vf4, $vf2
          vmaddaz.xyz  $A, $vf3, $vf2
          vmaddw.xyz   $vf2, $vf1, $vf0
          sqc2         $vf2, 0($a0)
        }
        v19 = 12 * v18;
      }
      while ( v18 < pConvexHull->m_numVertices );
    }
    MakePlanar__13CB4ConvexHull(pConvexHull);
    result = 1LL;
    if ( a2 )
    {
      v34 = 0LL;
      v35 = 0.0;
      LODWORD(v36) = 0;
      if ( pConvexHull->m_numVertices )
      {
        m_offsetVertices = pConvexHull->m_offsetVertices;
        __asm { qmtc2        $s2, $vf8 }
        m_numVertices = pConvexHull->m_numVertices;
        __asm { vaddw.x      $vf7, $vf0, $vf0 }
        v39 = 0;
        do
        {
          _$V1 = v39 + m_offsetVertices;
          _$V0 = &v54 + v39;
          __asm
          {
            lqc2         $vf2, 0($v1)
            lqc2         $vf6, 0xC0($v0)
            vsub.xyz     $vf1, $vf2, $vf6
            vmul.xyz     $vf1, $vf1, $vf1
            vadday.x     $A, $vf1, $vf1
            vmaddz.x     $vf1, $vf7, $vf1
            qmfc2        $v0, $vf1
          }
          if ( *&_$V0 <= 0.0000010000001 )
          {
            *(&v62[17] + v36) = 0;
          }
          else
          {
            __asm
            {
              lqc2         $vf5, 0($s1)
              lqc2         $vf4, 0x10($s1)
              lqc2         $vf3, 0x20($s1)
            }
            v34 = v34 + 1;
            __asm
            {
              lqc2         $vf2, 0x30($s1)
              vmulax.xyz   $A, $vf5, $vf6
              vmadday.xyz  $A, $vf4, $vf6
              vmaddaz.xyz  $A, $vf3, $vf6
              vmaddw.xyz   $vf1, $vf2, $vf0
              vsub.xyz     $vf1, $vf1, $vf8
              vmul.xyz     $vf1, $vf1, $vf1
              vadday.x     $A, $vf1, $vf1
              vmaddz.x     $vf1, $vf7, $vf1
              vnop
              vnop
              vnop
              vsqrt        $Q, $vf1.x
              vaddw.x      $vf1, $vf0, $vf0
              vwaitq
              vmulq.x      $vf1, $vf1, $Q
              qmfc2        $v0, $vf1
            }
            *(&v62[17] + v36) = _$V0;
            v35 = v35 + *&_$V0;
          }
          v36 = (v36 + 1);
          v39 = 16 * v36;
        }
        while ( v36 < m_numVertices );
      }
      result = 1LL;
      if ( v34 >= 2 )
      {
        __asm
        {
          vadd.xyz     $vf1, $vf0, $vf0
          vmove.xyzw   $vf5, $vf1
        }
        LODWORD(v44) = 0;
        __asm { sqc2         $vf1, 0x260+var_60($sp) }
        if ( pConvexHull->m_numVertices )
        {
          __asm { vaddw.x      $vf4, $vf0, $vf0 }
          v45 = 0;
          do
          {
            _$V1 = v45 + pConvexHull->m_offsetVertices;
            _$V0 = &v54 + v45;
            __asm
            {
              lqc2         $vf3, 0($v1)
              lqc2         $vf2, 0xC0($v0)
              vsub.xyz     $vf1, $vf3, $vf2
              vmul.xyz     $vf1, $vf1, $vf1
              vadday.x     $A, $vf1, $vf1
              vmaddz.x     $vf1, $vf4, $vf1
              qmfc2        $v0, $vf1
            }
            if ( *&_$V0 > 0.0000010000001 )
            {
              _$V0 = COERCE_INT((v35 - *(&v62[17] + v44)) / (v35 * (v34 - 1)));
              __asm
              {
                qmtc2        $v0, $vf1
                vmulx.xyz    $vf1, $vf3, $vf1
                vadd.xyz     $vf5, $vf5, $vf1
              }
            }
            v44 = (v44 + 1);
            v45 = 16 * v44;
          }
          while ( v44 < pConvexHull->m_numVertices );
        }
        __asm
        {
          lqc2         $vf4, 0x30($s1)
          lqc2         $vf1, 0($s1)
          lqc2         $vf3, 0x10($s1)
          lqc2         $vf2, 0x20($s1)
          vmulax.xyz   $A, $vf1, $vf5
          vmadday.xyz  $A, $vf3, $vf5
          vmaddaz.xyz  $A, $vf2, $vf5
          vmaddw.xyz   $vf1, $vf4, $vf0
          sqc2         $vf1, 0($s3)
        }
        result = 1LL;
      }
    }
  }
  else
  {
    result = 0LL;
  }
  __asm
  {
    lq           $s0, 0x260+var_10($sp)
    lq           $s1, 0x260+var_20($sp)
    lq           $s2, 0x260+var_30($sp)
    lq           $s3, 0x260+var_40($sp)
  }
  return result;
}

// CB4ConvexHull::MakePlanar(void)
__int64 __fastcall MakePlanar__13CB4ConvexHull(B4ConvexHull *pConvexHull)
{
  __int64 result; // $v0
  int v150; // $a1
  float v153; // [sp+4h] [-3Ch]
  float v154; // [sp+8h] [-38h]

  __asm
  {
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
  }
  LOBYTE(_$S1) = 0;
  _$A0 = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf2, 0($a0)
    lqc2         $vf1, 0x20($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { min          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x20($v0)
    lqc2         $vf2, 0($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x20($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x20($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x20($v0)
    lqc2         $vf2, 0($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x20($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lqc2         $vf2, 0x40($a0)
    lqc2         $vf1, 0x60($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { min          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0x40($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x60($v0)
    lqc2         $vf2, 0x40($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x60($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x40($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x60($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0x40($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x40($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x60($v0)
    lqc2         $vf2, 0x40($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x60($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lqc2         $vf2, 0x80($a0)
    lqc2         $vf1, 0xA0($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { min          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0x80($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xA0($v0)
    lqc2         $vf2, 0x80($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xA0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x80($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0xA0($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0x80($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x80($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xA0($v0)
    lqc2         $vf2, 0x80($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xA0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lqc2         $vf2, 0xC0($a0)
    lqc2         $vf1, 0xE0($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { min          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0xC0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf2, 0xC0($v0)
    lqc2         $vf1, 0xE0($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xE0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0xC0($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0xE0($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0xC0($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xC0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xE0($v0)
    lqc2         $vf2, 0xC0($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xE0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lqc2         $vf2, 0x10($a0)
    lqc2         $vf1, 0x30($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { max          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0x10($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x30($v0)
    lqc2         $vf2, 0x10($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x30($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x10($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x30($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0x10($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x10($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf2, 0x10($v0)
    lqc2         $vf1, 0x30($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x30($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lqc2         $vf2, 0x50($a0)
    lqc2         $vf1, 0x70($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { max          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0x50($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x70($v0)
    lqc2         $vf2, 0x50($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x70($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x50($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x70($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0x50($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x50($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x70($v0)
    lqc2         $vf2, 0x50($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x70($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lqc2         $vf2, 0x90($a0)
    lqc2         $vf1, 0xB0($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { max          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0x90($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xB0($v0)
    lqc2         $vf2, 0x90($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xB0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x90($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0xB0($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0x90($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x90($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xB0($v0)
    lqc2         $vf2, 0x90($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xB0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lqc2         $vf2, 0xD0($a0)
    lqc2         $vf1, 0xF0($a0)
    qmfc2        $v0, $vf2
    qmfc2        $v1, $vf1
  }
  _$F1 = *&_$V1;
  __asm { max          $f0, $f1 }
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vaddx.x      $vf2, $vf0, $vf1
    sqc2         $vf2, 0xD0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xF0($v0)
    lqc2         $vf2, 0xD0($v0)
    vaddx.x      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xF0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0xD0($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0xF0($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v154;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0xD0($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xD0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xF0($v0)
    lqc2         $vf2, 0xD0($v0)
    vaddz.z      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xF0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x10($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x10($v0)
    lqc2         $vf2, 0($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x10($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x40($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x50($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0x40($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x40($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x50($v0)
    lqc2         $vf2, 0x40($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x50($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x80($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x90($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0x80($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x80($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf2, 0x80($v0)
    lqc2         $vf1, 0x90($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x90($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0xC0($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0xD0($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    max          $f1, $f0
    lqc2         $vf1, 0xC0($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xC0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xD0($v0)
    lqc2         $vf2, 0xC0($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xD0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x20($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x30($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0x20($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x20($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0x30($v0)
    lqc2         $vf2, 0x20($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x30($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0x60($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0x70($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0x60($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x60($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf2, 0x60($v0)
    lqc2         $vf1, 0x70($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0x70($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0xA0($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0xB0($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0xA0($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xA0($a0)
  }
  LODWORD(_$V0) = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xB0($v0)
    lqc2         $vf2, 0xA0($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xB0($v0)
  }
  _$A0 = _$V0;
  __asm
  {
    lq           $v0, 0xE0($a0)
    sq           $v0, 0x40+var_40($sp)
    lq           $v1, 0xF0($a0)
    sq           $v1, 0x40+var_40($sp)
  }
  _$F0 = v153;
  __asm
  {
    min          $f1, $f0
    lqc2         $vf1, 0xE0($a0)
  }
  _$V0 = _$F1;
  __asm
  {
    qmtc2        $v0, $vf2
    vaddx.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xE0($a0)
  }
  result = pConvexHull->m_offsetVertices;
  __asm
  {
    lqc2         $vf1, 0xF0($v0)
    lqc2         $vf2, 0xE0($v0)
    vaddy.y      $vf1, $vf0, $vf2
    sqc2         $vf1, 0xF0($v0)
  }
  if ( pConvexHull->m_numPlanes )
  {
    v150 = 0;
    do
    {
      CalculatePlaneData__13CB4ConvexHulli(pConvexHull, v150);
      _$S1 = (_$S1 + 1);
      result = _$S1 < pConvexHull->m_numPlanes;
      v150 = _$S1;
    }
    while ( _$S1 < pConvexHull->m_numPlanes );
    __asm { lq           $s0, 0x40+var_10($sp) }
  }
  else
  {
    __asm { lq           $s0, 0x40+var_10($sp) }
  }
  __asm { lq           $s1, 0x40+var_20($sp) }
  return result;
}

// CB4ConvexHull::DebugRenderEdges(const GtMathPs2::CGtMatrix3x4 &, bool) const
__int64 __fastcall DebugRenderEdges__C13CB4ConvexHullRCQ29GtMathPs212CGtMatrix3x4b(
        B4ConvexHull *pConvexHull,
        int a2,
        __int64 a3)
{
  __int64 v12; // $ra
  char *v16; // $a0
  __int64 v17; // $v0
  bool v18; // dc
  __int64 m_numVertices; // $a1
  __int64 v23; // $v0
  float v27; // $f4
  float v29; // $f5
  __int64 result; // $v0
  unsigned __int64 v42; // $s2
  unsigned int i; // $a3
  unsigned __int8 *v44; // $a3
  float v50; // $f12
  float v51; // $f14
  float v54; // $f12
  float v55; // $f14
  __int128 v67; // [sp+0h] [-320h] BYREF
  char v68; // [sp+40h] [-2E0h] BYREF
  __int128 v69; // [sp+140h] [-1E0h] BYREF
  float v71; // [sp+160h] [-1C0h] BYREF
  float v72; // [sp+164h] [-1BCh]
  float v73; // [sp+168h] [-1B8h]
  float v74; // [sp+16Ch] [-1B4h]
  float v79; // [sp+274h] [-ACh]
  float v80; // [sp+278h] [-A8h]
  float v81; // [sp+27Ch] [-A4h]
  __int64 v82; // [sp+280h] [-A0h]

  _$A6 = a2;
  __asm
  {
    sq           $s3, 0x320+var_40($sp)
    sq           $fp, 0x320+var_90($sp)
    sq           $s0, 0x320+var_10($sp)
    sq           $s1, 0x320+var_20($sp)
    sq           $s2, 0x320+var_30($sp)
  }
  v16 = &v68;
  __asm
  {
    sq           $s4, 0x320+var_50($sp)
    sq           $s5, 0x320+var_60($sp)
    vaddw.x      $vf11, $vf0, $vf0
    sq           $s6, 0x320+var_70($sp)
    sq           $s7, 0x320+var_80($sp)
  }
  v82 = v12;
  v17 = 14LL;
  do
  {
    v18 = v17 != -1;
    v17 = v17 - 1;
  }
  while ( v18 );
  v71 = 0.0;
  v72 = 1.0;
  v73 = 0.0;
  v74 = 1.0;
  __asm { lq           $s7, 0x320+var_1C0($sp) }
  m_numVertices = pConvexHull->m_numVertices;
  v71 = 1.0;
  v72 = 1.0;
  v73 = 0.0;
  v74 = 1.0;
  __asm { lq           $s5, 0x320+var_1C0($sp) }
  _$V1 = pConvexHull->m_offsetVertices;
  if ( m_numVertices )
  {
    __asm
    {
      lqc2         $vf5, 0($a6)
      lqc2         $vf4, 0x10($a6)
    }
    LODWORD(v23) = m_numVertices;
    __asm
    {
      lqc2         $vf3, 0x20($a6)
      lqc2         $vf2, 0x30($a6)
    }
    do
    {
      __asm { lqc2         $vf1, 0($v1) }
      v23 = v23 - 1;
      __asm
      {
        vmulax.xyz   $A, $vf5, $vf1
        vmadday.xyz  $A, $vf4, $vf1
        vmaddaz.xyz  $A, $vf3, $vf1
        vmaddw.xyz   $vf1, $vf2, $vf0
      }
      _$V1 += 16;
      __asm { sqc2         $vf1, 0($a0) }
      v16 += 16;
    }
    while ( v23 );
  }
  _$V0 = COERCE_INT(1.4142135);
  __asm { qmtc2        $v0, $vf2 }
  _$A3 = *(gGraphicsManager.unknown_09 + 104);
  __asm
  {
    lqc2         $vf5, 0x320+var_F0($sp)
    lqc2         $vf1, 0x10($a3)
    vmulx.xyzw   $vf1, $vf1, $vf2
    lqc2         $vf10, 0x320+var_E0($sp)
    vmuly.y      $vf2, $vf1, $vf1
    vmulz.y      $vf3, $vf1, $vf1
    sqc2         $vf2, 0x320+var_B0($sp)
    vmulz.z      $vf4, $vf1, $vf1
    vmulx.w      $vf6, $vf1, $vf1
    vmuly.w      $vf7, $vf1, $vf1
    vmulx.x      $vf2, $vf1, $vf1
    vmulz.w      $vf8, $vf1, $vf1
    qmfc2        $v0, $vf2
    sqc2         $vf3, 0x320+var_B0($sp)
    vmuly.x      $vf3, $vf1, $vf1
  }
  v27 = 1.0 - *&_$V0;
  __asm
  {
    vmulz.x      $vf1, $vf1, $vf1
    qmfc2        $v0, $vf1
    sqc2         $vf4, 0x320+var_B0($sp)
  }
  v29 = *&_$V0;
  __asm
  {
    qmfc2        $v1, $vf3
    lqc2         $vf2, 0x320+var_D0($sp)
    sqc2         $vf6, 0x320+var_B0($sp)
  }
  _$V0 = COERCE_INT((1.0 - v79) - v80);
  __asm
  {
    sqc2         $vf7, 0x320+var_B0($sp)
    qmtc2        $v0, $vf4
    vaddx.x      $vf5, $vf0, $vf4
  }
  _$A2 = COERCE_INT(v27 - v80);
  __asm { vmove.xyzw   $vf7, $vf5 }
  _$A1 = COERCE_INT(v79 - v81);
  __asm { sqc2         $vf8, 0x320+var_B0($sp) }
  _$V0 = COERCE_INT(v29 + v81);
  __asm
  {
    qmtc2        $v0, $vf3
    vaddx.x      $vf2, $vf0, $vf3
    sqc2         $vf5, 0x320+var_F0($sp)
    qmtc2        $a2, $vf3
  }
  _$V0 = COERCE_INT(*&_$V1 - v81);
  __asm { qmtc2        $v0, $vf1 }
  _$V1 = COERCE_INT(*&_$V1 + v81);
  __asm
  {
    vaddx.x      $vf10, $vf0, $vf1
    qmtc2        $v1, $vf4
    vmove.xyzw   $vf8, $vf10
    vaddx.y      $vf7, $vf0, $vf4
    vaddx.y      $vf8, $vf0, $vf3
  }
  _$A0 = COERCE_INT(v29 - v81);
  __asm { qmtc2        $a1, $vf1 }
  _$V0 = COERCE_INT(v27 - v79);
  __asm
  {
    vmove.xyzw   $vf9, $vf2
    qmtc2        $a0, $vf3
    vmove.xyzw   $vf5, $vf7
    vaddx.y      $vf9, $vf0, $vf1
    vaddx.z      $vf5, $vf0, $vf3
    qmtc2        $v0, $vf6
  }
  _$V1 = COERCE_INT(v79 + v81);
  __asm
  {
    sqc2         $vf2, 0x320+var_D0($sp)
    lq           $v0, 0x320+var_C0($sp)
    qmtc2        $v1, $vf1
    sqc2         $vf10, 0x320+var_E0($sp)
    vmove.xyzw   $vf4, $vf8
    sq           $v0, 0x320+var_100($sp)
    vmove.xyzw   $vf3, $vf9
    vaddx.z      $vf4, $vf0, $vf1
    vaddx.z      $vf3, $vf0, $vf6
    sqc2         $vf7, 0x320+var_F0($sp)
    sqc2         $vf8, 0x320+var_E0($sp)
    sqc2         $vf9, 0x320+var_D0($sp)
    sqc2         $vf5, 0x320+var_F0($sp)
    sqc2         $vf4, 0x320+var_E0($sp)
    sqc2         $vf3, 0x320+var_D0($sp)
    sqc2         $vf5, 0x320+var_130($sp)
    sqc2         $vf4, 0x320+var_120($sp)
    sqc2         $vf3, 0x320+var_110($sp)
    sqc2         $vf5, 0x320+var_170($sp)
    sqc2         $vf4, 0x320+var_160($sp)
    sqc2         $vf3, 0x320+var_150($sp)
    sq           $v0, 0x320+var_140($sp)
    lqc2         $vf1, 0x30($a6)
    lqc2         $vf2, 0x20($a3)
    vsub.xyz     $vf1, $vf1, $vf2
    sqc2         $vf5, 0x320+var_320($sp)
    vmul.xyz     $vf1, $vf1, $vf1
    sqc2         $vf4, 0x320+var_310($sp)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf11, $vf1
    sqc2         $vf3, 0x320+var_300($sp)
    qmfc2        $v0, $vf1
    sqc2         $vf2, 0x320+var_140($sp)
    sqc2         $vf5, 0x320+var_1B0($sp)
    sqc2         $vf4, 0x320+var_1A0($sp)
    sqc2         $vf3, 0x320+var_190($sp)
    sqc2         $vf2, 0x320+var_180($sp)
    sqc2         $vf2, 0x320+var_2F0($sp)
  }
  if ( *&result < 2500.0 )
  {
    result = pConvexHull->m_numEdges;
    LODWORD(v42) = 0;
    if ( pConvexHull->m_numEdges )
    {
      for ( i = pConvexHull->m_offsetEdges; ; i = pConvexHull->m_offsetEdges )
      {
        v44 = (2 * v42 + i);
        __asm { por          $a2, $zero, $s7 }
        _$V1 = &v67 + *v44;
        __asm
        {
          lq           $v0, 0x40($v1)
          sq           $v0, 0x320+var_1E0($sp)
        }
        _$V1 = &v67 + v44[1];
        __asm
        {
          lq           $v0, 0x40($v1)
          sq           $v0, 0x320+var_1D0($sp)
        }
        DrawLine__15CB4DebugManagerRC7CGtLineGQ29GtMathPs26CGtV4d(&gDebugManager, &v69, _$A2);
        if ( a3 )
        {
          sprintf(&v71, &unk_4A7D10, v50, v51);
          __asm
          {
            lq           $a2, 0x320+var_1E0($sp)
            por          $a4, $zero, $s5
          }
          DrawVectorText__15CB4DebugManagerPCcGQ29GtMathPs26CGtV3dPQ29GtMathPs212CGtMatrix3x4fGQ29GtMathPs26CGtV4d(
            &gDebugManager,
            &v71,
            _$A2,
            &v67,
            _$A4,
            COERCE_INT(0.1));
          sprintf(&v71, &unk_4A7D10, v54, v55);
          __asm
          {
            lq           $a2, 0x320+var_1D0($sp)
            por          $a4, $zero, $s5
          }
          DrawVectorText__15CB4DebugManagerPCcGQ29GtMathPs26CGtV3dPQ29GtMathPs212CGtMatrix3x4fGQ29GtMathPs26CGtV4d(
            &gDebugManager,
            &v71,
            _$A2,
            &v67,
            _$A4,
            COERCE_INT(0.1));
        }
        v42 = v42 + 1;
        result = v42 < pConvexHull->m_numEdges;
        if ( v42 >= pConvexHull->m_numEdges )
          break;
      }
    }
  }
  __asm
  {
    lq           $s0, 0x320+var_10($sp)
    lq           $s1, 0x320+var_20($sp)
    lq           $s2, 0x320+var_30($sp)
    lq           $s3, 0x320+var_40($sp)
    lq           $s4, 0x320+var_50($sp)
    lq           $s5, 0x320+var_60($sp)
    lq           $s6, 0x320+var_70($sp)
    lq           $s7, 0x320+var_80($sp)
    lq           $fp, 0x320+var_90($sp)
  }
  return result;
}

// CB4ConvexHull::DebugRenderPlanes(const GtMathPs2::CGtMatrix3x4 &, const GtMathPs2::CGtPlane *, const GtMathPs2::CGtV3d *, bool)
__int64 __fastcall DebugRenderPlanes__13CB4ConvexHullRCQ29GtMathPs212CGtMatrix3x4PCQ29GtMathPs28CGtPlanePCQ29GtMathPs26CGtV3db(
        B4ConvexHull *pConvexHull,
        int a2,
        int a3,
        int a4,
        int a5)
{
  __int64 v14; // $ra
  float v15; // $f20
  float v16; // $f21
  __int64 v20; // $v0
  bool v21; // dc
  float v26; // $f5
  float v28; // $f4
  __int64 result; // $v0
  int v41; // $s0
  int v42; // $f21
  int v43; // $v1
  unsigned __int8 v44; // $s4
  __int64 v47; // $a0
  int v48; // $v0
  __int128 *v52; // $v1
  __int64 v54; // $a0
  float v58; // $f12
  float v59; // $f14
  __int128 v72; // [sp+0h] [-270h] BYREF
  __int128 v74; // [sp+20h] [-250h] BYREF
  float v75; // [sp+40h] [-230h] BYREF
  float v76; // [sp+44h] [-22Ch]
  float v77; // [sp+48h] [-228h]
  float v78; // [sp+4Ch] [-224h]
  __int128 v79; // [sp+50h] [-220h] BYREF
  float v84; // [sp+194h] [-DCh]
  float v85; // [sp+198h] [-D8h]
  float v86; // [sp+19Ch] [-D4h]
  int v87; // [sp+1A0h] [-D0h]
  int v88; // [sp+1A4h] [-CCh]
  __int64 v90; // [sp+1C0h] [-B0h]
  float v100; // [sp+260h] [-10h]
  float v101; // [sp+268h] [-8h]

  __asm
  {
    sq           $s5, 0x270+var_70($sp)
    vaddw.x      $vf11, $vf0, $vf0
    sq           $s3, 0x270+var_50($sp)
    sq           $s7, 0x270+var_90($sp)
  }
  _$S3 = a2;
  v88 = a5;
  __asm
  {
    sq           $s0, 0x270+var_20($sp)
    sq           $s1, 0x270+var_30($sp)
    sq           $s2, 0x270+var_40($sp)
    sq           $s4, 0x270+var_60($sp)
    sq           $s6, 0x270+var_80($sp)
    sq           $fp, 0x270+var_A0($sp)
  }
  v90 = v14;
  v101 = v16;
  v100 = v15;
  v87 = a3;
  v20 = 0LL;
  do
  {
    v21 = v20 != -1;
    v20 = v20 - 1;
  }
  while ( v21 );
  v75 = 1.0;
  v76 = 0.0;
  v77 = 0.0;
  v78 = 1.0;
  _$V0 = COERCE_INT(1.4142135);
  __asm { qmtc2        $v0, $vf2 }
  _$A3 = *(gGraphicsManager.unknown_09 + 104);
  __asm
  {
    lq           $fp, 0x270+var_230($sp)
    lqc2         $vf1, 0x10($a3)
    vmulx.xyzw   $vf1, $vf1, $vf2
    lqc2         $vf5, 0x270+var_120($sp)
    vmuly.y      $vf2, $vf1, $vf1
    vmulz.y      $vf3, $vf1, $vf1
    sqc2         $vf2, 0x270+var_E0($sp)
    vmulz.z      $vf4, $vf1, $vf1
    vmulx.w      $vf6, $vf1, $vf1
    vmuly.w      $vf7, $vf1, $vf1
    vmulx.x      $vf2, $vf1, $vf1
    vmulz.w      $vf8, $vf1, $vf1
    qmfc2        $v0, $vf2
    sqc2         $vf3, 0x270+var_E0($sp)
    vmuly.x      $vf3, $vf1, $vf1
  }
  v26 = 1.0 - *&_$V0;
  __asm
  {
    vmulz.x      $vf1, $vf1, $vf1
    qmfc2        $v0, $vf1
    sqc2         $vf4, 0x270+var_E0($sp)
  }
  v28 = *&_$V0;
  __asm
  {
    qmfc2        $v1, $vf3
    lqc2         $vf10, 0x270+var_110($sp)
    lqc2         $vf2, 0x270+var_100($sp)
    sqc2         $vf6, 0x270+var_E0($sp)
  }
  _$V0 = COERCE_INT((1.0 - v84) - v85);
  __asm
  {
    sqc2         $vf7, 0x270+var_E0($sp)
    qmtc2        $v0, $vf4
    vaddx.x      $vf5, $vf0, $vf4
  }
  _$A2 = COERCE_INT(v26 - v85);
  __asm { vmove.xyzw   $vf7, $vf5 }
  _$A1 = COERCE_INT(v84 - v86);
  __asm { sqc2         $vf8, 0x270+var_E0($sp) }
  _$V0 = COERCE_INT(v28 + v86);
  __asm
  {
    qmtc2        $v0, $vf3
    vaddx.x      $vf2, $vf0, $vf3
    sqc2         $vf5, 0x270+var_120($sp)
    qmtc2        $a2, $vf3
  }
  _$V0 = COERCE_INT(*&_$V1 - v86);
  __asm { qmtc2        $v0, $vf1 }
  _$V1 = COERCE_INT(*&_$V1 + v86);
  __asm
  {
    vaddx.x      $vf10, $vf0, $vf1
    qmtc2        $v1, $vf4
    vmove.xyzw   $vf8, $vf10
    vaddx.y      $vf7, $vf0, $vf4
    vaddx.y      $vf8, $vf0, $vf3
  }
  _$A0 = COERCE_INT(v28 - v86);
  __asm
  {
    qmtc2        $a1, $vf1
    vmove.xyzw   $vf9, $vf2
    qmtc2        $a0, $vf3
    vmove.xyzw   $vf5, $vf7
    vaddx.z      $vf5, $vf0, $vf3
    vaddx.y      $vf9, $vf0, $vf1
  }
  _$V0 = COERCE_INT(v26 - v84);
  _$V1 = COERCE_INT(v84 + v86);
  __asm
  {
    sqc2         $vf2, 0x270+var_100($sp)
    qmtc2        $v1, $vf1
    sqc2         $vf10, 0x270+var_110($sp)
    qmtc2        $v0, $vf6
    vmove.xyzw   $vf3, $vf8
    vmove.xyzw   $vf4, $vf9
    vaddx.z      $vf3, $vf0, $vf1
    vaddx.z      $vf4, $vf0, $vf6
    sqc2         $vf7, 0x270+var_120($sp)
    sqc2         $vf8, 0x270+var_110($sp)
    sqc2         $vf9, 0x270+var_100($sp)
    sqc2         $vf5, 0x270+var_120($sp)
    sqc2         $vf3, 0x270+var_110($sp)
    sqc2         $vf4, 0x270+var_100($sp)
    sqc2         $vf5, 0x270+var_160($sp)
    sqc2         $vf3, 0x270+var_150($sp)
    lq           $v0, 0x270+var_F0($sp)
    sqc2         $vf4, 0x270+var_140($sp)
    sqc2         $vf5, 0x270+var_1A0($sp)
    sqc2         $vf3, 0x270+var_190($sp)
    sqc2         $vf4, 0x270+var_180($sp)
    sq           $v0, 0x270+var_170($sp)
    sq           $v0, 0x270+var_130($sp)
    lqc2         $vf1, 0x30($s3)
    lqc2         $vf2, 0x20($a3)
    vsub.xyz     $vf1, $vf1, $vf2
    sqc2         $vf5, 0x270+var_220($sp)
    vmul.xyz     $vf1, $vf1, $vf1
    sqc2         $vf3, 0x270+var_210($sp)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf11, $vf1
    sqc2         $vf4, 0x270+var_200($sp)
    qmfc2        $v0, $vf1
    sqc2         $vf2, 0x270+var_170($sp)
    sqc2         $vf5, 0x270+var_1E0($sp)
    sqc2         $vf3, 0x270+var_1D0($sp)
    sqc2         $vf4, 0x270+var_1C0($sp)
    sqc2         $vf2, 0x270+var_1B0($sp)
    sqc2         $vf2, 0x270+var_1F0($sp)
  }
  if ( *&result < 2500.0 )
  {
    result = pConvexHull->m_numPlanes;
    v41 = 0;
    if ( pConvexHull->m_numPlanes )
    {
      __asm
      {
        vadd.xyz     $vf1, $vf0, $vf0
        sqc2         $vf1, 0x270+var_C0($sp)
      }
      *&v42 = 0.5;
      v43 = v87;
      do
      {
        v44 = v41 + 1;
        _$V0 = 16 * v41 + v43;
        __asm
        {
          lqc2         $vf4, 0($v0)
          lq           $v0, 0x270+var_C0($sp)
        }
        LODWORD(v47) = 0;
        __asm
        {
          sq           $v0, 0x270+var_230($sp)
          sq           $v0, 0x270+var_270($sp)
        }
        do
        {
          __asm { lqc2         $vf3, 0x270+var_270($sp) }
          v48 = *(4 * v41 + pConvexHull->m_offsetFaces + v47);
          v47 = v47 + 1;
          _$V0 = 16 * v48 + a4;
          __asm
          {
            lqc2         $vf1, 0($v0)
            vadd.xyz     $vf3, $vf3, $vf1
            sqc2         $vf3, 0x270+var_270($sp)
          }
        }
        while ( v47 < 4 );
        _$V0 = COERCE_INT(0.25);
        _$V1 = v42;
        __asm
        {
          qmtc2        $v0, $vf2
          qmtc2        $v1, $vf1
          vmulx.xyz    $vf3, $vf3, $vf2
          vmulx.xyz    $vf1, $vf4, $vf1
          vadd.xyz     $vf1, $vf3, $vf1
          sqc2         $vf3, 0x270+var_270($sp)
          sqc2         $vf1, 0x270+var_260($sp)
        }
        v52 = &v72;
        _$V0 = &v72;
        LODWORD(v54) = 1;
        __asm
        {
          lqc2         $vf5, 0($s3)
          lqc2         $vf4, 0x10($s3)
          lqc2         $vf3, 0x20($s3)
          lqc2         $vf2, 0x30($s3)
        }
        do
        {
          __asm { lqc2         $vf1, 0($v0) }
          v54 = v54 - 1;
          __asm
          {
            vmulax.xyz   $A, $vf5, $vf1
            vmadday.xyz  $A, $vf4, $vf1
            vmaddaz.xyz  $A, $vf3, $vf1
            vmaddw.xyz   $vf1, $vf2, $vf0
          }
          ++_$V0;
          __asm { sqc2         $vf1, 0($v1) }
          ++v52;
        }
        while ( v54 >= 0 );
        __asm
        {
          lq           $v0, 0x270+var_270($sp)
          lq           $v1, 0x270+var_260($sp)
          sq           $v0, 0x270+var_250($sp)
          por          $a2, $zero, $fp
          sq           $v1, 0x270+var_240($sp)
        }
        DrawLine__15CB4DebugManagerRC7CGtLineGQ29GtMathPs26CGtV4d(&gDebugManager, &v74, _$A2);
        if ( v88 )
        {
          v75 = 1.0;
          v76 = 1.0;
          v77 = 1.0;
          v78 = 1.0;
          __asm { lq           $s0, 0x270+var_230($sp) }
          sprintf(&v75, &unk_4A7D10, v58, v59);
          __asm
          {
            lq           $a2, 0x270+var_250($sp)
            por          $a4, $zero, $s0
          }
          DrawVectorText__15CB4DebugManagerPCcGQ29GtMathPs26CGtV3dPQ29GtMathPs212CGtMatrix3x4fGQ29GtMathPs26CGtV4d(
            &gDebugManager,
            &v75,
            _$A2,
            &v79,
            _$A4,
            COERCE_INT(0.050000001));
        }
        v41 = v44;
        result = v44 < pConvexHull->m_numPlanes;
        v43 = v87;
      }
      while ( v44 < pConvexHull->m_numPlanes );
    }
  }
  __asm
  {
    lq           $s0, 0x270+var_20($sp)
    lq           $s1, 0x270+var_30($sp)
    lq           $s2, 0x270+var_40($sp)
    lq           $s3, 0x270+var_50($sp)
    lq           $s4, 0x270+var_60($sp)
    lq           $s5, 0x270+var_70($sp)
    lq           $s6, 0x270+var_80($sp)
    lq           $s7, 0x270+var_90($sp)
    lq           $fp, 0x270+var_A0($sp)
  }
  return result;
}

__int64 __fastcall Initialise__20CB4ConvexHullVehicle(B4ConvexHull *a1)
{
  __int64 result; // $v0

  result = a1->m_deformData;
  a1->m_offsetPlanes = a1->m_planeData;
  a1->m_offsetDeformData = result;
  a1->m_offsetFaces = a1->m_faceData;
  a1->m_offsetVertices = a1->m_vertexData;
  a1->m_offsetEdges = a1->m_edgeData;
  return result;
}


