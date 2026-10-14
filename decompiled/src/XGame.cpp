// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XGame.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XGame.h"

// ============================================================================
// Address: 0x41f1e0 | Symbol: XStatusDisplay::XStatusDisplay
// ============================================================================
undefined4 * XStatusDisplay__XStatusDisplay(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471c4f;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XStatusDisplay::vftable;
  in_ECX[1] = param_1;
  iVar2 = FUN_0042d23e(0x2c,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    uVar6 = 1;
    uVar5 = 0xb9;
    uVar3 = XApplication__GetSurfaceList(0xb9,1);
    local_24 = JSprite__JSprite(uVar3,uVar5,uVar6);
  }
  local_8 = 0xffffffff;
  in_ECX[2] = local_24;
  iVar2 = FUN_0042d23e(0x2c,uVar1);
  local_8 = 1;
  if (iVar2 == 0) {
    local_2c = 0;
  }
  else {
    uVar6 = 1;
    uVar5 = 0xbc;
    uVar3 = XApplication__GetSurfaceList(0xbc,1);
    local_2c = JSprite__JSprite(uVar3,uVar5,uVar6);
  }
  local_8 = 0xffffffff;
  in_ECX[3] = local_2c;
  iVar2 = FUN_0042d23e(0x2c,uVar1);
  local_8 = 2;
  if (iVar2 == 0) {
    local_34 = 0;
  }
  else {
    uVar6 = 2;
    uVar5 = 0xbd;
    uVar3 = XApplication__GetSurfaceList(0xbd,2);
    local_34 = JSprite__JSprite(uVar3,uVar5,uVar6);
  }
  local_8 = 0xffffffff;
  in_ECX[4] = local_34;
  iVar2 = FUN_0042d23e(0x2c);
  local_8 = 3;
  if (iVar2 == 0) {
    local_3c = 0;
  }
  else {
    uVar6 = 2;
    uVar5 = 0xc0;
    uVar3 = XApplication__GetSurfaceList(0xc0,2);
    local_3c = JSprite__JSprite(uVar3,uVar5,uVar6);
  }
  local_8 = 0xffffffff;
  in_ECX[5] = local_3c;
  iVar2 = FUN_0042d23e(0x1c);
  local_8 = 4;
  if (iVar2 == 0) {
    local_44 = 0;
  }
  else {
    uVar6 = 10;
    uVar5 = 0xba;
    uVar3 = XApplication__GetSurfaceList(0xba,10);
    local_44 = JNumber__JNumber(uVar3,uVar5,uVar6);
  }
  local_8 = 0xffffffff;
  in_ECX[6] = local_44;
  iVar2 = FUN_0042d23e(0x1c);
  local_8 = 5;
  if (iVar2 == 0) {
    local_4c = 0;
  }
  else {
    uVar6 = 10;
    uVar5 = 0xba;
    uVar3 = XApplication__GetSurfaceList(0xba,10);
    local_4c = JNumber__JNumber(uVar3,uVar5,uVar6);
  }
  local_8 = 0xffffffff;
  in_ECX[7] = local_4c;
  JSprite__SetPosition(0xc,4);
  iVar2 = JSprite__GetWidth();
  JNumber__SetPosition(iVar2 + 0x14,5);
  JNumber__SetDisplayZero(1);
  JNumber__SetNumDigits(2);
  iVar4 = JNumber__GetDigitWidth();
  iVar2 = iVar2 + 0x2c + iVar4 * 2;
  JSprite__SetPosition(iVar2,4);
  iVar4 = JSprite__GetWidth();
  JNumber__SetPosition(iVar2 + 8 + iVar4,5);
  JNumber__SetDisplayZero(1);
  JNumber__SetNumDigits(2);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41f520 | Symbol: XStatusDisplay::~XStatusDisplay
// ============================================================================
void XStatusDisplay___XStatusDisplay(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XStatusDisplay::vftable;
  if (in_ECX[3] != 0) {
    if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[3])(1);
    }
    in_ECX[3] = 0;
  }
  if (in_ECX[2] != 0) {
    if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[2])(1);
    }
    in_ECX[2] = 0;
  }
  if (in_ECX[4] != 0) {
    if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[4])(1);
    }
    in_ECX[4] = 0;
  }
  if (in_ECX[7] != 0) {
    if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[7])(1);
    }
    in_ECX[7] = 0;
  }
  if (in_ECX[6] != 0) {
    if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[6])(1);
    }
    in_ECX[6] = 0;
  }
  if (in_ECX[5] != 0) {
    if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[5])(1);
    }
    in_ECX[5] = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41f6a0 | Symbol: XStatusDisplay::Draw
