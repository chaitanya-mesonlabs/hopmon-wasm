// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: d3dmath.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "d3dmath.h"

// ============================================================================
// Address: 0x4093c0 | Symbol: D3DMath_MatrixMultiply
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void D3DMath_MatrixMultiply(undefined4 param_1,int param_2,int param_3)

{
  ushort local_54;
  ushort local_50;
  ushort local_4c;
  float local_48 [16];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  _memset(local_48,0,0x40);
  for (local_50 = 0; local_50 < 4; local_50 = local_50 + 1) {
    for (local_4c = 0; local_4c < 4; local_4c = local_4c + 1) {
      for (local_54 = 0; local_54 < 4; local_54 = local_54 + 1) {
        local_48[(uint)local_4c + (uint)local_50 * 4] =
             *(float *)(param_2 + ((uint)local_54 + (uint)local_50 * 4) * 4) *
             *(float *)(param_3 + ((uint)local_4c + (uint)local_54 * 4) * 4) +
             local_48[(uint)local_4c + (uint)local_50 * 4];
      }
    }
  }
  FUN_004307f0(param_1,local_48,0x40);
  return;
}

// ============================================================================
// Address: 0x4094c0 | Symbol: D3DMath_MatrixInvert
// ============================================================================
undefined4 D3DMath_MatrixInvert(float *param_1,float *param_2)

{
  float fVar1;
  double dVar2;
  
  dVar2 = _fabs((double)(param_2[0xf] - 1.0));
  if ((((dVar2 <= 0.0010000000474974513) &&
       (dVar2 = _fabs((double)param_2[3]), dVar2 <= 0.0010000000474974513)) &&
      (dVar2 = _fabs((double)param_2[7]), dVar2 <= 0.0010000000474974513)) &&
     (dVar2 = _fabs((double)param_2[0xb]), dVar2 <= 0.0010000000474974513)) {
    fVar1 = 1.0 / (((param_2[5] * param_2[10] - param_2[6] * param_2[9]) * *param_2 -
                   (param_2[4] * param_2[10] - param_2[6] * param_2[8]) * param_2[1]) +
                  (param_2[4] * param_2[9] - param_2[5] * param_2[8]) * param_2[2]);
    *param_1 = (param_2[5] * param_2[10] - param_2[6] * param_2[9]) * fVar1;
    param_1[1] = -fVar1 * (param_2[1] * param_2[10] - param_2[2] * param_2[9]);
    param_1[2] = (param_2[1] * param_2[6] - param_2[2] * param_2[5]) * fVar1;
    param_1[3] = 0.0;
    param_1[4] = -fVar1 * (param_2[4] * param_2[10] - param_2[6] * param_2[8]);
    param_1[5] = (*param_2 * param_2[10] - param_2[2] * param_2[8]) * fVar1;
    param_1[6] = -fVar1 * (*param_2 * param_2[6] - param_2[2] * param_2[4]);
    param_1[7] = 0.0;
    param_1[8] = (param_2[4] * param_2[9] - param_2[5] * param_2[8]) * fVar1;
    param_1[9] = -fVar1 * (*param_2 * param_2[9] - param_2[1] * param_2[8]);
    param_1[10] = (*param_2 * param_2[5] - param_2[1] * param_2[4]) * fVar1;
    param_1[0xb] = 0.0;
    param_1[0xc] = -(param_2[0xc] * *param_1 + param_2[0xd] * param_1[4] + param_2[0xe] * param_1[8]
                    );
    param_1[0xd] = -(param_2[0xc] * param_1[1] + param_2[0xd] * param_1[5] +
                    param_2[0xe] * param_1[9]);
    param_1[0xe] = -(param_2[0xc] * param_1[2] + param_2[0xd] * param_1[6] +
                    param_2[0xe] * param_1[10]);
    param_1[0xf] = 1.0;
    return 0;
  }
  return 0x80070057;
}

