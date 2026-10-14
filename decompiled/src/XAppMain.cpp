// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XAppMain.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XAppMain.h"

// ============================================================================
// Address: 0x415e20 | Symbol: WinMain
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 WinMain(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE hMutex;
  DWORD DVar1;
  undefined4 uVar2;
  int iVar3;
  
  hMutex = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,"JJsoft Hopmon Mutex");
  DVar1 = GetLastError();
  if (DVar1 == 0xb7) {
    MessageBoxA((HWND)0x0,"HOPMON is already running.","Hopmon",0x30);
    uVar2 = 0;
  }
  else {
    XApplication__XApplication();
    iVar3 = XApplication__Create(param_1,param_3);
    if (iVar3 < 0) {
      XApplication___XApplication();
      uVar2 = 0;
    }
    else {
      uVar2 = CD3DApplication__Run();
      ReleaseMutex(hMutex);
      CloseHandle(hMutex);
      XApplication___XApplication();
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x415f10 | Symbol: XFPSDisplay::XFPSDisplay
// ============================================================================
undefined4 * XFPSDisplay__XFPSDisplay(undefined4 param_1)

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
  puStack_c = &LAB_00471233;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XFPSDisplay::vftable;
  in_ECX[1] = param_1;
  iVar2 = FUN_0042d23e(0x2c,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    uVar5 = 1;
    uVar4 = 0xbf;
    uVar3 = XApplication__GetSurfaceList(0xbf,1);
    local_1c = JSprite__JSprite(uVar3,uVar4,uVar5);
  }
  local_8 = 0xffffffff;
  in_ECX[2] = local_1c;
  iVar2 = FUN_0042d23e(0x1c,uVar1);
  local_8 = 1;
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    uVar5 = 10;
    uVar4 = 0xbb;
    uVar3 = XApplication__GetSurfaceList(0xbb,10);
    local_24 = JNumber__JNumber(uVar3,uVar4,uVar5);
  }
  local_8 = 0xffffffff;
  in_ECX[3] = local_24;
  JNumber__SetDisplayZero(1);
  JNumber__SetNumDigits(3);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x416030 | Symbol: XFPSDisplay::~XFPSDisplay
// ============================================================================
void XFPSDisplay___XFPSDisplay(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XFPSDisplay::vftable;
  return;
}

// ============================================================================
// Address: 0x416050 | Symbol: XFPSDisplay::Render
// ============================================================================
void XFPSDisplay__Render(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = CD3DApplication__DisplayFPS();
  if (iVar1 != 0) {
    iVar1 = CD3DApplication__GetScreenWidth();
    JSprite__SetPosition(iVar1 + -0x5a,4);
    uVar2 = CD3DApplication__GetBackBuffer();
    JSprite__Draw(uVar2);
    iVar3 = JSprite__GetWidth();
    JNumber__SetPosition(iVar1 + -0x56 + iVar3,4);
    uVar2 = CD3DApplication__GetFPS();
    JNumber__SetNumber(uVar2);
    uVar2 = CD3DApplication__GetBackBuffer();
    JNumber__Draw(uVar2);
  }
  return;
}

// ============================================================================
// Address: 0x416110 | Symbol: XApplication::XApplication
// ============================================================================
undefined4 * XApplication__XApplication(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 local_24;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471273;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CD3DApplication__CD3DApplication(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  *in_ECX = XApplication::vftable;
  in_ECX[0x6a] = 0;
  in_ECX[0x6b] = 0;
  in_ECX[0x6c] = 9;
  in_ECX[0x6d] = 0x2c;
  iVar1 = FUN_0042d23e(0x10);
  local_8 = 0;
  if (iVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JStringList__JStringList();
  }
  local_8 = 0xffffffff;
  in_ECX[0x6e] = local_1c;
  in_ECX[0x79] = 0;
  in_ECX[0x7a] = 0;
  in_ECX[0x7b] = 0;
  in_ECX[0x7c] = 0;
  in_ECX[0x7d] = 0;
  in_ECX[0x7e] = 0;
  in_ECX[0x7f] = 0;
  XApplication___DisableStickyKeys();
  in_ECX[0x30] = "SAITOGAMES_HOPMON_CLASS";
  in_ECX[0x31] = "Hopmon";
  in_ECX[0x32] = 1;
  in_ECX[0x39] = XApplication__ConfirmDevice;
  iVar1 = FUN_0042d23e(0xc);
  local_8 = 1;
  if (iVar1 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = JSurfaceList__JSurfaceList(in_ECX);
  }
  local_8 = 0xffffffff;
  in_ECX[0x7d] = local_24;
  XApplication__LoadWinRegData();
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4162c0 | Symbol: XApplication::~XApplication
// ============================================================================
void XApplication___XApplication(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00471290;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XApplication::vftable;
  XApplication__SaveWinRegData(uVar1);
  DeleteRegisterInfo();
  XApplication___RestoreStickyKeys();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x416320 | Symbol: XApplication::LoadWinRegData
// ============================================================================
void XApplication__LoadWinRegData(void)

{
  undefined1 local_30 [8];
  undefined1 local_28 [16];
  int local_18;
  ushort local_14 [2];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004712ca;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  LoadRegisterInfo("Software\\SaitoGames\\Hopmon",DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  JWinReg__JWinReg();
  local_8 = 0;
  FUN_00413970("Software\\SaitoGames\\Hopmon");
  local_8._0_1_ = 1;
  JWinReg__Create(0x80000001,local_28);
  local_8._0_1_ = 0;
  JString___JString();
  local_14[0] = 0;
  FUN_00413970("Level");
  local_8._0_1_ = 2;
  JWinReg__GetWord(local_30,local_14);
  local_8 = (uint)local_8._1_3_ << 8;
  JString___JString();
  *(uint *)(local_18 + 0x1ac) = (uint)local_14[0];
  if ((*(int *)(local_18 + 0x1ac) < 0) || (*(int *)(local_18 + 0x1b4) < *(int *)(local_18 + 0x1ac)))
  {
    *(undefined4 *)(local_18 + 0x1ac) = 0;
  }
  local_8 = 0xffffffff;
  JWinReg___JWinReg();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x416420 | Symbol: XApplication::SaveWinRegData
// ============================================================================
void XApplication__SaveWinRegData(void)

{
  undefined1 local_30 [8];
  undefined1 local_28 [16];
  int local_18;
  undefined2 local_12;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471304;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  SaveRegisterInfo("Software\\SaitoGames\\Hopmon",DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  JWinReg__JWinReg();
  local_8 = 0;
  FUN_00413970("Software\\SaitoGames\\Hopmon");
  local_8._0_1_ = 1;
  JWinReg__Create(0x80000001,local_28);
  local_8._0_1_ = 0;
  JString___JString();
  local_12 = *(undefined2 *)(local_18 + 0x1ac);
  FUN_00413970("Level");
  local_8._0_1_ = 2;
  JWinReg__SetWord(local_30,&local_12);
  local_8 = (uint)local_8._1_3_ << 8;
  JString___JString();
  local_8 = 0xffffffff;
  JWinReg___JWinReg();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x4164f0 | Symbol: XApplication::SetState
// ============================================================================
void XApplication__SetState(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1e4) = param_1;
  return;
}

// ============================================================================
// Address: 0x416510 | Symbol: XApplication::GetCurrentWorld
// ============================================================================
int XApplication__GetCurrentWorld(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x1a8) / 0xf;
}

// ============================================================================
// Address: 0x416530 | Symbol: XApplication::GetDInput
// ============================================================================
undefined4 XApplication__GetDInput(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1e8);
}

// ============================================================================
// Address: 0x416550 | Symbol: XApplication::GetMidiList
// ============================================================================
undefined4 XApplication__GetMidiList(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1ec);
}

// ============================================================================
// Address: 0x416570 | Symbol: XApplication::GetSoundList
// ============================================================================
undefined4 XApplication__GetSoundList(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1f0);
}

// ============================================================================
// Address: 0x416590 | Symbol: XApplication::GetSurfaceList
// ============================================================================
undefined4 XApplication__GetSurfaceList(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 500);
}

// ============================================================================
// Address: 0x4165b0 | Symbol: XApplication::Create
// ============================================================================
int XApplication__Create(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471368;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = CD3DApplication__Create(param_1,param_2);
  if (-1 < iVar2) {
    iVar2 = FUN_0042d23e(0x4a8,uVar1);
    local_8 = 0;
    if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = JDInput__JDInput(*(undefined4 *)(in_ECX + 0x28));
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x1e8) = local_20;
    iVar2 = JDInput__Create();
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0042d23e(0x14,uVar1);
      local_8 = 1;
      if (iVar2 == 0) {
        local_28 = 0;
      }
      else {
        local_28 = JMidiList__JMidiList(*(undefined4 *)(in_ECX + 0x28));
      }
      local_8 = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x1ec) = local_28;
      JMidiList__Append("Music01.mid");
      JMidiList__Append("Music02.mid");
      JMidiList__Append("Music03.mid");
      JMidiList__Append("Music04.mid");
      iVar2 = FUN_0042d23e(0x84);
      local_8 = 2;
      if (iVar2 == 0) {
        local_30 = 0;
      }
      else {
        local_30 = JSoundList__JSoundList(*(undefined4 *)(in_ECX + 0x28));
      }
      local_8 = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x1f0) = local_30;
      JSoundList__Create();
      FUN_00412c70(0xf3,4);
      FUN_00412c70(0xf4,4);
      FUN_00412c70(0xf5,4);
      FUN_00412c70(0x13e,4);
      FUN_00412c70(0x13f,2);
      FUN_00412c70(0xeb,1);
      FUN_00412c70(0xea,1);
      FUN_00412c70(0xff,1);
      FUN_00412c70(0xee,1);
      FUN_00412c70(0xef,1);
      FUN_00412c70(0xf0,1);
      FUN_00412c70(0xf1,1);
      FUN_00412c70(0xe8,1);
      FUN_00412c70(0xe9,1);
      FUN_00412c70(0xfe,1);
      FUN_00412c70(0xec,1);
      FUN_00412c70(0xed,1);
      FUN_00412c70(0x13d,1);
      JSurfaceList__CreateSurface(0xc3,0);
      JSurfaceList__CreateSurface(0xc2,0);
      JSurfaceList__CreateSurface(0xbf,1);
      JSurfaceList__CreateSurface(0xbb,1);
      iVar2 = FUN_0042d23e(0x10);
      local_8 = 3;
      if (iVar2 == 0) {
        local_38 = 0;
      }
      else {
        local_38 = XFPSDisplay__XFPSDisplay(in_ECX);
      }
      *(undefined4 *)(in_ECX + 0x1fc) = local_38;
      *(undefined4 *)(in_ECX + 0x1e4) = 3;
      iVar2 = 0;
    }
  }
  ExceptionList = local_10;
  return iVar2;
}