// ============================================================================
void XStatusDisplay__Draw(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int local_10;
  int local_c;
  
  JSprite__Draw(param_1);
  JSprite__Draw(param_1);
  JNumber__SetNumber(*(int *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x1a8) + 1);
  JNumber__Draw(param_1);
  uVar1 = XCrystalList__GetCrystalLeft();
  JNumber__SetNumber(uVar1);
  JNumber__Draw(param_1);
  iVar2 = CD3DApplication__GetScreenWidth();
  iVar3 = CD3DApplication__GetScreenHeight();
  iVar4 = XPac__GetFireEnergy();
  JSprite__SetCurrentFrame(9 < iVar4 / 100);
  JSprite__SetPosition(iVar2 + -0x11e,iVar3 + -0x1f);
  JSprite__Draw(param_1);
  local_c = JSprite__GetWidth();
  local_c = iVar2 + -0x117 + local_c;
  for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
    JSprite__SetCurrentFrame(local_10 < iVar4 / 100);
    JSprite__SetPosition(local_c,iVar3 + -0x1c);
    JSprite__Draw(param_1);
    iVar2 = JSprite__GetWidth();
    local_c = local_c + 1 + iVar2 / 3;
  }
  return;
}

// ============================================================================
// Address: 0x41f850 | Symbol: XProcessObject::XProcessObject
// ============================================================================
undefined4 * XProcessObject__XProcessObject(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_24;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471c8f;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XProcessObject::vftable;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  iVar2 = FUN_0042d23e(0x2c,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0xc3;
    uVar3 = XApplication__GetSurfaceList(0xc3,1);
    local_1c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8 = 0xffffffff;
  in_ECX[4] = local_1c;
  iVar2 = FUN_0042d23e(0x2c,uVar1);
  local_8 = 1;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0xc2;
    uVar3 = XApplication__GetSurfaceList(0xc2,1);
    local_24 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  in_ECX[5] = local_24;
  in_ECX[6] = 0;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41f970 | Symbol: XProcessObject::~XProcessObject
// ============================================================================
void XProcessObject___XProcessObject(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XProcessObject::vftable;
  if (in_ECX[4] != 0) {
    if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[4])(1);
    }
    in_ECX[4] = 0;
  }
  if (in_ECX[5] != 0) {
    if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[5])(1);
    }
    in_ECX[5] = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41fa00 | Symbol: XProcessObject::ProcessFrame
// ============================================================================
void XProcessObject__ProcessFrame(void)

{
  return;
}

// ============================================================================
// Address: 0x41fa10 | Symbol: XProcessObject::Render
// ============================================================================
void XProcessObject__Render(void)

{
  return;
}

// ============================================================================
// Address: 0x41fa20 | Symbol: XProcessObject::StartFadeIn
// ============================================================================
void XProcessObject__StartFadeIn(undefined4 param_1)

