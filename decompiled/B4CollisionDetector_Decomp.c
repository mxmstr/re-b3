/*
00000000 struct B4CollisionDetector__maVehicleRearHull // sizeof=0x680
00000000 {                                       // XREF: .bss:_20CB4CollisionDetector$_maVehicleRearHull/r
00000000     B4ConvexHull field_0[2];            // XREF: ConstructConcave__20CB4CollisionDetector+58/o
00000000                                         // CollideConcaveVehicles__20CB4CollisionDetectorP20CB4HullCollideParams+19C/o
00000680 };

00000000 struct B4CollisionDetector__maVehicleMiddleHull // sizeof=0x680
00000000 {                                       // XREF: .bss:_20CB4CollisionDetector$_maVehicleMiddleHull/r
00000000     B4ConvexHull field_0[2];            // XREF: ConstructConcave__20CB4CollisionDetector+50/o
00000000                                         // CollideConcaveVehicles__20CB4CollisionDetectorP20CB4HullCollideParams+10C/o
00000680 };

00000000 struct __attribute__((packed)) B4CollisionDetector__maVehicleFrontHull // sizeof=0x680
00000000 {                                       // XREF: .bss:_20CB4CollisionDetector$_maVehicleFrontHull/r
00000000     B4ConvexHull field_0[2];            // XREF: ConstructConcave__20CB4CollisionDetector+48/o
00000000                                         // CollideConcaveVehicles__20CB4CollisionDetectorP20CB4HullCollideParams+7C/o
00000680 };
*/

// CB4AccHullParams::Prepare(void)
void __fastcall Prepare__16CB4AccHullParams(int a1)
{
  __asm
  {
    vadd.xyz     $vf1, $vf0, $vf0 # Alternative name is 'gcc2_compiled.'
    sqc2         $vf1, 0x10($a0)
  }
  *(a1 + 68) = 0;
  __asm
  {
    sqc2         $vf1, 0x20($a0)
    sqc2         $vf1, 0x30($a0)
    sqc2         $vf1, 0x10+var_10($sp)
    sqc2         $vf1, 0($a0)
  }
  *(a1 + 64) = 0;
}

// CB4HullCollideHullParams::CalculateBounds(void)
__int64 __fastcall CalculateBounds__24CB4HullCollideHullParams(int *a1)
{
  __int64 v2; // $a2
  int v4; // $a1
  int v6; // $a4
  int v7; // $a5
  int i; // $v0
  int v9; // $a0
  __int64 v13; // $a2
  int v14; // $a4
  int j; // $a0
  int v18; // $v0
  __int64 result; // $v0
  float v23[4]; // [sp+0h] [-10h] BYREF

  __asm
  {
    vadd.xyz     $vf1, $vf0, $vf0
    sqc2         $vf1, 0x10+var_10($sp)
  }
  _$A3 = a1;
  __asm { vmove.xyzw   $vf4, $vf1 }
  LODWORD(v2) = 0;
  __asm { lq           $v1, 0x10+var_10($sp) }
  v23[0] = -3.4028235e38;
  v23[1] = -3.4028235e38;
  v23[2] = -3.4028235e38;
  __asm { sq           $v1, 0x110($a3) }
  v4 = *a1;
  __asm
  {
    lq           $v0, 0x10+var_10($sp)
    sq           $v0, 0x100($a3)
  }
  v6 = *a1;
  if ( *(*a1 + 24) )
  {
    v7 = *a1;
    for ( i = *(v6 + 8); ; i = *(v6 + 8) )
    {
      v9 = 16 * v2;
      v2 = v2 + 1;
      _$V0 = v9 + i;
      __asm
      {
        lqc2         $vf1, 0x110($a3)
        lqc2         $vf2, 0($v0)
      }
      _$V1 = v9 + *(v4 + 8);
      __asm
      {
        vmini.xyz    $vf1, $vf1, $vf2
        lqc2         $vf3, 0($v1)
        sqc2         $vf1, 0x110($a3)
      }
      v4 = v7;
      __asm
      {
        lqc2         $vf2, 0x100($a3)
        vadd.xyz     $vf4, $vf4, $vf3
      }
      _$A0 = v9 + *(v6 + 8);
      __asm
      {
        lqc2         $vf1, 0($a0)
        vmax.xyz     $vf2, $vf2, $vf1
        sqc2         $vf2, 0x100($a3)
      }
      if ( v2 >= *(v7 + 24) )
        break;
    }
  }
  LODWORD(v13) = 0;
  v14 = *_$A3;
  __asm { lqc2         $vf5, 0xF0($a3) }
  *&_$F0 = 1.0 / *(*_$A3 + 24);
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vmulx.xyz    $vf4, $vf4, $vf1
    vmove.xyzw   $vf3, $vf4
  }
  if ( *(*_$A3 + 24) )
  {
    __asm { vaddw.x      $vf2, $vf0, $vf0 }
    for ( j = *(*_$A3 + 8); ; j = *(v14 + 8) )
    {
      v18 = 16 * v13;
      v13 = v13 + 1;
      _$V0 = v18 + j;
      __asm
      {
        lqc2         $vf1, 0($v0)
        vsub.xyz     $vf1, $vf3, $vf1
        vmul.xyz     $vf1, $vf1, $vf1
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf2, $vf1
        qmfc2        $v0, $vf1
      }
      _$F0 = _$V0;
      __asm { max          $f2, $f0 }
      if ( v13 >= *(v14 + 24) )
        break;
    }
  }
  __asm
  {
    vmove.xyzw   $vf2, $vf5
    vadd.xyz     $vf2, $vf0, $vf4
  }
  result = COERCE_INT(_sqrtf(*&_$F0));
  __asm
  {
    vmove.xyzw   $vf1, $vf2
    qmtc2        $v0, $vf3
    sqc2         $vf2, 0xF0($a3)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0xF0($a3)
    vaddx.w      $vf1, $vf1, $vf3
    sqc2         $vf1, 0xF0($a3)
  }
  return result;
}

// CB4HullCollideHullParams::IsValidPlane(int) const
__int64 __fastcall IsValidPlane__C24CB4HullCollideHullParamsi(int a1, __int64 a2)
{
  __int64 v2; // $v1
  __int64 result; // $v0

  v2 = *(a1 + 288);
  if ( v2 == 1 )
    goto LABEL_7;
  if ( v2 < 2 )
    return 1LL;
  if ( v2 == 2 )
  {
    if ( !a2 )
      return 0LL;
LABEL_7:
    result = 1LL;
    if ( a2 != 5 )
      return result;
    return 0LL;
  }
  result = 1LL;
  if ( v2 == 3 )
    return a2 != 0;
  return result;
}

// CB4CollisionDetector::Construct(void)
void Construct__20CB4CollisionDetector()
{
  ConstructConcave__20CB4CollisionDetector();
}

// CB4CollisionDetector::Prepare(void)
__int64 Prepare__20CB4CollisionDetector()
{
  return PrepareConcave__20CB4CollisionDetector();
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

// CB4CollisionDetector::SetupParams(CB4HullCollideParams *, CB4VehiclePhysics *, CB4ActiveBody *, bool)
__int64 __fastcall SetupParams__20CB4CollisionDetectorP20CB4HullCollideParamsP17CB4VehiclePhysicsP13CB4ActiveBodyb(
        int *a1,
        int _$A1,
        unsigned int a3,
        int a4)
{
  __int64 result; // $v0

  _$A5 = _$A1 + 96;
  __asm
  {
    sq           $s0, 0x50+var_10($sp)
    sq           $s1, 0x50+var_20($sp)
    sq           $s2, 0x50+var_30($sp)
  }
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
    lq           $a2, 0x30($a5)
  }
  *a1 = _$A1 + 528;
  __asm
  {
    sq           $a2, 0xA0($s0)
    lq           $v0, 0xA0($a1)
    sq           $v0, 0x10($s0)
    lq           $v1, 0xC0($a1)
  }
  a1[72] = 0;
  __asm { sq           $v1, 0x20($s0) }
  CalculateBounds__24CB4HullCollideHullParams(a1);
  _$A1 = *(a3 + 32);
  _$A2 = a1 + 104;
  __asm
  {
    lq           $v0, 0($a1)
    sq           $v0, 0x160($s0)
    lq           $v1, 0x10($a1)
    sq           $v1, 0x170($s0)
    lq           $v0, 0x20($a1)
    sq           $v0, 0x180($s0)
    lq           $v1, 0x30($a1)
    sq           $v1, 0x190($s0)
  }
  LODWORD(_$V0) = _$A1;
  __asm
  {
    lqc2         $vf3, 0($v0)
    sqc2         $vf3, 0x1A0($s0)
    vmove.xyzw   $vf4, $vf3
    lqc2         $vf1, 0x10($v0)
    sqc2         $vf1, 0x1B0($s0)
    vmove.xyzw   $vf9, $vf1
    vaddy.x      $vf9, $vf0, $vf3
    lqc2         $vf2, 0x20($v0)
    vmove.xyzw   $vf7, $vf9
    sqc2         $vf2, 0x1C0($s0)
    vmove.xyzw   $vf8, $vf2
    vaddz.x      $vf8, $vf0, $vf3
    lqc2         $vf3, 0x30($v0)
    vmove.xyzw   $vf6, $vf8
    sqc2         $vf3, 0x1D0($s0)
    lqc2         $vf2, 0x10($a2)
    vaddx.y      $vf4, $vf0, $vf2
    lqc2         $vf1, 0x20($a2)
    vmove.xyzw   $vf5, $vf4
    vaddy.z      $vf7, $vf0, $vf1
    vaddz.y      $vf6, $vf0, $vf2
    vaddx.z      $vf5, $vf0, $vf1
    vmulx.xyz    $vf1, $vf5, $vf3
    vmuly.xyz    $vf2, $vf7, $vf3
    vmulz.xyz    $vf3, $vf6, $vf3
    vadd.xyz     $vf1, $vf1, $vf2
    sqc2         $vf4, 0x1A0($s0)
    vadd.xyz     $vf1, $vf1, $vf3
    sqc2         $vf9, 0x1B0($s0)
    vsub.xyz     $vf1, $vf0, $vf1
    sqc2         $vf8, 0x1C0($s0)
    sqc2         $vf5, 0x1A0($s0)
    sqc2         $vf7, 0x1B0($s0)
    sqc2         $vf6, 0x1C0($s0)
    sqc2         $vf1, 0x30($a2)
  }
  a1[76] = GetConvexHull__13CB4ActiveBody(a3);
  a1[148] = 0;
  CalculateBounds__24CB4HullCollideHullParams(a1 + 76);
  result = 3LL;
  if ( *(a3 + 44) == 3LL )
  {
    __asm { vadd.xyz     $vf3, $vf0, $vf0 }
    _$A0 = *(a3 + 32);
    result = *(*(a3 + 40) + 196);
    __asm
    {
      lqc2         $vf1, 0x20($a0)
      qmtc2        $v0, $vf2
      vmulx.xyz    $vf1, $vf1, $vf2
      sqc2         $vf1, 0x140($s0)
    }
  }
  else
  {
    __asm
    {
      vadd.xyz     $vf1, $vf0, $vf0
      sqc2         $vf1, 0x50+var_50($sp)
      sqc2         $vf1, 0x140($s0)
      vmove.xyzw   $vf3, $vf1
    }
  }
  a1[152] = a4;
  __asm { sqc2         $vf3, 0x150($s0) }
  a1[153] = 0;
  __asm
  {
    lq           $s0, 0x50+var_10($sp)
    lq           $s1, 0x50+var_20($sp)
    lq           $s2, 0x50+var_30($sp)
    sqc2         $vf3, 0x50+var_50($sp)
  }
  return result;
}

// CB4CollisionDetector::CollideVehicleWithActiveBody(CB4HullCollideParams *, CB4VehiclePhysics *, CB4ActiveBody *, bool)
__int64 __fastcall CollideVehicleWithActiveBody__20CB4CollisionDetectorP20CB4HullCollideParamsP17CB4VehiclePhysicsP13CB4ActiveBodyb(
        int *a1,
        int a2,
        unsigned int a3,
        int a4)
{
  __int64 v7; // $s0
  __int64 result; // $v0

  __asm
  {
    sq           $s1, 0x30+var_20($sp)
    sq           $s0, 0x30+var_10($sp)
  }
  v7 = *(*(a2 + 2552) + 9091) ^ 1LL;
  SetupParams__20CB4CollisionDetectorP20CB4HullCollideParamsP17CB4VehiclePhysicsP13CB4ActiveBodyb(a1, a2, a3, a4);
  if ( v7 )
  {
    result = CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(a1);
    __asm { lq           $s0, 0x30+var_10($sp) }
  }
  else
  {
    result = CollideConcaveVehicleWithConvexHull__20CB4CollisionDetectorP20CB4HullCollideParamsb(a1, 1LL);
    __asm { lq           $s0, 0x30+var_10($sp) }
  }
  __asm { lq           $s1, 0x30+var_20($sp) }
  return result;
}