// ============================================================================
// Address: 0x4169a0 | Symbol: XApplication::MsgProc
// ============================================================================
undefined4 XApplication__MsgProc(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_2 < 0x113) {
    if (param_2 == 0x112) {
      if (param_3 == 0xf100) {
        return 0;
      }
    }
    else if (param_2 == 0x1c) {
      if (param_3 == 1) {
        if (*(int *)(in_ECX + 0x1ec) != 0) {
          JMidiList__Resume();
        }
        if (*(int *)(in_ECX + 0x1e8) != 0) {
          JDInput__SetAcquireKeyboard(1);
          JDInput__SetAcquireJoystick(1);
        }
      }
      else {
        if (*(int *)(in_ECX + 0x1ec) != 0) {
          JMidiList__Pause();
        }
        if (*(int *)(in_ECX + 0x1e8) != 0) {
          JDInput__SetAcquireKeyboard(0);
          JDInput__SetAcquireJoystick(0);
        }
      }
    }
    else if ((param_2 == 0x100) && (param_3 == 0x50)) {
      PostMessageA(*(HWND *)(in_ECX + 0x28),0x111,0x9c44,0);
    }
  }
  else if (((param_2 == 0x3b9) && (param_3 == 1)) && (*(int *)(in_ECX + 0x1ec) != 0)) {
    JMidiList__Replay();
  }
  uVar1 = CD3DApplication__MsgProc(param_1,param_2,param_3,param_4);
  return uVar1;
}

