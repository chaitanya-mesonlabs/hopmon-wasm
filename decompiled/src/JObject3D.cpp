// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JObject3D.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JObject3D.h"

// ============================================================================
// Address: 0x40f3b0 | Symbol: JObject3DList::JObject3DList
// ============================================================================
undefined4 * JObject3DList__JObject3DList(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470c24;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JObject3DList::vftable;
  iVar2 = FUN_0042d23e(0xc,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JBaseList__JBaseList();
  }
  in_ECX[1] = local_1c;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x40f440 | Symbol: JObject3DList::~JObject3DList
// ============================================================================
void JObject3DList___JObject3DList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00470c41;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JObject3DList::vftable;
  JObject3DList__Empty(uVar1);
  if (in_ECX[1] != 0) {
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[1])(1);
    }
    in_ECX[1] = 0;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40f4d0 | Symbol: JObject3DList::Append
// ============================================================================
void JObject3DList__Append(undefined4 param_1)

{
  JBaseList__Append(param_1);
  return;
}

// ============================================================================
// Address: 0x40f4f0 | Symbol: JObject3DList::Empty
// ============================================================================
void JObject3DList__Empty(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint local_8;
  
  for (local_8 = 0; uVar1 = JObject3DList__Count(), local_8 < uVar1; local_8 = local_8 + 1) {
    puVar2 = (undefined4 *)JBaseList__GetData(local_8);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  JBaseList__Empty();
  return;
}

// ============================================================================
// Address: 0x40f570 | Symbol: JObject3DList::Remove
// ============================================================================
void JObject3DList__Remove(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)JBaseList__GetData(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  JBaseList__Remove(param_1);
  return;
}

// ============================================================================
// Address: 0x40f5d0 | Symbol: JObject3DList::Count
// ============================================================================
void JObject3DList__Count(void)

{
  JBaseList__Count();
  return;
}

// ============================================================================
// Address: 0x40f5f0 | Symbol: JObject3DList::GetAt
// ============================================================================
void JObject3DList__GetAt(undefined4 param_1)

{
  JBaseList__GetData(param_1);
  return;
}

// ============================================================================
// Address: 0x40f610 | Symbol: JObject3DList::Render
// ============================================================================
void JObject3DList__Render(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 local_8;
  
  local_8 = 0;
  while( true ) {
    uVar1 = JObject3DList__Count();
    if (uVar1 <= local_8) break;
    piVar2 = (int *)JBaseList__GetData(local_8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    local_8 = local_8 + 1;
  }
  return;
}

// ============================================================================
// Address: 0x40f670 | Symbol: JObject3DBase::JObject3DBase
// ============================================================================
undefined4 * JObject3DBase__JObject3DBase(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = JObject3DBase::vftable;
  in_ECX[1] = param_1;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0x3f800000;
  return in_ECX;
}

// ============================================================================
// Address: 0x40f700 | Symbol: JObject3DBase::~JObject3DBase
// ============================================================================
void JObject3DBase___JObject3DBase(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JObject3DBase::vftable;
  return;
}

// ============================================================================
// Address: 0x40f720 | Symbol: JObject3DBase::SetWorldPos
// ============================================================================
void JObject3DBase__SetWorldPos(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_1[1];
  *(undefined4 *)(in_ECX + 0x10) = param_1[2];
  return;
}

// ============================================================================
// Address: 0x40f750 | Symbol: FUN_0040f750
// ============================================================================
void FUN_0040f750(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (param_1 == 0) {
    *(undefined4 *)(in_ECX + 8) = param_2;
  }
  else if (param_1 == 1) {
    *(undefined4 *)(in_ECX + 0xc) = param_2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x10) = param_2;
  }
  return;
}

// ============================================================================
// Address: 0x40f7a0 | Symbol: JObject3DBase::ShiftWorldPos
// ============================================================================
void JObject3DBase__ShiftWorldPos(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined1 local_14 [12];
  int local_8;
  
  local_8 = in_ECX;
  puVar1 = (undefined4 *)FUN_00404050(local_14,in_ECX + 8,param_1);
  *(undefined4 *)(local_8 + 8) = *puVar1;
  *(undefined4 *)(local_8 + 0xc) = puVar1[1];
  *(undefined4 *)(local_8 + 0x10) = puVar1[2];
  return;
}

// ============================================================================
// Address: 0x40f7e0 | Symbol: FUN_0040f7e0
// ============================================================================
void FUN_0040f7e0(int param_1,float param_2)

{
  int in_ECX;
  
  if (param_1 == 0) {
    *(float *)(in_ECX + 8) = *(float *)(in_ECX + 8) + param_2;
  }
  else if (param_1 == 1) {
    *(float *)(in_ECX + 0xc) = *(float *)(in_ECX + 0xc) + param_2;
  }
  else {
    *(float *)(in_ECX + 0x10) = *(float *)(in_ECX + 0x10) + param_2;
  }
  return;
}

// ============================================================================
// Address: 0x40f840 | Symbol: JObject3DBase::ShiftWorldPos_OnGround
// ============================================================================
void JObject3DBase__ShiftWorldPos_OnGround(void)

{
  undefined1 local_20 [12];
  undefined1 local_14 [4];
  uint local_10;
  int *local_8;
  
  FUN_00403f60();
  FUN_00403f60();
  (**(code **)(*local_8 + 0x10))(local_14,local_20);
  local_8[3] = local_10 ^ 0x80000000;
  return;
}

// ============================================================================
// Address: 0x40f890 | Symbol: JObject3DBase::GetWorldPos
// ============================================================================
undefined4 * JObject3DBase__GetWorldPos(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 8);
  param_1[1] = *(undefined4 *)(in_ECX + 0xc);
  param_1[2] = *(undefined4 *)(in_ECX + 0x10);
  return param_1;
}

