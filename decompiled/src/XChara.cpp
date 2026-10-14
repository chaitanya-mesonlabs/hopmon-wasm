// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XChara.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XChara.h"

// ============================================================================
// Address: 0x417900 | Symbol: XCrystalList::XCrystalList
// ============================================================================
undefined4 * XCrystalList__XCrystalList(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_c;
  
  *in_ECX = XCrystalList::vftable;
  in_ECX[1] = param_1;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  for (local_c = 0; local_c < 0x1e; local_c = local_c + 1) {
    in_ECX[local_c + 2] = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x417970 | Symbol: XCrystalList::~XCrystalList
// ============================================================================
void XCrystalList___XCrystalList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00471410;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XCrystalList::vftable;
  XCrystalList__Empty(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x4179c0 | Symbol: XCrystalList::CreateCrystal
// ============================================================================
undefined4 XCrystalList__CreateCrystal(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471444;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = XCrystalList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    uVar3 = 0;
  }
  else {
    *(int *)(in_ECX + 0x84) = *(int *)(in_ECX + 0x84) + 1;
    iVar2 = FUN_0042d23e(0x88);
    local_8 = 0;
    if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = XCrystal__XCrystal(*(undefined4 *)(in_ECX + 4));
    }
    *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_20;
    uVar3 = *(undefined4 *)(in_ECX + 8 + iVar1 * 4);
  }
  ExceptionList = local_10;
  return uVar3;
}

// ============================================================================
// Address: 0x417a80 | Symbol: XCrystalList::Empty
// ============================================================================
void XCrystalList__Empty(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int local_8;
  
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      puVar1 = *(undefined4 **)(in_ECX + 8 + local_8 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      *(undefined4 *)(in_ECX + 8 + local_8 * 4) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x417b10 | Symbol: XCrystalList::CheckCollisionWithPac
// ============================================================================
void XCrystalList__CheckCollisionWithPac(void)

{
  int iVar1;
  int in_ECX;
  int local_c;
  
  iVar1 = XPac__GetState();
  if ((((iVar1 != 0) && (iVar1 = XPac__GetState(), iVar1 != 4)) &&
      (iVar1 = XPac__GetState(), iVar1 != 5)) && (iVar1 = XPac__GetState(), iVar1 != 1)) {
    for (local_c = 0; local_c < 0x1e; local_c = local_c + 1) {
      if (((*(int *)(in_ECX + 8 + local_c * 4) != 0) && (iVar1 = XCrystal__GetState(), iVar1 == 1))
         && (iVar1 = JObject3DBase__CheckCollisionRadius(*(undefined4 *)(in_ECX + 8 + local_c * 4)),
            iVar1 != 0)) {
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + 1;
        XCrystal__StartTaken(*(undefined4 *)(in_ECX + 0x80));
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x417c10 | Symbol: XCrystalList::DoVanishCrystal
// ============================================================================
void XCrystalList__DoVanishCrystal(void)

{
  int iVar1;
  int in_ECX;
  int local_c;
  
  if (0 < *(int *)(in_ECX + 0x80)) {
    for (local_c = 0; local_c < 0x1e; local_c = local_c + 1) {
      if (((*(int *)(in_ECX + 8 + local_c * 4) != 0) && (iVar1 = XCrystal__GetState(), iVar1 == 2))
         && (iVar1 = XCrystal__GetTakenPosition(), iVar1 == *(int *)(in_ECX + 0x80))) {
        XCrystal__StartVanishing();
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + -1;
        *(int *)(in_ECX + 0x84) = *(int *)(in_ECX + 0x84) + -1;
        return;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x417cd0 | Symbol: XCrystalList::StartGameOver
// ============================================================================
void XCrystalList__StartGameOver(void)

{
  int iVar1;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if ((*(int *)(in_ECX + 8 + local_8 * 4) != 0) && (iVar1 = XCrystal__GetState(), iVar1 == 2)) {
      XCrystal__StartGameOver();
      *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + -1;
    }
  }
  return;
}

// ============================================================================
// Address: 0x417d40 | Symbol: XCrystalList::GetTakenCount
// ============================================================================
undefined4 XCrystalList__GetTakenCount(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x80);
}

// ============================================================================
// Address: 0x417d60 | Symbol: XCrystalList::GetCrystalLeft
// ============================================================================
undefined4 XCrystalList__GetCrystalLeft(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x84);
}

// ============================================================================
// Address: 0x417d80 | Symbol: XCrystalList::ProcessRotate
// ============================================================================
void XCrystalList__ProcessRotate(undefined4 param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      XCrystal__ProcessRotate(param_1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x417dd0 | Symbol: XCrystalList::ProcessFrame
// ============================================================================
void XCrystalList__ProcessFrame(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      XCrystal__ProcessFrame();
      iVar2 = XCrystal__GetState();
      if (iVar2 == 0) {
        puVar1 = *(undefined4 **)(in_ECX + 8 + local_8 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(in_ECX + 8 + local_8 * 4) = 0;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x417e70 | Symbol: XCrystalList::Render
// ============================================================================
void XCrystalList__Render(void)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x14))();
    }
  }
  return;
}

// ============================================================================
// Address: 0x417ec0 | Symbol: XCrystalList::GetNullIndex
// ============================================================================
int XCrystalList__GetNullIndex(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x1d < local_8) {
      return -1;
    }
    if (*(int *)(in_ECX + 8 + local_8 * 4) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x417f00 | Symbol: XCrystal::XCrystal
// ============================================================================
undefined4 * XCrystal__XCrystal(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471480;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  JObject3DX__JObject3DX(*(undefined4 *)(param_1 + 4),0xab);
  local_8 = 0;
  *in_ECX = XCrystal::vftable;
  in_ECX[0x17] = param_1;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  iVar2 = FUN_0042d23e(0x88,uVar1);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JObject3D_Shadow__JObject3D_Shadow
                         (*(undefined4 *)(param_1 + 4),0x41a00000,0x41a00000);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x1a] = local_1c;
  in_ECX[0x1b] = 0;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  _D3DVECTOR___D3DVECTOR(0,0,0);
  (**(code **)(*(int *)in_ECX[0x1a] + 0x20))(0xa3,0,0,0x3f800000,0x3f800000);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x41f00000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x41f00000);
  JObject3DBase__SetCollisionRadius(0x41000000);
  JObject3DX__SetFlatShade(1);
  in_ECX[0x18] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x418100 | Symbol: XCrystal::~XCrystal
// ============================================================================
void XCrystal___XCrystal(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XCrystal::vftable;
  if (in_ECX[0x1a] != 0) {
    if ((undefined4 *)in_ECX[0x1a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x1a])(1);
    }
    in_ECX[0x1a] = 0;
  }
  JObject3DX___JObject3DX();
  return;
}

// ============================================================================
// Address: 0x418160 | Symbol: XCrystal::Render
// ============================================================================
void XCrystal__Render(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) != 0) {
    JObject3DX__Render();
    if (*(int *)(in_ECX + 0x60) == 1) {
      uVar1 = _D3DVECTOR___D3DVECTOR
                        (*(undefined4 *)(in_ECX + 8),0x3f800000,*(undefined4 *)(in_ECX + 0x10));
      JObject3DBase__SetWorldPos(uVar1);
      (**(code **)(**(int **)(in_ECX + 0x68) + 0x14))();
    }
  }
  return;
}

// ============================================================================
// Address: 0x4181e0 | Symbol: XCrystal::GetState
// ============================================================================
undefined4 XCrystal__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x60);
}

// ============================================================================
// Address: 0x418200 | Symbol: XCrystal::SetState
// ============================================================================
void XCrystal__SetState(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x60) = param_1;
  return;
}

// ============================================================================
// Address: 0x418220 | Symbol: XCrystal::GetTakenPosition
// ============================================================================
undefined4 XCrystal__GetTakenPosition(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) == 2) {
    uVar1 = *(undefined4 *)(in_ECX + 0x6c);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x418240 | Symbol: XCrystal::StartTaken
// ============================================================================
void XCrystal__StartTaken(undefined4 param_1)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 100;
  uVar1 = 0xe8;
  XApplication__GetSoundList(0xe8,100,0);
  JSoundList__Play(uVar1,uVar2,uVar3);
  *(undefined4 *)(in_ECX + 0x6c) = param_1;
  *(undefined4 *)(in_ECX + 0x60) = 2;
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

// ============================================================================
// Address: 0x418290 | Symbol: XCrystal::StartVanishing
// ============================================================================
void XCrystal__StartVanishing(void)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 100;
  uVar1 = 0xe9;
  XApplication__GetSoundList(0xe9,100,0);
  JSoundList__Play(uVar1,uVar2,uVar3);
  *(undefined4 *)(in_ECX + 0x60) = 3;
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

// ============================================================================
// Address: 0x4182d0 | Symbol: XCrystal::StartGameOver
// ============================================================================
void XCrystal__StartGameOver(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  iVar1 = Random(0x168);
  *(undefined4 *)(in_ECX + 0x74) = 0;
  fVar2 = (float10)sinf((float)iVar1 * 0.017453292);
  *(float *)(in_ECX + 0x70) = (float)fVar2;
  fVar2 = (float10)cosf((float)iVar1 * 0.017453292);
  *(float *)(in_ECX + 0x78) = (float)fVar2;
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x60) = 4;
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

// ============================================================================
// Address: 0x418370 | Symbol: XCrystal::ProcessRotate
// ============================================================================
void XCrystal__ProcessRotate(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = param_1 >> 0x1f;
  if (in_ECX[0x18] == 1) {
    (**(code **)(*in_ECX + 0xc))
              (1,(float)((double)param_1 + (double)(&DAT_00473840)[-iVar1]) * 0.012217305);
  }
  else if (in_ECX[0x18] == 3) {
    (**(code **)(*in_ECX + 0xc))
              (1,(float)((double)param_1 + (double)(&DAT_00473840)[-iVar1]) * 0.06981317);
  }
  else if (in_ECX[0x18] == 4) {
    (**(code **)(*in_ECX + 0xc))
              (1,(float)((double)param_1 + (double)(&DAT_00473840)[-iVar1]) * 0.06981317);
  }
  return;
}

// ============================================================================
// Address: 0x4184b0 | Symbol: XCrystal::ProcessFrame
// ============================================================================
void XCrystal__ProcessFrame(void)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 local_60 [12];
  undefined1 local_54 [12];
  undefined1 local_48 [4];
  float local_44;
  double local_3c;
  double local_34;
  double local_2c;
  undefined4 local_24;
  float local_20;
  float local_1c;
  int local_18;
  int local_14;
  int local_10;
  float local_c;
  int local_8;
  
  *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 1;
  local_8 = in_ECX;
  if (*(int *)(in_ECX + 0x60) == 2) {
    uVar1 = JObject3DBase__GetWorldPos(local_54);
    JObject3DBase__SetWorldPos(uVar1);
    FUN_0040f7e0(1,(float)(*(int *)(local_8 + 0x6c) + -1) * 12.0 + 20.0);
  }
  else if (*(int *)(in_ECX + 0x60) == 3) {
    FUN_0040f7e0(1,0x3f4ccccd);
    if (800.0 < *(float *)(local_8 + 0xc)) {
      *(undefined4 *)(local_8 + 0x60) = 0;
      *(undefined4 *)(local_8 + 100) = 0;
    }
  }
  else if (*(int *)(in_ECX + 0x60) == 4) {
    local_24 = 0xa0;
    local_10 = *(int *)(in_ECX + 100);
    local_2c = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
    local_20 = ((float)local_2c / 160.0) * 160.0;
    local_c = 0.0;
    if (*(uint *)(in_ECX + 100) < 0xa0) {
      local_14 = *(int *)(in_ECX + 100);
      local_34 = (double)local_14 + (double)(&DAT_00473840)[-(local_14 >> 0x1f)];
      fVar2 = (float10)sinf(((float)local_34 / 160.0) * 3.1415927);
      local_1c = (float)fVar2;
      local_c = local_1c * 60.0;
    }
    else {
      local_18 = *(int *)(in_ECX + 100) + -0xa0;
      local_3c = (double)local_18 + (double)(&DAT_00473840)[-(local_18 >> 0x1f)];
      local_c = (float)local_3c * -1.4;
    }
    FUN_00413780(local_48,local_8 + 0x70,local_20);
    local_44 = local_c;
    uVar1 = FUN_00404050(local_60,local_8 + 0x7c,local_48);
    JObject3DBase__SetWorldPos(uVar1);
    if (*(float *)(local_8 + 0xc) <= -20.0 && *(float *)(local_8 + 0xc) != -20.0) {
      *(undefined4 *)(local_8 + 0x60) = 0;
      *(undefined4 *)(local_8 + 100) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x4186e0 | Symbol: XParticleList::XParticleList
// ============================================================================
undefined4 * XParticleList__XParticleList(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_c;
  
  *in_ECX = XParticleList::vftable;
  in_ECX[1] = param_1;
  *(undefined2 *)(in_ECX + 2) = 0;
  for (local_c = 0; local_c < 0x96; local_c = local_c + 1) {
    in_ECX[local_c + 3] = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x418740 | Symbol: XParticleList::~XParticleList
// ============================================================================
void XParticleList___XParticleList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0047149d;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XParticleList::vftable;
  XParticleList__Empty(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x418790 | Symbol: XParticleList::Empty
// ============================================================================
void XParticleList__Empty(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x96; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 0xc + local_8 * 4) != 0) {
      puVar1 = *(undefined4 **)(in_ECX + 0xc + local_8 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      *(undefined4 *)(in_ECX + 0xc + local_8 * 4) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x418810 | Symbol: XParticleList::ProcessFrame
// ============================================================================
void XParticleList__ProcessFrame(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x96; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 0xc + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 0xc + local_8 * 4) + 0x28))();
      iVar2 = XParticleBase__GetState();
      if (iVar2 == 0) {
        puVar1 = *(undefined4 **)(in_ECX + 0xc + local_8 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(in_ECX + 0xc + local_8 * 4) = 0;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x4188c0 | Symbol: XParticleList::Render
// ============================================================================
void XParticleList__Render(undefined4 param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x96; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 0xc + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 0xc + local_8 * 4) + 0x24))(param_1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x418920 | Symbol: XParticleList::CreateEnemyExplode
// ============================================================================
void XParticleList__CreateEnemyExplode(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_24;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004714d1;
  local_10 = ExceptionList;
  uVar2 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar1 = XGameObject__GetVolumeOfPosition(param_1,param_2,param_3);
  uVar12 = 0;
  uVar3 = (uint)bVar1;
  uVar11 = 0xeb;
  XApplication__GetSoundList(0xeb,uVar3,0,uVar2);
  JSoundList__Play(uVar11,uVar3,uVar12);
  local_1c = 0;
  while ((local_1c < 0x1e && (iVar4 = XParticleList__GetNullIndex(), -1 < iVar4))) {
    iVar5 = FUN_0042d23e(0xac);
    local_8 = 0;
    if (iVar5 == 0) {
      local_24 = 0;
    }
    else {
      local_24 = XParticle_EnemyExplode__XParticle_EnemyExplode
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3);
    }
    local_8 = 0xffffffff;
    iVar5 = Random(0xb4);
    iVar6 = Random(0x168);
    fVar7 = (float10)sinf((float)iVar5 * 0.017453292);
    fVar8 = (float10)cosf((float)iVar5 * 0.017453292);
    FUN_00403f60();
    fVar9 = (float10)sinf((float)iVar6 * 0.017453292);
    fVar10 = (float)fVar9 * (float)fVar8;
    fVar9 = (float10)cosf((float)iVar6 * 0.017453292,uVar2,fVar10);
    XParticle_EnemyExplode__SetDirVector(fVar10,(float)fVar7,(float)fVar9 * (float)fVar8);
    *(undefined4 *)(in_ECX + 0xc + iVar4 * 4) = local_24;
    local_1c = local_1c + 1;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x418b30 | Symbol: XParticleList::CreateEnemyFireSmokePurple
// ============================================================================
void XParticleList__CreateEnemyFireSmokePurple
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471505;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = XParticleList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar1) {
    iVar2 = FUN_0042d23e(0xa0);
    local_8 = 0;
    if (iVar2 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = XParticle_EnemyFireSmokePurple__XParticle_EnemyFireSmokePurple
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3);
    }
    *(undefined4 *)(in_ECX + 0xc + iVar1 * 4) = local_1c;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x418bf0 | Symbol: XParticleList::CreateEnemyFireSmokeGreen
// ============================================================================
void XParticleList__CreateEnemyFireSmokeGreen
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471539;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = XParticleList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar1) {
    iVar2 = FUN_0042d23e(0xa0);
    local_8 = 0;
    if (iVar2 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = XParticle_EnemyFireSmokeGreen__XParticle_EnemyFireSmokeGreen
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3);
    }
    *(undefined4 *)(in_ECX + 0xc + iVar1 * 4) = local_1c;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x418cb0 | Symbol: XParticleList::CreatePacFireHit
// ============================================================================
void XParticleList__CreatePacFireHit(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047156d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = XParticleList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar2) {
    bVar1 = XGameObject__GetVolumeOfPosition(param_1,param_2,param_3);
    uVar6 = 0;
    uVar3 = (uint)bVar1;
    uVar5 = 0xea;
    XApplication__GetSoundList(0xea,uVar3,0);
    JSoundList__Play(uVar5,uVar3,uVar6);
    iVar4 = FUN_0042d23e(0xa8);
    local_8 = 0;
    if (iVar4 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = XParticle_PacFireHit__XParticle_PacFireHit
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3,0x428c0000,0x10);
    }
    *(undefined4 *)(in_ECX + 0xc + iVar2 * 4) = local_20;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x418dc0 | Symbol: XParticleList::CreatePacVanish
// ============================================================================
void XParticleList__CreatePacVanish(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004715a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = XParticleList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar1) {
    uVar5 = 0;
    uVar4 = 100;
    uVar3 = 0xf1;
    XApplication__GetSoundList(0xf1,100,0);
    JSoundList__Play(uVar3,uVar4,uVar5);
    iVar2 = FUN_0042d23e(0xa8);
    local_8 = 0;
    if (iVar2 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = XParticle_PacFireHit__XParticle_PacFireHit
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3,0x43160000,0x96);
    }
    *(undefined4 *)(in_ECX + 0xc + iVar1 * 4) = local_1c;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x418eb0 | Symbol: XParticleList::GetNullIndex
// ============================================================================
uint XParticleList__GetNullIndex(void)

{
  short sVar1;
  int in_ECX;
  uint local_10;
  
  sVar1 = *(short *)(in_ECX + 8);
  local_10 = 0xffffffff;
  do {
    if (local_10 != 0xffffffff) {
      return local_10;
    }
    if (*(int *)(in_ECX + 0xc + (uint)*(ushort *)(in_ECX + 8) * 4) == 0) {
      local_10 = (uint)*(ushort *)(in_ECX + 8);
    }
    *(short *)(in_ECX + 8) = (short)((ulonglong)(*(ushort *)(in_ECX + 8) + 1) % 0x96);
  } while (*(short *)(in_ECX + 8) != sVar1);
  return local_10;
}

// ============================================================================
// Address: 0x418f20 | Symbol: XParticleBase::XParticleBase
// ============================================================================
undefined4 *
XParticleBase__XParticleBase
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004715cb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JObject3D_Particle__JObject3D_Particle(*(undefined4 *)(param_1 + 4),param_5,param_5);
  local_8 = 0;
  *in_ECX = XParticleBase::vftable;
  in_ECX[0x22] = param_1;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = param_2;
  in_ECX[0x26] = param_3;
  in_ECX[0x27] = param_4;
  JObject3DBase__SetWorldPos(&param_2);
  in_ECX[0x23] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x418ff0 | Symbol: XParticleBase::~XParticleBase
// ============================================================================
void XParticleBase___XParticleBase(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XParticleBase::vftable;
  JObject3D_Particle___JObject3D_Particle();
  return;
}

// ============================================================================
// Address: 0x419010 | Symbol: XParticleBase::Render2
// ============================================================================
void XParticleBase__Render2(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x8c) != 0) {
    JObject3D_Rect__Render2(param_1);
  }
  return;
}

// ============================================================================
// Address: 0x419040 | Symbol: XParticleBase::GetState
// ============================================================================
undefined4 XParticleBase__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x8c);
}

// ============================================================================
// Address: 0x419060 | Symbol: XParticle_EnemyExplode::XParticle_EnemyExplode
// ============================================================================
undefined4 *
XParticle_EnemyExplode__XParticle_EnemyExplode
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004715f5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XParticleBase__XParticleBase(param_1,param_2,param_3,param_4,0x42480000);
  local_8 = 0;
  *in_ECX = XParticle_EnemyExplode::vftable;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  JObject3D_Rect__SetTexture(0xa2,0,0,0x3f800000,0x3f800000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x419150 | Symbol: XParticle_EnemyExplode::~XParticle_EnemyExplode
// ============================================================================
void XParticle_EnemyExplode___XParticle_EnemyExplode(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XParticle_EnemyExplode::vftable;
  XParticleBase___XParticleBase();
  return;
}

// ============================================================================
// Address: 0x419170 | Symbol: XParticle_EnemyExplode::SetDirVector
// ============================================================================
void XParticle_EnemyExplode__SetDirVector(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = param_1;
  *(undefined4 *)(in_ECX + 0xa4) = param_2;
  *(undefined4 *)(in_ECX + 0xa8) = param_3;
  return;
}

// ============================================================================
// Address: 0x4191a0 | Symbol: XParticle_EnemyExplode::ProcessFrame
// ============================================================================
void XParticle_EnemyExplode__ProcessFrame(void)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 local_48 [12];
  undefined1 local_3c [12];
  double local_30;
  double local_28;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_20 = 0x78;
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_14 = 0.0;
    local_18 = 0.0;
    local_8 = in_ECX;
    if (*(uint *)(in_ECX + 0x90) < 0x78) {
      local_c = *(int *)(in_ECX + 0x90);
      local_28 = (double)local_c + (double)(&DAT_00473840)[-(local_c >> 0x1f)];
      local_14 = 1.0 - (float)local_28 / 120.0;
      local_10 = *(int *)(in_ECX + 0x90);
      local_30 = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
      fVar2 = (float10)sinf(((float)local_30 / 120.0) * 1.5707964);
      local_1c = (float)fVar2;
      local_18 = local_1c * 55.0;
    }
    JObject3DBase__ScaleTo(local_14);
    FUN_00413780(local_3c,local_8 + 0xa0,local_18);
    uVar1 = FUN_00404050(local_48,local_8 + 0x94,local_3c);
    JObject3DBase__SetWorldPos(uVar1);
    if (0x77 < *(uint *)(local_8 + 0x90)) {
      *(undefined4 *)(local_8 + 0x8c) = 0;
      *(undefined4 *)(local_8 + 0x90) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x419320 | Symbol: XParticle_EnemyFireSmokePurple::XParticle_EnemyFireSmokePurple
// ============================================================================
undefined4 *
XParticle_EnemyFireSmokePurple__XParticle_EnemyFireSmokePurple
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047161f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XParticleBase__XParticleBase(param_1,param_2,param_3,param_4,0x41900000);
  local_8 = 0;
  *in_ECX = XParticle_EnemyFireSmokePurple::vftable;
  JObject3D_Rect__SetTexture(0xaa,0,0,0x3f800000,0x3f800000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4193e0 | Symbol: XParticle_EnemyFireSmokePurple::~XParticle_EnemyFireSmokePurple
// ============================================================================
void XParticle_EnemyFireSmokePurple___XParticle_EnemyFireSmokePurple(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XParticle_EnemyFireSmokePurple::vftable;
  XParticleBase___XParticleBase();
  return;
}

// ============================================================================
// Address: 0x419400 | Symbol: XParticle_EnemyFireSmokePurple::ProcessFrame
// ============================================================================
void XParticle_EnemyFireSmokePurple__ProcessFrame(void)

{
  int in_ECX;
  float local_10;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_10 = 0.0;
    if (*(uint *)(in_ECX + 0x90) < 0x32) {
      local_10 = 1.0 - (float)((double)*(int *)(in_ECX + 0x90) +
                              (double)(&DAT_00473840)[-(*(int *)(in_ECX + 0x90) >> 0x1f)]) / 50.0;
    }
    JObject3DBase__ScaleTo(local_10);
    if (0x31 < *(uint *)(in_ECX + 0x90)) {
      *(undefined4 *)(in_ECX + 0x8c) = 0;
      *(undefined4 *)(in_ECX + 0x90) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x4194d0 | Symbol: XParticle_EnemyFireSmokeGreen::XParticle_EnemyFireSmokeGreen
// ============================================================================
undefined4 *
XParticle_EnemyFireSmokeGreen__XParticle_EnemyFireSmokeGreen
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471649;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XParticleBase__XParticleBase(param_1,param_2,param_3,param_4,0x41880000);
  local_8 = 0;
  *in_ECX = XParticle_EnemyFireSmokeGreen::vftable;
  JObject3D_Rect__SetTexture(0xb7,0,0,0x3f800000,0x3f800000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x419590 | Symbol: XParticle_EnemyFireSmokeGreen::~XParticle_EnemyFireSmokeGreen
// ============================================================================
void XParticle_EnemyFireSmokeGreen___XParticle_EnemyFireSmokeGreen(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XParticle_EnemyFireSmokeGreen::vftable;
  XParticleBase___XParticleBase();
  return;
}

// ============================================================================
// Address: 0x4195b0 | Symbol: XParticle_EnemyFireSmokeGreen::ProcessFrame
// ============================================================================
void XParticle_EnemyFireSmokeGreen__ProcessFrame(void)

{
  int in_ECX;
  float local_10;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_10 = 0.0;
    if (*(uint *)(in_ECX + 0x90) < 0x32) {
      local_10 = 1.0 - (float)((double)*(int *)(in_ECX + 0x90) +
                              (double)(&DAT_00473840)[-(*(int *)(in_ECX + 0x90) >> 0x1f)]) / 50.0;
    }
    JObject3DBase__ScaleTo(local_10);
    if (0x31 < *(uint *)(in_ECX + 0x90)) {
      *(undefined4 *)(in_ECX + 0x8c) = 0;
      *(undefined4 *)(in_ECX + 0x90) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x419680 | Symbol: XParticle_PacFireHit::XParticle_PacFireHit
// ============================================================================
undefined4 *
XParticle_PacFireHit__XParticle_PacFireHit
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined4 *in_ECX;
  
  XParticleBase__XParticleBase(param_1,param_2,param_3,param_4,param_5);
  *in_ECX = XParticle_PacFireHit::vftable;
  in_ECX[0x28] = param_6;
  in_ECX[0x29] = 2;
  return in_ECX;
}

// ============================================================================
// Address: 0x4196e0 | Symbol: XParticle_PacFireHit::~XParticle_PacFireHit
// ============================================================================
void XParticle_PacFireHit___XParticle_PacFireHit(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XParticle_PacFireHit::vftable;
  XParticleBase___XParticleBase();
  return;
}

// ============================================================================
// Address: 0x419700 | Symbol: XParticle_PacFireHit::Render2
// ============================================================================
void XParticle_PacFireHit__Render2(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint local_c;
  
  if (in_ECX[0x23] != 0) {
    JObject3D_Rect___SetWorldTransform2(param_1);
    (**(code **)(*in_ECX + 0x18))();
    for (local_c = 0; local_c < (uint)in_ECX[0x29]; local_c = local_c + 1) {
      XParticle_PacFireHit___SetTextureRandomly();
      if ((short)in_ECX[0xe] != 0) {
        piVar1 = (int *)CD3DApplication__GetD3DDevice();
        uVar2 = D3DTextr_GetSurface((short)in_ECX[0xe]);
        (**(code **)(*piVar1 + 0x8c))(piVar1,0,uVar2);
      }
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x68))(piVar1,4,0x1e2,in_ECX[0xb],in_ECX[10],in_ECX[0xd],in_ECX[0xc],0)
      ;
    }
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x8c))(piVar1,0,0);
    (**(code **)(*in_ECX + 0x1c))();
    JObject3DBase___ResetWorldTransform();
  }
  return;
}

// ============================================================================
// Address: 0x419830 | Symbol: XParticle_PacFireHit::ProcessFrame
// ============================================================================
void XParticle_PacFireHit__ProcessFrame(void)

{
  int in_ECX;
  float local_14;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_14 = 0.2;
    if (*(uint *)(in_ECX + 0x90) < *(uint *)(in_ECX + 0xa0)) {
      local_14 = 1.0 - ((float)((double)*(int *)(in_ECX + 0x90) +
                               (double)(&DAT_00473840)[-(*(int *)(in_ECX + 0x90) >> 0x1f)]) /
                       (float)((double)*(int *)(in_ECX + 0xa0) +
                              (double)(&DAT_00473840)[-(*(int *)(in_ECX + 0xa0) >> 0x1f)])) * 0.8;
    }
    JObject3DBase__ScaleTo(local_14);
    if (*(uint *)(in_ECX + 0xa0) >> 1 <= *(uint *)(in_ECX + 0x90)) {
      *(undefined4 *)(in_ECX + 0xa4) = 1;
    }
    if (*(uint *)(in_ECX + 0xa0) <= *(uint *)(in_ECX + 0x90)) {
      *(undefined4 *)(in_ECX + 0x8c) = 0;
      *(undefined4 *)(in_ECX + 0x90) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x419960 | Symbol: XParticle_PacFireHit::_SetTextureRandomly
// ============================================================================
void XParticle_PacFireHit___SetTextureRandomly(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = Random(9,0x3eaaaaab);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0,0,0x3eaaaaab,0x3eaaaaab);
  }
  else if (iVar1 == 1) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3eaaaaab,0,0x3f2aaaab,0x3eaaaaab);
  }
  else if (iVar1 == 2) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3f2aaaab,0,0x3f800000,0x3eaaaaab);
  }
  else if (iVar1 == 3) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0,0x3eaaaaab,0x3eaaaaab,0x3f2aaaab);
  }
  else if (iVar1 == 4) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3eaaaaab,0x3eaaaaab,0x3f2aaaab,0x3f2aaaab);
  }
  else if (iVar1 == 5) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3f2aaaab,0x3eaaaaab,0x3f800000,0x3f2aaaab);
  }
  else if (iVar1 == 6) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0,0x3f2aaaab,0x3eaaaaab,0x3f800000);
  }
  else if (iVar1 == 7) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3eaaaaab,0x3f2aaaab,0x3f2aaaab,0x3f800000);
  }
  else if (iVar1 == 8) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3f2aaaab,0x3f2aaaab,0x3f800000,0x3f800000);
  }
  return;
}

