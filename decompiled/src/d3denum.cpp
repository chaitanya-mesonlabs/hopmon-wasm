// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: d3denum.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "d3denum.h"

// ============================================================================
// Address: 0x404500 | Symbol: D3DEnum_EnumerateDevices
// ============================================================================
undefined4 D3DEnum_EnumerateDevices(undefined4 param_1)

{
  undefined4 uVar1;
  
  DAT_00487f50 = param_1;
  DirectDrawEnumerateExA(DriverEnumCallback,0,7);
  if (DAT_00487f54 == 0) {
    uVar1 = 0x81000002;
  }
  else if (DAT_0048dfe8 == 0) {
    uVar1 = 0x81000003;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x404540 | Symbol: D3DEnum_FreeResources
// ============================================================================
void D3DEnum_FreeResources(void)

{
  uint local_8;
  
  for (local_8 = 0; local_8 < DAT_0048dfe8; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00488418 + local_8 * 0x4d4) != 0) {
      FUN_0042d26e(*(undefined4 *)(&DAT_00488418 + local_8 * 0x4d4),0x7c);
      *(undefined4 *)(&DAT_00488418 + local_8 * 0x4d4) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x4045b0 | Symbol: D3DEnum_GetDevices
// ============================================================================
void D3DEnum_GetDevices(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = &DAT_00487f58;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = DAT_0048dfe8;
  }
  return;
}

// ============================================================================
// Address: 0x4045e0 | Symbol: D3DEnum_SelectDefaultDevice
// ============================================================================
undefined4 D3DEnum_SelectDefaultDevice(int *param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    D3DEnum_GetDevices(&local_c,&local_20);
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    for (local_8 = 0; local_8 < local_20; local_8 = local_8 + 1) {
      if (*(int *)(local_c + 0x4cc + local_8 * 0x4d4) != 0) {
        if (*(int *)(local_c + 0x118 + local_8 * 0x4d4) == 0) {
          cVar1 = __(*(undefined4 *)(local_c + 0x28 + local_8 * 0x4d4),&DAT_00475d88);
          if (cVar1 == '\0') {
            local_18 = local_8 * 0x4d4 + local_c;
          }
          else {
            local_1c = local_8 * 0x4d4 + local_c;
          }
        }
        else {
          cVar1 = __(*(undefined4 *)(local_c + 0x28 + local_8 * 0x4d4),&DAT_00475d68);
          if (cVar1 == '\0') {
            local_14 = local_8 * 0x4d4 + local_c;
          }
          else {
            local_10 = local_8 * 0x4d4 + local_c;
          }
        }
      }
    }
    if (((param_2 & 1) == 0) && (local_10 != 0)) {
      *param_1 = local_10;
    }
    else if (((param_2 & 1) == 0) && (local_14 != 0)) {
      *param_1 = local_14;
    }
    else if (local_18 == 0) {
      if (local_1c == 0) {
        return 0x81000004;
      }
      *param_1 = local_1c;
    }
    else {
      *param_1 = local_18;
    }
    if ((param_2 & 2) == 0) {
      *(undefined4 *)(*param_1 + 0x494) = 1;
    }
    else {
      *(undefined4 *)(*param_1 + 0x494) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x404780 | Symbol: D3DEnum_UserChangeDevice
// ============================================================================
undefined4 D3DEnum_UserChangeDevice(LPARAM param_1)

{
  HWND hWndParent;
  HMODULE hInstance;
  INT_PTR IVar1;
  undefined4 uVar2;
  LPCSTR lpTemplateName;
  code *lpDialogFunc;
  
  lpDialogFunc = ChangeDeviceProc;
  hWndParent = GetForegroundWindow();
  lpTemplateName = (LPCSTR)0x90;
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  IVar1 = DialogBoxParamA(hInstance,lpTemplateName,hWndParent,lpDialogFunc,param_1);
  if (IVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x4047c0 | Symbol: D3DEnum_UserChangeDeviceOnDesktop
// ============================================================================
undefined4 D3DEnum_UserChangeDeviceOnDesktop(LPARAM param_1)

{
  HWND hWndParent;
  HMODULE hInstance;
  INT_PTR IVar1;
  undefined4 uVar2;
  LPCSTR lpTemplateName;
  code *lpDialogFunc;
  
  lpDialogFunc = ChangeDeviceProc;
  hWndParent = GetDesktopWindow();
  lpTemplateName = (LPCSTR)0x90;
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  IVar1 = DialogBoxParamA(hInstance,lpTemplateName,hWndParent,lpDialogFunc,param_1);
  if (IVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x404800 | Symbol: SortModesCallback
// ============================================================================
undefined4 SortModesCallback(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(uint *)(param_1 + 0xc) < *(uint *)(param_2 + 0xc)) {
    uVar1 = 0xffffffff;
  }
  else if (*(uint *)(param_2 + 0xc) < *(uint *)(param_1 + 0xc)) {
    uVar1 = 1;
  }
  else if (*(uint *)(param_1 + 8) < *(uint *)(param_2 + 8)) {
    uVar1 = 0xffffffff;
  }
  else if (*(uint *)(param_2 + 8) < *(uint *)(param_1 + 8)) {
    uVar1 = 1;
  }
  else if (*(uint *)(param_1 + 0x54) < *(uint *)(param_2 + 0x54)) {
    uVar1 = 0xffffffff;
  }
  else if (*(uint *)(param_2 + 0x54) < *(uint *)(param_1 + 0x54)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x404890 | Symbol: ModeEnumCallback
// ============================================================================
undefined4 ModeEnumCallback(undefined4 *param_1,int param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  lVar1 = (ulonglong)(*(int *)(param_2 + 0x4c4) + 1) * 0x7c;
  uVar2 = FUN_0042d2b4(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  FUN_004307f0(uVar2,*(undefined4 *)(param_2 + 0x4c0),*(int *)(param_2 + 0x4c4) * 0x7c);
  FUN_0042d26e(*(undefined4 *)(param_2 + 0x4c0),0x7c);
  *(undefined4 *)(param_2 + 0x4c0) = uVar2;
  puVar4 = (undefined4 *)(*(int *)(param_2 + 0x4c0) + *(int *)(param_2 + 0x4c4) * 0x7c);
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  *(int *)(param_2 + 0x4c4) = *(int *)(param_2 + 0x4c4) + 1;
  return 1;
}

// ============================================================================
// Address: 0x404960 | Symbol: DeviceEnumCallback
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DeviceEnumCallback(undefined4 param_1,LPCSTR param_2,uint *param_3,LPCSTR param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  LPSTR lpString1;
  LPCSTR pCVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint local_94;
  uint local_90;
  undefined4 local_84 [21];
  int local_30;
  uint local_18;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  DAT_00487f54 = DAT_00487f54 + 1;
  iVar4 = DAT_0048dfe8 * 0x4d4;
  lpString1 = &DAT_00487f58 + iVar4;
  _memset(lpString1,0,0x4d4);
  *(uint *)(&DAT_00488070 + iVar4) = *param_3 & 0x80000;
  FUN_004307f0(iVar4 + 0x487f84,param_3,0xec);
  *(undefined4 *)(&DAT_00488424 + iVar4) = *(undefined4 *)(param_4 + 0x4cc);
  pCVar5 = param_4 + 0x120;
  puVar6 = (undefined4 *)(&DAT_00488078 + iVar4);
  for (iVar3 = 0x5f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *(undefined4 *)pCVar5;
    pCVar5 = pCVar5 + 4;
    puVar6 = puVar6 + 1;
  }
  pCVar5 = param_4 + 0x29c;
  puVar6 = (undefined4 *)(&DAT_004881f4 + iVar4);
  for (iVar3 = 0x5f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *(undefined4 *)pCVar5;
    pCVar5 = pCVar5 + 4;
    puVar6 = puVar6 + 1;
  }
  *(uint *)(&DAT_004883f8 + iVar4) = param_3[0x31];
  *(uint *)(&DAT_004883fc + iVar4) = param_3[0x32];
  *(uint *)(&DAT_00488400 + iVar4) = param_3[0x33];
  *(uint *)(&DAT_00488404 + iVar4) = param_3[0x34];
  *(undefined **)(&DAT_00487f80 + iVar4) = &DAT_004883f8 + iVar4;
  uVar2 = FUN_0042d2b4(-(uint)((int)((ulonglong)*(uint *)(param_4 + 0x4c4) * 0x7c >> 0x20) != 0) |
                       (uint)((ulonglong)*(uint *)(param_4 + 0x4c4) * 0x7c));
  *(undefined4 *)(&DAT_00488418 + iVar4) = uVar2;
  if (*(int *)(param_4 + 0x11c) == 0) {
    *(undefined4 *)(&DAT_00488074 + iVar4) = 0;
    lstrcpynA(lpString1,param_2,0x27);
  }
  else {
    *(undefined4 *)(&DAT_00488408 + iVar4) = *(undefined4 *)(param_4 + 0x4b0);
    *(undefined4 *)(&DAT_0048840c + iVar4) = *(undefined4 *)(param_4 + 0x4b4);
    *(undefined4 *)(&DAT_00488410 + iVar4) = *(undefined4 *)(param_4 + 0x4b8);
    *(undefined4 *)(&DAT_00488414 + iVar4) = *(undefined4 *)(param_4 + 0x4bc);
    *(undefined **)(&DAT_00488074 + iVar4) = &DAT_00488408 + iVar4;
    lstrcpynA(lpString1,param_4,0x27);
  }
  if (((*(int *)(&DAT_00488074 + iVar4) == 0) || (*(int *)(&DAT_00488070 + iVar4) != 0)) &&
     ((DAT_00487f50 == (code *)0x0 ||
      (iVar3 = (*DAT_00487f50)(&DAT_00488078 + iVar4,iVar4 + 0x487f84), -1 < iVar3)))) {
    for (local_94 = 0; local_94 < *(uint *)(param_4 + 0x4c4); local_94 = local_94 + 1) {
      puVar6 = (undefined4 *)(*(int *)(param_4 + 0x4c0) + local_94 * 0x7c);
      puVar7 = local_84;
      for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      uVar1 = *(uint *)(&DAT_00487ff8 + iVar4);
      if (((local_30 == 0x20) && ((uVar1 & 0x100) != 0)) ||
         (((local_30 == 0x18 && ((uVar1 & 0x200) != 0)) ||
          ((local_30 == 0x10 && ((uVar1 & 0x400) != 0)))))) {
        puVar6 = local_84;
        puVar7 = (undefined4 *)
                 (*(int *)(&DAT_00488418 + iVar4) + *(int *)(&DAT_0048841c + iVar4) * 0x7c);
        for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        *(int *)(&DAT_0048841c + iVar4) = *(int *)(&DAT_0048841c + iVar4) + 1;
        if ((local_18 & 0x80000) != 0) {
          *(undefined4 *)(&DAT_00488428 + iVar4) = 1;
        }
      }
    }
    if (*(int *)(&DAT_0048841c + iVar4) != 0) {
      for (local_90 = 0; local_90 < *(uint *)(&DAT_0048841c + iVar4); local_90 = local_90 + 1) {
        if (((*(int *)(*(int *)(&DAT_00488418 + iVar4) + 0xc + local_90 * 0x7c) == 0x280) &&
            (*(int *)(*(int *)(&DAT_00488418 + iVar4) + 8 + local_90 * 0x7c) == 0x1e0)) &&
           (*(int *)(*(int *)(&DAT_00488418 + iVar4) + 0x54 + local_90 * 0x7c) == 0x10)) {
          puVar6 = (undefined4 *)(*(int *)(&DAT_00488418 + iVar4) + local_90 * 0x7c);
          puVar7 = (undefined4 *)(&DAT_00488370 + iVar4);
          for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          *(uint *)(&DAT_00488420 + iVar4) = local_90;
        }
      }
      *(undefined4 *)(&DAT_004883ec + iVar4) = *(undefined4 *)(&DAT_00488424 + iVar4);
      *(undefined4 *)(&DAT_004883f4 + iVar4) = 0;
      DAT_0048dfe8 = DAT_0048dfe8 + 1;
    }
  }
  return 1;
}

// ============================================================================
// Address: 0x404df0 | Symbol: DriverEnumCallback
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DriverEnumCallback(undefined4 *param_1,LPCSTR param_2)

{
  int iVar1;
  int *local_4e4;
  int *local_4e0;
  CHAR local_4dc [284];
  undefined4 *local_3c0;
  undefined4 local_3bc [2];
  uint local_3b4;
  undefined4 local_240 [133];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  size_t local_18;
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  iVar1 = DirectDrawCreateEx(param_1,&local_4e0,&DAT_00475fe8,0);
  if (-1 < iVar1) {
    iVar1 = (**(code **)*local_4e0)(local_4e0,&DAT_00475dd8,&local_4e4);
    if (iVar1 < 0) {
      (**(code **)(*local_4e0 + 8))(local_4e0);
    }
    else {
      _memset(local_4dc,0,0x4d4);
      lstrcpynA(local_4dc,param_2,0x27);
      local_3bc[0] = 0x17c;
      local_240[0] = 0x17c;
      (**(code **)(*local_4e0 + 0x2c))(local_4e0,local_3bc,local_240);
      if (param_1 != (undefined4 *)0x0) {
        local_2c = *param_1;
        local_28 = param_1[1];
        local_24 = param_1[2];
        local_20 = param_1[3];
        local_3c0 = &local_2c;
      }
      if (((local_3b4 & 0x80000) != 0) && (local_3c0 == (undefined4 *)0x0)) {
        local_10 = 1;
      }
      (**(code **)(*local_4e0 + 0x20))(local_4e0,0,0,local_4dc,ModeEnumCallback);
      _qsort(local_1c,local_18,0x7c,SortModesCallback);
      (**(code **)(*local_4e4 + 0xc))(local_4e4,DeviceEnumCallback,local_4dc);
      if (local_1c != (void *)0x0) {
        FUN_0042d26e(local_1c,0x7c);
        local_1c = (void *)0x0;
      }
      (**(code **)(*local_4e4 + 8))(local_4e4);
      (**(code **)(*local_4e0 + 8))(local_4e0);
    }
  }
  return 1;
}

// ============================================================================
// Address: 0x404ff0 | Symbol: UpdateDialogControls
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UpdateDialogControls
               (HWND param_1,int param_2,uint param_3,WPARAM param_4,WPARAM param_5,WPARAM param_6)

{
  HWND hWnd;
  int iVar1;
  WPARAM wParam;
  LRESULT LVar2;
  int local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  BOOL local_88;
  HWND local_84;
  WPARAM local_80;
  HWND local_7c;
  HWND local_78;
  HWND local_74;
  HWND local_70;
  uint local_6c;
  uint local_68;
  int local_64;
  HWND local_60;
  int local_5c;
  CHAR local_58 [80];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  D3DEnum_GetDevices(&local_98,&local_94);
  local_74 = GetDlgItem(param_1,1000);
  local_60 = GetDlgItem(param_1,0x3e9);
  local_78 = GetDlgItem(param_1,0x3f4);
  local_7c = GetDlgItem(param_1,0x3f5);
  hWnd = GetDlgItem(param_1,0x3f6);
  local_84 = GetDlgItem(param_1,0x3f7);
  local_70 = GetDlgItem(param_1,0x3fe);
  if (local_84 != (HWND)0x0) {
    SendMessageA(local_84,0xf1,param_6,0);
  }
  if (local_70 != (HWND)0x0) {
    iVar1 = IsRegistered();
    if (iVar1 == 0) {
      SetWindowTextA(local_70,"UNREGISTERED");
    }
    else {
      SetWindowTextA(local_70,"");
    }
  }
  SendMessageA(local_74,0x14b,0,0);
  SendMessageA(local_60,0x14b,0,0);
  if (*(int *)(param_2 + 0x4cc) == 0) {
    param_4 = 0;
  }
  for (local_6c = 0; local_6c < local_94; local_6c = local_6c + 1) {
    local_64 = local_6c * 0x4d4 + local_98;
    wParam = SendMessageA(local_74,0x143,0,local_64);
    if (local_64 == param_2) {
      SendMessageA(local_74,0x14e,wParam,0);
      if (local_78 != (HWND)0x0) {
        EnableWindow(local_78,*(BOOL *)(local_64 + 0x4cc));
        SendMessageA(local_78,0xf1,param_4,0);
      }
      if (local_7c != (HWND)0x0) {
        if ((*(int *)(local_64 + 0x4d0) == 0) || (param_4 != 0)) {
          local_88 = 0;
        }
        else {
          local_88 = 1;
        }
        EnableWindow(local_7c,local_88);
        SendMessageA(local_7c,0xf1,param_5,0);
      }
      local_8c = (uint)(param_4 == 0);
      EnableWindow(local_60,local_8c);
      local_90 = (uint)(param_4 == 0);
      EnableWindow(hWnd,local_90);
      for (local_68 = 0; local_68 < *(uint *)(local_64 + 0x4c4); local_68 = local_68 + 1) {
        local_5c = local_68 * 0x7c + *(int *)(local_64 + 0x4c0);
        if ((((((*(uint *)(local_5c + 0x6c) & 0x80000) != 0) || (param_5 == 0)) &&
             (0x27f < *(uint *)(local_5c + 0xc))) &&
            ((0x1df < *(uint *)(local_5c + 8) && (*(uint *)(local_5c + 0xc) < 0x501)))) &&
           ((*(uint *)(local_5c + 8) < 0x3c1 && (*(int *)(local_5c + 0x54) == 0x10)))) {
          wsprintfA(local_58,"%ld x %ld",*(undefined4 *)(local_5c + 0xc),
                    *(undefined4 *)(local_5c + 8));
          local_80 = SendMessageA(local_60,0x143,0,(LPARAM)local_58);
          SendMessageA(local_60,0x151,local_80,local_68);
          if (local_68 == param_3) {
            SendMessageA(local_60,0x14e,local_80,0);
          }
          if ((param_5 != 0) && (LVar2 = SendMessageA(local_60,0x147,0,0), LVar2 == -1)) {
            SendMessageA(local_60,0x14e,local_80,0);
          }
        }
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x4053b0 | Symbol: ChangeDeviceProc
// ============================================================================
undefined4 ChangeDeviceProc(HWND param_1,int param_2,uint param_3,int *param_4)

{
  undefined4 uVar1;
  LPCSTR lpFile;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  LPCSTR lpParameters;
  LPCSTR lpDirectory;
  INT nShowCmd;
  undefined1 local_64 [8];
  undefined1 local_5c [8];
  undefined1 local_54 [4];
  WPARAM local_50;
  HWND local_4c;
  LRESULT local_48;
  LRESULT local_44;
  HWND local_40;
  LRESULT local_3c;
  HWND local_38;
  LRESULT local_34;
  HWND local_30;
  HWND local_2c;
  LRESULT local_28;
  LRESULT local_24;
  int local_20;
  LRESULT local_1c;
  LRESULT local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470845;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  D3DEnum_GetDevices(&local_20,local_54,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (param_2 == 0x110) {
    DAT_0048dfec = param_4;
    if (param_4 == (int *)0x0) {
      uVar1 = 0;
    }
    else {
      DAT_0048dff0 = *param_4;
      DAT_0048dff4 = *(int *)(DAT_0048dff0 + 0x4c8);
      DAT_0048dff8 = *(int *)(DAT_0048dff0 + 0x494);
      DAT_0048dffc = *(int *)(DAT_0048dff0 + 0x498);
      DAT_0048e000 = *(undefined4 *)(DAT_0048dff0 + 0x49c);
      UpdateDialogControls(param_1,DAT_0048dff0,DAT_0048dff4,DAT_0048dff8,DAT_0048dffc,DAT_0048e000)
      ;
      uVar1 = 1;
    }
  }
  else if (param_2 == 0x111) {
    local_4c = GetDlgItem(param_1,1000);
    local_2c = GetDlgItem(param_1,0x3e9);
    local_30 = GetDlgItem(param_1,0x3f4);
    local_38 = GetDlgItem(param_1,0x3f5);
    local_40 = GetDlgItem(param_1,0x3f7);
    local_1c = SendMessageA(local_4c,0x147,0,0);
    local_50 = SendMessageA(local_2c,0x147,0,0);
    local_18 = SendMessageA(local_2c,0x150,local_50,0);
    if (local_30 == (HWND)0x0) {
      local_34 = 0;
    }
    else {
      local_34 = SendMessageA(local_30,0xf0,0,0);
    }
    local_28 = local_34;
    if (local_38 == (HWND)0x0) {
      local_3c = 0;
    }
    else {
      local_3c = SendMessageA(local_38,0xf0,0,0);
    }
    local_24 = local_3c;
    if (local_40 == (HWND)0x0) {
      local_44 = 0;
    }
    else {
      local_44 = SendMessageA(local_40,0xf0,0,0);
    }
    local_48 = local_44;
    local_14 = local_1c * 0x4d4 + local_20;
    if ((param_3 & 0xffff) == 1) {
      *(LRESULT *)(local_14 + 0x49c) = local_44;
      if ((((local_14 == DAT_0048dff0) && (local_18 == DAT_0048dff4)) && (local_28 == DAT_0048dff8))
         && (local_24 == DAT_0048dffc)) {
        EndDialog(param_1,2);
      }
      else {
        *DAT_0048dfec = local_14;
        *(LRESULT *)(local_14 + 0x494) = local_28;
        *(LRESULT *)(local_14 + 0x498) = local_24;
        *(LRESULT *)(local_14 + 0x4c8) = local_18;
        puVar3 = (undefined4 *)(*(int *)(local_14 + 0x4c0) + local_18 * 0x7c);
        puVar4 = (undefined4 *)(local_14 + 0x418);
        for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        EndDialog(param_1,1);
      }
      uVar1 = 1;
    }
    else if ((param_3 & 0xffff) == 2) {
      EndDialog(param_1,2);
      uVar1 = 1;
    }
    else {
      if (param_3 >> 0x10 == 9) {
        if ((param_3 & 0xffff) == 1000) {
          local_18 = *(int *)(local_20 + 0x4c8 + local_1c * 0x4d4);
          local_28 = *(int *)(local_20 + 0x494 + local_1c * 0x4d4);
          local_24 = *(int *)(local_20 + 0x498 + local_1c * 0x4d4);
        }
      }
      else if (((param_3 & 0xffff) != 0x3fd) && ((param_3 & 0xffff) == 0x402)) {
        FUN_00413970("Manual_E.htm");
        local_8 = 0;
        ConvertToFullPath(local_64,local_5c,0);
        local_8 = CONCAT31(local_8._1_3_,2);
        JString___JString();
        nShowCmd = 1;
        lpDirectory = (LPCSTR)0x0;
        lpParameters = (LPCSTR)0x0;
        lpFile = (LPCSTR)JString__c_str();
        ShellExecuteA((HWND)0x0,"open",lpFile,lpParameters,lpDirectory,nShowCmd);
        local_8 = 0xffffffff;
        JString___JString();
      }
      UpdateDialogControls(param_1,local_1c * 0x4d4 + local_20,local_18,local_28,local_24,local_48);
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  ExceptionList = local_10;
  return uVar1;
}

// ============================================================================
// Address: 0x405800 | Symbol: ==
// ============================================================================
/* Library Function - Multiple Matches With Same Base Name
    bool __cdecl _Bitmask_includes(enum __std_fs_file_attr,enum __std_fs_file_attr)
    bool __cdecl _Bitmask_includes(enum __std_fs_stats_flags,enum __std_fs_stats_flags)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

bool __(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = IsEqualGUID(param_1,param_2);
  return iVar1 != 0;
}

// ============================================================================
// Address: 0x405830 | Symbol: IsEqualGUID
// ============================================================================
bool IsEqualGUID(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0042eaa0(param_1,param_2,0x10);
  return iVar1 == 0;
}
