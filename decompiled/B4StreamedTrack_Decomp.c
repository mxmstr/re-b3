/*
00000000 struct GtPolygonIntersectionResult // sizeof=0x6C
00000000 {                                       // XREF: TestBodyAgainstWave__19CB4ShockwaveManagerP13CB4ActiveBodyiif/r
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
*/

// CB4StreamedTrack::Construct(void)
__int64 __fastcall Construct__16CB4StreamedTrack(unsigned int pStreamedTrack)
{
  __int64 result; // $v0

  __asm
  {
    sq           $s0, 0x30+var_10($sp)
    sq           $s1, 0x30+var_20($sp)
  }
  *(pStreamedTrack + 28) = -1;
  *(pStreamedTrack + 76) = -1;
  *(pStreamedTrack + 72) = -1;
  *(pStreamedTrack + 112) = -1;
  *(pStreamedTrack + 108) = -1;
  *(pStreamedTrack + 120) = -1;
  *(pStreamedTrack + 116) = -1;
  *(pStreamedTrack + 4) = -1;
  *pStreamedTrack = -1;
  *(pStreamedTrack + 44) = -1;
  *(pStreamedTrack + 40) = -1;
  *(pStreamedTrack + 52) = -1;
  *(pStreamedTrack + 48) = -1;
  *(pStreamedTrack + 104) = -1;
  *(pStreamedTrack + 100) = -1;
  *(pStreamedTrack + 12) = -1;
  *(pStreamedTrack + 8) = -1;
  *(pStreamedTrack + 60) = -1;
  *(pStreamedTrack + 56) = -1;
  *(pStreamedTrack + 68) = -1;
  *(pStreamedTrack + 24) = 0;
  *(pStreamedTrack + 92) = 0;
  *(pStreamedTrack + 93) = 0;
  *(pStreamedTrack + 94) = 0;
  *(pStreamedTrack + 95) = 0;
  *(pStreamedTrack + 25) = 0;
  *(pStreamedTrack + 80) = 0;
  *(pStreamedTrack + 84) = 0;
  *(pStreamedTrack + 88) = 0;
  *(pStreamedTrack + 20) = 0;
  *(pStreamedTrack + 64) = -1;
  *(pStreamedTrack + 96) = 1;
  memset(16CB4StreamedTrack_mabActiveDetourChevrons, 0, sizeof(16CB4StreamedTrack_mabActiveDetourChevrons));
  memset(&16CB4StreamedTrack_mabRenderActiveDetourChevrons, 0, 8uLL);
  result = 1LL;
  geStreamedWorldDiskSemaphore = -1;
  *(pStreamedTrack + 16) = 1;
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    lq           $s1, 0x30+var_20($sp)
  }
  return result;
}

// CB4StreamedTrack::Destruct(void)
__int64 __fastcall Destruct__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 result; // $v0

  result = 57LL;
  *(pStreamedTrack + 16) = 57;
  return result;
}

// CB4StreamedTrack::Prepare(bool, EPlayerCarIndex)
__int64 __fastcall Prepare__16CB4StreamedTrackb15EPlayerCarIndex(unsigned int pStreamedTrack, char a2, int a3)
{
  __int64 v10; // $v1
  __int64 result; // $v0
  __int64 v13; // $v1
  __int64 v14; // $s2
  int *v15; // $s0
  __int64 v16; // $s2
  int *v17; // $s0
  int v18; // $s3
  __int64 v19; // $s2
  _DWORD *v20; // $s0
  int v21; // $v0
  __int64 v22; // $v0
  __int64 v23; // $s2
  _DWORD *v24; // $s0
  int v25; // $v0
  __int64 v26; // $v0
  int v27; // $v1
  __int64 v28; // $v0
  int v29; // $a0
  __int64 v30; // $v0
  int v31; // $hi
  int v32; // $v0
  __int64 v33; // $v0
  int v34; // $hi
  int v35; // $v0
  __int64 v36; // $v0

  __asm
  {
    sq           $s1, 0x70+var_20($sp)
    sq           $s0, 0x70+var_10($sp)
    sq           $s2, 0x70+var_30($sp)
    sq           $s3, 0x70+var_40($sp)
    sq           $s4, 0x70+var_50($sp)
    sq           $s5, 0x70+var_60($sp)
  }
  v10 = *(pStreamedTrack + 16);
  if ( v10 == 4 )
  {
    v18 = *(*&gWorld.m_StaticTrack[4] + 84);
    if ( (*(*(*gWorld.m_StreamManager + 40) + 68))(*gWorld.m_StreamManager + *(*(*gWorld.m_StreamManager + 40) + 64)) != 1 )
    {
LABEL_24:
      result = 0LL;
      goto LABEL_50;
    }
    LODWORD(v19) = 0;
    if ( *(pStreamedTrack + 8) - 1 > 0LL )
    {
      v20 = (pStreamedTrack + 380);
      do
      {
        if ( *v20 )
        {
          v21 = *(pStreamedTrack + 8);
        }
        else
        {
          v22 = AcquireHighDetailUnit__16CB4StreamManager(gWorld.m_StreamManager);
          *v20 = v22;
          if ( !v22 )
            goto LABEL_24;
          v21 = *(pStreamedTrack + 8);
        }
        v19 = v19 + 1;
        ++v20;
      }
      while ( v19 < v21 - 1 );
    }
    LODWORD(v23) = 0;
    if ( *(pStreamedTrack + 12) - 1 > 0LL )
    {
      v24 = (pStreamedTrack + 420);
      do
      {
        if ( *v24 )
        {
          v25 = *(pStreamedTrack + 12);
        }
        else
        {
          v26 = AcquireLODUnit__16CB4StreamManager(gWorld.m_StreamManager);
          *v24 = v26;
          if ( !v26 )
            goto LABEL_24;
          v25 = *(pStreamedTrack + 12);
        }
        v23 = v23 + 1;
        ++v24;
      }
      while ( v23 < v25 - 1 );
    }
    v27 = *(pStreamedTrack + 28);
    *(pStreamedTrack + 44) = -1;
    *(pStreamedTrack + 92) = 0;
    *(pStreamedTrack + 93) = 0;
    *(pStreamedTrack + 94) = 0;
    *(pStreamedTrack + 80) = 0;
    *(pStreamedTrack + 84) = 0;
    *(pStreamedTrack + 88) = 0;
    *(pStreamedTrack + 40) = -1;
    *(pStreamedTrack + 48) = 0;
    *(pStreamedTrack + 52) = 0;
    *(pStreamedTrack + 104) = 0;
    *(pStreamedTrack + 100) = 0;
    v28 = *(&gWorld.m_Timer.lastFrame + 4 * v27 + &loc_176980) - 8;
    *(pStreamedTrack + 120) = v28;
    if ( v28 < 0 )
      LODWORD(v28) = v18 - -v28 % v18;
    v29 = 4 * *(pStreamedTrack + 28);
    *(pStreamedTrack + 120) = v28 % v18;
    v30 = *(&gWorld.m_Timer.lastFrame + &loc_176980 + v29) - 4;
    *(pStreamedTrack + 116) = v30;
    if ( v30 < 0 )
      LODWORD(v30) = v18 - -v30 % v18;
    v31 = v30 % v18;
    v32 = *(pStreamedTrack + 120);
    *(pStreamedTrack + 116) = v31;
    v33 = v32 - 1;
    *(pStreamedTrack + 112) = v33;
    if ( v33 < 0 )
      LODWORD(v33) = v18 - -v33 % v18;
    v34 = v33 % v18;
    v35 = *(pStreamedTrack + 116);
    *(pStreamedTrack + 112) = v34;
    v36 = v35 - 1;
    *(pStreamedTrack + 108) = v36;
    if ( v36 < 0 )
      LODWORD(v36) = v18 - -v36 % v18;
    *(pStreamedTrack + 68) = 17;
    *(pStreamedTrack + 108) = v36 % v18;
    *(pStreamedTrack + 56) = -1;
    *(pStreamedTrack + 64) = 9;
    *(pStreamedTrack + 36) = 8;
    *(pStreamedTrack + 32) = 4;
    *(pStreamedTrack + 16) = 5;
    *(pStreamedTrack + 60) = -1;
    *(pStreamedTrack + 25) = 0;
LABEL_48:
    UpdateStreamFSM__16CB4StreamedTrack(pStreamedTrack);
    if ( *(pStreamedTrack + 92) )
    {
      *(pStreamedTrack + 16) = 2;
      *(pStreamedTrack + 104) = 8;
      result = 1LL;
      *(pStreamedTrack + 100) = 4;
      *(pStreamedTrack + 4) = 8;
      *pStreamedTrack = 4;
      goto LABEL_50;
    }
    goto LABEL_24;
  }
  if ( v10 >= 5 )
  {
    if ( v10 == 5 )
      goto LABEL_48;
    result = 1LL;
    if ( v10 != 56 )
    {
LABEL_50:
      __asm { lq           $s0, 0x70+var_10($sp) }
      goto LABEL_51;
    }
    goto LABEL_8;
  }
  if ( v10 == 1 )
  {
LABEL_8:
    geStreamedWorldDiskSemaphore = -1;
    *(pStreamedTrack + 95) = 0;
    *(pStreamedTrack + 96) = 1;
    *(pStreamedTrack + 92) = 0;
    *(pStreamedTrack + 93) = 0;
    *(pStreamedTrack + 94) = 0;
    *(pStreamedTrack + 80) = 0;
    *(pStreamedTrack + 84) = 0;
    *(pStreamedTrack + 88) = 0;
    *(pStreamedTrack + 20) = 0;
    *(pStreamedTrack + 100) = -1;
    *(pStreamedTrack + 76) = -1;
    *(pStreamedTrack + 72) = -1;
    *(pStreamedTrack + 44) = -1;
    *(pStreamedTrack + 40) = -1;
    *(pStreamedTrack + 52) = -1;
    *(pStreamedTrack + 48) = -1;
    *(pStreamedTrack + 60) = -1;
    *(pStreamedTrack + 56) = -1;
    *(pStreamedTrack + 68) = -1;
    *(pStreamedTrack + 64) = -1;
    *(pStreamedTrack + 104) = -1;
    *(pStreamedTrack + 24) = a2;
    *(pStreamedTrack + 28) = a3;
    memset(16CB4StreamedTrack_mabActiveDetourChevrons, 0, sizeof(16CB4StreamedTrack_mabActiveDetourChevrons));
    memset(&16CB4StreamedTrack_mabRenderActiveDetourChevrons, 0, 8uLL);
    *(pStreamedTrack + 8) = 10;
    *(pStreamedTrack + 12) = 18;
    *(pStreamedTrack + 25) = 1;
    *(pStreamedTrack + 16) = 2;
    *(pStreamedTrack + 500) = 0;
LABEL_9:
    memset((pStreamedTrack + 126), 0, 0x24uLL);
    memset((pStreamedTrack + 164), 0, 0x48uLL);
    memset((pStreamedTrack + 236), 0, 0x48uLL);
    memset((pStreamedTrack + 308), 0, 0x48uLL);
    v13 = *(pStreamedTrack + 25);
    *(pStreamedTrack + 492) = 0;
    *(pStreamedTrack + 496) = 0;
    if ( v13 || gWorld.m_StreamManager[4] )
    {
      geStreamedWorldDiskSemaphore = -1;
      *(pStreamedTrack + 95) = 0;
      LODWORD(v14) = 0;
      if ( *(pStreamedTrack + 8) > 0LL )
      {
        v15 = (pStreamedTrack + 380);
        do
        {
          if ( *v15 )
          {
            ReleaseHighDetailUnit__16CB4StreamManagerP24CB4StreamedTrackHighData(gWorld.m_StreamManager, *v15);
            *v15 = 0;
          }
          v14 = v14 + 1;
          ++v15;
        }
        while ( v14 < *(pStreamedTrack + 8) );
      }
      LODWORD(v16) = 0;
      if ( *(pStreamedTrack + 12) > 0LL )
      {
        v17 = (pStreamedTrack + 420);
        do
        {
          if ( *v17 )
          {
            ReleaseLODUnit__16CB4StreamManagerP35CB4StreamedTrackLODAndCollisionData(gWorld.m_StreamManager, *v17);
            *v17 = 0;
          }
          v16 = v16 + 1;
          ++v17;
        }
        while ( v16 < *(pStreamedTrack + 12) );
      }
      result = 0LL;
      *(pStreamedTrack + 16) = 4;
      goto LABEL_50;
    }
    *(pStreamedTrack + 16) = 5;
    goto LABEL_48;
  }
  result = 1LL;
  if ( v10 == 2 )
    goto LABEL_9;
  __asm { lq           $s0, 0x70+var_10($sp) }
LABEL_51:
  __asm
  {
    lq           $s1, 0x70+var_20($sp)
    lq           $s2, 0x70+var_30($sp)
    lq           $s3, 0x70+var_40($sp)
    lq           $s4, 0x70+var_50($sp)
    lq           $s5, 0x70+var_60($sp)
  }
  return result;
}

// CB4StreamedTrack::Release(void)
__int64 __fastcall Release__16CB4StreamedTrack(unsigned int pStreamedTrack)
{
  int *v6; // $s0
  __int64 v7; // $s2
  int *v8; // $s0
  __int64 result; // $v0

  __asm
  {
    sq           $s1, 0x50+var_20($sp)
    sq           $s2, 0x50+var_30($sp)
    sq           $s0, 0x50+var_10($sp)
    sq           $s3, 0x50+var_40($sp)
  }
  LODWORD(_$S2) = 0;
  if ( *(pStreamedTrack + 8) > 0LL )
  {
    v6 = (pStreamedTrack + 380);
    do
    {
      if ( *v6 )
      {
        ReleaseHighDetailUnit__16CB4StreamManagerP24CB4StreamedTrackHighData(gWorld.m_StreamManager, *v6);
        *v6 = 0;
      }
      _$S2 = _$S2 + 1;
      ++v6;
    }
    while ( _$S2 < *(pStreamedTrack + 8) );
  }
  LODWORD(v7) = 0;
  if ( *(pStreamedTrack + 12) > 0LL )
  {
    v8 = (pStreamedTrack + 420);
    do
    {
      if ( *v8 )
      {
        ReleaseLODUnit__16CB4StreamManagerP35CB4StreamedTrackLODAndCollisionData(gWorld.m_StreamManager, *v8);
        *v8 = 0;
      }
      v7 = v7 + 1;
      ++v8;
    }
    while ( v7 < *(pStreamedTrack + 12) );
  }
  result = -1LL;
  geStreamedWorldDiskSemaphore = -1;
  *(pStreamedTrack + 16) = 56;
  *(pStreamedTrack + 100) = -1;
  *(pStreamedTrack + 92) = 0;
  *(pStreamedTrack + 93) = 0;
  *(pStreamedTrack + 94) = 0;
  *(pStreamedTrack + 76) = -1;
  *(pStreamedTrack + 72) = -1;
  *(pStreamedTrack + 120) = -1;
  *(pStreamedTrack + 116) = -1;
  *(pStreamedTrack + 4) = -1;
  *pStreamedTrack = -1;
  *(pStreamedTrack + 52) = -1;
  *(pStreamedTrack + 48) = -1;
  *(pStreamedTrack + 12) = -1;
  *(pStreamedTrack + 8) = -1;
  *(pStreamedTrack + 68) = -1;
  *(pStreamedTrack + 64) = -1;
  *(pStreamedTrack + 104) = -1;
  __asm
  {
    lq           $s0, 0x50+var_10($sp)
    lq           $s1, 0x50+var_20($sp)
    lq           $s2, 0x50+var_30($sp)
    lq           $s3, 0x50+var_40($sp)
  }
  return result;
}