// ============================================================================
// Address: 0x419c60 | Symbol: XEnemyFireList::XEnemyFireList
// ============================================================================
undefined4 * XEnemyFireList__XEnemyFireList(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_8;
  
  *in_ECX = XEnemyFireList::vftable;
  in_ECX[1] = param_1;
  for (local_8 = 0; local_8 < 0x3c; local_8 = local_8 + 1) {
    in_ECX[local_8 + 2] = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x419cb0 | Symbol: XEnemyFireList::~XEnemyFireList
// ============================================================================
void XEnemyFireList___XEnemyFireList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00471666;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XEnemyFireList::vftable;
  XEnemyFireList__Empty(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x419d00 | Symbol: XEnemyFireList::CheckCollisionWithPac
// ============================================================================
void XEnemyFireList__CheckCollisionWithPac(void)

{
  int iVar1;
  int in_ECX;
  int local_c;
  
  iVar1 = XPac__GetState();
  if (((iVar1 != 0) && (iVar1 = XPac__GetState(), iVar1 != 4)) &&
     (iVar1 = XPac__GetState(), iVar1 != 5)) {
    for (local_c = 0; local_c < 0x3c; local_c = local_c + 1) {
      if (((*(int *)(in_ECX + 8 + local_c * 4) != 0) &&
          (iVar1 = XEnemyFireBase__GetState(), iVar1 != 0)) &&
         (iVar1 = JObject3DBase__CheckCollisionRadius(*(undefined4 *)(in_ECX + 8 + local_c * 4)),
         iVar1 != 0)) {
        XEnemyFireBase__SetState(0);
        XPac__StartDying();
        return;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x419dd0 | Symbol: XEnemyFireList::Empty
// ============================================================================
void XEnemyFireList__Empty(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x3c; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      puVar1 = *(undefined4 **)(in_ECX + 8 + local_8 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      *(undefined4 *)(in_ECX + 8 + local_8 * 4) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x419e40 | Symbol: XEnemyFireList::ProcessFrame
// ============================================================================
void XEnemyFireList__ProcessFrame(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x3c; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x28))();
      iVar2 = XEnemyFireBase__GetState();
      if (iVar2 == 0) {
        puVar1 = *(undefined4 **)(in_ECX + 8 + local_8 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(in_ECX + 8 + local_8 * 4) = 0;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x419ee0 | Symbol: XEnemyFireList::Render
// ============================================================================
void XEnemyFireList__Render(undefined4 param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x3c; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x24))(param_1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x419f40 | Symbol: XEnemyFireList::CreateCannonUpFire
// ============================================================================
void XEnemyFireList__CreateCannonUpFire(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047169a;
  local_10 = ExceptionList;
  uVar2 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = XEnemyFireList__GetNullIndex(uVar2);
  if (-1 < iVar3) {
    bVar1 = XGameObject__GetVolumeOfPosition(param_1,param_2,param_3);
    uVar8 = 0;
    uVar4 = (uint)bVar1;
    uVar7 = 0xf4;
    XApplication__GetSoundList(0xf4,uVar4,0);
    JSoundList__Play(uVar7,uVar4,uVar8);
    iVar5 = FUN_0042d23e(0xb0);
    local_8 = 0;
    if (iVar5 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = XEnemyFire_CannonUp__XEnemyFire_CannonUp
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3);
    }
    local_8 = 0xffffffff;
    iVar5 = Random(0x168);
    FUN_00403f60();
    fVar6 = (float10)sinf((float)iVar5 * 0.017453292);
    fVar9 = (float)fVar6;
    fVar6 = (float10)cosf((float)iVar5 * 0.017453292,uVar2,fVar9);
    XEnemyFire_CannonUp__SetValues(0x42340000,fVar9,0,(float)fVar6);
    *(undefined4 *)(in_ECX + 8 + iVar3 * 4) = local_20;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41a0e0 | Symbol: XEnemyFireList::CreateVolcanoFire
// ============================================================================
void XEnemyFireList__CreateVolcanoFire(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004716ce;
  local_10 = ExceptionList;
  uVar2 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = XEnemyFireList__GetNullIndex(uVar2);
  if (-1 < iVar3) {
    bVar1 = XGameObject__GetVolumeOfPosition(param_1,param_2,param_3);
    uVar8 = 0;
    uVar4 = (uint)bVar1;
    uVar7 = 0xf4;
    XApplication__GetSoundList(0xf4,uVar4,0);
    JSoundList__Play(uVar7,uVar4,uVar8);
    iVar5 = FUN_0042d23e(0xb0);
    local_8 = 0;
    if (iVar5 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = XEnemyFire_CannonUp__XEnemyFire_CannonUp
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3);
    }
    local_8 = 0xffffffff;
    iVar5 = Random(0x168);
    FUN_00403f60();
    fVar6 = (float10)sinf((float)iVar5 * 0.017453292);
    fVar9 = (float)fVar6;
    fVar6 = (float10)cosf((float)iVar5 * 0.017453292,uVar2,fVar9);
    XEnemyFire_CannonUp__SetValues(0x42a00000,fVar9,0,(float)fVar6);
    *(undefined4 *)(in_ECX + 8 + iVar3 * 4) = local_20;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41a280 | Symbol: XEnemyFireList::CreateCannonFire
// ============================================================================
void XEnemyFireList__CreateCannonFire
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_38 [12];
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  byte local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471702;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = XEnemyFireList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < local_24) {
    local_11 = XGameObject__GetVolumeOfPosition(param_1,param_2,param_3);
    uVar4 = 0;
    uVar1 = (uint)local_11;
    uVar3 = 0xf3;
    XApplication__GetSoundList(0xf3,uVar1,0);
    JSoundList__Play(uVar3,uVar1,uVar4);
    local_1c = FUN_0042d23e(0xac);
    local_8 = 0;
    if (local_1c == 0) {
      local_20 = 0;
    }
    else {
      local_20 = XEnemyFire_Cannon__XEnemyFire_Cannon
                           (*(undefined4 *)(local_18 + 4),param_1,param_2,param_3);
    }
    local_2c = local_20;
    local_8 = 0xffffffff;
    local_28 = local_20;
    puVar2 = (undefined4 *)GetVectorFromDir(local_38,param_4);
    XEnemyFire_Cannon__SetValues(*puVar2,puVar2[1],puVar2[2]);
    *(undefined4 *)(local_18 + 8 + local_24 * 4) = local_28;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41a3b0 | Symbol: XEnemyFireList::CreateUFOFire
// ============================================================================
void XEnemyFireList__CreateUFOFire(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471736;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = XEnemyFireList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar2) {
    bVar1 = XGameObject__GetVolumeOfPosition(param_1,param_2,param_3);
    uVar6 = 0;
    uVar3 = (uint)bVar1;
    uVar5 = 0xf3;
    XApplication__GetSoundList(0xf3,uVar3,0);
    JSoundList__Play(uVar5,uVar3,uVar6);
    iVar4 = FUN_0042d23e(0xb0);
    local_8 = 0;
    if (iVar4 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = XEnemyFire_UFO__XEnemyFire_UFO(*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3)
      ;
    }
    *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_20;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41a4c0 | Symbol: XEnemyFireList::CreateSteamFire
// ============================================================================
void XEnemyFireList__CreateSteamFire(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047176a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = XEnemyFireList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < iVar1) {
    iVar2 = FUN_0042d23e(0xa0);
    local_8 = 0;
    if (iVar2 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = XEnemyFire_Steam__XEnemyFire_Steam
                           (*(undefined4 *)(in_ECX + 4),param_1,param_2,param_3);
    }
    *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_1c;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41a580 | Symbol: XEnemyFireList::GetNullIndex
// ============================================================================
int XEnemyFireList__GetNullIndex(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x3b < local_8) {
      return -1;
    }
    if (*(int *)(in_ECX + 8 + local_8 * 4) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x41a5c0 | Symbol: XEnemyFireBase::XEnemyFireBase
// ============================================================================
undefined4 *
XEnemyFireBase__XEnemyFireBase
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471794;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JObject3D_Particle__JObject3D_Particle(*(undefined4 *)(param_1 + 4),param_5,param_5);
  local_8 = 0;
  *in_ECX = XEnemyFireBase::vftable;
  in_ECX[0x22] = param_1;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = param_2;
  in_ECX[0x26] = param_3;
  in_ECX[0x27] = param_4;
  JObject3DBase__SetWorldPos(&param_2);
  in_ECX[0x23] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41a690 | Symbol: XEnemyFireBase::~XEnemyFireBase
// ============================================================================
void XEnemyFireBase___XEnemyFireBase(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemyFireBase::vftable;
  JObject3D_Particle___JObject3D_Particle();
  return;
}

// ============================================================================
// Address: 0x41a6b0 | Symbol: XEnemyFireBase::Render2
// ============================================================================
void XEnemyFireBase__Render2(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x8c) != 0) {
    JObject3D_Rect__Render2(param_1);
  }
  return;
}

// ============================================================================
// Address: 0x41a6e0 | Symbol: XEnemyFireBase::GetState
// ============================================================================
undefined4 XEnemyFireBase__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x8c);
}

// ============================================================================
// Address: 0x41a700 | Symbol: XEnemyFireBase::SetState
// ============================================================================
void XEnemyFireBase__SetState(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x8c) = param_1;
  return;
}

// ============================================================================
// Address: 0x41a720 | Symbol: XEnemyFire_CannonUp::XEnemyFire_CannonUp
// ============================================================================
undefined4 *
XEnemyFire_CannonUp__XEnemyFire_CannonUp
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004717be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XEnemyFireBase__XEnemyFireBase(param_1,param_2,param_3,param_4,0x41900000);
  local_8 = 0;
  *in_ECX = XEnemyFire_CannonUp::vftable;
  in_ECX[0x28] = 0;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  JObject3D_Rect__SetTexture(0xa9,0,0,0x3f800000,0x3f800000);
  JObject3DBase__SetCollisionRadius(0x40e00000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41a830 | Symbol: XEnemyFire_CannonUp::~XEnemyFire_CannonUp
// ============================================================================
void XEnemyFire_CannonUp___XEnemyFire_CannonUp(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemyFire_CannonUp::vftable;
  XEnemyFireBase___XEnemyFireBase();
  return;
}

// ============================================================================
// Address: 0x41a850 | Symbol: XEnemyFire_CannonUp::SetValues
// ============================================================================
void XEnemyFire_CannonUp__SetValues
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = param_1;
  *(undefined4 *)(in_ECX + 0xa4) = param_2;
  *(undefined4 *)(in_ECX + 0xa8) = param_3;
  *(undefined4 *)(in_ECX + 0xac) = param_4;
  return;
}

// ============================================================================
// Address: 0x41a890 | Symbol: XEnemyFire_CannonUp::ProcessFrame
// ============================================================================
uint XEnemyFire_CannonUp__ProcessFrame(void)

{
  undefined4 uVar1;
  uint in_ECX;
  float10 fVar2;
  undefined1 local_44 [12];
  undefined1 local_38 [4];
  float local_34;
  double local_2c;
  double local_24;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_c = *(int *)(in_ECX + 0x90);
    local_24 = (double)local_c + (double)(&DAT_00473840)[-(local_c >> 0x1f)];
    local_18 = ((float)local_24 / 200.0) * *(float *)(in_ECX + 0xa0);
    local_10 = *(int *)(in_ECX + 0x90);
    local_2c = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
    local_8 = in_ECX;
    fVar2 = (float10)sinf(((float)local_2c / 200.0) * 3.1415927);
    local_14 = (float)fVar2;
    local_1c = local_14 * 100.0;
    FUN_00413780(local_38,local_8 + 0xa4,local_18);
    local_34 = local_1c;
    uVar1 = FUN_00404050(local_44,local_8 + 0x94,local_38);
    JObject3DBase__SetWorldPos(uVar1);
    in_ECX = *(uint *)(local_8 + 0x90) / 8;
    if (*(uint *)(local_8 + 0x90) % 8 == 0) {
      in_ECX = XParticleList__CreateEnemyFireSmokePurple
                         (*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0xc),
                          *(undefined4 *)(local_8 + 0x10));
    }
    if (*(float *)(local_8 + 0xc) <= 0.0 && *(float *)(local_8 + 0xc) != 0.0) {
      *(undefined4 *)(local_8 + 0x8c) = 0;
      *(undefined4 *)(local_8 + 0x90) = 0;
      in_ECX = local_8;
    }
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x41aa20 | Symbol: XEnemyFire_Cannon::XEnemyFire_Cannon
// ============================================================================
undefined4 *
XEnemyFire_Cannon__XEnemyFire_Cannon
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004717e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XEnemyFireBase__XEnemyFireBase(param_1,param_2,param_3,param_4,0x41900000);
  local_8 = 0;
  *in_ECX = XEnemyFire_Cannon::vftable;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  JObject3D_Rect__SetTexture(0xa9,0,0,0x3f800000,0x3f800000);
  JObject3DBase__SetCollisionRadius(0x40e00000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41ab20 | Symbol: XEnemyFire_Cannon::~XEnemyFire_Cannon
// ============================================================================
void XEnemyFire_Cannon___XEnemyFire_Cannon(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemyFire_Cannon::vftable;
  XEnemyFireBase___XEnemyFireBase();
  return;
}

// ============================================================================
// Address: 0x41ab40 | Symbol: XEnemyFire_Cannon::SetValues
// ============================================================================
void XEnemyFire_Cannon__SetValues(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = param_1;
  *(undefined4 *)(in_ECX + 0xa4) = param_2;
  *(undefined4 *)(in_ECX + 0xa8) = param_3;
  return;
}

// ============================================================================
// Address: 0x41ab70 | Symbol: XEnemyFire_Cannon::ProcessFrame
// ============================================================================
void XEnemyFire_Cannon__ProcessFrame(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_20 [12];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_14 = 0x3fcccccd;
    local_8 = in_ECX;
    FUN_00413780(local_20,in_ECX + 0xa0,0x3fcccccd);
    JObject3DBase__ShiftWorldPos(local_20);
    if (*(uint *)(local_8 + 0x90) % 8 == 0) {
      XParticleList__CreateEnemyFireSmokePurple
                (*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0xc),
                 *(undefined4 *)(local_8 + 0x10));
    }
    local_10 = XMap__ConvertPosXToMapX(*(undefined4 *)(local_8 + 8));
    local_c = XMap__ConvertPosZToMapZ(*(undefined4 *)(local_8 + 0x10));
    if (0xf < *(uint *)(local_8 + 0x90)) {
      iVar1 = XMap__IsBlocked_Fire(local_10,local_c);
      if (iVar1 != 0) {
        *(undefined4 *)(local_8 + 0x8c) = 0;
        *(undefined4 *)(local_8 + 0x90) = 0;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x41acb0 | Symbol: XEnemyFire_UFO::XEnemyFire_UFO
// ============================================================================
undefined4 *
XEnemyFire_UFO__XEnemyFire_UFO
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471812;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XEnemyFireBase__XEnemyFireBase(param_1,param_2,param_3,param_4,0x41880000);
  local_8 = 0;
  *in_ECX = XEnemyFire_UFO::vftable;
  _D3DVECTOR___D3DVECTOR(0,0xbf800000,0);
  in_ECX[0x2b] = 0;
  JObject3D_Rect__SetTexture(0xb6,0,0,0x3f800000,0x3f800000);
  JObject3DBase__SetCollisionRadius(0x40e00000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41adc0 | Symbol: XEnemyFire_UFO::~XEnemyFire_UFO
// ============================================================================
void XEnemyFire_UFO___XEnemyFire_UFO(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemyFire_UFO::vftable;
  XEnemyFireBase___XEnemyFireBase();
  return;
}

// ============================================================================
// Address: 0x41ade0 | Symbol: XEnemyFire_UFO::ProcessFrame
// ============================================================================
void XEnemyFire_UFO__ProcessFrame(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_48 [12];
  undefined1 local_3c [12];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_30 = 0x3f99999a;
    local_8 = in_ECX;
    FUN_00413780(local_3c,in_ECX + 0xa0,0x3f99999a);
    JObject3DBase__ShiftWorldPos(local_3c);
    if (*(uint *)(local_8 + 0x90) % 9 == 0) {
      XParticleList__CreateEnemyFireSmokeGreen
                (*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0xc),
                 *(undefined4 *)(local_8 + 0x10));
    }
    if (*(int *)(local_8 + 0xac) == 0) {
      if (*(float *)(local_8 + 0xc) <= 20.0 && *(float *)(local_8 + 0xc) != 20.0) {
        local_18 = XPac__GetMapPosX();
        local_20 = XPac__GetMapPosZ();
        local_1c = XMap__ConvertPosXToMapX(*(undefined4 *)(local_8 + 8));
        local_24 = XMap__ConvertPosZToMapZ(*(undefined4 *)(local_8 + 0x10));
        local_10 = FUN_0044da60(local_18 - local_1c);
        local_14 = FUN_0044da60(local_20 - local_24);
        local_c = 0xffffffff;
        if ((local_10 == 0) && (local_14 == 0)) {
          local_c = Random(4);
        }
        else if (local_14 < local_10) {
          if (local_1c < local_18) {
            local_c = 1;
          }
          else {
            local_c = 3;
          }
        }
        else if (local_10 < local_14) {
          if (local_24 < local_20) {
            local_c = 2;
          }
          else {
            local_c = 0;
          }
        }
        else {
          iVar1 = Random(2);
          if (iVar1 == 0) {
            if (local_1c < local_18) {
              local_c = 1;
            }
            else {
              local_c = 3;
            }
          }
          else if (local_24 < local_20) {
            local_c = 2;
          }
          else {
            local_c = 0;
          }
        }
        puVar2 = (undefined4 *)GetVectorFromDir(local_48,local_c);
        *(undefined4 *)(local_8 + 0xa0) = *puVar2;
        *(undefined4 *)(local_8 + 0xa4) = puVar2[1];
        *(undefined4 *)(local_8 + 0xa8) = puVar2[2];
        *(undefined4 *)(local_8 + 0xac) = 1;
      }
    }
    else {
      local_2c = XMap__ConvertPosXToMapX(*(undefined4 *)(local_8 + 8));
      local_28 = XMap__ConvertPosZToMapZ(*(undefined4 *)(local_8 + 0x10));
      if ((0xf < *(uint *)(local_8 + 0x90)) &&
         (iVar1 = XMap__IsBlocked_Fire(local_2c,local_28), iVar1 != 0)) {
        *(undefined4 *)(local_8 + 0x8c) = 0;
        *(undefined4 *)(local_8 + 0x90) = 0;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x41b0c0 | Symbol: XEnemyFire_Steam::XEnemyFire_Steam
// ============================================================================
undefined4 *
XEnemyFire_Steam__XEnemyFire_Steam
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047183c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XEnemyFireBase__XEnemyFireBase(param_1,param_2,param_3,param_4,0x41900000);
  local_8 = 0;
  *in_ECX = XEnemyFire_Steam::vftable;
  JObject3D__SetAlphaState(3);
  JObject3D__SetFilterState(1);
  JObject3D_Rect__SetTexture(0xdc,0,0,0x3f800000,0x3f800000);
  JObject3DBase__SetCollisionRadius(0x40e00000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41b1b0 | Symbol: XEnemyFire_Steam::~XEnemyFire_Steam
// ============================================================================
void XEnemyFire_Steam___XEnemyFire_Steam(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemyFire_Steam::vftable;
  XEnemyFireBase___XEnemyFireBase();
  return;
}

// ============================================================================
// Address: 0x41b1d0 | Symbol: XEnemyFire_Steam::ProcessFrame
// ============================================================================
void XEnemyFire_Steam__ProcessFrame(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    FUN_0040f750(1,*(float *)(in_ECX + 0x98) +
                   ((float)((double)*(int *)(in_ECX + 0x90) +
                           (double)(&DAT_00473840)[-(*(int *)(in_ECX + 0x90) >> 0x1f)]) / 80.0) *
                   120.0);
    JObject3D__SetAlphaFactor
              ((1.0 - (float)((double)*(int *)(in_ECX + 0x90) +
                             (double)(&DAT_00473840)[-(*(int *)(in_ECX + 0x90) >> 0x1f)]) / 80.0) *
               0.9 + 0.1);
    if (0x4f < *(uint *)(in_ECX + 0x90)) {
      *(undefined4 *)(in_ECX + 0x8c) = 0;
      *(undefined4 *)(in_ECX + 0x90) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x41b2f0 | Symbol: Concurrency::details::SchedulingNode::XCrystal::
// ============================================================================
/* Library Function - Single Match
    public: void * __thiscall Concurrency::details::SchedulingNode::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::SchedulingNode::XCrystal__(SchedulingNode *this,uint param_1)

{
  XCrystal___XCrystal();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x88);
  }
  return this;
}

// ============================================================================
// Address: 0x41b330 | Symbol: Concurrency::details::SchedulingNode::XCrystalList::
// ============================================================================
/* Library Function - Single Match
    public: void * __thiscall Concurrency::details::SchedulingNode::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::SchedulingNode::XCrystalList__(SchedulingNode *this,uint param_1)

{
  XCrystalList___XCrystalList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x88);
  }
  return this;
}

// ============================================================================
// Address: 0x41b370 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemyFireBase::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemyFireBase__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemyFireBase___XEnemyFireBase();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xa0);
  }
  return this;
}

// ============================================================================
// Address: 0x41b3b0 | Symbol: XEnemyFireList::
// ============================================================================
undefined4 XEnemyFireList__(uint param_1)

{
  undefined4 in_ECX;
  
  XEnemyFireList___XEnemyFireList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0xf8);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x41b3f0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemyFire_Cannon::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemyFire_Cannon__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemyFire_Cannon___XEnemyFire_Cannon();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xac);
  }
  return this;
}

// ============================================================================
// Address: 0x41b430 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemyFire_CannonUp::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemyFire_CannonUp__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemyFire_CannonUp___XEnemyFire_CannonUp();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xb0);
  }
  return this;
}

// ============================================================================
// Address: 0x41b470 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemyFire_Steam::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemyFire_Steam__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemyFire_Steam___XEnemyFire_Steam();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xa0);
  }
  return this;
}

// ============================================================================
// Address: 0x41b4b0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemyFire_UFO::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemyFire_UFO__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemyFire_UFO___XEnemyFire_UFO();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xb0);
  }
  return this;
}

// ============================================================================
// Address: 0x41b4f0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XParticleBase::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XParticleBase__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XParticleBase___XParticleBase();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xa0);
  }
  return this;
}

// ============================================================================
// Address: 0x41b530 | Symbol: XParticleList::
// ============================================================================
undefined4 XParticleList__(uint param_1)

{
  undefined4 in_ECX;
  
  XParticleList___XParticleList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x264);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x41b570 | Symbol: Concurrency::details::ThreadVirtualProcessor::XParticle_EnemyExplode::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XParticle_EnemyExplode__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XParticle_EnemyExplode___XParticle_EnemyExplode();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xac);
  }
  return this;
}

// ============================================================================
// Address: 0x41b5b0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XParticle_EnemyFireSmokeGreen::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XParticle_EnemyFireSmokeGreen__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XParticle_EnemyFireSmokeGreen___XParticle_EnemyFireSmokeGreen();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xa0);
  }
  return this;
}

// ============================================================================
// Address: 0x41b5f0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XParticle_EnemyFireSmokePurple::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XParticle_EnemyFireSmokePurple__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XParticle_EnemyFireSmokePurple___XParticle_EnemyFireSmokePurple();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xa0);
  }
  return this;
}

// ============================================================================
// Address: 0x41b630 | Symbol: Concurrency::details::ThreadVirtualProcessor::XParticle_PacFireHit::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XParticle_PacFireHit__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XParticle_PacFireHit___XParticle_PacFireHit();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0xa8);
  }
  return this;
}