// ============================================================================
// Address: 0x40f8c0 | Symbol: JObject3DBase::SetCollisionRadius
// ============================================================================
void JObject3DBase__SetCollisionRadius(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}

// ============================================================================
// Address: 0x40f8e0 | Symbol: JObject3DBase::CheckCollisionRadius
// ============================================================================
bool JObject3DBase__CheckCollisionRadius(int param_1)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)D3DFindDistance(in_ECX + 8,param_1 + 8);
  return (float)fVar1 < *(float *)(in_ECX + 0x14) + *(float *)(param_1 + 0x14);
}

// ============================================================================
// Address: 0x40f940 | Symbol: JObject3DBase::ScaleTo
// ============================================================================
void JObject3DBase__ScaleTo(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 8))(1.0 / (float)in_ECX[9]);
  (**(code **)(*in_ECX + 8))(param_1);
  return;
}

// ============================================================================
// Address: 0x40f9a0 | Symbol: JObject3DBase::RotateTo
// ============================================================================
void JObject3DBase__RotateTo(int param_1,undefined4 param_2)

{
  int *in_ECX;
  uint local_c;
  
  if (param_1 == 0) {
    local_c = in_ECX[6] ^ 0x80000000;
  }
  else if (param_1 == 1) {
    local_c = in_ECX[7] ^ 0x80000000;
  }
  else {
    local_c = in_ECX[8] ^ 0x80000000;
  }
  (**(code **)(*in_ECX + 0xc))(param_1,local_c);
  (**(code **)(*in_ECX + 0xc))(param_1,param_2);
  return;
}

// ============================================================================
// Address: 0x40fa40 | Symbol: JObject3DBase::_SetRenderState
// ============================================================================
void JObject3DBase___SetRenderState(void)

{
  return;
}

// ============================================================================
// Address: 0x40fa50 | Symbol: JObject3DBase::_ResetRenderState
// ============================================================================
void JObject3DBase___ResetRenderState(void)

{
  return;
}

// ============================================================================
// Address: 0x40fa60 | Symbol: JObject3DBase::_SetWorldTransform
// ============================================================================
void JObject3DBase___SetWorldTransform(void)

{
  undefined1 local_4c [64];
  int *local_c;
  int local_8;
  
  _D3DMATRIX___D3DMATRIX();
  FUN_00412100(local_4c,*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0xc),
               *(undefined4 *)(local_8 + 0x10));
  local_c = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*local_c + 0x2c))(local_c,1,local_4c);
  return;
}

// ============================================================================
// Address: 0x40fad0 | Symbol: JObject3DBase::_ResetWorldTransform
// ============================================================================
void JObject3DBase___ResetWorldTransform(void)

{
  undefined1 local_4c [68];
  int *local_8;
  
  _D3DMATRIX___D3DMATRIX();
  D3DUtil_SetIdentityMatrix(local_4c);
  local_8 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*local_8 + 0x2c))(local_8,1,local_4c);
  return;
}

// ============================================================================
// Address: 0x40fb20 | Symbol: JObject3DX::JObject3DX
// ============================================================================
undefined4 * JObject3DX__JObject3DX(undefined4 param_1,short param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_20;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470c7a;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  JObject3DBase__JObject3DBase(param_1);
  local_8 = 0;
  *in_ECX = JObject3DX::vftable;
  in_ECX[10] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
    in_ECX[local_18 + 0xb] = 0;
  }
  if (param_2 != -1) {
    iVar2 = FUN_0042d23e(4,uVar1);
    local_8._0_1_ = 1;
    if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = CD3DFile__CD3DFile();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    in_ECX[0xb] = local_20;
    CD3DFile__LoadFromResource(param_2);
  }
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x40fc40 | Symbol: JObject3DX::~JObject3DX
// ============================================================================
void JObject3DX___JObject3DX(void)

{
  undefined4 *in_ECX;
  int local_8;
  
  *in_ECX = JObject3DX::vftable;
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    if (in_ECX[local_8 + 0xb] != 0) {
      if (in_ECX[local_8 + 0xb] != 0) {
        CD3DFile__(1);
      }
      in_ECX[local_8 + 0xb] = 0;
    }
  }
  JObject3DBase___JObject3DBase();
  return;
}

// ============================================================================
// Address: 0x40fcc0 | Symbol: JObject3DX::Shift
// ============================================================================
void JObject3DX__Shift(undefined4 *param_1)

{
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; (local_8 < 10 && (*(int *)(in_ECX + 0x2c + local_8 * 4) != 0));
      local_8 = local_8 + 1) {
    CD3DFile__Shift(*param_1,param_1[1],param_1[2]);
  }
  return;
}

// ============================================================================
// Address: 0x40fd20 | Symbol: JObject3DX::ScaleBy
// ============================================================================
void JObject3DX__ScaleBy(float param_1)