// CB4StreamedTrack::ReadAnotherUnitForwards(void)
__int64 __fastcall ReadAnotherUnitForwards__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 v6; // $v1
  __int64 v7; // $v0
  bool v8; // $a0
  __int64 v9; // $v0
  bool v10; // dc
  __int64 result; // $v0
  __int64 v12; // $v0
  int v13; // $a0
  int v14; // $s1
  __int64 v15; // $v0
  int v16; // $a0
  int v17; // $s3
  __int64 v18; // $a0
  int v19; // $a1
  int v20; // $a2
  int v21; // $v1

  __asm
  {
    sq           $s2, 0x50+var_30($sp)
    sq           $s0, 0x50+var_10($sp)
    sq           $s1, 0x50+var_20($sp)
    sq           $s3, 0x50+var_40($sp)
  }
  v6 = *(pStreamedTrack + 44);
  v7 = *(pStreamedTrack + 60);
  v8 = 0;
  if ( v6 != v7 )
    goto LABEL_5;
  v9 = 0LL;
  if ( *(pStreamedTrack + 52) == *(pStreamedTrack + 68) )
  {
    v9 = 0LL;
    if ( *(pStreamedTrack + 40) == *(pStreamedTrack + 56) )
    {
      v8 = *(pStreamedTrack + 48) == *(pStreamedTrack + 64);
LABEL_5:
      v9 = v8;
    }
  }
  v10 = v9 == 0;
  result = 0LL;
  if ( !v10 )
  {
    v12 = *(pStreamedTrack + 64);
    v13 = *(pStreamedTrack + 8);
    if ( v12 < 0 )
      LODWORD(v12) = v13 - -v12 % v13;
    v14 = v12 % v13;
    v15 = *(pStreamedTrack + 68);
    v16 = *(pStreamedTrack + 12);
    if ( v15 < 0 )
      LODWORD(v15) = v16 - -v15 % v16;
    v17 = v15 % v16;
    *(pStreamedTrack + 380 + 4 * v14) = AcquireHighDetailUnit__16CB4StreamManager(gWorld.m_StreamManager);
    v18 = AcquireLODUnit__16CB4StreamManager(gWorld.m_StreamManager);
    *(pStreamedTrack + 4 * v17 + 420) = v18;
    result = 0LL;
    if ( *(pStreamedTrack + 380 + 4 * v14) && v18 )
    {
      v19 = *(pStreamedTrack + 64) + 1;
      v20 = *(pStreamedTrack + 60) + 1;
      v21 = *(pStreamedTrack + 56) + 1;
      ++*(pStreamedTrack + 68);
      *(pStreamedTrack + 64) = v19;
      result = 1LL;
      *(pStreamedTrack + 60) = v20;
      *(pStreamedTrack + 56) = v21;
      *(pStreamedTrack + 25) = 1;
      gWorld.m_StreamManager[4] = 1;
    }
  }
  __asm
  {
    lq           $s0, 0x50+var_10($sp)
    lq           $s1, 0x50+var_20($sp)
    lq           $s2, 0x50+var_30($sp)
    lq           $s3, 0x50+var_40($sp)
  }
  return result;
}

// CB4StreamedTrack::ReadAnotherUnitBackwards(void)
__int64 __fastcall ReadAnotherUnitBackwards__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 v6; // $v1
  __int64 v7; // $v0
  bool v8; // $a0
  __int64 v9; // $v0
  bool v10; // dc
  __int64 result; // $v0
  __int64 v12; // $v0
  int v13; // $a0
  int v14; // $s1
  __int64 v15; // $v0
  int v16; // $a0
  int v17; // $s3
  __int64 v18; // $a0
  int v19; // $a1
  int v20; // $a2
  int v21; // $v1

  __asm
  {
    sq           $s2, 0x50+var_30($sp)
    sq           $s0, 0x50+var_10($sp)
    sq           $s1, 0x50+var_20($sp)
    sq           $s3, 0x50+var_40($sp)
  }
  v6 = *(pStreamedTrack + 44);
  v7 = *(pStreamedTrack + 60);
  v8 = 0;
  if ( v6 != v7 )
    goto LABEL_5;
  v9 = 0LL;
  if ( *(pStreamedTrack + 52) == *(pStreamedTrack + 68) )
  {
    v9 = 0LL;
    if ( *(pStreamedTrack + 40) == *(pStreamedTrack + 56) )
    {
      v8 = *(pStreamedTrack + 48) == *(pStreamedTrack + 64);
LABEL_5:
      v9 = v8;
    }
  }
  v10 = v9 == 0;
  result = 0LL;
  if ( !v10 )
  {
    v12 = *(pStreamedTrack + 56);
    v13 = *(pStreamedTrack + 8);
    if ( v12 < 0 )
      LODWORD(v12) = v13 - -v12 % v13;
    v14 = v12 % v13;
    v15 = *(pStreamedTrack + 60);
    v16 = *(pStreamedTrack + 12);
    if ( v15 < 0 )
      LODWORD(v15) = v16 - -v15 % v16;
    v17 = v15 % v16;
    *(pStreamedTrack + 380 + 4 * v14) = AcquireHighDetailUnit__16CB4StreamManager(gWorld.m_StreamManager);
    v18 = AcquireLODUnit__16CB4StreamManager(gWorld.m_StreamManager);
    *(pStreamedTrack + 4 * v17 + 420) = v18;
    result = 0LL;
    if ( *(pStreamedTrack + 380 + 4 * v14) && v18 )
    {
      v19 = *(pStreamedTrack + 56) - 1;
      v20 = *(pStreamedTrack + 68) - 1;
      v21 = *(pStreamedTrack + 64) - 1;
      --*(pStreamedTrack + 60);
      *(pStreamedTrack + 56) = v19;
      result = 1LL;
      *(pStreamedTrack + 68) = v20;
      *(pStreamedTrack + 64) = v21;
      *(pStreamedTrack + 25) = 1;
      gWorld.m_StreamManager[4] = 1;
    }
  }
  __asm
  {
    lq           $s0, 0x50+var_10($sp)
    lq           $s1, 0x50+var_20($sp)
    lq           $s2, 0x50+var_30($sp)
    lq           $s3, 0x50+var_40($sp)
  }
  return result;
}

// CB4StreamedTrack::UpdateStreamLowFSM(void)
__int64 __fastcall UpdateStreamLowFSM__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 v5; // $v1
  __int64 result; // $v0
  int v9; // $v1
  __int64 v10; // $v0
  int v11; // $a0
  int v12; // $s0

  __asm
  {
    sq           $s1, 0x40+var_20($sp)
    sq           $s2, 0x40+var_30($sp)
    sq           $s0, 0x40+var_10($sp)
  }
  v5 = *(pStreamedTrack + 88);
  if ( v5 == 2 )
  {
    if ( *(pStreamedTrack + 96) )
      v10 = *(pStreamedTrack + 52);
    else
      v10 = *(pStreamedTrack + 44);
    v11 = *(pStreamedTrack + 12);
    if ( v10 < 0 )
      LODWORD(v10) = v11 - -v10 % v11;
    *(pStreamedTrack + 76) = v10 % v11;
    (*(*(*gWorld.m_StreamManager + 40) + 28))(
      *gWorld.m_StreamManager + *(*(*gWorld.m_StreamManager + 40) + 24),
      *(pStreamedTrack + 4 * *(pStreamedTrack + 76) + 420),
      *(*(pStreamedTrack + 20) + 12));
    *(pStreamedTrack + 88) = 3;
    goto LABEL_18;
  }
  if ( v5 >= 3 )
  {
    result = 0LL;
    if ( v5 != 3 )
    {
      __asm { lq           $s0, 0x40+var_10($sp) }
      goto LABEL_20;
    }
    v12 = pStreamedTrack + 420;
    FixUp__35CB4StreamedTrackLODAndCollisionDatai(
      *(pStreamedTrack + 420 + 4 * *(pStreamedTrack + 76)),
      *(*&gWorld.m_StaticTrack[4] + 52));
    result = 1LL;
    *(*(v12 + 4 * *(pStreamedTrack + 76)) | 0x20000000) = 2;
    *(pStreamedTrack + 88) = 0;
LABEL_19:
    __asm { lq           $s0, 0x40+var_10($sp) }
    goto LABEL_20;
  }
  result = 0LL;
  if ( v5 == 1 )
  {
    if ( *(pStreamedTrack + 96) )
      v9 = *(pStreamedTrack + 120);
    else
      v9 = *(pStreamedTrack + 112);
    *(pStreamedTrack + 20) = *(*&gWorld.m_StaticTrack[4] + 88) + 16 * v9;
    (*(*(*gWorld.m_StreamManager + 40) + 44))(
      *gWorld.m_StreamManager + *(*(*gWorld.m_StreamManager + 40) + 40),
      *(*(pStreamedTrack + 20) + 4),
      0LL);
    *(pStreamedTrack + 88) = 2;
LABEL_18:
    result = 0LL;
    goto LABEL_19;
  }
  __asm { lq           $s0, 0x40+var_10($sp) }
LABEL_20:
  __asm
  {
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return result;
}

// CB4StreamedTrack::UpdateStreamHighFSM(void)
__int64 __fastcall UpdateStreamHighFSM__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 v5; // $v1
  __int64 result; // $v0
  int v9; // $v1
  __int64 v10; // $v0
  int v11; // $a0
  int v12; // $s0

  __asm
  {
    sq           $s1, 0x40+var_20($sp)
    sq           $s2, 0x40+var_30($sp)
    sq           $s0, 0x40+var_10($sp)
  }
  v5 = *(pStreamedTrack + 84);
  if ( v5 == 2 )
  {
    if ( *(pStreamedTrack + 96) )
      v10 = *(pStreamedTrack + 48);
    else
      v10 = *(pStreamedTrack + 40);
    v11 = *(pStreamedTrack + 8);
    if ( v10 < 0 )
      LODWORD(v10) = v11 - -v10 % v11;
    *(pStreamedTrack + 72) = v10 % v11;
    (*(*(*gWorld.m_StreamManager + 40) + 28))(
      *gWorld.m_StreamManager + *(*(*gWorld.m_StreamManager + 40) + 24),
      *(pStreamedTrack + 4 * *(pStreamedTrack + 72) + 380),
      *(*(pStreamedTrack + 20) + 8));
    *(pStreamedTrack + 84) = 3;
    goto LABEL_18;
  }
  if ( v5 >= 3 )
  {
    result = 0LL;
    if ( v5 != 3 )
    {
      __asm { lq           $s0, 0x40+var_10($sp) }
      goto LABEL_20;
    }
    v12 = pStreamedTrack + 380;
    FixUp__24CB4StreamedTrackHighDatas(*(pStreamedTrack + 380 + 4 * *(pStreamedTrack + 72)));
    result = 1LL;
    *(*(v12 + 4 * *(pStreamedTrack + 72)) | 0x20000000) = 2;
    *(pStreamedTrack + 84) = 0;
LABEL_19:
    __asm { lq           $s0, 0x40+var_10($sp) }
    goto LABEL_20;
  }
  result = 0LL;
  if ( v5 == 1 )
  {
    if ( *(pStreamedTrack + 96) )
      v9 = *(pStreamedTrack + 116);
    else
      v9 = *(pStreamedTrack + 108);
    *(pStreamedTrack + 20) = *(*&gWorld.m_StaticTrack[4] + 88) + 16 * v9;
    (*(*(*gWorld.m_StreamManager + 40) + 44))(
      *gWorld.m_StreamManager + *(*(*gWorld.m_StreamManager + 40) + 40),
      **(pStreamedTrack + 20),
      0LL);
    *(pStreamedTrack + 84) = 2;
LABEL_18:
    result = 0LL;
    goto LABEL_19;
  }
  __asm { lq           $s0, 0x40+var_10($sp) }
LABEL_20:
  __asm
  {
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return result;
}

// CB4StreamedTrack::UpdateStreamFSM(void)
__int64 __fastcall UpdateStreamFSM__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 result; // $v0
  __int64 v7; // $v1
  int v8; // $s0
  __int64 v16; // $v1
  int v17; // $hi
  __int64 v18; // $v1
  bool v19; // dc
  __int64 v21; // $v1
  int v22; // $hi
  int v23; // $a3
  int v24; // $a1
  int v25; // $a2
  int v26; // $a0
  int v27; // $v0
  __int64 v28; // $v1
  int v29; // $hi
  __int64 v30; // $v0
  int v31; // $v1
  __int64 v32; // $v0
  int v33; // $v1
  __int64 v34; // $v0
  int v35; // $hi
  int v36; // $v0
  __int64 v37; // $v0
  int v38; // $a0
  int v39; // $a1
  __int64 v40; // $v0
  int v41; // $a0
  int v42; // $s0
  unsigned int v43; // $s2

  __asm
  {
    sq           $s0, 0x50+var_10($sp)
    sq           $s3, 0x50+var_40($sp)
  }
  result = &gWorld;
  __asm
  {
    sq           $s1, 0x50+var_20($sp)
    sq           $s2, 0x50+var_30($sp)
  }
  if ( gWorld.m_StreamManager[5] )
    goto LABEL_65;
  result = (*(*(*gWorld.m_StreamManager + 40) + 68))(*gWorld.m_StreamManager + *(*(*gWorld.m_StreamManager + 40) + 64)) ^ 1;
  if ( result )
    goto LABEL_65;
  v7 = *(pStreamedTrack + 80);
  v8 = *(*&gWorld.m_StaticTrack[4] + 84);
  if ( v7 == 1 )
  {
    if ( !*(pStreamedTrack + 84) )
      *(pStreamedTrack + 84) = 1;
    result = UpdateStreamHighFSM__16CB4StreamedTrack(pStreamedTrack);
    if ( !result )
    {
      __asm { lq           $s0, 0x50+var_10($sp) }
      goto LABEL_66;
    }
    result = 2LL;
    if ( !*(pStreamedTrack + 92) )
    {
      v16 = *(pStreamedTrack + 116) + 1;
      ++*(pStreamedTrack + 48);
      if ( v16 < 0 )
        v17 = (v8 - -v16 % v8) % v8;
      else
        v17 = v16 % v8;
      v18 = *(pStreamedTrack + 64);
      result = *(pStreamedTrack + 48) < v18;
      v19 = *(pStreamedTrack + 48) < v18;
      *(pStreamedTrack + 116) = v17;
      if ( !v19 )
      {
        result = 1LL;
        *(pStreamedTrack + 93) = 1;
      }
LABEL_64:
      *(pStreamedTrack + 80) = 0;
      goto LABEL_65;
    }
    *(pStreamedTrack + 80) = 2;
LABEL_65:
    __asm { lq           $s0, 0x50+var_10($sp) }
    goto LABEL_66;
  }
  result = v7 < 2;
  if ( v7 >= 2 )
  {
    result = 3LL;
    if ( v7 != 2 )
    {
      if ( v7 != 3 )
      {
        __asm { lq           $s0, 0x50+var_10($sp) }
LABEL_66:
        __asm { lq           $s1, 0x50+var_20($sp) }
        goto LABEL_67;
      }
      result = *(pStreamedTrack + 92);
      v23 = -1;
      if ( *(pStreamedTrack + 92) )
      {
        if ( *(pStreamedTrack + 96) )
          v23 = 1;
        v24 = *(pStreamedTrack + 52) + v23;
        v25 = *(pStreamedTrack + 116);
        v26 = *(pStreamedTrack + 40) + v23;
        v27 = *(pStreamedTrack + 44) + v23;
        *(pStreamedTrack + 48) += v23;
        v28 = v25 + v23;
        *(pStreamedTrack + 52) = v24;
        *(pStreamedTrack + 40) = v26;
        *(pStreamedTrack + 44) = v27;
        if ( v28 < 0 )
          v29 = (v8 - -v28 % v8) % v8;
        else
          v29 = v28 % v8;
        v30 = *(pStreamedTrack + 120) + v23;
        *(pStreamedTrack + 116) = v29;
        if ( v30 < 0 )
          LODWORD(v30) = v8 - -v30 % v8;
        v31 = v30 % v8;
        v32 = *(pStreamedTrack + 108) + v23;
        *(pStreamedTrack + 120) = v31;
        if ( v32 < 0 )
          LODWORD(v32) = v8 - -v32 % v8;
        v33 = v32 % v8;
        v34 = *(pStreamedTrack + 112) + v23;
        *(pStreamedTrack + 108) = v33;
        if ( v34 < 0 )
          LODWORD(v34) = v8 - -v34 % v8;
        v35 = v34 % v8;
        v36 = *(pStreamedTrack + 72);
        *(pStreamedTrack + 112) = v35;
        v37 = v36 + v23;
        v38 = *(pStreamedTrack + 8);
        if ( v37 < 0 )
          LODWORD(v37) = v38 - -v37 % v38;
        v39 = v37 % v38;
        v40 = *(pStreamedTrack + 76) + v23;
        v41 = *(pStreamedTrack + 12);
        if ( v40 < 0 )
          LODWORD(v40) = v41 - -v40 % v41;
        v42 = v40 % v41;
        v43 = pStreamedTrack + 380 + 4 * v39;
        ReleaseHighDetailUnit__16CB4StreamManagerP24CB4StreamedTrackHighData(gWorld.m_StreamManager, *v43);
        result = ReleaseLODUnit__16CB4StreamManagerP35CB4StreamedTrackLODAndCollisionData(
                   gWorld.m_StreamManager,
                   *(pStreamedTrack + 420 + 4 * v42));
        *v43 = 0;
        *(pStreamedTrack + 420 + 4 * v42) = 0;
      }
      goto LABEL_64;
    }
    if ( !*(pStreamedTrack + 88) )
      *(pStreamedTrack + 88) = 1;
    result = UpdateStreamLowFSM__16CB4StreamedTrack(pStreamedTrack);
    if ( !result )
    {
      __asm { lq           $s0, 0x50+var_10($sp) }
      goto LABEL_66;
    }
    result = 3LL;
    if ( !*(pStreamedTrack + 92) )
    {
      v21 = *(pStreamedTrack + 120) + 1;
      ++*(pStreamedTrack + 52);
      if ( v21 < 0 )
        v22 = (v8 - -v21 % v8) % v8;
      else
        v22 = v21 % v8;
      v19 = *(pStreamedTrack + 52) < *(pStreamedTrack + 68);
      *(pStreamedTrack + 120) = v22;
      if ( !v19 )
        *(pStreamedTrack + 94) = 1;
      result = 3LL;
    }
    *(pStreamedTrack + 80) = 3;
    goto LABEL_65;
  }
  __asm { lq           $s0, 0x50+var_10($sp) }
  if ( *(pStreamedTrack + 80) )
  {
    __asm { lq           $s1, 0x50+var_20($sp) }
LABEL_67:
    __asm { lq           $s2, 0x50+var_30($sp) }
    goto LABEL_68;
  }
  if ( *(pStreamedTrack + 48) < *(pStreamedTrack + 64) )
  {
    *(pStreamedTrack + 96) = 1;
    *(pStreamedTrack + 80) = 1;
    goto LABEL_20;
  }
  if ( *(pStreamedTrack + 56) < *(pStreamedTrack + 40) )
  {
    *(pStreamedTrack + 80) = 1;
    *(pStreamedTrack + 96) = 0;
    goto LABEL_20;
  }
  if ( *(pStreamedTrack + 52) >= *(pStreamedTrack + 68) )
  {
    if ( *(pStreamedTrack + 60) >= *(pStreamedTrack + 44) )
      goto LABEL_20;
    *(pStreamedTrack + 96) = 0;
  }
  else
  {
    *(pStreamedTrack + 96) = 1;
  }
  *(pStreamedTrack + 80) = 2;
