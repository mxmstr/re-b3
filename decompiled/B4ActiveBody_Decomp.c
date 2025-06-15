/*


00000000 struct __attribute__((packed)) B4ActiveBody // sizeof=0x30
00000000 {                                       // XREF: B4ActiveBodyManager/r
00000000     void *vtable;
00000004     unsigned __int8 unknown_start_fields[28];
00000020     GtV3d *m_pBBoxMin;
00000024     GtV3d *m_pBBoxMax;
00000028     void *m_pPhysicsData;
0000002C     EActiveBodyType m_eBodyType;
00000030 };
*/

// CB4ActiveBody::GetPointVelocity(GtMathPs2::CGtV3d)
__int64 __fastcall GetPointVelocity__13CB4ActiveBodyGQ29GtMathPs26CGtV3d(B4ActiveBody *pActiveBody, __int64 _$A1)
{
  __int64 m_eBodyType_low; // $v1
  void *m_pPhysicsData; // $v1
  __int64 result; // $v0
  float v9[4]; // [sp+0h] [-10h] BYREF

  m_eBodyType_low = SLOBYTE(pActiveBody->m_eBodyType);
  __asm { qmtc2        $a1, $vf2 }
  v9[0] = 0.0;
  v9[1] = 0.0;
  v9[2] = 0.0;
  __asm { lqc2         $vf1, 0x10+var_10($sp) }
  if ( m_eBodyType_low == 3 )
  {
    m_pPhysicsData = pActiveBody->m_pPhysicsData;
    _$A0 = pActiveBody->m_pBBoxMin;
    _$V0 = *(m_pPhysicsData + 49);
    __asm
    {
      lqc2         $vf2, 0x20($a0)
      qmtc2        $v0, $vf1
      vmulx.xyz    $vf1, $vf2, $vf1
      qmfc2        $v0, $vf1
    }
  }
  else
  {
    __asm { qmfc2        $v0, $vf1 }
    if ( m_eBodyType_low != 6 )
    {
      _$V0 = pActiveBody->m_pPhysicsData;
      _$V1 = *(_$V0 + 125);
      __asm
      {
        lqc2         $vf3, 0xC0($v0)
        lqc2         $vf1, 0x30($v1)
        vsub.xyz     $vf1, $vf2, $vf1
        lqc2         $vf2, 0xA0($v0)
        vopmula      $A, $vf3, $vf1
        vopmsub      $vf1, $vf1, $vf3
        vadd.xyz     $vf1, $vf1, $vf2
        qmfc2        $v0, $vf1
      }
    }
  }
  return result;
}

// CB4ActiveBody::GetConvexHull(void)
__int64 __fastcall GetConvexHull__13CB4ActiveBody(B4ActiveBody *pActiveBody)
{
  __int64 m_eBodyType_low; // $v1
  __int64 v2; // $a1
  int v3; // $a0

  m_eBodyType_low = SLOBYTE(pActiveBody->m_eBodyType);
  v2 = 0LL;
  if ( m_eBodyType_low == 3 )
  {
    v3 = *(pActiveBody->m_pPhysicsData + 44);
    if ( v3 )
      return v3 + 7616;
  }
  else if ( m_eBodyType_low != 6 )
  {
    return *(pActiveBody->m_pPhysicsData + 126);
  }
  return v2;
}

// CB4ActiveBody::GetNetworkCollBodyType(void) const
__int64 __fastcall GetNetworkCollBodyType__C13CB4ActiveBody(B4ActiveBody *pActiveBody)
{
  __int64 result; // $v0
  __int64 v2; // $v1
  __int64 m_eBodyType_low; // $a1
  __int64 v4; // $a0
  __int64 v5; // $a0

  switch ( LOBYTE(pActiveBody->m_eBodyType) )
  {
    case 0:
    case 2:
      result = 0LL;
      break;
    case 1:
      result = 1LL;
      break;
    case 3:
      result = 2LL;
      break;
    case 6:
    case 7:
    case 8:
      result = 9LL;
      break;
    default:
      if ( *&gWorld.m_CrashScore[1048] < 2LL )
        v2 = gWorld.m_aPlayerCars[0][11272];
      else
        v2 = gWorld.m_aPlayerCars[1][11272];
      m_eBodyType_low = SLOBYTE(pActiveBody->m_eBodyType);
      if ( m_eBodyType_low == 4 )
      {
        v4 = *(pActiveBody->m_pPhysicsData + 14091);
        if ( gWorld.m_aPlayerCars[0][11272] == v4 || v2 == v4 )
          result = 3LL;
        else
          result = 5LL;
      }
      else
      {
        result = 9LL;
        if ( m_eBodyType_low == 5 )
        {
          v5 = *(pActiveBody->m_pPhysicsData + 14810);
          if ( gWorld.m_aPlayerCars[0][11272] == v5 || v2 == v5 )
            result = 6LL;
          else
            result = 8LL;
        }
      }
      break;
  }
  return result;
}