{
  int in_ECX;
  int local_8;
  
  *(float *)(in_ECX + 0x24) = *(float *)(in_ECX + 0x24) * param_1;
  for (local_8 = 0; (local_8 < 10 && (*(int *)(in_ECX + 0x2c + local_8 * 4) != 0));
      local_8 = local_8 + 1) {
    CD3DFile__Scale(param_1);
  }
  return;
}

// ============================================================================
// Address: 0x40fd90 | Symbol: JObject3DX::RotateBy
// ============================================================================
void JObject3DX__RotateBy(int param_1,float param_2)

{
  int in_ECX;
  int local_14;
  int local_10;
  int local_c;
  
  if (param_1 == 0) {
    *(float *)(in_ECX + 0x18) = *(float *)(in_ECX + 0x18) + param_2;
    for (local_c = 0; (local_c < 10 && (*(int *)(in_ECX + 0x2c + local_c * 4) != 0));
        local_c = local_c + 1) {
      CD3DFile__RotateX(param_2);
    }
  }
  else if (param_1 == 1) {
    *(float *)(in_ECX + 0x1c) = *(float *)(in_ECX + 0x1c) + param_2;
    for (local_10 = 0; (local_10 < 10 && (*(int *)(in_ECX + 0x2c + local_10 * 4) != 0));
        local_10 = local_10 + 1) {
      CD3DFile__RotateY(param_2);
    }
  }
  else {
    *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x20) + param_2;
    for (local_14 = 0; (local_14 < 10 && (*(int *)(in_ECX + 0x2c + local_14 * 4) != 0));
        local_14 = local_14 + 1) {
      CD3DFile__RotateZ(param_2);
    }
  }
  return;
}

// ============================================================================
// Address: 0x40fec0 | Symbol: JObject3DX::GetBox
// ============================================================================
void JObject3DX__GetBox(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2c) == 0) {
    puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(0,0,0);
    *param_1 = *puVar1;
    param_1[1] = puVar1[1];
    param_1[2] = puVar1[2];
    puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(0,0,0);
    *param_2 = *puVar1;
    param_2[1] = puVar1[1];
    param_2[2] = puVar1[2];
  }
  else {
    CD3DFile__GetBoxMin(param_1);
    CD3DFile__GetBoxMax(param_2);
  }
  return;
}

// ============================================================================
// Address: 0x40ff80 | Symbol: JObject3DX::Render
// ============================================================================
void JObject3DX__Render(void)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if (in_ECX[in_ECX[10] + 0xb] != 0) {
    JObject3DBase___SetWorldTransform();
    (**(code **)(*in_ECX + 0x18))();
    uVar1 = CD3DApplication__GetD3DDevice();
    CD3DFile__Render(uVar1);
    (**(code **)(*in_ECX + 0x1c))();
    JObject3DBase___ResetWorldTransform();
  }
  return;
}

// ============================================================================
// Address: 0x40fff0 | Symbol: JObject3DX::AppendExtraFrame
// ============================================================================
void JObject3DX__AppendExtraFrame(undefined2 param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_20;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470cab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  for (local_14 = 0; (local_14 < 10 && (*(int *)(in_ECX + 0x2c + local_14 * 4) != 0));
      local_14 = local_14 + 1) {
  }
  if (local_14 < 10) {
    iVar1 = FUN_0042d23e(4,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (iVar1 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = CD3DFile__CD3DFile();
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x2c + local_14 * 4) = local_20;
    CD3DFile__LoadFromResource(param_1);
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x4100c0 | Symbol: JObject3DX::SetCurrentFrame
// ============================================================================
void JObject3DX__SetCurrentFrame(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  return;
}

// ============================================================================
// Address: 0x4100e0 | Symbol: JObject3DX::SetFlatShade
// ============================================================================
void JObject3DX__SetFlatShade(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x54) = param_1;
  return;
}

// ============================================================================
// Address: 0x410100 | Symbol: JObject3DX::_SetRenderState
// ============================================================================
void JObject3DX___SetRenderState(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_10;
  
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x54))(piVar1,9,in_ECX + 0x58);
  if (*(int *)(in_ECX + 0x54) == 0) {
    local_10 = 2;
  }
  else {
    local_10 = 1;
  }
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x50))(piVar1,9,local_10);
  return;
}

// ============================================================================
// Address: 0x410180 | Symbol: JObject3DX::_ResetRenderState
// ============================================================================
void JObject3DX___ResetRenderState(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x50))(piVar1,9,*(undefined4 *)(in_ECX + 0x58));
  return;
}