LABEL_20:
  result = *(pStreamedTrack + 93);
  __asm { lq           $s0, 0x50+var_10($sp) }
  if ( !*(pStreamedTrack + 93) )
    goto LABEL_66;
  result = *(pStreamedTrack + 94);
  __asm { lq           $s1, 0x50+var_20($sp) }
  if ( !*(pStreamedTrack + 94) )
    goto LABEL_67;
  result = *(pStreamedTrack + 92);
  __asm { lq           $s2, 0x50+var_30($sp) }
  if ( !*(pStreamedTrack + 92) )
  {
    result = 1LL;
    *(pStreamedTrack + 92) = 1;
  }
LABEL_68:
  __asm { lq           $s3, 0x50+var_40($sp) }
  return result;
}

// CB4StreamedTrack::GetUnit(int, EB4TrackType)
__int64 __fastcall GetUnit__16CB4StreamedTracki12EB4TrackType(int pStreamedTrack, __int64 a2, __int64 a3)
{
  _DWORD *v4; // $v0
  __int64 v5; // $a3
  int v6; // $a0
  __int64 v7; // $hi
  __int64 result; // $v0
  int v9; // $v0
  __int64 v10; // $a1
  int v11; // $v0
  int v12; // $a0

  v4 = (pStreamedTrack + 4 * a3);
  v5 = v4[12];
  if ( v5 != v4[16] )
  {
    v6 = v4[2];
    v7 = v5 < 0 ? (v6 - -v5 % v6) % v6 : v5 % v6;
    if ( a2 == v7 )
      return 0LL;
  }
  if ( a2 < 0 || a2 >= *(pStreamedTrack + 4 * a3 + 8) )
    return 0LL;
  v9 = 4 * a2;
  if ( a3 == 1 )
  {
    v10 = *(pStreamedTrack + v9 + 420);
    if ( !*(pStreamedTrack + v9 + 420) )
      return 0LL;
    result = 0LL;
    if ( *(v10 | 0x20000000) == 2LL )
      return v10;
    return result;
  }
  v11 = pStreamedTrack + v9;
  v12 = *(v11 + 380);
  if ( !v12 )
    return 0LL;
  result = *(v11 + 380);
  if ( *(v12 | 0x20000000) != 2LL )
    return 0LL;
  return result;
}

// CB4StreamedTrack::GetUnitOriginalID(int)
__int64 __fastcall GetUnitOriginalID__16CB4StreamedTracki(int pStreamedTrack, __int64 a2)
{
  __int64 Unit__16CB4StreamedTracki12EB4TrackType; // $v0

  if ( a2 >= 0
    && (Unit__16CB4StreamedTracki12EB4TrackType = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, a2, 1LL)) != 0 )
  {
    return *(Unit__16CB4StreamedTracki12EB4TrackType + 4);
  }
  else
  {
    return -1LL;
  }
}

// CB4StreamedTrack::Update(void)
__int64 __fastcall Update__16CB4StreamedTrack(unsigned int pStreamedTrack)
{
  __int64 result; // $v0
  __int64 UnitForCurrentBasis__C16CB4StreamedTrack; // $s1
  int v6; // $v1
  int v7; // $a1
  __int64 v8; // $v0
  __int64 v9; // $v1
  bool v10; // $v1
  __int64 AnotherUnitForwards__16CB4StreamedTrack; // $v0
  __int64 v12; // $v0
  int v13; // $a0
  bool v14; // dc
  int v15; // $v0
  bool v16; // $a1
  __int64 v17; // $s1
  __int64 v18; // $v0
  int v19; // $v1
  int v20; // $a0
  int v21; // $a1
  int v22; // $v1
  __int64 v23; // $v0
  int v24; // $a0
  int v25; // $v1
  __int64 v26; // $v0
  int v27; // $a0

  __asm
  {
    sq           $s0, 0x30+var_10($sp)
    sq           $s1, 0x30+var_20($sp)
  }
  if ( !*&gWorld.m_CrashScore[1000] )
  {
    result = 1LL;
    goto LABEL_46;
  }
  UpdateStreamFSM__16CB4StreamedTrack(pStreamedTrack);
  UnitForCurrentBasis__C16CB4StreamedTrack = GetUnitForCurrentBasis__C16CB4StreamedTrack(pStreamedTrack);
  if ( UnitForCurrentBasis__C16CB4StreamedTrack == -1 )
    UnitForCurrentBasis__C16CB4StreamedTrack = *(pStreamedTrack + 4);
  v6 = *(pStreamedTrack + 4);
  if ( UnitForCurrentBasis__C16CB4StreamedTrack == v6 )
  {
    if ( geStreamedWorldDiskSemaphore == *(pStreamedTrack + 28) )
      geStreamedWorldDiskSemaphore = -1;
    goto LABEL_21;
  }
  v7 = UnitForCurrentBasis__C16CB4StreamedTrack;
  if ( *(pStreamedTrack + 95) )
    goto LABEL_24;
  gSoundManager.base.bankManager[17276] = 1;
  if ( geStreamedWorldDiskSemaphore == -1LL )
    geStreamedWorldDiskSemaphore = *(pStreamedTrack + 28);
  if ( geStreamedWorldDiskSemaphore == *(pStreamedTrack + 28) )
  {
    v9 = *(pStreamedTrack + 4);
    if ( v9 >= UnitForCurrentBasis__C16CB4StreamedTrack )
      v10 = v9 - UnitForCurrentBasis__C16CB4StreamedTrack >= 5LL;
    else
      v10 = UnitForCurrentBasis__C16CB4StreamedTrack - v9 < 5LL;
    *(pStreamedTrack + 96) = v10;
    if ( v10 )
      AnotherUnitForwards__16CB4StreamedTrack = ReadAnotherUnitForwards__16CB4StreamedTrack(pStreamedTrack);
    else
      AnotherUnitForwards__16CB4StreamedTrack = ReadAnotherUnitBackwards__16CB4StreamedTrack(pStreamedTrack);
    if ( AnotherUnitForwards__16CB4StreamedTrack )
      *(pStreamedTrack + 95) = 1;
LABEL_21:
    v8 = *(pStreamedTrack + 95);
    goto LABEL_22;
  }
  v8 = *(pStreamedTrack + 95);
LABEL_22:
  v6 = *(pStreamedTrack + 4);
  if ( !v8 )
  {
LABEL_45:
    result = 1LL;
    *(pStreamedTrack + 100) = *pStreamedTrack;
    goto LABEL_46;
  }
  v7 = UnitForCurrentBasis__C16CB4StreamedTrack;
LABEL_24:
  v12 = UnitForCurrentBasis__C16CB4StreamedTrack - v6;
  v13 = v6;
  if ( v12 >= 0 )
  {
    v14 = v12 < 5;
    v15 = v7 - v6;
    if ( v14 )
      goto LABEL_30;
    v13 = v6 + *(pStreamedTrack + 12);
  }
  else
  {
    v14 = v12 >= -4;
    v15 = v7 - v6;
    if ( v14 )
      goto LABEL_30;
    v7 += *(pStreamedTrack + 12);
  }
  v15 = v7 - v13;
LABEL_30:
  v16 = 0;
  v17 = (v15 + 3) >= 7;
  if ( *(pStreamedTrack + 44) != *(pStreamedTrack + 60) )
  {
LABEL_34:
    v18 = v16;
    goto LABEL_35;
  }
  v18 = 0LL;
  if ( *(pStreamedTrack + 52) == *(pStreamedTrack + 68) )
  {
    v18 = 0LL;
    if ( *(pStreamedTrack + 40) == *(pStreamedTrack + 56) )
    {
      v16 = *(pStreamedTrack + 48) == *(pStreamedTrack + 64);
      goto LABEL_34;
    }
  }
LABEL_35:
  if ( v18 )
  {
    v17 = 0LL;
    v19 = *(pStreamedTrack + 32);
    if ( *(pStreamedTrack + 96) )
    {
      v20 = *pStreamedTrack + 1;
      v21 = *(pStreamedTrack + 36) + 1;
      ++*(pStreamedTrack + 4);
      v22 = v19 + 1;
    }
    else
    {
      v20 = *pStreamedTrack - 1;
      v21 = *(pStreamedTrack + 36) - 1;
      --*(pStreamedTrack + 4);
      v22 = v19 - 1;
    }
    *pStreamedTrack = v20;
    *(pStreamedTrack + 36) = v21;
    *(pStreamedTrack + 32) = v22;
    v23 = *(pStreamedTrack + 4);
    v24 = *(pStreamedTrack + 12);
    if ( v23 < 0 )
      LODWORD(v23) = v24 - -v23 % v24;
    v25 = v23 % v24;
    v26 = *pStreamedTrack;
    *(pStreamedTrack + 4) = v25;
    v27 = *(pStreamedTrack + 8);
    if ( v26 < 0 )
      LODWORD(v26) = v27 - -v26 % v27;
    *(pStreamedTrack + 95) = 0;
    *pStreamedTrack = v26 % v27;
    geStreamedWorldDiskSemaphore = -1;
    FlipNow__15CB4SoundManager(&gSoundManager);
  }
  result = 0LL;
  if ( !v17 )
    goto LABEL_45;
LABEL_46:
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    lq           $s1, 0x30+var_20($sp)
  }
  return result;
}

// CB4StreamedTrack::UpdateStreamPVS(void)
__int64 __fastcall UpdateStreamPVS__16CB4StreamedTrack(unsigned int pStreamedTrack)
{
  __int64 result; // $v0
  int Unit__16CB4StreamedTracki12EB4TrackType; // $v0
  __int64 v14; // $a1
  int v15; // $v0
  __int64 v16; // $a2
  __int64 v17; // $a1
  int v18; // $s6
  __int64 v19; // $v1
  int v20; // $s7
  int v21; // $s0
  int v22; // $a0
  __int64 v23; // $a4
  __int64 v24; // $a2
  __int64 v25; // $s5
  int v26; // $v0
  int v27; // $s3
  __int64 v30; // $s2
  __int64 v31; // $a1
  int v32; // $a0
  __int64 v33; // $hi
  __int64 v34; // $a1
  int v35; // $a2
  __int64 v36; // $hi
  int v37; // $v0
  int v38; // $a0

  __asm
  {
    sq           $s1, 0xB0+var_20($sp)
    sq           $s0, 0xB0+var_10($sp)
    sq           $s2, 0xB0+var_30($sp)
    sq           $s3, 0xB0+var_40($sp)
    sq           $s4, 0xB0+var_50($sp)
    sq           $s5, 0xB0+var_60($sp)
    sq           $s6, 0xB0+var_70($sp)
    sq           $s7, 0xB0+var_80($sp)
    sq           $fp, 0xB0+var_90($sp)
  }
  result = *(pStreamedTrack + 92);
  __asm { lq           $s0, 0xB0+var_10($sp) }
  if ( *(pStreamedTrack + 92) )
  {
    Unit__16CB4StreamedTracki12EB4TrackType = GetUnit__16CB4StreamedTracki12EB4TrackType(
                                                pStreamedTrack,
                                                *pStreamedTrack,
                                                0LL);
    v14 = *(pStreamedTrack + 100);
    *(pStreamedTrack + 492) = Unit__16CB4StreamedTracki12EB4TrackType;
    v15 = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, v14, 0LL);
    *(pStreamedTrack + 496) = v15;
    v16 = *(v15 + 4);
    v17 = *(*(pStreamedTrack + 492) + 4);
    if ( v16 < v17 )
    {
      v19 = v16 + *(*&gWorld.m_StaticTrack[4] + 84);
      v18 = v19 - v17;
      if ( v17 + 4 < v19 )
        v18 = 0;
    }
    else
    {
      v18 = 0;
      if ( v17 + 4 >= v16 )
        v18 = v16 - v17;
    }
    v20 = pStreamedTrack + 164;
    memset((pStreamedTrack + 164), 0, 0x48uLL);
    memset((pStreamedTrack + 236), 0, 0x48uLL);
    v21 = 0;
    memset((pStreamedTrack + 308), 0, 0x48uLL);
    v22 = 0;
    while ( 1 )
    {
      v23 = 0LL;
      v24 = 0LL;
      v25 = v21 + 1;
      while ( v24 < 17 )
      {
        v26 = *(pStreamedTrack + 496) + 169 * v24;
        if ( *(*(pStreamedTrack + 492) + v22 + 291) - v18 == *(v26 + 291) )
        {
          if ( *(v26 + 292) )
          {
            v23 = 1LL;
            break;
          }
          v24 = v24 + 1;
        }
        else
        {
          v24 = v24 + 1;
        }
      }
      if ( !v23 )
        goto LABEL_33;
      v27 = 0;
      _$V1 = *(*(pStreamedTrack + 492) + 169 * v21 + 291);
      __asm
      {
        pabsw        $v0, $v1
        pextlw       $v0, $zero, $v0
      }
      if ( _$V0 < 5 )
      {
        v31 = *pStreamedTrack + _$V1;
        v32 = *(pStreamedTrack + 8);
        v33 = v31 < 0 ? (v32 - -v31 % v32) % v32 : v31 % v32;
        v30 = 0LL;
        v27 = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, v33, 0LL);
      }
      else
      {
        v30 = 1LL;
      }
      v34 = *(pStreamedTrack + 4) + *(*(pStreamedTrack + 492) + 169 * v21 + 291);
      v35 = *(pStreamedTrack + 12);
      v36 = v34 < 0 ? (v35 - -v34 % v35) % v35 : v34 % v35;
      v37 = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, v36, 1LL);
      if ( !v30 )
        break;
      v38 = 4 * v21;
      if ( *(v37 + 80) > 0LL )
      {
        *(v20 + 4 * v21) = v37;
        goto LABEL_30;
      }