// CB4CollisionDetector::CollideVehicles(CB4HullCollideParams *, CB4VehiclePhysics *, CB4VehiclePhysics *, bool)
__int64 __fastcall CollideVehicles__20CB4CollisionDetectorP20CB4HullCollideParamsP17CB4VehiclePhysicsT2b(
        unsigned int a1,
        int a2,
        int a3,
        void *a4)
{
  __int64 v8; // $s0
  __int64 v9; // $s2
  int *v10; // $a0
  __int64 result; // $v0
  __int64 v13; // $a1

  __asm
  {
    sq           $s1, 0x40+var_20($sp)
    sq           $s2, 0x40+var_30($sp)
    sq           $s0, 0x40+var_10($sp)
  }
  v8 = *(*(a2 + 2552) + 9091) ^ 1LL;
  v9 = *(*(a3 + 2552) + 9091) ^ 1LL;
  SetupParams__20CB4CollisionDetectorP20CB4HullCollideParamsP16CB4CollidingBodyT2b(a1, a2, a3, a4);
  if ( !v8 )
  {
    v10 = a1;
    if ( !v9 )
    {
      result = CollideConcaveVehicles__20CB4CollisionDetectorP20CB4HullCollideParams(a1);
      __asm { lq           $s0, 0x40+var_10($sp) }
      goto LABEL_9;
    }
    v13 = 1LL;
LABEL_8:
    result = CollideConcaveVehicleWithConvexHull__20CB4CollisionDetectorP20CB4HullCollideParamsb(v10, v13);
    __asm { lq           $s0, 0x40+var_10($sp) }
    goto LABEL_9;
  }
  v10 = a1;
  if ( !v9 )
  {
    v13 = 0LL;
    goto LABEL_8;
  }
  result = CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(a1);
  __asm { lq           $s0, 0x40+var_10($sp) }
LABEL_9:
  __asm
  {
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

// CB4CollisionDetector::ConstructConcave(void)
void ConstructConcave__20CB4CollisionDetector()
{
  __asm
  {
    sq           $s2, 0x40+var_30($sp)
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
  }
  Construct__13CB4ConvexHull(20CB4CollisionDetector__maVehicleFrontHull.field_0);
  Construct__13CB4ConvexHull(20CB4CollisionDetector__maVehicleMiddleHull.field_0);
  Construct__13CB4ConvexHull(20CB4CollisionDetector__maVehicleRearHull.field_0);
  Construct__13CB4ConvexHull(&20CB4CollisionDetector__maVehicleFrontHull.field_0[1]);
  Construct__13CB4ConvexHull(&20CB4CollisionDetector__maVehicleMiddleHull.field_0[1]);
  Construct__13CB4ConvexHull(&20CB4CollisionDetector__maVehicleRearHull.field_0[1]);
  __asm
  {
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
}

// CB4CollisionDetector::PrepareConcave(void)
__int64 PrepareConcave__20CB4CollisionDetector()
{
  B4ConvexHull *v9; // $s1
  B4ConvexHull *v10; // $s2
  B4ConvexHull *v11; // $s0
  __int64 v12; // $t4
  unsigned int m_offsetFaces; // $v1
  __int64 v14; // $a7
  unsigned int v15; // $v0
  unsigned int v16; // $v1
  unsigned int v17; // $v0
  unsigned int v18; // $v1
  unsigned int v19; // $v0
  unsigned int m_offsetEdges; // t0
  unsigned int v21; // $v0
  unsigned int v22; // $v0
  unsigned int v23; // $v1
  unsigned int v24; // $v0
  unsigned int v25; // $v1
  unsigned int v26; // $v0
  unsigned int v27; // $v1
  unsigned int v28; // $v0
  unsigned int v29; // $v1
  unsigned int v30; // $v0
  int v31; // $a0
  _BYTE *v32; // $v0
  _BYTE *v33; // $v1
  char v34; // $a2
  char v35; // $a3
  char v36; // $a4
  char *v37; // $v0
  _BYTE *v38; // $a0
  char v39; // $a1
  char v40; // $a2
  __int64 v41; // $a5
  B4ConvexHull *v42; // $a4
  int v43; // $a0
  _BYTE *v44; // $a1
  char v45; // $v1
  char *v46; // $v0
  _BYTE *v47; // $a0
  char v48; // $v1
  int v49; // $v0
  char *v50; // $v1
  char *v51; // $v0
  __int64 result; // $v0
  int v62; // [sp+0h] [-B0h]

  __asm
  {
    sq           $s3, 0xB0+var_40($sp)
    sq           $s4, 0xB0+var_50($sp)
    sq           $s5, 0xB0+var_60($sp)
    sq           $s6, 0xB0+var_70($sp)
    sq           $s7, 0xB0+var_80($sp)
    sq           $fp, 0xB0+var_90($sp)
    sq           $s0, 0xB0+var_10($sp)
    sq           $s1, 0xB0+var_20($sp)
    sq           $s2, 0xB0+var_30($sp)
  }
  v62 = 0;
  do
  {
    v9 = &20CB4CollisionDetector__maVehicleFrontHull.field_0[v62];
    v10 = &20CB4CollisionDetector__maVehicleMiddleHull.field_0[v62];
    v11 = &20CB4CollisionDetector__maVehicleRearHull.field_0[v62];
    Prepare__13CB4ConvexHull(v9);
    Prepare__13CB4ConvexHull(v10);
    Prepare__13CB4ConvexHull(v11);
    Initialise__20CB4ConvexHullVehicle(v9);
    Initialise__20CB4ConvexHullVehicle(v10);
    Initialise__20CB4ConvexHullVehicle(v11);
    v9->m_numVertices = 8;
    v12 = v62 + 1;
    m_offsetFaces = v9->m_offsetFaces;
    v9->m_numEdges = 12;
    v9->m_numPlanes = 6;
    LODWORD(v14) = 0;
    *(m_offsetFaces + 3) = 1;
    *m_offsetFaces = 0;
    *(m_offsetFaces + 1) = 2;
    *(m_offsetFaces + 2) = 3;
    v15 = v9->m_offsetFaces;
    *(v9->m_offsetFaces + 4) = 4;
    v15 += 4;
    *(v15 + 3) = 5;
    *(v15 + 1) = 0;
    *(v15 + 2) = 1;
    v16 = v9->m_offsetFaces;
    *(v9->m_offsetFaces + 8) = 4;
    v16 += 8;
    *(v16 + 3) = 0;
    *(v16 + 1) = 6;
    *(v16 + 2) = 2;
    v17 = v9->m_offsetFaces;
    *(v9->m_offsetFaces + 12) = 1;
    v17 += 12;
    *(v17 + 3) = 5;
    *(v17 + 1) = 3;
    *(v17 + 2) = 7;
    v18 = v9->m_offsetFaces;
    *(v9->m_offsetFaces + 16) = 2;
    v18 += 16;
    *(v18 + 3) = 3;
    *(v18 + 1) = 6;
    *(v18 + 2) = 7;
    v19 = v9->m_offsetFaces;
    *(v9->m_offsetFaces + 20) = 5;
    v19 += 20;
    *(v19 + 3) = 4;
    *(v19 + 1) = 7;
    *(v19 + 2) = 6;
    m_offsetEdges = v9->m_offsetEdges;
    *m_offsetEdges = 0;
    *(m_offsetEdges + 1) = 1;
    v21 = v9->m_offsetEdges;
    *(v21 + 3) = 4;
    *(v21 + 2) = 5;
    *(v9->m_offsetEdges + 4) = 4;
    v22 = v9->m_offsetEdges;
    *(v22 + 7) = 1;
    *(v22 + 6) = 5;
    v23 = v9->m_offsetEdges;
    *(v23 + 9) = 3;
    *(v23 + 8) = 2;
    v24 = v9->m_offsetEdges;
    *(v24 + 11) = 6;
    *(v24 + 10) = 7;
    v25 = v9->m_offsetEdges;
    *(v25 + 13) = 2;
    *(v25 + 12) = 6;
    v26 = v9->m_offsetEdges;
    *(v26 + 15) = 3;
    *(v26 + 14) = 7;
    v27 = v9->m_offsetEdges;
    *(v27 + 17) = 0;
    *(v27 + 16) = 2;
    v28 = v9->m_offsetEdges;
    *(v28 + 19) = 1;
    *(v28 + 18) = 3;
    v29 = v9->m_offsetEdges;
    *(v29 + 21) = 4;
    *(v29 + 20) = 6;
    v30 = v9->m_offsetEdges;
    *(v30 + 22) = 7;
    *(v30 + 23) = 5;
    do
    {
      v31 = 4 * v14;
      v14 = v14 + 1;
      v32 = (v31 + v9->m_offsetFaces);
      v33 = (v31 + v10->m_offsetFaces);
      v34 = v32[1];
      v35 = v32[2];
      v36 = v32[3];
      *v33 = *v32;
      v33[3] = v36;
      v33[1] = v34;
      v33[2] = v35;
      v37 = (v31 + v9->m_offsetFaces);
      v38 = (v31 + v11->m_offsetFaces);
      v39 = *v37;
      LOBYTE(v33) = v37[1];
      v40 = v37[2];
      v38[3] = v37[3];
      *v38 = v39;
      v38[1] = v33;
      v38[2] = v40;
    }
    while ( v14 < 8 );
    LODWORD(v41) = 0;
    v42 = &20CB4CollisionDetector__maVehicleFrontHull.field_0[v62];
    do
    {
      v43 = 2 * v41;
      v41 = v41 + 1;
      v44 = (v43 + 20CB4CollisionDetector__maVehicleMiddleHull.field_0[v62].m_offsetEdges);
      v45 = *(v43 + v42->m_offsetEdges);
      v44[1] = *(v43 + v42->m_offsetEdges + 1);
      *v44 = v45;
      v46 = (v43 + v42->m_offsetEdges);
      v47 = (v43 + 20CB4CollisionDetector__maVehicleRearHull.field_0[v62].m_offsetEdges);
      v48 = *v46;
      v47[1] = v46[1];
      *v47 = v48;
    }
    while ( v41 < 12 );
    v49 = 832 * v62++;
    v50 = &20CB4CollisionDetector__maVehicleRearHull + v49;
    v51 = &20CB4CollisionDetector__maVehicleMiddleHull + v49;
    v51[26] = 12;
    v50[26] = 12;
    v51[24] = 8;
    v51[25] = 6;
    v50[25] = 6;
    v50[24] = 8;
  }
  while ( v12 < 2 );
  __asm { lq           $s0, 0xB0+var_10($sp) }
  result = 1LL;
  __asm
  {
    lq           $s1, 0xB0+var_20($sp)
    lq           $s2, 0xB0+var_30($sp)
    lq           $s3, 0xB0+var_40($sp)
    lq           $s4, 0xB0+var_50($sp)
    lq           $s5, 0xB0+var_60($sp)
    lq           $s6, 0xB0+var_70($sp)
    lq           $s7, 0xB0+var_80($sp)
    lq           $fp, 0xB0+var_90($sp)
  }
  return result;
}

// CB4CollisionDetector::CollideConcaveVehicleWithWorld(CB4HullWorldTriCollideParams *, CB4VehiclePhysics *)
__int64 __fastcall CollideConcaveVehicleWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP17CB4VehiclePhysics(
        unsigned int a1,
        int a2)
{
  __int64 v4; // $ra
  __int64 result; // $v0
  __int128 v14; // [sp+0h] [-80h] BYREF
  int v17; // [sp+40h] [-40h]
  bool v18; // [sp+44h] [-3Ch]
  __int64 v19; // [sp+50h] [-30h]

  __asm
  {
    sq           $s0, 0x80+var_10($sp)
    sq           $s1, 0x80+var_20($sp)
  }
  _$S0 = a1;
  v19 = v4;
  Prepare__16CB4AccHullParams(&v14);
  SetupVehicleHulls__20CB4CollisionDetectoriPC13CB4ConvexHull(0, *(a2 + 504));
  *_$S0 = &20CB4CollisionDetector__maVehicleFrontHull;
  if ( CollideBodyConvexHullWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP16CB4CollidingBody(
         _$S0,
         a2) )
  {
    __asm
    {
      lqc2         $vf1, 0xC0($s0)
      lqc2         $vf6, 0xB0($s0)
      lqc2         $vf2, 0xD0($s0)
      lqc2         $vf4, 0x80+var_70($sp)
      lqc2         $vf5, 0x80+var_80($sp)
      vadd.xyz     $vf4, $vf4, $vf1
      lqc2         $vf3, 0x80+var_60($sp)
      vadd.xyz     $vf5, $vf5, $vf6
      vadd.xyz     $vf3, $vf3, $vf2
      sqc2         $vf4, 0x80+var_70($sp)
      sqc2         $vf5, 0x80+var_80($sp)
      sqc2         $vf3, 0x80+var_60($sp)
    }
    v18 |= *(_$S0 + 337) != 0LL;
    ++v17;
  }
  *_$S0 = &20CB4CollisionDetector__maVehicleMiddleHull;
  if ( CollideBodyConvexHullWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP16CB4CollidingBody(
         _$S0,
         a2) )
  {
    __asm
    {
      lqc2         $vf1, 0xC0($s0)
      lqc2         $vf6, 0xB0($s0)
      lqc2         $vf2, 0xD0($s0)
      lqc2         $vf4, 0x80+var_70($sp)
      lqc2         $vf5, 0x80+var_80($sp)
      vadd.xyz     $vf4, $vf4, $vf1
      lqc2         $vf3, 0x80+var_60($sp)
      vadd.xyz     $vf5, $vf5, $vf6
      vadd.xyz     $vf3, $vf3, $vf2
      sqc2         $vf4, 0x80+var_70($sp)
      sqc2         $vf5, 0x80+var_80($sp)
      sqc2         $vf3, 0x80+var_60($sp)
    }
    v18 |= *(_$S0 + 337) != 0LL;
    ++v17;
  }
  *_$S0 = &20CB4CollisionDetector__maVehicleRearHull;
  if ( CollideBodyConvexHullWithWorld__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP16CB4CollidingBody(
         _$S0,
         a2) )
  {
    __asm
    {
      lqc2         $vf1, 0xC0($s0)
      lqc2         $vf6, 0xB0($s0)
      lqc2         $vf2, 0xD0($s0)
      lqc2         $vf4, 0x80+var_70($sp)
      lqc2         $vf5, 0x80+var_80($sp)
      vadd.xyz     $vf4, $vf4, $vf1
      lqc2         $vf3, 0x80+var_60($sp)
      vadd.xyz     $vf5, $vf5, $vf6
      vadd.xyz     $vf3, $vf3, $vf2
      sqc2         $vf4, 0x80+var_70($sp)
      sqc2         $vf5, 0x80+var_80($sp)
      sqc2         $vf3, 0x80+var_60($sp)
    }
    v18 |= *(_$S0 + 337) != 0LL;
    ++v17;
  }
  __asm { lqc2         $vf1, 0x80+var_70($sp) }
  if ( v17 <= 0LL )
  {
    result = 0LL;
  }
  else
  {
    __asm
    {
      vaddw.x      $vf2, $vf0, $vf0
      vmul.xyz     $vf1, $vf1, $vf1
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf2, $vf1
      qmfc2        $v0, $vf1
      vmove.xyzw   $vf3, $vf2
    }
    _$V1 = COERCE_INT(1.0 / v17);
    __asm
    {
      lqc2         $vf1, 0x80+var_80($sp)
      qmtc2        $v1, $vf2
      vmulx.xyz    $vf1, $vf1, $vf2
      sqc2         $vf1, 0xB0($s0)
      lqc2         $vf2, 0x80+var_70($sp)
    }
    if ( *&_$V0 >= 2.3283064e-10 )
    {
      __asm
      {
        vmul.xyz     $vf1, $vf2, $vf2
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf3, $vf1
        sqc2         $vf2, 0xC0($s0)
        vnop
        vnop
        vnop
        vrsqrt       $Q, $vf0.w, $vf1.x
        vwaitq
        vmulq.xyz    $vf2, $vf2, $Q
        sqc2         $vf2, 0xC0($s0)
      }
    }
    else
    {
      __asm
      {
        lq           $v0, 0x140($s0)
        sq           $v0, 0xC0($s0)
      }
    }
    result = 1LL;
    __asm { lq           $v1, 0x80+var_60($sp) }
    *(_$S0 + 337) = v18;
    __asm { sq           $v1, 0xD0($s0) }
  }
  __asm
  {
    lq           $s0, 0x80+var_10($sp)
    lq           $s1, 0x80+var_20($sp)
  }
  return result;
}

// CB4CollisionDetector::CollideConcaveVehicleWithConvexHull(CB4HullCollideParams *, bool)
__int64 __fastcall CollideConcaveVehicleWithConvexHull__20CB4CollisionDetectorP20CB4HullCollideParamsb(
        int *a1,
        __int64 a2)
{
  __int64 v6; // $ra
  int *v8; // $s2
  int *v9; // $s1
  int v10; // $s3
  __int64 result; // $v0
  __int128 v19; // [sp+0h] [-A0h] BYREF
  int v23; // [sp+40h] [-60h]
  bool v24; // [sp+44h] [-5Ch]
  __int64 v25; // [sp+50h] [-50h]

  __asm
  {
    sq           $s0, 0xA0+var_10($sp)
    sq           $s1, 0xA0+var_20($sp)
  }
  _$S0 = a1;
  __asm
  {
    sq           $s2, 0xA0+var_30($sp)
    sq           $s3, 0xA0+var_40($sp)
  }
  v25 = v6;
  if ( a2 )
  {
    v8 = a1;
    v9 = a1;
    a1[148] = 0;
    CalculateBounds__24CB4HullCollideHullParams(a1 + 76);
  }
  else
  {
    v8 = a1 + 76;
    a1[72] = 0;
    v9 = a1 + 76;
    CalculateBounds__24CB4HullCollideHullParams(a1);
  }
  Prepare__16CB4AccHullParams(&v19);
  v10 = *v8;
  SetupVehicleHulls__20CB4CollisionDetectoriPC13CB4ConvexHull(0, *v8);
  *v8 = &20CB4CollisionDetector__maVehicleFrontHull;
  v9[72] = 1;
  CalculateBounds__24CB4HullCollideHullParams(v9);
  __asm { lqc2         $vf7, 0xA0+var_90($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0xA0+var_A0($sp)
      lqc2         $vf6, 0xA0+var_80($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0xA0+var_70($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0xA0+var_90($sp)
      sqc2         $vf5, 0xA0+var_A0($sp)
      sqc2         $vf6, 0xA0+var_80($sp)
      sqc2         $vf4, 0xA0+var_70($sp)
    }
    v24 = (v24 | (*(_$S0 + 612) == 1LL)) != 0;
    ++v23;
  }
  *v8 = &20CB4CollisionDetector__maVehicleMiddleHull;
  v9[72] = 2;
  CalculateBounds__24CB4HullCollideHullParams(v9);
  __asm { lqc2         $vf7, 0xA0+var_90($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0xA0+var_A0($sp)
      lqc2         $vf6, 0xA0+var_80($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0xA0+var_70($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0xA0+var_90($sp)
      sqc2         $vf5, 0xA0+var_A0($sp)
      sqc2         $vf6, 0xA0+var_80($sp)
      sqc2         $vf4, 0xA0+var_70($sp)
    }
    v24 = (v24 | (*(_$S0 + 612) == 1LL)) != 0;
    ++v23;
  }
  *v8 = &20CB4CollisionDetector__maVehicleRearHull;
  v9[72] = 3;
  CalculateBounds__24CB4HullCollideHullParams(v9);
  __asm { lqc2         $vf7, 0xA0+var_90($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0xA0+var_A0($sp)
      lqc2         $vf6, 0xA0+var_80($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0xA0+var_70($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0xA0+var_90($sp)
      sqc2         $vf5, 0xA0+var_A0($sp)
      sqc2         $vf6, 0xA0+var_80($sp)
      sqc2         $vf4, 0xA0+var_70($sp)
    }
    v24 = (v24 | (*(_$S0 + 612) == 1LL)) != 0;
    ++v23;
  }
  *v8 = v10;
  __asm { lqc2         $vf3, 0xA0+var_A0($sp) }
  if ( v23 > 0LL )
  {
    result = 1LL;
    __asm { lqc2         $vf2, 0xA0+var_90($sp) }
    _$V1 = COERCE_INT(1.0 / v23);
    __asm
    {
      lq           $a1, 0xA0+var_80($sp)
      qmtc2        $v1, $vf1
      lq           $a0, 0xA0+var_70($sp)
      vmulx.xyz    $vf2, $vf2, $vf1
      vmulx.xyz    $vf3, $vf3, $vf1
      sqc2         $vf3, 0x280($s0)
      sqc2         $vf2, 0x270($s0)
      sq           $a0, 0x200($s0)
    }
    *(_$S0 + 612) = v24;
    __asm { sq           $a1, 0xD0($s0) }
  }
  else
  {
    result = 0LL;
  }
  __asm
  {
    lq           $s0, 0xA0+var_10($sp)
    lq           $s1, 0xA0+var_20($sp)
    lq           $s2, 0xA0+var_30($sp)
    lq           $s3, 0xA0+var_40($sp)
  }
  return result;
}

// CB4CollisionDetector::CollideConcaveVehicles(CB4HullCollideParams *)
__int64 __fastcall CollideConcaveVehicles__20CB4CollisionDetectorP20CB4HullCollideParams(unsigned int *a1)
{
  __int64 v10; // $ra
  unsigned int v12; // $fp
  __int64 v13; // $v0
  __int64 result; // $v0
  float v15; // $f1
  __int128 v28; // [sp+0h] [-100h] BYREF
  int v32; // [sp+40h] [-C0h]
  bool v33; // [sp+44h] [-BCh]
  int v34; // [sp+50h] [-B0h]
  __int64 v35; // [sp+60h] [-A0h]

  __asm { sq           $s0, 0x100+var_10($sp) }
  _$S0 = a1;
  __asm
  {
    sq           $s1, 0x100+var_20($sp)
    sq           $s6, 0x100+var_70($sp)
    sq           $s7, 0x100+var_80($sp)
    sq           $fp, 0x100+var_90($sp)
    sq           $s2, 0x100+var_30($sp)
    sq           $s3, 0x100+var_40($sp)
    sq           $s4, 0x100+var_50($sp)
    sq           $s5, 0x100+var_60($sp)
  }
  v35 = v10;
  Prepare__16CB4AccHullParams(&v28);
  v12 = *_$S0;
  v34 = _$S0[76];
  SetupVehicleHulls__20CB4CollisionDetectoriPC13CB4ConvexHull(0, v12);
  SetupVehicleHulls__20CB4CollisionDetectoriPC13CB4ConvexHull(1, _$S0[76]);
  _$S0[72] = 1;
  *_$S0 = &20CB4CollisionDetector__maVehicleFrontHull;
  CalculateBounds__24CB4HullCollideHullParams(_$S0);
  _$S0[76] = &20CB4CollisionDetector__maVehicleFrontHull.field_0[1];
  _$S0[148] = 1;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[76] = &20CB4CollisionDetector__maVehicleMiddleHull.field_0[1];
  _$S0[148] = 2;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[76] = &20CB4CollisionDetector__maVehicleRearHull.field_0[1];
  _$S0[148] = 3;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[72] = 2;
  *_$S0 = &20CB4CollisionDetector__maVehicleMiddleHull;
  CalculateBounds__24CB4HullCollideHullParams(_$S0);
  _$S0[76] = &20CB4CollisionDetector__maVehicleFrontHull.field_0[1];
  _$S0[148] = 1;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[76] = &20CB4CollisionDetector__maVehicleMiddleHull.field_0[1];
  _$S0[148] = 2;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[76] = &20CB4CollisionDetector__maVehicleRearHull.field_0[1];
  _$S0[148] = 3;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[72] = 3;
  *_$S0 = &20CB4CollisionDetector__maVehicleRearHull;
  CalculateBounds__24CB4HullCollideHullParams(_$S0);
  _$S0[76] = &20CB4CollisionDetector__maVehicleFrontHull.field_0[1];
  _$S0[148] = 1;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[76] = &20CB4CollisionDetector__maVehicleMiddleHull.field_0[1];
  _$S0[148] = 2;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  _$S0[76] = &20CB4CollisionDetector__maVehicleRearHull.field_0[1];
  _$S0[148] = 3;
  CalculateBounds__24CB4HullCollideHullParams(_$S0 + 76);
  __asm { lqc2         $vf7, 0x100+var_F0($sp) }
  if ( CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0) )
  {
    __asm
    {
      lqc2         $vf1, 0x270($s0)
      vadd.xyz     $vf7, $vf7, $vf1
      lqc2         $vf2, 0x280($s0)
      lqc2         $vf3, 0xD0($s0)
      lqc2         $vf1, 0x200($s0)
      lqc2         $vf5, 0x100+var_100($sp)
      lqc2         $vf6, 0x100+var_E0($sp)
      vadd.xyz     $vf5, $vf5, $vf2
      lqc2         $vf4, 0x100+var_D0($sp)
      vadd.xyz     $vf6, $vf6, $vf3
      vadd.xyz     $vf4, $vf4, $vf1
      sqc2         $vf7, 0x100+var_F0($sp)
      sqc2         $vf5, 0x100+var_100($sp)
      sqc2         $vf6, 0x100+var_E0($sp)
      sqc2         $vf4, 0x100+var_D0($sp)
    }
    v33 = (v33 | (_$S0[153] == 1LL)) != 0;
    ++v32;
  }
  v13 = v32;
  *_$S0 = v12;
  _$S0[76] = v34;
  if ( v13 > 0 )
  {
    v15 = v13;
    __asm { lqc2         $vf3, 0x100+var_100($sp) }
    result = 1LL;
    __asm { lqc2         $vf2, 0x100+var_F0($sp) }
    _$V1 = COERCE_INT(1.0 / v15);
    __asm
    {
      lq           $a1, 0x100+var_E0($sp)
      qmtc2        $v1, $vf1
      lq           $a0, 0x100+var_D0($sp)
      vmulx.xyz    $vf2, $vf2, $vf1
      vmulx.xyz    $vf3, $vf3, $vf1
      sqc2         $vf3, 0x280($s0)
      sqc2         $vf2, 0x270($s0)
      sq           $a0, 0x200($s0)
    }
    _$S0[153] = v33;
    __asm { sq           $a1, 0xD0($s0) }
  }
  else
  {
    result = 0LL;
  }
  __asm
  {
    lq           $s0, 0x100+var_10($sp)
    lq           $s1, 0x100+var_20($sp)
    lq           $s2, 0x100+var_30($sp)
    lq           $s3, 0x100+var_40($sp)
    lq           $s4, 0x100+var_50($sp)
    lq           $s5, 0x100+var_60($sp)
    lq           $s6, 0x100+var_70($sp)
    lq           $s7, 0x100+var_80($sp)
    lq           $fp, 0x100+var_90($sp)
  }
  return result;
}

// CB4CollisionDetector::SetupVehicleHulls(int, const CB4ConvexHull *)
__int64 __fastcall SetupVehicleHulls__20CB4CollisionDetectoriPC13CB4ConvexHull(int a1, _DWORD *a2)
{
  int v5; // $s2
  unsigned int v7; // $a3
  char *v18; // $s0
  unsigned int v24; // $s2
  __int64 result; // $v0

  __asm { sq           $s2, 0x40+var_30($sp) }
  v5 = a1;
  __asm
  {
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
  }
  v7 = &20CB4CollisionDetector__maVehicleFrontHull.field_0[a1];
  *(v7 + 8) = a2[2];
  *(v7 + 12) = a2[3];
  *(v7 + 16) = a2[4];
  _$A2 = a2[1];
  __asm
  {
    lq           $v0, 0($a2)
    sq           $v0, 0($a4)
  }
  _$V1 = _$A2;
  __asm
  {
    lq           $v0, 0x10($v1)
    sq           $v0, 0x10($a2)
  }
  _$V1 = _$A2;
  __asm
  {
    lq           $v0, 0x20($v1)
    sq           $v0, 0x20($a2)
  }
  _$V1 = _$A2;
  __asm
  {
    lq           $v0, 0x30($v1)
    sq           $v0, 0x30($a2)
  }
  _$V1 = _$A2;
  __asm
  {
    lq           $v0, 0x40($v1)
    sq           $v0, 0x40($a2)
  }
  CalculatePlaneData__13CB4ConvexHulli(v7, 5);
  v18 = &20CB4CollisionDetector__maVehicleMiddleHull + v5 * 832;
  *(v18 + 2) = a2[2] + 64;
  *(v18 + 4) = a2[4] + 48;
  _$V1 = a2[1];
  __asm
  {
    lq           $v0, 0x50($v1)
    sq           $v0, 0x10($a2)
    lq           $v0, 0x60($v1)
    sq           $v0, 0x20($a2)
    lq           $v0, 0x70($v1)
    sq           $v0, 0x30($a2)
    lq           $v0, 0x80($v1)
    sq           $v0, 0x40($a2)
  }
  CalculatePlaneData__13CB4ConvexHulli(&20CB4CollisionDetector__maVehicleMiddleHull.field_0[v5], 0);
  CalculatePlaneData__13CB4ConvexHulli(&20CB4CollisionDetector__maVehicleMiddleHull.field_0[v5], 5);
  v24 = &20CB4CollisionDetector__maVehicleRearHull + v5 * 832;
  *(v24 + 8) = a2[2] + 128;
  *(v24 + 16) = a2[4] + 96;
  _$V1 = a2[1];
  __asm
  {
    lq           $v0, 0x90($v1)
    sq           $v0, 0x10($a2)
    lq           $v0, 0xA0($v1)
    sq           $v0, 0x20($a2)
    lq           $v0, 0xB0($v1)
    sq           $v0, 0x30($a2)
    lq           $v0, 0xC0($v1)
    sq           $v0, 0x40($a2)
    lq           $v0, 0xD0($v1)
    sq           $v0, 0x50($a2)
  }
  result = CalculatePlaneData__13CB4ConvexHulli(v24, 0);
  __asm
  {
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return result;
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

// CB4CollisionDetector::CollideConcaveVehicles(CB4HullCollideParams *)
__int64 __fastcall CollideConvexHulls__20CB4CollisionDetectorP20CB4HullCollideParams(int a1)
{
  bool v4; // dc
  __int64 result; // $v0
  int v6; // $a0
  float v8; // [sp+Ch] [-24h]

  __asm { sq           $s0, 0x30+var_10($sp) }
  _$S0 = a1;
  if ( !gDebugManager.physicsDebug[24] )
    goto LABEL_3;
  __asm
  {
    lqc2         $vf8, 0xF0($s0)
    vaddw.x      $vf10, $vf0, $vf0
    lqc2         $vf7, 0x220($s0)
    lqc2         $vf3, 0x30($s0)
    vaddw.w      $vf9, $vf8, $vf7
    lqc2         $vf4, 0x160($s0)
    vmulx.xyz    $vf3, $vf3, $vf8
    vmulx.xyz    $vf4, $vf4, $vf7
    lqc2         $vf2, 0x60($s0)
    lqc2         $vf1, 0x190($s0)
    vadd.xyz     $vf2, $vf2, $vf3
    vadd.xyz     $vf1, $vf1, $vf4
    lqc2         $vf6, 0x40($s0)
    lqc2         $vf3, 0x170($s0)
    vmuly.xyz    $vf6, $vf6, $vf8
    lqc2         $vf4, 0x50($s0)
    vmuly.xyz    $vf3, $vf3, $vf7
    lqc2         $vf5, 0x180($s0)
    vadd.xyz     $vf2, $vf2, $vf6
    sqc2         $vf9, 0x30+var_30($sp)
    vadd.xyz     $vf1, $vf1, $vf3
    vmulz.xyz    $vf4, $vf4, $vf8
    vmulz.xyz    $vf5, $vf5, $vf7
    vadd.xyz     $vf2, $vf2, $vf4
    vadd.xyz     $vf1, $vf1, $vf5
    vsub.xyz     $vf1, $vf1, $vf2
    vmul.xyz     $vf1, $vf1, $vf1
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf10, $vf1
    qmfc2        $v0, $vf1
  }
  v4 = (v8 * v8) < *&_$V0;
  result = 0LL;
  if ( !v4 )
  {
LABEL_3:
    v6 = a1 + 256;
    if ( !gDebugManager.physicsDebug[25]
      || (v4 = BoxBoxCollision__FRC17CGtAxisAlignedBoxRCQ29GtMathPs212CGtMatrix3x4T0T1T1PfPQ29GtMathPs26CGtV3dT6(
                 v6,
                 (_$S0 + 12),
                 (_$S0 + 140),
                 (_$S0 + 88),
                 (_$S0 + 104),
                 0,
                 0LL,
                 0LL) == 0,
          result = 0LL,
          !v4) )
    {
      result = DoCollideConvexHullToHull__20CB4CollisionDetectorP20CB4HullCollideParams(_$S0);
    }
  }
  __asm { lq           $s0, 0x30+var_10($sp) }
  return result;
}

// CB4CollisionDetector::DoCollideConvexHullToHull(CB4HullCollideParams *)
__int64 __fastcall DoCollideConvexHullToHull__20CB4CollisionDetectorP20CB4HullCollideParams(int *a1)
{
  __int64 v10; // $ra
  __int64 v12; // $v0
  bool v13; // dc
  int v15; // $a1
  int v17; // $a0
  __int64 v20; // $v0
  __int64 v21; // $v0
  __int64 v22; // $v0
  int v23; // $v1
  int v24; // $a1
  int v25; // $v0
  __int64 v27; // $v1
  _BYTE *v28; // $v0
  __int64 v29; // $v0
  __int64 v30; // $v1
  int v32; // $v0
  signed __int64 v36; // $v0
  int v37; // $s1
  int v38; // $a4
  B4CollisionDetector *v39; // $a0
  __int64 v42; // $s1
  __int64 result; // $v0
  float v44; // $f20
  __int64 CollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d; // $s2
  __int64 v50; // $v0
  __int64 v53; // $v0
  int v54; // $v1
  unsigned __int64 v57; // $a0
  float v58; // $f0
  float v59; // $f2
  _BYTE v74[256]; // [sp+0h] [-BD0h] BYREF
  char v75; // [sp+100h] [-AD0h] BYREF
  B4CollisionDetector v76; // [sp+200h] [-9D0h] BYREF
  B4CollisionDetector v77; // [sp+580h] [-650h] BYREF
  int v86[4]; // [sp+A80h] [-150h] BYREF
  __int128 v87; // [sp+A90h] [-140h] BYREF
  int v90; // [sp+AC0h] [-110h]
  int v91; // [sp+AC4h] [-10Ch]
  int v94; // [sp+AF0h] [-E0h]
  __int64 v98; // [sp+B30h] [-A0h]

  __asm
  {
    vaddw.x      $vf1, $vf0, $vf0
    sqc2         $vf1, 0xBD0+var_D0($sp)
    sq           $s0, 0xBD0+var_10($sp)
    sq           $s2, 0xBD0+var_30($sp)
  }
  _$S0 = a1;
  __asm
  {
    sq           $s6, 0xBD0+var_70($sp)
    sq           $fp, 0xBD0+var_90($sp)
  }
  v94 = &v75;
  __asm
  {
    sq           $s1, 0xBD0+var_20($sp)
    sq           $s3, 0xBD0+var_40($sp)
    sq           $s4, 0xBD0+var_50($sp)
    sq           $s5, 0xBD0+var_60($sp)
    sq           $s7, 0xBD0+var_80($sp)
  }
  v98 = v10;
  v12 = 14LL;
  do
  {
    v13 = v12 != -1;
    v12 = v12 - 1;
  }
  while ( v13 );
  __asm
  {
    lqc2         $vf3, 0x30($s0)
    lqc2         $vf2, 0x1A0($s0)
  }
  _$S5 = a1 + 12;
  v15 = *a1;
  _$S3 = a1 + 104;
  v17 = a1[76];
  _$S7 = _$S0 + 88;
  _$S4 = _$S0 + 28;
  v20 = 14LL;
  do
  {
    v13 = v20 != -1;
    v20 = v20 - 1;
  }
  while ( v13 );
  v21 = 54LL;
  do
  {
    v13 = v21 != -1;
    v21 = v21 - 1;
  }
  while ( v13 );
  v22 = 62LL;
  do
  {
    v13 = v22 != -1;
    v22 = v22 - 1;
  }
  while ( v13 );
  __asm
  {
    lqc2         $vf9, 0x10($s3)
    lqc2         $vf7, 0x20($s3)
    lqc2         $vf1, 0x10($s5)
  }
  v90 = *(v15 + 4);
  __asm
  {
    vmulax.xyz   $A, $vf2, $vf3
    vmadday.xyz  $A, $vf9, $vf3
    vmaddz.xyz   $vf14, $vf7, $vf3
    vmulax.xyz   $A, $vf2, $vf1
    vmadday.xyz  $A, $vf9, $vf1
    vmaddz.xyz   $vf15, $vf7, $vf1
  }
  v91 = *(v17 + 4);
  v23 = *(v15 + 8);
  __asm
  {
    lqc2         $vf10, 0x70($s0)
    lqc2         $vf8, 0x10($s4)
    lqc2         $vf6, 0x20($s4)
    lqc2         $vf5, 0x30($s5)
    lqc2         $vf3, 0x1A0($s0)
    lqc2         $vf2, 0x30($s3)
    lqc2         $vf4, 0x160($s0)
    lqc2         $vf1, 0x10($s7)
  }
  v24 = *(v17 + 8);
  __asm
  {
    lqc2         $vf11, 0x20($s5)
    sqc2         $vf15, 0xBD0+var_180($sp)
    vmulax.xyz   $A, $vf3, $vf11
    vmadday.xyz  $A, $vf9, $vf11
    vmaddz.xyz   $vf12, $vf7, $vf11
    vmulax.xyz   $A, $vf3, $vf5
    vmadday.xyz  $A, $vf9, $vf5
    vmaddaz.xyz  $A, $vf7, $vf5
    vmaddw.xyz   $vf13, $vf2, $vf0
    sqc2         $vf14, 0xBD0+var_190($sp)
    vmulax.xyz   $A, $vf10, $vf4
    vmadday.xyz  $A, $vf8, $vf4
    vmaddz.xyz   $vf7, $vf6, $vf4
    vmulax.xyz   $A, $vf10, $vf1
    vmadday.xyz  $A, $vf8, $vf1
    vmaddz.xyz   $vf9, $vf6, $vf1
    lqc2         $vf3, 0x20($s7)
    lqc2         $vf2, 0x30($s7)
    lqc2         $vf1, 0x30($s4)
    sqc2         $vf14, 0xBD0+var_250($sp)
    vmulax.xyz   $A, $vf10, $vf3
    vmadday.xyz  $A, $vf8, $vf3
    vmaddz.xyz   $vf4, $vf6, $vf3
    vmulax.xyz   $A, $vf10, $vf2
    vmadday.xyz  $A, $vf8, $vf2
    vmaddaz.xyz  $A, $vf6, $vf2
    vmaddw.xyz   $vf5, $vf1, $vf0
    sqc2         $vf15, 0xBD0+var_240($sp)
    sqc2         $vf12, 0xBD0+var_230($sp)
    sqc2         $vf13, 0xBD0+var_220($sp)
    sqc2         $vf12, 0xBD0+var_170($sp)
    sqc2         $vf13, 0xBD0+var_160($sp)
    sqc2         $vf14, 0xBD0+var_1D0($sp)
    sqc2         $vf15, 0xBD0+var_1C0($sp)
    sqc2         $vf12, 0xBD0+var_1B0($sp)
    sqc2         $vf13, 0xBD0+var_1A0($sp)
    sqc2         $vf7, 0xBD0+var_190($sp)
    sqc2         $vf9, 0xBD0+var_180($sp)
    sqc2         $vf4, 0xBD0+var_170($sp)
    sqc2         $vf7, 0xBD0+var_210($sp)
    sqc2         $vf9, 0xBD0+var_200($sp)
    sqc2         $vf4, 0xBD0+var_1F0($sp)
    sqc2         $vf5, 0xBD0+var_1E0($sp)
    sqc2         $vf5, 0xBD0+var_160($sp)
    sqc2         $vf7, 0xBD0+var_1D0($sp)
    sqc2         $vf9, 0xBD0+var_1C0($sp)
    sqc2         $vf4, 0xBD0+var_1B0($sp)
    sqc2         $vf5, 0xBD0+var_1A0($sp)
  }
  if ( *(*_$S0 + 24) )
  {
    _$A0 = v23;
    LODWORD(v27) = *(*_$S0 + 24);
    v28 = v74;
    do
    {
      __asm { lqc2         $vf3, 0($a0) }
      v27 = v27 - 1;
      __asm { lqc2         $vf5, 0xBD0+var_250($sp) }
      _$A0 += 16;
      __asm
      {
        lqc2         $vf4, 0xBD0+var_240($sp)
        lqc2         $vf2, 0xBD0+var_230($sp)
        lqc2         $vf1, 0xBD0+var_220($sp)
        vmulax.xyz   $A, $vf5, $vf3
        vmadday.xyz  $A, $vf4, $vf3
        vmaddaz.xyz  $A, $vf2, $vf3
        vmaddw.xyz   $vf3, $vf1, $vf0
        sqc2         $vf3, 0($v0)
      }
      v28 += 16;
    }
    while ( v27 );
    v25 = _$S0[76];
  }
  else
  {
    v25 = _$S0[76];
  }
  v29 = *(v25 + 24);
  if ( v29 )
  {
    LODWORD(v30) = v29;
    _$A0 = v24;
    v32 = v94;
    do
    {
      __asm { lqc2         $vf3, 0($a0) }
      v30 = v30 - 1;
      __asm { lqc2         $vf5, 0xBD0+var_210($sp) }
      _$A0 += 16;
      __asm
      {
        lqc2         $vf4, 0xBD0+var_200($sp)
        lqc2         $vf2, 0xBD0+var_1F0($sp)
        lqc2         $vf1, 0xBD0+var_1E0($sp)
        vmulax.xyz   $A, $vf5, $vf3
        vmadday.xyz  $A, $vf4, $vf3
        vmaddaz.xyz  $A, $vf2, $vf3
        vmaddw.xyz   $vf3, $vf1, $vf0
        sqc2         $vf3, 0($v0)
      }
      v32 += 16;
    }
    while ( v30 );
    __asm { lqc2         $vf2, 0x140($s0) }
  }
  else
  {
    __asm { lqc2         $vf2, 0x140($s0) }
  }
  __asm
  {
    lqc2         $vf1, 0x10($s0)
    vsub.xyz     $vf5, $vf1, $vf2
    lqc2         $vf4, 0xBD0+var_D0($sp)
    vmul.xyz     $vf1, $vf5, $vf5
    lqc2         $vf3, 0x60($s0)
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf4, $vf1
    lqc2         $vf2, 0x190($s0)
    vsub.xyz     $vf2, $vf2, $vf3
    qmfc2        $v0, $vf1
    vmul.xyz     $vf1, $vf2, $vf2
    vadday.x     $A, $vf1, $vf1
    vmaddz.x     $vf1, $vf4, $vf1
    vmove.xyzw   $vf4, $vf2
    vnop
    vnop
    vnop
    vrsqrt       $Q, $vf0.w, $vf1.x
    vwaitq
    vmulq.xyz    $vf4, $vf4, $Q
    vmove.xyzw   $vf3, $vf4
  }
  if ( *&_$V0 >= 2.3283064e-10 )
  {
    __asm
    {
      vmul.xyz     $vf2, $vf5, $vf5
      lqc2         $vf6, 0xBD0+var_D0($sp)
      vadday.x     $A, $vf2, $vf2
      vmaddz.x     $vf2, $vf6, $vf2
      vaddw.x      $vf3, $vf0, $vf0
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf2.x
      vwaitq
      vmulq.xyz    $vf5, $vf5, $Q
      vmove.xyzw   $vf2, $vf5
      vmul.xyz     $vf1, $vf2, $vf4
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf3, $vf1
      qmfc2        $v0, $vf1
      vmove.xyzw   $vf3, $vf2
    }
    if ( *&_$V0 <= 0.80000001 )
      __asm { vmove.xyzw   $vf3, $vf4 }
  }
  __asm
  {
    lqc2         $vf4, 0x70($s0)
    vsub.xyz     $vf5, $vf0, $vf3
    lqc2         $vf2, 0x10($s4)
    lqc2         $vf1, 0x20($s4)
    vmulax.xyz   $A, $vf4, $vf3
    vmadday.xyz  $A, $vf2, $vf3
    vmaddz.xyz   $vf6, $vf1, $vf3
    sqc2         $vf6, 0xBD0+var_100($sp)
    lqc2         $vf3, 0x1A0($s0)
    lqc2         $vf2, 0x10($s3)
    lqc2         $vf1, 0x20($s3)
    vmulax.xyz   $A, $vf3, $vf5
    vmadday.xyz  $A, $vf2, $vf5
    vmaddz.xyz   $vf4, $vf1, $vf5
    lq           $a2, 0xBD0+var_100($sp) # $A2
    sqc2         $vf4, 0xBD0+var_F0($sp)
  }
  BuildClippedEdgeList__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dPUiGQ29GtMathPs26CGtV3dPC13CB4ConvexHullT1(
    &v76,
    v86,
    _$A2,
    *_$S0,
    v74);
  v36 = ClipEdgesByHull__20CB4CollisionDetectorPQ29GtMathPs26CGtV3diT1UiPQ29GtMathPs28CGtPlaneUi(
          &v77,
          64LL,
          &v76,
          v86[0],
          v91,
          *(_$S0[76] + 25));
  v37 = v36;
  if ( v36 )
  {
    v39 = &v77;
    if ( v36 > 0 )
    {
      _$V1 = &v77;
      do
      {
        __asm { lqc2         $vf3, 0($v1) }
        v36 = v36 - 1;
        __asm { lqc2         $vf5, 0xBD0+var_210($sp) }
        _$V1 = (_$V1 + 16);
        __asm
        {
          lqc2         $vf4, 0xBD0+var_200($sp)
          lqc2         $vf2, 0xBD0+var_1F0($sp)
          lqc2         $vf1, 0xBD0+var_1E0($sp)
          vmulax.xyz   $A, $vf5, $vf3
          vmadday.xyz  $A, $vf4, $vf3
          vmaddaz.xyz  $A, $vf2, $vf3
          vmaddw.xyz   $vf3, $vf1, $vf0
          sqc2         $vf3, 0($a0)
        }
        v39 = (v39 + 16);
      }
      while ( v36 );
    }
    v38 = v94;
  }
  else
  {
    v38 = v94;
  }
  __asm { lq           $a2, 0xBD0+var_F0($sp) # $A2 }
  BuildClippedEdgeList__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dPUiGQ29GtMathPs26CGtV3dPC13CB4ConvexHullT1(
    &v76,
    v86,
    _$A2,
    _$S0[76],
    v38);
  v42 = (v37
       + ClipEdgesByHull__20CB4CollisionDetectorPQ29GtMathPs26CGtV3diT1UiPQ29GtMathPs28CGtPlaneUi(
           &v77 + 16 * v37,
           64 - v37,
           &v76,
           v86[0],
           v90,
           *(*_$S0 + 25)));
  result = 0LL;
  if ( v42 >= 2 )
  {
    v44 = 0.0;
    GetAveragePoint__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dPCQ29GtMathPs26CGtV3di(&v87, &v77, v42);
    __asm
    {
      lq           $a1, 0xBD0+var_140($sp) # $A1
      lq           $a2, 0xBD0+var_100($sp) # $A2
    }
    CollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d = GetCollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d(_$S0, _$A1, _$A2);
    if ( CollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d == -1 )
    {
      __asm
      {
        vadd.xyz     $vf9, $vf0, $vf0
        sqc2         $vf9, 0xBD0+var_1D0($sp)
        vmove.xyzw   $vf7, $vf9
      }
    }
    else
    {
      __asm { lqc2         $vf4, 0x30($s0) }
      _$V0 = 16
           * CollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d
           + v90;
      __asm
      {
        lqc2         $vf3, 0x10($s5)
        lqc2         $vf1, 0x20($s5)
        lqc2         $vf6, 0x30($s5)
        lqc2         $vf5, 0($v0)
        lqc2         $vf2, 0xBD0+var_130($sp)
        vmulax.xyz   $A, $vf4, $vf5
        vmadday.xyz  $A, $vf3, $vf5
        vmaddz.xyz   $vf9, $vf1, $vf5
        vmulax.xyz   $A, $vf4, $vf2
        vmadday.xyz  $A, $vf3, $vf2
        vmaddaz.xyz  $A, $vf1, $vf2
        vmaddw.xyz   $vf7, $vf6, $vf0
      }
      v44 = 1.0;
    }
    if ( v42 > 0 )
    {
      _$A0 = &v77;
      LODWORD(v50) = v42;
      do
      {
        __asm { lqc2         $vf3, 0($a0) }
        v50 = v50 - 1;
        __asm
        {
          lqc2         $vf5, 0xBD0+var_250($sp)
          lqc2         $vf4, 0xBD0+var_240($sp)
          lqc2         $vf2, 0xBD0+var_230($sp)
          lqc2         $vf1, 0xBD0+var_220($sp)
          vmulax.xyz   $A, $vf5, $vf3
          vmadday.xyz  $A, $vf4, $vf3
          vmaddaz.xyz  $A, $vf2, $vf3
          vmaddw.xyz   $vf3, $vf1, $vf0
          sqc2         $vf3, 0($a0)
        }
        _$A0 = (_$A0 + 16);
      }
      while ( v50 );
    }
    __asm
    {
      lqc2         $vf2, 0xBD0+var_140($sp)
      lqc2         $vf5, 0xBD0+var_250($sp)
      lqc2         $vf4, 0xBD0+var_240($sp)
      lqc2         $vf3, 0xBD0+var_230($sp)
      lqc2         $vf1, 0xBD0+var_220($sp)
      vmulax.xyz   $A, $vf5, $vf2
      vmadday.xyz  $A, $vf4, $vf2
      vmaddaz.xyz  $A, $vf3, $vf2
      vmaddw.xyz   $vf2, $vf1, $vf0
      lq           $a2, 0xBD0+var_F0($sp) # $A2
      sqc2         $vf7, 0xBD0+var_C0($sp)
      sqc2         $vf9, 0xBD0+var_B0($sp)
      qmfc2        $a1, $vf2 # $A1
      sqc2         $vf2, 0xBD0+var_140($sp)
    }
    v53 = GetCollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d(
            (_$S0 + 76),
            _$A1,
            _$A2);
    __asm
    {
      lqc2         $vf7, 0xBD0+var_C0($sp)
      lqc2         $vf9, 0xBD0+var_B0($sp)
    }
    if ( CollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d == -1 )
    {
      v54 = v91;
      if ( v53 == -1 )
      {
        result = 0LL;
        goto LABEL_49;
      }
    }
    else
    {
      v54 = v91;
      if ( v53 == -1 )
      {
        __asm
        {
          vadd.xyz     $vf1, $vf0, $vf0
          sqc2         $vf1, 0xBD0+var_1D0($sp)
          vmove.xyzw   $vf11, $vf1
        }
        goto LABEL_41;
      }
    }
    __asm
    {
      lqc2         $vf5, 0x160($s0)
      lqc2         $vf4, 0x10($s7)
    }
    _$V0 = 16 * v53 + v54;
    __asm
    {
      lqc2         $vf3, 0x20($s7)
      lqc2         $vf6, 0x30($s7)
      lqc2         $vf1, 0xBD0+var_120($sp)
      vmulax.xyz   $A, $vf5, $vf1
      vmadday.xyz  $A, $vf4, $vf1
      vmaddaz.xyz  $A, $vf3, $vf1
      vmaddw.xyz   $vf1, $vf6, $vf0
      lqc2         $vf2, 0($v0)
      vadd.xyz     $vf7, $vf7, $vf1
      vmulax.xyz   $A, $vf5, $vf2
      vmadday.xyz  $A, $vf4, $vf2
      vmaddz.xyz   $vf11, $vf3, $vf2
    }
    v44 = v44 + 1.0;
LABEL_41:
    __asm
    {
      vsub.xyz     $vf3, $vf9, $vf11
      sqc2         $vf3, 0x270($s0)
      vmul.xyz     $vf1, $vf3, $vf3
      lqc2         $vf4, 0x1A0($s0)
    }
    _$V0 = COERCE_INT(1.0 / v44);
    LODWORD(v57) = 0;
    __asm
    {
      lqc2         $vf2, 0xBD0+var_D0($sp)
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf2, $vf1
    }
    v58 = 0.0;
    __asm
    {
      qmtc2        $v0, $vf2
      vnop
      vnop
      vnop
      vrsqrt       $Q, $vf0.w, $vf1.x
      vwaitq
      vmulq.xyz    $vf3, $vf3, $Q
      vmulx.xyz    $vf7, $vf7, $vf2
      sqc2         $vf3, 0x270($s0)
      sqc2         $vf7, 0x280($s0)
    }
    v59 = 0.0;
    __asm
    {
      lqc2         $vf2, 0x10($s3)
      lqc2         $vf1, 0x20($s3)
      vmulax.xyz   $A, $vf4, $vf3
      vmadday.xyz  $A, $vf2, $vf3
      vmaddz.xyz   $vf1, $vf1, $vf3
      lqc2         $vf4, 0xBD0+var_140($sp)
      vaddw.x      $vf2, $vf0, $vf0
      vmove.xyzw   $vf3, $vf1
    }
    _$V1 = &v77;
    do
    {
      __asm
      {
        lqc2         $vf1, 0($v1)
        vsub.xyz     $vf1, $vf4, $vf1
        vmul.xyz     $vf1, $vf1, $vf3
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf2, $vf1
        qmfc2        $v0, $vf1
      }
      if ( v58 >= *&_$V0 )
      {
        if ( *&_$V0 < v59 )
          v59 = *&_$V0;
      }
      else
      {
        v58 = *&_$V0;
      }
      v57 = v57 + 1;
      _$V1 = (_$V1 + 16);
    }
    while ( v57 < v42 );
    _$V0 = COERCE_INT(v59 - v58);
    __asm
    {
      lqc2         $vf3, 0x270($s0)
      qmtc2        $v0, $vf2
    }
    _$V1 = COERCE_INT(0.5);
    __asm
    {
      qmtc2        $v1, $vf1
      vmulx.xyz    $vf3, $vf3, $vf2
      lqc2         $vf2, 0x30($s0)
      vmulx.xyz    $vf3, $vf3, $vf1
      lqc2         $vf7, 0x40($s0)
      vsub.xyz     $vf8, $vf0, $vf3
      lqc2         $vf6, 0x50($s0)
      lqc2         $vf4, 0x60($s0)
    }
    result = 1LL;
    __asm
    {
      lqc2         $vf1, 0x190($s0)
      vadd.xyz     $vf4, $vf4, $vf3
      lq           $v1, 0x280($s0)
      vsub.xyz     $vf1, $vf1, $vf3
      sqc2         $vf7, 0x80($s0)
      sqc2         $vf6, 0x90($s0)
      sqc2         $vf2, 0x70($s0)
      sqc2         $vf9, 0xC0($s0)
      sqc2         $vf8, 0x200($s0)
      sqc2         $vf4, 0x60($s0)
      sqc2         $vf3, 0xD0($s0)
      sqc2         $vf4, 0xA0($s0)
      sqc2         $vf11, 0x1F0($s0)
      sqc2         $vf1, 0x190($s0)
      sq           $v1, 0x1E0($s0)
      vmove.xyzw   $vf10, $vf7
      sq           $v1, 0xB0($s0)
      vmove.xyzw   $vf9, $vf6
      vaddz.x      $vf9, $vf0, $vf2
      vaddy.x      $vf10, $vf0, $vf2
      vmove.xyzw   $vf5, $vf2
      lqc2         $vf2, 0x10($s4)
      vaddx.y      $vf5, $vf0, $vf2
      lqc2         $vf1, 0x20($s4)
      vmove.xyzw   $vf3, $vf5
      vmove.xyzw   $vf6, $vf9
      vaddx.z      $vf3, $vf0, $vf1
      vmove.xyzw   $vf7, $vf10
      vaddz.y      $vf6, $vf0, $vf2
      vaddy.z      $vf7, $vf0, $vf1
      sqc2         $vf5, 0x70($s0)
      vmuly.xyz    $vf2, $vf7, $vf4
      vmulx.xyz    $vf1, $vf3, $vf4
      vmulz.xyz    $vf4, $vf6, $vf4
      vadd.xyz     $vf1, $vf1, $vf2
      sqc2         $vf9, 0x90($s0)
      vadd.xyz     $vf1, $vf1, $vf4
      sqc2         $vf10, 0x80($s0)
      vsub.xyz     $vf1, $vf0, $vf1
      sqc2         $vf3, 0x70($s0)
      sqc2         $vf7, 0x80($s0)
      sqc2         $vf6, 0x90($s0)
      sqc2         $vf1, 0x30($s4)
      lqc2         $vf2, 0x160($s0)
      lqc2         $vf1, 0x170($s0)
      lqc2         $vf3, 0x180($s0)
      sqc2         $vf2, 0x1A0($s0)
      vmove.xyzw   $vf9, $vf1
      sqc2         $vf1, 0x1B0($s0)
      vaddy.x      $vf9, $vf0, $vf2
      vmove.xyzw   $vf8, $vf3
      sqc2         $vf3, 0x1C0($s0)
      vaddz.x      $vf8, $vf0, $vf2
      vmove.xyzw   $vf4, $vf2
      lqc2         $vf2, 0x190($s0)
      vmove.xyzw   $vf7, $vf9
      vmove.xyzw   $vf6, $vf8
      sqc2         $vf2, 0x1D0($s0)
      lqc2         $vf3, 0x10($s3)
      vaddx.y      $vf4, $vf0, $vf3
      lqc2         $vf1, 0x20($s3)
      vmove.xyzw   $vf5, $vf4
      vaddy.z      $vf7, $vf0, $vf1
      vaddz.y      $vf6, $vf0, $vf3
      vaddx.z      $vf5, $vf0, $vf1
      vmulx.xyz    $vf1, $vf5, $vf2
      vmuly.xyz    $vf3, $vf7, $vf2
      vmulz.xyz    $vf2, $vf6, $vf2
      vadd.xyz     $vf1, $vf1, $vf3
      sqc2         $vf4, 0x1A0($s0)
      vadd.xyz     $vf1, $vf1, $vf2
      sqc2         $vf9, 0x1B0($s0)
      vsub.xyz     $vf1, $vf0, $vf1
      sqc2         $vf8, 0x1C0($s0)
      sqc2         $vf5, 0x1A0($s0)
      sqc2         $vf7, 0x1B0($s0)
      sqc2         $vf6, 0x1C0($s0)
      sqc2         $vf1, 0x30($s3)
    }
    _$S0[153] = 1;
  }
LABEL_49:
  __asm
  {
    lq           $s0, 0xBD0+var_10($sp)
    lq           $s1, 0xBD0+var_20($sp)
    lq           $s2, 0xBD0+var_30($sp)
    lq           $s3, 0xBD0+var_40($sp)
    lq           $s4, 0xBD0+var_50($sp)
    lq           $s5, 0xBD0+var_60($sp)
    lq           $s6, 0xBD0+var_70($sp)
    lq           $s7, 0xBD0+var_80($sp)
    lq           $fp, 0xBD0+var_90($sp)
  }
  return result;
}

// CB4CollisionDetector::BuildClippedEdgeList(GtMathPs2::CGtV3d *, unsigned int *, GtMathPs2::CGtV3d, const CB4ConvexHull *, GtMathPs2::CGtV3d *)
__int64 __fastcall BuildClippedEdgeList__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dPUiGQ29GtMathPs26CGtV3dPC13CB4ConvexHullT1(
        __int64 a1,
        int *a2,
        __int64 _$A2,
        int a4,
        int a5)
{
  unsigned __int64 v6; // $a5
  int v7; // $a7
  unsigned __int64 v8; // $a2
  _DWORD *v10; // $a1
  __int64 result; // $v0
  unsigned __int64 v13; // $a5
  int i; // $v1
  unsigned __int8 v15; // $a0
  int v16; // $v1
  int v20; // $a0
  _DWORD v22[16]; // [sp+0h] [-50h] BYREF
  unsigned __int8 v23; // [sp+40h] [-10h]
  unsigned __int8 v24; // [sp+41h] [-Fh]

  LODWORD(v6) = 0;
  if ( *(a4 + 24) )
  {
    __asm { qmtc2        $a2, $vf3 }
    v7 = *(a4 + 8);
    v8 = *(a4 + 24);
    __asm { vaddw.x      $vf2, $vf0, $vf0 }
    do
    {
      _$V0 = 16 * v6 + v7;
      __asm { lqc2         $vf1, 0($v0) }
      v10 = &v22[v6];
      __asm { vmul.xyz     $vf1, $vf3, $vf1 }
      v6 = (v6 + 1);
      __asm
      {
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf2, $vf1
        qmfc2        $v0, $vf1
      }
      *v10 = _$V0;
    }
    while ( v6 < v8 );
  }
  *a2 = 0;
  result = *(a4 + 26);
  LODWORD(v13) = 0;
  if ( *(a4 + 26) )
  {
    for ( i = *(a4 + 12); ; i = *(a4 + 12) )
    {
      v15 = *(2 * v13 + i + 1);
      v23 = *(2 * v13 + i);
      v24 = v15;
      v16 = 16 * v23;
      if ( *&v22[v23] >= 0.0 || (v16 = 16 * v23, *&v22[v24] >= 0.0) )
      {
        _$V1 = v16 + a5;
        __asm { lq           $a1, 0($v1) }
        _$A2 = 16 * v24 + a5;
        v20 = *a2 + 1;
        __asm { sq           $a1, 0($v0) }
        *a2 = v20;
        __asm
        {
          lq           $v0, 0($a2)
          sq           $v0, 0($v1)
        }
        *a2 = v20 + 1;
      }
      v13 = (v13 + 1);
      result = v13 < *(a4 + 26);
      if ( v13 >= *(a4 + 26) )
        break;
    }
  }
  return result;
}

// CB4CollisionDetector::GetAveragePoint(GtMathPs2::CGtV3d *, const GtMathPs2::CGtV3d *, int)
__int64 __fastcall GetAveragePoint__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dPCQ29GtMathPs26CGtV3di(
        __int64 a1,
        int _$A1,
        __int64 a3)
{
  __int64 v4; // $v0
  __int64 result; // $v0

  __asm
  {
    lqc2         $vf3, 0($a1)
    vmove.xyzw   $vf2, $vf3
  }
  if ( a3 > 1 )
  {
    _$A1 = _$A1 + 16;
    LODWORD(v4) = a3 - 1;
    do
    {
      __asm { lqc2         $vf1, 0($a1) }
      v4 = v4 - 1;
      __asm
      {
        vmax.xyz     $vf2, $vf2, $vf1
        vmini.xyz    $vf3, $vf3, $vf1
      }
      _$A1 += 16;
    }
    while ( v4 );
  }
  __asm { vadd.xyz     $vf1, $vf3, $vf2 }
  result = COERCE_INT(0.5);
  __asm
  {
    sqc2         $vf1, 0($a0)
    qmtc2        $v0, $vf2
    vmulx.xyz    $vf1, $vf1, $vf2
    sqc2         $vf1, 0($a0)
  }
  return result;
}

// CB4CollisionDetector::GetAveragePoint(GtMathPs2::CGtV3d *, GtMathPs2::CGtV3d *, GtMathPs2::CGtV3d *, const GtMathPs2::CGtV3d *, int)
__int64 __fastcall GetAveragePoint__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dN21PCQ29GtMathPs26CGtV3di(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int _$A3,
        __int64 a5)
{
  __int64 v6; // $v0
  __int64 result; // $v0

  __asm
  {
    lqc2         $vf2, 0($a3)
    vmove.xyzw   $vf3, $vf2
  }
  if ( a5 > 1 )
  {
    _$A3 = _$A3 + 16;
    LODWORD(v6) = a5 - 1;
    do
    {
      __asm { lqc2         $vf1, 0($a3) }
      v6 = v6 - 1;
      __asm
      {
        vmax.xyz     $vf3, $vf3, $vf1
        vmini.xyz    $vf2, $vf2, $vf1
      }
      _$A3 += 16;
    }
    while ( v6 );
  }
  __asm
  {
    sqc2         $vf2, 0($a1)
    vadd.xyz     $vf1, $vf2, $vf3
    sqc2         $vf3, 0($a2)
  }
  result = COERCE_INT(0.5);
  __asm
  {
    sqc2         $vf1, 0($a0)
    qmtc2        $v0, $vf2
    vmulx.xyz    $vf1, $vf1, $vf2
    sqc2         $vf1, 0($a0)
  }
  return result;
}

// CB4CollisionDetector::DoCollideHullTriangles(CB4HullWorldTriCollideParams *, CB4ConvexHullCollideInfo *)
__int64 __fastcall DoCollideHullTriangles__20CB4CollisionDetectorP28CB4HullWorldTriCollideParamsP24CB4ConvexHullCollideInfo(
        unsigned int a1,
        _DWORD *a2)
{
  __int64 v11; // $ra
  __int64 v14; // $v0
  bool v15; // dc
  int v19; // $s5
  int *v24; // $s1
  __int64 v29; // $s3
  int i; // $v1
  int v31; // $s0
  __int64 v32; // $fp
  __int64 v33; // $v0
  int v34; // $v0
  __int64 v35; // $a1
  _BYTE *v37; // $a0
  __int64 v39; // $a4
  float v45; // $f1
  __int64 v52; // $a0
  __int128 *v53; // $v0
  int v58; // $f0
  __int64 result; // $v0
  __int128 v74; // [sp+0h] [-410h] BYREF
  _BYTE v77[512]; // [sp+40h] [-3D0h] BYREF
  _DWORD v78[8]; // [sp+250h] [-1C0h] BYREF
  _BYTE v79[48]; // [sp+270h] [-1A0h] BYREF
  __int128 v80; // [sp+2A0h] [-170h] BYREF
  __int128 v81; // [sp+2B0h] [-160h] BYREF
  __int128 v82; // [sp+2C0h] [-150h] BYREF
  __int128 v83; // [sp+2D0h] [-140h] BYREF
  __int128 v84; // [sp+2E0h] [-130h] BYREF
  int v89; // [sp+330h] [-E0h]
  __int16 v90; // [sp+334h] [-DCh]
  int *v92; // [sp+350h] [-C0h]
  __int64 v94; // [sp+370h] [-A0h]

  __asm
  {
    sq           $s2, 0x410+var_30($sp)
    vadd.xyz     $vf1, $vf0, $vf0
    sq           $s4, 0x410+var_50($sp)
    sq           $s0, 0x410+var_10($sp)
  }
  _$S4 = a1;
  __asm
  {
    sq           $s1, 0x410+var_20($sp)
    sq           $s3, 0x410+var_40($sp)
    sq           $s5, 0x410+var_60($sp)
    sq           $s6, 0x410+var_70($sp)
    sq           $s7, 0x410+var_80($sp)
    sq           $fp, 0x410+var_90($sp)
  }
  v94 = v11;
  v14 = 30LL;
  do
  {
    v15 = v14 != -1;
    v14 = v14 - 1;
  }
  while ( v15 );
  _$V0 = &kLarge_0;
  __asm { lq           $v0, (kLarge_0 - 0x1C71400)($v0) }
  _$V1 = &kSmall_0;
  v19 = 0;
  __asm { sq           $v0, 0x410+var_100($sp) }
  v89 = *(*a1 + 4);
  __asm
  {
    lq           $v1, (kSmall_0 - 0x1C713F0)($v1)
    sqc2         $vf1, 0x410+var_120($sp)
    sq           $v1, 0x410+var_110($sp)
  }
  a2[1201] = -1;
  __asm
  {
    lq           $v0, 0x410+var_120($sp)
    sq           $v0, 0x410+var_F0($sp)
  }
  a2[1196] = a1;
  a2[1192] = 0;
  a2[1193] = 0;
  a2[1200] = 0;
  __asm { sqc2         $vf1, 0x410+var_1D0($sp) }
  LODWORD(_$V0) = *a1;
  a2[1194] = a1;
  a2[1198] = _$V0;
  __asm { sqc2         $vf1, 0xD0($s4) }
  _$A0 = a2[1196];
  __asm { lq           $v1, 0x70($a0) }
  v24 = *(a2[1194] + 304);
  __asm
  {
    sq           $v1, 0x410+var_410($sp)
    lq           $v0, 0x80($a0)
    sq           $v0, 0x410+var_400($sp)
    lq           $v1, 0x90($a0)
    sq           $v1, 0x410+var_3F0($sp)
    lq           $v1, 0x410+var_120($sp)
    lq           $v0, 0xA0($a0)
    sq           $v1, 0x410+var_140($sp)
    sq           $v0, 0x410+var_3E0($sp)
    sq           $v1, 0x410+var_1D0($sp)
  }
  v29 = 0LL;
  if ( *v24 > 0LL )
  {
    v92 = v78;
    for ( i = *_$S4; ; i = *_$S4 )
    {
      v31 = v19 << 6;
      v32 = v19 + 1;
      v33 = 1LL;
      do
      {
        v15 = v33 != -1;
        v33 = v33 - 1;
      }
      while ( v15 );
      v34 = *(i + 25);
      LODWORD(v35) = 2;
      _$V1 = &v74;
      v78[0] = v34;
      v78[1] = v89;
      v37 = v79;
      _$V0 = v31 + v24[1];
      do
      {
        __asm { lqc2         $vf3, 0($v0) }
        v35 = v35 - 1;
        __asm { lqc2         $vf5, 0($v1) }
        _$V0 += 16;
        __asm
        {
          lqc2         $vf4, 0x10($v1)
          lqc2         $vf2, 0x20($v1)
          lqc2         $vf1, 0x30($v1)
          vmulax.xyz   $A, $vf5, $vf3
          vmadday.xyz  $A, $vf4, $vf3
          vmaddaz.xyz  $A, $vf2, $vf3
          vmaddw.xyz   $vf3, $vf1, $vf0
          sqc2         $vf3, 0($a0)
        }
        v37 += 16;
      }
      while ( v35 >= 0 );
      v39 = ClipPolyWithConvexHull__14GtIntersectionPCQ29GtMathPs26CGtV3diRC13CGtConvexHullPQ29GtMathPs26CGtV3d(
              v79,
              3LL,
              v92,
              v77);
      if ( v39 )
      {
        __asm { lqc2         $vf4, 0x410+var_410($sp) }
        _$V0 = v31 + v24[1];
        __asm
        {
          lqc2         $vf3, 0x410+var_400($sp)
          lqc2         $vf2, 0x30($v0)
          lqc2         $vf1, 0x410+var_3F0($sp)
          vmulax.xyz   $A, $vf4, $vf2
          vmadday.xyz  $A, $vf3, $vf2
          vmaddz.xyz   $vf2, $vf1, $vf2
        }
        v29 = v29 + 1;
        __asm { sqc2         $vf2, 0x410+var_B0($sp) }
        GetAveragePoint__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dN21PCQ29GtMathPs26CGtV3di(&v80, &v81, &v82, v77, v39);
        __asm
        {
          lqc2         $vf3, 0x410+var_170($sp)
          lqc2         $vf4, 0x410+var_120($sp)
          lqc2         $vf2, 0x410+var_B0($sp)
          vadd.xyz     $vf4, $vf4, $vf3
          vsub.xyz     $vf1, $vf0, $vf2
          sqc2         $vf4, 0x410+var_120($sp)
          qmfc2        $a2, $vf1 # $A2
          lqc2         $vf1, 0x410+var_140($sp)
          vadd.xyz     $vf1, $vf1, $vf2
          qmfc2        $a1, $vf3 # $A1
          sqc2         $vf1, 0x410+var_140($sp)
        }
        _$V1 = COERCE_INT(GetHullPenetration__20CB4CollisionDetectorP13CB4ConvexHullGQ29GtMathPs26CGtV3dT2(a2[1198], _$A1, _$A2));
        __asm
        {
          qmtc2        $v1, $vf2
          lqc2         $vf6, 0x410+var_F0($sp)
        }
        _$A0 = v31 + v24[1];
        __asm
        {
          lqc2         $vf1, 0x30($a0)
          vmulx.xyz    $vf1, $vf1, $vf2
          lqc2         $vf3, 0x410+var_160($sp)
          vadd.xyz     $vf6, $vf6, $vf1
          lqc2         $vf1, 0x410+var_100($sp)
          vmini.xyz    $vf1, $vf1, $vf3
          lqc2         $vf2, 0x410+var_150($sp)
          lqc2         $vf3, 0x410+var_110($sp)
          vmax.xyz     $vf3, $vf3, $vf2
          sqc2         $vf6, 0x410+var_F0($sp)
          sqc2         $vf1, 0x410+var_100($sp)
          sqc2         $vf3, 0x410+var_110($sp)
        }
        v90 = *(2 * v19 + v24[2]);
      }
      ++v19;
      if ( v32 >= *v24 )
        break;
    }
  }
  if ( v29 )
  {
    if ( v29 < 0 )
      v45 = (v29 & 1 | (v29 >> 1)) + (v29 & 1 | (v29 >> 1));
    else
      v45 = v29;
    __asm
    {
      vaddw.x      $vf3, $vf0, $vf0
      lqc2         $vf2, 0x410+var_140($sp)
      lqc2         $vf6, 0x410+var_120($sp)
    }
    _$V1 = COERCE_INT(1.0 / v45);
    __asm
    {
      qmtc2        $v1, $vf1
      vmulx.xyz    $vf4, $vf2, $vf1
      vmulx.xyz    $vf6, $vf6, $vf1
      vmul.xyz     $vf2, $vf4, $vf4
      sqc2         $vf6, 0x410+var_D0($sp)
      vadday.x     $A, $vf2, $vf2
      vmaddz.x     $vf1, $vf3, $vf2
      sqc2         $vf4, 0x410+var_140($sp)
      qmfc2        $v0, $vf1
      por          $s0, $zero, $v1
    }
    if ( *&_$V0 >= 0.022500001 )
    {
      __asm { vmove.xyzw   $vf2, $vf4 }
      *(_$S4 + 336) = 0;
      __asm
      {
        vnop
        vnop
        vnop
        vrsqrt       $Q, $vf0.w, $vf1.x
        vwaitq
        vmulq.xyz    $vf2, $vf2, $Q
        por          $s0, $zero, $v1
        sqc2         $vf2, 0x410+var_140($sp)
      }
      _$V1 = a2[1196] + 48;
      __asm
      {
        lqc2         $vf4, 0x30($v0)
        lqc2         $vf3, 0x20($v1)
        lqc2         $vf1, 0x10($v1)
        vmulax.xyz   $A, $vf4, $vf2
        vmadday.xyz  $A, $vf1, $vf2
        vmaddz.xyz   $vf2, $vf3, $vf2
        sqc2         $vf2, 0xC0($v0)
      }
    }
    else
    {
      __asm { lq           $v0, 0x140($s4) }
      _$A1 = &v83;
      _$V1 = &v74;
      __asm { sq           $v0, 0x410+var_140($sp) }
      LODWORD(v52) = 0;
      v53 = &v84;
      do
      {
        __asm { lqc2         $vf3, 0($a1) }
        v52 = v52 - 1;
        __asm { lqc2         $vf4, 0($v1) }
        ++_$A1;
        __asm
        {
          lqc2         $vf2, 0x10($v1)
          lqc2         $vf1, 0x20($v1)
          vmulax.xyz   $A, $vf4, $vf3
          vmadday.xyz  $A, $vf2, $vf3
          vmaddz.xyz   $vf3, $vf1, $vf3
          sqc2         $vf3, 0($v0)
        }
        ++v53;
      }
      while ( v52 >= 0 );
      __asm { lq           $v1, 0x410+var_140($sp) }
      *(_$S4 + 336) = 1;
      __asm
      {
        lq           $a1, 0x410+var_D0($sp) # $A1
        sq           $v1, 0xC0($v0)
        lq           $a2, 0x410+var_130($sp) # $A2
      }
      _$V0 = COERCE_INT(GetHullPenetration__20CB4CollisionDetectorP13CB4ConvexHullGQ29GtMathPs26CGtV3dT2(a2[1198], _$A1, _$A2));
      __asm
      {
        lqc2         $vf2, 0x410+var_140($sp)
        qmtc2        $v0, $vf1
        vmulx.xyz    $vf2, $vf2, $vf1
      }
      if ( v29 < 0 )
        *&v58 = (v29 & 1 | (v29 >> 1)) + (v29 & 1 | (v29 >> 1));
      else
        *&v58 = v29;
      _$V0 = v58;
      __asm
      {
        qmtc2        $v0, $vf1
        vmulx.xyz    $vf3, $vf2, $vf1
        sqc2         $vf3, 0x410+var_F0($sp)
      }
    }
    __asm
    {
      qmtc2        $s0, $vf5
      lqc2         $vf4, 0x410+var_F0($sp)
    }
    result = 1LL;
    _$V1 = a2[1196] + 48;
    __asm
    {
      vmulx.xyz    $vf5, $vf4, $vf5
      lqc2         $vf4, 0x30($v1)
      lqc2         $vf3, 0x10($v1)
      lqc2         $vf1, 0x20($v1)
      lqc2         $vf2, 0x30($a0)
      lqc2         $vf6, 0x410+var_D0($sp)
      vmulax.xyz   $A, $vf2, $vf6
      vmadday.xyz  $A, $vf3, $vf6
      vmaddaz.xyz  $A, $vf1, $vf6
      vmaddw.xyz   $vf2, $vf4, $vf0
      sqc2         $vf2, 0xB0($a0)
    }
    *(a2[1196] + 224) = v90;
    __asm
    {
      sqc2         $vf5, 0xD0($a0)
      lq           $v1, 0x410+var_110($sp)
      sq           $v1, 0x170($s4)
      lq           $a0, 0x410+var_100($sp)
      sq           $a0, 0x160($s4)
    }
  }
  else
  {
    *(_$S4 + 336) = 0;
    result = 0LL;
  }
  __asm
  {
    lq           $s0, 0x410+var_10($sp)
    lq           $s1, 0x410+var_20($sp)
    lq           $s2, 0x410+var_30($sp)
    lq           $s3, 0x410+var_40($sp)
    lq           $s4, 0x410+var_50($sp)
    lq           $s5, 0x410+var_60($sp)
    lq           $s6, 0x410+var_70($sp)
    lq           $s7, 0x410+var_80($sp)
    lq           $fp, 0x410+var_90($sp)
  }
  return result;
}

// CB4CollisionDetector::DoCollideConvexHullToHull(CB4HullCollideParams *)
float __fastcall GetHullPenetration__20CB4CollisionDetectorP13CB4ConvexHullGQ29GtMathPs26CGtV3dT2(
        int a1,
        __int64 _$A1,
        __int64 _$A2)
{
  __int64 v4; // $v1
  __int64 v5; // $a1
  float v8; // $f2
  float v10; // $f2
  float v14; // [sp+Ch] [-4h]

  __asm { qmtc2        $a2, $vf2 }
  _$V0 = COERCE_INT(100.0);
  __asm
  {
    qmtc2        $a1, $vf4
    qmtc2        $v0, $vf1
  }
  v4 = *(a1 + 25);
  __asm { vmulx.xyz    $vf3, $vf2, $vf1 }
  LODWORD(_$A2) = 0;
  __asm { vadd.xyz     $vf3, $vf3, $vf4 }
  v5 = 0LL;
  if ( *(a1 + 25) )
  {
    _$A0 = *(a1 + 4);
    __asm
    {
      vmove.xyzw   $vf6, $vf4
      vaddw.x      $vf5, $vf0, $vf0
    }
    do
    {
      __asm
      {
        lqc2         $vf2, 0($a0)
        vmul.xyz     $vf1, $vf3, $vf2
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf5, $vf1
        sqc2         $vf2, 0x10+var_10($sp)
        qmfc2        $v0, $vf1
      }
      v8 = *&_$V0;
      if ( v14 <= *&_$V0 )
      {
        __asm { lqc2         $vf2, 0($a0) }
        v5 = 1LL;
        __asm
        {
          vmul.xyz     $vf1, $vf6, $vf2
          vadday.x     $A, $vf1, $vf1
          vmaddz.x     $vf1, $vf5, $vf1
          sqc2         $vf2, 0x10+var_10($sp)
          qmfc2        $v0, $vf1
        }
        if ( v14 <= *&_$V0 )
          return 0.0;
        v10 = v8 - *&_$V0;
        if ( fabsf(v10) > 0.000099999997 )
        {
          _$V0 = _$V0;
          __asm
          {
            lqc2         $vf1, 0($a0)
            qmtc2        $v0, $vf2
            vsub.xyz     $vf3, $vf3, $vf4
            vsubx.w      $vf1, $vf1, $vf2
            sqc2         $vf1, 0x10+var_10($sp)
          }
          _$V0 = COERCE_INT(v14 / v10);
          __asm
          {
            qmtc2        $v0, $vf1
            vmulx.xyz    $vf3, $vf3, $vf1
            vadd.xyz     $vf3, $vf4, $vf3
          }
        }
        _$A2 = _$A2 + 1;
      }
      else
      {
        _$A2 = _$A2 + 1;
      }
      _$A0 += 16;
    }
    while ( _$A2 < v4 );
  }
  if ( !v5 )
    return 0.0;
  __asm
  {
    vsub.xyz     $vf3, $vf4, $vf3
    vaddw.x      $vf1, $vf0, $vf0
    vmul.xyz     $vf2, $vf3, $vf3
    vadday.x     $A, $vf2, $vf2
    vmaddz.x     $vf2, $vf1, $vf2
    vnop
    vnop
    vnop
    vsqrt        $Q, $vf2.x
    vaddw.x      $vf2, $vf0, $vf0
    vwaitq
    vmulq.x      $vf2, $vf2, $Q
    qmfc2        $v0, $vf2
  }
  return *&_$V0;
}

// CB4CollisionDetector::GetCollisionPlane(CB4HullCollideHullParams *, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d *)
__int64 __fastcall GetCollisionPlane__20CB4CollisionDetectorP24CB4HullCollideHullParamsGQ29GtMathPs26CGtV3dT2PQ29GtMathPs26CGtV3d(
        unsigned int a1,
        __int64 _$A1,
        __int64 _$A2)
{
  __int64 v11; // $ra
  float v12; // $f20
  float v13; // $f21
  __int64 v16; // $s0
  __int64 v18; // $s4
  __int64 v19; // $s3
  float v20; // $f20
  int v21; // $s2
  float v22; // $f21
  bool v26; // dc
  int v27; // $v0
  float v29; // $f0
  __int64 result; // $v0
  _OWORD v39[3]; // [sp+0h] [-130h] BYREF
  __int128 v40; // [sp+30h] [-100h] BYREF
  __int64 v45; // [sp+90h] [-A0h]
  float v54; // [sp+120h] [-10h]
  float v55; // [sp+128h] [-8h]

  _$V0 = COERCE_INT(0.5);
  _$V1 = COERCE_INT(10.0);
  __asm
  {
    sq           $a2, 0x130+var_E0($sp)
    qmtc2        $a2, $vf3
    qmtc2        $v0, $vf1
    qmtc2        $v1, $vf2
    vmulx.xyz    $vf1, $vf3, $vf1
    vmulx.xyz    $vf2, $vf3, $vf2
    sq           $a1, 0x130+var_D0($sp)
    qmtc2        $a1, $vf3
    sq           $s0, 0x130+var_20($sp)
    vsub.xyz     $vf1, $vf3, $vf1
    vadd.xyz     $vf2, $vf3, $vf2
    sqc2         $vf1, 0x130+var_100($sp)
    sqc2         $vf2, 0x130+var_F0($sp)
  }
  v16 = 0LL;
  __asm
  {
    sq           $s1, 0x130+var_30($sp)
    sq           $s4, 0x130+var_60($sp)
    sq           $s5, 0x130+var_70($sp)
  }
  v18 = -1LL;
  v54 = v12;
  __asm
  {
    sq           $s2, 0x130+var_40($sp)
    sq           $s3, 0x130+var_50($sp)
    sq           $s6, 0x130+var_80($sp)
    sq           $s7, 0x130+var_90($sp)
  }
  v45 = v11;
  v55 = v13;
  v19 = *(*a1 + 25);
  v20 = 3.4028235e38;
  if ( *(*a1 + 25) )
  {
    __asm
    {
      vaddw.x      $vf1, $vf0, $vf0
      vaddw.x      $vf3, $vf0, $vf0
      sqc2         $vf1, 0x130+var_C0($sp)
      sqc2         $vf3, 0x130+var_B0($sp)
    }
    v21 = 0x1000000;
    do
    {
      if ( IsValidPlane__C24CB4HullCollideHullParamsi(a1, v16) )
      {
        __asm { lqc2         $vf3, 0x130+var_E0($sp) }
        _$V0 = 16 * v16 + *(*a1 + 4);
        __asm
        {
          lqc2         $vf2, 0($v0)
          vmul.xyz     $vf1, $vf3, $vf2
          lqc2         $vf3, 0x130+var_C0($sp)
          vadday.x     $A, $vf1, $vf1
          vmaddz.x     $vf1, $vf3, $vf1
          qmfc2        $v0, $vf1
          qmfc2        $a1, $vf2
        }
        if ( v22 < *&_$V0 )
        {
          v26 = IntersectLine__14GtIntersectionRC7CGtLineGQ29GtMathPs28CGtPlaneP21CGtIntersectionResult(&v40, _$A1, v39) != 1;
          v27 = v21;
          if ( v26 )
            goto LABEL_9;
          __asm
          {
            lqc2         $vf3, 0x130+var_D0($sp)
            lqc2         $vf2, 0x130+var_130($sp)
            vsub.xyz     $vf1, $vf2, $vf3
            vmul.xyz     $vf1, $vf1, $vf1
            lqc2         $vf3, 0x130+var_B0($sp)
            vadday.x     $A, $vf1, $vf1
            vmaddz.x     $vf1, $vf3, $vf1
            qmfc2        $v0, $vf1
          }
          v29 = *&_$V0;
          v26 = *&_$V0 >= v20;
          v27 = v21;
          if ( v26 )
            goto LABEL_9;
          __asm { sqc2         $vf2, 0($s5) }
          v18 = v16;
          v20 = v29;
        }
      }
      v27 = v21;
LABEL_9:
      v16 = v27 >> 24;
      v21 += 0x1000000;
    }
    while ( v16 < v19 );
  }
  result = v18;
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
  }
  return result;
}

// CB4CollisionDetector::ClipEdgesByHull(GtMathPs2::CGtV3d *, int, GtMathPs2::CGtV3d *, unsigned int, GtMathPs2::CGtPlane *, unsigned int)
unsigned __int64 __fastcall ClipEdgesByHull__20CB4CollisionDetectorPQ29GtMathPs26CGtV3diT1UiPQ29GtMathPs28CGtPlaneUi(
        int a1,
        __int64 a2,
        int a3,
        unsigned __int64 a4,
        int a5,
        unsigned __int64 a6)
{
  int v19; // $s5
  unsigned __int64 v21; // $a2
  int v22; // $a7
  int v23; // $v1
  int v24; // $a0
  unsigned __int64 v27; // $a4
  int v28; // $t4
  unsigned __int64 v29; // $a5
  __int64 v30; // $a6
  unsigned __int64 v31; // $t5
  __int64 v36; // $v0
  unsigned __int64 result; // $v0
  float v48; // [sp+4h] [-9Ch]
  float v49; // [sp+8h] [-98h]

  __asm
  {
    sq           $s0, 0xA0+var_10($sp)
    sq           $s1, 0xA0+var_20($sp)
    sq           $s2, 0xA0+var_30($sp)
    sq           $s4, 0xA0+var_50($sp)
    sq           $s5, 0xA0+var_60($sp)
  }
  _$S4 = a5;
  __asm { sq           $s6, 0xA0+var_70($sp) }
  LODWORD(_$S0) = 1;
  __asm
  {
    sq           $s3, 0xA0+var_40($sp)
    sq           $s7, 0xA0+var_80($sp)
  }
  v19 = 0;
  __asm { lq           $a3, 0($s4) # $A3 }
  v21 = ClipEdgesByPlane__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dT1UiGQ29GtMathPs28CGtPlane(
          gaTempEdgePoints,
          a3,
          a4,
          _$A3);
  if ( a6 > 1 )
  {
    v22 = 0;
    if ( v21 < 2 )
      goto LABEL_7;
    v23 = 1;
    do
    {
      v24 = 224 * v19;
      _$V0 = 16 * _$S0 + _$S4;
      v19 = v23;
      __asm { lq           $a3, 0($v0) # $A3 }
      v21 = ClipEdgesByPlane__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dT1UiGQ29GtMathPs28CGtPlane(
              &gaTempEdgePoints[224 * v23],
              &gaTempEdgePoints[v24],
              v21,
              _$A3);
      _$S0 = (_$S0 + 1);
      if ( _$S0 >= a6 )
        break;
      v23 = 1 - v19;
    }
    while ( v21 >= 2 );
  }
  v22 = 0;
LABEL_7:
  v27 = 0LL;
  if ( v21 )
  {
    v28 = a1;
    for ( LODWORD(v29) = 0; ; LODWORD(v29) = 0 )
    {
      v30 = 0LL;
      v31 = v22 + 1;
      if ( v27 )
      {
        _$V0 = COERCE_INT(0.0000001);
        __asm { qmtc2        $v0, $vf3 }
        _$A3 = a1;
        _$A1 = &gaTempEdgePoints[224 * v19 + 4 * v22];
        while ( 1 )
        {
          __asm
          {
            lqc2         $vf2, 0($a3)
            lqc2         $vf1, 0($a1)
            vsub.xyz     $vf1, $vf1, $vf2
            vabs.xyz     $vf1, $vf1
            vsubx.xyz    $vf1, $vf1, $vf3
            qmfc2        $v0, $vf1
          }
          if ( *&_$V0 < 0.0 )
          {
            __asm { sqc2         $vf1, 0xA0+var_A0($sp) }
            v36 = 0LL;
            if ( v48 < 0.0 )
            {
              __asm { sqc2         $vf1, 0xA0+var_A0($sp) }
              v36 = v49 < 0.0;
            }
          }
          else
          {
            v36 = 0LL;
          }
          if ( v36 )
            break;
          v29 = v29 + 1;
          _$A3 += 16;
          if ( v29 >= v27 )
            goto LABEL_19;
        }
        v30 = 1LL;
      }
LABEL_19:
      if ( !v30 )
      {
        v27 = v27 + 1;
        _$V1 = &gaTempEdgePoints[224 * v19 + 4 * v22];
        __asm
        {
          lq           $v0, 0($v1)
          sq           $v0, 0($t4)
        }
        v28 += 16;
      }
      ++v22;
      if ( v31 >= v21 )
        break;
    }
  }
  __asm { lq           $s0, 0xA0+var_10($sp) }
  result = v27;
  __asm
  {
    lq           $s1, 0xA0+var_20($sp)
    lq           $s2, 0xA0+var_30($sp)
    lq           $s3, 0xA0+var_40($sp)
    lq           $s4, 0xA0+var_50($sp)
    lq           $s5, 0xA0+var_60($sp)
    lq           $s6, 0xA0+var_70($sp)
    lq           $s7, 0xA0+var_80($sp)
  }
  return result;
}

// CB4CollisionDetector::ClipEdgesByPlane(GtMathPs2::CGtV3d *, GtMathPs2::CGtV3d *, unsigned int, GtMathPs2::CGtPlane)
__int64 __fastcall ClipEdgesByPlane__20CB4CollisionDetectorPQ29GtMathPs26CGtV3dT1UiGQ29GtMathPs28CGtPlane(
        int a1,
        int _$A1,
        unsigned __int64 a3,
        __int64 _$A3)
{
  __int64 v4; // $a4
  unsigned __int64 v6; // $a5
  float v9; // $f1
  __int64 v10; // $a3
  __int64 v11; // $v1
  float v13; // [sp+Ch] [-4h]

  v4 = 0LL;
  if ( !a3 )
    return 0LL;
  __asm { sq           $a3, 0x10+var_10($sp) }
  LODWORD(v6) = 0;
  __asm
  {
    qmtc2        $a3, $vf6
    vaddw.x      $vf5, $vf0, $vf0
  }
  do
  {
    __asm
    {
      lqc2         $vf3, 0($a1)
      vmul.xyz     $vf1, $vf6, $vf3
      lqc2         $vf4, 0x10($a1)
      vadday.x     $A, $vf1, $vf1
      vmaddz.x     $vf1, $vf5, $vf1
      vmul.xyz     $vf2, $vf6, $vf4
      qmfc2        $v0, $vf1
      vadday.x     $A, $vf2, $vf2
      vmaddz.x     $vf2, $vf5, $vf2
      qmfc2        $v1, $vf2
    }
    v9 = *&_$V1;
    v10 = v13 >= *&_$V0;
    v11 = v13 >= *&_$V1;
    if ( v10 != v11 )
    {
      v4 = v4 + 1;
      _$V0 = COERCE_INT((v13 - *&_$V0) / (v9 - *&_$V0));
      __asm
      {
        qmtc2        $v0, $vf1
        vaddax.xyz   $A, $vf3, $vf0
        vmsubax.xyz  $A, $vf3, $vf1
        vmaddx.xyz   $vf1, $vf4, $vf1
        sqc2         $vf1, 0($a0)
      }
      a1 += 16;
    }
    if ( v10 == 1 )
    {
      __asm { sqc2         $vf3, 0($a0) }
      v4 = v4 + 1;
      a1 += 16;
    }
    v6 = v6 + 2;
    if ( v11 == 1 )
    {
      __asm { sqc2         $vf4, 0($a0) }
      v4 = v4 + 1;
      a1 += 16;
    }
    _$A1 += 32;
  }
  while ( v6 < a3 );
  return v4;
}

// BoxBoxCollision(const CGtAxisAlignedBox &, const GtMathPs2::CGtMatrix3x4 &, const CGtAxisAlignedBox &, const GtMathPs2::CGtMatrix3x4 &, const GtMathPs2::CGtMatrix3x4 &, float *, GtMathPs2::CGtV3d *, GtMathPs2::CGtV3d *)
__int64 __fastcall BoxBoxCollision__FRC17CGtAxisAlignedBoxRCQ29GtMathPs212CGtMatrix3x4T0T1T1PfPQ29GtMathPs26CGtV3dT6(
        int a1,
        int a2,
        int a3,
        int a4,
        int _$A4,
        float *a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v11; // $ra
  __int64 result; // $v0
  __int128 v21; // [sp+0h] [-100h] BYREF
  __int64 v22; // [sp+C0h] [-40h]

  _$V0 = a2;
  __asm
  {
    sq           $s0, 0x100+var_10($sp)
    sq           $s1, 0x100+var_20($sp)
  }
  _$S0 = a4;
  __asm { sq           $s2, 0x100+var_30($sp) }
  _$S1 = a7;
  v22 = v11;
  _$S2 = a8;
  __asm
  {
    lqc2         $vf5, 0($a4)
    lqc2         $vf3, 0x10($a4)
    lqc2         $vf2, 0x20($a4)
    lqc2         $vf11, 0x30($a4)
    lqc2         $vf12, 0x30($v0)
    lqc2         $vf9, 0($v0)
    lqc2         $vf4, 0x10($v0)
    lqc2         $vf1, 0x20($v0)
    vmulax.xyz   $A, $vf5, $vf9
    vmadday.xyz  $A, $vf3, $vf9
    vmaddz.xyz   $vf6, $vf2, $vf9
    vmulax.xyz   $A, $vf5, $vf4
    vmadday.xyz  $A, $vf3, $vf4
    vmaddz.xyz   $vf7, $vf2, $vf4
    vmulax.xyz   $A, $vf5, $vf1
    vmadday.xyz  $A, $vf3, $vf1
    vmaddz.xyz   $vf8, $vf2, $vf1
    vmulax.xyz   $A, $vf5, $vf12
    vmadday.xyz  $A, $vf3, $vf12
    vmaddaz.xyz  $A, $vf2, $vf12
    vmaddw.xyz   $vf10, $vf11, $vf0
    sqc2         $vf6, 0x100+var_100($sp)
    sqc2         $vf7, 0x100+var_F0($sp)
    sqc2         $vf8, 0x100+var_E0($sp)
    sqc2         $vf10, 0x100+var_D0($sp)
    sqc2         $vf6, 0x100+var_80($sp)
    sqc2         $vf7, 0x100+var_70($sp)
    sqc2         $vf8, 0x100+var_60($sp)
    sqc2         $vf10, 0x100+var_50($sp)
    sqc2         $vf6, 0x100+var_C0($sp)
    sqc2         $vf7, 0x100+var_B0($sp)
    sqc2         $vf8, 0x100+var_A0($sp)
    sqc2         $vf10, 0x100+var_90($sp)
  }
  result = BoxBoxTest__FRC17CGtAxisAlignedBoxT0PQ29GtMathPs212CGtMatrix3x4PfPQ29GtMathPs26CGtV3dT4(a1, a3, &v21, a6, a7);
  if ( _$S1 )
  {
    __asm
    {
      lqc2         $vf2, 0($s1)
      lqc2         $vf5, 0($s0)
      lqc2         $vf4, 0x10($s0)
      lqc2         $vf3, 0x20($s0)
      lqc2         $vf1, 0x30($s0)
      vmulax.xyz   $A, $vf5, $vf2
      vmadday.xyz  $A, $vf4, $vf2
      vmaddaz.xyz  $A, $vf3, $vf2
      vmaddw.xyz   $vf2, $vf1, $vf0
      sqc2         $vf2, 0($s1)
    }
  }
  if ( _$S2 )
  {
    __asm
    {
      lqc2         $vf4, 0x20($s0)
      lqc2         $vf1, 0($s2)
      lqc2         $vf3, 0($s0)
      lqc2         $vf2, 0x10($s0)
      vmulax.xyz   $A, $vf3, $vf1
      vmadday.xyz  $A, $vf2, $vf1
      vmaddz.xyz   $vf1, $vf4, $vf1
      sqc2         $vf1, 0($s2)
      lq           $s0, 0x100+var_10($sp)
    }
  }
  else
  {
    __asm { lq           $s0, 0x100+var_10($sp) }
  }
  __asm
  {
    lq           $s1, 0x100+var_20($sp)
    lq           $s2, 0x100+var_30($sp)
  }
  return result;
}

// CB4HullCollideHullParams::CalculateBounds(void)
__int64 __fastcall CalculateBounds__24CB4HullCollideHullParams(int *a1)
{
  __int64 v2; // $a2
  int v4; // $a1
  int v6; // $a4
  int v7; // $a5
  int i; // $v0
  int v9; // $a0
  __int64 v13; // $a2
  int v14; // $a4
  int j; // $a0
  int v18; // $v0
  __int64 result; // $v0
  float v23[4]; // [sp+0h] [-10h] BYREF

  __asm
  {
    vadd.xyz     $vf1, $vf0, $vf0
    sqc2         $vf1, 0x10+var_10($sp)
  }
  _$A3 = a1;
  __asm { vmove.xyzw   $vf4, $vf1 }
  LODWORD(v2) = 0;
  __asm { lq           $v1, 0x10+var_10($sp) }
  v23[0] = -3.4028235e38;
  v23[1] = -3.4028235e38;
  v23[2] = -3.4028235e38;
  __asm { sq           $v1, 0x110($a3) }
  v4 = *a1;
  __asm
  {
    lq           $v0, 0x10+var_10($sp)
    sq           $v0, 0x100($a3)
  }
  v6 = *a1;
  if ( *(*a1 + 24) )
  {
    v7 = *a1;
    for ( i = *(v6 + 8); ; i = *(v6 + 8) )
    {
      v9 = 16 * v2;
      v2 = v2 + 1;
      _$V0 = v9 + i;
      __asm
      {
        lqc2         $vf1, 0x110($a3)
        lqc2         $vf2, 0($v0)
      }
      _$V1 = v9 + *(v4 + 8);
      __asm
      {
        vmini.xyz    $vf1, $vf1, $vf2
        lqc2         $vf3, 0($v1)
        sqc2         $vf1, 0x110($a3)
      }
      v4 = v7;
      __asm
      {
        lqc2         $vf2, 0x100($a3)
        vadd.xyz     $vf4, $vf4, $vf3
      }
      _$A0 = v9 + *(v6 + 8);
      __asm
      {
        lqc2         $vf1, 0($a0)
        vmax.xyz     $vf2, $vf2, $vf1
        sqc2         $vf2, 0x100($a3)
      }
      if ( v2 >= *(v7 + 24) )
        break;
    }
  }
  LODWORD(v13) = 0;
  v14 = *_$A3;
  __asm { lqc2         $vf5, 0xF0($a3) }
  *&_$F0 = 1.0 / *(*_$A3 + 24);
  _$V0 = _$F0;
  __asm
  {
    qmtc2        $v0, $vf1
    vmulx.xyz    $vf4, $vf4, $vf1
    vmove.xyzw   $vf3, $vf4
  }
  if ( *(*_$A3 + 24) )
  {
    __asm { vaddw.x      $vf2, $vf0, $vf0 }
    for ( j = *(*_$A3 + 8); ; j = *(v14 + 8) )
    {
      v18 = 16 * v13;
      v13 = v13 + 1;
      _$V0 = v18 + j;
      __asm
      {
        lqc2         $vf1, 0($v0)
        vsub.xyz     $vf1, $vf3, $vf1
        vmul.xyz     $vf1, $vf1, $vf1
        vadday.x     $A, $vf1, $vf1
        vmaddz.x     $vf1, $vf2, $vf1
        qmfc2        $v0, $vf1
      }
      _$F0 = _$V0;
      __asm { max          $f2, $f0 }
      if ( v13 >= *(v14 + 24) )
        break;
    }
  }
  __asm
  {
    vmove.xyzw   $vf2, $vf5
    vadd.xyz     $vf2, $vf0, $vf4
  }
  result = COERCE_INT(_sqrtf(*&_$F0));
  __asm
  {
    vmove.xyzw   $vf1, $vf2
    qmtc2        $v0, $vf3
    sqc2         $vf2, 0xF0($a3)
    vsubw.w      $vf1, $vf0, $vf0
    sqc2         $vf1, 0xF0($a3)
    vaddx.w      $vf1, $vf1, $vf3
    sqc2         $vf1, 0xF0($a3)
  }
  return result;
}