// ============================================================================
// Address: 0x4101c0 | Symbol: JObject3D::JObject3D
// ============================================================================
undefined4 * JObject3D__JObject3D(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470cf6;
  local_10 = ExceptionList;
  uVar3 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  JObject3DBase__JObject3DBase(param_1);
  local_8 = 0;
  *in_ECX = JObject3D::vftable;
  in_ECX[10] = param_2;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = param_3;
  in_ECX[0xd] = 0;
  *(undefined2 *)(in_ECX + 0xe) = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  uVar1 = in_ECX[10];
  lVar2 = (ulonglong)uVar1 * 0x20;
  local_20 = FUN_0042d2b4(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2,uVar3);
  local_8._0_1_ = 1;
  if (local_20 == 0) {
    local_20 = 0;
  }
  else {
    vector_constructor_iterator(local_20,0x20,uVar1,_D3DLVERTEX___D3DLVERTEX);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0xb] = local_20;
  _memset((void *)in_ECX[0xb],0,in_ECX[10] << 5);
  uVar4 = FUN_0042d2b4(-(uint)((int)((ulonglong)(uint)in_ECX[0xc] * 2 >> 0x20) != 0) |
                       (uint)((ulonglong)(uint)in_ECX[0xc] * 2),uVar3);
  in_ECX[0xd] = uVar4;
  _memset((void *)in_ECX[0xd],0,in_ECX[0xc] << 1);
  JObject3D__SetColor(0xff,0xff,0xff,0xff);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x410400 | Symbol: JObject3D::~JObject3D
// ============================================================================
void JObject3D___JObject3D(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JObject3D::vftable;
  if (in_ECX[0xb] != 0) {
    thunk_FUN_00451f46(in_ECX[0xb]);
    in_ECX[0xb] = 0;
  }
  if (in_ECX[0xd] != 0) {
    thunk_FUN_00451f46(in_ECX[0xd]);
    in_ECX[0xd] = 0;
  }
  JObject3DBase___JObject3DBase();
  return;
}

// ============================================================================
// Address: 0x410470 | Symbol: JObject3D::Shift
// ============================================================================
void JObject3D__Shift(undefined4 param_1)

{
  undefined1 local_8c [64];
  undefined1 local_4c [32];
  undefined1 local_2c [32];
  int local_c;
  uint local_8;
  
  _D3DMATRIX___D3DMATRIX();
  D3DUtil_SetTranslateMatrix(local_8c,param_1);
  _D3DVERTEX___D3DVERTEX();
  _D3DVERTEX___D3DVERTEX();
  for (local_8 = 0; local_8 < *(uint *)(local_c + 0x28); local_8 = local_8 + 1) {
    SetVertexFromLVertex(local_2c,local_8 * 0x20 + *(int *)(local_c + 0x2c));
    D3DMath_VertexMatrixMultiply(local_4c,local_2c,local_8c);
    SetLVertexFromVertex(local_8 * 0x20 + *(int *)(local_c + 0x2c),local_4c);
  }
  return;
}

// ============================================================================
// Address: 0x410520 | Symbol: JObject3D::ScaleBy
// ============================================================================
void JObject3D__ScaleBy(float param_1)

{
  int in_ECX;
  undefined1 local_8c [64];
  undefined1 local_4c [32];
  undefined1 local_2c [32];
  int local_c;
  uint local_8;
  
  *(float *)(in_ECX + 0x24) = *(float *)(in_ECX + 0x24) * param_1;
  local_c = in_ECX;
  _D3DMATRIX___D3DMATRIX();
  D3DUtil_SetScaleMatrix(local_8c,param_1,param_1,param_1);
  _D3DVERTEX___D3DVERTEX();
  _D3DVERTEX___D3DVERTEX();
  for (local_8 = 0; local_8 < *(uint *)(local_c + 0x28); local_8 = local_8 + 1) {
    SetVertexFromLVertex(local_2c,local_8 * 0x20 + *(int *)(local_c + 0x2c));
    D3DMath_VertexMatrixMultiply(local_4c,local_2c,local_8c);
    SetLVertexFromVertex(local_8 * 0x20 + *(int *)(local_c + 0x2c),local_4c);
  }
  return;
}

// ============================================================================
// Address: 0x410600 | Symbol: JObject3D::RotateBy
// ============================================================================
void JObject3D__RotateBy(int param_1,float param_2)

{
  undefined1 local_94 [64];
  undefined1 local_54 [32];
  undefined1 local_34 [32];
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  _D3DMATRIX___D3DMATRIX();
  _D3DVERTEX___D3DVERTEX();
  _D3DVERTEX___D3DVERTEX();
  if (param_1 == 0) {
    *(float *)(local_8 + 0x18) = *(float *)(local_8 + 0x18) + param_2;
    D3DUtil_SetRotateXMatrix(local_94,param_2);
    for (local_c = 0; local_c < *(uint *)(local_8 + 0x28); local_c = local_c + 1) {
      SetVertexFromLVertex(local_34,local_c * 0x20 + *(int *)(local_8 + 0x2c));
      D3DMath_VertexMatrixMultiply(local_54,local_34,local_94);
      SetLVertexFromVertex(local_c * 0x20 + *(int *)(local_8 + 0x2c),local_54);
    }
  }
  else if (param_1 == 1) {
    *(float *)(local_8 + 0x1c) = *(float *)(local_8 + 0x1c) + param_2;
    D3DUtil_SetRotateYMatrix(local_94,param_2);
    for (local_10 = 0; local_10 < *(uint *)(local_8 + 0x28); local_10 = local_10 + 1) {
      SetVertexFromLVertex(local_34,local_10 * 0x20 + *(int *)(local_8 + 0x2c));
      D3DMath_VertexMatrixMultiply(local_54,local_34,local_94);
      SetLVertexFromVertex(local_10 * 0x20 + *(int *)(local_8 + 0x2c),local_54);
    }
  }
  else {
    *(float *)(local_8 + 0x20) = *(float *)(local_8 + 0x20) + param_2;
    D3DUtil_SetRotateZMatrix(local_94,param_2);
    for (local_14 = 0; local_14 < *(uint *)(local_8 + 0x28); local_14 = local_14 + 1) {
      SetVertexFromLVertex(local_34,local_14 * 0x20 + *(int *)(local_8 + 0x2c));
      D3DMath_VertexMatrixMultiply(local_54,local_34,local_94);
      SetLVertexFromVertex(local_14 * 0x20 + *(int *)(local_8 + 0x2c),local_54);
    }
  }
  return;
}

// ============================================================================
// Address: 0x410810 | Symbol: JObject3D::GetBox
// ============================================================================
void JObject3D__GetBox(float *param_1,float *param_2)

{
  float fVar1;
  float *pfVar2;
  int in_ECX;
  uint local_8;
  
  pfVar2 = (float *)_D3DVECTOR___D3DVECTOR(0x7f7fffff,0x7f7fffff,0x7f7fffff);
  *param_1 = *pfVar2;
  param_1[1] = pfVar2[1];
  param_1[2] = pfVar2[2];
  pfVar2 = (float *)_D3DVECTOR___D3DVECTOR(0x800000,0x800000,0x800000);
  *param_2 = *pfVar2;
  param_2[1] = pfVar2[1];
  param_2[2] = pfVar2[2];
  for (local_8 = 0; local_8 < *(uint *)(in_ECX + 0x28); local_8 = local_8 + 1) {
    pfVar2 = (float *)(*(int *)(in_ECX + 0x2c) + local_8 * 0x20);
    if (*pfVar2 <= *param_1 && *param_1 != *pfVar2) {
      *param_1 = *(float *)(*(int *)(in_ECX + 0x2c) + local_8 * 0x20);
    }
    pfVar2 = (float *)(*(int *)(in_ECX + 0x2c) + 4 + local_8 * 0x20);
    if (*pfVar2 <= param_1[1] && param_1[1] != *pfVar2) {
      param_1[1] = *(float *)(*(int *)(in_ECX + 0x2c) + 4 + local_8 * 0x20);
    }
    pfVar2 = (float *)(*(int *)(in_ECX + 0x2c) + 8 + local_8 * 0x20);
    if (*pfVar2 <= param_1[2] && param_1[2] != *pfVar2) {
      param_1[2] = *(float *)(*(int *)(in_ECX + 0x2c) + 8 + local_8 * 0x20);
    }
    fVar1 = *(float *)(*(int *)(in_ECX + 0x2c) + local_8 * 0x20);
    if (*param_2 <= fVar1 && fVar1 != *param_2) {
      *param_2 = *(float *)(*(int *)(in_ECX + 0x2c) + local_8 * 0x20);
    }
    fVar1 = *(float *)(*(int *)(in_ECX + 0x2c) + 4 + local_8 * 0x20);
    if (param_2[1] <= fVar1 && fVar1 != param_2[1]) {
      param_2[1] = *(float *)(*(int *)(in_ECX + 0x2c) + 4 + local_8 * 0x20);
    }
    fVar1 = *(float *)(*(int *)(in_ECX + 0x2c) + 8 + local_8 * 0x20);
    if (param_2[2] <= fVar1 && fVar1 != param_2[2]) {
      param_2[2] = *(float *)(*(int *)(in_ECX + 0x2c) + 8 + local_8 * 0x20);
    }
  }
  return;
}

// ============================================================================
// Address: 0x4109f0 | Symbol: JObject3D::Render
// ============================================================================
void JObject3D__Render(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  JObject3DBase___SetWorldTransform();
  if ((short)in_ECX[0xe] != 0) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    uVar2 = D3DTextr_GetSurface((short)in_ECX[0xe]);
    (**(code **)(*piVar1 + 0x8c))(piVar1,0,uVar2);
  }
  (**(code **)(*in_ECX + 0x18))();
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x68))(piVar1,4,0x1e2,in_ECX[0xb],in_ECX[10],in_ECX[0xd],in_ECX[0xc],0);
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x8c))(piVar1,0,0);
  (**(code **)(*in_ECX + 0x1c))();
  JObject3DBase___ResetWorldTransform();
  return;
}