LABEL_32:
      *(pStreamedTrack + 308 + v38) = v37 + 152;
LABEL_33:
      ++v21;
      result = v25 < 17;
      v22 = 169 * v25;
      if ( v25 >= 17 )
      {
        __asm { lq           $s0, 0xB0+var_10($sp) }
        goto LABEL_35;
      }
    }
    v38 = 4 * v21;
    *(v20 + 4 * v21) = v27;
LABEL_30:
    if ( *(v37 + 80) > 0LL )
      *(pStreamedTrack + 236 + v38) = v37;
    goto LABEL_32;
  }
LABEL_35:
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

// CB4StreamedTrack::IntersectLineNearestWithUnit(unsigned int, const CGtLine &, CGtPolygonIntersectionResult *)
__int64 __fastcall IntersectLineNearestWithUnit__16CB4StreamedTrackUiRC7CGtLineP28CGtPolygonIntersectionResult(
        unsigned int pStreamedTrack,
        __int64 a2,
        int a3,
        int a4)
{
  if ( *(*&gWorld.m_StaticTrack[4] + 80) )
    return IntersectLineNearestWithWorld__16CB4StreamedTrackRC7CGtLineP28CGtPolygonIntersectionResult(
             pStreamedTrack,
             a3,
             a4);
  else
    return InternalIntersectLineNearestWithUnit__16CB4StreamedTrackUiRC7CGtLineP28CGtPolygonIntersectionResult(
             pStreamedTrack,
             a2,
             a3,
             a4);
}

// CB4StreamedTrack::InternalIntersectLineNearestWithUnit(unsigned int, const CGtLine &, CGtPolygonIntersectionResult *)
__int64 __fastcall InternalIntersectLineNearestWithUnit__16CB4StreamedTrackUiRC7CGtLineP28CGtPolygonIntersectionResult(
        int pStreamedTrack,
        __int64 a2,
        int a3,
        int a4)
{
  __int64 Unit__16CB4StreamedTracki12EB4TrackType; // $v0
  __int64 result; // $v0

  __asm
  {
    sq           $s0, 0x30+var_10($sp)
    sq           $s1, 0x30+var_20($sp)
  }
  Unit__16CB4StreamedTracki12EB4TrackType = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, a2, 1LL);
  if ( Unit__16CB4StreamedTracki12EB4TrackType )
    result = IntersectLineNearest__C18CGtCollisionKDTreeRC7CGtLineP28CGtPolygonIntersectionResult(
               *(Unit__16CB4StreamedTracki12EB4TrackType + 144),
               a3,
               a4) == 1;
  else
    result = 0LL;
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    lq           $s1, 0x30+var_20($sp)
  }
  return result;
}

// CB4StreamedTrack::IntersectLineNearestWithWorld(const CGtLine &, CGtPolygonIntersectionResult *)
__int64 __fastcall IntersectLineNearestWithWorld__16CB4StreamedTrackRC7CGtLineP28CGtPolygonIntersectionResult(
        int pStreamedTrack,
        int a2,
        int a3)
{
  __int64 result; // $v0
  __int64 v14; // $v1
  __int64 v15; // $s0
  __int64 v16; // $s6
  int v17; // $a1
  __int64 v18; // $hi
  bool v19; // dc

  __asm
  {
    sq           $s2, 0x80+var_30($sp)
    sq           $s3, 0x80+var_40($sp)
    sq           $s4, 0x80+var_50($sp)
    sq           $s0, 0x80+var_10($sp)
    sq           $s1, 0x80+var_20($sp)
    sq           $s5, 0x80+var_60($sp)
    sq           $s6, 0x80+var_70($sp)
  }
  if ( *(*&gWorld.m_StaticTrack[4] + 80) )
  {
    result = IntersectLineNearest__C18CGtCollisionKDTreeRC7CGtLineP28CGtPolygonIntersectionResult(
               *(*&gWorld.m_StaticTrack[4] + 80),
               a2,
               a3) == 1;
  }
  else
  {
    result = 0LL;
    if ( *(pStreamedTrack + 92) )
    {
      v14 = *(pStreamedTrack + 104) - 4;
      v15 = v14;
      if ( v14 < 0 )
        v15 = v14 + *(pStreamedTrack + 12);
      v16 = v15 + 9;
      if ( v15 >= v16 )
      {
LABEL_13:
        result = 0LL;
      }
      else
      {
        while ( 1 )
        {
          v17 = *(pStreamedTrack + 12);
          v18 = v15 < 0 ? (v17 - -v15 % v17) % v17 : v15 % v17;
          if ( LineIntersectsOrIsInsideHull__C20CB4StreamedTrackHullRC7CGtLine(
                 *(pStreamedTrack + 420 + 4 * v18) + 96,
                 a2) )
          {
            v19 = InternalIntersectLineNearestWithUnit__16CB4StreamedTrackUiRC7CGtLineP28CGtPolygonIntersectionResult(
                    pStreamedTrack,
                    v18,
                    a2,
                    a3) != 0;
            result = 1LL;
            if ( v19 )
              break;
          }
          v15 = v15 + 1;
          if ( v15 >= v16 )
            goto LABEL_13;
        }
      }
    }
  }
  __asm
  {
    lq           $s0, 0x80+var_10($sp)
    lq           $s1, 0x80+var_20($sp)
    lq           $s2, 0x80+var_30($sp)
    lq           $s3, 0x80+var_40($sp)
    lq           $s4, 0x80+var_50($sp)
    lq           $s5, 0x80+var_60($sp)
    lq           $s6, 0x80+var_70($sp)
  }
  return result;
}

// CB4StreamedTrack::IntersectLineWithUnit(unsigned int, const CGtLine &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *)
__int64 __fastcall IntersectLineWithUnit__16CB4StreamedTrackUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(
        int pStreamedTrack,
        __int64 a2,
        int a3,
        __int64 (__fastcall *a4)(_QWORD, _QWORD),
        int a5)
{
  __int64 result; // $v0
  __int64 Unit__16CB4StreamedTracki12EB4TrackType; // $v0

  __asm
  {
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
    sq           $s2, 0x40+var_30($sp)
  }
  if ( *(*&gWorld.m_StaticTrack[4] + 80) )
  {
    IntersectLine__C18CGtCollisionKDTreeRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(
      *(*&gWorld.m_StaticTrack[4] + 80),
      a3,
      a4,
      a5);
    result = 1LL;
  }
  else
  {
    Unit__16CB4StreamedTracki12EB4TrackType = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, a2, 1LL);
    if ( Unit__16CB4StreamedTracki12EB4TrackType )
    {
      IntersectLine__C18CGtCollisionKDTreeRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(
        *(Unit__16CB4StreamedTracki12EB4TrackType + 144),
        a3,
        a4,
        a5);
      result = 1LL;
    }
    else
    {
      result = 0LL;
    }
  }
  __asm
  {
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return result;
}

// CB4StreamedTrack::IntersectSphereWithUnit(unsigned int, GtMathPs2::CGtSphere, bool (*)(const CGtPolygonIntersectionResult &, void *), void *)
__int64 __fastcall IntersectSphereWithUnit__16CB4StreamedTrackUiGQ29GtMathPs29CGtSpherePFRC28CGtPolygonIntersectionResultPv_bPv(
        int pStreamedTrack,
        __int64 a2,
        __int64 _$A2,
        __int64 (__fastcall *a4)(_QWORD, __int64),
        __int64 a5)
{
  __int64 result; // $v0
  __int64 Unit__16CB4StreamedTracki12EB4TrackType; // $v0

  __asm
  {
    sq           $s0, 0x40+var_10($sp)
    sq           $s1, 0x40+var_20($sp)
    sq           $s2, 0x40+var_30($sp)
    por          $s0, $zero, $a2
  }
  if ( *(*&gWorld.m_StaticTrack[4] + 80) )
  {
    __asm { por          $a1, $zero, $s0 }
    IntersectSphere__C18CGtCollisionKDTreeGQ29GtMathPs29CGtSpherePFRC28CGtPolygonIntersectionResultPv_bPv(
      *(*&gWorld.m_StaticTrack[4] + 80),
      _$A1,
      a4,
      a5);
    result = 1LL;
  }
  else
  {
    Unit__16CB4StreamedTracki12EB4TrackType = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, a2, 1LL);
    if ( Unit__16CB4StreamedTracki12EB4TrackType )
    {
      __asm { por          $a1, $zero, $s0 }
      IntersectSphere__C18CGtCollisionKDTreeGQ29GtMathPs29CGtSpherePFRC28CGtPolygonIntersectionResultPv_bPv(
        *(Unit__16CB4StreamedTracki12EB4TrackType + 144),
        _$A1,
        a4,
        a5);
      result = 1LL;
    }
    else
    {
      result = 0LL;
    }
  }
  __asm
  {
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return result;
}

