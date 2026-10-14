// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: d3dfile.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "d3dfile.h"

// ============================================================================
// Address: 0x405870 | Symbol: CD3DFileObject::AddNext
// ============================================================================
void CD3DFileObject__AddNext(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x50) == 0) {
    *(undefined4 *)(in_ECX + 0x50) = param_1;
  }
  else {
    CD3DFileObject__AddNext(param_1);
  }
  return;
}

// ============================================================================
// Address: 0x4058a0 | Symbol: CD3DFileObject::AddChild
// ============================================================================
void CD3DFileObject__AddChild(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    *(undefined4 *)(in_ECX + 0x54) = param_1;
  }
  else {
    CD3DFileObject__AddNext(param_1);
  }
  return;
}

// ============================================================================
// Address: 0x4058d0 | Symbol: CD3DFileObject::SetNormals
// ============================================================================
void CD3DFileObject__SetNormals(int param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < *(uint *)(in_ECX + 0x9c); local_8 = local_8 + 1) {
    *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 0xc + local_8 * 0x20) =
         *(undefined4 *)(param_1 + local_8 * 0xc);
    *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 0x10 + local_8 * 0x20) =
         *(undefined4 *)(param_1 + 4 + local_8 * 0xc);
    *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 0x14 + local_8 * 0x20) =
         *(undefined4 *)(param_1 + 8 + local_8 * 0xc);
  }
  return;
}

// ============================================================================
// Address: 0x405960 | Symbol: CD3DFileObject::SetTextureCoords
// ============================================================================
void CD3DFileObject__SetTextureCoords(int param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < *(uint *)(in_ECX + 0x9c); local_8 = local_8 + 1) {
    *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 0x18 + local_8 * 0x20) =
         *(undefined4 *)(param_1 + local_8 * 8);
    *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 0x1c + local_8 * 0x20) =
         *(undefined4 *)(param_1 + 4 + local_8 * 8);
  }
  return;
}

// ============================================================================
// Address: 0x4059d0 | Symbol: CD3DFileObject::SetMaterialData
// ============================================================================
void CD3DFileObject__SetMaterialData(uint param_1,undefined4 *param_2,LPCSTR param_3)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 < 0x10) {
    puVar2 = param_2;
    puVar3 = (undefined4 *)(in_ECX + 0xb0 + param_1 * 0x98);
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    lstrcpynA((LPSTR)(in_ECX + 0xf4 + param_1 * 0x98),param_3,0x50);
    if ((float)param_2[3] <= 1.0 && (float)param_2[3] != 1.0) {
      *(undefined4 *)(in_ECX + 0xa30) = 1;
    }
  }
  return;
}

// ============================================================================
// Address: 0x405a40 | Symbol: CD3DFileObject::AddFace
// ============================================================================
void CD3DFileObject__AddFace(uint param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int in_ECX;
  uint *puVar2;
  uint local_14;
  uint local_10;
  undefined2 *local_8;
  
  if (param_1 < 0x10) {
    if (*(uint *)(in_ECX + 0xac) < param_1 + 1) {
      *(uint *)(in_ECX + 0xac) = param_1 + 1;
    }
    local_8 = *(undefined2 **)(in_ECX + 0xa8);
    for (local_14 = 0; local_14 <= param_1; local_14 = local_14 + 1) {
      local_8 = local_8 + *(int *)(in_ECX + 0x144 + local_14 * 0x98);
    }
    while (param_3 != 0) {
      uVar1 = *param_2;
      puVar2 = param_2 + 1;
      for (local_10 = 2; local_10 < uVar1; local_10 = local_10 + 1) {
        *(int *)(in_ECX + 0x144 + param_1 * 0x98) = *(int *)(in_ECX + 0x144 + param_1 * 0x98) + 3;
        *local_8 = (short)*puVar2;
        local_8[1] = (short)param_2[local_10];
        local_8[2] = (short)puVar2[local_10];
        local_8 = local_8 + 3;
      }
      param_2 = puVar2 + uVar1;
      param_3 = param_3 + -1;
    }
  }
  return;
}

