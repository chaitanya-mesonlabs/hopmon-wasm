// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JStandard.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JStandard.h"

// ============================================================================
// Address: 0x4136a0 | Symbol: Randomize
// ============================================================================
void Randomize(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  FUN_0044ccb8(DVar1);
  return;
}

// ============================================================================
// Address: 0x4136c0 | Symbol: Random
// ============================================================================
int Random(int param_1)

{
  int iVar1;
  
  if (param_1 < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0044cc97();
    iVar1 = iVar1 % param_1;
  }
  return iVar1;
}

// ============================================================================
// Address: 0x4136e0 | Symbol: Round
// ============================================================================
int Round(float param_1)

{
  if (param_1 < 0.0) {
    param_1 = param_1 - 0.5;
  }
  else {
    param_1 = param_1 + 0.5;
  }
  return (int)param_1;
}

// ============================================================================
// Address: 0x413720 | Symbol: D3DVectorMultiply
// ============================================================================
float * D3DVectorMultiply(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  
  FUN_00403f60();
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *param_1 = (float)param_3 * *param_2;
  param_1[1] = (float)param_3 * fVar1;
  param_1[2] = (float)param_3 * fVar2;
  return param_1;
}

// ============================================================================
// Address: 0x413780 | Symbol: FUN_00413780
// ============================================================================
float * FUN_00413780(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  FUN_00403f60();
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  *param_1 = *param_2 * param_3;
  param_1[1] = fVar1 * param_3;
  param_1[2] = fVar2 * param_3;
  return param_1;
}

// ============================================================================
// Address: 0x4137e0 | Symbol: D3DFindDistance
// ============================================================================
void D3DFindDistance(float *param_1,float *param_2)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float10)fabsf(*param_1 - *param_2);
  fVar2 = (float10)fabsf(param_1[1] - param_2[1]);
  fVar3 = (float10)fabsf(param_1[2] - param_2[2]);
  sqrtf((float)fVar1 * (float)fVar1 + (float)fVar2 * (float)fVar2 + (float)fVar3 * (float)fVar3);
  return;
}

// ============================================================================
// Address: 0x413880 | Symbol: fabsf
// ============================================================================
float10 fabsf(float param_1)

{
  double dVar1;
  
  dVar1 = _fabs((double)param_1);
  return (float10)(float)dVar1;
}