// CB4StreamedTrack::GetIrradiance(int, GtMathPs2::CGtV3d, CGtIrradianceMap *, float)
__int64 __usercall GetIrradiance__16CB4StreamedTrackiGQ29GtMathPs26CGtV3dP16CGtIrradianceMapf@<$v0>(
        int pStreamedTrack@<$a0>,
        __int64 a2@<$a1>,
        __int64 _$A2@<$a2>,
        unsigned int a4@<$a3>,
        float a5@<$f12>)
{
  __int64 v10; // $ra
  __int64 result; // $v0
  int Unit__16CB4StreamedTracki12EB4TrackType; // $s3
  int v18; // $v0
  bool v19; // dc
  unsigned __int16 *v20; // $a4
  unsigned int v21; // $a3
  float *v22; // $a0
  char *v23; // $v1
  __int64 v24; // $a2
  int v25; // $v0
  float *v26; // $a1
  char *v27; // $a0
  __int64 v28; // $a2
  int v29; // $v0
  float *v30; // $a1
  __int64 v31; // $a2
  unsigned int v32; // $a0
  char *v33; // $v1
  int v34; // $v0
  char *v35; // $a1
  __int64 v36; // $a2
  float *v37; // $a0
  int v38; // $v0
  float *v39; // $a1
  __int64 v40; // $a2
  unsigned int v41; // $a0
  char *v42; // $v1
  int v43; // $v0
  char *v44; // $a1
  __int64 v45; // $a2
  float *v46; // $a0
  int v47; // $v0
  float *v48; // $a0
  unsigned int v49; // $a3
  float *v50; // $a0
  char *v51; // $v1
  __int64 v52; // $a2
  int v53; // $v0
  float *v54; // $a1
  char *v55; // $a0
  __int64 v56; // $a2
  int v57; // $v0
  float *v58; // $a1
  __int64 v59; // $a2
  unsigned int v60; // $a0
  char *v61; // $v1
  int v62; // $v0
  char *v63; // $a1
  __int64 v64; // $a2
  float *v65; // $a0
  int v66; // $v0
  float *v67; // $a1
  __int64 v68; // $a2
  unsigned int v69; // $a0
  char *v70; // $v1
  int v71; // $v0
  char *v72; // $a1
  __int64 v73; // $a2
  float *v74; // $a0
  int v75; // $v0
  float *v76; // $v1
  float *v77; // $v0
  __int64 v78; // $a1
  float v79; // $f0
  float v80; // $f1
  float v81; // $f0
  __int64 v82; // $v1
  __int64 v83; // $a0
  __int64 v84; // $a1
  __int128 v90; // [sp+0h] [-190h] BYREF
  _BYTE v91[84]; // [sp+20h] [-170h] BYREF
  float v92; // [sp+74h] [-11Ch]
  float v93; // [sp+78h] [-118h]
  unsigned __int16 *v94; // [sp+80h] [-110h]
  int v95; // [sp+84h] [-10Ch]
  _QWORD v96[2]; // [sp+90h] [-100h] BYREF
  _QWORD v97[2]; // [sp+A0h] [-F0h] BYREF
  int v98; // [sp+B0h] [-E0h]
  float v99; // [sp+C0h] [-D0h] BYREF
  _BYTE v100[12]; // [sp+C4h] [-CCh] BYREF
  _BYTE v101[32]; // [sp+D0h] [-C0h] BYREF
  float v102; // [sp+F0h] [-A0h] BYREF
  _BYTE v103[12]; // [sp+F4h] [-9Ch] BYREF
  _BYTE v104[32]; // [sp+100h] [-90h] BYREF
  float v105[4]; // [sp+120h] [-70h] BYREF
  __int64 v106; // [sp+130h] [-60h]

  __asm
  {
    sq           $s0, 0x190+var_10($sp)
    sq           $s1, 0x190+var_20($sp)
    sq           $s2, 0x190+var_30($sp)
    por          $s1, $zero, $a2
    sq           $s4, 0x190+var_50($sp)
    sq           $s3, 0x190+var_40($sp)
  }
  v106 = v10;
  for ( result = 1LL; result != -1; result = result - 1 )
    ;
  if ( a2 >= 0 )
  {
    __asm { sq           $s1, 0x190+var_190($sp) }
    Unit__16CB4StreamedTracki12EB4TrackType = GetUnit__16CB4StreamedTracki12EB4TrackType(pStreamedTrack, a2, 1LL);
    v18 = *(pStreamedTrack + 28);
    v105[0] = 0.0;
    v105[1] = -a5;
    v105[2] = 0.0;
    __asm
    {
      lqc2         $vf2, 0x190+var_70($sp)
      lqc2         $vf1, 0x190+var_190($sp)
      vadd.xyz     $vf1, $vf1, $vf2
      sqc2         $vf1, 0x190+var_180($sp)
    }
    v19 = IntersectLineNearestWithUnit__16CB4StreamedTrackUiRC7CGtLineP28CGtPolygonIntersectionResult(
            gWorld.m_StreamedTrackPlayers[v18],
            a2,
            &v90,
            v91) == 0;
    result = v95;
    if ( !v19 )
    {
      v20 = v94;
      if ( v95 )
      {
        v49 = 9 * v94[5] + *(Unit__16CB4StreamedTracki12EB4TrackType + 148);
        v50 = v96 + 1;
        v51 = (v49 + 1);
        LODWORD(v52) = 2;
        *v96 = ((*v49 + *v49) * 1.6) * 0.0078125;
        do
        {
          v53 = *v51;
          v52 = v52 - 1;
          ++v51;
          *v50++ = ((v53 * 0.75) * 1.6) * 0.0078125;
        }
        while ( v52 >= 0 );
        v54 = v97;
        v55 = (v49 + 4);
        LODWORD(v56) = 4;
        do
        {
          v57 = *v55;
          v56 = v56 + 1;
          ++v55;
          *v54++ = ((v57 * 0.5) * 1.6) * 0.0078125;
        }
        while ( v56 < 9 );
        v58 = v100;
        LODWORD(v59) = 2;
        v60 = 9 * v20[4] + *(Unit__16CB4StreamedTracki12EB4TrackType + 148);
        v61 = (v60 + 1);
        v99 = ((*v60 + *v60) * 1.6) * 0.0078125;
        do
        {
          v62 = *v61;
          v59 = v59 - 1;
          ++v61;
          *v58++ = ((v62 * 0.75) * 1.6) * 0.0078125;
        }
        while ( v59 >= 0 );
        v63 = (v60 + 4);
        LODWORD(v64) = 4;
        v65 = v101;
        do
        {
          v66 = *v63;
          v64 = v64 + 1;
          ++v63;
          *v65++ = ((v66 * 0.5) * 1.6) * 0.0078125;
        }
        while ( v64 < 9 );
        v67 = v103;
        LODWORD(v68) = 2;
        v69 = 9 * v20[6] + *(Unit__16CB4StreamedTracki12EB4TrackType + 148);
        v70 = (v69 + 1);
        v102 = ((*v69 + *v69) * 1.6) * 0.0078125;
        do
        {
          v71 = *v70;
          v68 = v68 - 1;
          ++v70;
          *v67++ = ((v71 * 0.75) * 1.6) * 0.0078125;
        }
        while ( v68 >= 0 );
        v72 = (v69 + 4);
        LODWORD(v73) = 4;
        v74 = v104;
        do
        {
          v75 = *v72;
          v73 = v73 + 1;
          ++v72;
          *v74++ = ((v75 * 0.5) * 1.6) * 0.0078125;
        }
        while ( v73 < 9 );
        v48 = &v102;
      }
      else
      {
        v21 = 9 * v94[3] + *(Unit__16CB4StreamedTracki12EB4TrackType + 148);
        v22 = v96 + 1;
        v23 = (v21 + 1);
        LODWORD(v24) = 2;
        *v96 = ((*v21 + *v21) * 1.6) * 0.0078125;
        do
        {
          v25 = *v23;
          v24 = v24 - 1;
          ++v23;
          *v22++ = ((v25 * 0.75) * 1.6) * 0.0078125;
        }
        while ( v24 >= 0 );
        v26 = v97;
        v27 = (v21 + 4);
        LODWORD(v28) = 4;
        do
        {
          v29 = *v27;
          v28 = v28 + 1;
          ++v27;
          *v26++ = ((v29 * 0.5) * 1.6) * 0.0078125;
        }
        while ( v28 < 9 );
        v30 = v100;
        LODWORD(v31) = 2;
        v32 = 9 * v20[4] + *(Unit__16CB4StreamedTracki12EB4TrackType + 148);
        v33 = (v32 + 1);
        v99 = ((*v32 + *v32) * 1.6) * 0.0078125;
        do
        {
          v34 = *v33;
          v31 = v31 - 1;
          ++v33;
          *v30++ = ((v34 * 0.75) * 1.6) * 0.0078125;
        }
        while ( v31 >= 0 );
        v35 = (v32 + 4);
        LODWORD(v36) = 4;
        v37 = v101;
        do
        {
          v38 = *v35;
          v36 = v36 + 1;
          ++v35;
          *v37++ = ((v38 * 0.5) * 1.6) * 0.0078125;
        }
        while ( v36 < 9 );
        v39 = v103;
        LODWORD(v40) = 2;
        v41 = 9 * v20[5] + *(Unit__16CB4StreamedTracki12EB4TrackType + 148);
        v42 = (v41 + 1);
        v102 = ((*v41 + *v41) * 1.6) * 0.0078125;
        do
        {
          v43 = *v42;
          v40 = v40 - 1;
          ++v42;
          *v39++ = ((v43 * 0.75) * 1.6) * 0.0078125;
        }
        while ( v40 >= 0 );
        v44 = (v41 + 4);
        LODWORD(v45) = 4;
        v46 = v104;
        do
        {
          v47 = *v44;
          v45 = v45 + 1;
          ++v44;
          *v46++ = ((v47 * 0.5) * 1.6) * 0.0078125;
        }
        while ( v45 < 9 );
        v48 = &v102;
      }
      v76 = v96;
      v77 = &v99;
      LODWORD(v78) = 8;
      do
      {
        v78 = v78 - 1;
        *v77 = *v77 - *v76;
        *v48 = *v48 - *v76;
        *v77 = *v77 * v92;
        *v48 = *v48 * v93;
        v79 = *v77++;
        v80 = *v76 + v79;
        *v76 = v80;
        v81 = *v48++;
        *v76++ = v80 + v81;
      }
      while ( v78 >= 0 );
      v82 = v96[1];
      v83 = v97[0];
      v84 = v97[1];
      *a4 = v96[0];
      *(a4 + 8) = v82;
      *(a4 + 16) = v83;
      *(a4 + 24) = v84;
      result = v98;
      *(a4 + 32) = v98;
    }
  }
  __asm
  {
    lq           $s0, 0x190+var_10($sp)
    lq           $s1, 0x190+var_20($sp)
    lq           $s2, 0x190+var_30($sp)
    lq           $s3, 0x190+var_40($sp)
    lq           $s4, 0x190+var_50($sp)
  }
  return result;
}

// CB4StreamedTrack::ComputeVehicleRenderData(CB4VehicleEssentialParams *, float)
__int64 __usercall ComputeVehicleRenderData__16CB4StreamedTrackP25CB4VehicleEssentialParamsf@<$v0>(
        int pStreamedTrack@<$a0>,
        int a2@<$a1>,
        float a3@<$f12>)
{
  __int64 result; // $v0
  __int64 v5; // $a1

  result = *(pStreamedTrack + 92);
  _$A3 = a2;
  if ( !*(pStreamedTrack + 92) )
    return result;
  v5 = *(a2 + 90);
  if ( v5 < 0 )
    return result;
  __asm { lq           $a2, 0x30($a3) }
  return GetIrradiance__16CB4StreamedTrackiGQ29GtMathPs26CGtV3dP16CGtIrradianceMapf(
           gWorld.m_StreamedTrackPlayers[*(pStreamedTrack + 28)],
           v5,
           _$A2,
           _$A3 + 92,
           a3);
}