// ============================================================================
// Address: 0x409920 | Symbol: D3DMath_VectorMatrixMultiply
// ============================================================================
undefined4 D3DMath_VectorMatrixMultiply(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  float fVar23;
  double dVar24;
  
  fVar1 = *param_2;
  fVar2 = *param_3;
  fVar3 = param_2[1];
  fVar4 = param_3[4];
  fVar5 = param_2[2];
  fVar6 = param_3[8];
  fVar7 = param_3[0xc];
  fVar8 = *param_2;
  fVar9 = param_3[1];
  fVar10 = param_2[1];
  fVar11 = param_3[5];
  fVar12 = param_2[2];
  fVar13 = param_3[9];
  fVar14 = param_3[0xd];
  fVar15 = *param_2;
  fVar16 = param_3[2];
  fVar17 = param_2[1];
  fVar18 = param_3[6];
  fVar19 = param_2[2];
  fVar20 = param_3[10];
  fVar21 = param_3[0xe];
  fVar23 = *param_2 * param_3[3] + param_2[1] * param_3[7] + param_2[2] * param_3[0xb] +
           param_3[0xf];
  dVar24 = _fabs((double)fVar23);
  if (9.999999747378752e-06 <= dVar24) {
    *param_1 = (fVar1 * fVar2 + fVar3 * fVar4 + fVar5 * fVar6 + fVar7) / fVar23;
    param_1[1] = (fVar8 * fVar9 + fVar10 * fVar11 + fVar12 * fVar13 + fVar14) / fVar23;
    param_1[2] = (fVar15 * fVar16 + fVar17 * fVar18 + fVar19 * fVar20 + fVar21) / fVar23;
    uVar22 = 0;
  }
  else {
    uVar22 = 0x80070057;
  }
  return uVar22;
}

// ============================================================================
// Address: 0x409aa0 | Symbol: D3DMath_VertexMatrixMultiply
// ============================================================================
int D3DMath_VertexMatrixMultiply(int param_1,int param_2,undefined4 param_3)

{
  undefined4 local_10;
  
  local_10 = D3DMath_VectorMatrixMultiply(param_1,param_2,param_3);
  if (-1 < local_10) {
    local_10 = D3DMath_VectorMatrixMultiply(param_1 + 0xc,param_2 + 0xc,param_3);
  }
  return local_10;
}

// ============================================================================
// Address: 0x409b00 | Symbol: D3DMath_QuaternionFromRotation
// ============================================================================
void D3DMath_QuaternionFromRotation
               (float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
               float param_6)

{
  float10 fVar1;
  
  fVar1 = (float10)sinf(param_6 / 2.0);
  *param_1 = (float)fVar1 * *param_5;
  fVar1 = (float10)sinf(param_6 / 2.0);
  *param_2 = (float)fVar1 * param_5[1];
  fVar1 = (float10)sinf(param_6 / 2.0);
  *param_3 = (float)fVar1 * param_5[2];
  fVar1 = (float10)cosf(param_6 / 2.0);
  *param_4 = (float)fVar1;
  return;
}

// ============================================================================
// Address: 0x409bc0 | Symbol: D3DMath_RotationFromQuaternion
// ============================================================================
void D3DMath_RotationFromQuaternion
               (float *param_1,float *param_2,float param_3,float param_4,float param_5,
               undefined4 param_6)

{
  float10 fVar1;
  
  fVar1 = (float10)acosf(param_6);
  *param_2 = (float)fVar1 * 2.0;
  fVar1 = (float10)sinf(*param_2 / 2.0);
  *param_1 = param_3 / (float)fVar1;
  fVar1 = (float10)sinf(*param_2 / 2.0);
  param_1[1] = param_4 / (float)fVar1;
  fVar1 = (float10)sinf(*param_2 / 2.0);
  param_1[2] = param_5 / (float)fVar1;
  return;
}