// ============================================================================
// Address: 0x416b00 | Symbol: XApplication::OneTimeSceneInit
// ============================================================================
undefined4 XApplication__OneTimeSceneInit(void)

{
  D3DTextr_CreateTextureFromResource(0x9c,0,0);
  D3DTextr_CreateTextureFromResource(0xfb,0,0);
  D3DTextr_CreateTextureFromResource(0xfc,0,0);
  D3DTextr_CreateTextureFromResource(0xa0,0,0);
  D3DTextr_CreateTextureFromResource(0xa1,0,0);
  D3DTextr_CreateTextureFromResource(0xa9,0,0);
  D3DTextr_CreateTextureFromResource(0xaa,0,0);
  D3DTextr_CreateTextureFromResource(0xb6,0,0);
  D3DTextr_CreateTextureFromResource(0xb7,0,0);
  D3DTextr_CreateTextureFromResource(0xdc,2,0);
  D3DTextr_CreateTextureFromResource(0xa2,0,0);
  D3DTextr_CreateTextureFromResource(0xa3,0,0);
  D3DTextr_CreateTextureFromResource(0xc1,0,0);
  D3DTextr_CreateTextureFromResource(0x14c,0,0);
  return 0;
}

// ============================================================================
// Address: 0x416c00 | Symbol: XApplication::InitDeviceObjects
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 XApplication__InitDeviceObjects(void)