// CB4StreamedTrack::ForEveryUnitInSafeArea(void (*)(CB4StreamedTrackLODAndCollisionData *, int, void *), void *)
__int64 __fastcall ForEveryUnitInSafeArea__16CB4StreamedTrackPFP35CB4StreamedTrackLODAndCollisionDataiPv_vPv(
        int pStreamedTrack,
        void (__fastcall *a2)(_QWORD))
{
  __int64 v9; // $v1
  __int64 v11; // $s0
  __int64 v12; // $v1
  __int64 result; // $v0
  __int64 v14; // $s3
  int v15; // $s2
  int v16; // $a1
  int v17; // $hi

  __asm
  {
    sq           $s1, 0x70+var_20($sp)
    sq           $s4, 0x70+var_50($sp)
    sq           $s5, 0x70+var_60($sp)
    sq           $s0, 0x70+var_10($sp)
    sq           $s2, 0x70+var_30($sp)
    sq           $s3, 0x70+var_40($sp)
  }
  v9 = *(pStreamedTrack + 104) - 4;
  if ( v9 < 0 )
    v9 = v9 + *(pStreamedTrack + 12);
  v11 = v9;
  v12 = v9 + 9;
  result = v11 < v12;
  v14 = v12;
  if ( v11 < v12 )
  {
    v15 = pStreamedTrack + 420;
    do
    {
      v16 = *(pStreamedTrack + 12);
      if ( v11 < 0 )
        v17 = (v16 - -v11 % v16) % v16;
      else
        v17 = v11 % v16;
      v11 = v11 + 1;
      a2(*(v15 + 4 * v17));
      result = v11 < v14;
    }
    while ( v11 < v14 );
  }
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

// CB4StreamedTrack::AllowChevronRender(void)
__int64 __fastcall AllowChevronRender__16CB4StreamedTrack(int pStreamedTrack)
{
  int v4; // $a0
  __int64 result; // $v0
  int v6; // $s0
  bool v7; // dc
  bool v8; // $a0
  int v9; // $a1
  __int64 v10; // $a2
  int v11; // $a2
  __int64 v12; // $v1
  __int64 v14; // $a3
  int v15; // $a0
  __int64 v16; // $v0
  __int64 v17; // $a0
  int v18; // $a0
  __int64 v19; // $v1

  __asm
  {
    sq           $s1, 0x30+var_20($sp)
    sq           $s0, 0x30+var_10($sp)
  }
  if ( !gGame.pad13[0] )
  {
    v4 = *(pStreamedTrack + 28);
    v14 = 0x6D6123044330FCCFLL;
    if ( *(&gGame.camMgr0.state + 2000 * v4) )
      v14 = **(&gGame.camMgr0.state + 2000 * v4);
    v15 = 8000 * v4;
    if ( v14 != 0xBA38E5FB73BF9888LL )
    {
      v16 = *(&gGame.camMgr0.state + v15);
      v17 = 0x6D6123044330FCCFLL;
      if ( v16 )
        v17 = *v16;
      v7 = v17 == 0xBA38E873F7DDDE52LL;
      v18 = 8000 * *(pStreamedTrack + 28);
      if ( !v7 )
      {
        v19 = 0x6D6123044330FCCFLL;
        if ( *(&gGame.camMgr0.state + v18) )
          v19 = **(&gGame.camMgr0.state + v18);
        result = 0LL;
        if ( v19 == 0xBA38E687F15C922CLL )
          goto LABEL_29;
        if ( *(*(pStreamedTrack + 496) + 109) >= 0LL )
        {
          if ( gGraphicsManager.pad_0048[14] )
          {
            result = 1LL;
            if ( !*(&gWorld.m_Timer.lastFrame + ShowPersonas__20CB4ConnectingService + &unk_1F27FCB - 32643856) )
              goto LABEL_29;
          }
        }
      }
    }
    goto LABEL_28;
  }
  result = 0LL;
  if ( *(*(pStreamedTrack + 496) + 109) < 0LL )
    goto LABEL_29;
  v6 = *gGame.stagePtr;
  v7 = (*(*(v6 + 212) + 716))(v6 + *(*(v6 + 212) + 712)) != 0;
  result = 0LL;
  if ( v7 )
    goto LABEL_29;
  v8 = 0;
  if ( *(v6 + 216) == 11LL )
    v8 = *(v6 + 709) == 0LL;
  result = 0LL;
  if ( v8 )
    goto LABEL_29;
  v9 = *(pStreamedTrack + 28);
  result = 0LL;
  if ( gWorld.m_ConnectingService[&loc_177460 + 15120 * v9 + 10059] )
    goto LABEL_29;
  v10 = 0x6D6123044330FCCFLL;
  if ( *(&gGame.camMgr0.state + 2000 * v9) )
    v10 = **(&gGame.camMgr0.state + 2000 * v9);
  v7 = v10 == 0xBA38E687F15C922CLL;
  v11 = 8000 * v9;
  if ( v7 )
    goto LABEL_28;
  v12 = 0x6D6123044330FCCFLL;
  if ( *(&gGame.camMgr0.state + v11) )
    v12 = **(&gGame.camMgr0.state + v11);
  result = 1LL;
  if ( v12 == 0xBA38E862A8C6963BLL )
  {
LABEL_28:
    result = 0LL;
LABEL_29:
    __asm { lq           $s0, 0x30+var_10($sp) }
    goto LABEL_30;
  }
  __asm { lq           $s0, 0x30+var_10($sp) }
LABEL_30:
  __asm { lq           $s1, 0x30+var_20($sp) }
  return result;
}

// CB4StreamedTrack::GetUnitForCurrentBasis(void) const
__int64 __fastcall GetUnitForCurrentBasis__C16CB4StreamedTrack(unsigned int pStreamedTrack)
{
  int v2; // $a3
  __int64 v3; // $a1
  __int64 v4; // $a0

  v2 = *(pStreamedTrack + 28);
  v3 = 0x6D6123044330FCCFLL;
  v4 = *(pStreamedTrack + 500);
  if ( *(&gGame.camMgr0.state + 2000 * v2) )
    v3 = **(&gGame.camMgr0.state + 2000 * v2);
  if ( v3 == 0xBA38E63A96099FBFLL || (*&gGame.camMgr0.behaviourObjects[8000 * v2 + 6144] & 1LL) != 0 )
    v4 = 1LL;
  if ( v4 )
  {
    if ( v4 != 1 )
      return -1LL;
    return GetCurrentUnit__C22CB4PlayerCameraManager(&gGame.camMgr0 + *(pStreamedTrack + 28));
  }
  else
  {
    _$V0 = &gWorld + &loc_177460 + 15120 * *(pStreamedTrack + 28);
    __asm { lq           $a1, 0x30($v0) }
    return TestPosition__16CB4StreamedTrackGQ29GtMathPs26CGtV3d(pStreamedTrack, _$A1);
  }
}

// CB4StreamedTrackData::FixUp(void)
__int64 __fastcall FixUp__20CB4StreamedTrackData(int pStreamedTrackData)
{
  __int64 result; // $v0
  __int16 *v2; // $a2
  __int64 v3; // $a1
  int i; // $v1
  int v5; // $v1
  __int64 v6; // $v0
  bool v7; // dc
  int v8; // $v0
  __int64 v9; // $v0
  int v10; // $v0

  result = *(pStreamedTrackData + 80);
  v2 = (pStreamedTrackData + 80);
  if ( result <= 0 )
    return result;
  result = *(pStreamedTrackData + 84) + pStreamedTrackData + 80;
  *(pStreamedTrackData + 84) = result;
  LODWORD(v3) = 0;
  if ( *(pStreamedTrackData + 80) > 0LL )
  {
    for ( i = *(pStreamedTrackData + 84); ; i = *(pStreamedTrackData + 84) )
    {
      v5 = (v3 << 6) + i;
      v6 = *(v5 + 12);
      v7 = v6 == 0;
      v8 = v6 + v5;
      if ( !v7 )
        *(v5 + 12) = v8;
      v9 = *(v5 + 28);
      v7 = v9 == 0;
      v10 = v9 + v5;
      if ( !v7 )
        *(v5 + 28) = v10;
      v3 = v3 + 1;
      result = v3 < *v2;
      if ( v3 >= *v2 )
        break;
    }
  }
  return result;
}

// CB4StreamedTrackHighData::FixUp(short)
__int64 __fastcall FixUp__24CB4StreamedTrackHighDatas(int pStreamedTrackHighData)
{
  __int64 v5; // $v0
  bool v6; // dc
  int v7; // $v0
  __int64 v8; // $v0
  int v9; // $v0
  __int64 result; // $v0
  unsigned __int64 v11; // $s0

  __asm
  {
    sq           $s1, 0x40+var_20($sp)
    sq           $s0, 0x40+var_10($sp)
    sq           $s2, 0x40+var_30($sp)
  }
  FixUp__20CB4StreamedTrackData(pStreamedTrackHighData);
  v5 = *(pStreamedTrackHighData + 3176);
  v6 = v5 == 0;
  v7 = v5 + pStreamedTrackHighData;
  if ( !v6 )
    *(pStreamedTrackHighData + 3176) = v7;
  v8 = *(pStreamedTrackHighData + 3180);
  v6 = v8 == 0;
  v9 = v8 + pStreamedTrackHighData;
  if ( !v6 )
    *(pStreamedTrackHighData + 3180) = v9;
  result = *(pStreamedTrackHighData + 3184);
  LOWORD(v11) = 0;
  if ( *(pStreamedTrackHighData + 3184) )
  {
    do
    {
      FixUp__22CB4ParticleEmitterData();
      v11 = (v11 + 1);
      result = 12 * v11;
    }
    while ( v11 < *(pStreamedTrackHighData + 3184) );
  }
  *(pStreamedTrackHighData + 88) = 0;
  __asm
  {
    lq           $s0, 0x40+var_10($sp)
    lq           $s1, 0x40+var_20($sp)
    lq           $s2, 0x40+var_30($sp)
  }
  return result;
}

// CB4StreamedTrackLODAndCollisionData::FixUp(int)
__int64 __fastcall FixUp__35CB4StreamedTrackLODAndCollisionDatai(int pStreamedTrackLODAndCollisionData, __int64 a2)
{
  __int64 v6; // $v1
  __int64 v7; // $v0
  bool v8; // dc
  GtCollisionKDTree *v9; // $v0
  int *v10; // $v1
  __int64 v11; // $v0
  int v12; // $v0
  int v13; // $v1
  int v14; // $a0
  __int64 result; // $v0

  __asm
  {
    sq           $s0, 0x30+var_10($sp)
    sq           $s1, 0x30+var_20($sp)
  }
  FixUp__20CB4StreamedTrackData(pStreamedTrackLODAndCollisionData);
  v6 = *(pStreamedTrackLODAndCollisionData + 148);
  *(pStreamedTrackLODAndCollisionData + 88) = 1;
  if ( v6 )
    *(pStreamedTrackLODAndCollisionData + 148) = v6 + pStreamedTrackLODAndCollisionData;
  v7 = *(pStreamedTrackLODAndCollisionData + 144);
  v8 = v7 == 0;
  v9 = (v7 + pStreamedTrackLODAndCollisionData);
  if ( !v8 )
  {
    *(pStreamedTrackLODAndCollisionData + 144) = v9;
    FixUp__18CGtCollisionKDTree(v9);
  }
  FixUp__18CB4InstanceManageri((pStreamedTrackLODAndCollisionData + 152), a2);
  v10 = (*(pStreamedTrackLODAndCollisionData + 160) + pStreamedTrackLODAndCollisionData);
  *(pStreamedTrackLODAndCollisionData + 160) = v10;
  v11 = *v10;
  v8 = v11 == 0;
  v12 = v10 + v11;
  if ( !v8 )
    *v10 = v12;
  v13 = *(pStreamedTrackLODAndCollisionData + 160);
  if ( *(v13 + 8) )
  {
    *(v13 + 8) += v13 + 8;
    v13 = *(pStreamedTrackLODAndCollisionData + 160);
  }
  if ( *(v13 + 16) )
    *(v13 + 16) += v13 + 16;
  v14 = *(pStreamedTrackLODAndCollisionData + 160);
  result = *(v14 + 24);
  if ( *(v14 + 24) )
  {
    result = result + v14 + 24;
    *(v14 + 24) = result;
  }
  __asm
  {
    lq           $s0, 0x30+var_10($sp)
    lq           $s1, 0x30+var_20($sp)
  }
  return result;
}

// CB4StreamedTrackHull::LineIntersectsOrIsInsideHull(const CGtLine &) const
__int64 __fastcall LineIntersectsOrIsInsideHull__C20CB4StreamedTrackHullRC7CGtLine(int _$A0, int _$A1)
{
  __int64 v3; // $v0
  __int64 result; // $v0
  __int64 v5; // $a0
  float *v6; // $v1
  float v7; // [sp+4h] [-1Ch]
  float v8; // [sp+8h] [-18h]
  float v9; // [sp+Ch] [-14h]
  __int128 v10; // [sp+10h] [-10h] BYREF

  __asm
  {
    lqc2         $vf4, 0($a1)
    lqc2         $vf2, 0($a0)
    lqc2         $vf1, 0x10($a0)
    vmulx.xyzw   $vf2, $vf2, $vf4
    vmulz.xyzw   $vf1, $vf1, $vf4
    lqc2         $vf3, 0x20($a0)
    vadd.xyzw    $vf2, $vf2, $vf1
    vsub.xyzw    $vf2, $vf2, $vf3
    qmfc2        $v0, $vf2
  }
  if ( *&_$V0 > 0.0 )
  {
    __asm { sqc2         $vf2, 0x20+var_20($sp) }
    if ( v7 > 0.0 )
    {
      __asm { sqc2         $vf2, 0x20+var_20($sp) }
      v3 = 0LL;
      if ( v8 > 0.0 )
      {
        __asm { sqc2         $vf2, 0x20+var_20($sp) }
        v3 = v9 > 0.0;
      }
    }
    else
    {
      v3 = 0LL;
    }
  }
  else
  {
    v3 = 0LL;
  }
  if ( v3 )
    return 1LL;
  __asm
  {
    lqc2         $vf3, 0x10($a1)
    vsub.xyzw    $vf4, $vf0, $vf0
    lqc2         $vf1, 0($a1)
    vsub.xyzw    $vf4, $vf4, $vf2
    vsub.xyz     $vf3, $vf3, $vf1
    lqc2         $vf2, 0x10($a0)
    lqc2         $vf1, 0($a0)
    vmulz.xyzw   $vf2, $vf2, $vf3
    vmulx.xyzw   $vf1, $vf1, $vf3
    vadd.xyzw    $vf1, $vf1, $vf2
    vnop
    vnop
    vnop
    vdiv         $Q, $vf0.w, $vf1.x
    vwaitq
    vmulq.x      $vf2, $vf4, $Q
    vdiv         $Q, $vf0.w, $vf1.y
    vwaitq
    vmulq.y      $vf2, $vf4, $Q
    vdiv         $Q, $vf0.w, $vf1.z
    vwaitq
    vmulq.z      $vf2, $vf4, $Q
    vdiv         $Q, $vf0.w, $vf1.w
    vwaitq
    vmulq.w      $vf2, $vf4, $Q
  }
  LODWORD(v5) = 0;
  __asm { sqc2         $vf2, 0x20+var_10($sp) }
  v6 = &v10;
  do
  {
    if ( *v6 >= 0.0 )
    {
      result = 1LL;
      if ( *v6 <= 1.0 )
        return result;
      v5 = v5 + 1;
    }
    else
    {
      v5 = v5 + 1;
    }
    ++v6;
  }
  while ( v5 < 4 );
  return 0LL;
}

// _safeUnitCallback(CB4StreamedTrackLODAndCollisionData *, int, void *)
__int64 __fastcall safeUnitCallback__FP35CB4StreamedTrackLODAndCollisionDataiPv(int _$A0, int a2, int a3)
{
  __int64 result; // $v0

  __asm
  {
    lq           $v0, 0x60($a0)
    sq           $v0, 0xBD0($a3)
    lq           $v0, 0x70($a0)
    sq           $v0, 0x10($a3)
    lq           $v1, 0x80($a0)
    sq           $v1, 0x20($a3)
  }
  result = a3 + 4 * *(a3 + 3504);
  *(result + 3456) = a2;
  ++*(a3 + 3504);
  return result;
}

// CB4StreamedTrack::TestPosition(GtMathPs2::CGtV3d)
__int64 __fastcall TestPosition__16CB4StreamedTrackGQ29GtMathPs26CGtV3d(int pStreamedTrack, __int64 _$A1)
{
  __int64 v3; // $v1
  __int64 v4; // $a2
  int v5; // $a3
  int v6; // $a0
  __int64 v7; // $a4
  __int64 i; // $hi

  if ( !*(pStreamedTrack + 92) )
    return -1LL;
  v3 = *(pStreamedTrack + 104) - 4;
  v4 = v3;
  if ( v3 < 0 )
    v4 = v3 + *(pStreamedTrack + 12);
  __asm { qmtc2        $a1, $vf4 }
  if ( v4 >= v4 + 9 )
    return -1LL;
  v5 = *(pStreamedTrack + 12);
  v6 = pStreamedTrack + 420;
  v7 = v4 + 9;
  for ( i = v4 % v5; ; i = v4 % v5 )
  {
    _$V1 = *(v6 + 4 * i);
    __asm
    {
      lqc2         $vf3, 0x80($v1)
      lqc2         $vf1, 0x60($v1)
      lqc2         $vf2, 0x70($v1)
      vmulax.xyzw  $A, $vf1, $vf4
      vmaddaz.xyzw $A, $vf2, $vf4
      vmsubw.xyzw  $vf1, $vf3, $vf0
      qmfc2        $v1, $vf1
      psraw        $v0, $v1, 0x1F
      pcpyud       $v1, $v0, $zero
    }
    v4 = v4 + 1;
    if ( !(_$V0 | _$V1) )
      break;
    if ( v4 >= v7 )
      return -1LL;
  }
  return i;
}

// CB4StreamedTrack::DoUnitFrustumTesting(void)
__int64 __fastcall DoUnitFrustumTesting__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 v10; // $ra
  _WORD *v11; // $v0
  int v12; // $fp
  int v13; // $s7
  int v14; // $a0
  char v15; // $s6
  int v16; // $v0
  __int16 v17; // $s5
  int v18; // $s0
  int v20; // $v0
  int v21; // $s3
  __int64 v22; // $v0
  __int64 v23; // $v1
  __int64 v24; // $s1
  int v25; // $a0
  int v26; // $s0
  __int64 v27; // $v0
  bool v28; // dc
  __int64 v29; // $v0
  __int64 v30; // $v0
  __int64 v34; // $v0
  __int64 result; // $v0
  __int128 v45; // [sp+80h] [-230h] BYREF
  _BYTE v46[224]; // [sp+100h] [-1B0h] BYREF
  int v48; // [sp+200h] [-B0h]
  int v49; // [sp+204h] [-ACh]
  __int64 v50; // [sp+210h] [-A0h]

  v11 = (pStreamedTrack + 158);
  __asm
  {
    sq           $s0, 0x2B0+var_10($sp)
    sq           $fp, 0x2B0+var_90($sp)
  }
  LODWORD(_$S0) = 16;
  __asm { sq           $s1, 0x2B0+var_20($sp) }
  v12 = pStreamedTrack + 126;
  __asm
  {
    sq           $s2, 0x2B0+var_30($sp)
    sq           $s3, 0x2B0+var_40($sp)
    sq           $s4, 0x2B0+var_50($sp)
    sq           $s5, 0x2B0+var_60($sp)
    sq           $s6, 0x2B0+var_70($sp)
    sq           $s7, 0x2B0+var_80($sp)
  }
  v50 = v10;
  do
  {
    *v11 = 0;
    _$S0 = _$S0 - 1;
    --v11;
  }
  while ( _$S0 >= 0 );
  v13 = pStreamedTrack + 164;
  v14 = 0;
  do
  {
    v15 = 2 * v14;
    v16 = 3 << (2 * v14);
    v17 = ~v16;
    v49 = v14 + 1;
    v48 = ~v16;
    v18 = 0;
    _$S4 = &gGraphicsManager.pad1_3[560 * v14 + 64];
    v20 = 0;
    do
    {
      v21 = v20;
      v22 = *(v13 + v20);
      if ( v22 )
      {
        v23 = IntersectFrustum__14GtIntersectionRC10CGtFrustumRC14CGtExtrudedBox(_$S4, v22 + 16);
        if ( v23 )
        {
          if ( v23 == 2 )
          {
            v24 = v18 + 1;
            v25 = 1;
            v26 = 2 * v18;
          }
          else
          {
            __asm { lqc2         $vf1, 0xD0($s4) }
            v24 = v18 + 1;
            v26 = 2 * v18;
            __asm { vadd.xyz     $vf3, $vf0, $vf0 }
            v27 = 6LL;
            do
            {
              v28 = v27 != -1;
              v27 = v27 - 1;
            }
            while ( v28 );
            v29 = 6LL;
            do
            {
              v28 = v29 != -1;
              v29 = v29 - 1;
            }
            while ( v28 );
            v30 = 6LL;
            do
            {
              v28 = v30 != -1;
              v30 = v30 - 1;
            }
            while ( v28 );
            __asm
            {
              sqc2         $vf3, 0x2B0+var_D0($sp)
              lqc2         $vf2, 0x2B0+var_C0($sp)
              vadd.xyz     $vf2, $vf0, $vf1
            }
            _$V1 = *(v13 + v21);
            __asm { vmove.xyzw   $vf1, $vf2 }
            _$V0 = 1120403456LL;
            __asm
            {
              vsubw.w      $vf1, $vf0, $vf0
              lqc2         $vf5, 0x10($v1)
              qmtc2        $v0, $vf2
              vaddx.w      $vf1, $vf1, $vf2
              vaddw.y      $vf3, $vf0, $vf5
              sqc2         $vf1, 0x2B0+var_C0($sp)
              vadd.xyz     $vf8, $vf5, $vf3
              sqc2         $vf5, 0x2B0+var_2B0($sp)
              lqc2         $vf4, 0x20($v1)
              vadd.xyz     $vf7, $vf4, $vf3
              sqc2         $vf4, 0x2B0+var_2A0($sp)
              lqc2         $vf1, 0x30($v1)
              vadd.xyz     $vf6, $vf1, $vf3
              sqc2         $vf1, 0x2B0+var_290($sp)
              lqc2         $vf2, 0x40($v1)
              vadd.xyz     $vf3, $vf2, $vf3
              sqc2         $vf5, 0x2B0+var_230($sp)
              sqc2         $vf1, 0x2B0+var_210($sp)
              sqc2         $vf2, 0x2B0+var_220($sp)
              sqc2         $vf4, 0x2B0+var_200($sp)
              sqc2         $vf8, 0x2B0+var_1F0($sp)
              sqc2         $vf3, 0x2B0+var_1E0($sp)
              sqc2         $vf6, 0x2B0+var_1D0($sp)
              sqc2         $vf7, 0x2B0+var_1C0($sp)
              sqc2         $vf2, 0x2B0+var_280($sp)
              sqc2         $vf8, 0x2B0+var_270($sp)
              sqc2         $vf7, 0x2B0+var_260($sp)
              sqc2         $vf6, 0x2B0+var_250($sp)
              sqc2         $vf3, 0x2B0+var_240($sp)
            }
            ConvertTo__C20CGtSimpleOrientedBoxP14CGtOrientedBox(&v45, v46);
            __asm { lq           $a0, 0x2B0+var_C0($sp) }
            v34 = IntersectSphere__14GtIntersectionGQ29GtMathPs29CGtSphereRC14CGtOrientedBox(_$A0, v46);
            v25 = 2;
            if ( v34 )
              v25 = 3;
          }
        }
        else
        {
          v24 = v18 + 1;
          v25 = 0;
          v26 = 2 * v18;
        }
        *(v12 + v26) = *(v12 + v26) & v17 | (v25 << v15);
      }
      else
      {
        v24 = v18 + 1;
        *(v12 + 2 * v18) &= v48;
      }
      v18 = v24;
      v20 = 4 * v24;
    }
    while ( v24 < 17 );
    v14 = v49;
    result = v49 < 4LL;
  }
  while ( v49 < 4LL );
  __asm
  {
    lq           $s0, 0x2B0+var_10($sp)
    lq           $s1, 0x2B0+var_20($sp)
    lq           $s2, 0x2B0+var_30($sp)
    lq           $s3, 0x2B0+var_40($sp)
    lq           $s4, 0x2B0+var_50($sp)
    lq           $s5, 0x2B0+var_60($sp)
    lq           $s6, 0x2B0+var_70($sp)
    lq           $s7, 0x2B0+var_80($sp)
    lq           $fp, 0x2B0+var_90($sp)
  }
  return result;
}

