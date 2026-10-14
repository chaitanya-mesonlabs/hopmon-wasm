// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XTitle.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XTitle.h"

// ============================================================================
// Address: 0x4289c0 | Symbol: XTitleBackground::XTitleBackground
// ============================================================================
undefined4 * XTitleBackground__XTitleBackground(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_24;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00472389;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XTitleBackground::vftable;
  in_ECX[1] = param_1;
  iVar2 = FUN_0042d23e(0x88,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JObject3D_Rect__JObject3D_Rect(in_ECX[1],0x44340000,0x43c80000);
  }
  local_8 = 0xffffffff;
  in_ECX[2] = local_1c;
  iVar2 = FUN_0042d23e(0x88,uVar1);
  local_8 = 1;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = JObject3D_Rect__JObject3D_Rect(in_ECX[1],0x44340000,0x43c80000);
  }
  local_8 = 0xffffffff;
  in_ECX[3] = local_24;
  in_ECX[4] = 0;
  (**(code **)(*(int *)in_ECX[2] + 0xc))(0,0x40490fdb);
  FUN_0040f7e0(1,0x42f00000);
  JObject3D__UsePerspective(1);
  JObject3D__SetFilterState(1);
  FUN_0040f7e0(1,0xc2f00000);
  JObject3D__UsePerspective(1);
  JObject3D__SetFilterState(2);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x428b80 | Symbol: XTitleBackground::~XTitleBackground
// ============================================================================
void XTitleBackground___XTitleBackground(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XTitleBackground::vftable;
  if (in_ECX[2] != 0) {
    if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[2])(1);
    }
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
// Address: 0x428c10 | Symbol: XTitleBackground::ProcessFrame
// ============================================================================
void XTitleBackground__ProcessFrame(int param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x10) =
       (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.02 +
       *(float *)(in_ECX + 0x10);
  return;
}

// ============================================================================
// Address: 0x428c60 | Symbol: XTitleBackground::Render
// ============================================================================
void XTitleBackground__Render(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))
            (0xc1,0,*(undefined4 *)(in_ECX + 0x10),0x41900000,*(float *)(in_ECX + 0x10) + 10.0);
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x20))
            (0xc1,0,*(uint *)(in_ECX + 0x10) ^ 0x80000000,0x41900000,
             10.0 - *(float *)(in_ECX + 0x10));
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x14))();
  return;
}

// ============================================================================
// Address: 0x428d40 | Symbol: XLogoObject::XLogoObject
// ============================================================================
undefined4 * XLogoObject__XLogoObject(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004723e3;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XProcessObject__XProcessObject(param_1);
  local_8 = 0;
  *in_ECX = XLogoObject::vftable;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  XApplication__GetMidiList(uVar1);
  JMidiList__Stop();
  uVar4 = 0;
  uVar3 = 0x13c;
  XApplication__GetSurfaceList(0x13c,0);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  iVar2 = FUN_0042d23e(0x78);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = XCamera__XCamera(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[8] = local_1c;
  XCamera__ResetForTitle();
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 2;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0x13c;
    uVar3 = XApplication__GetSurfaceList(0x13c,1);
    local_24 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[9] = local_24;
  iVar2 = FUN_0042d23e(0x88);
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = JObject3D_Rect__JObject3D_Rect(in_ECX[1],0x44160000,0x44160000);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[10] = local_2c;
  (**(code **)(*(int *)in_ECX[10] + 0xc))(0,0xbfc90fdb);
  JObject3D__UsePerspective(0);
  (**(code **)(*(int *)in_ECX[10] + 0x20))(0x14c,0,0,0x3f800000,0x3f800000);
  XProcessObject__StartProcess(0);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x428f70 | Symbol: XLogoObject::~XLogoObject
// ============================================================================
void XLogoObject___XLogoObject(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00472400;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XLogoObject::vftable;
  if (in_ECX[8] != 0) {
    if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[8])(1,uVar1);
    }
    in_ECX[8] = 0;
  }
  if (in_ECX[9] != 0) {
    if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[9])(1);
    }
    in_ECX[9] = 0;
  }
  if (in_ECX[10] != 0) {
    if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[10])(1);
    }
    in_ECX[10] = 0;
  }
  uVar2 = 0x13c;
  XApplication__GetSurfaceList(0x13c);
  JSurfaceList__DestroySurface(uVar2);
  XProcessObject___XProcessObject();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x429090 | Symbol: XLogoObject::ProcessFrame