{
  undefined1 local_b4 [64];
  int local_74;
  undefined1 local_70 [104];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  JSurfaceList__RestoreAllSurfaces();
  D3DTextr_RestoreAllTextures(*(undefined4 *)(local_74 + 0x38));
  (**(code **)(**(int **)(local_74 + 0x38) + 0x50))(*(undefined4 *)(local_74 + 0x38),0x1b,0);
  (**(code **)(**(int **)(local_74 + 0x38) + 0x50))(*(undefined4 *)(local_74 + 0x38),0x1a,1);
  (**(code **)(**(int **)(local_74 + 0x38) + 0x50))(*(undefined4 *)(local_74 + 0x38),0x89,1);
  (**(code **)(**(int **)(local_74 + 0x38) + 0x50))(*(undefined4 *)(local_74 + 0x38),7,1);
  _D3DMATRIX___D3DMATRIX();
  D3DUtil_SetProjectionMatrix(local_b4,0x3f3ba866,0x3f400000,0x41200000,0x44fa0000);
  (**(code **)(**(int **)(local_74 + 0x38) + 0x2c))(*(undefined4 *)(local_74 + 0x38),3,local_b4);
  _D3DLIGHT7___D3DLIGHT7();
  FUN_0040c170(local_70,3,0x3f451eb8,0x3dcccccd,0x3f000000,0xbf800000,0x3f000000);
  (**(code **)(**(int **)(local_74 + 0x38) + 0x48))(*(undefined4 *)(local_74 + 0x38),0,local_70);
  (**(code **)(**(int **)(local_74 + 0x38) + 0xb0))(*(undefined4 *)(local_74 + 0x38),0,1);
  (**(code **)(**(int **)(local_74 + 0x38) + 0x50))
            (*(undefined4 *)(local_74 + 0x38),0x8b,0xff898989);
  return 0;
}

// ============================================================================
// Address: 0x416dd0 | Symbol: XApplication::DeleteDeviceObjects
// ============================================================================
undefined4 XApplication__DeleteDeviceObjects(void)

{
  JSurfaceList__InvalidateAllSurfaces();
  D3DTextr_InvalidateAllTextures();
  return 0;
}

// ============================================================================
// Address: 0x416df0 | Symbol: XApplication::Render
// ============================================================================
undefined4 XApplication__Render(void)

