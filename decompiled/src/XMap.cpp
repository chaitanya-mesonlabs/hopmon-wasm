// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XMap.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XMap.h"

// ============================================================================
// Address: 0x420ee0 | Symbol: GetMapResId
// ============================================================================
undefined4 GetMapResId(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = XApplication__GetCurrentWorld();
  iVar2 = *(int *)(param_1 + 0x1a8) % 0xf;
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      return 0x11c;
    }
    if (iVar2 == 1) {
      return 0x115;
    }
    if (iVar2 == 2) {
      return 0x116;
    }
    if (iVar2 == 3) {
      return 0x117;
    }
    if (iVar2 == 4) {
      return 0x118;
    }
    if (iVar2 == 5) {
      return 0x119;
    }
    if (iVar2 == 6) {
      return 0x11a;
    }
    if (iVar2 == 7) {
      return 0x11b;
    }
    if (iVar2 == 8) {
      return 0x114;
    }
    if (iVar2 == 9) {
      return 0x109;
    }
    if (iVar2 == 10) {
      return 0x10a;
    }
    if (iVar2 == 0xb) {
      return 0x10b;
    }
    if (iVar2 == 0xc) {
      return 0x10c;
    }
    if (iVar2 == 0xd) {
      return 0x10d;
    }
    if (iVar2 == 0xe) {
      return 0x10e;
    }
  }
  else if (iVar1 == 1) {
    if (iVar2 == 0) {
      return 0x11d;
    }
    if (iVar2 == 1) {
      return 0x11e;
    }
    if (iVar2 == 2) {
      return 0x11f;
    }
    if (iVar2 == 3) {
      return 0x120;
    }
    if (iVar2 == 4) {
      return 0x121;
    }
    if (iVar2 == 5) {
      return 0x122;
    }
    if (iVar2 == 6) {
      return 0x123;
    }
    if (iVar2 == 7) {
      return 0x124;
    }
    if (iVar2 == 8) {
      return 0x125;
    }
    if (iVar2 == 9) {
      return 0x126;
    }
    if (iVar2 == 10) {
      return 0x127;
    }
    if (iVar2 == 0xb) {
      return 0x128;
    }
    if (iVar2 == 0xc) {
      return 0x129;
    }
    if (iVar2 == 0xd) {
      return 0x12a;
    }
    if (iVar2 == 0xe) {
      return 299;
    }
  }
  else if (iVar1 == 2) {
    if (iVar2 == 0) {
      return 300;
    }
    if (iVar2 == 1) {
      return 0x12d;
    }
    if (iVar2 == 2) {
      return 0x12e;
    }
    if (iVar2 == 3) {
      return 0x12f;
    }
    if (iVar2 == 4) {
      return 0x130;
    }
    if (iVar2 == 5) {
      return 0x131;
    }
    if (iVar2 == 6) {
      return 0x132;
    }
    if (iVar2 == 7) {
      return 0x133;
    }
    if (iVar2 == 8) {
      return 0x134;
    }
    if (iVar2 == 9) {
      return 0x135;
    }
    if (iVar2 == 10) {
      return 0x136;
    }
    if (iVar2 == 0xb) {
      return 0x137;
    }
    if (iVar2 == 0xc) {
      return 0x138;
    }
    if (iVar2 == 0xd) {
      return 0x139;
    }
    if (iVar2 == 0xe) {
      return 0x13a;
    }
  }
  return 0x11c;
}

// ============================================================================
// Address: 0x421280 | Symbol: XCamera::XCamera
// ============================================================================
undefined4 * XCamera__XCamera(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = XCamera::vftable;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  _D3DVECTOR___D3DVECTOR(0,0,0);
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  _D3DMATRIX___D3DMATRIX();
  D3DUtil_SetIdentityMatrix(in_ECX + 0xe);
  return in_ECX;
}

// ============================================================================
// Address: 0x421350 | Symbol: XCamera::~XCamera
// ============================================================================
void XCamera___XCamera(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XCamera::vftable;
  return;
}

// ============================================================================
// Address: 0x421370 | Symbol: XCamera::ResetForGame
// ============================================================================
void XCamera__ResetForGame(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_14 [2];
  undefined4 local_c;
  int local_8;
  
  *(undefined4 *)(in_ECX + 0x28) = 0x43d20000;
  *(undefined4 *)(in_ECX + 0x2c) = 0x3f490fdb;
  *(undefined4 *)(in_ECX + 0x30) = 0x40490fdb;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_8 = in_ECX;
  JObject3DBase__GetWorldPos(local_14);
  puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(local_14[0],0,local_c);
  *(undefined4 *)(local_8 + 0x10) = *puVar1;
  *(undefined4 *)(local_8 + 0x14) = puVar1[1];
  *(undefined4 *)(local_8 + 0x18) = puVar1[2];
  puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(local_14[0],0,local_c);
  *(undefined4 *)(local_8 + 0x1c) = *puVar1;
  *(undefined4 *)(local_8 + 0x20) = puVar1[1];
  *(undefined4 *)(local_8 + 0x24) = puVar1[2];
  XCamera__UpdateViewMatrix();
  *(undefined4 *)(local_8 + 8) = 1;
  *(undefined4 *)(local_8 + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x421460 | Symbol: XCamera::ResetForTitle
// ============================================================================
void XCamera__ResetForTitle(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x28) = 0x43fa0000;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0x40490fdb;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(0,0,0);
  *(undefined4 *)(in_ECX + 0x10) = *puVar1;
  *(undefined4 *)(in_ECX + 0x14) = puVar1[1];
  *(undefined4 *)(in_ECX + 0x18) = puVar1[2];
  puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(0,0,0);
  *(undefined4 *)(in_ECX + 0x1c) = *puVar1;
  *(undefined4 *)(in_ECX + 0x20) = puVar1[1];
  *(undefined4 *)(in_ECX + 0x24) = puVar1[2];
  XCamera__UpdateViewMatrix();
  *(undefined4 *)(in_ECX + 8) = 1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x421530 | Symbol: XCamera::DoSetTransform
// ============================================================================
void XCamera__DoSetTransform(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x2c))(piVar1,2,in_ECX + 0x38);
  }
  return;
}

// ============================================================================
// Address: 0x421570 | Symbol: XCamera::GetState
// ============================================================================
undefined4 XCamera__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}

// ============================================================================
// Address: 0x421590 | Symbol: XCamera::GetViewDirection
// ============================================================================
undefined4 XCamera__GetViewDirection(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x34);
}

// ============================================================================
// Address: 0x4215b0 | Symbol: XCamera::GetViewMatrix
// ============================================================================
int XCamera__GetViewMatrix(void)

{
  int in_ECX;
  
  return in_ECX + 0x38;
}

// ============================================================================
// Address: 0x4215d0 | Symbol: XCamera::StartRotatingLeft
// ============================================================================
void XCamera__StartRotatingLeft(void)

{
  int in_ECX;
  uint uVar1;
  
  uVar1 = *(int *)(in_ECX + 0x34) + 3U & 0x80000003;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
  }
  *(uint *)(in_ECX + 0x34) = uVar1;
  *(undefined4 *)(in_ECX + 8) = 2;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x421610 | Symbol: XCamera::StartRotatingRight
// ============================================================================
void XCamera__StartRotatingRight(void)

{
  int in_ECX;
  uint uVar1;
  
  uVar1 = *(int *)(in_ECX + 0x34) + 1U & 0x80000003;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
  }
  *(uint *)(in_ECX + 0x34) = uVar1;
  *(undefined4 *)(in_ECX + 8) = 3;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x421650 | Symbol: XCamera::StartLevelCompleted