// CB4ActiveBody::CanFatalAgainst(CB4ActiveBody *) const
__int64 __fastcall CanFatalAgainst__C13CB4ActiveBodyP13CB4ActiveBody(B4ActiveBody *pActiveBody, B4ActiveBody *a2)
{
  __int64 NetworkCollBodyType__C13CB4ActiveBody; // $s1
  int v6; // $a3
  __int64 m_eBodyType_low; // $v1
  __int64 v8; // $a2
  __int64 v9; // $v0
  __int64 v10; // $v1
  __int64 v11; // $v0
  __int64 v12; // $v1
  __int64 result; // $v0

  __asm
  {
    sq           $s0, 0x30+var_10($sp)
    sq           $s1, 0x30+var_20($sp)
  }
  NetworkCollBodyType__C13CB4ActiveBody = GetNetworkCollBodyType__C13CB4ActiveBody(pActiveBody);
  v6 = GetNetworkCollBodyType__C13CB4ActiveBody(a2);
  m_eBodyType_low = SLOBYTE(a2->m_eBodyType);
  v8 = 0LL;
  if ( m_eBodyType_low == 2 || !LOBYTE(a2->m_eBodyType) || (v9 = 0LL, m_eBodyType_low == 1) )
    v9 = 1LL;
  if ( v9 || (v10 = SLOBYTE(a2->m_eBodyType), v10 == 4) || (v11 = 0LL, v10 == 5) )
    v11 = 1LL;
  if ( v11 )
    v8 = *(a2->m_pPhysicsData + 1098) > 3999.0;
  v12 = 0LL;
  if ( NetworkCollBodyType__C13CB4ActiveBody != 1 && NetworkCollBodyType__C13CB4ActiveBody != 7 )
    v12 = NetworkCollBodyType__C13CB4ActiveBody != 8;
  if ( !v8 || (result = 1LL, !v12) )
    result = *(&kaabCanFatal + 10 * NetworkCollBodyType__C13CB4ActiveBody + v6);
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    lq           $s1, 0x30+var_20($sp)
  }
  return result;
}