// ============================================================================
// Address: 0x405b90 | Symbol: CD3DFileObject::ComputeNormals
// ============================================================================
undefined4 CD3DFileObject__ComputeNormals(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  float10 fVar4;
  undefined1 local_98 [24];
  undefined1 local_80 [12];
  undefined1 local_74 [12];
  undefined1 local_68 [12];
  undefined1 local_5c [12];
  void *local_50;
  float local_4c;
  int local_48;
  int local_44;
  void *local_40;
  int local_3c;
  void *local_38;
  uint local_34;
  void *local_30;
  ushort local_2c;
  ushort local_28;
  ushort local_24;
  uint local_20;
  void *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470896;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_34 = *(uint *)(in_ECX + 0x9c);
  local_18 = in_ECX;
  local_30 = (void *)FUN_0042d2b4(-(uint)((int)((ulonglong)local_34 * 0xc >> 0x20) != 0) |
                                  (uint)((ulonglong)local_34 * 0xc),
                                  DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (local_30 == (void *)0x0) {
    local_38 = (void *)0x0;
  }
  else {
    vector_constructor_iterator(local_30,0xc,local_34,FUN_00403f60);
    local_38 = local_30;
  }
  local_40 = local_38;
  local_8 = 0xffffffff;
  local_1c = local_38;
  _memset(local_38,0,*(int *)(local_18 + 0x9c) * 0xc);
  for (local_20 = 0; local_20 < *(uint *)(local_18 + 0xa4); local_20 = local_20 + 3) {
    local_24 = *(ushort *)(*(int *)(local_18 + 0xa8) + local_20 * 2);
    local_28 = *(ushort *)(*(int *)(local_18 + 0xa8) + 2 + local_20 * 2);
    local_2c = *(ushort *)(*(int *)(local_18 + 0xa8) + 4 + local_20 * 2);
    local_48 = (uint)local_24 * 0x20 + *(int *)(local_18 + 0xa0);
    local_3c = (uint)local_28 * 0x20 + *(int *)(local_18 + 0xa0);
    local_44 = (uint)local_2c * 0x20 + *(int *)(local_18 + 0xa0);
    uVar1 = operator-(local_68,local_44,local_3c);
    uVar1 = operator-(local_74,local_3c,local_48,uVar1);
    uVar1 = CrossProduct(local_80,uVar1);
    Normalize(local_5c,uVar1);
    _D3DVECTOR__operator__(local_5c);
    _D3DVECTOR__operator__(local_5c);
    _D3DVECTOR__operator__(local_5c);
  }
  for (local_14 = 0; local_14 < *(uint *)(local_18 + 0x9c); local_14 = local_14 + 1) {
    fVar4 = (float10)Magnitude((void *)(local_14 * 0xc + (int)local_1c));
    local_4c = (float)fVar4;
    if (local_4c < 0.1) {
      puVar2 = (undefined4 *)_D3DVECTOR___D3DVECTOR(0,0,0x3f800000);
      puVar3 = (undefined4 *)(local_14 * 0xc + (int)local_1c);
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
    }
    puVar2 = (undefined4 *)Normalize(local_98,(void *)(local_14 * 0xc + (int)local_1c));
    puVar3 = (undefined4 *)(local_14 * 0xc + (int)local_1c);
    *puVar3 = *puVar2;
    puVar3[1] = puVar2[1];
    puVar3[2] = puVar2[2];
    *(undefined4 *)(*(int *)(local_18 + 0xa0) + 0xc + local_14 * 0x20) =
         *(undefined4 *)((int)local_1c + local_14 * 0xc);
    *(undefined4 *)(*(int *)(local_18 + 0xa0) + 0x10 + local_14 * 0x20) =
         *(undefined4 *)((int)local_1c + local_14 * 0xc + 4);
    *(undefined4 *)(*(int *)(local_18 + 0xa0) + 0x14 + local_14 * 0x20) =
         *(undefined4 *)((int)local_1c + local_14 * 0xc + 8);
  }
  local_50 = local_1c;
  FUN_0042d26e(local_1c,0xc);
  ExceptionList = local_10;
  return 0;
}

// ============================================================================
// Address: 0x405ea0 | Symbol: CD3DFileObject::SetMeshGeometry
// ============================================================================
undefined4
CD3DFileObject__SetMeshGeometry
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  int local_24;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004708dc;
  local_10 = ExceptionList;
  uVar3 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x9c) = param_2;
  uVar1 = *(uint *)(in_ECX + 0x9c);
  lVar2 = (ulonglong)uVar1 * 0x20;
  local_24 = FUN_0042d2b4(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2,uVar3);
  local_8 = 0;
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    vector_constructor_iterator(local_24,0x20,uVar1,_D3DVERTEX___D3DVERTEX);
  }
  local_8 = 0xffffffff;
  *(int *)(in_ECX + 0xa0) = local_24;
  if (*(int *)(in_ECX + 0xa0) == 0) {
    uVar4 = 0x80004005;
  }
  else {
    for (local_18 = 0; local_18 < *(uint *)(in_ECX + 0x9c); local_18 = local_18 + 1) {
      _memset((void *)(local_18 * 0x20 + *(int *)(in_ECX + 0xa0)),0,0x20);
      *(undefined4 *)(*(int *)(in_ECX + 0xa0) + local_18 * 0x20) =
           *(undefined4 *)(param_1 + local_18 * 0xc);
      *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 4 + local_18 * 0x20) =
           *(undefined4 *)(param_1 + 4 + local_18 * 0xc);
      *(undefined4 *)(*(int *)(in_ECX + 0xa0) + 8 + local_18 * 0x20) =
           *(undefined4 *)(param_1 + 8 + local_18 * 0xc);
    }
    uVar4 = GetNumIndices(param_3,param_4);
    *(undefined4 *)(in_ECX + 0xa4) = uVar4;
    lVar2 = (ulonglong)*(uint *)(in_ECX + 0xa4) * 2;
    uVar4 = FUN_0042d2b4(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2,uVar3);
    *(undefined4 *)(in_ECX + 0xa8) = uVar4;
    if (*(int *)(in_ECX + 0xa8) == 0) {
      uVar4 = 0x80004005;
    }
    else {
      *(undefined4 *)(in_ECX + 0x98) = 1;
      uVar4 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar4;
}

// ============================================================================
// Address: 0x406080 | Symbol: CD3DFileObject::GetMeshGeometry
// ============================================================================
undefined4
CD3DFileObject__GetMeshGeometry
          (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int in_ECX;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(in_ECX + 0xa0);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(in_ECX + 0x9c);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(in_ECX + 0xa8);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(in_ECX + 0xa4);
  }
  return 0;
}

// ============================================================================
// Address: 0x4060e0 | Symbol: CD3DFileObject::Render
// ============================================================================
void CD3DFileObject__Render(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_d8 [64];
  undefined4 local_98 [16];
  undefined1 local_58 [64];
  int local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  local_8 = in_ECX;
  if (*(int *)(in_ECX + 0x98) == 0) {
    if (*(int *)(in_ECX + 0x54) != 0) {
      _D3DMATRIX___D3DMATRIX();
      _D3DMATRIX___D3DMATRIX();
      (**(code **)(*param_1 + 0x30))(param_1,1,local_58);
      puVar1 = (undefined4 *)FUN_00408060(local_d8,local_8 + 0x58,local_58);
      puVar3 = local_98;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar3 = puVar3 + 1;
      }
      (**(code **)(*param_1 + 0x2c))(param_1,1,local_98);
      CD3DFileObject__Render(param_1,param_2);
      (**(code **)(*param_1 + 0x2c))(param_1,1,local_58);
    }
  }
  else {
    local_10 = *(int *)(in_ECX + 0xa8);
    for (local_c = 0; local_c <= *(uint *)(local_8 + 0xac); local_c = local_c + 1) {
      if (*(int *)(local_8 + 0x144 + local_c * 0x98) != 0) {
        if (param_2 == *(int *)(local_8 + 0xa30)) {
          local_18 = local_8 + 0xf4 + local_c * 0x98;
          local_14 = *(undefined4 *)(local_8 + 0x144 + local_c * 0x98);
          (**(code **)(*param_1 + 0x40))(param_1,local_8 + 0xb0 + local_c * 0x98);
          (**(code **)(*param_1 + 0x68))
                    (param_1,4,0x112,*(undefined4 *)(local_8 + 0xa0),*(undefined4 *)(local_8 + 0x9c)
                     ,local_10,local_14,0);
        }
        local_10 = local_10 + *(int *)(local_8 + 0x144 + local_c * 0x98) * 2;
      }
    }
  }
  if (*(int *)(local_8 + 0x50) != 0) {
    CD3DFileObject__Render(param_1,param_2);
  }
  return;
}