// ============================================================================
// Address: 0x410ad0 | Symbol: JObject3D::SetTexture
// ============================================================================
void JObject3D__SetTexture(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x38) = param_1;
  return;
}

// ============================================================================
// Address: 0x410af0 | Symbol: JObject3D::SetColor
// ============================================================================
void JObject3D__SetColor(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < *(uint *)(in_ECX + 0x28); local_8 = local_8 + 1) {
    *(uint *)(*(int *)(in_ECX + 0x2c) + 0x10 + local_8 * 0x20) =
         (uint)param_4 << 0x18 | (uint)param_1 << 0x10 | (uint)param_2 << 8 | (uint)param_3;
  }
  return;
}

// ============================================================================
// Address: 0x410b50 | Symbol: JObject3D::SetAlpha
// ============================================================================
void JObject3D__SetAlpha(ushort param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < *(uint *)(in_ECX + 0x28); local_8 = local_8 + 1) {
    *(uint *)(*(int *)(in_ECX + 0x2c) + 0x10 + local_8 * 0x20) =
         (uint)param_1 << 0x18 |
         *(uint *)(*(int *)(in_ECX + 0x2c) + 0x10 + local_8 * 0x20) & 0xffffff;
  }
  return;
}

// ============================================================================
// Address: 0x410bc0 | Symbol: JObject3D::SetAlphaFactor
// ============================================================================
void JObject3D__SetAlphaFactor(float param_1)

{
  undefined2 uVar1;
  
  uVar1 = Round(param_1 * 255.0);
  JObject3D__SetAlpha(uVar1);
  return;
}