// CB4StreamedTrack::IsUnitVisibleToMainCamera(int)
__int64 __fastcall IsUnitVisibleToMainCamera__16CB4StreamedTracki(int pStreamedTrack, __int64 a2)
{
  __int64 v3; // $v1
  _DWORD *v4; // $a2

  if ( !*(pStreamedTrack + 92) )
    return 1LL;
  if ( a2 == -1 )
    return 0LL;
  LODWORD(v3) = 0;
  v4 = (pStreamedTrack + 236);
  do
  {
    if ( *v4 == *(pStreamedTrack + 4 * a2 + 420) )
      return (*(pStreamedTrack + 2 * v3 + 126) & 3LL) != 0;
    v3 = v3 + 1;
    ++v4;
  }
  while ( v3 < 17 );
  return 1LL;
}

// CB4StreamedTrack::RenderBeforeVehicles(void)
__int64 __fastcall RenderBeforeVehicles__16CB4StreamedTrack(unsigned int pStreamedTrack)
{
  __int64 result; // $v0
  int v12; // $a1
  __int64 v14; // $s7
  unsigned int v15; // $v1
  __int64 v16; // $a1
  int v17; // $s7
  uint64_t field_160; // $v0
  unsigned int v19; // $v1
  unsigned int v20; // $s2
  char *v21; // $s1
  _WORD *v22; // $s0
  __int64 v23; // $s3
  __int64 v24; // $a2
  __int64 v25; // $a0
  bool v26; // dc
  int v27; // $a0
  int v28; // $a1
  __int64 v29; // $s0
  __int64 i; // $v0
  uint64_t v31; // $v0
  char v32; // $s6
  __int64 v33; // $fp
  char *v34; // $s2
  unsigned int v35; // $s0
  __int64 v36; // $s3
  unsigned __int16 *v37; // $s1
  __int64 v38; // $a2
  __int64 v39; // $v1
  int v40; // $v1
  int v41; // $a1
  int v42; // $s7
  int v43; // $a0
  float v44; // $f20
  int v45; // $v1
  __int16 v46; // $a0
  __int64 v47; // $s6
  __int64 v48; // $s2
  unsigned __int16 *v49; // $s1
  _DWORD **v50; // $s0
  _DWORD *v51; // $a2
  int v52; // $a5
  unsigned int v53; // $a3
  __int64 v54; // $s2
  _WORD *v55; // $s0
  unsigned int v56; // $s1
  int v57; // $a1
  _WORD *v58; // $s1
  unsigned int v59; // $s0
  __int64 v60; // $s2
  __int64 v61; // $a2
  float v62; // $f12
  int v73; // [sp+4h] [-ACh]
  int v74; // [sp+Ch] [-A4h]
  int v75; // [sp+Ch] [-A4h]

  __asm
  {
    sq           $s0, 0xB0+var_10($sp)
    sq           $s1, 0xB0+var_20($sp)
    sq           $s2, 0xB0+var_30($sp)
    sq           $s3, 0xB0+var_40($sp)
    sq           $s4, 0xB0+var_50($sp)
    sq           $s5, 0xB0+var_60($sp)
    sq           $s6, 0xB0+var_70($sp)
    sq           $s7, 0xB0+var_80($sp)
    sq           $fp, 0xB0+var_90($sp)
  }
  result = 30998528LL;
  if ( *(pStreamedTrack + 92) )
  {
    v73 = *&gWorld.m_StaticTrack[4];
    DoUnitFrustumTesting__16CB4StreamedTrack(pStreamedTrack);
    v12 = *(pStreamedTrack + 492) + 96;
    MEMORY[0x1000E010] = 512;
    MEMORY[0x1000D480] = 1879056384;
    MEMORY[0x1000D410] = v12;
    MEMORY[0x1000D420] = 192;
    MEMORY[0x1000D400] = 256;
    _sync();
    _sync();
    if ( (MEMORY[0x1000D400] & 0x100) != 0 )
    {
      MEMORY[0x1000E020] = 512;
      _sync();
      _sync();
      __asm { mfthc1       $ra, $f0 }
      while ( (MEMORY[0x1000D400] & 0x100) != 0 )
        ;
    }
    LODWORD(v14) = 0;
    PrepareRenderStatesForRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
    v15 = pStreamedTrack;
    do
    {
      v16 = *(*(v15 + 496) + v14 + 100);
      if ( v16 >= 0 )
      {
        if ( gGraphicsManager.pad_0048[13] )
          RenderBackdrop__14CB4StaticTrackRC17CB4BackdropObject(gWorld.m_StaticTrack, (*(v73 + 36) + 8 * v16));
        v14 = v14 + 1;
      }
      else
      {
        v14 = v14 + 1;
      }
      v15 = pStreamedTrack;
    }
    while ( v14 < 8 );
    v17 = 0;
    if ( MEMORY[0x70002003] > 0LL )
    {
      while ( 1 )
      {
        v74 = v17 + 1;
        BeginNonInstanceRender__16CB4TrackRendererRC16CB4TrackMaterial(
          &gTrackRenderer,
          (*(v73 + 8) + 40 * *(2 * v17 + 0x70002014LL)));
        if ( !gGraphicsManager.pad_0048[15] )
          goto LABEL_28;
        if ( gTrackRenderer.flag153 )
          goto LABEL_18;
        if ( gTrackRenderer.field_160 == gTrackRenderer.field_168 )
          break;
        field_160 = gTrackRenderer.field_160;
LABEL_19:
        gTrackRenderer.flag153 = 0;
        gTrackRenderer.field_168 = field_160;
        gTrackRenderer.field_184 = gTrackRenderer.field_176;
        ReallySetupCameraData__16CB4TrackRenderer(&gTrackRenderer);
        v19 = pStreamedTrack;
LABEL_20:
        v74 = v17 + 1;
        v20 = v19 + 164;
        v21 = (v17 + 1879056582);
        v22 = (v19 + 126);
        LODWORD(v23) = 16;
        do
        {
          v24 = *v22 & 3LL;
          if ( v24 )
          {
            v25 = *v21;
            v26 = v25 < 0;
            v27 = v25 << 6;
            if ( !v26 )
            {
              v28 = v27 + *(*v20 + 84);
              if ( *(v28 + 12) )
                RenderMesh__16CB4TrackRendererRC12CB4TrackMesh16EB4TrackClipModeb(&gTrackRenderer, v28, v24, 0);
            }
            v20 += 4;
          }
          else
          {
            v20 += 4;
          }
          v21 += 169;
          v23 = v23 - 1;
          ++v22;
        }
        while ( v23 >= 0 );
LABEL_28:
        if ( gGraphicsManager.pad_0048[16] )
        {
          v29 = 1LL;
          for ( i = gTrackRenderer.flag153; ; i = gTrackRenderer.flag153 )
          {
            if ( v29 == i )
            {
              if ( gTrackRenderer.field_160 == gTrackRenderer.field_168 )
              {
                v32 = 2 * v29;
                if ( gTrackRenderer.field_176 == gTrackRenderer.field_184 )
                  goto LABEL_39;
                v31 = gTrackRenderer.field_160;
              }
              else
              {
                v31 = gTrackRenderer.field_160;
              }
            }
            else
            {
              v31 = gTrackRenderer.field_160;
            }
            gTrackRenderer.field_168 = v31;
            gTrackRenderer.field_184 = gTrackRenderer.field_176;
            gTrackRenderer.flag153 = v29;
            if ( (v29 << 24) >= 0LL )
              ReallySetupCameraData__16CB4TrackRenderer(&gTrackRenderer);
            v32 = 2 * v29;
LABEL_39:
            v33 = v29 + 1;
            v34 = (v17 + 1879056665);
            v35 = pStreamedTrack + 236;
            LODWORD(v36) = 16;
            v37 = (pStreamedTrack + 126);
            do
            {
              if ( *v35 )
              {
                v38 = (*v37 >> v32) & 3LL;
                if ( v38 )
                {
                  v39 = *v34;
                  v26 = v39 < 0;
                  v40 = v39 << 6;
                  if ( !v26 )
                  {
                    v41 = v40 + *(*v35 + 84);
                    if ( *(v41 + 12) )
                      RenderMesh__16CB4TrackRendererRC12CB4TrackMesh16EB4TrackClipModeb(&gTrackRenderer, v41, v38, 1u);
                  }
                  v34 += 169;
                }
                else
                {
                  v34 += 169;
                }
              }
              else
              {
                v34 += 169;
              }
              ++v37;
              v36 = v36 - 1;
              v35 += 4;
            }
            while ( v36 >= 0 );
            v29 = v33;
            if ( v33 >= 4 )
              break;
          }
        }
        v17 = v74;
        EndMaterial__16CB4TrackRenderer(&gTrackRenderer);
        if ( v74 >= MEMORY[0x70002003] )
          goto LABEL_52;
      }
      v19 = pStreamedTrack;
      if ( gTrackRenderer.field_176 == gTrackRenderer.field_184 )
        goto LABEL_20;
LABEL_18:
      field_160 = gTrackRenderer.field_160;
      goto LABEL_19;
    }
LABEL_52:
    v42 = 0;
    if ( *(v73 + 52) > 0LL )
    {
      v43 = v73;
      do
      {
        v44 = 0.0;
        v45 = 80 * v42 + *(v43 + 56);
        v46 = *(v45 + 62);
        v47 = 0LL;
        if ( (v46 & 4) != 0 )
        {
          v44 = *(v45 + 72);
          v47 = 1LL;
        }
        v75 = v42 + 1;
        if ( (v46 & 2) != 0 && gGraphicsManager.pad_0048[18] )
        {
          LODWORD(v48) = 16;
          v49 = (pStreamedTrack + 126);
          BeginInstanceRender__16CB4TrackRendererPC15CB4InstanceMeshPC17CGtAxisAlignedBoxRC16CB4TrackMaterialff24EB4InstanceDistanceCheckbf(
            &gTrackRenderer,
            v45 + 48,
            v45,
            (*(v73 + 8) + 40 * *(v45 + 60)),
            0LL,
            v47,
            *(v45 + 64),
            v44);
          v50 = (pStreamedTrack + 308);
          PushCameraForInstanceRendering__16CB4TrackRenderer19EB4RenderableCamera(&gTrackRenderer, 1);
          PushCameraForInstanceRendering__16CB4TrackRenderer19EB4RenderableCamera(&gTrackRenderer, 2);
          PushCameraForInstanceRendering__16CB4TrackRenderer19EB4RenderableCamera(&gTrackRenderer, 3);
          do
          {
            v51 = *v50;
            if ( *v50 )
            {
              if ( *(*v51 + v42) )
              {
                if ( (((*v49 >> 6) | ((*v49 >> 4) | (*v49 >> 2))) & 3) != 0 )
                  RenderInstances__16CB4TrackRendererScPC15CB4InstanceData(
                    &gTrackRenderer,
                    *(*v51 + v42),
                    *(4 * v42 + v51[1]));
                ++v49;
              }
              else
              {
                ++v49;
              }
            }
            else
            {
              ++v49;
            }
            v48 = v48 - 1;
            ++v50;
          }
          while ( v48 >= 0 );
          EndInstanceRender__16CB4TrackRenderer(&gTrackRenderer);
        }
        v52 = 80 * v42 + *(v73 + 56);
        v53 = 40 * *(v52 + 56) + *(v73 + 8);
        if ( (*(v53 + 36) & 4LL) != 0 && gGraphicsManager.pad_0048[17] )
        {
          BeginInstanceRender__16CB4TrackRendererPC15CB4InstanceMeshPC17CGtAxisAlignedBoxRC16CB4TrackMaterialff24EB4InstanceDistanceCheckbf(
            &gTrackRenderer,
            v52 + 32,
            80 * v42 + *(v73 + 56),
            v53,
            *(v52 + 62) & 1LL,
            v47,
            *(v52 + 64),
            v44);
          LODWORD(v54) = 16;
          v55 = (pStreamedTrack + 126);
          PushCameraForInstanceRendering__16CB4TrackRenderer19EB4RenderableCamera(&gTrackRenderer, 0);
          v56 = pStreamedTrack + 308;
          do
          {
            if ( (*v55 & 3LL) != 0 )
            {
              if ( *(**v56 + v42) )
                RenderInstances__16CB4TrackRendererScPC15CB4InstanceData(
                  &gTrackRenderer,
                  *(**v56 + v42),
                  *(4 * v42 + *(*v56 + 4)));
              v56 += 4;
            }
            else
            {
              v56 += 4;
            }
            v54 = v54 - 1;
            ++v55;
          }
          while ( v54 >= 0 );
          EndInstanceRender__16CB4TrackRenderer(&gTrackRenderer);
          v57 = 80 * v42 + *(v73 + 56);
          if ( (*(v57 + 62) & 1LL) != 0 )
          {
            BeginInstanceRender__16CB4TrackRendererPC15CB4InstanceMeshPC17CGtAxisAlignedBoxRC16CB4TrackMaterialff24EB4InstanceDistanceCheckbf(
              &gTrackRenderer,
              v57 + 40,
              v57,
              (*(v73 + 8) + 40 * *(v57 + 58)),
              2LL,
              v47,
              *(v57 + 64),
              v44);
            v58 = (pStreamedTrack + 126);
            v59 = pStreamedTrack + 308;
            LODWORD(v60) = 16;
            PushCameraForInstanceRendering__16CB4TrackRenderer19EB4RenderableCamera(&gTrackRenderer, 0);
            do
            {
              if ( (*v58 & 3LL) != 0 )
              {
                if ( *(**v59 + v42) )
                  RenderInstances__16CB4TrackRendererScPC15CB4InstanceData(
                    &gTrackRenderer,
                    *(**v59 + v42),
                    *(4 * v42 + *(*v59 + 4)));
                v59 += 4;
              }
              else
              {
                v59 += 4;
              }
              v60 = v60 - 1;
              ++v58;
            }
            while ( v60 >= 0 );
            EndInstanceRender__16CB4TrackRenderer(&gTrackRenderer);
          }
        }
        ++v42;
        v43 = v73;
      }
      while ( v75 < *(v73 + 52) );
    }
    if ( gGraphicsManager.pad_0048[13] && MEMORY[0x7000200E] >= 0LL )
    {
      v61 = 0LL;
      if ( MEMORY[0x7000200F] >= 0LL )
        v61 = *(v73 + 48) + 8 * MEMORY[0x7000200F];
      v62 = 0.0;
      if ( *(pStreamedTrack + 492) )
        v62 = *(*(pStreamedTrack + 492) + 112);
      RenderWater__14CB4StaticTrackfRC17CB4BackdropObjectPC17CB4BackdropObject(
        pStreamedTrack,
        (*(v73 + 44) + 8 * MEMORY[0x7000200E]),
        v61,
        v62);
    }
    result = RestoreRenderStatesAfterRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
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
    lq           $s7, 0xB0+var_80($sp)
    lq           $fp, 0xB0+var_90($sp)
  }
  return result;
}