// ============================================================================
// Address: 0x409c90 | Symbol: D3DMath_QuaternionFromAngles
// ============================================================================
void D3DMath_QuaternionFromAngles
               (float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
               float param_6,float param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  
  fVar7 = (float10)sinf(param_5 / 2.0);
  fVar1 = (float)fVar7;
  fVar7 = (float10)sinf(param_6 / 2.0);
  fVar2 = (float)fVar7;
  fVar7 = (float10)sinf(param_7 / 2.0);
  fVar3 = (float)fVar7;
  fVar7 = (float10)cosf(param_5 / 2.0);
  fVar4 = (float)fVar7;
  fVar7 = (float10)cosf(param_6 / 2.0);
  fVar5 = (float)fVar7;
  fVar7 = (float10)cosf(param_7 / 2.0);
  fVar6 = (float)fVar7;
  *param_1 = fVar3 * fVar5 * fVar4 - fVar6 * fVar2 * fVar1;
  *param_2 = fVar6 * fVar2 * fVar4 + fVar3 * fVar5 * fVar1;
  *param_3 = fVar6 * fVar5 * fVar1 - fVar3 * fVar2 * fVar4;
  *param_4 = fVar6 * fVar5 * fVar4 + fVar3 * fVar2 * fVar1;
  return;
}

// ============================================================================
// Address: 0x409e00 | Symbol: D3DMath_MatrixFromQuaternion
// ============================================================================
void D3DMath_MatrixFromQuaternion
               (float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  *param_1 = 1.0 - (param_3 * param_3 + param_4 * param_4) * 2.0;
  param_1[1] = (param_2 * param_3 - param_5 * param_4) * 2.0;
  param_1[2] = (param_2 * param_4 + param_5 * param_3) * 2.0;
  param_1[4] = (param_2 * param_3 + param_5 * param_4) * 2.0;
  param_1[5] = 1.0 - (param_2 * param_2 + param_4 * param_4) * 2.0;
  param_1[6] = (param_3 * param_4 - param_5 * param_2) * 2.0;
  param_1[8] = (param_2 * param_4 - param_5 * param_3) * 2.0;
  param_1[9] = (param_3 * param_4 + param_5 * param_2) * 2.0;
  param_1[10] = 1.0 - (param_2 * param_2 + param_3 * param_3) * 2.0;
  param_1[0xb] = 0.0;
  param_1[7] = 0.0;
  param_1[3] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xf] = 1.0;
  return;
}

// ============================================================================
// Address: 0x409ff0 | Symbol: D3DMath_QuaternionFromMatrix
// ============================================================================
void D3DMath_QuaternionFromMatrix
               (float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float10 fVar19;
  
  if (0.0 < *param_5 + param_5[5] + param_5[10]) {
    fVar19 = (float10)sqrtf(*param_5 + param_5[5] + param_5[10] + param_5[0xf]);
    fVar18 = (float)fVar19;
    *param_1 = (param_5[6] - param_5[9]) / (fVar18 * 2.0);
    *param_2 = (param_5[8] - param_5[2]) / (fVar18 * 2.0);
    *param_3 = (param_5[1] - param_5[4]) / (fVar18 * 2.0);
    *param_4 = fVar18 * 0.5;
  }
  fVar18 = *param_1;
  fVar1 = *param_1;
  fVar2 = *param_2;
  fVar3 = *param_2;
  fVar4 = *param_3;
  fVar5 = *param_3;
  fVar6 = *param_1;
  fVar7 = *param_2;
  fVar8 = *param_1;
  fVar9 = *param_3;
  fVar10 = *param_2;
  fVar11 = *param_3;
  fVar12 = *param_4;
  fVar13 = *param_1;
  fVar14 = *param_4;
  fVar15 = *param_2;
  fVar16 = *param_4;
  fVar17 = *param_3;
  *param_5 = 1.0 - (fVar2 * fVar3 + fVar4 * fVar5) * 2.0;
  param_5[1] = (fVar6 * fVar7 - fVar16 * fVar17) * 2.0;
  param_5[2] = (fVar8 * fVar9 + fVar14 * fVar15) * 2.0;
  param_5[4] = (fVar6 * fVar7 + fVar16 * fVar17) * 2.0;
  param_5[5] = 1.0 - (fVar18 * fVar1 + fVar4 * fVar5) * 2.0;
  param_5[6] = (fVar10 * fVar11 - fVar12 * fVar13) * 2.0;
  param_5[8] = (fVar8 * fVar9 - fVar14 * fVar15) * 2.0;
  param_5[9] = (fVar10 * fVar11 + fVar12 * fVar13) * 2.0;
  param_5[10] = 1.0 - (fVar18 * fVar1 + fVar2 * fVar3) * 2.0;
  param_5[0xb] = 0.0;
  param_5[7] = 0.0;
  param_5[3] = 0.0;
  param_5[0xe] = 0.0;
  param_5[0xd] = 0.0;
  param_5[0xc] = 0.0;
  param_5[0xf] = 1.0;
  return;
}