// ============================================================================
// Address: 0x410c00 | Symbol: JObject3D::GetVertexCount
// ============================================================================
undefined4 JObject3D__GetVertexCount(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}

// ============================================================================
// Address: 0x410c20 | Symbol: JObject3D::GetVertexAt
// ============================================================================
undefined4 * JObject3D__GetVertexAt(undefined4 *param_1,int param_2)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(*(int *)(in_ECX + 0x2c) + param_2 * 0x20);
  puVar3 = param_1;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}

// ============================================================================
// Address: 0x410c50 | Symbol: JObject3D::SetVertexAt
// ============================================================================
void JObject3D__SetVertexAt(int param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&stack0x00000008;
  puVar3 = (undefined4 *)(*(int *)(in_ECX + 0x2c) + param_1 * 0x20);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

// ============================================================================
// Address: 0x410c80 | Symbol: JObject3D::GetIndexCount
// ============================================================================
undefined4 JObject3D__GetIndexCount(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}

// ============================================================================
// Address: 0x410ca0 | Symbol: JObject3D::GetIndexAt
// ============================================================================
undefined2 JObject3D__GetIndexAt(int param_1)

{
  int in_ECX;
  
  return *(undefined2 *)(*(int *)(in_ECX + 0x34) + param_1 * 2);
}

// ============================================================================
// Address: 0x410cc0 | Symbol: JObject3D::SetIndexAt
// ============================================================================
void JObject3D__SetIndexAt(int param_1,undefined2 param_2)

{
  int in_ECX;
  
  *(undefined2 *)(*(int *)(in_ECX + 0x34) + param_1 * 2) = param_2;
  return;
}

// ============================================================================
// Address: 0x410ce0 | Symbol: JObject3D::UsePerspective
// ============================================================================
void JObject3D__UsePerspective(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x7c) = param_1;
  return;
}

// ============================================================================
// Address: 0x410d00 | Symbol: JObject3D::SetAlphaState
// ============================================================================
void JObject3D__SetAlphaState(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x80) = param_1;
  return;
}

// ============================================================================
// Address: 0x410d20 | Symbol: JObject3D::SetFilterState
// ============================================================================
void JObject3D__SetFilterState(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x84) = param_1;
  return;
}

// ============================================================================
// Address: 0x410d40 | Symbol: JObject3D::_SetRenderState
// ============================================================================
void JObject3D___SetRenderState(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x54))(piVar1,0x89,in_ECX + 0x3c);
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x54))(piVar1,4,in_ECX + 0x40);
  if (*(int *)(in_ECX + 0x80) != 0) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x54))(piVar1,0x1b,in_ECX + 0x44);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x54))(piVar1,0x13,in_ECX + 0x48);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x54))(piVar1,0x14,in_ECX + 0x4c);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x54))(piVar1,0x1d,in_ECX + 0x50);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x54))(piVar1,0xe,in_ECX + 0x54);
    if (*(int *)(in_ECX + 0x80) == 3) {
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x90))(piVar1,0,1,in_ECX + 0x58);
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x90))(piVar1,0,2,in_ECX + 0x5c);
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x90))(piVar1,0,3,in_ECX + 0x60);
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x90))(piVar1,0,4,in_ECX + 100);
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x90))(piVar1,0,5,in_ECX + 0x68);
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x90))(piVar1,0,6,in_ECX + 0x6c);
    }
  }
  if (*(int *)(in_ECX + 0x84) != 0) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x90))(piVar1,0,0x11,in_ECX + 0x70);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x90))(piVar1,0,0x10,in_ECX + 0x74);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x90))(piVar1,0,0x12,in_ECX + 0x78);
  }
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x50))(piVar1,0x89,0);
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x50))(piVar1,4,*(undefined4 *)(in_ECX + 0x7c));
  if (*(int *)(in_ECX + 0x80) == 1) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1b,1);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x13,2);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x14,2);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1d,0);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0xe,0);
  }
  else if (*(int *)(in_ECX + 0x80) == 2) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1b,1);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x13,1);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x14,3);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1d,0);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0xe,0);
  }
  else if (*(int *)(in_ECX + 0x80) == 3) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1b,1);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x13,5);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x14,6);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1d,0);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0xe,0);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,1,4);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,2,2);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,3,0);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,4,4);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,5,2);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,6,0);
  }
  if (*(int *)(in_ECX + 0x84) == 1) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x11,1);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x10,1);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x12,2);
  }
  else if (*(int *)(in_ECX + 0x84) == 2) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x11,2);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x10,2);
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x12,3);
  }
  return;
}