// ============================================================================
void XCamera__StartLevelCompleted(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 4;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x421670 | Symbol: XCamera::StartGameOver
// ============================================================================
void XCamera__StartGameOver(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 5;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x421690 | Symbol: XCamera::IncrVerticalAngle
// ============================================================================
void XCamera__IncrVerticalAngle(int param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x2c) =
       (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.008726646 +
       *(float *)(in_ECX + 0x2c);
  if (1.4207964 < *(float *)(in_ECX + 0x2c)) {
    *(undefined4 *)(in_ECX + 0x2c) = 0x3fb5dca8;
  }
  return;
}

// ============================================================================
// Address: 0x421710 | Symbol: XCamera::DecrVerticalAngle
// ============================================================================
void XCamera__DecrVerticalAngle(int param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x2c) =
       *(float *)(in_ECX + 0x2c) -
       (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.008726646;
  if (*(float *)(in_ECX + 0x2c) <= 0.2 && *(float *)(in_ECX + 0x2c) != 0.2) {
    *(undefined4 *)(in_ECX + 0x2c) = 0x3e4ccccd;
  }
  return;
}

// ============================================================================
// Address: 0x421790 | Symbol: XCamera::ProcessFrame
// ============================================================================
void XCamera__ProcessFrame(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_38 [2];
  undefined4 local_30;
  undefined4 local_2c [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  int local_8;
  
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  local_8 = in_ECX;
  if (*(int *)(in_ECX + 8) == 1) {
    JObject3DBase__GetWorldPos(local_2c);
    puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(local_2c[0],0,local_24);
    *(undefined4 *)(local_8 + 0x10) = *puVar1;
    *(undefined4 *)(local_8 + 0x14) = puVar1[1];
    *(undefined4 *)(local_8 + 0x18) = puVar1[2];
    puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(local_2c[0],0,local_24);
    *(undefined4 *)(local_8 + 0x1c) = *puVar1;
    *(undefined4 *)(local_8 + 0x20) = puVar1[1];
    *(undefined4 *)(local_8 + 0x24) = puVar1[2];
    XCamera__UpdateViewMatrix();
  }
  else if ((*(int *)(in_ECX + 8) == 2) || (*(int *)(in_ECX + 8) == 3)) {
    local_10 = 0x3cd67750;
    local_c = 0.02617994;
    if (*(int *)(in_ECX + 8) == 2) {
      local_c = -0.02617994;
    }
    *(float *)(in_ECX + 0x30) = *(float *)(in_ECX + 0x30) + local_c;
    JObject3DBase__GetWorldPos(local_38);
    puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(local_38[0],0,local_30);
    *(undefined4 *)(local_8 + 0x10) = *puVar1;
    *(undefined4 *)(local_8 + 0x14) = puVar1[1];
    *(undefined4 *)(local_8 + 0x18) = puVar1[2];
    puVar1 = (undefined4 *)_D3DVECTOR___D3DVECTOR(local_38[0],0,local_30);
    *(undefined4 *)(local_8 + 0x1c) = *puVar1;
    *(undefined4 *)(local_8 + 0x20) = puVar1[1];
    *(undefined4 *)(local_8 + 0x24) = puVar1[2];
    XCamera__UpdateViewMatrix();
    if (0x3b < *(uint *)(local_8 + 0xc)) {
      *(undefined4 *)(local_8 + 8) = 1;
      *(undefined4 *)(local_8 + 0xc) = 0;
    }
  }
  else if (*(int *)(in_ECX + 8) == 4) {
    *(float *)(in_ECX + 0x14) = *(float *)(in_ECX + 0x14) + 0.7;
    *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x20) + 0.7;
    *(float *)(in_ECX + 0x28) = *(float *)(in_ECX + 0x28) - 0.5;
    if (*(float *)(in_ECX + 0x28) <= 140.0 && *(float *)(in_ECX + 0x28) != 140.0) {
      *(undefined4 *)(in_ECX + 0x28) = 0x430c0000;
    }
    local_14 = 0x3aa02279;
    *(float *)(in_ECX + 0x2c) = *(float *)(in_ECX + 0x2c) + 0.0012217305;
    if (1.4207964 < *(float *)(in_ECX + 0x2c)) {
      *(undefined4 *)(in_ECX + 0x2c) = 0x3fb5dca8;
    }
    local_18 = 0xbc0efa35;
    *(float *)(in_ECX + 0x30) = *(float *)(in_ECX + 0x30) + -0.008726646;
    XCamera__UpdateViewMatrix();
  }
  else if (*(int *)(in_ECX + 8) == 5) {
    *(float *)(in_ECX + 0x28) = *(float *)(in_ECX + 0x28) + 0.5;
    local_1c = 0x3aa02279;
    *(float *)(in_ECX + 0x2c) = *(float *)(in_ECX + 0x2c) + 0.0012217305;
    if (1.4207964 < *(float *)(in_ECX + 0x2c)) {
      *(undefined4 *)(in_ECX + 0x2c) = 0x3fb5dca8;
    }
    local_20 = 0xbc0efa35;
    *(float *)(in_ECX + 0x30) = *(float *)(in_ECX + 0x30) + -0.008726646;
    XCamera__UpdateViewMatrix();
  }
  return;
}

// ============================================================================
// Address: 0x421af0 | Symbol: XCamera::UpdateViewMatrix
// ============================================================================
void XCamera__UpdateViewMatrix(void)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  int local_8;
  
  local_8 = in_ECX;
  fVar2 = (float10)sinf(*(undefined4 *)(in_ECX + 0x2c));
  local_10 = (float)fVar2;
  local_18 = local_10 * *(float *)(local_8 + 0x28);
  fVar2 = (float10)cosf(*(undefined4 *)(local_8 + 0x2c));
  local_14 = (float)fVar2;
  local_c = local_14 * *(float *)(local_8 + 0x28);
  FUN_00403f60();
  local_28 = *(float *)(local_8 + 0x20) + local_18;
  fVar2 = (float10)sinf(*(undefined4 *)(local_8 + 0x30));
  local_1c = (float)fVar2;
  local_2c = local_1c * local_c + *(float *)(local_8 + 0x1c);
  fVar2 = (float10)cosf(*(undefined4 *)(local_8 + 0x30));
  local_20 = (float)fVar2;
  local_24 = local_20 * local_c + *(float *)(local_8 + 0x24);
  uVar1 = _D3DVECTOR___D3DVECTOR(0,0x3f800000,0);
  D3DUtil_SetViewMatrix(local_8 + 0x38,&local_2c,local_8 + 0x10,uVar1);
  return;
}

// ============================================================================
// Address: 0x421c10 | Symbol: XPreviewMap::XPreviewMap
// ============================================================================
undefined4 * XPreviewMap__XPreviewMap(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = XPreviewMap::vftable;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0x41200000;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined2 *)(in_ECX + 7) = 0;
  iVar1 = XApplication__GetCurrentWorld();
  if (iVar1 == 0) {
    *(undefined2 *)(in_ECX + 7) = 0x9c;
  }
  else {
    iVar1 = XApplication__GetCurrentWorld();
    if (iVar1 == 1) {
      *(undefined2 *)(in_ECX + 7) = 0xfb;
    }
    else {
      *(undefined2 *)(in_ECX + 7) = 0xfc;
    }
  }
  XPreviewMap___LoadMapArray(param_2);
  XPreviewMap___CreateMapObject();
  (**(code **)(*(int *)in_ECX[3] + 0xc))(0,0xbf060a92);
  return in_ECX;
}

// ============================================================================
// Address: 0x421d00 | Symbol: XPreviewMap::~XPreviewMap
// ============================================================================
void XPreviewMap___XPreviewMap(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XPreviewMap::vftable;
  if (in_ECX[2] != 0) {
    thunk_FUN_00451f46(in_ECX[2]);
    in_ECX[2] = 0;
  }
  if (in_ECX[3] != 0) {
    if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[3])(1);
    }
    in_ECX[3] = 0;
  }
  return;
}

// ============================================================================
// Address: 0x421d80 | Symbol: XPreviewMap::ProcessFrame
// ============================================================================
void XPreviewMap__ProcessFrame(int param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(0,0x3f060a92);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))
            (1,(float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.0052359877
            );
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(0,0xbf060a92);
  return;
}

// ============================================================================
// Address: 0x421e20 | Symbol: XPreviewMap::Render
// ============================================================================
void XPreviewMap__Render(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x14))();
  return;
}