{
  int iVar1;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x38) + 0x28))
            (*(undefined4 *)(in_ECX + 0x38),0,0,3,0x2d1d62,0x3f800000,0);
  if (*(int *)(in_ECX + 0x1e4) == 2) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x38) + 0x14))(*(undefined4 *)(in_ECX + 0x38));
    if (-1 < iVar1) {
      (**(code **)(**(int **)(in_ECX + 0x1f8) + 8))();
      XFPSDisplay__Render();
      (**(code **)(**(int **)(in_ECX + 0x38) + 0x18))(*(undefined4 *)(in_ECX + 0x38));
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x416e90 | Symbol: XApplication::FrameMove
// ============================================================================
undefined4 XApplication__FrameMove(uint param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_5c;
  undefined4 local_54;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_34;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004713e7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x14 < param_1) {
    param_1 = 0x14;
  }
  if (*(int *)(in_ECX + 0x1e4) == 2) {
    (**(code **)(**(int **)(in_ECX + 0x1f8) + 4))(param_1,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  }
  if (*(int *)(in_ECX + 0x1e4) == 3) {
    if (*(int *)(in_ECX + 0x1f8) != 0) {
      if (*(undefined4 **)(in_ECX + 0x1f8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x1f8))(1);
      }
      *(undefined4 *)(in_ECX + 0x1f8) = 0;
    }
    iVar1 = FUN_0042d23e(0x2c);
    local_8 = 0;
    if (iVar1 == 0) {
      local_34 = 0;
    }
    else {
      local_34 = XLogoObject__XLogoObject(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x1f8) = local_34;
    *(undefined4 *)(in_ECX + 0x1e4) = 2;
  }
  else if (*(int *)(in_ECX + 0x1e4) == 4) {
    if (*(int *)(in_ECX + 0x1f8) != 0) {
      if (*(undefined4 **)(in_ECX + 0x1f8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x1f8))(1);
      }
      *(undefined4 *)(in_ECX + 0x1f8) = 0;
    }
    iVar1 = FUN_0042d23e(0x4c);
    local_8 = 1;
    if (iVar1 == 0) {
      local_3c = 0;
    }
    else {
      local_3c = XTitleObject__XTitleObject(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x1f8) = local_3c;
    *(undefined4 *)(in_ECX + 0x1e4) = 2;
  }
  else if (*(int *)(in_ECX + 0x1e4) == 5) {
    if (*(int *)(in_ECX + 0x1f8) != 0) {
      if (*(undefined4 **)(in_ECX + 0x1f8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x1f8))(1);
      }
      *(undefined4 *)(in_ECX + 0x1f8) = 0;
    }
    iVar1 = FUN_0042d23e(0x60);
    local_8 = 2;
    if (iVar1 == 0) {
      local_44 = 0;
    }
    else {
      local_44 = XSelectLevelObject__XSelectLevelObject(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x1f8) = local_44;
    *(undefined4 *)(in_ECX + 0x1e4) = 2;
  }
  else if (*(int *)(in_ECX + 0x1e4) == 6) {
    if (*(int *)(in_ECX + 0x1f8) != 0) {
      if (*(undefined4 **)(in_ECX + 0x1f8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x1f8))(1);
      }
      *(undefined4 *)(in_ECX + 0x1f8) = 0;
    }
    iVar1 = FUN_0042d23e(0x48);
    local_8 = 3;
    if (iVar1 == 0) {
      local_4c = 0;
    }
    else {
      local_4c = XGameObject__XGameObject(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x1f8) = local_4c;
    *(undefined4 *)(in_ECX + 0x1e4) = 2;
  }
  else if (*(int *)(in_ECX + 0x1e4) == 7) {
    if (*(int *)(in_ECX + 0x1f8) != 0) {
      if (*(undefined4 **)(in_ECX + 0x1f8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x1f8))(1);
      }
      *(undefined4 *)(in_ECX + 0x1f8) = 0;
    }
    iVar1 = FUN_0042d23e(0x40);
    local_8 = 4;
    if (iVar1 == 0) {
      local_54 = 0;
    }
    else {
      local_54 = XRegisterInfoObject__XRegisterInfoObject(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x1f8) = local_54;
    *(undefined4 *)(in_ECX + 0x1e4) = 2;
  }
  else if (*(int *)(in_ECX + 0x1e4) == 8) {
    if (*(int *)(in_ECX + 0x1f8) != 0) {
      if (*(undefined4 **)(in_ECX + 0x1f8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x1f8))(1);
      }
      *(undefined4 *)(in_ECX + 0x1f8) = 0;
    }
    iVar1 = FUN_0042d23e(0x88);
    local_8 = 5;
    if (iVar1 == 0) {
      local_5c = 0;
    }
    else {
      local_5c = XEndingObject__XEndingObject(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0x1f8) = local_5c;
    *(undefined4 *)(in_ECX + 0x1e4) = 2;
  }
  else if (*(int *)(in_ECX + 0x1e4) == 1) {
    PostMessageA(*(HWND *)(in_ECX + 0x28),0x111,0x9c46,0);
    *(undefined4 *)(in_ECX + 0x1e4) = 0;
  }
  ExceptionList = local_10;
  return 0;
}

// ============================================================================
// Address: 0x417370 | Symbol: XApplication::FinalCleanup
// ============================================================================
undefined4 XApplication__FinalCleanup(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1f8) != 0) {
    if (*(undefined4 **)(in_ECX + 0x1f8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x1f8))(1);
    }
    *(undefined4 *)(in_ECX + 0x1f8) = 0;
  }
  if (*(int *)(in_ECX + 0x1fc) != 0) {
    if (*(undefined4 **)(in_ECX + 0x1fc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x1fc))(1);
    }
    *(undefined4 *)(in_ECX + 0x1fc) = 0;
  }
  if (*(int *)(in_ECX + 500) != 0) {
    if (*(undefined4 **)(in_ECX + 500) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 500))(1);
    }
    *(undefined4 *)(in_ECX + 500) = 0;
  }
  if (*(int *)(in_ECX + 0x1f0) != 0) {
    if (*(undefined4 **)(in_ECX + 0x1f0) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x1f0))(1);
    }
    *(undefined4 *)(in_ECX + 0x1f0) = 0;
  }
  if (*(int *)(in_ECX + 0x1ec) != 0) {
    if (*(undefined4 **)(in_ECX + 0x1ec) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x1ec))(1);
    }
    *(undefined4 *)(in_ECX + 0x1ec) = 0;
  }
  if (*(int *)(in_ECX + 0x1e8) != 0) {
    if (*(undefined4 **)(in_ECX + 0x1e8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x1e8))(1);
    }
    *(undefined4 *)(in_ECX + 0x1e8) = 0;
  }
  if (*(int *)(in_ECX + 0x1b8) != 0) {
    if (*(undefined4 **)(in_ECX + 0x1b8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x1b8))(1);
    }
    *(undefined4 *)(in_ECX + 0x1b8) = 0;
  }
  return 0;
}