// ============================================================================
// Address: 0x40a2f0 | Symbol: D3DMath_QuaternionMultiply
// ============================================================================
void D3DMath_QuaternionMultiply
               (float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
               float param_6,float param_7,float param_8,float param_9,float param_10,float param_11
               ,float param_12)

{
  *param_1 = ((param_5 * param_12 + param_6 * param_11) - param_7 * param_10) + param_8 * param_9;
  *param_2 = -param_5 * param_11 + param_6 * param_12 + param_7 * param_9 + param_8 * param_10;
  *param_3 = (param_5 * param_10 - param_6 * param_9) + param_7 * param_12 + param_8 * param_11;
  *param_4 = ((-param_5 * param_9 - param_6 * param_10) - param_7 * param_11) + param_8 * param_12;
  return;
}

// ============================================================================
// Address: 0x40a420 | Symbol: D3DMath_QuaternionSlerp
// ============================================================================
void D3DMath_QuaternionSlerp
               (float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
               float param_6,float param_7,float param_8,float param_9,float param_10,float param_11
               ,float param_12,float param_13)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_5 * param_9 + param_6 * param_10 + param_7 * param_11 + param_8 * param_12;
  if (local_c < 0.0) {
    local_c = -local_c;
    param_9 = -param_9;
    param_10 = -param_10;
    param_11 = -param_11;
    param_12 = -param_12;
  }
  local_8 = 1.0 - param_13;
  if (0.001 < 1.0 - local_c) {
    fVar2 = (float10)acosf(local_c);
    fVar1 = (float)fVar2;
    fVar2 = (float10)sinf(fVar1 * local_8);
    fVar3 = (float10)sinf(fVar1);
    local_8 = (float)fVar2 / (float)fVar3;
    fVar2 = (float10)sinf(fVar1 * param_13);
    fVar3 = (float10)sinf(fVar1);
    param_13 = (float)fVar2 / (float)fVar3;
  }
  *param_1 = local_8 * param_5 + param_13 * param_9;
  *param_2 = local_8 * param_6 + param_13 * param_10;
  *param_3 = local_8 * param_7 + param_13 * param_11;
  *param_4 = local_8 * param_8 + param_13 * param_12;
  return;
}

// ============================================================================
// Address: 0x40a620 | Symbol: acosf
// ============================================================================
float10 acosf(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_0044c270((double)param_1);
  return (float10)(float)fVar1;
}

// ============================================================================
// Address: 0x40a650 | Symbol: cosf
// ============================================================================
float10 cosf(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_0044c2c0((double)param_1);
  return (float10)(float)fVar1;
}

// ============================================================================
// Address: 0x40a680 | Symbol: sinf
// ============================================================================
float10 sinf(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_0044c360((double)param_1);
  return (float10)(float)fVar1;
}

// ============================================================================
// Address: 0x40a6b0 | Symbol: sqrtf
// ============================================================================
float10 sqrtf(float param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_0044bca0((double)param_1);
  return (float10)(float)fVar1;
}