// ============================================================================
// Address: 0x421e40 | Symbol: XPreviewMap::_LoadMapArray
// ============================================================================
void XPreviewMap___LoadMapArray(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined1 local_60 [16];
  SchedulerBase local_50 [24];
  InternalContextBase local_38 [8];
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471de5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JStringList__JStringList(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  JStringList__JStringList();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_30 = GetStringListFromResource(local_60,param_1);
  local_24 = 0;
  do {
    uVar1 = JStringList__Count();
    if (uVar1 <= local_24) {
LAB_00421f1e:
      local_8 = local_8 & 0xffffff00;
      JStringList___JStringList();
      *(undefined4 *)(local_14 + 0x14) = 0;
      local_1c = 0;
      while( true ) {
        uVar1 = JStringList__Count();
        if (uVar1 <= local_1c) break;
        JStringList__GetString(local_1c);
        uVar1 = JString__Length();
        if (*(uint *)(local_14 + 0x14) < uVar1) {
          JStringList__GetString(local_1c);
          uVar2 = JString__Length();
          *(undefined4 *)(local_14 + 0x14) = uVar2;
        }
        local_1c = local_1c + 1;
      }
      *(int *)(local_14 + 0x14) = *(int *)(local_14 + 0x14) + 2;
      iVar3 = JStringList__Count();
      *(int *)(local_14 + 0x18) = iVar3 + 2;
      local_28 = FUN_0042d2b4(*(int *)(local_14 + 0x18) * *(int *)(local_14 + 0x14));
      *(undefined4 *)(local_14 + 8) = local_28;
      _memset(*(void **)(local_14 + 8),0x2e,*(int *)(local_14 + 0x18) * *(int *)(local_14 + 0x14));
      for (local_20 = 1; local_20 < *(int *)(local_14 + 0x18) + -1; local_20 = local_20 + 1) {
        for (local_18 = 1; local_18 < *(int *)(local_14 + 0x14) + -1; local_18 = local_18 + 1) {
          local_2c = local_20 * *(int *)(local_14 + 0x14) + local_18;
          uVar2 = JStringList__GetString(local_20 + -1);
          FUN_00413a80(uVar2);
          local_8 = CONCAT31(local_8._1_3_,3);
          uVar5 = local_18 - 1;
          uVar1 = JString__Length();
          if (uVar5 < uVar1) {
            iVar3 = JString__c_str();
            *(undefined1 *)(*(int *)(local_14 + 8) + local_2c) =
                 *(undefined1 *)(iVar3 + -1 + local_18);
          }
          local_8 = local_8 & 0xffffff00;
          JString___JString();
        }
      }
      local_8 = 0xffffffff;
      JStringList___JStringList();
      ExceptionList = local_10;
      return;
    }
    uVar2 = JStringList__GetString(local_24);
    FUN_00413a80(uVar2);
    local_8._0_1_ = 2;
    iVar3 = JString__Length();
    if (iVar3 == 0) {
LAB_00421f02:
      local_8 = CONCAT31(local_8._1_3_,1);
      JString___JString();
      goto LAB_00421f1e;
    }
    pcVar4 = (char *)JString__c_str();
    if (*pcVar4 == '_') goto LAB_00421f02;
    Concurrency::details::SchedulerBase::JStringList__Append(local_50,local_38);
    local_8 = CONCAT31(local_8._1_3_,1);
    JString___JString();
    local_24 = local_24 + 1;
  } while( true );
}

// ============================================================================
// Address: 0x4220c0 | Symbol: XPreviewMap::_CreateMapObject
// ============================================================================
void XPreviewMap___CreateMapObject(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_f0 [4];
  undefined4 uStack_e0;
  float fStack_dc;
  undefined4 *puStack_d8;
  undefined1 *puStack_d4;
  uint uStack_d0;
  undefined1 *local_cc;
  uint local_c8;
  float local_c4;
  int *local_c0;
  uint uStack_bc;
  undefined4 local_b0 [11];
  undefined4 local_84;
  int *local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  int *local_68;
  int local_64;
  undefined4 *local_60;
  int local_5c;
  int local_58;
  ushort local_54;
  int local_50;
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  float local_38;
  int *local_34;
  undefined1 local_30 [8];
  undefined1 *local_28;
  uint local_24;
  float local_20;
  float local_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471e33;
  local_10 = ExceptionList;
  uStack_bc = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_78 = ((float)*(int *)(in_ECX + 0x14) * *(float *)(in_ECX + 0x10)) / 2.0;
  local_7c = ((float)*(int *)(in_ECX + 0x18) * *(float *)(in_ECX + 0x10)) / 2.0;
  local_c0 = (int *)0x42212f;
  local_14 = in_ECX;
  JObject3DList__JObject3DList();
  local_8 = 0;
  for (local_24 = 0; (int)local_24 < *(int *)(local_14 + 0x18); local_24 = local_24 + 1) {
    for (local_28 = (undefined1 *)0x0; (int)local_28 < *(int *)(local_14 + 0x14);
        local_28 = local_28 + 1) {
      local_18 = local_28 + local_24 * *(int *)(local_14 + 0x14);
      local_20 = ((float)(int)local_28 * *(float *)(local_14 + 0x10) +
                 *(float *)(local_14 + 0x10) / 2.0) - local_78;
      local_c0 = (int *)(((float)(int)(*(int *)(local_14 + 0x18) - local_24) *
                          *(float *)(local_14 + 0x10) - *(float *)(local_14 + 0x10) / 2.0) -
                        local_7c);
      local_1c = (float)local_c0;
      if (local_18[*(int *)(local_14 + 8)] != '.') {
        if (local_18[*(int *)(local_14 + 8)] == '@') {
          local_18[*(int *)(local_14 + 8)] = 0x2d;
          local_c8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
          local_cc = local_30;
          uStack_d0 = 0x42224c;
          local_c4 = local_20;
          XPreviewMap___CreateFloor();
        }
        else if (local_18[*(int *)(local_14 + 8)] == '$') {
          local_18[*(int *)(local_14 + 8)] = 0x2d;
          local_c8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
          local_cc = local_30;
          uStack_d0 = 0x4222a0;
          local_c4 = local_20;
          XPreviewMap___CreateFloor();
        }
        else if (((byte)local_18[*(int *)(local_14 + 8)] < 0x41) ||
                (0x5a < (byte)local_18[*(int *)(local_14 + 8)])) {
          if (((byte)local_18[*(int *)(local_14 + 8)] < 0x61) ||
             (0x7a < (byte)local_18[*(int *)(local_14 + 8)])) {
            if ((((((local_18[*(int *)(local_14 + 8)] == '-') ||
                   (local_18[*(int *)(local_14 + 8)] == '+')) ||
                  (local_18[*(int *)(local_14 + 8)] == '!')) ||
                 ((local_18[*(int *)(local_14 + 8)] == '[' ||
                  (local_18[*(int *)(local_14 + 8)] == ']')))) ||
                (local_18[*(int *)(local_14 + 8)] == '>')) ||
               (((local_18[*(int *)(local_14 + 8)] == '<' ||
                 (local_18[*(int *)(local_14 + 8)] == '#')) ||
                ((local_18[*(int *)(local_14 + 8)] == '=' ||
                 (local_18[*(int *)(local_14 + 8)] == '*')))))) {
              local_c8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
              local_cc = local_30;
              uStack_d0 = 0x422444;
              local_c4 = local_20;
              XPreviewMap___CreateFloor();
            }
            else if ((0x30 < (byte)local_18[*(int *)(local_14 + 8)]) &&
                    ((byte)local_18[*(int *)(local_14 + 8)] < 0x34)) {
              local_38 = 0.0;
              if (local_18[*(int *)(local_14 + 8)] == '1') {
                local_c8 = local_24;
                local_cc = local_28;
                uStack_d0 = 1;
                puStack_d4 = local_30;
                puStack_d8 = (undefined4 *)0x4224bb;
                local_c4 = local_20;
                XPreviewMap___CreateWalls();
                local_38 = *(float *)(local_14 + 0x10);
              }
              else if (local_18[*(int *)(local_14 + 8)] == '2') {
                local_c8 = local_24;
                local_cc = local_28;
                uStack_d0 = 1;
                puStack_d4 = local_30;
                puStack_d8 = (undefined4 *)0x42250b;
                local_c4 = local_20;
                XPreviewMap___CreateWalls();
                local_c0 = (int *)local_1c;
                local_c4 = local_20;
                local_c8 = local_24;
                local_cc = local_28;
                uStack_d0 = 2;
                puStack_d4 = local_30;
                puStack_d8 = (undefined4 *)0x422537;
                XPreviewMap___CreateWalls();
                local_38 = *(float *)(local_14 + 0x10) * 2.0;
              }
              else if (local_18[*(int *)(local_14 + 8)] == '3') {
                local_c8 = local_24;
                local_cc = local_28;
                uStack_d0 = 1;
                puStack_d4 = local_30;
                puStack_d8 = (undefined4 *)0x422593;
                local_c4 = local_20;
                XPreviewMap___CreateWalls();
                local_c0 = (int *)local_1c;
                local_c4 = local_20;
                local_c8 = local_24;
                local_cc = local_28;
                uStack_d0 = 2;
                puStack_d4 = local_30;
                puStack_d8 = (undefined4 *)0x4225bf;
                XPreviewMap___CreateWalls();
                local_c0 = (int *)local_1c;
                local_c4 = local_20;
                local_c8 = local_24;
                local_cc = local_28;
                uStack_d0 = 3;
                puStack_d4 = local_30;
                puStack_d8 = (undefined4 *)0x4225eb;
                XPreviewMap___CreateWalls();
                local_38 = *(float *)(local_14 + 0x10) * 3.0;
              }
              local_c0 = (int *)0x88;
              local_c4 = 6.074789e-39;
              local_64 = FUN_0042d23e();
              local_8._0_1_ = 1;
              if (local_64 == 0) {
                local_68 = (int *)0x0;
              }
              else {
                local_c0 = *(int **)(local_14 + 0x10);
                local_c4 = *(float *)(local_14 + 0x10);
                local_c8 = *(undefined4 *)(local_14 + 4);
                local_cc = (undefined1 *)0x422645;
                local_68 = (int *)JObject3D_Rect__JObject3D_Rect();
              }
              local_80 = local_68;
              local_8 = (uint)local_8._1_3_ << 8;
              local_34 = local_68;
              local_c0 = (int *)0x3e800000;
              local_c4 = 0.5;
              local_c8 = 0;
              local_cc = (undefined1 *)0x3e800000;
              uStack_d0 = (uint)*(ushort *)(local_14 + 0x1c);
              puStack_d4 = (undefined1 *)0x4226a9;
              (**(code **)(*local_68 + 0x20))();
              puStack_d4 = (undefined1 *)local_1c;
              puStack_d8 = (undefined4 *)local_38;
              fStack_dc = local_20;
              uStack_e0 = 0x4226d5;
              puStack_d4 = (undefined1 *)_D3DVECTOR___D3DVECTOR();
              puStack_d8 = (undefined4 *)0x4226e3;
              (**(code **)(*local_34 + 4))();
              local_c0 = local_34;
              local_c4 = 6.07511e-39;
              JObject3DList__Append();
            }
          }
          else {
            local_18[*(int *)(local_14 + 8)] = 0x2d;
            local_c8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
            local_cc = local_30;
            uStack_d0 = 0x422353;
            local_c4 = local_20;
            XPreviewMap___CreateFloor();
          }
        }
        else {
          local_c8 = 0x2d;
          local_cc = local_30;
          uStack_d0 = 0x4222ed;
          local_c4 = local_20;
          XPreviewMap___CreateFloor();
        }
      }
    }
  }
  local_5c = 0;
  local_58 = 0;
  local_3c = 0;
  while( true ) {
    local_c0 = (int *)0x422721;
    uVar2 = JObject3DList__Count();
    if (uVar2 <= local_3c) break;
    local_c0 = (int *)local_3c;
    local_c4 = 6.075203e-39;
    local_6c = JObject3DList__GetAt();
    local_c0 = (int *)0x42273d;
    iVar3 = JObject3D__GetVertexCount();
    local_5c = iVar3 + local_5c;
    local_c0 = (int *)0x42274b;
    iVar3 = JObject3D__GetIndexCount();
    local_58 = iVar3 + local_58;
    local_3c = local_3c + 1;
  }
  local_c0 = (int *)0x88;
  local_c4 = 6.075264e-39;
  local_70 = FUN_0042d23e();
  local_8._0_1_ = 2;
  if (local_70 == 0) {
    local_74 = 0;
  }
  else {
    local_c0 = (int *)local_58;
    local_c4 = (float)local_5c;
    local_c8 = *(undefined4 *)(local_14 + 4);
    local_cc = (undefined1 *)0x422784;
    local_74 = JObject3D__JObject3D();
  }
  local_84 = local_74;
  local_8 = (uint)local_8._1_3_ << 8;
  *(undefined4 *)(local_14 + 0xc) = local_74;
  local_c0 = (int *)0x3f800000;
  local_c4 = 1.0;
  local_c8 = 0;
  local_cc = (undefined1 *)0x0;
  uStack_d0 = (uint)*(ushort *)(local_14 + 0x1c);
  puStack_d4 = (undefined1 *)0x4227ec;
  (**(code **)(**(int **)(local_14 + 0xc) + 0x20))();
  local_50 = 0;
  local_60 = (undefined4 *)0x0;
  local_40 = 0;
  while( true ) {
    puStack_d4 = (undefined1 *)0x422814;
    uVar2 = JObject3DList__Count();
    if (uVar2 <= local_40) break;
    puStack_d4 = (undefined1 *)local_40;
    puStack_d8 = (undefined4 *)0x422829;
    local_4c = JObject3DList__GetAt();
    local_44 = 0;
    while( true ) {
      puStack_d4 = (undefined1 *)0x422846;
      uVar2 = JObject3D__GetIndexCount();
      if (uVar2 <= local_44) break;
      puStack_d4 = (undefined1 *)local_44;
      puStack_d8 = (undefined4 *)0x422857;
      sVar1 = JObject3D__GetIndexAt();
      local_54 = sVar1 + (short)local_50;
      puStack_d4 = (undefined1 *)(uint)local_54;
      puStack_d8 = local_60;
      fStack_dc = 6.07566e-39;
      JObject3D__SetIndexAt();
      local_60 = (undefined4 *)((int)local_60 + 1);
      local_44 = local_44 + 1;
    }
    local_48 = 0;
    while( true ) {
      puStack_d4 = (undefined1 *)0x42289d;
      uVar2 = JObject3D__GetVertexCount();
      if (uVar2 <= local_48) break;
      puStack_d4 = (undefined1 *)local_48;
      puStack_d8 = local_b0;
      fStack_dc = 6.075746e-39;
      JObject3D__GetVertexAt();
      puVar4 = local_b0;
      puVar5 = auStack_f0;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      JObject3D__SetVertexAt(local_50);
      local_50 = local_50 + 1;
      local_48 = local_48 + 1;
    }
    local_40 = local_40 + 1;
  }
  local_8 = 0xffffffff;
  puStack_d4 = (undefined1 *)0x4228f5;
  JObject3DList___JObject3DList();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x422910 | Symbol: XPreviewMap::_ConvertMapItemToInt
// ============================================================================
int XPreviewMap___ConvertMapItemToInt(byte param_1)

{
  int iVar1;
  
  if ((param_1 < 0x31) || (0x33 < param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 - 0x30;
  }
  return iVar1;
}

// ============================================================================
// Address: 0x422940 | Symbol: XPreviewMap::_CreateFloor
// ============================================================================
void XPreviewMap___CreateFloor
               (undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471e6a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_0042d23e(0x88,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    local_20 = (int *)0x0;
  }
  else {
    local_20 = (int *)JObject3D_Rect__JObject3D_Rect
                                (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x10),
                                 *(undefined4 *)(in_ECX + 0x10));
  }
  local_8 = 0xffffffff;
  if (param_2 == '!') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f400000,0x3e800000,0x3f800000,0x3f000000);
  }
  else if (param_2 == '[') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0,0x3f000000,0x3e800000,0x3f400000);
  }
  else if (param_2 == '>') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3e800000,0x3f000000,0x3f000000,0x3f400000);
  }
  else if (param_2 == ']') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f000000,0x3f000000,0x3f400000,0x3f400000);
  }
  else if (param_2 == '<') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f400000,0x3f000000,0x3f800000,0x3f400000);
  }
  else if (param_2 == '#') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0,0x3e800000,0x3e800000,0x3f000000);
  }
  else if (param_2 == '=') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3e800000,0x3e800000,0x3f000000,0x3f000000);
  }
  else if (param_2 == '*') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f000000,0x3e800000,0x3f400000,0x3f000000);
  }
  else {
    (**(code **)(*local_20 + 0x20))(*(undefined2 *)(in_ECX + 0x1c),0,0,0x3e800000,0x3e800000);
  }
  uVar2 = _D3DVECTOR___D3DVECTOR(param_3,0,param_4);
  (**(code **)(*local_20 + 4))(uVar2);
  JObject3DList__Append(local_20);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x422d30 | Symbol: XPreviewMap::_CreateWalls