// ============================================================================
void XLogoObject__ProcessFrame(uint param_1)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint local_c;
  
  if (*(int *)(in_ECX + 8) != 0) {
    for (local_c = 0; local_c < param_1; local_c = local_c + 1) {
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
      if (*(int *)(in_ECX + 0xc) == 0x32) {
        uVar3 = 0;
        uVar2 = 100;
        uVar1 = 0x13d;
        XApplication__GetSoundList(0x13d,100,0);
        JSoundList__Play(uVar1,uVar2,uVar3);
      }
      if (0x3b5 < *(uint *)(in_ECX + 0xc)) {
        XApplication__SetState(4);
        *(undefined4 *)(in_ECX + 8) = 0;
        return;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x429120 | Symbol: XLogoObject::Render
// ============================================================================
void XLogoObject__Render(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  
  if (*(int *)(in_ECX + 8) != 0) {
    XCamera__DoSetTransform();
    (**(code **)(**(int **)(in_ECX + 0x28) + 0x14))();
    iVar1 = CD3DApplication__GetScreenWidth();
    iVar1 = iVar1 / 2;
    iVar2 = CD3DApplication__GetScreenHeight(iVar1);
    JSprite__SetCenterPos(iVar1,iVar2 / 2);
    uVar4 = 0x3f800000;
    uVar3 = CD3DApplication__GetBackBuffer(0x3f800000);
    JSprite__DrawScale(uVar3,uVar4);
  }
  return;
}

// ============================================================================
// Address: 0x4291c0 | Symbol: XRegisterInfoObject::XRegisterInfoObject
// ============================================================================
undefined4 * XRegisterInfoObject__XRegisterInfoObject(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
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
  puStack_c = &LAB_004724a2;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XProcessObject__XProcessObject(param_1);
  local_8 = 0;
  *in_ECX = XRegisterInfoObject::vftable;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  uVar3 = 3;
  XApplication__GetMidiList(3,uVar1);
  JMidiList__Play(uVar3);
  uVar4 = 1;
  uVar3 = 0xd0;
  XApplication__GetSurfaceList(0xd0,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xd1;
  XApplication__GetSurfaceList(0xd1,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 200;
  XApplication__GetSurfaceList(200,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 0;
  uVar3 = 0x142;
  XApplication__GetSurfaceList(0x142,0);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 0;
  uVar3 = 0x143;
  XApplication__GetSurfaceList(0x143,0);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 0;
  uVar3 = 0x141;
  XApplication__GetSurfaceList(0x141,0);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  iVar2 = FUN_0042d23e(0x78);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = XCamera__XCamera(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[8] = local_1c;
  XCamera__ResetForTitle();
  iVar2 = FUN_0042d23e(0x14);
  local_8._0_1_ = 2;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = XTitleBackground__XTitleBackground(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[9] = local_24;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    local_2c = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xd0;
    uVar3 = XApplication__GetSurfaceList(0xd0,2);
    local_2c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[10] = local_2c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 4;
  if (iVar2 == 0) {
    local_34 = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xd1;
    uVar3 = XApplication__GetSurfaceList(0xd1,2);
    local_34 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xb] = local_34;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 5;
  if (iVar2 == 0) {
    local_3c = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 200;
    uVar3 = XApplication__GetSurfaceList(200,2);
    local_3c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xc] = local_3c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 6;
  if (iVar2 == 0) {
    local_44 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0x142;
    uVar3 = XApplication__GetSurfaceList(0x142,1);
    local_44 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xd] = local_44;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 7;
  if (iVar2 == 0) {
    local_4c = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0x143;
    uVar3 = XApplication__GetSurfaceList(0x143,1);
    local_4c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xe] = local_4c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 8;
  if (iVar2 == 0) {
    local_54 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0x141;
    uVar3 = XApplication__GetSurfaceList(0x141,1);
    local_54 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0xf] = local_54;
  XProcessObject__StartFadeIn(0);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4295a0 | Symbol: XRegisterInfoObject::~XRegisterInfoObject
// ============================================================================
void XRegisterInfoObject___XRegisterInfoObject(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_004724bf;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XRegisterInfoObject::vftable;
  if (in_ECX[8] != 0) {
    if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[8])(1,uVar1);
    }
    in_ECX[8] = 0;
  }
  if (in_ECX[9] != 0) {
    if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[9])(1);
    }
    in_ECX[9] = 0;
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
  uVar2 = 0xd0;
  XApplication__GetSurfaceList(0xd0);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xd1;
  XApplication__GetSurfaceList(0xd1);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 200;
  XApplication__GetSurfaceList(200);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0x142;
  XApplication__GetSurfaceList(0x142);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0x143;
  XApplication__GetSurfaceList(0x143);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0x141;
  XApplication__GetSurfaceList(0x141);
  JSurfaceList__DestroySurface(uVar2);
  XProcessObject___XProcessObject();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x429860 | Symbol: XRegisterInfoObject::ProcessFrame
// ============================================================================
void XRegisterInfoObject__ProcessFrame(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_14;
  
  if (*(int *)(in_ECX + 8) != 0) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
    if (*(int *)(in_ECX + 8) == 1) {
      XProcessObject__ProcessFadeIn();
      if (0x77 < *(uint *)(in_ECX + 0xc)) {
        XProcessObject__StartProcess(0);
      }
    }
    else if ((*(int *)(in_ECX + 8) == 2) &&
            (XProcessObject__ProcessFadeOut(), 0x77 < *(uint *)(in_ECX + 0xc))) {
      XApplication__SetState(5);
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
    XTitleBackground__ProcessFrame(param_1);
    if (*(int *)(in_ECX + 8) == 3) {
      bVar1 = 0x18 < *(uint *)(in_ECX + 0xc) % 0x32;
      JSprite__SetCurrentFrame(bVar1);
      JSprite__SetCurrentFrame(bVar1);
      XApplication__GetDInput();
      JDInput__UpdateInputState();
      uVar2 = XApplication__GetDInput();
      local_14 = CheckButtonPressed(uVar2);
      uVar2 = 1;
      XApplication__GetDInput(1);
      iVar3 = JDInput__GetKeyboardPressed(uVar2);
      if (iVar3 != 0) {
        local_14 = 1;
      }
      if (local_14 != 0) {
        uVar5 = 0;
        uVar4 = 100;
        uVar2 = 0xed;
        XApplication__GetSoundList(0xed,100,0);
        JSoundList__Play(uVar2,uVar4,uVar5);
        XProcessObject__StartFadeOut(0);
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x4299d0 | Symbol: XRegisterInfoObject::Render
// ============================================================================
void XRegisterInfoObject__Render(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    XCamera__DoSetTransform();
    XTitleBackground__Render();
    iVar1 = CD3DApplication__GetScreenWidth();
    iVar1 = iVar1 / 2;
    iVar2 = CD3DApplication__GetScreenHeight();
    iVar2 = iVar2 / 2;
    JSprite__SetCenterPos(iVar1 + -0x9f,iVar2 + -0x5c);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    JSprite__SetCenterPos(iVar1 + 0x9f,iVar2 + -0x5c);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    JSprite__SetCenterPos(iVar1,iVar2 + 0x70);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    JSprite__SetCenterPos(iVar1,iVar2 + 0xd0);
    JSprite__SetCurrentFrame(1);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    if (*(int *)(in_ECX + 8) == 3) {
      iVar1 = JSprite__GetPosIntX();
      iVar2 = JSprite__GetWidth();
      iVar4 = JSprite__GetPosIntX();
      iVar5 = JSprite__GetWidth();
      iVar6 = JSprite__GetPosIntY();
      JSprite__SetPosition((iVar1 - iVar2 / 2) + -4,iVar6 + 2);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      JSprite__SetPosition(iVar4 + 4 + iVar5,iVar6 + 2);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
    if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 2)) {
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
  }
  return;
}

// ============================================================================
// Address: 0x429c10 | Symbol: XSelectLevelObject::XSelectLevelObject
// ============================================================================
undefined4 * XSelectLevelObject__XSelectLevelObject(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_6c;
  undefined4 local_64;
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
  puStack_c = &LAB_004725ac;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XProcessObject__XProcessObject(param_1);
  local_8 = 0;
  *in_ECX = XSelectLevelObject::vftable;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0xffffffff;
  in_ECX[0x17] = 0;
  uVar3 = 0;
  XApplication__GetMidiList(0,uVar1);
  JMidiList__Play(uVar3);
  uVar4 = 1;
  uVar3 = 0xd0;
  XApplication__GetSurfaceList(0xd0,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xd1;
  XApplication__GetSurfaceList(0xd1,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xce;
  XApplication__GetSurfaceList(0xce,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xcf;
  XApplication__GetSurfaceList(0xcf,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xf7;
  XApplication__GetSurfaceList(0xf7,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xb9;
  XApplication__GetSurfaceList(0xb9,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0x140;
  XApplication__GetSurfaceList(0x140,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xba;
  XApplication__GetSurfaceList(0xba,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xcd;
  XApplication__GetSurfaceList(0xcd,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xcc;
  XApplication__GetSurfaceList(0xcc,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 200;
  XApplication__GetSurfaceList(200,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  iVar2 = FUN_0042d23e(0x78);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = XCamera__XCamera(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[8] = local_1c;
  XCamera__ResetForTitle();
  iVar2 = FUN_0042d23e(0x1c);
  local_8._0_1_ = 2;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    uVar5 = 10;
    uVar4 = 0xba;
    uVar3 = XApplication__GetSurfaceList(0xba,10);
    local_24 = JNumber__JNumber(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x15] = local_24;
  JNumber__SetDisplayZero(1);
  JNumber__SetNumDigits(2);
  iVar2 = FUN_0042d23e(0x14);
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = XTitleBackground__XTitleBackground(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[9] = local_2c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 4;
  if (iVar2 == 0) {
    local_34 = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xd0;
    uVar3 = XApplication__GetSurfaceList(0xd0,2);
    local_34 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xb] = local_34;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 5;
  if (iVar2 == 0) {
    local_3c = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xd1;
    uVar3 = XApplication__GetSurfaceList(0xd1,2);
    local_3c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xc] = local_3c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 6;
  if (iVar2 == 0) {
    local_44 = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xce;
    uVar3 = XApplication__GetSurfaceList(0xce,2);
    local_44 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xd] = local_44;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 7;
  if (iVar2 == 0) {
    local_4c = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xcf;
    uVar3 = XApplication__GetSurfaceList(0xcf,2);
    local_4c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xe] = local_4c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 8;
  if (iVar2 == 0) {
    local_54 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0xf7;
    uVar3 = XApplication__GetSurfaceList(0xf7,1);
    local_54 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x12] = local_54;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 9;
  if (iVar2 == 0) {
    local_5c = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0xb9;
    uVar3 = XApplication__GetSurfaceList(0xb9,1);
    local_5c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x13] = local_5c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 10;
  if (iVar2 == 0) {
    local_64 = 0;
  }
  else {
    uVar5 = 3;
    uVar4 = 0x140;
    uVar3 = XApplication__GetSurfaceList(0x140,3);
    local_64 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x14] = local_64;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 0xb;
  if (iVar2 == 0) {
    local_6c = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xcd;
    uVar3 = XApplication__GetSurfaceList(0xcd,2);
    local_6c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0xf] = local_6c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 0xc;
  if (iVar2 == 0) {
    local_74 = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 0xcc;
    uVar3 = XApplication__GetSurfaceList(0xcc,2);
    local_74 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x10] = local_74;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 0xd;
  if (iVar2 == 0) {
    local_7c = 0;
  }
  else {
    uVar5 = 2;
    uVar4 = 200;
    uVar3 = XApplication__GetSurfaceList(200,2);
    local_7c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x11] = local_7c;
  XSelectLevelObject__CreatePreviewMap();
  XProcessObject__StartFadeIn(0);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x42a2c0 | Symbol: XSelectLevelObject::~XSelectLevelObject
// ============================================================================
void XSelectLevelObject___XSelectLevelObject(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 uVar2;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_004725cc;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XSelectLevelObject::vftable;
  if (in_ECX[8] != 0) {
    if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[8])(1,uVar1);
    }
    in_ECX[8] = 0;
  }
  if (in_ECX[0x15] != 0) {
    if ((undefined4 *)in_ECX[0x15] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x15])(1);
    }
    in_ECX[0x15] = 0;
  }
  if (in_ECX[9] != 0) {
    if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[9])(1);
    }
    in_ECX[9] = 0;
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
  if (in_ECX[0x12] != 0) {
    if ((undefined4 *)in_ECX[0x12] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x12])(1);
    }
    in_ECX[0x12] = 0;
  }
  if (in_ECX[0x13] != 0) {
    if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x13])(1);
    }
    in_ECX[0x13] = 0;
  }
  if (in_ECX[0x14] != 0) {
    if ((undefined4 *)in_ECX[0x14] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x14])(1);
    }
    in_ECX[0x14] = 0;
  }
  for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
    if (in_ECX[local_18 + 0xf] != 0) {
      if ((undefined4 *)in_ECX[local_18 + 0xf] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[local_18 + 0xf])(1);
      }
      in_ECX[local_18 + 0xf] = 0;
    }
  }
  uVar2 = 0xd0;
  XApplication__GetSurfaceList(0xd0);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xd1;
  XApplication__GetSurfaceList(0xd1);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xce;
  XApplication__GetSurfaceList(0xce);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xcf;
  XApplication__GetSurfaceList(0xcf);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xf7;
  XApplication__GetSurfaceList(0xf7);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xb9;
  XApplication__GetSurfaceList(0xb9);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0x140;
  XApplication__GetSurfaceList(0x140);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xba;
  XApplication__GetSurfaceList(0xba);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xcd;
  XApplication__GetSurfaceList(0xcd);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xcc;
  XApplication__GetSurfaceList(0xcc);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 200;
  XApplication__GetSurfaceList(200);
  JSurfaceList__DestroySurface(uVar2);
  XProcessObject___XProcessObject();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x42a700 | Symbol: XSelectLevelObject::ProcessFrame
// ============================================================================
void XSelectLevelObject__ProcessFrame(int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int in_ECX;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_10;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return;
  }
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  if (*(int *)(in_ECX + 8) == 1) {
    XProcessObject__ProcessFadeIn();
    if (0x77 < *(uint *)(in_ECX + 0xc)) {
      *(undefined4 *)(in_ECX + 0x58) = 0;
      XProcessObject__StartProcess(0);
    }
  }
  else if ((*(int *)(in_ECX + 8) == 2) &&
          (XProcessObject__ProcessFadeOut(), 0x77 < *(uint *)(in_ECX + 0xc))) {
    if (*(int *)(in_ECX + 0x18) == 0) {
      iVar5 = IsRegistered();
      if ((iVar5 == 0) &&
         (*(int *)(*(int *)(in_ECX + 4) + 0x1b0) < *(int *)(*(int *)(in_ECX + 4) + 0x1a8))) {
        XApplication__SetState(7);
        *(undefined4 *)(in_ECX + 8) = 0;
        return;
      }
      XApplication__SetState(6);
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
    if (*(int *)(in_ECX + 0x18) == 1) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x1a8) = 0;
      XApplication__SetState(4);
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
  }
  XTitleBackground__ProcessFrame(param_1);
  XPreviewMap__ProcessFrame(param_1);
  if (*(int *)(in_ECX + 8) != 3) {
    return;
  }
  bVar1 = 0x18 < *(uint *)(in_ECX + 0xc) % 0x32;
  JSprite__SetCurrentFrame(bVar1);
  JSprite__SetCurrentFrame(bVar1);
  JSprite__SetCurrentFrame(bVar1);
  JSprite__SetCurrentFrame(bVar1);
  XApplication__GetDInput();
  JDInput__UpdateInputState();
  uVar6 = 200;
  XApplication__GetDInput(200);
  iVar5 = JDInput__GetKeyboardPressed(uVar6);
  if (iVar5 == 0) {
    uVar7 = 0;
    uVar6 = 0;
    XApplication__GetDInput(0,0);
    iVar5 = JDInput__GetJoyDirPressed(uVar6,uVar7);
    if (iVar5 != 0) goto LAB_0042a8f8;
    bVar1 = false;
  }
  else {
LAB_0042a8f8:
    bVar1 = true;
  }
  uVar6 = 0xcd;
  XApplication__GetDInput(0xcd);
  iVar5 = JDInput__GetKeyboardPressed(uVar6);
  if (iVar5 == 0) {
    uVar7 = 1;
    uVar6 = 0;
    XApplication__GetDInput(0,1);
    iVar5 = JDInput__GetJoyDirPressed(uVar6,uVar7);
    if (iVar5 != 0) goto LAB_0042a943;
    bVar3 = false;
  }
  else {
LAB_0042a943:
    bVar3 = true;
  }
  uVar6 = 0xd0;
  XApplication__GetDInput(0xd0);
  iVar5 = JDInput__GetKeyboardPressed(uVar6);
  if (iVar5 == 0) {
    uVar7 = 2;
    uVar6 = 0;
    XApplication__GetDInput(0,2);
    iVar5 = JDInput__GetJoyDirPressed(uVar6,uVar7);
    if (iVar5 != 0) goto LAB_0042a98e;
    bVar4 = false;
  }
  else {
LAB_0042a98e:
    bVar4 = true;
  }
  uVar6 = 0xcb;
  XApplication__GetDInput(0xcb);
  iVar5 = JDInput__GetKeyboardPressed(uVar6);
  if (iVar5 == 0) {
    uVar7 = 3;
    uVar6 = 0;
    XApplication__GetDInput(0,3);
    iVar5 = JDInput__GetJoyDirPressed(uVar6,uVar7);
    if (iVar5 == 0) {
      bVar2 = false;
      goto LAB_0042a9e0;
    }
  }
  bVar2 = true;
LAB_0042a9e0:
  uVar6 = XApplication__GetDInput();
  local_10 = CheckButtonPressed(uVar6);
  if (*(int *)(in_ECX + 0x5c) == 0) {
    uVar6 = 1;
    XApplication__GetDInput(1);
    iVar5 = JDInput__GetKeyboardPressed(uVar6);
    if (iVar5 != 0) {
      *(undefined4 *)(in_ECX + 0x58) = 2;
      local_10 = 1;
    }
    if (bVar1) {
      uVar8 = 0;
      uVar7 = 100;
      uVar6 = 0xec;
      XApplication__GetSoundList(0xec,100,0);
      JSoundList__Play(uVar6,uVar7,uVar8);
      *(int *)(in_ECX + 0x58) = *(int *)(in_ECX + 0x58) + -1;
      if (*(int *)(in_ECX + 0x58) < 0) {
        *(undefined4 *)(in_ECX + 0x58) = 2;
      }
    }
    else if (bVar4) {
      uVar8 = 0;
      uVar7 = 100;
      uVar6 = 0xec;
      XApplication__GetSoundList(0xec,100,0);
      JSoundList__Play(uVar6,uVar7,uVar8);
      *(int *)(in_ECX + 0x58) = *(int *)(in_ECX + 0x58) + 1;
      if (2 < *(int *)(in_ECX + 0x58)) {
        *(undefined4 *)(in_ECX + 0x58) = 0;
      }
    }
    else if (local_10 != 0) {
      uVar8 = 0;
      uVar7 = 100;
      uVar6 = 0xed;
      XApplication__GetSoundList(0xed,100,0);
      JSoundList__Play(uVar6,uVar7,uVar8);
      if (*(int *)(in_ECX + 0x58) == 0) {
        XProcessObject__StartFadeOut(0);
      }
      else if (*(int *)(in_ECX + 0x58) == 1) {
        *(undefined4 *)(in_ECX + 0x5c) = 1;
      }
      else {
        XProcessObject__StartFadeOut(1);
      }
    }
  }
  else {
    uVar6 = 1;
    XApplication__GetDInput(1);
    iVar5 = JDInput__GetKeyboardPressed(uVar6);
    if (iVar5 != 0) {
      local_10 = 1;
    }
    if (bVar2) {
      uVar8 = 0;
      uVar7 = 100;
      uVar6 = 0xec;
      XApplication__GetSoundList(0xec,100,0);
      JSoundList__Play(uVar6,uVar7,uVar8);
      *(int *)(*(int *)(in_ECX + 4) + 0x1a8) = *(int *)(*(int *)(in_ECX + 4) + 0x1a8) + -1;
      if (*(int *)(*(int *)(in_ECX + 4) + 0x1a8) < 0) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x1a8) =
             *(undefined4 *)(*(int *)(in_ECX + 4) + 0x1ac);
      }
      XSelectLevelObject__CreatePreviewMap();
    }
    else if (bVar3) {
      uVar8 = 0;
      uVar7 = 100;
      uVar6 = 0xec;
      XApplication__GetSoundList(0xec,100,0);
      JSoundList__Play(uVar6,uVar7,uVar8);
      *(int *)(*(int *)(in_ECX + 4) + 0x1a8) = *(int *)(*(int *)(in_ECX + 4) + 0x1a8) + 1;
      if (*(int *)(*(int *)(in_ECX + 4) + 0x1ac) < *(int *)(*(int *)(in_ECX + 4) + 0x1a8)) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x1a8) = 0;
      }
      XSelectLevelObject__CreatePreviewMap();
    }
    else if (local_10 != 0) {
      uVar8 = 0;
      uVar7 = 100;
      uVar6 = 0xed;
      XApplication__GetSoundList(0xed,100,0);
      JSoundList__Play(uVar6,uVar7,uVar8);
      *(undefined4 *)(in_ECX + 0x5c) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x42ac50 | Symbol: XSelectLevelObject::Render
// ============================================================================
void XSelectLevelObject__Render(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int local_20;
  int local_14;
  int local_10;
  int local_c;
  
  if (*(int *)(in_ECX + 8) != 0) {
    XCamera__DoSetTransform();
    XTitleBackground__Render();
    XPreviewMap__Render();
    iVar1 = CD3DApplication__GetScreenWidth();
    iVar1 = iVar1 / 2;
    iVar2 = CD3DApplication__GetScreenHeight();
    iVar2 = iVar2 / 2;
    JSprite__SetPosition(iVar1 + -0x4c,iVar2 + -200);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    iVar4 = JSprite__GetWidth();
    JNumber__SetNumber(*(int *)(*(int *)(in_ECX + 4) + 0x1a8) + 1);
    JNumber__SetPosition(iVar1 + -0x44 + iVar4,iVar2 + -0xc6);
    uVar3 = CD3DApplication__GetBackBuffer();
    JNumber__Draw(uVar3);
    iVar4 = JSprite__GetWidth();
    local_c = iVar1 - (((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) *
                      *(int *)(*(int *)(in_ECX + 4) + 0x1b4)) / 2;
    iVar4 = JNumber__GetHeight();
    for (local_14 = 0; local_14 <= *(int *)(*(int *)(in_ECX + 4) + 0x1b4); local_14 = local_14 + 1)
    {
      if (local_14 == *(int *)(*(int *)(in_ECX + 4) + 0x1a8)) {
        JSprite__SetCurrentFrame(2);
      }
      else if (*(int *)(*(int *)(in_ECX + 4) + 0x1ac) < local_14) {
        JSprite__SetCurrentFrame(0);
      }
      else {
        JSprite__SetCurrentFrame(1);
      }
      JSprite__SetPosition(local_c,iVar2 + -0xb4 + iVar4);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      iVar5 = JSprite__GetWidth();
      local_c = ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + local_c;
    }
    local_20 = iVar2 + 0x6e;
    for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
      JSprite__SetCenterPos(iVar1,local_20);
      JSprite__SetCurrentFrame(*(int *)(in_ECX + 0x58) == local_10);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      iVar4 = JSprite__GetHeight();
      local_20 = local_20 + 8 + iVar4;
    }
    iVar4 = IsRegistered();
    if (iVar4 == 0) {
      JSprite__SetPosition(iVar1 + -0x138,iVar2 + 0xde);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
    if (*(int *)(in_ECX + 8) == 3) {
      if (*(int *)(in_ECX + 0x5c) == 0) {
        if (-1 < *(int *)(in_ECX + 0x58)) {
          iVar1 = JSprite__GetPosIntX();
          iVar2 = JSprite__GetWidth();
          iVar4 = JSprite__GetPosIntX();
          iVar5 = JSprite__GetWidth();
          iVar6 = JSprite__GetPosIntY();
          JSprite__SetPosition((iVar1 - iVar2 / 2) + -4,iVar6 + 2);
          uVar3 = CD3DApplication__GetBackBuffer();
          JSprite__Draw(uVar3);
          JSprite__SetPosition(iVar4 + 4 + iVar5,iVar6 + 2);
          uVar3 = CD3DApplication__GetBackBuffer();
          JSprite__Draw(uVar3);
        }
      }
      else {
        iVar1 = JSprite__GetPosIntX();
        iVar2 = JSprite__GetWidth();
        iVar4 = JNumber__GetPosX();
        iVar5 = JNumber__GetWidth();
        iVar6 = JSprite__GetPosIntY();
        JSprite__SetPosition((iVar1 - iVar2 / 2) + -6,iVar6 + 2);
        uVar3 = CD3DApplication__GetBackBuffer();
        JSprite__Draw(uVar3);
        JSprite__SetPosition(iVar4 + 6 + iVar5,iVar6 + 2);
        uVar3 = CD3DApplication__GetBackBuffer();
        JSprite__Draw(uVar3);
      }
    }
    if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 2)) {
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
  }
  return;
}

// ============================================================================
// Address: 0x42b110 | Symbol: XSelectLevelObject::CreatePreviewMap
// ============================================================================
void XSelectLevelObject__CreatePreviewMap(void)

{
  undefined2 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004725fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x28) != 0) {
    if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x28))(1,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
    }
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  iVar2 = FUN_0042d23e(0x20);
  local_8 = 0;
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else {
    uVar1 = GetMapResId(*(undefined4 *)(in_ECX + 4));
    local_20 = XPreviewMap__XPreviewMap(*(undefined4 *)(in_ECX + 4),uVar1);
  }
  *(undefined4 *)(in_ECX + 0x28) = local_20;
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x42b1f0 | Symbol: XTitleObject::XTitleObject
// ============================================================================
undefined4 * XTitleObject__XTitleObject(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_64;
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
  puStack_c = &LAB_004726bd;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XProcessObject__XProcessObject(param_1);
  local_8 = 0;
  *in_ECX = XTitleObject::vftable;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0xffffffff;
  uVar4 = 0;
  XApplication__GetMidiList(0,uVar1);
  JMidiList__Play(uVar4);
  uVar5 = 1;
  uVar4 = 0xd0;
  XApplication__GetSurfaceList(0xd0,1);
  JSurfaceList__CreateSurface(uVar4,uVar5);
  uVar5 = 1;
  uVar4 = 0xd1;
  XApplication__GetSurfaceList(0xd1,1);
  JSurfaceList__CreateSurface(uVar4,uVar5);
  uVar5 = 1;
  uVar4 = 0xdb;
  XApplication__GetSurfaceList(0xdb,1);
  JSurfaceList__CreateSurface(uVar4,uVar5);
  uVar5 = 1;
  uVar4 = 0xf8;
  XApplication__GetSurfaceList(0xf8,1);
  JSurfaceList__CreateSurface(uVar4,uVar5);
  uVar5 = 1;
  uVar4 = 0xf7;
  XApplication__GetSurfaceList(0xf7,1);
  JSurfaceList__CreateSurface(uVar4,uVar5);
  uVar5 = 1;
  uVar4 = 0xcd;
  XApplication__GetSurfaceList(0xcd,1);
  JSurfaceList__CreateSurface(uVar4,uVar5);
  uVar5 = 1;
  uVar4 = 0xc9;
  XApplication__GetSurfaceList(0xc9,1);
  JSurfaceList__CreateSurface(uVar4,uVar5);
  iVar2 = FUN_0042d23e(0x78);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = XCamera__XCamera(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[8] = local_1c;
  XCamera__ResetForTitle();
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 2;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = JObject3DX__JObject3DX(in_ECX[1],0x94);
  }
  local_8._0_1_ = 0;
  in_ECX[9] = local_24;
  (**(code **)(*(int *)in_ECX[9] + 0xc))(0,0xbfc90fdb);
  (**(code **)(*(int *)in_ECX[9] + 8))(0x432a0000);
  iVar2 = FUN_0042d23e(0x14);
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = XTitleBackground__XTitleBackground(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[10] = local_2c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 4;
  if (iVar2 == 0) {
    local_34 = 0;
  }
  else {
    uVar3 = 2;
    uVar5 = 0xd0;
    uVar4 = XApplication__GetSurfaceList(0xd0,2);
    local_34 = JSprite__JSprite(uVar4,uVar5,uVar3);
  }
  local_8._0_1_ = 0;
  in_ECX[0xb] = local_34;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 5;
  if (iVar2 == 0) {
    local_3c = 0;
  }
  else {
    uVar3 = 2;
    uVar5 = 0xd1;
    uVar4 = XApplication__GetSurfaceList(0xd1,2);
    local_3c = JSprite__JSprite(uVar4,uVar5,uVar3);
  }
  local_8._0_1_ = 0;
  in_ECX[0xc] = local_3c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 6;
  if (iVar2 == 0) {
    local_44 = 0;
  }
  else {
    uVar3 = 1;
    uVar5 = 0xdb;
    uVar4 = XApplication__GetSurfaceList(0xdb,1);
    local_44 = JSprite__JSprite(uVar4,uVar5,uVar3);
  }
  local_8._0_1_ = 0;
  in_ECX[0xf] = local_44;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 7;
  if (iVar2 == 0) {
    local_4c = 0;
  }
  else {
    uVar3 = 1;
    uVar5 = 0xf8;
    uVar4 = XApplication__GetSurfaceList(0xf8,1);
    local_4c = JSprite__JSprite(uVar4,uVar5,uVar3);
  }
  local_8._0_1_ = 0;
  in_ECX[0x10] = local_4c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 8;
  if (iVar2 == 0) {
    local_54 = 0;
  }
  else {
    uVar3 = 1;
    uVar5 = 0xf7;
    uVar4 = XApplication__GetSurfaceList(0xf7,1);
    local_54 = JSprite__JSprite(uVar4,uVar5,uVar3);
  }
  local_8._0_1_ = 0;
  in_ECX[0x11] = local_54;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 9;
  if (iVar2 == 0) {
    local_5c = 0;
  }
  else {
    uVar3 = 2;
    uVar5 = 0xcd;
    uVar4 = XApplication__GetSurfaceList(0xcd,2);
    local_5c = JSprite__JSprite(uVar4,uVar5,uVar3);
  }
  local_8._0_1_ = 0;
  in_ECX[0xd] = local_5c;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 10;
  if (iVar2 == 0) {
    local_64 = 0;
  }
  else {
    uVar3 = 2;
    uVar5 = 0xc9;
    uVar4 = XApplication__GetSurfaceList(0xc9,2);
    local_64 = JSprite__JSprite(uVar4,uVar5,uVar3);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0xe] = local_64;
  XProcessObject__StartFadeIn(0);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x42b6f0 | Symbol: XTitleObject::~XTitleObject
// ============================================================================
void XTitleObject___XTitleObject(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 uVar2;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_004726da;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XTitleObject::vftable;
  if (in_ECX[8] != 0) {
    if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[8])(1,uVar1);
    }
    in_ECX[8] = 0;
  }
  if (in_ECX[9] != 0) {
    if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[9])(1);
    }
    in_ECX[9] = 0;
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
  for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
    if (in_ECX[local_18 + 0xd] != 0) {
      if ((undefined4 *)in_ECX[local_18 + 0xd] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[local_18 + 0xd])(1);
      }
      in_ECX[local_18 + 0xd] = 0;
    }
  }
  uVar2 = 0xd0;
  XApplication__GetSurfaceList(0xd0);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xd1;
  XApplication__GetSurfaceList(0xd1);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xdb;
  XApplication__GetSurfaceList(0xdb);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xf8;
  XApplication__GetSurfaceList(0xf8);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xf7;
  XApplication__GetSurfaceList(0xf7);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xcd;
  XApplication__GetSurfaceList(0xcd);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xc9;
  XApplication__GetSurfaceList(0xc9);
  JSurfaceList__DestroySurface(uVar2);
  XProcessObject___XProcessObject();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x42ba20 | Symbol: XTitleObject::ProcessFrame
// ============================================================================
void XTitleObject__ProcessFrame(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_20;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return;
  }
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  if (*(int *)(in_ECX + 8) == 1) {
    XProcessObject__ProcessFadeIn();
    if (0x77 < *(uint *)(in_ECX + 0xc)) {
      *(undefined4 *)(in_ECX + 0x48) = 0;
      XProcessObject__StartProcess(0);
    }
  }
  else if ((*(int *)(in_ECX + 8) == 2) &&
          (XProcessObject__ProcessFadeOut(), 0x77 < *(uint *)(in_ECX + 0xc))) {
    if (*(int *)(in_ECX + 0x18) == 0) {
      XApplication__SetState(5);
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
    if (*(int *)(in_ECX + 0x18) == 1) {
      XApplication__SetState(1);
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
  }
  XTitleBackground__ProcessFrame(param_1);
  (**(code **)(**(int **)(in_ECX + 0x24) + 0xc))
            (1,(float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.010471975)
  ;
  if (*(int *)(in_ECX + 8) != 3) {
    return;
  }
  bVar1 = 0x18 < *(uint *)(in_ECX + 0xc) % 0x32;
  JSprite__SetCurrentFrame(bVar1);
  JSprite__SetCurrentFrame(bVar1);
  XApplication__GetDInput();
  JDInput__UpdateInputState();
  uVar4 = 200;
  XApplication__GetDInput(200);
  iVar3 = JDInput__GetKeyboardPressed(uVar4);
  if (iVar3 == 0) {
    uVar5 = 0;
    uVar4 = 0;
    XApplication__GetDInput(0,0);
    iVar3 = JDInput__GetJoyDirPressed(uVar4,uVar5);
    if (iVar3 != 0) goto LAB_0042bbdb;
    bVar1 = false;
  }
  else {
LAB_0042bbdb:
    bVar1 = true;
  }
  uVar4 = 0xd0;
  XApplication__GetDInput(0xd0);
  iVar3 = JDInput__GetKeyboardPressed(uVar4);
  if (iVar3 == 0) {
    uVar5 = 2;
    uVar4 = 0;
    XApplication__GetDInput(0,2);
    iVar3 = JDInput__GetJoyDirPressed(uVar4,uVar5);
    if (iVar3 == 0) {
      bVar2 = false;
      goto LAB_0042bc2d;
    }
  }
  bVar2 = true;
LAB_0042bc2d:
  uVar4 = XApplication__GetDInput();
  local_20 = CheckButtonPressed(uVar4);
  uVar4 = 1;
  XApplication__GetDInput(1);
  iVar3 = JDInput__GetKeyboardPressed(uVar4);
  if (iVar3 != 0) {
    *(undefined4 *)(in_ECX + 0x48) = 1;
    local_20 = 1;
  }
  if (bVar1) {
    uVar6 = 0;
    uVar5 = 100;
    uVar4 = 0xec;
    XApplication__GetSoundList(0xec,100,0);
    JSoundList__Play(uVar4,uVar5,uVar6);
    *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + -1;
    if (*(int *)(in_ECX + 0x48) < 0) {
      *(undefined4 *)(in_ECX + 0x48) = 1;
    }
  }
  else if (bVar2) {
    uVar6 = 0;
    uVar5 = 100;
    uVar4 = 0xec;
    XApplication__GetSoundList(0xec,100,0);
    JSoundList__Play(uVar4,uVar5,uVar6);
    *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + 1;
    if (1 < *(int *)(in_ECX + 0x48)) {
      *(undefined4 *)(in_ECX + 0x48) = 0;
    }
  }
  else if (local_20 != 0) {
    uVar6 = 0;
    uVar5 = 100;
    uVar4 = 0xed;
    XApplication__GetSoundList(0xed,100,0);
    JSoundList__Play(uVar4,uVar5,uVar6);
    if (*(int *)(in_ECX + 0x48) == 0) {
      XProcessObject__StartFadeOut(0);
    }
    else {
      XProcessObject__StartFadeOut(1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x42bd50 | Symbol: XTitleObject::Render
// ============================================================================
void XTitleObject__Render(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int local_18;
  int local_c;
  
  if (*(int *)(in_ECX + 8) != 0) {
    XCamera__DoSetTransform();
    XTitleBackground__Render();
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x14))();
    iVar1 = CD3DApplication__GetScreenWidth();
    iVar1 = iVar1 / 2;
    iVar2 = CD3DApplication__GetScreenHeight();
    iVar2 = iVar2 / 2;
    JSprite__SetCenterPos(iVar1,iVar2 + -0xa0);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    JSprite__SetCenterPos(iVar1,iVar2 + -0x5a);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    local_18 = iVar2 + 0x96;
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      JSprite__SetCenterPos(iVar1,local_18);
      JSprite__SetCurrentFrame(*(int *)(in_ECX + 0x48) == local_c);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      iVar4 = JSprite__GetHeight();
      local_18 = local_18 + 8 + iVar4;
    }
    iVar4 = IsRegistered();
    if (iVar4 == 0) {
      JSprite__SetPosition(iVar1 + -0x138,iVar2 + 0xde);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
    if ((*(int *)(in_ECX + 8) == 3) && (-1 < *(int *)(in_ECX + 0x48))) {
      iVar1 = JSprite__GetPosIntX();
      iVar2 = JSprite__GetWidth();
      iVar4 = JSprite__GetPosIntX();
      iVar5 = JSprite__GetWidth();
      iVar6 = JSprite__GetPosIntY();
      JSprite__SetPosition((iVar1 - iVar2 / 2) + -4,iVar6 + 2);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      JSprite__SetPosition(iVar4 + 4 + iVar5,iVar6 + 2);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
    if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 2)) {
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
  }
  return;
}

// ============================================================================
// Address: 0x42c030 | Symbol: XEndingObject::XEndingObject
// ============================================================================
undefined4 * XEndingObject__XEndingObject(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_90;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_20;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004727e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XProcessObject__XProcessObject(param_1);
  local_8 = 0;
  *in_ECX = XEndingObject::vftable;
  in_ECX[8] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0xffffffff;
  uVar3 = 0;
  XApplication__GetMidiList(0,uVar1);
  JMidiList__Play(uVar3);
  uVar4 = 1;
  uVar3 = 0x144;
  XApplication__GetSurfaceList(0x144,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0x145;
  XApplication__GetSurfaceList(0x145,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  uVar4 = 1;
  uVar3 = 0xf8;
  XApplication__GetSurfaceList(0xf8,1);
  JSurfaceList__CreateSurface(uVar3,uVar4);
  iVar2 = FUN_0042d23e(0x78);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = XCamera__XCamera(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[8] = local_20;
  XCamera__ResetForTitle();
  iVar2 = FUN_0042d23e(0x14);
  local_8._0_1_ = 2;
  if (iVar2 == 0) {
    local_28 = 0;
  }
  else {
    local_28 = XTitleBackground__XTitleBackground(in_ECX[1]);
  }
  local_8._0_1_ = 0;
  in_ECX[0x13] = local_28;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    local_30 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0x144;
    uVar3 = XApplication__GetSurfaceList(0x144,1);
    local_30 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x14] = local_30;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 4;
  if (iVar2 == 0) {
    local_38 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0x145;
    uVar3 = XApplication__GetSurfaceList(0x145,1);
    local_38 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x15] = local_38;
  iVar2 = FUN_0042d23e(0x2c);
  local_8._0_1_ = 5;
  if (iVar2 == 0) {
    local_40 = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0xf8;
    uVar3 = XApplication__GetSurfaceList(0xf8,1);
    local_40 = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8._0_1_ = 0;
  in_ECX[0x16] = local_40;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 6;
  if (iVar2 == 0) {
    local_48 = 0;
  }
  else {
    local_48 = JObject3DX__JObject3DX(in_ECX[1],0x94);
  }
  local_8._0_1_ = 0;
  in_ECX[9] = local_48;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 7;
  if (iVar2 == 0) {
    local_50 = 0;
  }
  else {
    local_50 = JObject3DX__JObject3DX(in_ECX[1],0x9d);
  }
  local_8._0_1_ = 0;
  in_ECX[10] = local_50;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 8;
  if (iVar2 == 0) {
    local_58 = 0;
  }
  else {
    local_58 = JObject3DX__JObject3DX(in_ECX[1],0xa4);
  }
  local_8._0_1_ = 0;
  in_ECX[0xb] = local_58;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 9;
  if (iVar2 == 0) {
    local_60 = 0;
  }
  else {
    local_60 = JObject3DX__JObject3DX(in_ECX[1],0xaf);
  }
  local_8._0_1_ = 0;
  in_ECX[0xc] = local_60;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 10;
  if (iVar2 == 0) {
    local_68 = 0;
  }
  else {
    local_68 = JObject3DX__JObject3DX(in_ECX[1],0xd4);
  }
  local_8._0_1_ = 0;
  in_ECX[0xd] = local_68;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 0xb;
  if (iVar2 == 0) {
    local_70 = 0;
  }
  else {
    local_70 = JObject3DX__JObject3DX(in_ECX[1],0xad);
  }
  local_8._0_1_ = 0;
  in_ECX[0xe] = local_70;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 0xc;
  if (iVar2 == 0) {
    local_78 = 0;
  }
  else {
    local_78 = JObject3DX__JObject3DX(in_ECX[1],0xac);
  }
  local_8._0_1_ = 0;
  in_ECX[0xf] = local_78;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 0xd;
  if (iVar2 == 0) {
    local_80 = 0;
  }
  else {
    local_80 = JObject3DX__JObject3DX(in_ECX[1],0xa6);
  }
  local_8._0_1_ = 0;
  in_ECX[0x10] = local_80;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 0xe;
  if (iVar2 == 0) {
    local_88 = 0;
  }
  else {
    local_88 = JObject3DX__JObject3DX(in_ECX[1],0xb3);
  }
  local_8._0_1_ = 0;
  in_ECX[0x11] = local_88;
  iVar2 = FUN_0042d23e(0x5c);
  local_8._0_1_ = 0xf;
  if (iVar2 == 0) {
    local_90 = 0;
  }
  else {
    local_90 = JObject3DX__JObject3DX(in_ECX[1],0xb1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x12] = local_90;
  for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
    (**(code **)(*(int *)in_ECX[local_18 + 9] + 0xc))(0,0xbfc90fdb);
  }
  in_ECX[0x18] = 0x43340000;
  in_ECX[0x19] = (float)in_ECX[0x18] * 1.0;
  in_ECX[0x1a] = (float)in_ECX[0x18] * 1.5;
  in_ECX[0x1b] = (float)in_ECX[0x18] * 1.78;
  in_ECX[0x1c] = (float)in_ECX[0x18] * 1.1;
  in_ECX[0x1d] = (float)in_ECX[0x18] * 1.6;
  in_ECX[0x1e] = (float)in_ECX[0x18] * 1.4;
  in_ECX[0x1f] = (float)in_ECX[0x18] * 1.4;
  in_ECX[0x20] = (float)in_ECX[0x18] * 0.65;
  in_ECX[0x21] = (float)in_ECX[0x18] * 0.7;
  XProcessObject__StartFadeIn(0);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x42c850 | Symbol: XEndingObject::~XEndingObject
// ============================================================================
void XEndingObject___XEndingObject(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 uVar2;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00472808;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XEndingObject::vftable;
  if (in_ECX[8] != 0) {
    if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[8])(1,uVar1);
    }
    in_ECX[8] = 0;
  }
  if (in_ECX[0x13] != 0) {
    if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x13])(1);
    }
    in_ECX[0x13] = 0;
  }
  if (in_ECX[0x14] != 0) {
    if ((undefined4 *)in_ECX[0x14] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x14])(1);
    }
    in_ECX[0x14] = 0;
  }
  if (in_ECX[0x15] != 0) {
    if ((undefined4 *)in_ECX[0x15] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x15])(1);
    }
    in_ECX[0x15] = 0;
  }
  if (in_ECX[0x16] != 0) {
    if ((undefined4 *)in_ECX[0x16] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x16])(1);
    }
    in_ECX[0x16] = 0;
  }
  for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
    if (in_ECX[local_18 + 9] != 0) {
      if ((undefined4 *)in_ECX[local_18 + 9] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[local_18 + 9])(1);
      }
      in_ECX[local_18 + 9] = 0;
    }
  }
  uVar2 = 0x144;
  XApplication__GetSurfaceList(0x144);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0x145;
  XApplication__GetSurfaceList(0x145);
  JSurfaceList__DestroySurface(uVar2);
  uVar2 = 0xf8;
  XApplication__GetSurfaceList(0xf8);
  JSurfaceList__DestroySurface(uVar2);
  XProcessObject___XProcessObject();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x42ca70 | Symbol: XEndingObject::ProcessFrame
// ============================================================================
void XEndingObject__ProcessFrame(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_24;
  float local_c;
  
  if (*(int *)(in_ECX + 8) != 0) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
    if (*(int *)(in_ECX + 8) == 1) {
      XProcessObject__ProcessFadeIn();
      if (0x77 < *(uint *)(in_ECX + 0xc)) {
        XProcessObject__StartProcess(0);
      }
    }
    else if ((*(int *)(in_ECX + 8) == 2) &&
            (XProcessObject__ProcessFadeOut(), 0x77 < *(uint *)(in_ECX + 0xc))) {
      XApplication__SetState(3);
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
    XTitleBackground__ProcessFrame(param_1);
    if (*(int *)(in_ECX + 8) == 3) {
      uVar3 = *(uint *)(in_ECX + 0xc) % 8000;
      *(uint *)(in_ECX + 0x5c) = uVar3 / 800;
      uVar3 = uVar3 % 800;
      if (uVar3 < 100) {
        local_c = (((float)uVar3 + 0.0) / 100.0) *
                  *(float *)(in_ECX + 0x60 + *(int *)(in_ECX + 0x5c) * 4);
      }
      else if (uVar3 < 700) {
        local_c = *(float *)(in_ECX + 0x60 + *(int *)(in_ECX + 0x5c) * 4);
      }
      else {
        local_c = ((float)((double)(int)(800 - uVar3) +
                          (double)(&DAT_00473840)[-((int)(800 - uVar3) >> 0x1f)]) / 100.0) *
                  *(float *)(in_ECX + 0x60 + *(int *)(in_ECX + 0x5c) * 4);
      }
      if (local_c < 1.0) {
        local_c = 1.0;
      }
      JObject3DBase__ScaleTo(local_c);
      (**(code **)(**(int **)(in_ECX + 0x24 + *(int *)(in_ECX + 0x5c) * 4) + 0xc))
                (1,(float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) *
                   0.013962634);
      XApplication__GetDInput();
      JDInput__UpdateInputState();
      uVar1 = XApplication__GetDInput();
      local_24 = CheckButtonPressed(uVar1);
      uVar1 = 1;
      XApplication__GetDInput(1);
      iVar2 = JDInput__GetKeyboardPressed(uVar1);
      if (iVar2 != 0) {
        local_24 = 1;
      }
      if (local_24 != 0) {
        uVar5 = 0;
        uVar4 = 100;
        uVar1 = 0xed;
        XApplication__GetSoundList(0xed,100,0);
        JSoundList__Play(uVar1,uVar4,uVar5);
        XProcessObject__StartFadeOut(0);
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x42cd00 | Symbol: XEndingObject::Render
// ============================================================================
void XEndingObject__Render(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    XCamera__DoSetTransform();
    XTitleBackground__Render();
    if (-1 < *(int *)(in_ECX + 0x5c)) {
      (**(code **)(**(int **)(in_ECX + 0x24 + *(int *)(in_ECX + 0x5c) * 4) + 0x14))();
    }
    iVar1 = CD3DApplication__GetScreenWidth();
    iVar1 = iVar1 / 2;
    iVar2 = CD3DApplication__GetScreenHeight();
    iVar2 = iVar2 / 2;
    JSprite__SetCenterPos(iVar1,iVar2 + -0xa0);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    JSprite__SetCenterPos(iVar1,iVar2 + 0x3c);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    JSprite__SetCenterPos(iVar1,iVar2 + 0xbe);
    uVar3 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar3);
    if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 2)) {
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
      uVar3 = CD3DApplication__GetBackBuffer();
      JSprite__Draw(uVar3);
    }
  }
  return;
}

// ============================================================================
// Address: 0x42ce50 | Symbol: CheckButtonPressed
// ============================================================================
undefined4 CheckButtonPressed(void)

{
  int iVar1;
  
  iVar1 = JDInput__GetKeyboardPressed(0x9c);
  if ((((((iVar1 == 0) && (iVar1 = JDInput__GetKeyboardPressed(0x1c), iVar1 == 0)) &&
        (iVar1 = JDInput__GetKeyboardPressed(0x2a), iVar1 == 0)) &&
       ((iVar1 = JDInput__GetKeyboardPressed(0x36), iVar1 == 0 &&
        (iVar1 = JDInput__GetKeyboardPressed(0x1d), iVar1 == 0)))) &&
      ((iVar1 = JDInput__GetKeyboardPressed(0x9d), iVar1 == 0 &&
       ((iVar1 = JDInput__GetKeyboardPressed(0x2c), iVar1 == 0 &&
        (iVar1 = JDInput__GetKeyboardPressed(0x2d), iVar1 == 0)))))) &&
     ((iVar1 = JDInput__GetJoyButtonPressed(0,0), iVar1 == 0 &&
      (iVar1 = JDInput__GetJoyButtonPressed(0,1), iVar1 == 0)))) {
    return 0;
  }
  return 1;
}

// ============================================================================
// Address: 0x42cf00 | Symbol: Concurrency::details::SchedulingNode::XEndingObject::
// ============================================================================
/* Library Function - Single Match
    public: void * __thiscall Concurrency::details::SchedulingNode::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::SchedulingNode::XEndingObject__(SchedulingNode *this,uint param_1)

{
  XEndingObject___XEndingObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x88);
  }
  return this;
}

// ============================================================================
// Address: 0x42cf40 | Symbol: XLogoObject::
// ============================================================================
undefined4 XLogoObject__(uint param_1)

{
  undefined4 in_ECX;
  
  XLogoObject___XLogoObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x2c);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x42cf70 | Symbol: XRegisterInfoObject::
// ============================================================================
/* Library Function - Multiple Matches With Same Base Name
    public: virtual void * __thiscall `unsigned int __cdecl Concurrency::_Receive_impl<unsigned
   int>(class Concurrency::ISource<unsigned int> *,unsigned int,class std::function<bool
   __cdecl(unsigned int const &)> const *)'::`2'::_Blocking_recipient::`scalar deleting
   destructor'(unsigned int)
    public: virtual void * __thiscall `enum Concurrency::agent_status __cdecl
   Concurrency::_Receive_impl<enum Concurrency::agent_status>(class Concurrency::ISource<enum
   Concurrency::agent_status> *,unsigned int,class std::function<bool __cdecl(enum
   Concurrency::agent_status const &)> const *)'::`2'::_Blocking_recipient::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4 XRegisterInfoObject__(uint param_1)

{
  undefined4 in_ECX;
  
  XRegisterInfoObject___XRegisterInfoObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x40);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x42cfa0 | Symbol: XSelectLevelObject::
// ============================================================================
undefined4 XSelectLevelObject__(uint param_1)

{
  undefined4 in_ECX;
  
  XSelectLevelObject___XSelectLevelObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x60);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x42cfd0 | Symbol: XTitleBackground::
// ============================================================================
undefined4 XTitleBackground__(uint param_1)

{
  undefined4 in_ECX;
  
  XTitleBackground___XTitleBackground();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x14);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x42d000 | Symbol: Concurrency::details::CachedTransmogrifiedPrimary::XTitleObject::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::CachedTransmogrifiedPrimary::`scalar
   deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::CachedTransmogrifiedPrimary::XTitleObject__
          (CachedTransmogrifiedPrimary *this,uint param_1)

{
  XTitleObject___XTitleObject();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x4c);
  }
  return this;
}