// CB4StreamedTrack::RenderAfterVehicles(void)
__int64 __fastcall RenderAfterVehicles__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 result; // $v0
  int v12; // $s7
  int v13; // $a0
  __int64 v14; // $s0
  int v15; // $v0
  uint64_t field_160; // $v0
  int v17; // $s2
  __int64 v18; // $s6
  unsigned int v19; // $s1
  _WORD *v20; // $s0
  __int64 v21; // $s4
  __int64 v22; // $a2
  __int64 v23; // $a0
  bool v24; // dc
  int v25; // $a0
  int v26; // $a1

  __asm
  {
    sq           $s5, 0xA0+var_60($sp)
    sq           $s0, 0xA0+var_10($sp)
    sq           $s1, 0xA0+var_20($sp)
    sq           $s2, 0xA0+var_30($sp)
  }
  result = &gWorld.m_PropManager[24016];
  __asm
  {
    sq           $s3, 0xA0+var_40($sp)
    sq           $s4, 0xA0+var_50($sp)
    sq           $s6, 0xA0+var_70($sp)
    sq           $s7, 0xA0+var_80($sp)
    sq           $fp, 0xA0+var_90($sp)
  }
  v12 = *&gWorld.m_StaticTrack[4];
  if ( *(pStreamedTrack + 92) )
  {
    result = 5046272LL;
    if ( gGraphicsManager.pad_0048[15] )
    {
      result = 29556736LL;
      if ( gDebugManager.physicsDebug[6] != 1LL )
      {
        PrepareRenderStatesForRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
        v13 = *(pStreamedTrack + 492);
        v14 = *(v13 + 99);
        if ( v14 < *(v13 + 98) )
        {
          v15 = 2 * v14;
          do
          {
            BeginNonInstanceRender__16CB4TrackRendererRC16CB4TrackMaterial(
              &gTrackRenderer,
              (*(v12 + 8) + 40 * *(v13 + v15 + 116)));
            if ( gTrackRenderer.flag153 )
            {
              field_160 = gTrackRenderer.field_160;
            }
            else if ( gTrackRenderer.field_160 == gTrackRenderer.field_168 )
            {
              v17 = v14;
              if ( gTrackRenderer.field_176 == gTrackRenderer.field_184 )
                goto LABEL_13;
              field_160 = gTrackRenderer.field_160;
            }
            else
            {
              field_160 = gTrackRenderer.field_160;
            }
            gTrackRenderer.field_168 = field_160;
            gTrackRenderer.field_184 = gTrackRenderer.field_176;
            gTrackRenderer.flag153 = 0;
            ReallySetupCameraData__16CB4TrackRenderer(&gTrackRenderer);
            v17 = v14;
LABEL_13:
            v18 = v14 + 1;
            v19 = pStreamedTrack + 164;
            v20 = (pStreamedTrack + 126);
            LODWORD(v21) = 16;
            do
            {
              v22 = *v20 & 3LL;
              if ( v22 )
              {
                v23 = *(*(pStreamedTrack + 492) + v17 + 294);
                v24 = v23 < 0;
                v25 = v23 << 6;
                if ( !v24 )
                {
                  v26 = v25 + *(*v19 + 84);
                  if ( *(v26 + 12) )
                    RenderMesh__16CB4TrackRendererRC12CB4TrackMesh16EB4TrackClipModeb(&gTrackRenderer, v26, v22, 0);
                }
                v19 += 4;
              }
              else
              {
                v19 += 4;
              }
              v17 += 169;
              v21 = v21 - 1;
              ++v20;
            }
            while ( v21 >= 0 );
            LODWORD(v14) = v18;
            EndMaterial__16CB4TrackRenderer(&gTrackRenderer);
            v13 = *(pStreamedTrack + 492);
            v15 = 2 * v18;
          }
          while ( v18 < *(v13 + 98) );
        }
        result = RestoreRenderStatesAfterRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
      }
    }
  }
  __asm
  {
    lq           $s0, 0xA0+var_10($sp)
    lq           $s1, 0xA0+var_20($sp)
    lq           $s2, 0xA0+var_30($sp)
    lq           $s3, 0xA0+var_40($sp)
    lq           $s4, 0xA0+var_50($sp)
    lq           $s5, 0xA0+var_60($sp)
    lq           $s6, 0xA0+var_70($sp)
    lq           $s7, 0xA0+var_80($sp)
    lq           $fp, 0xA0+var_90($sp)
  }
  return result;
}

// CB4StreamedTrack::RenderAfterSpecular(void)
__int64 __fastcall RenderAfterSpecular__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 v10; // $ra
  __int64 result; // $v0
  __int64 v13; // $a0
  int v14; // $s3
  float v15; // $f20
  int v16; // $a1
  __int16 v17; // $a4
  __int64 v18; // $fp
  unsigned int v19; // $a3
  __int64 v20; // $s7
  unsigned int v21; // $s1
  _WORD *v22; // $s0
  __int64 v23; // $s2
  int v24; // $a1
  _WORD *v25; // $s0
  unsigned int v26; // $s1
  __int64 v27; // $s2
  __int64 v28; // $a2
  unsigned int v29; // $a1
  _BYTE *v30; // $a0
  char v31; // $v1
  _WORD *v32; // $s0
  int v33; // $a0
  __int64 v34; // $s3
  int v35; // $v0
  uint64_t field_160; // $v0
  int v37; // $s2
  __int64 v38; // $s7
  _WORD *v39; // $s0
  unsigned int v40; // $s1
  __int64 v41; // $a2
  __int64 v42; // $a0
  bool v43; // dc
  int v44; // $a0
  int v45; // $a1
  int *v46; // $s1
  __int64 v47; // $s2
  _BYTE v57[32]; // [sp+0h] [-D0h] BYREF
  int v58; // [sp+20h] [-B0h]
  _WORD *v59; // [sp+24h] [-ACh]
  __int64 v60; // [sp+30h] [-A0h]

  __asm
  {
    sq           $s6, 0xD0+var_70($sp)
    sq           $s0, 0xD0+var_10($sp)
    sq           $s1, 0xD0+var_20($sp)
    sq           $s2, 0xD0+var_30($sp)
    sq           $s3, 0xD0+var_40($sp)
    sq           $s4, 0xD0+var_50($sp)
    sq           $s5, 0xD0+var_60($sp)
    sq           $s7, 0xD0+var_80($sp)
    sq           $fp, 0xD0+var_90($sp)
  }
  v60 = v10;
  result = *&gWorld.m_StaticTrack[4];
  v13 = *(pStreamedTrack + 92);
  v58 = *&gWorld.m_StaticTrack[4];
  if ( !v13 )
    goto LABEL_56;
  v59 = (pStreamedTrack + 126);
  PrepareRenderStatesForRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
  if ( gGraphicsManager.pad_0048[17] )
  {
    v14 = 0;
    if ( *(v58 + 52) > 0LL )
    {
      do
      {
        v15 = 0.0;
        v16 = 80 * v14 + *(v58 + 56);
        v17 = *(v16 + 62);
        v18 = 0LL;
        if ( (v17 & 4) != 0 )
        {
          v15 = *(v16 + 72);
          v18 = 1LL;
        }
        v19 = 40 * *(v16 + 56) + *(v58 + 8);
        v20 = v14 + 1;
        if ( (*(v19 + 36) & 4LL) == 0 )
        {
          BeginInstanceRender__16CB4TrackRendererPC15CB4InstanceMeshPC17CGtAxisAlignedBoxRC16CB4TrackMaterialff24EB4InstanceDistanceCheckbf(
            &gTrackRenderer,
            v16 + 32,
            v16,
            v19,
            v17 & 1,
            v18,
            *(v16 + 64),
            v15);
          PushCameraForInstanceRendering__16CB4TrackRenderer19EB4RenderableCamera(&gTrackRenderer, 0);
          v21 = pStreamedTrack + 308;
          v22 = v59;
          LODWORD(v23) = 16;
          do
          {
            if ( (*v22 & 3LL) != 0 )
            {
              if ( *(**v21 + v14) )
                RenderInstances__16CB4TrackRendererScPC15CB4InstanceData(
                  &gTrackRenderer,
                  *(**v21 + v14),
                  *(4 * v14 + *(*v21 + 4)));
              v21 += 4;
            }
            else
            {
              v21 += 4;
            }
            v23 = v23 - 1;
            ++v22;
          }
          while ( v23 >= 0 );
          EndInstanceRender__16CB4TrackRenderer(&gTrackRenderer);
          v24 = 80 * v14 + *(v58 + 56);
          if ( (*(v24 + 62) & 1LL) != 0 )
          {
            BeginInstanceRender__16CB4TrackRendererPC15CB4InstanceMeshPC17CGtAxisAlignedBoxRC16CB4TrackMaterialff24EB4InstanceDistanceCheckbf(
              &gTrackRenderer,
              v24 + 40,
              80 * v14 + *(v58 + 56),
              (*(v58 + 8) + 40 * *(v24 + 58)),
              2LL,
              v18,
              *(v24 + 64),
              v15);
            v25 = v59;
            v26 = pStreamedTrack + 308;
            PushCameraForInstanceRendering__16CB4TrackRenderer19EB4RenderableCamera(&gTrackRenderer, 0);
            LODWORD(v27) = 16;
            do
            {
              if ( (*v25 & 3LL) != 0 )
              {
                if ( *(**v26 + v14) )
                  RenderInstances__16CB4TrackRendererScPC15CB4InstanceData(
                    &gTrackRenderer,
                    *(**v26 + v14),
                    *(4 * v14 + *(*v26 + 4)));
                v26 += 4;
              }
              else
              {
                v26 += 4;
              }
              v27 = v27 - 1;
              ++v25;
            }
            while ( v27 >= 0 );
            EndInstanceRender__16CB4TrackRenderer(&gTrackRenderer);
          }
        }
        ++v14;
      }
      while ( v20 < *(v58 + 52) );
    }
  }
  LODWORD(v28) = 0;
  if ( gGraphicsManager.pad_0048[19] )
  {
    v29 = *(pStreamedTrack + 496) + 291;
    do
    {
      v30 = &v57[v28];
      v31 = *v29;
      v28 = v28 + 1;
      v29 += 169;
      *v30 = v31;
    }
    while ( v28 < 17 );
    Render__14CB4PropManagerScsPSc(gWorld.m_PropManager);
  }
  if ( gGraphicsManager.pad_0048[15] )
  {
    if ( gDebugManager.physicsDebug[6] )
    {
      v32 = v59;
      goto LABEL_51;
    }
    v33 = *(pStreamedTrack + 492);
    v34 = *(v33 + 98);
    if ( v34 >= *(v33 + 97) )
    {
      v32 = v59;
      goto LABEL_51;
    }
    v35 = 2 * v34;
    do
    {
      BeginNonInstanceRender__16CB4TrackRendererRC16CB4TrackMaterial(
        &gTrackRenderer,
        (*(v58 + 8) + 40 * *(v33 + v35 + 116)));
      if ( gTrackRenderer.flag153 )
      {
        field_160 = gTrackRenderer.field_160;
      }
      else if ( gTrackRenderer.field_160 == gTrackRenderer.field_168 )
      {
        v37 = v34;
        if ( gTrackRenderer.field_176 == gTrackRenderer.field_184 )
          goto LABEL_41;
        field_160 = gTrackRenderer.field_160;
      }
      else
      {
        field_160 = gTrackRenderer.field_160;
      }
      gTrackRenderer.field_168 = field_160;
      gTrackRenderer.field_184 = gTrackRenderer.field_176;
      gTrackRenderer.flag153 = 0;
      ReallySetupCameraData__16CB4TrackRenderer(&gTrackRenderer);
      v37 = v34;
LABEL_41:
      v38 = v34 + 1;
      v39 = v59;
      v40 = pStreamedTrack + 164;
      LODWORD(v34) = 16;
      do
      {
        v41 = *v39 & 3LL;
        if ( v41 )
        {
          v42 = *(*(pStreamedTrack + 492) + v37 + 294);
          v43 = v42 < 0;
          v44 = v42 << 6;
          if ( !v43 )
          {
            v45 = v44 + *(*v40 + 84);
            if ( *(v45 + 12) )
              RenderMesh__16CB4TrackRendererRC12CB4TrackMesh16EB4TrackClipModeb(&gTrackRenderer, v45, v41, 0);
          }
          v40 += 4;
        }
        else
        {
          v40 += 4;
        }
        v37 += 169;
        v34 = v34 - 1;
        ++v39;
      }
      while ( v34 >= 0 );
      LODWORD(v34) = v38;
      EndMaterial__16CB4TrackRenderer(&gTrackRenderer);
      v33 = *(pStreamedTrack + 492);
      v35 = 2 * v38;
    }
    while ( v38 < *(v33 + 97) );
  }
  v32 = v59;
LABEL_51:
  v46 = (pStreamedTrack + 236);
  LODWORD(v47) = 16;
  do
  {
    if ( (*v32 & 3LL) != 0 )
      SubmitWorldCoronasForRendering__17CB4EffectsManagerP35CB4StreamedTrackLODAndCollisionData(&gEffectsManager, *v46);
    ++v46;
    v47 = v47 - 1;
    ++v32;
  }
  while ( v47 >= 0 );
  result = RestoreRenderStatesAfterRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
LABEL_56:
  __asm
  {
    lq           $s0, 0xD0+var_10($sp)
    lq           $s1, 0xD0+var_20($sp)
    lq           $s2, 0xD0+var_30($sp)
    lq           $s3, 0xD0+var_40($sp)
    lq           $s4, 0xD0+var_50($sp)
    lq           $s5, 0xD0+var_60($sp)
    lq           $s6, 0xD0+var_70($sp)
    lq           $s7, 0xD0+var_80($sp)
    lq           $fp, 0xD0+var_90($sp)
  }
  return result;
}

// CB4StreamedTrack::RenderChevrons(void)
__int64 __fastcall RenderChevrons__16CB4StreamedTrack(int pStreamedTrack)
{
  __int64 result; // $v0
  int v11; // $s2
  bool v12; // dc
  int v13; // $a0
  __int64 v14; // $a1
  int v15; // $s0
  int v16; // $a1
  _BYTE *v17; // $v0
  int v18; // $a1

  __asm
  {
    sq           $s1, 0x90+var_20($sp)
    sq           $s0, 0x90+var_10($sp)
    sq           $s2, 0x90+var_30($sp)
    sq           $s3, 0x90+var_40($sp)
    sq           $s4, 0x90+var_50($sp)
    sq           $s5, 0x90+var_60($sp)
    sq           $s6, 0x90+var_70($sp)
    sq           $s7, 0x90+var_80($sp)
  }
  result = 30998528LL;
  if ( *(pStreamedTrack + 92) )
  {
    v11 = *&gWorld.m_StaticTrack[4];
    v12 = AllowChevronRender__16CB4StreamedTrack(pStreamedTrack) == 0;
    result = 29556736LL;
    if ( !v12 )
    {
      PrepareRenderStatesForRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
      RenderBackdrop__14CB4StaticTrackRC17CB4BackdropObject(
        gWorld.m_StaticTrack,
        (*(v11 + 40) + 8 * *(*(pStreamedTrack + 496) + 109)));
      v13 = *(pStreamedTrack + 496);
      LODWORD(v14) = 0;
      if ( *(v13 + 282) > 0LL )
      {
        v15 = 0x1000000;
        do
        {
          v16 = *(v13 + v14 + 283);
          v17 = &16CB4StreamedTrack_mabRenderActiveDetourChevrons + v16;
          if ( 16CB4StreamedTrack_mabActiveDetourChevrons[v16] )
          {
            v18 = 8 * v16;
            if ( *v17 )
              RenderBackdrop__14CB4StaticTrackRC17CB4BackdropObject(gWorld.m_StaticTrack, (*(v11 + 40) + v18));
          }
          v13 = *(pStreamedTrack + 496);
          v14 = v15 >> 24;
          v15 += 0x1000000;
        }
        while ( v14 < *(v13 + 282) );
      }
      result = RestoreRenderStatesAfterRenderingTrack__16CB4TrackRenderer(&gTrackRenderer);
    }
  }
  __asm
  {
    lq           $s0, 0x90+var_10($sp)
    lq           $s1, 0x90+var_20($sp)
    lq           $s2, 0x90+var_30($sp)
    lq           $s3, 0x90+var_40($sp)
    lq           $s4, 0x90+var_50($sp)
    lq           $s5, 0x90+var_60($sp)
    lq           $s6, 0x90+var_70($sp)
    lq           $s7, 0x90+var_80($sp)
  }
  return result;
}