// ============================================================================
void XPreviewMap___CreateWalls
               (undefined4 param_1,int param_2,int param_3,int param_4,float param_5,float param_6)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int in_ECX;
  float fVar11;
  int *local_4c;
  int *local_44;
  int *local_3c;
  int *local_34;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471ed4;
  local_10 = ExceptionList;
  uVar8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  fVar11 = (float)(param_2 + -1) * *(float *)(in_ECX + 0x10) + *(float *)(in_ECX + 0x10) / 2.0;
  iVar9 = *(int *)(in_ECX + 0x14);
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar2 = *(int *)(in_ECX + 0x14);
  cVar4 = XPreviewMap___ConvertMapItemToInt
                    (*(undefined1 *)
                      (*(int *)(in_ECX + 8) + param_4 * *(int *)(in_ECX + 0x14) + -1 + param_3));
  cVar3 = (char)param_2;
  cVar5 = XPreviewMap___ConvertMapItemToInt
                    (*(undefined1 *)(*(int *)(in_ECX + 8) + param_4 * iVar9 + 1 + param_3));
  cVar6 = XPreviewMap___ConvertMapItemToInt
                    (*(undefined1 *)(*(int *)(in_ECX + 8) + (param_4 + -1) * iVar1 + param_3));
  cVar7 = XPreviewMap___ConvertMapItemToInt
                    (*(undefined1 *)(*(int *)(in_ECX + 8) + (param_4 + 1) * iVar2 + param_3));
  if ((char)(cVar4 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88,uVar8);
    local_8 = 0;
    if (iVar9 == 0) {
      local_34 = (int *)0x0;
    }
    else {
      local_34 = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x10),
                                   *(undefined4 *)(in_ECX + 0x10));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_34 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f000000,0,0x3f400000,0x3e800000);
    (**(code **)(*local_34 + 0xc))(1,0x3fc90fdb);
    (**(code **)(*local_34 + 0xc))(2,0x3fc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(param_5 - *(float *)(in_ECX + 0x10) / 2.0,fVar11,param_6);
    (**(code **)(*local_34 + 4))(uVar10);
    JObject3DList__Append(local_34);
  }
  if ((char)(cVar5 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88);
    local_8 = 1;
    if (iVar9 == 0) {
      local_3c = (int *)0x0;
    }
    else {
      local_3c = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x10),
                                   *(undefined4 *)(in_ECX + 0x10));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_3c + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f400000,0,0x3f800000,0x3e800000);
    (**(code **)(*local_3c + 0xc))(1,0xbfc90fdb);
    (**(code **)(*local_3c + 0xc))(2,0xbfc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(*(float *)(in_ECX + 0x10) / 2.0 + param_5,fVar11,param_6);
    (**(code **)(*local_3c + 4))(uVar10);
    JObject3DList__Append(local_3c);
  }
  if ((char)(cVar6 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88);
    local_8 = 2;
    if (iVar9 == 0) {
      local_44 = (int *)0x0;
    }
    else {
      local_44 = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x10),
                                   *(undefined4 *)(in_ECX + 0x10));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_44 + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f400000,0,0x3f800000,0x3e800000);
    (**(code **)(*local_44 + 0xc))(1,0x40490fdb);
    (**(code **)(*local_44 + 0xc))(0,0x3fc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(param_5,fVar11,*(float *)(in_ECX + 0x10) / 2.0 + param_6);
    (**(code **)(*local_44 + 4))(uVar10);
    JObject3DList__Append(local_44);
  }
  if ((char)(cVar7 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88);
    local_8 = 3;
    if (iVar9 == 0) {
      local_4c = (int *)0x0;
    }
    else {
      local_4c = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x10),
                                   *(undefined4 *)(in_ECX + 0x10));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_4c + 0x20))
              (*(undefined2 *)(in_ECX + 0x1c),0x3f000000,0,0x3f400000,0x3e800000);
    (**(code **)(*local_4c + 0xc))(0,0xbfc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(param_5,fVar11,param_6 - *(float *)(in_ECX + 0x10) / 2.0);
    (**(code **)(*local_4c + 4))(uVar10);
    JObject3DList__Append(local_4c);
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x423370 | Symbol: XMap::XMap
// ============================================================================
undefined4 *
XMap__XMap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = XMap::vftable;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0x42200000;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  *(undefined2 *)(in_ECX + 10) = 0;
  iVar1 = XApplication__GetCurrentWorld();
  if (iVar1 == 0) {
    *(undefined2 *)(in_ECX + 10) = 0x9c;
  }
  else {
    iVar1 = XApplication__GetCurrentWorld();
    if (iVar1 == 1) {
      *(undefined2 *)(in_ECX + 10) = 0xfb;
    }
    else {
      *(undefined2 *)(in_ECX + 10) = 0xfc;
    }
  }
  XMap___LoadMapArray(param_2);
  XMap___CreateMapObject(param_3,param_4,param_5,param_6);
  XMap___CreateBackground();
  return in_ECX;
}