// CB4ActiveBody::GetInteractionTypeAgainst(CB4ActiveBody *) const
__int64 __fastcall GetInteractionTypeAgainst__C13CB4ActiveBodyP13CB4ActiveBody(
        B4ActiveBody *pActiveBody,
        B4ActiveBody *a2)
{
  __int64 NetworkCollBodyType__C13CB4ActiveBody; // $s0
  __int64 v8; // $v0
  __int64 v9; // $a3
  int v10; // $v1
  int v11; // $a0

  __asm
  {
    sq           $s2, 0x40+var_30($sp)
    sq           $s1, 0x40+var_20($sp)
    sq           $s0, 0x40+var_10($sp)
  }
  NetworkCollBodyType__C13CB4ActiveBody = GetNetworkCollBodyType__C13CB4ActiveBody(pActiveBody);
  v8 = GetNetworkCollBodyType__C13CB4ActiveBody(a2);
  v9 = v8;
  if ( NetworkCollBodyType__C13CB4ActiveBody == 1 && v8 == 5 )
  {
    v9 = 4LL;
    if ( *(a2->m_pPhysicsData + 14091) != *(*(pActiveBody->m_pPhysicsData + 1340) + 11400) )
      v9 = 5LL;
  }
  else if ( v8 == 1
         && NetworkCollBodyType__C13CB4ActiveBody == 5
         && *(pActiveBody->m_pPhysicsData + 14091) == *(*(a2->m_pPhysicsData + 1340) + 11400) )
  {
    NetworkCollBodyType__C13CB4ActiveBody = 4LL;
  }
  if ( NetworkCollBodyType__C13CB4ActiveBody == 1 && v9 == 8 )
  {
    if ( *(a2->m_pPhysicsData + 14810) == *(*(pActiveBody->m_pPhysicsData + 1340) + 11400) )
      LODWORD(v9) = 7;
    goto LABEL_19;
  }
  if ( v9 != 1 )
  {
LABEL_19:
    v10 = 4 * v9;
    goto LABEL_20;
  }
  v10 = 4;
  if ( NetworkCollBodyType__C13CB4ActiveBody == 8 )
  {
    if ( *(pActiveBody->m_pPhysicsData + 14810) == *(*(a2->m_pPhysicsData + 1340) + 11400) )
      LODWORD(NetworkCollBodyType__C13CB4ActiveBody) = 7;
    goto LABEL_19;
  }
LABEL_20:
  v11 = 40 * NetworkCollBodyType__C13CB4ActiveBody;
  __asm
  {
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return *(&kaaePhysicsType + v10 + v11);
}

// CB4ActiveBody::GetIntervals(void)
__int64 __fastcall GetIntervals__13CB4ActiveBody(B4ActiveBody *_$A0)
{
  __int64 result; // $v0

  result = _$A0->m_pBBoxMax;
  _$V1 = _$A0->m_pBBoxMin;
  __asm
  {
    lqc2         $vf7, 0($v0)
    lqc2         $vf12, 0($a0)
    sqc2         $vf7, 0x20+var_20($sp)
    lqc2         $vf10, 0x10($v0)
    lqc2         $vf11, 0x10($a0)
    sqc2         $vf10, 0x20+var_10($sp)
    lqc2         $vf3, 0($v1)
    lqc2         $vf5, 0x10($v1)
    vaddx.x      $vf1, $vf0, $vf3
    lqc2         $vf6, 0x20($v1)
    vaddx.y      $vf1, $vf0, $vf5
    vaddx.z      $vf1, $vf0, $vf6
    vaddy.x      $vf2, $vf0, $vf3
    vmul.xyz     $vf8, $vf1, $vf7
    vaddy.y      $vf2, $vf0, $vf5
    vaddy.z      $vf2, $vf0, $vf6
    vmul.xyz     $vf1, $vf1, $vf10
    vaddz.x      $vf4, $vf0, $vf3
    vmul.xyz     $vf9, $vf2, $vf7
    vmax.xyz     $vf3, $vf1, $vf8
    vaddz.y      $vf4, $vf0, $vf5
    vmini.xyz    $vf1, $vf1, $vf8
    vaddz.z      $vf4, $vf0, $vf6
    vmul.xyz     $vf2, $vf2, $vf10
    vmul.xyz     $vf7, $vf4, $vf7
    vmax.xyz     $vf8, $vf2, $vf9
    vaddy.x      $vf6, $vf3, $vf3
    vmini.xyz    $vf2, $vf2, $vf9
    vmul.xyz     $vf4, $vf4, $vf10
    vaddz.x      $vf6, $vf6, $vf3
    vaddy.x      $vf5, $vf1, $vf1
    vmax.xyz     $vf9, $vf4, $vf7
    vaddz.x      $vf5, $vf5, $vf1
    vaddy.x      $vf3, $vf8, $vf8
    vaddx.x      $vf12, $vf0, $vf5
    vaddx.x      $vf11, $vf0, $vf6
    vmini.xyz    $vf4, $vf4, $vf7
    vaddz.x      $vf3, $vf3, $vf8
    vaddy.x      $vf1, $vf2, $vf2
    vaddz.x      $vf1, $vf1, $vf2
    vmove.xyzw   $vf7, $vf12
    vmove.xyzw   $vf8, $vf11
    vaddx.y      $vf7, $vf0, $vf1
    vaddx.y      $vf8, $vf0, $vf3
    vaddy.x      $vf5, $vf4, $vf4
    vaddy.x      $vf6, $vf9, $vf9
    vaddz.x      $vf5, $vf5, $vf4
    vaddz.x      $vf6, $vf6, $vf9
    vmove.xyzw   $vf2, $vf7
    vmove.xyzw   $vf3, $vf8
    vaddx.z      $vf2, $vf0, $vf5
    sqc2         $vf12, 0($a0)
    vaddx.z      $vf3, $vf0, $vf6
    sqc2         $vf11, 0x10($a0)
    sqc2         $vf2, 0($a0)
    sqc2         $vf3, 0x10($a0)
    lqc2         $vf1, 0x30($v1)
    vadd.xyz     $vf2, $vf2, $vf1
    sqc2         $vf2, 0($a0)
    lqc2         $vf1, 0x30($v1)
    vadd.xyz     $vf3, $vf3, $vf1
    sqc2         $vf3, 0x10($a0)
  }
  return result;
}

// CB4ActiveBody::GetEssentialParams(void) const
__int64 __fastcall GetEssentialParams__C13CB4ActiveBody(B4ActiveBody *pActiveBody)
{
  if ( LOBYTE(pActiveBody->m_eBodyType) == 3LL )
    return pActiveBody->m_pPhysicsData + 112;
  if ( (LOBYTE(pActiveBody->m_eBodyType) - 6) < 3 )
    return 0LL;
  return *(pActiveBody->m_pPhysicsData + 637);
}

// CB4ActiveBody::GetSpeedInMPS(void) const
float __fastcall GetSpeedInMPS__C13CB4ActiveBody(B4ActiveBody *pActiveBody)
{
  float result; // $f0

  switch ( LOBYTE(pActiveBody->m_eBodyType) )
  {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
      result = *(*(pActiveBody->m_pPhysicsData + 637) + 84);
      break;
    case 3:
      result = *(pActiveBody->m_pPhysicsData + 49);
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

// CB4ActiveBody::GetPhysicsData(void) const
__int64 __fastcall GetPhysicsData__C13CB4ActiveBody(B4ActiveBody *a1)
{
  return a1->m_pPhysicsData;
}