{
  int in_ECX;
  
  XProcessObject___ResetFadeIn();
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  *(undefined4 *)(in_ECX + 8) = 1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x41fa60 | Symbol: XProcessObject::StartFadeOut
// ============================================================================
void XProcessObject__StartFadeOut(undefined4 param_1)

{
  int in_ECX;
  
  XProcessObject___ResetFadeOut();
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  *(undefined4 *)(in_ECX + 8) = 2;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x41faa0 | Symbol: XProcessObject::StartProcess
// ============================================================================
void XProcessObject__StartProcess(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  *(undefined4 *)(in_ECX + 8) = 3;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

// ============================================================================
// Address: 0x41fad0 | Symbol: XProcessObject::ProcessFadeIn
// ============================================================================
void XProcessObject__ProcessFadeIn(void)

{
  int iVar1;
  int in_ECX;
  float fVar2;
  undefined4 local_8;
  
  XProcessObject___ResetFadeIn();
  local_8 = *(int *)(in_ECX + 0xc) + -0x14;
  if (local_8 < 0) {
    local_8 = 0;
  }
  else if (100 < local_8) {
    local_8 = 100;
  }
  fVar2 = (float)local_8 / 100.0;
  iVar1 = CD3DApplication__GetScreenWidth(100,fVar2);
  fVar2 = fVar2 * (float)(iVar1 / 2);
  JSprite__ShiftPosX(-fVar2);
  JSprite__ShiftPosX(fVar2);
  return;
}

// ============================================================================
// Address: 0x41fb80 | Symbol: XProcessObject::ProcessFadeOut
// ============================================================================
void XProcessObject__ProcessFadeOut(void)

{
  int iVar1;
  int in_ECX;
  float fVar2;
  undefined4 local_c;
  
  XProcessObject___ResetFadeOut();
  local_c = *(int *)(in_ECX + 0xc);
  if (100 < local_c) {
    local_c = 100;
  }
  fVar2 = (float)local_c / 100.0;
  iVar1 = CD3DApplication__GetScreenWidth(100,fVar2);
  fVar2 = fVar2 * (float)(iVar1 / 2);
  JSprite__ShiftPosX(fVar2);
  JSprite__ShiftPosX(-fVar2);
  return;
}

// ============================================================================
// Address: 0x41fc20 | Symbol: XProcessObject::_ResetFadeIn
// ============================================================================
void XProcessObject___ResetFadeIn(void)

{
  int iVar1;
  AFX_ROW_ALIGNMENT AVar2;
  int in_ECX;
  
  iVar1 = CD3DApplication__GetScreenWidth();
  iVar1 = iVar1 / 2;
  AVar2 = CD3DApplication__GetScreenHeight();
  CDockingPanesRow::JSprite__SetDrawSize(*(CDockingPanesRow **)(in_ECX + 0x10),iVar1,AVar2);
  JSprite__SetPosition(0,0);
  AVar2 = CD3DApplication__GetScreenHeight();
  CDockingPanesRow::JSprite__SetDrawSize(*(CDockingPanesRow **)(in_ECX + 0x14),iVar1,AVar2);
  JSprite__SetPosition(iVar1,0);
  return;
}

// ============================================================================
// Address: 0x41fca0 | Symbol: XProcessObject::_ResetFadeOut
// ============================================================================
void XProcessObject___ResetFadeOut(void)

{
  int iVar1;
  AFX_ROW_ALIGNMENT AVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  
  iVar1 = CD3DApplication__GetScreenWidth();
  iVar1 = iVar1 / 2;
  AVar2 = CD3DApplication__GetScreenHeight();
  CDockingPanesRow::JSprite__SetDrawSize(*(CDockingPanesRow **)(in_ECX + 0x10),iVar1,AVar2);
  JSprite__SetPosition(-iVar1,0);
  AVar2 = CD3DApplication__GetScreenHeight();
  CDockingPanesRow::JSprite__SetDrawSize(*(CDockingPanesRow **)(in_ECX + 0x14),iVar1,AVar2);
  uVar4 = 0;
  uVar3 = CD3DApplication__GetScreenWidth(0);
  JSprite__SetPosition(uVar3,uVar4);
  return;
}

// ============================================================================
// Address: 0x41fd30 | Symbol: XGameObject::XGameObject
// ============================================================================
undefined4 * XGameObject__XGameObject(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_5c;
  undefined4 local_54;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471d4f;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XProcessObject__XProcessObject(param_1);
  local_8 = 0;
  *in_ECX = XGameObject::vftable;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  uVar4 = 1;
  uVar3 = 0xbc;
  XApplication__GetSurfaceList(0xbc,1,uVar1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xb9;
  XApplication__GetSurfaceList(0xb9,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xbd;
  XApplication__GetSurfaceList(0xbd,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xba;
  XApplication__GetSurfaceList(0xba,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xc0;
  XApplication__GetSurfaceList(0xc0,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  iVar2 = FUN_0042d23e(0x78);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = XCamera__XCamera(param_1);
  }
  local_8._0_1_ = 0;
  in_ECX[8] = local_1c;
  iVar2 = FUN_0042d23e(0x90);
  local_8._0_1_ = 2;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = XPac__XPac(in_ECX);
  }
  local_8._0_1_ = 0;
  in_ECX[10] = local_24;
  iVar2 = FUN_0042d23e(0x80);
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = XEnemyList__XEnemyList(in_ECX);
  }
  local_8._0_1_ = 0;
  in_ECX[0xb] = local_2c;
  iVar2 = FUN_0042d23e(0x6c);
  local_8._0_1_ = 4;
  if (iVar2 == 0) {
    local_34 = 0;
  }
  else {
    local_34 = XMapObjectList__XMapObjectList(in_ECX);
  }
  local_8._0_1_ = 0;
  in_ECX[0xc] = local_34;
  iVar2 = FUN_0042d23e(0x14);
  local_8._0_1_ = 5;
  if (iVar2 == 0) {
    local_3c = 0;
  }
  else {
    local_3c = XPacFireList__XPacFireList(in_ECX);
  }
  local_8._0_1_ = 0;
  in_ECX[0xd] = local_3c;
  iVar2 = FUN_0042d23e(0xf8);
  local_8._0_1_ = 6;
  if (iVar2 == 0) {
    local_44 = 0;
  }
  else {
    local_44 = XEnemyFireList__XEnemyFireList(in_ECX);
  }
  local_8._0_1_ = 0;
  in_ECX[0xe] = local_44;
  iVar2 = FUN_0042d23e(0x264);
  local_8._0_1_ = 7;
  if (iVar2 == 0) {
    local_4c = 0;
  }
  else {
    local_4c = XParticleList__XParticleList(in_ECX);
  }
  local_8._0_1_ = 0;
  in_ECX[0xf] = local_4c;
  iVar2 = FUN_0042d23e(0x88);
  local_8._0_1_ = 8;
  if (iVar2 == 0) {
    local_54 = 0;
  }
  else {
    local_54 = XCrystalList__XCrystalList(in_ECX);
  }
  local_8._0_1_ = 0;
  in_ECX[0x10] = local_54;
  iVar2 = FUN_0042d23e(0x20);
  local_8._0_1_ = 9;
  if (iVar2 == 0) {
    local_5c = 0;
  }
  else {
    local_5c = XStatusDisplay__XStatusDisplay(in_ECX);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x11] = local_5c;
  XGameObject__InitLevel();
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4200e0 | Symbol: XGameObject::~XGameObject
// ============================================================================
void XGameObject___XGameObject(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00471d6c;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XGameObject::vftable;
  if (in_ECX[9] != 0) {
    if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[9])(1,uVar1);
    }
    in_ECX[9] = 0;
  }
  if (in_ECX[8] != 0) {
    if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[8])(1);
    }
    in_ECX[8] = 0;
  }
  if (in_ECX[10] != 0) {
    if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[10])(1);
    }
    in_ECX[10] = 0;
  }
  if (in_ECX[0xb] != 0) {
    if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xb])(1);
    }
    in_ECX[0xb] = 0;
  }
  if (in_ECX[0xc] != 0) {
    if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xc])(1);
    }
    in_ECX[0xc] = 0;
  }
  if (in_ECX[0xd] != 0) {
    if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xd])(1);
    }
    in_ECX[0xd] = 0;
  }
  if (in_ECX[0xe] != 0) {
    if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xe])(1);
    }
    in_ECX[0xe] = 0;
  }
  if (in_ECX[0xf] != 0) {
    if ((undefined4 *)in_ECX[0xf] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0xf])(1);
    }
    in_ECX[0xf] = 0;
  }
  if (in_ECX[0x10] != 0) {
    if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x10])(1);
    }
    in_ECX[0x10] = 0;
  }
  if (in_ECX[0x11] != 0) {
    if ((undefined4 *)in_ECX[0x11] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x11])(1);
    }
    in_ECX[0x11] = 0;
  }
  uVar2 = 0xbc;
  XApplication__GetSurfaceList(0xbc);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xb9;
  XApplication__GetSurfaceList(0xb9);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xbd;
  XApplication__GetSurfaceList(0xbd);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xba;
  XApplication__GetSurfaceList(0xba);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xc0;
  XApplication__GetSurfaceList(0xc0);
  JSurfaceList__DestroySurface(uVar2);
  XProcessObject___XProcessObject();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x420400 | Symbol: XGameObject::ProcessFrame
