// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XRegister.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XRegister.h"

// ============================================================================
// Address: 0x428700 | Symbol: LoadRegisterInfo
// ============================================================================
void LoadRegisterInfo(void)

{
  if (DAT_0048ec50 != (void *)0x0) {
    FUN_0042d26e(DAT_0048ec50,0x2c);
    DAT_0048ec50 = (void *)0x0;
  }
  DAT_0048ec50 = (void *)FUN_0042d23e(0x2c);
  _memset(DAT_0048ec50,0,0x2c);
  _CheckRegistrationKey();
  return;
}

// ============================================================================
// Address: 0x428760 | Symbol: SaveRegisterInfo
// ============================================================================
void SaveRegisterInfo(void)

{
  return;
}

// ============================================================================
// Address: 0x428770 | Symbol: DeleteRegisterInfo
// ============================================================================
void DeleteRegisterInfo(void)

{
  if (DAT_0048ec50 != 0) {
    FUN_0042d26e(DAT_0048ec50,0x2c);
    DAT_0048ec50 = 0;
  }
  return;
}

// ============================================================================
// Address: 0x4287b0 | Symbol: DoRegister
// ============================================================================
void DoRegister(HWND param_1)

{
  int iVar1;
  
  iVar1 = _ExecuteRgisterDialog(param_1,DAT_0048ec50);
  if (-1 < iVar1) {
    _CheckRegistrationKey();
    if (*(int *)(DAT_0048ec50 + 0x28) != 0) {
      MessageBoxA(param_1,"Thank you! You have successfully registered Hopmon.","Hopmon",0x40);
    }
  }
  return;
}

// ============================================================================
// Address: 0x428800 | Symbol: IsRegistered
// ============================================================================
undefined4 IsRegistered(void)

{
  return 1;
}

// ============================================================================
// Address: 0x428810 | Symbol: _ChangeRegisterProc
// ============================================================================
undefined4 _ChangeRegisterProc(HWND param_1,int param_2,short param_3,LPCSTR param_4)

{
  undefined4 uVar1;
  HWND pHVar2;
  HWND hWnd;
  uint local_10;
  uint local_c;
  
  if (param_2 == 0x110) {
    DAT_0048ec54 = param_4;
    if (param_4 == (LPCSTR)0x0) {
      uVar1 = 0;
    }
    else {
      pHVar2 = GetDlgItem(param_1,0x400);
      hWnd = GetDlgItem(param_1,1);
      SendMessageA(pHVar2,0xc5,0x1e,0);
      SetWindowTextA(pHVar2,DAT_0048ec54);
      local_c = (uint)(*(int *)(DAT_0048ec54 + 0x28) == 0);
      EnableWindow(pHVar2,local_c);
      local_10 = (uint)(*(int *)(DAT_0048ec54 + 0x28) == 0);
      EnableWindow(hWnd,local_10);
      uVar1 = 1;
    }
  }
  else if (param_2 == 0x111) {
    if (param_3 == 1) {
      pHVar2 = GetDlgItem(param_1,0x400);
      GetWindowTextA(pHVar2,DAT_0048ec54,0x27);
      EndDialog(param_1,1);
    }
    else if (param_3 == 2) {
      EndDialog(param_1,2);
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x428960 | Symbol: _ExecuteRgisterDialog
// ============================================================================
undefined4 _ExecuteRgisterDialog(HWND param_1,LPARAM param_2)

{
  HMODULE hInstance;
  INT_PTR IVar1;
  undefined4 uVar2;
  LPCSTR lpTemplateName;
  code *lpDialogFunc;
  
  lpDialogFunc = _ChangeRegisterProc;
  lpTemplateName = (LPCSTR)0xf9;
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  IVar1 = DialogBoxParamA(hInstance,lpTemplateName,param_1,lpDialogFunc,param_2);
  if (IVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x4289a0 | Symbol: _CheckRegistrationKey
// ============================================================================
void _CheckRegistrationKey(void)

{
  if (DAT_0048ec50 != 0) {
    *(undefined4 *)(DAT_0048ec50 + 0x28) = 1;
  }
  return;
}
