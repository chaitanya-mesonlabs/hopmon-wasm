// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: d3dutil.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "d3dutil.h"

// ============================================================================
// Address: 0x40bf30 | Symbol: D3DUtil_GetDXSDKMediaPath
// ============================================================================
undefined * D3DUtil_GetDXSDKMediaPath(void)

{
  undefined *puVar1;
  DWORD local_14 [2];
  HKEY local_c;
  LSTATUS local_8;
  
  local_14[1] = 0x200;
  local_8 = RegOpenKeyExA((HKEY)0x80000002,"Software\\Microsoft\\DirectX",0,0x20019,&local_c);
  if (local_8 == 0) {
    local_8 = RegQueryValueExA(local_c,"DXSDK Samples Path",(LPDWORD)0x0,local_14,&DAT_0048e010,
                               local_14 + 1);
    RegCloseKey(local_c);
    if (local_8 == 0) {
      lstrcatA(&DAT_0048e010,"\\D3DIM\\Media\\");
      puVar1 = &DAT_0048e010;
    }
    else {
      puVar1 = &DAT_0048e00c;
    }
  }
  else {
    puVar1 = &DAT_0048e00c;
  }
  return puVar1;
}

// ============================================================================
// Address: 0x40bfc0 | Symbol: D3DUtil_InitSurfaceDesc
// ============================================================================
void D3DUtil_InitSurfaceDesc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  _memset(param_1,0,0x7c);
  *param_1 = 0x7c;
  param_1[1] = param_2;
  param_1[0x1a] = param_3;
  param_1[0x12] = 0x20;
  return;
}

// ============================================================================
// Address: 0x40c000 | Symbol: D3DUtil_InitMaterial
// ============================================================================
void D3DUtil_InitMaterial
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  _memset(param_1,0,0x44);
  param_1[4] = param_2;
  *param_1 = param_2;
  param_1[5] = param_3;
  param_1[1] = param_3;
  param_1[6] = param_4;
  param_1[2] = param_4;
  param_1[7] = param_5;
  param_1[3] = param_5;
  return;
}

// ============================================================================
// Address: 0x40c080 | Symbol: D3DUtil_InitLight
// ============================================================================
void D3DUtil_InitLight(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  float10 fVar1;
  
  _memset(param_1,0,0x68);
  *param_1 = param_2;
  param_1[1] = 0x3f800000;
  param_1[2] = 0x3f800000;
  param_1[3] = 0x3f800000;
  param_1[5] = param_1[1];
  param_1[6] = param_1[2];
  param_1[7] = param_1[3];
  param_1[8] = param_1[4];
  param_1[0x10] = param_3;
  param_1[0xd] = param_3;
  param_1[0x11] = param_4;
  param_1[0xe] = param_4;
  param_1[0x12] = param_5;
  param_1[0xf] = param_5;
  param_1[0x15] = 0x3f800000;
  fVar1 = (float10)FUN_0044bca0(0x47efffffe0000000);
  param_1[0x13] = (float)fVar1;
  return;
}

// ============================================================================
// Address: 0x40c170 | Symbol: FUN_0040c170
// ============================================================================
void FUN_0040c170(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  float10 fVar1;
  
  _memset(param_1,0,0x68);
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_3;
  param_1[3] = param_3;
  param_1[5] = param_4;
  param_1[6] = param_4;
  param_1[7] = param_4;
  param_1[0x10] = param_5;
  param_1[0xd] = param_5;
  param_1[0x11] = param_6;
  param_1[0xe] = param_6;
  param_1[0x12] = param_7;
  param_1[0xf] = param_7;
  param_1[0x15] = 0x3f800000;
  fVar1 = (float10)FUN_0044bca0(0x47efffffe0000000);
  param_1[0x13] = (float)fVar1;
  return;
}