// ============================================================================
void XGameObject__ProcessFrame(uint param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int in_ECX;
  undefined4 uVar9;
  undefined4 uVar10;
  uint local_10;
  int local_c;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return;
  }
  *(uint *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  if (*(int *)(in_ECX + 8) == 1) {
    XProcessObject__ProcessFadeIn();
    if (0x77 < *(uint *)(in_ECX + 0xc)) {
      XProcessObject__StartProcess(0);
    }
  }
  else if (*(int *)(in_ECX + 8) == 2) {
    XProcessObject__ProcessFadeOut();
    if (0x77 < *(uint *)(in_ECX + 0xc)) {
      if (*(int *)(in_ECX + 0x18) == 0) {
        XApplication__SetState(5);
        *(undefined4 *)(in_ECX + 8) = 0;
        return;
      }
      *(int *)(*(int *)(in_ECX + 4) + 0x1a8) = *(int *)(*(int *)(in_ECX + 4) + 0x1a8) + 1;
      if (*(int *)(*(int *)(in_ECX + 4) + 0x1b4) < *(int *)(*(int *)(in_ECX + 4) + 0x1a8)) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x1a8) = 0;
        XApplication__SetState(8);
        *(undefined4 *)(in_ECX + 8) = 0;
        return;
      }
      if (*(int *)(*(int *)(in_ECX + 4) + 0x1ac) < *(int *)(*(int *)(in_ECX + 4) + 0x1a8)) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x1ac) =
             *(undefined4 *)(*(int *)(in_ECX + 4) + 0x1a8);
        XApplication__SaveWinRegData();
      }
      iVar7 = IsRegistered();
      if ((iVar7 == 0) &&
         (*(int *)(*(int *)(in_ECX + 4) + 0x1b0) < *(int *)(*(int *)(in_ECX + 4) + 0x1a8))) {
        XApplication__SetState(7);
        *(undefined4 *)(in_ECX + 8) = 0;
        return;
      }
      XGameObject__InitLevel();
      return;
    }
  }
  else if (*(int *)(in_ECX + 8) == 3) {
    if (*(int *)(in_ECX + 0x18) == 1) {
      if (300 < *(uint *)(in_ECX + 0xc)) {
        XProcessObject__StartFadeOut(1);
      }
    }
    else if ((*(int *)(in_ECX + 0x18) == 2) && (300 < *(uint *)(in_ECX + 0xc))) {
      XProcessObject__StartFadeOut(0);
    }
  }
  XPac__ProcessRotate(param_1);
  XEnemyList__ProcessRotate(param_1);
  XMapObjectList__ProcessRotate(param_1);
  XCrystalList__ProcessRotate(param_1);
  for (local_10 = 0; local_10 < param_1; local_10 = local_10 + 1) {
    XEnemyList__CheckCollisionWithPac();
    XEnemyFireList__CheckCollisionWithPac();
    XCrystalList__CheckCollisionWithPac();
    XPacFireList__CheckCollisionWithEnemy();
    XMap__ProcessFrame();
    XPac__ProcessFrame();
    XCamera__ProcessFrame(*(undefined4 *)(in_ECX + 0x28));
    XCrystalList__ProcessFrame();
    XPacFireList__ProcessFrame();
    XEnemyFireList__ProcessFrame();
    XParticleList__ProcessFrame();
    XEnemyList__ProcessFrame();
    XMapObjectList__ProcessFrame();
  }
  XApplication__GetDInput();
  JDInput__UpdateInputState();
  uVar9 = 200;
  XApplication__GetDInput(200);
  iVar7 = JDInput__GetKeyboardState(uVar9);
  if (iVar7 == 0) {
    uVar10 = 0;
    uVar9 = 0;
    XApplication__GetDInput(0,0);
    iVar7 = JDInput__GetJoyDirState(uVar9,uVar10);
    if (iVar7 != 0) goto LAB_0042070d;
    bVar3 = false;
  }
  else {
LAB_0042070d:
    bVar3 = true;
  }
  uVar9 = 0xcd;
  XApplication__GetDInput(0xcd);
  iVar7 = JDInput__GetKeyboardState(uVar9);
  if (iVar7 == 0) {
    uVar10 = 1;
    uVar9 = 0;
    XApplication__GetDInput(0,1);
    iVar7 = JDInput__GetJoyDirState(uVar9,uVar10);
    if (iVar7 != 0) goto LAB_00420758;
    bVar5 = false;
  }
  else {
LAB_00420758:
    bVar5 = true;
  }
  uVar9 = 0xd0;
  XApplication__GetDInput(0xd0);
  iVar7 = JDInput__GetKeyboardState(uVar9);
  if (iVar7 == 0) {
    uVar10 = 2;
    uVar9 = 0;
    XApplication__GetDInput(0,2);
    iVar7 = JDInput__GetJoyDirState(uVar9,uVar10);
    if (iVar7 != 0) goto LAB_004207a3;
    bVar4 = false;
  }
  else {
LAB_004207a3:
    bVar4 = true;
  }
  uVar9 = 0xcb;
  XApplication__GetDInput(0xcb);
  iVar7 = JDInput__GetKeyboardState(uVar9);
  if (iVar7 == 0) {
    uVar10 = 3;
    uVar9 = 0;
    XApplication__GetDInput(0,3);
    iVar7 = JDInput__GetJoyDirState(uVar9,uVar10);
    if (iVar7 != 0) goto LAB_004207ee;
    bVar6 = false;
  }
  else {
LAB_004207ee:
    bVar6 = true;
  }
  uVar9 = 0x2a;
  XApplication__GetDInput(0x2a);
  iVar7 = JDInput__GetKeyboardPressed(uVar9);
  if (iVar7 == 0) {
    uVar9 = 0x36;
    XApplication__GetDInput(0x36);
    iVar7 = JDInput__GetKeyboardPressed(uVar9);
    if (iVar7 != 0) goto LAB_00420866;
    uVar9 = 0x2c;
    XApplication__GetDInput(0x2c);
    iVar7 = JDInput__GetKeyboardPressed(uVar9);
    if (iVar7 != 0) goto LAB_00420866;
    uVar10 = 0;
    uVar9 = 0;
    XApplication__GetDInput(0,0);
    iVar7 = JDInput__GetJoyButtonPressed(uVar9,uVar10);
    if (iVar7 != 0) goto LAB_00420866;
    bVar1 = false;
  }
  else {
LAB_00420866:
    bVar1 = true;
  }
  uVar9 = 0x1d;
  XApplication__GetDInput(0x1d);
  iVar7 = JDInput__GetKeyboardState(uVar9);
  if (iVar7 == 0) {
    uVar9 = 0x9d;
    XApplication__GetDInput(0x9d);
    iVar7 = JDInput__GetKeyboardState(uVar9);
    if (iVar7 == 0) {
      uVar9 = 0x2d;
      XApplication__GetDInput(0x2d);
      iVar7 = JDInput__GetKeyboardState(uVar9);
      if (iVar7 == 0) {
        uVar10 = 1;
        uVar9 = 0;
        XApplication__GetDInput(0,1);
        iVar7 = JDInput__GetJoyButtonState(uVar9,uVar10);
        if (iVar7 == 0) {
          bVar2 = false;
          goto LAB_004208e8;
        }
      }
    }
  }
  bVar2 = true;