// ============================================================================
// Address: 0x417570 | Symbol: XApplication::RestoreSurfaces
// ============================================================================
undefined4 XApplication__RestoreSurfaces(void)

{
  JSurfaceList__RestoreAllSurfaces();
  return 0;
}

// ============================================================================
// Address: 0x417590 | Symbol: XApplication::ConfirmDevice
// ============================================================================
undefined4 XApplication__ConfirmDevice(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_2 + 0x4c) & 2) == 0) {
    uVar1 = 0x80004005;
  }
  else if ((*(uint *)(param_2 + 0x50) & 2) == 0) {
    uVar1 = 0x80004005;
  }
  else if (((*(uint *)(param_2 + 0x5c) & 0x80) == 0) && ((*(uint *)(param_2 + 0x5c) & 4) == 0)) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x4175f0 | Symbol: XApplication::_DisableStickyKeys
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void XApplication___DisableStickyKeys(void)

{
  BOOL BVar1;
  int in_ECX;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_24 = in_ECX;
  _memset((void *)(in_ECX + 0x1bc),0,8);
  _memset((void *)(local_24 + 0x1c4),0,0x18);
  _memset((void *)(local_24 + 0x1dc),0,8);
  *(undefined4 *)(local_24 + 0x1bc) = 8;
  BVar1 = SystemParametersInfoA(0x3a,8,(PVOID)(local_24 + 0x1bc),0);
  if (BVar1 == 0) {
    *(undefined4 *)(local_24 + 0x1bc) = 0;
  }
  else if ((*(uint *)(local_24 + 0x1c0) & 2) == 0) {
    *(undefined4 *)(local_24 + 0x1bc) = 0;
  }
  else {
    local_2c = *(undefined4 *)(local_24 + 0x1bc);
    local_28 = *(uint *)(local_24 + 0x1c0) & 0xfffffffa;
    SystemParametersInfoA(0x3b,8,&local_2c,0);
  }
  *(undefined4 *)(local_24 + 0x1c4) = 0x18;
  BVar1 = SystemParametersInfoA(0x32,0x18,(PVOID)(local_24 + 0x1c4),0);
  if (BVar1 == 0) {
    *(undefined4 *)(local_24 + 0x1c4) = 0;
  }
  else if ((*(uint *)(local_24 + 0x1c8) & 2) == 0) {
    *(undefined4 *)(local_24 + 0x1c4) = 0;
  }
  else {
    local_20 = *(undefined4 *)(local_24 + 0x1c4);
    local_18 = *(undefined4 *)(local_24 + 0x1cc);
    local_14 = *(undefined4 *)(local_24 + 0x1d0);
    local_10 = *(undefined4 *)(local_24 + 0x1d4);
    local_c = *(undefined4 *)(local_24 + 0x1d8);
    local_1c = *(uint *)(local_24 + 0x1c8) & 0xfffffffa;
    SystemParametersInfoA(0x33,0x18,&local_20,0);
  }
  *(undefined4 *)(local_24 + 0x1dc) = 8;
  BVar1 = SystemParametersInfoA(0x34,8,(PVOID)(local_24 + 0x1dc),0);
  if (BVar1 == 0) {
    *(undefined4 *)(local_24 + 0x1dc) = 0;
  }
  else if ((*(uint *)(local_24 + 0x1e0) & 2) == 0) {
    *(undefined4 *)(local_24 + 0x1dc) = 0;
  }
  else {
    local_34 = *(undefined4 *)(local_24 + 0x1dc);
    local_30 = *(uint *)(local_24 + 0x1e0) & 0xfffffffa;
    SystemParametersInfoA(0x35,8,&local_34,0);
  }
  return;
}