// ============================================================================
// Address: 0x40c260 | Symbol: D3DUtil_SetViewMatrix
// ============================================================================
undefined4
D3DUtil_SetViewMatrix(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined1 local_90 [24];
  undefined1 local_78 [12];
  undefined1 local_6c [24];
  undefined1 local_54 [12];
  undefined1 local_48 [12];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  operator-(&local_20,param_3,param_2);
  fVar4 = (float10)Magnitude(&local_20);
  local_8 = (float)fVar4;
  if (1e-06 <= local_8) {
    _D3DVECTOR__operator__(local_8);
    fVar4 = (float10)DotProduct(param_4,&local_20);
    local_24 = (float)fVar4;
    uVar1 = operator*(local_48,local_24,&local_20);
    operator-(&local_14,param_4,uVar1);
    fVar4 = (float10)Magnitude(&local_14);
    local_8 = (float)fVar4;
    if (local_8 < 1e-06) {
      uVar1 = operator*(local_54,local_1c,&local_20);
      uVar2 = _D3DVECTOR___D3DVECTOR(0,0x3f800000,0);
      puVar3 = (undefined4 *)operator-(local_6c,uVar2,uVar1);
      local_14 = *puVar3;
      local_10 = puVar3[1];
      local_c = puVar3[2];
      fVar4 = (float10)Magnitude(&local_14);
      local_8 = (float)fVar4;
      if (local_8 < 1e-06) {
        uVar1 = operator*(local_78,local_18,&local_20);
        uVar2 = _D3DVECTOR___D3DVECTOR(0,0,0x3f800000);
        puVar3 = (undefined4 *)operator-(local_90,uVar2,uVar1);
        local_14 = *puVar3;
        local_10 = puVar3[1];
        local_c = puVar3[2];
        fVar4 = (float10)Magnitude(&local_14);
        local_8 = (float)fVar4;
        if (local_8 < 1e-06) {
          return 0x80070057;
        }
      }
    }
    _D3DVECTOR__operator__(local_8);
    CrossProduct(&local_3c,&local_14,&local_20);
    D3DUtil_SetIdentityMatrix(param_1);
    *param_1 = local_3c;
    param_1[1] = local_14;
    param_1[2] = local_20;
    param_1[4] = local_38;
    param_1[5] = local_10;
    param_1[6] = local_1c;
    param_1[8] = local_34;
    param_1[9] = local_c;
    param_1[10] = local_18;
    fVar4 = (float10)DotProduct(param_2,&local_3c);
    local_28 = (float)fVar4;
    param_1[0xc] = -local_28;
    fVar4 = (float10)DotProduct(param_2,&local_14);
    local_2c = (float)fVar4;
    param_1[0xd] = -local_2c;
    fVar4 = (float10)DotProduct(param_2,&local_20);
    param_1[0xe] = -(float)fVar4;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x40c550 | Symbol: D3DUtil_SetProjectionMatrix
// ============================================================================
undefined4
D3DUtil_SetProjectionMatrix(float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  undefined4 uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  double dVar6;
  
  dVar6 = _fabs((double)(param_5 - param_4));
  if (0.009999999776482582 <= dVar6) {
    fVar2 = (float10)FUN_0044c360((double)(param_2 / 2.0));
    dVar6 = _fabs((double)fVar2);
    if (0.009999999776482582 <= dVar6) {
      fVar2 = (float10)cosf();
      fVar3 = (float10)sinf();
      fVar4 = (float10)cosf();
      fVar5 = (float10)sinf();
      param_5 = param_5 / (param_5 - param_4);
      _memset(param_1,0,0x40);
      *param_1 = ((float)fVar2 / (float)fVar3) * param_3;
      param_1[5] = ((float)fVar4 / (float)fVar5) * 1.0;
      param_1[10] = param_5;
      param_1[0xb] = 1.0;
      param_1[0xe] = -param_5 * param_4;
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80070057;
    }
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x40c710 | Symbol: D3DUtil_SetRotateXMatrix
// ============================================================================
void D3DUtil_SetRotateXMatrix(int param_1,undefined4 param_2)

{
  float10 fVar1;
  
  D3DUtil_SetIdentityMatrix(param_1);
  fVar1 = (float10)cosf(param_2);
  *(float *)(param_1 + 0x14) = (float)fVar1;
  fVar1 = (float10)sinf(param_2);
  *(float *)(param_1 + 0x18) = (float)fVar1;
  fVar1 = (float10)sinf(param_2);
  *(float *)(param_1 + 0x24) = -(float)fVar1;
  fVar1 = (float10)cosf(param_2);
  *(float *)(param_1 + 0x28) = (float)fVar1;
  return;
}

// ============================================================================
// Address: 0x40c7a0 | Symbol: D3DUtil_SetRotateYMatrix
// ============================================================================
void D3DUtil_SetRotateYMatrix(float *param_1,undefined4 param_2)

{
  float10 fVar1;
  
  D3DUtil_SetIdentityMatrix(param_1);
  fVar1 = (float10)cosf(param_2);
  *param_1 = (float)fVar1;
  fVar1 = (float10)sinf(param_2);
  param_1[2] = -(float)fVar1;
  fVar1 = (float10)sinf(param_2);
  param_1[8] = (float)fVar1;
  fVar1 = (float10)cosf(param_2);
  param_1[10] = (float)fVar1;
  return;
}

// ============================================================================
// Address: 0x40c830 | Symbol: D3DUtil_SetRotateZMatrix
// ============================================================================
void D3DUtil_SetRotateZMatrix(float *param_1,undefined4 param_2)

{
  float10 fVar1;
  
  D3DUtil_SetIdentityMatrix(param_1);
  fVar1 = (float10)cosf(param_2);
  *param_1 = (float)fVar1;
  fVar1 = (float10)sinf(param_2);
  param_1[1] = (float)fVar1;
  fVar1 = (float10)sinf(param_2);
  param_1[4] = -(float)fVar1;
  fVar1 = (float10)cosf(param_2);
  param_1[5] = (float)fVar1;
  return;
}

// ============================================================================
// Address: 0x40c8c0 | Symbol: D3DUtil_SetRotationMatrix
// ============================================================================
void D3DUtil_SetRotationMatrix(float *param_1,undefined4 param_2,undefined4 param_3)

{
  float10 fVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar1 = (float10)cosf(param_3);
  local_8 = (float)fVar1;
  fVar1 = (float10)sinf(param_3);
  local_c = (float)fVar1;
  Normalize(&local_18,param_2);
  *param_1 = local_18 * local_18 * (1.0 - local_8) + local_8;
  param_1[1] = local_18 * local_14 * (1.0 - local_8) - local_10 * local_c;
  param_1[2] = local_18 * local_10 * (1.0 - local_8) + local_14 * local_c;
  param_1[4] = local_14 * local_18 * (1.0 - local_8) + local_10 * local_c;
  param_1[5] = local_14 * local_14 * (1.0 - local_8) + local_8;
  param_1[6] = local_14 * local_10 * (1.0 - local_8) - local_18 * local_c;
  param_1[8] = local_10 * local_18 * (1.0 - local_8) - local_14 * local_c;
  param_1[9] = local_10 * local_14 * (1.0 - local_8) + local_18 * local_c;
  param_1[10] = local_10 * local_10 * (1.0 - local_8) + local_8;
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
// Address: 0x40cb00 | Symbol: _DbgOut
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int _DbgOut(undefined4 param_1,undefined4 param_2,int param_3,LPCSTR param_4)

{
  CHAR local_108 [256];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  wsprintfA(local_108,"%s(%ld): ",param_1,param_2);
  OutputDebugStringA(local_108);
  OutputDebugStringA(param_4);
  if (param_3 != 0) {
    wsprintfA(local_108,"(hr=%08lx)\n",param_3);
    OutputDebugStringA(local_108);
  }
  OutputDebugStringA("\n");
  return param_3;
}

// ============================================================================
// Address: 0x40cb90 | Symbol: operator*
// ============================================================================
undefined4 operator*(undefined4 param_1,float param_2,float *param_3)

{
  _D3DVECTOR___D3DVECTOR(param_2 * *param_3,param_2 * param_3[1],param_2 * param_3[2]);
  return param_1;
}

// ============================================================================
// Address: 0x40cbe0 | Symbol: _D3DVECTOR::operator/=
// ============================================================================
float * _D3DVECTOR__operator__(float param_1)

{
  float *in_ECX;
  
  *in_ECX = *in_ECX / param_1;
  in_ECX[1] = in_ECX[1] / param_1;
  in_ECX[2] = in_ECX[2] / param_1;
  return in_ECX;
}

// ============================================================================
// Address: 0x40cc30 | Symbol: DotProduct
// ============================================================================
float10 DotProduct(float *param_1,float *param_2)

{
  return (float10)(*param_1 * *param_2 + param_1[1] * param_2[1] + param_1[2] * param_2[2]);
}