// ============================================================================
// Address: 0x4114c0 | Symbol: JObject3D::_ResetRenderState
// ============================================================================
void JObject3D___ResetRenderState(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x50))(piVar1,0x89,*(undefined4 *)(in_ECX + 0x3c));
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x50))(piVar1,4,*(undefined4 *)(in_ECX + 0x40));
  if (*(int *)(in_ECX + 0x80) != 0) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1b,*(undefined4 *)(in_ECX + 0x44));
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x13,*(undefined4 *)(in_ECX + 0x48));
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x14,*(undefined4 *)(in_ECX + 0x4c));
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0x1d,*(undefined4 *)(in_ECX + 0x50));
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x50))(piVar1,0xe,*(undefined4 *)(in_ECX + 0x54));
    if (*(int *)(in_ECX + 0x80) == 3) {
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x94))(piVar1,0,1,*(undefined4 *)(in_ECX + 0x58));
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x94))(piVar1,0,2,*(undefined4 *)(in_ECX + 0x5c));
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x94))(piVar1,0,3,*(undefined4 *)(in_ECX + 0x60));
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x94))(piVar1,0,4,*(undefined4 *)(in_ECX + 100));
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x94))(piVar1,0,5,*(undefined4 *)(in_ECX + 0x68));
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x94))(piVar1,0,6,*(undefined4 *)(in_ECX + 0x6c));
    }
  }
  if (*(int *)(in_ECX + 0x84) != 0) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x11,*(undefined4 *)(in_ECX + 0x70));
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x10,*(undefined4 *)(in_ECX + 0x74));
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x94))(piVar1,0,0x12,*(undefined4 *)(in_ECX + 0x78));
  }
  return;
}

// ============================================================================
// Address: 0x411780 | Symbol: JObject3D_Rect::JObject3D_Rect
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * JObject3D_Rect__JObject3D_Rect(undefined4 param_1,float param_2,float param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  uint local_28;
  undefined2 local_20 [6];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470d20;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  JObject3D__JObject3D(param_1,4,6);
  local_8 = 0;
  *in_ECX = JObject3D_Rect::vftable;
  param_2 = param_2 / 2.0;
  param_3 = param_3 / 2.0;
  uVar2 = _D3DVECTOR___D3DVECTOR(-param_2,0,param_3);
  SetLVertexFromVector(in_ECX[0xb],uVar2,uVar1);
  uVar2 = _D3DVECTOR___D3DVECTOR(param_2,0,param_3);
  SetLVertexFromVector(in_ECX[0xb] + 0x20,uVar2);
  uVar2 = _D3DVECTOR___D3DVECTOR(-param_2,0,-param_3);
  SetLVertexFromVector(in_ECX[0xb] + 0x40,uVar2);
  uVar2 = _D3DVECTOR___D3DVECTOR(param_2,0,-param_3);
  SetLVertexFromVector(in_ECX[0xb] + 0x60,uVar2);
  local_20[0] = 0;
  local_20[1] = 1;
  local_20[2] = 3;
  local_20[3] = 0;
  local_20[4] = 3;
  local_20[5] = 2;
  for (local_28 = 0; local_28 < (uint)in_ECX[0xc]; local_28 = local_28 + 1) {
    *(undefined2 *)(in_ECX[0xd] + local_28 * 2) = local_20[local_28];
  }
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x411990 | Symbol: JObject3D_Rect::~JObject3D_Rect
// ============================================================================
void JObject3D_Rect___JObject3D_Rect(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JObject3D_Rect::vftable;
  JObject3D___JObject3D();
  return;
}

// ============================================================================
// Address: 0x4119b0 | Symbol: JObject3D_Rect::SetTexture
// ============================================================================
void JObject3D_Rect__SetTexture
               (undefined2 param_1,float param_2,float param_3,float param_4,float param_5)

{
  int in_ECX;
  
  JObject3D__SetTexture(param_1,param_2,param_3,param_4,param_5);
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x18) = param_2 + 0.0001;
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x1c) = param_3 + 0.0001;
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x38) = param_4 - 0.0001;
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x3c) = param_3 + 0.0001;
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x58) = param_2 + 0.0001;
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x5c) = param_5 - 0.0001;
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x78) = param_4 - 0.0001;
  *(float *)(*(int *)(in_ECX + 0x2c) + 0x7c) = param_5 - 0.0001;
  return;
}

// ============================================================================
// Address: 0x411b10 | Symbol: JObject3D_Rect::Render2
// ============================================================================
void JObject3D_Rect__Render2(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  JObject3D_Rect___SetWorldTransform2(param_1);
  if ((short)in_ECX[0xe] != 0) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    uVar2 = D3DTextr_GetSurface((short)in_ECX[0xe]);
    (**(code **)(*piVar1 + 0x8c))(piVar1,0,uVar2);
  }
  (**(code **)(*in_ECX + 0x18))();
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x68))(piVar1,4,0x1e2,in_ECX[0xb],in_ECX[10],in_ECX[0xd],in_ECX[0xc],0);
  piVar1 = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*piVar1 + 0x8c))(piVar1,0,0);
  (**(code **)(*in_ECX + 0x1c))();
  JObject3DBase___ResetWorldTransform();
  return;
}

// ============================================================================
// Address: 0x411c00 | Symbol: JObject3D_Rect::_SetWorldTransform2
// ============================================================================
void JObject3D_Rect___SetWorldTransform2(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8c [16];
  undefined1 local_4c [48];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int *local_c;
  int local_8;
  
  _D3DMATRIX___D3DMATRIX();
  puVar2 = local_8c;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  D3DMath_MatrixInvert(local_4c,local_8c);
  local_1c = *(undefined4 *)(local_8 + 8);
  local_18 = *(undefined4 *)(local_8 + 0xc);
  local_14 = *(undefined4 *)(local_8 + 0x10);
  local_c = (int *)CD3DApplication__GetD3DDevice();
  (**(code **)(*local_c + 0x2c))(local_c,1,local_4c);
  return;
}