// ============================================================================
// Address: 0x4177f0 | Symbol: XApplication::_RestoreStickyKeys
// ============================================================================
void XApplication___RestoreStickyKeys(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1bc) != 0) {
    SystemParametersInfoA(0x3b,8,(PVOID)(in_ECX + 0x1bc),0);
  }
  if (*(int *)(in_ECX + 0x1c4) != 0) {
    SystemParametersInfoA(0x33,0x18,(PVOID)(in_ECX + 0x1c4),0);
  }
  if (*(int *)(in_ECX + 0x1dc) != 0) {
    SystemParametersInfoA(0x35,8,(PVOID)(in_ECX + 0x1dc),0);
  }
  return;
}

// ============================================================================
// Address: 0x417860 | Symbol: _D3DLIGHT7::_D3DLIGHT7
// ============================================================================
undefined4 _D3DLIGHT7___D3DLIGHT7(void)

{
  undefined4 in_ECX;
  
  FUN_00403f60();
  FUN_00403f60();
  return in_ECX;
}

// ============================================================================
// Address: 0x417890 | Symbol: XApplication::
// ============================================================================
undefined4 XApplication__(uint param_1)

{
  undefined4 in_ECX;
  
  XApplication___XApplication();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x200);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x4178d0 | Symbol: XFPSDisplay::
// ============================================================================
undefined4 XFPSDisplay__(uint param_1)

{
  undefined4 in_ECX;
  
  XFPSDisplay___XFPSDisplay();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x10);
  }
  return in_ECX;
}