LAB_004208e8:
  iVar7 = XPac__GetState();
  if (((iVar7 == 1) || (iVar7 = XPac__GetState(), iVar7 == 2)) ||
     (iVar7 = XPac__GetState(), iVar7 == 3)) {
    uVar9 = 1;
    XApplication__GetDInput(1);
    iVar7 = JDInput__GetKeyboardPressed(uVar9);
    if (iVar7 != 0) {
      XPac__StartDying();
    }
  }
  iVar7 = XPac__GetState();
  if (((iVar7 == 1) || (iVar7 = XPac__GetState(), iVar7 == 2)) ||
     (iVar7 = XPac__GetState(), iVar7 == 3)) {
    if ((bVar1) && (iVar7 = XPac__GetFireEnergy(), 999 < iVar7)) {
      XPacFireList__CreateFire();
      XPac__ResetFireEnergy();
    }
    if (bVar2) {
      if (bVar3) {
        XCamera__IncrVerticalAngle(param_1);
      }
      else if (bVar4) {
        XCamera__DecrVerticalAngle(param_1);
      }
    }
    iVar7 = XCamera__GetState();
    if (iVar7 == 1) {
      if (bVar2) {
        if (bVar5) {
          XCamera__StartRotatingLeft();
        }
        else if (bVar6) {
          XCamera__StartRotatingRight();
        }
      }
      else {
        local_c = -1;
        if (bVar3) {
          local_c = 0;
        }
        else if (bVar5) {
          local_c = 1;
        }
        else if (bVar4) {
          local_c = 2;
        }
        else if (bVar6) {
          local_c = 3;
        }
        if (-1 < local_c) {
          iVar7 = XCamera__GetViewDirection();
          uVar8 = iVar7 + local_c & 0x80000003;
          if ((int)uVar8 < 0) {
            uVar8 = (uVar8 - 1 | 0xfffffffc) + 1;
          }
          iVar7 = XPac__GetState();
          if (iVar7 == 1) {
            XPac__StartMoving(uVar8);
          }
          else {
            iVar7 = XPac__GetState();
            if (iVar7 == 3) {
              XPac__SetFaceDirection(uVar8);
            }
          }
        }
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x420ad0 | Symbol: XGameObject::Render
// ============================================================================
void XGameObject__Render(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    XCamera__DoSetTransform();
    XMap__Render();
    XMapObjectList__Render();
    XCrystalList__Render();
    XEnemyList__Render();
    (**(code **)(**(int **)(in_ECX + 0x28) + 0x14))();
    uVar1 = XCamera__GetViewMatrix();
    XParticleList__Render(uVar1);
    uVar1 = XCamera__GetViewMatrix();
    XEnemyFireList__Render(uVar1);
    uVar1 = XCamera__GetViewMatrix();
    XPacFireList__Render(uVar1);
    uVar1 = CD3DApplication__GetBackBuffer();
    XStatusDisplay__Draw(uVar1);
    if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 2)) {
      uVar1 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar1);
      uVar1 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x420bd0 | Symbol: XGameObject::InitLevel
// ============================================================================
void XGameObject__InitLevel(void)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471d9d;
  local_10 = ExceptionList;
  uVar2 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = XApplication__GetCurrentWorld(uVar2);
  if (iVar3 == 0) {
    uVar7 = 1;
    XApplication__GetMidiList(1);
    JMidiList__Play(uVar7);
  }
  else {
    iVar3 = XApplication__GetCurrentWorld(uVar2);
    if (iVar3 == 1) {
      uVar7 = 2;
      XApplication__GetMidiList(2);
      JMidiList__Play(uVar7);
    }
    else {
      uVar7 = 3;
      XApplication__GetMidiList(3);
      JMidiList__Play(uVar7);
    }
  }
  XPac__Reset();
  XEnemyList__Empty();
  XMapObjectList__Empty();
  XCrystalList__Empty();
  XPacFireList__Empty();
  XEnemyFireList__Empty();
  XParticleList__Empty();
  XCrystalList__Empty();
  if (*(int *)(in_ECX + 0x24) != 0) {
    if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
    }
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  iVar3 = FUN_0042d23e(0x2c);
  local_8 = 0;
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    uVar7 = *(undefined4 *)(in_ECX + 0x40);
    uVar6 = *(undefined4 *)(in_ECX + 0x30);
    uVar5 = *(undefined4 *)(in_ECX + 0x2c);
    uVar4 = *(undefined4 *)(in_ECX + 0x28);
    uVar1 = GetMapResId(*(undefined4 *)(in_ECX + 4),uVar4,uVar5,uVar6,uVar7);
    local_20 = XMap__XMap(*(undefined4 *)(in_ECX + 4),uVar1,uVar4,uVar5,uVar6,uVar7);
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x24) = local_20;
  XCamera__ResetForGame(*(undefined4 *)(in_ECX + 0x28));
  XProcessObject__StartFadeIn(0);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x420d90 | Symbol: XGameObject::GetVolumeOfPosition
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int XGameObject__GetVolumeOfPosition(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  float10 extraout_ST0;
  undefined1 local_14 [12];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  iVar2 = XPac__GetState(0x44098000,0x43020000);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    uVar3 = JObject3DBase__GetWorldPos(local_14);
    D3DFindDistance(&stack0x00000004,uVar3);
    fVar1 = (float)extraout_ST0;
    if (130.0 <= fVar1) {
      if (fVar1 <= 550.0) {
        iVar2 = ((int)(((550.0 - fVar1) / 420.0) * 30.0) & 0xffU) + 0x46;
      }
      else {
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 100;
    }
  }
  return iVar2;
}

// ============================================================================
// Address: 0x420e50 | Symbol: XGameObject::
// ============================================================================
undefined4 XGameObject__(uint param_1)

{
  undefined4 in_ECX;
  
  XGameObject___XGameObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x48);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x420e80 | Symbol: XProcessObject::
// ============================================================================
undefined4 XProcessObject__(uint param_1)

{
  undefined4 in_ECX;
  
  XProcessObject___XProcessObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x20);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x420eb0 | Symbol: XStatusDisplay::
// ============================================================================
undefined4 XStatusDisplay__(uint param_1)

{
  undefined4 in_ECX;
  
  XStatusDisplay___XStatusDisplay();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x20);
  }
  return in_ECX;
}