// ============================================================================
// Address: 0x4062b0 | Symbol: CD3DFileObject::EnumObjects
// ============================================================================
undefined4 CD3DFileObject__EnumObjects(code *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 local_88 [64];
  undefined4 local_48 [16];
  int local_8;
  
  iVar1 = (*param_1)();
  if (iVar1 == 1) {
    uVar2 = 1;
  }
  else {
    if (*(int *)(local_8 + 0x54) != 0) {
      puVar3 = param_2;
      puVar4 = local_48;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = (undefined4 *)FUN_00408060(local_88,param_2,local_8 + 0x58);
      puVar4 = param_2;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar1 = CD3DFileObject__EnumObjects(param_1,param_2,param_3);
      if (iVar1 == 1) {
        return 1;
      }
      puVar3 = local_48;
      puVar4 = param_2;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    if ((*(int *)(local_8 + 0x50) != 0) &&
       (iVar1 = CD3DFileObject__EnumObjects(param_1,param_2,param_3), iVar1 == 1)) {
      return 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x406390 | Symbol: CD3DFileObject::CD3DFileObject
// ============================================================================
LPSTR CD3DFileObject__CD3DFileObject(LPCSTR param_1)

{
  LPSTR in_ECX;
  
  _D3DMATRIX___D3DMATRIX();
  in_ECX[0x50] = '\0';
  in_ECX[0x51] = '\0';
  in_ECX[0x52] = '\0';
  in_ECX[0x53] = '\0';
  in_ECX[0x54] = '\0';
  in_ECX[0x55] = '\0';
  in_ECX[0x56] = '\0';
  in_ECX[0x57] = '\0';
  *in_ECX = '\0';
  in_ECX[0x98] = '\0';
  in_ECX[0x99] = '\0';
  in_ECX[0x9a] = '\0';
  in_ECX[0x9b] = '\0';
  if (param_1 != (LPCSTR)0x0) {
    lstrcpyA(in_ECX,param_1);
  }
  D3DUtil_SetIdentityMatrix(in_ECX + 0x58);
  D3DUtil_InitMaterial(in_ECX + 0xb0,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  _memset(in_ECX + 0xb0,0,0x980);
  in_ECX[0xac] = '\0';
  in_ECX[0xad] = '\0';
  in_ECX[0xae] = '\0';
  in_ECX[0xaf] = '\0';
  in_ECX[0xa30] = '\0';
  in_ECX[0xa31] = '\0';
  in_ECX[0xa32] = '\0';
  in_ECX[0xa33] = '\0';
  in_ECX[0x9c] = '\0';
  in_ECX[0x9d] = '\0';
  in_ECX[0x9e] = '\0';
  in_ECX[0x9f] = '\0';
  in_ECX[0xa0] = '\0';
  in_ECX[0xa1] = '\0';
  in_ECX[0xa2] = '\0';
  in_ECX[0xa3] = '\0';
  in_ECX[0xa4] = '\0';
  in_ECX[0xa5] = '\0';
  in_ECX[0xa6] = '\0';
  in_ECX[0xa7] = '\0';
  in_ECX[0xa8] = '\0';
  in_ECX[0xa9] = '\0';
  in_ECX[0xaa] = '\0';
  in_ECX[0xab] = '\0';
  return in_ECX;
}

// ============================================================================
// Address: 0x4064c0 | Symbol: CD3DFileObject::~CD3DFileObject
// ============================================================================
void CD3DFileObject___CD3DFileObject(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    if (*(int *)(in_ECX + 0x54) != 0) {
      CD3DFileObject__(1);
    }
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  if (*(int *)(in_ECX + 0x50) != 0) {
    if (*(int *)(in_ECX + 0x50) != 0) {
      CD3DFileObject__(1);
    }
    *(undefined4 *)(in_ECX + 0x50) = 0;
  }
  if (*(int *)(in_ECX + 0xa0) != 0) {
    FUN_0042d26e(*(undefined4 *)(in_ECX + 0xa0),0x20);
    *(undefined4 *)(in_ECX + 0xa0) = 0;
  }
  if (*(int *)(in_ECX + 0xa8) != 0) {
    FUN_0042d26e(*(undefined4 *)(in_ECX + 0xa8),2);
    *(undefined4 *)(in_ECX + 0xa8) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x4065b0 | Symbol: CD3DFile::GetMeshVertices
// ============================================================================
undefined4 CD3DFile__GetMeshVertices(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = CD3DFile__FindObject(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = CD3DFileObject__GetMeshGeometry(param_2,param_3,0,0);
  }
  return uVar2;
}

// ============================================================================
// Address: 0x4065f0 | Symbol: CD3DFile::GetMeshIndices
// ============================================================================
undefined4 CD3DFile__GetMeshIndices(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = CD3DFile__FindObject(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = CD3DFileObject__GetMeshGeometry(0,0,param_2,param_3);
  }
  return uVar2;
}

// ============================================================================
// Address: 0x406630 | Symbol: CD3DFile::FindObject
// ============================================================================
undefined4 CD3DFile__FindObject(int param_1)

{
  undefined4 *in_ECX;
  int local_10;
  undefined4 local_c;
  
  if (param_1 == 0) {
    local_c = *in_ECX;
  }
  else {
    local_10 = param_1;
    local_c = 0;
    CD3DFile__EnumObjects(FindMeshCB,0,&local_10);
  }
  return local_c;
}

// ============================================================================
// Address: 0x406670 | Symbol: CD3DFile::EnumObjects
// ============================================================================
void CD3DFile__EnumObjects(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  if (*in_ECX != 0) {
    _D3DMATRIX___D3DMATRIX();
    if (param_2 == (undefined4 *)0x0) {
      D3DUtil_SetIdentityMatrix(local_48);
    }
    else {
      puVar2 = local_48;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
    }
    CD3DFileObject__EnumObjects(param_1,local_48,param_3);
  }
  return;
}

// ============================================================================
// Address: 0x4066d0 | Symbol: CD3DFile::Scale
// ============================================================================
void CD3DFile__Scale(void)

{
  CD3DFile__EnumObjects(ScaleMeshCB,0,&stack0x00000004);
  return;
}

// ============================================================================
// Address: 0x4066f0 | Symbol: CD3DFile::Shift
// ============================================================================
void CD3DFile__Shift(void)

{
  CD3DFile__EnumObjects(ShiftMeshCB,0,&stack0x00000004);
  return;
}

// ============================================================================
// Address: 0x406710 | Symbol: CD3DFile::RotateX
// ============================================================================
void CD3DFile__RotateX(void)

{
  CD3DFile__EnumObjects(RotateXMeshCB,0,&stack0x00000004);
  return;
}

// ============================================================================
// Address: 0x406730 | Symbol: CD3DFile::RotateY
// ============================================================================
void CD3DFile__RotateY(void)

{
  CD3DFile__EnumObjects(RotateYMeshCB,0,&stack0x00000004);
  return;
}

// ============================================================================
// Address: 0x406750 | Symbol: CD3DFile::RotateZ
// ============================================================================
void CD3DFile__RotateZ(void)

{
  CD3DFile__EnumObjects(RotateZMeshCB,0,&stack0x00000004);
  return;
}

// ============================================================================
// Address: 0x406770 | Symbol: CD3DFile::GetBoxMin
// ============================================================================
void CD3DFile__GetBoxMin(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(0x7f7fffff,0x7f7fffff,0x7f7fffff);
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  CD3DFile__EnumObjects(GetBoxMinMeshCB,0,param_1);
  return;
}

// ============================================================================
// Address: 0x4067e0 | Symbol: CD3DFile::GetBoxMax
// ============================================================================
void CD3DFile__GetBoxMax(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(0x800000,0x800000,0x800000);
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  CD3DFile__EnumObjects(GetBoxMaxMeshCB,0,param_1);
  return;
}

// ============================================================================
// Address: 0x406850 | Symbol: CD3DFile::LoadFromFile
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CD3DFile__LoadFromFile(LPCSTR param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  LPCSTR lpString2;
  int *in_ECX;
  undefined4 uVar4;
  undefined4 local_238;
  int local_234;
  int local_230;
  int local_22c;
  int *local_228;
  int *local_224;
  int local_220;
  int *local_21c;
  int *local_218;
  CHAR local_214;
  undefined1 local_213 [511];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470913;
  local_10 = ExceptionList;
  uVar2 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = 0;
  local_21c = in_ECX;
  local_14 = uVar2;
  if (*in_ECX != 0) {
    local_22c = *in_ECX;
    if (local_22c != 0) {
      CD3DFileObject__(1);
    }
    *local_21c = 0;
  }
  iVar3 = DirectXFileCreate(&local_218,uVar2,uVar4);
  if (iVar3 < 0) {
    local_220 = -0x7fffbffb;
  }
  else {
    iVar3 = (**(code **)(*local_218 + 0x14))(local_218,&DAT_00486008,0xcce);
    if (iVar3 < 0) {
      (**(code **)(*local_218 + 8))(local_218);
      local_220 = -0x7fffbffb;
    }
    else {
      local_220 = (**(code **)(*local_218 + 0xc))(local_218,param_1,0,&local_228);
      if (local_220 < 0) {
        local_214 = '\0';
        _memset(local_213,0,0x1ff);
        lpString2 = (LPCSTR)D3DUtil_GetDXSDKMediaPath();
        lstrcatA(&local_214,lpString2);
        lstrcatA(&local_214,param_1);
        local_220 = (**(code **)(*local_218 + 0xc))(local_218,&local_214,0,&local_228);
        if (local_220 < 0) {
          (**(code **)(*local_218 + 8))(local_218);
          ExceptionList = local_10;
          return local_220;
        }
      }
      local_230 = FUN_0042d23e(0xa34);
      local_8 = 0;
      if (local_230 == 0) {
        local_234 = 0;
      }
      else {
        local_234 = CD3DFileObject__CD3DFileObject("D3DFile_Root");
      }
      local_8 = 0xffffffff;
      *local_21c = local_234;
      while (local_220 = (**(code **)(*local_228 + 0xc))(local_228,&local_224), -1 < local_220) {
        (**(code **)(*local_224 + 0x18))(local_224,&local_238);
        cVar1 = __(local_238,&DAT_00475638);
        if (cVar1 != '\0') {
          ParseFrame(local_224,*local_21c);
        }
        cVar1 = __(local_238,&DAT_00475688);
        if (cVar1 != '\0') {
          ParseMesh(local_224,*local_21c);
        }
        (**(code **)(*local_224 + 8))(local_224);
      }
      if (local_220 == -0x7789fc99) {
        local_220 = 0;
      }
      else if (*local_21c != 0) {
        if (*local_21c != 0) {
          CD3DFileObject__(1);
        }
        *local_21c = 0;
      }
      (**(code **)(*local_228 + 8))(local_228);
      (**(code **)(*local_218 + 8))(local_218);
    }
  }
  ExceptionList = local_10;
  return local_220;
}

// ============================================================================
// Address: 0x406be0 | Symbol: CD3DFile::LoadFromResource
// ============================================================================
int CD3DFile__LoadFromResource(ushort param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470954;
  local_10 = ExceptionList;
  uVar2 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48 = 0;
  local_18 = in_ECX;
  if (*in_ECX != 0) {
    local_28 = *in_ECX;
    if (local_28 == 0) {
      local_3c = 0;
    }
    else {
      local_3c = CD3DFileObject__(1);
    }
    *local_18 = 0;
  }
  iVar3 = DirectXFileCreate(&local_14,uVar2);
  if (iVar3 < 0) {
    local_1c = -0x7fffbffb;
  }
  else {
    iVar3 = (**(code **)(*local_14 + 0x14))(local_14,&DAT_00486008,0xcce);
    if (iVar3 < 0) {
      (**(code **)(*local_14 + 8))(local_14);
      local_1c = -0x7fffbffb;
    }
    else {
      local_54 = 0;
      local_50 = (uint)param_1;
      local_4c = 10;
      local_1c = (**(code **)(*local_14 + 0xc))(local_14,&local_54,1,&local_24);
      if (local_1c < 0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
      else {
        local_2c = FUN_0042d23e(0xa34);
        local_8 = 0;
        if (local_2c == 0) {
          local_30 = 0;
        }
        else {
          local_30 = CD3DFileObject__CD3DFileObject("D3DFile_Root");
        }
        local_40 = local_30;
        local_8 = 0xffffffff;
        *local_18 = local_30;
        while( true ) {
          local_1c = (**(code **)(*local_24 + 0xc))(local_24,&local_20);
          if (local_1c < 0) break;
          (**(code **)(*local_20 + 0x18))(local_20,&local_34);
          cVar1 = __(local_34,&DAT_00475638);
          if (cVar1 != '\0') {
            ParseFrame(local_20,*local_18);
          }
          cVar1 = __(local_34,&DAT_00475688);
          if (cVar1 != '\0') {
            ParseMesh(local_20,*local_18);
          }
          (**(code **)(*local_20 + 8))(local_20);
        }
        if (local_1c == -0x7789fc99) {
          local_1c = 0;
        }
        else if (*local_18 != 0) {
          local_38 = *local_18;
          if (local_38 == 0) {
            local_44 = 0;
          }
          else {
            local_44 = CD3DFileObject__(1);
          }
          *local_18 = 0;
        }
        (**(code **)(*local_24 + 8))(local_24);
        (**(code **)(*local_14 + 8))(local_14);
      }
    }
  }
  ExceptionList = local_10;
  return local_1c;
}

// ============================================================================
// Address: 0x406e40 | Symbol: CD3DFile::Render
// ============================================================================
undefined4 CD3DFile__Render(int *param_1)

{
  undefined1 local_9c [68];
  undefined1 local_58 [64];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int *local_c;
  int *local_8;
  
  _D3DMATRIX___D3DMATRIX();
  if (*local_c != 0) {
    (**(code **)(*param_1 + 0x44))(param_1,local_9c);
    (**(code **)(*param_1 + 0x88))(param_1,0,&local_8);
    (**(code **)(*param_1 + 0x30))(param_1,1,local_58);
    (**(code **)(*param_1 + 0x54))(param_1,0x1b,&local_10);
    (**(code **)(*param_1 + 0x54))(param_1,0x13,&local_14);
    (**(code **)(*param_1 + 0x54))(param_1,0x14,&local_18);
    CD3DFileObject__Render(param_1,0);
    (**(code **)(*param_1 + 0x50))(param_1,0x1b,1);
    (**(code **)(*param_1 + 0x50))(param_1,0x13,5);
    (**(code **)(*param_1 + 0x50))(param_1,0x14,6);
    CD3DFileObject__Render(param_1,1);
    (**(code **)(*param_1 + 0x50))(param_1,0x1b,local_10);
    (**(code **)(*param_1 + 0x50))(param_1,0x13,local_14);
    (**(code **)(*param_1 + 0x50))(param_1,0x14,local_18);
    (**(code **)(*param_1 + 0x2c))(param_1,1,local_58);
    (**(code **)(*param_1 + 0x8c))(param_1,0,local_8);
    (**(code **)(*param_1 + 0x40))(param_1,local_9c);
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x406fd0 | Symbol: CD3DFile::CD3DFile
// ============================================================================
undefined4 * CD3DFile__CD3DFile(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  return in_ECX;
}

// ============================================================================
// Address: 0x406ff0 | Symbol: CD3DFile::~CD3DFile
// ============================================================================
void CD3DFile___CD3DFile(void)

{
  int *in_ECX;
  
  if (*in_ECX != 0) {
    if (*in_ECX != 0) {
      CD3DFileObject__(1);
    }
    *in_ECX = 0;
  }
  return;
}

// ============================================================================
// Address: 0x407040 | Symbol: GetFace
// ============================================================================
int * GetFace(int *param_1,uint param_2)

{
  uint local_8;
  
  for (local_8 = 0; local_8 < param_2; local_8 = local_8 + 1) {
    param_1 = param_1 + *param_1 + 1;
  }
  return param_1;
}

// ============================================================================
// Address: 0x407080 | Symbol: GetNumIndices
// ============================================================================
int GetNumIndices(int *param_1,int param_2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (param_2 == 0) break;
    local_8 = (*param_1 + -2) * 3 + local_8;
    param_1 = param_1 + *param_1 + 1;
    param_2 = param_2 + -1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x4070d0 | Symbol: ParseMaterial
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x004071bc) */

undefined4 ParseMaterial(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined1 local_e8 [16];
  undefined1 local_d8 [16];
  undefined1 local_c8 [16];
  undefined1 local_b8 [16];
  undefined1 local_a8 [4];
  undefined4 *local_a4;
  undefined1 local_a0 [4];
  undefined4 local_9c;
  undefined4 local_98;
  int *local_94;
  int local_90;
  int *local_8c;
  CHAR local_88 [128];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1,0,local_a0,&local_90);
  if (-1 < iVar2) {
    _memset(local_e8,0,0x44);
    FUN_004307f0(local_e8,local_90,0x10);
    FUN_004307f0(local_d8,local_90,0x10);
    FUN_004307f0(local_a8,local_90 + 0x10,4);
    FUN_004307f0(local_c8,local_90 + 0x14,0xc);
    FUN_004307f0(local_b8,local_90 + 0x20,0xc);
    local_98 = 0;
    local_88[0] = '\0';
    iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_94);
    if (-1 < iVar2) {
      iVar2 = (**(code **)*local_94)(local_94,&DAT_00475308,&local_8c);
      if (-1 < iVar2) {
        (**(code **)(*local_8c + 0x18))(local_8c,&local_9c);
        cVar1 = __(&DAT_00475508,local_9c);
        if (cVar1 != '\0') {
          iVar2 = (**(code **)(*local_8c + 0x14))(local_8c,0,local_a0,&local_a4);
          if (iVar2 < 0) {
            return 0;
          }
          lstrcpynA(local_88,(LPCSTR)*local_a4,0x80);
        }
        (**(code **)(*local_8c + 8))(local_8c);
      }
      (**(code **)(*local_94 + 8))(local_94);
    }
    CD3DFileObject__SetMaterialData(param_3,local_e8,local_88);
  }
  return 0;
}

// ============================================================================
// Address: 0x4072f0 | Symbol: ParseMeshMaterialList
// ============================================================================
undefined4 ParseMeshMaterialList(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int *local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  local_c = 0;
  while( true ) {
    iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_10);
    if (iVar2 < 0) break;
    iVar2 = (**(code **)*local_10)(local_10,&DAT_00475308,&local_8);
    if (-1 < iVar2) {
      (**(code **)(*local_8 + 0x18))(local_8,&local_18);
      cVar1 = __(&DAT_00475658,local_18);
      if (cVar1 != '\0') {
        local_1c = local_c;
        ParseMaterial(local_8,param_2,local_c);
        local_c = local_c + 1;
      }
      (**(code **)(*local_8 + 8))(local_8);
    }
    iVar2 = (**(code **)*local_10)(local_10,&DAT_004752f8,&local_14);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_14 + 0x14))(local_14,&local_8);
      if (-1 < iVar2) {
        (**(code **)(*local_8 + 0x18))(local_8,&local_20);
        cVar1 = __(&DAT_00475658,local_20);
        if (cVar1 != '\0') {
          ParseMaterial(local_8,param_2,local_c);
          local_c = local_c + 1;
        }
        (**(code **)(*local_8 + 8))(local_8);
      }
      (**(code **)(*local_14 + 8))(local_14);
    }
    (**(code **)(*local_10 + 8))(local_10);
  }
  return 0;
}

// ============================================================================
// Address: 0x407440 | Symbol: ParseMesh
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 ParseMesh(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_d8 [4];
  undefined1 local_d4 [4];
  uint *local_d0;
  uint local_cc;
  uint *local_c8;
  uint local_c4;
  uint *local_c0;
  uint *local_b8;
  int local_b4;
  undefined4 local_b0;
  int local_ac;
  int local_a8;
  uint local_a4;
  uint local_a0;
  int local_9c;
  int local_98;
  int local_94;
  undefined4 local_90;
  uint *local_8c;
  uint local_88;
  int *local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  int *local_74;
  int local_70;
  uint *local_6c;
  uint *local_68;
  undefined1 local_64 [80];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047098b;
  local_10 = ExceptionList;
  local_14 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_b0 = 0x50;
  iVar2 = (**(code **)(*param_1 + 0xc))(param_1,local_64,&local_b0,local_14);
  if (iVar2 < 0) {
    uVar3 = 0x80004005;
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1,0,local_d4,&local_6c);
    if (iVar2 < 0) {
      uVar3 = 0x80004005;
    }
    else {
      local_80 = *local_6c;
      local_b8 = local_6c + 1;
      local_88 = local_b8[local_80 * 3];
      local_8c = local_b8 + local_80 * 3 + 1;
      local_6c = local_8c;
      local_94 = FUN_0042d23e(0xa34);
      local_8 = 0;
      if (local_94 == 0) {
        local_98 = 0;
      }
      else {
        local_98 = CD3DFileObject__CD3DFileObject(local_64);
      }
      local_b4 = local_98;
      local_8 = 0xffffffff;
      local_70 = local_98;
      CD3DFileObject__SetMeshGeometry(local_b8,local_80,local_8c,local_88);
      local_ac = 0;
      local_a8 = 0;
      while (iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_84), -1 < iVar2) {
        iVar2 = (**(code **)*local_84)(local_84,&DAT_00475308,&local_74);
        if (-1 < iVar2) {
          (**(code **)(*local_74 + 0x18))(local_74,&local_90);
          iVar2 = (**(code **)(*local_74 + 0x14))(local_74,0,local_d8,&local_68);
          if (iVar2 < 0) {
            local_9c = local_70;
            if (local_70 != 0) {
              CD3DFileObject__(1);
            }
            ExceptionList = local_10;
            return 0;
          }
          cVar1 = __(&DAT_00475618,local_90);
          if (cVar1 != '\0') {
            local_a0 = *local_68;
            local_a4 = local_68[1];
            local_c0 = local_68 + 2;
            local_68 = local_c0;
            if ((local_a0 == 1) || (local_a4 != local_88)) {
              CD3DFileObject__AddFace(0,local_8c,local_88);
            }
            else {
              for (local_7c = 0; local_7c < local_a0; local_7c = local_7c + 1) {
                for (local_78 = 0; local_78 < local_a4; local_78 = local_78 + 1) {
                  if (local_c0[local_78] == local_7c) {
                    uVar4 = 1;
                    uVar3 = GetFace(local_8c,local_78,1);
                    CD3DFileObject__AddFace(local_7c,uVar3,uVar4);
                  }
                }
              }
            }
            ParseMeshMaterialList(local_74,local_70);
            local_a8 = 1;
          }
          cVar1 = __(&DAT_004755f8,local_90);
          if (cVar1 != '\0') {
            local_c4 = *local_68;
            local_c8 = local_68 + 1;
            if (local_c4 == local_80) {
              CD3DFileObject__SetNormals(local_c8);
              local_ac = 1;
            }
          }
          cVar1 = __(&DAT_00475608,local_90);
          if (cVar1 != '\0') {
            local_cc = *local_68;
            local_d0 = local_68 + 1;
            if (local_cc == local_80) {
              CD3DFileObject__SetTextureCoords(local_d0);
            }
          }
          (**(code **)(*local_74 + 8))(local_74);
        }
        (**(code **)(*local_84 + 8))(local_84);
      }
      if (local_a8 == 0) {
        CD3DFileObject__AddFace(0,local_8c,local_88);
      }
      if (local_ac == 0) {
        CD3DFileObject__ComputeNormals();
      }
      CD3DFileObject__AddChild(local_70);
      uVar3 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

// ============================================================================
// Address: 0x407870 | Symbol: ParseFrame
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 ParseFrame(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_98;
  int local_94 [2];
  int local_8c;
  undefined4 local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  int *local_74;
  int local_70;
  int *local_6c;
  int local_68;
  undefined1 local_64 [80];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004709cc;
  local_10 = ExceptionList;
  local_14 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_88 = 0x50;
  iVar2 = (**(code **)(*param_1 + 0xc))(param_1,local_64,&local_88,local_14);
  if (iVar2 < 0) {
    uVar3 = 0x80004005;
  }
  else {
    local_7c = FUN_0042d23e(0xa34);
    local_8 = 0;
    if (local_7c == 0) {
      local_80 = 0;
    }
    else {
      local_80 = CD3DFileObject__CD3DFileObject(local_64);
    }
    local_8c = local_80;
    local_8 = 0xffffffff;
    local_70 = local_80;
    while (iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_74), -1 < iVar2) {
      iVar2 = (**(code **)*local_74)(local_74,&DAT_00475308,&local_6c);
      if (-1 < iVar2) {
        (**(code **)(*local_6c + 0x18))(local_6c,&local_78);
        cVar1 = __(&DAT_00475638,local_78);
        if (cVar1 != '\0') {
          ParseFrame(local_6c,local_70);
        }
        cVar1 = __(&DAT_00475688,local_78);
        if (cVar1 != '\0') {
          ParseMesh(local_6c,local_70);
        }
        cVar1 = __(&DAT_00475628,local_78);
        if (cVar1 != '\0') {
          iVar2 = (**(code **)(*local_6c + 0x14))(local_6c,0,local_94,&local_98);
          if (iVar2 < 0) {
            local_84 = local_70;
            if (local_70 != 0) {
              CD3DFileObject__(1);
            }
            ExceptionList = local_10;
            return 0;
          }
          if (local_94[0] == 0x40) {
            local_68 = local_98;
            *(float *)(local_98 + 8) = *(float *)(local_98 + 8) * -1.0;
            *(float *)(local_98 + 0x20) = *(float *)(local_98 + 0x20) * -1.0;
            *(float *)(local_98 + 0x18) = *(float *)(local_98 + 0x18) * -1.0;
            *(float *)(local_98 + 0x24) = *(float *)(local_98 + 0x24) * -1.0;
            *(float *)(local_98 + 0x38) = *(float *)(local_98 + 0x38) * -1.0;
            CD3DFileObject__SetMatrix(local_98);
          }
        }
        (**(code **)(*local_6c + 8))(local_6c);
      }
      (**(code **)(*local_74 + 8))(local_74);
    }
    CD3DFileObject__AddChild(local_70);
    uVar3 = 0;
  }
  ExceptionList = local_10;
  return uVar3;
}

// ============================================================================
// Address: 0x407b10 | Symbol: ScaleMeshCB
// ============================================================================
undefined4 ScaleMeshCB(undefined4 param_1,undefined4 param_2,float *param_3)

{
  int iVar1;
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar1 = CD3DFileObject__GetMeshGeometry(&local_c,&local_10,0,0);
  if (-1 < iVar1) {
    for (local_8 = 0; local_8 < local_10; local_8 = local_8 + 1) {
      *(float *)(local_c + local_8 * 0x20) = *(float *)(local_c + local_8 * 0x20) * *param_3;
      *(float *)(local_c + 4 + local_8 * 0x20) = *(float *)(local_c + 4 + local_8 * 0x20) * *param_3
      ;
      *(float *)(local_c + 8 + local_8 * 0x20) = *(float *)(local_c + 8 + local_8 * 0x20) * *param_3
      ;
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x407bd0 | Symbol: ShiftMeshCB
// ============================================================================
undefined4 ShiftMeshCB(undefined4 param_1,undefined4 param_2,float *param_3)

{
  int iVar1;
  uint local_14 [2];
  int local_c;
  uint local_8;
  
  iVar1 = CD3DFileObject__GetMeshGeometry(&local_c,local_14,0,0);
  if (-1 < iVar1) {
    for (local_8 = 0; local_8 < local_14[0]; local_8 = local_8 + 1) {
      *(float *)(local_c + local_8 * 0x20) = *(float *)(local_c + local_8 * 0x20) + *param_3;
      *(float *)(local_c + 4 + local_8 * 0x20) =
           *(float *)(local_c + 4 + local_8 * 0x20) + param_3[1];
      *(float *)(local_c + 8 + local_8 * 0x20) =
           *(float *)(local_c + 8 + local_8 * 0x20) + param_3[2];
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x407c90 | Symbol: RotateXMeshCB
// ============================================================================
undefined4 RotateXMeshCB(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_70 [64];
  undefined4 local_30 [8];
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar1 = CD3DFileObject__GetMeshGeometry(&local_c,&local_10,0,0);
  if (-1 < iVar1) {
    _D3DMATRIX___D3DMATRIX();
    D3DUtil_SetRotateXMatrix(local_70,*param_3);
    _D3DVERTEX___D3DVERTEX();
    for (local_8 = 0; local_8 < local_10; local_8 = local_8 + 1) {
      D3DMath_VertexMatrixMultiply(local_30,local_8 * 0x20 + local_c,local_70);
      puVar2 = local_30;
      puVar3 = (undefined4 *)(local_8 * 0x20 + local_c);
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x407d30 | Symbol: RotateYMeshCB
// ============================================================================
undefined4 RotateYMeshCB(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_70 [64];
  undefined4 local_30 [8];
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar1 = CD3DFileObject__GetMeshGeometry(&local_c,&local_10,0,0);
  if (-1 < iVar1) {
    _D3DMATRIX___D3DMATRIX();
    D3DUtil_SetRotateYMatrix(local_70,*param_3);
    _D3DVERTEX___D3DVERTEX();
    for (local_8 = 0; local_8 < local_10; local_8 = local_8 + 1) {
      D3DMath_VertexMatrixMultiply(local_30,local_8 * 0x20 + local_c,local_70);
      puVar2 = local_30;
      puVar3 = (undefined4 *)(local_8 * 0x20 + local_c);
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x407dd0 | Symbol: RotateZMeshCB
// ============================================================================
undefined4 RotateZMeshCB(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_70 [64];
  undefined4 local_30 [8];
  uint local_10;
  int local_c;
  uint local_8;
  
  iVar1 = CD3DFileObject__GetMeshGeometry(&local_c,&local_10,0,0);
  if (-1 < iVar1) {
    _D3DMATRIX___D3DMATRIX();
    D3DUtil_SetRotateZMatrix(local_70,*param_3);
    _D3DVERTEX___D3DVERTEX();
    for (local_8 = 0; local_8 < local_10; local_8 = local_8 + 1) {
      D3DMath_VertexMatrixMultiply(local_30,local_8 * 0x20 + local_c,local_70);
      puVar2 = local_30;
      puVar3 = (undefined4 *)(local_8 * 0x20 + local_c);
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x407e70 | Symbol: GetBoxMinMeshCB
// ============================================================================
undefined4 GetBoxMinMeshCB(undefined4 param_1,undefined4 param_2,float *param_3)

{
  float *pfVar1;
  int iVar2;
  uint local_14;
  int local_10 [2];
  uint local_8;
  
  iVar2 = CD3DFileObject__GetMeshGeometry(local_10,&local_14,0,0);
  if (-1 < iVar2) {
    for (local_8 = 0; local_8 < local_14; local_8 = local_8 + 1) {
      pfVar1 = (float *)(local_10[0] + local_8 * 0x20);
      if (*pfVar1 <= *param_3 && *param_3 != *pfVar1) {
        *param_3 = *(float *)(local_10[0] + local_8 * 0x20);
      }
      pfVar1 = (float *)(local_10[0] + 4 + local_8 * 0x20);
      if (*pfVar1 <= param_3[1] && param_3[1] != *pfVar1) {
        param_3[1] = *(float *)(local_10[0] + 4 + local_8 * 0x20);
      }
      pfVar1 = (float *)(local_10[0] + 8 + local_8 * 0x20);
      if (*pfVar1 <= param_3[2] && param_3[2] != *pfVar1) {
        param_3[2] = *(float *)(local_10[0] + 8 + local_8 * 0x20);
      }
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x407f40 | Symbol: GetBoxMaxMeshCB
// ============================================================================
undefined4 GetBoxMaxMeshCB(undefined4 param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  uint local_14;
  int local_10 [2];
  uint local_8;
  
  iVar2 = CD3DFileObject__GetMeshGeometry(local_10,&local_14,0,0);
  if (-1 < iVar2) {
    for (local_8 = 0; local_8 < local_14; local_8 = local_8 + 1) {
      fVar1 = *(float *)(local_10[0] + local_8 * 0x20);
      if (*param_3 <= fVar1 && fVar1 != *param_3) {
        *param_3 = *(float *)(local_10[0] + local_8 * 0x20);
      }
      fVar1 = *(float *)(local_10[0] + 4 + local_8 * 0x20);
      if (param_3[1] <= fVar1 && fVar1 != param_3[1]) {
        param_3[1] = *(float *)(local_10[0] + 4 + local_8 * 0x20);
      }
      fVar1 = *(float *)(local_10[0] + 8 + local_8 * 0x20);
      if (param_3[2] <= fVar1 && fVar1 != param_3[2]) {
        param_3[2] = *(float *)(local_10[0] + 8 + local_8 * 0x20);
      }
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x408010 | Symbol: FindMeshCB
// ============================================================================
bool FindMeshCB(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  LPCSTR lpString2;
  int iVar1;
  
  lpString2 = (LPCSTR)CD3DFileObject__GetName();
  iVar1 = lstrcmpiA((LPCSTR)*param_3,lpString2);
  if (iVar1 == 0) {
    param_3[1] = param_1;
  }
  return iVar1 == 0;
}

// ============================================================================
// Address: 0x408050 | Symbol: _D3DVERTEX::_D3DVERTEX
// ============================================================================
undefined4 _D3DVERTEX___D3DVERTEX(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}

// ============================================================================
// Address: 0x408060 | Symbol: FUN_00408060
// ============================================================================
undefined4 * FUN_00408060(undefined4 *param_1)

{
  undefined4 *puVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_54 [16];
  float *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  _D3DMATRIX___D3DMATRIX();
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      puVar1 = (undefined4 *)_D3DMATRIX__operator__(local_8,local_c);
      *puVar1 = 0;
      for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
        local_14 = (float *)_D3DMATRIX__operator__(local_8,local_c);
        pfVar2 = (float *)FUN_00408170(local_8,local_10);
        pfVar3 = (float *)FUN_00408170(local_10,local_c);
        *local_14 = *pfVar2 * *pfVar3 + *local_14;
      }
    }
  }
  puVar1 = local_54;
  puVar5 = param_1;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar5 = puVar5 + 1;
  }
  return param_1;
}

// ============================================================================
// Address: 0x408150 | Symbol: _D3DMATRIX::operator()
// ============================================================================
int _D3DMATRIX__operator__(int param_1,int param_2)

{
  int in_ECX;
  
  return param_1 * 0x10 + in_ECX + param_2 * 4;
}

// ============================================================================
// Address: 0x408170 | Symbol: FUN_00408170
// ============================================================================
int FUN_00408170(int param_1,int param_2)

{
  int in_ECX;
  
  return param_1 * 0x10 + in_ECX + param_2 * 4;
}

// ============================================================================
// Address: 0x408190 | Symbol: _D3DVECTOR::operator+=
// ============================================================================
float * _D3DVECTOR__operator__(float *param_1)

{
  float *in_ECX;
  
  *in_ECX = *in_ECX + *param_1;
  in_ECX[1] = in_ECX[1] + param_1[1];
  in_ECX[2] = in_ECX[2] + param_1[2];
  return in_ECX;
}

// ============================================================================
// Address: 0x4081f0 | Symbol: CD3DFileObject::
// ============================================================================
undefined4 CD3DFileObject__(uint param_1)

{
  undefined4 in_ECX;
  
  CD3DFileObject___CD3DFileObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0xa34);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x408230 | Symbol: vector_constructor_iterator
// ============================================================================
void vector_constructor_iterator(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  while( true ) {
    if (param_3 == 0) break;
    (*param_4)();
    param_3 = param_3 + -1;
  }
  return;
}

// ============================================================================
// Address: 0x408260 | Symbol: D3DUtil_SetIdentityMatrix
// ============================================================================
void D3DUtil_SetIdentityMatrix(undefined4 *param_1)

{
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0xf] = 0x3f800000;
  param_1[10] = 0x3f800000;
  param_1[5] = 0x3f800000;
  *param_1 = 0x3f800000;
  return;
}

// ============================================================================
// Address: 0x408330 | Symbol: CD3DFileObject::GetName
// ============================================================================
undefined4 CD3DFileObject__GetName(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}

// ============================================================================
// Address: 0x408340 | Symbol: CD3DFileObject::SetMatrix
// ============================================================================
void CD3DFileObject__SetMatrix(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x58);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}