// ============================================================================
// Address: 0x411c90 | Symbol: JObject3D_Shadow::JObject3D_Shadow
// ============================================================================
undefined4 *
JObject3D_Shadow__JObject3D_Shadow(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470d54;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JObject3D_Rect__JObject3D_Rect(param_1,param_2,param_3);
  local_8 = 0;
  *in_ECX = JObject3D_Shadow::vftable;
  JObject3D__UsePerspective(1);
  JObject3D__SetAlphaState(2);
  JObject3D__SetFilterState(2);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x411d30 | Symbol: JObject3D_Shadow::~JObject3D_Shadow
// ============================================================================
void JObject3D_Shadow___JObject3D_Shadow(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JObject3D_Shadow::vftable;
  JObject3D_Rect___JObject3D_Rect();
  return;
}

// ============================================================================
// Address: 0x411d50 | Symbol: JObject3D_Particle::JObject3D_Particle
// ============================================================================
undefined4 *
JObject3D_Particle__JObject3D_Particle(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470d7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JObject3D_Rect__JObject3D_Rect(param_1,param_2,param_3);
  local_8 = 0;
  *in_ECX = JObject3D_Particle::vftable;
  JObject3D__RotateBy(0,0xbfc90fdb);
  JObject3D__UsePerspective(0);
  JObject3D__SetAlphaState(1);
  JObject3D__SetFilterState(2);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x411e00 | Symbol: JObject3D_Particle::~JObject3D_Particle
// ============================================================================
void JObject3D_Particle___JObject3D_Particle(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JObject3D_Particle::vftable;
  JObject3D_Rect___JObject3D_Rect();
  return;
}

// ============================================================================
// Address: 0x411e20 | Symbol: SetLVertexFromVector
// ============================================================================
void SetLVertexFromVector(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return;
}

// ============================================================================
// Address: 0x411e50 | Symbol: SetLVertexFromVertex
// ============================================================================
void SetLVertexFromVertex(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return;
}

// ============================================================================
// Address: 0x411e80 | Symbol: SetVertexFromLVertex
// ============================================================================
void SetVertexFromLVertex(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return;
}

// ============================================================================
// Address: 0x411eb0 | Symbol: _D3DLVERTEX::_D3DLVERTEX
// ============================================================================
undefined4 _D3DLVERTEX___D3DLVERTEX(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}

// ============================================================================
// Address: 0x411ec0 | Symbol: CD3DFile::
// ============================================================================
undefined4 CD3DFile__(uint param_1)

{
  undefined4 in_ECX;
  
  CD3DFile___CD3DFile();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,4);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x411ef0 | Symbol: Concurrency::details::SchedulingNode::JObject3D::
// ============================================================================
/* Library Function - Single Match
    public: void * __thiscall Concurrency::details::SchedulingNode::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::SchedulingNode::JObject3D__(SchedulingNode *this,uint param_1)

{
  JObject3D___JObject3D();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x88);
  }
  return this;
}

// ============================================================================
// Address: 0x411f30 | Symbol: JObject3DBase::
// ============================================================================
undefined4 JObject3DBase__(uint param_1)

{
  undefined4 in_ECX;
  
  JObject3DBase___JObject3DBase();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x28);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x411f60 | Symbol: JObject3DList::
// ============================================================================
undefined4 JObject3DList__(uint param_1)

{
  undefined4 in_ECX;
  
  JObject3DList___JObject3DList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,8);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x411f90 | Symbol: JObject3DX::
// ============================================================================
undefined4 JObject3DX__(uint param_1)

{
  undefined4 in_ECX;
  
  JObject3DX___JObject3DX();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x5c);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x411fc0 | Symbol: Concurrency::details::ThreadVirtualProcessor::JObject3D_Particle::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::JObject3D_Particle__
          (ThreadVirtualProcessor *this,uint param_1)

{
  JObject3D_Particle___JObject3D_Particle();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x88);
  }
  return this;
}

// ============================================================================
// Address: 0x412000 | Symbol: Concurrency::details::ThreadVirtualProcessor::JObject3D_Rect::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::JObject3D_Rect__
          (ThreadVirtualProcessor *this,uint param_1)

{
  JObject3D_Rect___JObject3D_Rect();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x88);
  }
  return this;
}

// ============================================================================
// Address: 0x412040 | Symbol: Concurrency::details::ThreadVirtualProcessor::JObject3D_Shadow::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::JObject3D_Shadow__
          (ThreadVirtualProcessor *this,uint param_1)

{
  JObject3D_Shadow___JObject3D_Shadow();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x88);
  }
  return this;
}

// ============================================================================
// Address: 0x412080 | Symbol: D3DUtil_SetScaleMatrix
// ============================================================================
void D3DUtil_SetScaleMatrix
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D3DUtil_SetIdentityMatrix(param_1);
  *param_1 = param_2;
  param_1[5] = param_3;
  param_1[10] = param_4;
  return;
}

// ============================================================================
// Address: 0x4120c0 | Symbol: D3DUtil_SetTranslateMatrix
// ============================================================================
void D3DUtil_SetTranslateMatrix(undefined4 param_1,undefined4 *param_2)

{
  FUN_00412100(param_1,*param_2,param_2[1],param_2[2]);
  return;
}

// ============================================================================
// Address: 0x412100 | Symbol: FUN_00412100
// ============================================================================
void FUN_00412100(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D3DUtil_SetIdentityMatrix(param_1);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x34) = param_3;
  *(undefined4 *)(param_1 + 0x38) = param_4;
  return;
}