// ============================================================================
// Address: 0x423470 | Symbol: XMap::~XMap
// ============================================================================
void XMap___XMap(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XMap::vftable;
  if (in_ECX[2] != 0) {
    thunk_FUN_00451f46(in_ECX[2]);
    in_ECX[2] = 0;
  }
  if (in_ECX[3] != 0) {
    thunk_FUN_00451f46(in_ECX[3]);
    in_ECX[3] = 0;
  }
  if (in_ECX[4] != 0) {
    thunk_FUN_00451f46(in_ECX[4]);
    in_ECX[4] = 0;
  }
  if (in_ECX[5] != 0) {
    if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[5])(1);
    }
    in_ECX[5] = 0;
  }
  if (in_ECX[6] != 0) {
    if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[6])(1);
    }
    in_ECX[6] = 0;
  }
  return;
}

// ============================================================================
// Address: 0x423580 | Symbol: XMap::ProcessFrame
// ============================================================================
void XMap__ProcessFrame(void)

{
  return;
}

// ============================================================================
// Address: 0x423590 | Symbol: XMap::Render
// ============================================================================
void XMap__Render(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x18) + 0x14))();
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x14))();
  return;
}

// ============================================================================
// Address: 0x4235d0 | Symbol: XMap::GetChipSize
// ============================================================================
int XMap__GetChipSize(void)

{
  int in_ECX;
  
  return in_ECX + 0x1c;
}

// ============================================================================
// Address: 0x4235f0 | Symbol: XMap::IsBlocked_Pac
// ============================================================================
undefined4 XMap__IsBlocked_Pac(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar3 = XMap___IsOutsideMap(param_1,param_2);
  if (iVar3 == 0) {
    bVar1 = *(byte *)(*(int *)(in_ECX + 8) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
    cVar2 = *(char *)(*(int *)(in_ECX + 0xc) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
    if (((bVar1 == 0x2e) || ((0x40 < bVar1 && (bVar1 < 0x5b)))) ||
       ((0x30 < bVar1 && (bVar1 < 0x34)))) {
      uVar4 = 1;
    }
    else if ((cVar2 == 'x') || (cVar2 == 'y')) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}

// ============================================================================
// Address: 0x4236a0 | Symbol: XMap::IsBlocked_Fire
// ============================================================================
undefined4 XMap__IsBlocked_Fire(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = XMap___IsOutsideMap(param_1,param_2);
  if (iVar2 == 0) {
    bVar1 = *(byte *)(*(int *)(in_ECX + 8) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
    if (((bVar1 < 0x41) || (0x5a < bVar1)) && ((bVar1 < 0x31 || (0x33 < bVar1)))) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

// ============================================================================
// Address: 0x423710 | Symbol: XMap::IsBlocked_Enemy
// ============================================================================
undefined4 XMap__IsBlocked_Enemy(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = XMap___IsOutsideMap(param_1,param_2);
  if (iVar2 == 0) {
    bVar1 = *(byte *)(*(int *)(in_ECX + 8) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
    if ((((bVar1 == 0x2e) || (bVar1 == 0x2b)) || ((0x40 < bVar1 && (bVar1 < 0x5b)))) ||
       ((0x30 < bVar1 && (bVar1 < 0x34)))) {
      uVar3 = 1;
    }
    else if (*(char *)(*(int *)(in_ECX + 0xc) + param_2 * *(int *)(in_ECX + 0x20) + param_1) == '0')
    {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

// ============================================================================
// Address: 0x4237c0 | Symbol: XMap::IsBlocked_UFO
// ============================================================================
undefined4 XMap__IsBlocked_UFO(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = XMap___IsOutsideMap(param_1,param_2);
  if (iVar2 == 0) {
    cVar1 = *(char *)(*(int *)(in_ECX + 8) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
    if (((cVar1 == '.') || (cVar1 == 'P')) || (cVar1 == '3')) {
      uVar3 = 1;
    }
    else if (*(char *)(*(int *)(in_ECX + 0x10) + param_2 * *(int *)(in_ECX + 0x20) + param_1) == '0'
            ) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

// ============================================================================
// Address: 0x423850 | Symbol: XMap::IsWarpZone
// ============================================================================
bool XMap__IsWarpZone(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  bool bVar2;
  
  iVar1 = XMap___IsOutsideMap(param_1,param_2);
  if (iVar1 == 0) {
    bVar2 = *(char *)(*(int *)(in_ECX + 8) + param_2 * *(int *)(in_ECX + 0x20) + param_1) == '*';
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}

// ============================================================================
// Address: 0x4238b0 | Symbol: XMap::IsArrow
// ============================================================================
undefined4 XMap__IsArrow(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  
  iVar2 = XMap___IsOutsideMap(param_1,param_2);
  if (iVar2 == 0) {
    cVar1 = *(char *)(*(int *)(in_ECX + 8) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
    if ((((cVar1 == '[') || (cVar1 == ']')) || (cVar1 == '<')) || (cVar1 == '>')) {
      local_10 = 1;
    }
    else {
      local_10 = 0;
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}

// ============================================================================
// Address: 0x423930 | Symbol: XMap::GetArrowDirection
// ============================================================================
undefined4 XMap__GetArrowDirection(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = XMap___IsOutsideMap(param_1,param_2);
  if (iVar2 == 0) {
    cVar1 = *(char *)(*(int *)(in_ECX + 8) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
    if (cVar1 == '[') {
      uVar3 = 0;
    }
    else if (cVar1 == '>') {
      uVar3 = 1;
    }
    else if (cVar1 == ']') {
      uVar3 = 2;
    }
    else if (cVar1 == '<') {
      uVar3 = 3;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

// ============================================================================
// Address: 0x4239c0 | Symbol: XMap::ConvertPosXToMapX
// ============================================================================
int XMap__ConvertPosXToMapX(float param_1)

{
  int in_ECX;
  
  return (int)((param_1 + ((float)*(int *)(in_ECX + 0x20) * *(float *)(in_ECX + 0x1c)) / 2.0) /
              *(float *)(in_ECX + 0x1c));
}

// ============================================================================
// Address: 0x423a10 | Symbol: XMap::ConvertPosZToMapZ
// ============================================================================
int XMap__ConvertPosZToMapZ(float param_1)

{
  int in_ECX;
  
  return (*(int *)(in_ECX + 0x24) + -1) -
         (int)((param_1 + ((float)*(int *)(in_ECX + 0x24) * *(float *)(in_ECX + 0x1c)) / 2.0) /
              *(float *)(in_ECX + 0x1c));
}

// ============================================================================
// Address: 0x423a60 | Symbol: XMap::UpdateEnemyMap
// ============================================================================
void XMap__UpdateEnemyMap(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined1 *)(*(int *)(in_ECX + 0xc) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
  *(undefined1 *)(*(int *)(in_ECX + 0xc) + param_2 * *(int *)(in_ECX + 0x20) + param_1) = 0x30;
  *(undefined1 *)(*(int *)(in_ECX + 0xc) + param_4 * *(int *)(in_ECX + 0x20) + param_3) = uVar1;
  return;
}

// ============================================================================
// Address: 0x423ac0 | Symbol: XMap::ZeroEnemyMap
// ============================================================================
void XMap__ZeroEnemyMap(int param_1,int param_2)

{
  int in_ECX;
  
  *(undefined1 *)(*(int *)(in_ECX + 0xc) + param_2 * *(int *)(in_ECX + 0x20) + param_1) = 0x30;
  return;
}

// ============================================================================
// Address: 0x423af0 | Symbol: XMap::UpdateUFOMap
// ============================================================================
void XMap__UpdateUFOMap(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined1 *)(*(int *)(in_ECX + 0x10) + param_2 * *(int *)(in_ECX + 0x20) + param_1);
  *(undefined1 *)(*(int *)(in_ECX + 0x10) + param_2 * *(int *)(in_ECX + 0x20) + param_1) = 0x30;
  *(undefined1 *)(*(int *)(in_ECX + 0x10) + param_4 * *(int *)(in_ECX + 0x20) + param_3) = uVar1;
  return;
}

// ============================================================================
// Address: 0x423b50 | Symbol: XMap::_LoadMapArray
// ============================================================================
void XMap___LoadMapArray(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined1 local_68 [16];
  SchedulerBase local_58 [24];
  InternalContextBase local_40 [8];
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471f19;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JStringList__JStringList(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  JStringList__JStringList();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_38 = GetStringListFromResource(local_68,param_1);
  local_24 = 0;
  do {
    uVar1 = JStringList__Count();
    if (uVar1 <= local_24) {
LAB_00423c2e:
      local_8 = local_8 & 0xffffff00;
      JStringList___JStringList();
      *(undefined4 *)(local_14 + 0x20) = 0;
      local_1c = 0;
      while( true ) {
        uVar1 = JStringList__Count();
        if (uVar1 <= local_1c) break;
        JStringList__GetString(local_1c);
        uVar1 = JString__Length();
        if (*(uint *)(local_14 + 0x20) < uVar1) {
          JStringList__GetString(local_1c);
          uVar2 = JString__Length();
          *(undefined4 *)(local_14 + 0x20) = uVar2;
        }
        local_1c = local_1c + 1;
      }
      *(int *)(local_14 + 0x20) = *(int *)(local_14 + 0x20) + 2;
      iVar3 = JStringList__Count();
      *(int *)(local_14 + 0x24) = iVar3 + 2;
      local_28 = FUN_0042d2b4(*(int *)(local_14 + 0x24) * *(int *)(local_14 + 0x20));
      *(undefined4 *)(local_14 + 8) = local_28;
      _memset(*(void **)(local_14 + 8),0x2e,*(int *)(local_14 + 0x24) * *(int *)(local_14 + 0x20));
      local_2c = FUN_0042d2b4(*(int *)(local_14 + 0x24) * *(int *)(local_14 + 0x20));
      *(undefined4 *)(local_14 + 0xc) = local_2c;
      _memset(*(void **)(local_14 + 0xc),0x30,*(int *)(local_14 + 0x24) * *(int *)(local_14 + 0x20))
      ;
      local_30 = FUN_0042d2b4(*(int *)(local_14 + 0x24) * *(int *)(local_14 + 0x20));
      *(undefined4 *)(local_14 + 0x10) = local_30;
      _memset(*(void **)(local_14 + 0x10),0x30,*(int *)(local_14 + 0x24) * *(int *)(local_14 + 0x20)
             );
      for (local_20 = 1; local_20 < *(int *)(local_14 + 0x24) + -1; local_20 = local_20 + 1) {
        for (local_18 = 1; local_18 < *(int *)(local_14 + 0x20) + -1; local_18 = local_18 + 1) {
          local_34 = local_20 * *(int *)(local_14 + 0x20) + local_18;
          uVar2 = JStringList__GetString(local_20 + -1);
          FUN_00413a80(uVar2);
          local_8 = CONCAT31(local_8._1_3_,3);
          uVar5 = local_18 - 1;
          uVar1 = JString__Length();
          if (uVar5 < uVar1) {
            iVar3 = JString__c_str();
            *(undefined1 *)(*(int *)(local_14 + 8) + local_34) =
                 *(undefined1 *)(iVar3 + -1 + local_18);
          }
          local_8 = local_8 & 0xffffff00;
          JString___JString();
        }
      }
      local_8 = 0xffffffff;
      JStringList___JStringList();
      ExceptionList = local_10;
      return;
    }
    uVar2 = JStringList__GetString(local_24);
    FUN_00413a80(uVar2);
    local_8._0_1_ = 2;
    iVar3 = JString__Length();
    if (iVar3 == 0) {
LAB_00423c12:
      local_8 = CONCAT31(local_8._1_3_,1);
      JString___JString();
      goto LAB_00423c2e;
    }
    pcVar4 = (char *)JString__c_str();
    if (*pcVar4 == '_') goto LAB_00423c12;
    Concurrency::details::SchedulerBase::JStringList__Append(local_58,local_40);
    local_8 = CONCAT31(local_8._1_3_,1);
    JString___JString();
    local_24 = local_24 + 1;
  } while( true );
}

// ============================================================================
// Address: 0x423e50 | Symbol: XMap::_CreateMapObject
// ============================================================================
void XMap___CreateMapObject(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStack_100 [4];
  undefined4 uStack_f0;
  float fStack_ec;
  undefined4 *puStack_e8;
  undefined1 *puStack_e4;
  uint uStack_e0;
  undefined1 *local_dc;
  uint local_d8;
  undefined1 *local_d4;
  int *local_d0;
  uint uStack_cc;
  undefined4 local_c0 [11];
  undefined4 local_94;
  int *local_90;
  float local_8c;
  float local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  int *local_74;
  int local_70;
  ushort local_6c;
  undefined4 *local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  float local_3c;
  int local_38;
  int *local_34;
  undefined1 local_30 [8];
  float local_28;
  float local_24;
  undefined1 *local_20;
  uint local_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471f67;
  local_10 = ExceptionList;
  uStack_cc = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_88 = ((float)*(int *)(in_ECX + 0x20) * *(float *)(in_ECX + 0x1c)) / 2.0;
  local_8c = ((float)*(int *)(in_ECX + 0x24) * *(float *)(in_ECX + 0x1c)) / 2.0;
  local_d0 = (int *)0x423ec5;
  local_14 = in_ECX;
  JObject3DList__JObject3DList();
  local_8 = 0;
  for (local_1c = 0; (int)local_1c < *(int *)(local_14 + 0x24); local_1c = local_1c + 1) {
    for (local_20 = (undefined1 *)0x0; (int)local_20 < *(int *)(local_14 + 0x20);
        local_20 = local_20 + 1) {
      local_18 = local_20 + local_1c * *(int *)(local_14 + 0x20);
      local_28 = ((float)(int)local_20 * *(float *)(local_14 + 0x1c) +
                 *(float *)(local_14 + 0x1c) / 2.0) - local_88;
      local_24 = ((float)(int)(*(int *)(local_14 + 0x24) - local_1c) * *(float *)(local_14 + 0x1c) -
                 *(float *)(local_14 + 0x1c) / 2.0) - local_8c;
      if (local_18[*(int *)(local_14 + 8)] != '.') {
        if (local_18[*(int *)(local_14 + 8)] == '@') {
          local_d4 = (undefined1 *)0x0;
          local_d8 = 0x423fc0;
          local_d0 = (int *)local_28;
          FUN_0040f750();
          local_d0 = (int *)local_24;
          local_d4 = (undefined1 *)0x2;
          local_d8 = 0x423fd5;
          FUN_0040f750();
          local_d0 = (int *)local_1c;
          local_d4 = local_20;
          local_d8 = 0x423fe5;
          XPac__SetMapPos();
          local_18[*(int *)(local_14 + 8)] = 0x2d;
          local_d0 = (int *)local_24;
          local_d4 = (undefined1 *)local_28;
          local_d8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
          local_dc = local_30;
          uStack_e0 = 0x424022;
          XMap___CreateFloor();
        }
        else if (local_18[*(int *)(local_14 + 8)] == '$') {
          local_d0 = (int *)0x424041;
          local_84 = XCrystalList__CreateCrystal();
          local_d0 = (int *)local_28;
          local_d4 = (undefined1 *)0x0;
          local_d8 = 0x424059;
          FUN_0040f750();
          local_d0 = (int *)local_24;
          local_d4 = (undefined1 *)0x2;
          local_d8 = 0x42406e;
          FUN_0040f750();
          local_18[*(int *)(local_14 + 8)] = 0x2d;
          local_d0 = (int *)local_24;
          local_d4 = (undefined1 *)local_28;
          local_d8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
          local_dc = local_30;
          uStack_e0 = 0x4240ab;
          XMap___CreateFloor();
        }
        else if (((byte)local_18[*(int *)(local_14 + 8)] < 0x41) ||
                (0x5a < (byte)local_18[*(int *)(local_14 + 8)])) {
          if (((byte)local_18[*(int *)(local_14 + 8)] < 0x61) ||
             (0x7a < (byte)local_18[*(int *)(local_14 + 8)])) {
            local_d0 = (int *)local_24;
            if ((((((local_18[*(int *)(local_14 + 8)] == '-') ||
                   (local_18[*(int *)(local_14 + 8)] == '+')) ||
                  (local_18[*(int *)(local_14 + 8)] == '!')) ||
                 ((local_18[*(int *)(local_14 + 8)] == '[' ||
                  (local_18[*(int *)(local_14 + 8)] == ']')))) ||
                (local_18[*(int *)(local_14 + 8)] == '>')) ||
               (((local_18[*(int *)(local_14 + 8)] == '<' ||
                 (local_18[*(int *)(local_14 + 8)] == '#')) ||
                ((local_18[*(int *)(local_14 + 8)] == '=' ||
                 (local_18[*(int *)(local_14 + 8)] == '*')))))) {
              local_d8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
              local_dc = local_30;
              uStack_e0 = 0x42443f;
              local_d4 = (undefined1 *)local_28;
              XMap___CreateFloor();
              if (local_18[*(int *)(local_14 + 8)] == '!') {
                local_d0 = (int *)(uint)(byte)local_18[*(int *)(local_14 + 8)];
                local_d4 = (undefined1 *)0x424467;
                local_5c = XMapObjectList__CreateMapObject();
                if (local_5c != 0) {
                  local_d0 = (int *)local_28;
                  local_d4 = (undefined1 *)0x0;
                  local_d8 = 0x424485;
                  FUN_0040f750();
                  local_d0 = (int *)local_24;
                  local_d4 = (undefined1 *)0x2;
                  local_d8 = 0x42449a;
                  FUN_0040f750();
                }
              }
            }
            else if ((0x30 < (byte)local_18[*(int *)(local_14 + 8)]) &&
                    ((byte)local_18[*(int *)(local_14 + 8)] < 0x34)) {
              local_3c = 0.0;
              if (local_18[*(int *)(local_14 + 8)] == '1') {
                local_d8 = local_1c;
                local_dc = local_20;
                uStack_e0 = 1;
                puStack_e4 = local_30;
                puStack_e8 = (undefined4 *)0x424511;
                local_d4 = (undefined1 *)local_28;
                XMap___CreateWalls();
                local_3c = *(float *)(local_14 + 0x1c);
              }
              else if (local_18[*(int *)(local_14 + 8)] == '2') {
                local_d8 = local_1c;
                local_dc = local_20;
                uStack_e0 = 1;
                puStack_e4 = local_30;
                puStack_e8 = (undefined4 *)0x424561;
                local_d4 = (undefined1 *)local_28;
                XMap___CreateWalls();
                local_d0 = (int *)local_24;
                local_d4 = (undefined1 *)local_28;
                local_d8 = local_1c;
                local_dc = local_20;
                uStack_e0 = 2;
                puStack_e4 = local_30;
                puStack_e8 = (undefined4 *)0x42458d;
                XMap___CreateWalls();
                local_3c = *(float *)(local_14 + 0x1c) * 2.0;
              }
              else if (local_18[*(int *)(local_14 + 8)] == '3') {
                local_d8 = local_1c;
                local_dc = local_20;
                uStack_e0 = 1;
                puStack_e4 = local_30;
                puStack_e8 = (undefined4 *)0x4245e9;
                local_d4 = (undefined1 *)local_28;
                XMap___CreateWalls();
                local_d0 = (int *)local_24;
                local_d4 = (undefined1 *)local_28;
                local_d8 = local_1c;
                local_dc = local_20;
                uStack_e0 = 2;
                puStack_e4 = local_30;
                puStack_e8 = (undefined4 *)0x424615;
                XMap___CreateWalls();
                local_d0 = (int *)local_24;
                local_d4 = (undefined1 *)local_28;
                local_d8 = local_1c;
                local_dc = local_20;
                uStack_e0 = 3;
                puStack_e4 = local_30;
                puStack_e8 = (undefined4 *)0x424641;
                XMap___CreateWalls();
                local_3c = *(float *)(local_14 + 0x1c) * 3.0;
              }
              local_d0 = (int *)0x88;
              local_d4 = (undefined1 *)0x424660;
              local_70 = FUN_0042d23e();
              local_8._0_1_ = 1;
              if (local_70 == 0) {
                local_74 = (int *)0x0;
              }
              else {
                local_d0 = *(int **)(local_14 + 0x1c);
                local_d4 = *(undefined1 **)(local_14 + 0x1c);
                local_d8 = *(undefined4 *)(local_14 + 4);
                local_dc = (undefined1 *)0x42469b;
                local_74 = (int *)JObject3D_Rect__JObject3D_Rect();
              }
              local_90 = local_74;
              local_8 = (uint)local_8._1_3_ << 8;
              local_34 = local_74;
              local_d0 = (int *)0x3e800000;
              local_d4 = (undefined1 *)0x3f000000;
              local_d8 = 0;
              local_dc = (undefined1 *)0x3e800000;
              uStack_e0 = (uint)*(ushort *)(local_14 + 0x28);
              puStack_e4 = (undefined1 *)0x424705;
              (**(code **)(*local_74 + 0x20))();
              puStack_e4 = (undefined1 *)local_24;
              puStack_e8 = (undefined4 *)local_3c;
              fStack_ec = local_28;
              uStack_f0 = 0x424731;
              puStack_e4 = (undefined1 *)_D3DVECTOR___D3DVECTOR();
              puStack_e8 = (undefined4 *)0x42473f;
              (**(code **)(*local_34 + 4))();
              local_d0 = local_34;
              local_d4 = (undefined1 *)0x42474b;
              JObject3DList__Append();
            }
          }
          else {
            local_d0 = (int *)(uint)(byte)local_18[*(int *)(local_14 + 8)];
            local_d4 = (undefined1 *)0x424288;
            local_58 = XEnemyList__CreateEnemy();
            local_d0 = (int *)local_28;
            local_d4 = (undefined1 *)0x0;
            local_d8 = 0x4242a0;
            FUN_0040f750();
            local_d0 = (int *)local_24;
            local_d4 = (undefined1 *)0x2;
            local_d8 = 0x4242b5;
            FUN_0040f750();
            local_d0 = (int *)local_1c;
            local_d4 = local_20;
            local_d8 = 0x4242c5;
            XEnemyBase__SetMapPos();
            if (local_18[*(int *)(local_14 + 8)] == 'd') {
              local_18[*(int *)(local_14 + 0x10)] = local_18[*(int *)(local_14 + 8)];
            }
            else {
              local_18[*(int *)(local_14 + 0xc)] = local_18[*(int *)(local_14 + 8)];
            }
            local_18[*(int *)(local_14 + 8)] = 0x2d;
            local_d0 = (int *)local_24;
            local_d4 = (undefined1 *)local_28;
            local_d8 = (uint)(byte)local_18[*(int *)(local_14 + 8)];
            local_dc = local_30;
            uStack_e0 = 0x424346;
            XMap___CreateFloor();
          }
        }
        else {
          local_d0 = (int *)(uint)(byte)local_18[*(int *)(local_14 + 8)];
          local_d4 = (undefined1 *)0x4240f2;
          local_54 = XMapObjectList__CreateMapObject();
          if (local_54 != 0) {
            local_d0 = (int *)local_28;
            local_d4 = (undefined1 *)0x0;
            local_d8 = 0x424110;
            FUN_0040f750();
            local_d0 = (int *)local_24;
            local_d4 = (undefined1 *)0x2;
            local_d8 = 0x424125;
            FUN_0040f750();
          }
          local_d0 = (int *)local_24;
          local_d4 = (undefined1 *)local_28;
          local_d8 = 0x2d;
          local_dc = local_30;
          uStack_e0 = 0x424149;
          XMap___CreateFloor();
          if (local_18[*(int *)(local_14 + 8)] == 'V') {
            local_20[*(int *)(local_14 + 8) + (local_1c - 1) * *(int *)(local_14 + 0x20) + -1] =
                 0x5a;
            local_20[*(int *)(local_14 + 8) + (local_1c - 1) * *(int *)(local_14 + 0x20)] = 0x5a;
            local_20[*(int *)(local_14 + 8) + (local_1c - 1) * *(int *)(local_14 + 0x20) + 1] = 0x5a
            ;
            local_20[*(int *)(local_14 + 8) + local_1c * *(int *)(local_14 + 0x20) + -1] = 0x5a;
            local_20[*(int *)(local_14 + 8) + local_1c * *(int *)(local_14 + 0x20) + 1] = 0x5a;
            local_20[*(int *)(local_14 + 8) + (local_1c + 1) * *(int *)(local_14 + 0x20) + -1] =
                 0x5a;
            local_20[*(int *)(local_14 + 8) + (local_1c + 1) * *(int *)(local_14 + 0x20)] = 0x5a;
            local_20[*(int *)(local_14 + 8) + (local_1c + 1) * *(int *)(local_14 + 0x20) + 1] = 0x5a
            ;
          }
        }
      }
    }
  }
  local_64 = 0;
  local_60 = 0;
  local_40 = 0;
  while( true ) {
    local_d0 = (int *)0x42477d;
    uVar2 = JObject3DList__Count();
    if (uVar2 <= local_40) break;
    local_d0 = (int *)local_40;
    local_d4 = (undefined1 *)0x42478e;
    local_78 = JObject3DList__GetAt();
    local_d0 = (int *)0x424799;
    iVar3 = JObject3D__GetVertexCount();
    local_64 = iVar3 + local_64;
    local_d0 = (int *)0x4247a7;
    iVar3 = JObject3D__GetIndexCount();
    local_60 = iVar3 + local_60;
    local_40 = local_40 + 1;
  }
  local_d0 = (int *)0x88;
  local_d4 = (undefined1 *)0x4247b9;
  local_7c = FUN_0042d23e();
  local_8._0_1_ = 2;
  if (local_7c == 0) {
    local_80 = 0;
  }
  else {
    local_d0 = (int *)local_60;
    local_d4 = (undefined1 *)local_64;
    local_d8 = *(undefined4 *)(local_14 + 4);
    local_dc = (undefined1 *)0x4247e0;
    local_80 = JObject3D__JObject3D();
  }
  local_94 = local_80;
  local_8 = (uint)local_8._1_3_ << 8;
  *(undefined4 *)(local_14 + 0x14) = local_80;
  local_d0 = (int *)0x3f800000;
  local_d4 = (undefined1 *)0x3f800000;
  local_d8 = 0;
  local_dc = (undefined1 *)0x0;
  uStack_e0 = (uint)*(ushort *)(local_14 + 0x28);
  puStack_e4 = (undefined1 *)0x42484e;
  (**(code **)(**(int **)(local_14 + 0x14) + 0x20))();
  local_38 = 0;
  local_68 = (undefined4 *)0x0;
  local_44 = 0;
  while( true ) {
    puStack_e4 = (undefined1 *)0x424876;
    uVar2 = JObject3DList__Count();
    if (uVar2 <= local_44) break;
    puStack_e4 = (undefined1 *)local_44;
    puStack_e8 = (undefined4 *)0x42488b;
    local_50 = JObject3DList__GetAt();
    local_48 = 0;
    while( true ) {
      puStack_e4 = (undefined1 *)0x4248a8;
      uVar2 = JObject3D__GetIndexCount();
      if (uVar2 <= local_48) break;
      puStack_e4 = (undefined1 *)local_48;
      puStack_e8 = (undefined4 *)0x4248b9;
      sVar1 = JObject3D__GetIndexAt();
      local_6c = sVar1 + (short)local_38;
      puStack_e4 = (undefined1 *)(uint)local_6c;
      puStack_e8 = local_68;
      fStack_ec = 6.087277e-39;
      JObject3D__SetIndexAt();
      local_68 = (undefined4 *)((int)local_68 + 1);
      local_48 = local_48 + 1;
    }
    local_4c = 0;
    while( true ) {
      puStack_e4 = (undefined1 *)0x4248ff;
      uVar2 = JObject3D__GetVertexCount();
      if (uVar2 <= local_4c) break;
      puStack_e4 = (undefined1 *)local_4c;
      puStack_e8 = local_c0;
      fStack_ec = 6.087362e-39;
      JObject3D__GetVertexAt();
      puVar4 = local_c0;
      puVar5 = auStack_100;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      JObject3D__SetVertexAt(local_38);
      local_38 = local_38 + 1;
      local_4c = local_4c + 1;
    }
    local_44 = local_44 + 1;
  }
  local_8 = 0xffffffff;
  puStack_e4 = (undefined1 *)0x424957;
  JObject3DList___JObject3DList();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x424970 | Symbol: XMap::_CreateBackground
// ============================================================================
void XMap___CreateBackground(void)

{
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471f9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00403f60(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  FUN_00403f60();
  (**(code **)(**(int **)(local_14 + 0x14) + 0x10))(local_40,local_34);
  local_24 = (float)(*(int *)(local_14 + 0x20) + 4) * *(float *)(local_14 + 0x1c);
  local_20 = (float)(*(int *)(local_14 + 0x24) + 4) * *(float *)(local_14 + 0x1c);
  local_18 = FUN_0042d23e(0x88);
  local_8 = 0;
  if (local_18 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JObject3D_Rect__JObject3D_Rect(*(undefined4 *)(local_14 + 4),local_24,local_20);
  }
  local_28 = local_1c;
  local_8 = 0xffffffff;
  *(undefined4 *)(local_14 + 0x18) = local_1c;
  FUN_0040f7e0(1,0xc2c80000);
  (**(code **)(**(int **)(local_14 + 0x18) + 0x20))
            (0xc1,0,0,(float)(*(int *)(local_14 + 0x20) + 4),(float)(*(int *)(local_14 + 0x24) + 4))
  ;
  JObject3D__UsePerspective(1);
  JObject3D__SetFilterState(2);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x424af0 | Symbol: XMap::_ConvertMapItemToInt
// ============================================================================
int XMap___ConvertMapItemToInt(byte param_1)

{
  int iVar1;
  
  if ((param_1 < 0x31) || (0x33 < param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 - 0x30;
  }
  return iVar1;
}

// ============================================================================
// Address: 0x424b20 | Symbol: XMap::_CreateFloor
// ============================================================================
void XMap___CreateFloor(undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471fd2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_0042d23e(0x88,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    local_20 = (int *)0x0;
  }
  else {
    local_20 = (int *)JObject3D_Rect__JObject3D_Rect
                                (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x1c),
                                 *(undefined4 *)(in_ECX + 0x1c));
  }
  local_8 = 0xffffffff;
  if (param_2 == '!') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f400000,0x3e800000,0x3f800000,0x3f000000);
  }
  else if (param_2 == '[') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0,0x3f000000,0x3e800000,0x3f400000);
  }
  else if (param_2 == '>') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3e800000,0x3f000000,0x3f000000,0x3f400000);
  }
  else if (param_2 == ']') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f000000,0x3f000000,0x3f400000,0x3f400000);
  }
  else if (param_2 == '<') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f400000,0x3f000000,0x3f800000,0x3f400000);
  }
  else if (param_2 == '#') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0,0x3e800000,0x3e800000,0x3f000000);
  }
  else if (param_2 == '=') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3e800000,0x3e800000,0x3f000000,0x3f000000);
  }
  else if (param_2 == '*') {
    (**(code **)(*local_20 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f000000,0x3e800000,0x3f400000,0x3f000000);
  }
  else {
    (**(code **)(*local_20 + 0x20))(*(undefined2 *)(in_ECX + 0x28),0,0,0x3e800000,0x3e800000);
  }
  uVar2 = _D3DVECTOR___D3DVECTOR(param_3,0,param_4);
  (**(code **)(*local_20 + 4))(uVar2);
  JObject3DList__Append(local_20);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x424f10 | Symbol: XMap::_CreateWalls
// ============================================================================
void XMap___CreateWalls(undefined4 param_1,int param_2,int param_3,int param_4,float param_5,
                       float param_6)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int in_ECX;
  float fVar11;
  int *local_4c;
  int *local_44;
  int *local_3c;
  int *local_34;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047203c;
  local_10 = ExceptionList;
  uVar8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  fVar11 = (float)(param_2 + -1) * *(float *)(in_ECX + 0x1c) + *(float *)(in_ECX + 0x1c) / 2.0;
  iVar9 = *(int *)(in_ECX + 0x20);
  iVar1 = *(int *)(in_ECX + 0x20);
  iVar2 = *(int *)(in_ECX + 0x20);
  cVar4 = XMap___ConvertMapItemToInt
                    (*(undefined1 *)
                      (*(int *)(in_ECX + 8) + param_4 * *(int *)(in_ECX + 0x20) + -1 + param_3));
  cVar3 = (char)param_2;
  cVar5 = XMap___ConvertMapItemToInt
                    (*(undefined1 *)(*(int *)(in_ECX + 8) + param_4 * iVar9 + 1 + param_3));
  cVar6 = XMap___ConvertMapItemToInt
                    (*(undefined1 *)(*(int *)(in_ECX + 8) + (param_4 + -1) * iVar1 + param_3));
  cVar7 = XMap___ConvertMapItemToInt
                    (*(undefined1 *)(*(int *)(in_ECX + 8) + (param_4 + 1) * iVar2 + param_3));
  if ((char)(cVar4 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88,uVar8);
    local_8 = 0;
    if (iVar9 == 0) {
      local_34 = (int *)0x0;
    }
    else {
      local_34 = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x1c),
                                   *(undefined4 *)(in_ECX + 0x1c));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_34 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f000000,0,0x3f400000,0x3e800000);
    (**(code **)(*local_34 + 0xc))(1,0x3fc90fdb);
    (**(code **)(*local_34 + 0xc))(2,0x3fc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(param_5 - *(float *)(in_ECX + 0x1c) / 2.0,fVar11,param_6);
    (**(code **)(*local_34 + 4))(uVar10);
    JObject3DList__Append(local_34);
  }
  if ((char)(cVar5 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88);
    local_8 = 1;
    if (iVar9 == 0) {
      local_3c = (int *)0x0;
    }
    else {
      local_3c = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x1c),
                                   *(undefined4 *)(in_ECX + 0x1c));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_3c + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f400000,0,0x3f800000,0x3e800000);
    (**(code **)(*local_3c + 0xc))(1,0xbfc90fdb);
    (**(code **)(*local_3c + 0xc))(2,0xbfc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(*(float *)(in_ECX + 0x1c) / 2.0 + param_5,fVar11,param_6);
    (**(code **)(*local_3c + 4))(uVar10);
    JObject3DList__Append(local_3c);
  }
  if ((char)(cVar6 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88);
    local_8 = 2;
    if (iVar9 == 0) {
      local_44 = (int *)0x0;
    }
    else {
      local_44 = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x1c),
                                   *(undefined4 *)(in_ECX + 0x1c));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_44 + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f400000,0,0x3f800000,0x3e800000);
    (**(code **)(*local_44 + 0xc))(1,0x40490fdb);
    (**(code **)(*local_44 + 0xc))(0,0x3fc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(param_5,fVar11,*(float *)(in_ECX + 0x1c) / 2.0 + param_6);
    (**(code **)(*local_44 + 4))(uVar10);
    JObject3DList__Append(local_44);
  }
  if ((char)(cVar7 - cVar3) < '\0') {
    iVar9 = FUN_0042d23e(0x88);
    local_8 = 3;
    if (iVar9 == 0) {
      local_4c = (int *)0x0;
    }
    else {
      local_4c = (int *)JObject3D_Rect__JObject3D_Rect
                                  (*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x1c),
                                   *(undefined4 *)(in_ECX + 0x1c));
    }
    local_8 = 0xffffffff;
    (**(code **)(*local_4c + 0x20))
              (*(undefined2 *)(in_ECX + 0x28),0x3f000000,0,0x3f400000,0x3e800000);
    (**(code **)(*local_4c + 0xc))(0,0xbfc90fdb);
    uVar10 = _D3DVECTOR___D3DVECTOR(param_5,fVar11,param_6 - *(float *)(in_ECX + 0x1c) / 2.0);
    (**(code **)(*local_4c + 4))(uVar10);
    JObject3DList__Append(local_4c);
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x425550 | Symbol: XMap::_IsOutsideMap
// ============================================================================
undefined4 XMap___IsOutsideMap(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((param_1 < 0) || (*(int *)(in_ECX + 0x20) <= param_1)) {
    uVar1 = 1;
  }
  else if ((param_2 < 0) || (*(int *)(in_ECX + 0x24) <= param_2)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x425590 | Symbol: XCamera::
// ============================================================================
undefined4 XCamera__(uint param_1)

{
  undefined4 in_ECX;
  
  XCamera___XCamera();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x78);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x4255c0 | Symbol: XMap::
// ============================================================================
undefined4 XMap__(uint param_1)

{
  undefined4 in_ECX;
  
  XMap___XMap();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x2c);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x4255f0 | Symbol: XPreviewMap::
// ============================================================================
undefined4 XPreviewMap__(uint param_1)

{
  undefined4 in_ECX;
  
  XPreviewMap___XPreviewMap();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x20);
  }
  return in_ECX;
}
