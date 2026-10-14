// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: ddutil.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "ddutil.h"

// ============================================================================
// Address: 0x40cc80 | Symbol: DDLoadPalette
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DDLoadPalette(int *param_1,LPCSTR param_2)

{
  HGLOBAL hResData;
  undefined4 local_460;
  HRSRC local_45c;
  int local_458;
  HFILE local_454;
  undefined1 local_44d;
  uint local_44c;
  uint *local_448;
  uint local_444;
  undefined1 local_440 [16];
  int local_430 [3];
  ushort local_422;
  uint local_410;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  for (local_444 = 0; (int)local_444 < 0x100; local_444 = local_444 + 1) {
    local_408[local_444 * 4] = (char)((ulonglong)(((int)local_444 >> 5 & 7U) * 0xff) / 7);
    local_408[local_444 * 4 + 1] = (char)((ulonglong)(((int)local_444 >> 2 & 7U) * 0xff) / 7);
    local_408[local_444 * 4 + 2] = (char)((ulonglong)((local_444 & 3) * 0xff) / 3);
    local_408[local_444 * 4 + 3] = 0;
  }
  if ((param_2 == (LPCSTR)0x0) ||
     (local_45c = FindResourceA((HMODULE)0x0,param_2,(LPCSTR)0x2), local_45c == (HRSRC)0x0)) {
    if ((param_2 != (LPCSTR)0x0) && (local_454 = _lopen(param_2,0), local_454 != -1)) {
      _lread(local_454,local_440,0xe);
      _lread(local_454,local_430,0x28);
      _lread(local_454,local_408,0x400);
      _lclose(local_454);
      if (local_430[0] == 0x28) {
        if (local_422 < 9) {
          if (local_410 == 0) {
            local_44c = 1 << ((byte)local_422 & 0x1f);
          }
          else {
            local_44c = local_410;
          }
        }
        else {
          local_44c = 0;
        }
      }
      else {
        local_44c = 0;
      }
      for (local_444 = 0; (int)local_444 < (int)local_44c; local_444 = local_444 + 1) {
        local_44d = local_408[local_444 * 4];
        local_408[local_444 * 4] = local_408[local_444 * 4 + 2];
        local_408[local_444 * 4 + 2] = local_44d;
      }
    }
  }
  else {
    hResData = LoadResource((HMODULE)0x0,local_45c);
    local_448 = LockResource(hResData);
    if (local_448 == (uint *)0x0) {
      OutputDebugStringA("lock resource failed\n");
    }
    local_458 = (int)local_448 + *local_448;
    if ((local_448 == (uint *)0x0) || (*local_448 < 0x28)) {
      local_44c = 0;
    }
    else if (*(ushort *)((int)local_448 + 0xe) < 9) {
      if (local_448[8] == 0) {
        local_44c = 1 << ((byte)*(undefined2 *)((int)local_448 + 0xe) & 0x1f);
      }
      else {
        local_44c = local_448[8];
      }
    }
    else {
      local_44c = 0;
    }
    for (local_444 = 0; (int)local_444 < (int)local_44c; local_444 = local_444 + 1) {
      local_408[local_444 * 4] = *(undefined1 *)(local_458 + 2 + local_444 * 4);
      local_408[local_444 * 4 + 1] = *(undefined1 *)(local_458 + 1 + local_444 * 4);
      local_408[local_444 * 4 + 2] = *(undefined1 *)(local_458 + local_444 * 4);
      local_408[local_444 * 4 + 3] = 0;
    }
  }
  (**(code **)(*param_1 + 0x14))(param_1,4,local_408,&local_460,0);
  return local_460;
}

// ============================================================================
// Address: 0x40d030 | Symbol: DDLoadBitmap
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 DDLoadBitmap(int *param_1,LPCSTR param_2,undefined4 *param_3,undefined4 *param_4)

{
  HMODULE hInst;
  LPCSTR name;
  UINT type;
  int iVar1;
  int cy;
  UINT fuLoad;
  undefined1 local_a4 [4];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  HANDLE local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_1c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  *param_3 = 0xffffffff;
  *param_4 = 0xffffffff;
  fuLoad = 0x2000;
  cy = 0;
  iVar1 = 0;
  type = 0;
  name = param_2;
  hInst = GetModuleHandleA((LPCSTR)0x0);
  local_88 = LoadImageA(hInst,name,type,iVar1,cy,fuLoad);
  if (local_88 == (HANDLE)0x0) {
    local_88 = LoadImageA((HINSTANCE)0x0,param_2,0,0,0,0x2010);
  }
  if (local_88 == (HANDLE)0x0) {
    local_8c = 0;
  }
  else {
    GetObjectA(local_88,0x18,local_a4);
    _memset(&local_84,0,0x7c);
    local_84 = 0x7c;
    local_80 = 7;
    local_1c = 0x40;
    local_78 = local_a0;
    local_7c = local_9c;
    iVar1 = (**(code **)(*param_1 + 0x18))(param_1,&local_84,&local_8c,0);
    if (iVar1 == 0) {
      DDCopyBitmap(local_8c,local_88,0,0,0,0);
      DeleteObject(local_88);
      *param_3 = local_a0;
      *param_4 = local_9c;
    }
    else {
      local_8c = 0;
    }
  }
  return local_8c;
}

// ============================================================================
// Address: 0x40d180 | Symbol: DDReLoadBitmap
// ============================================================================
int DDReLoadBitmap(undefined4 param_1,LPCSTR param_2)

{
  HMODULE hInst;
  LPCSTR name;
  UINT type;
  int iVar1;
  int cy;
  UINT fuLoad;
  HGDIOBJ local_8;
  
  fuLoad = 0x2000;
  cy = 0;
  iVar1 = 0;
  type = 0;
  name = param_2;
  hInst = GetModuleHandleA((LPCSTR)0x0);
  local_8 = LoadImageA(hInst,name,type,iVar1,cy,fuLoad);
  if (local_8 == (HANDLE)0x0) {
    local_8 = LoadImageA((HINSTANCE)0x0,param_2,0,0,0,0x2010);
  }
  if (local_8 == (HGDIOBJ)0x0) {
    OutputDebugStringA("handle is null\n");
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = DDCopyBitmap(param_1,local_8,0,0,0,0);
    if (iVar1 != 0) {
      OutputDebugStringA("ddcopybitmap failed\n");
    }
    DeleteObject(local_8);
  }
  return iVar1;
}

// ============================================================================
// Address: 0x40d220 | Symbol: DDCopyBitmap
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DDCopyBitmap(int *param_1,HANDLE param_2,int param_3,int param_4,int param_5,int param_6)

{
  int hSrc;
  int wSrc;
  undefined1 local_b0 [4];
  int local_ac;
  int local_a8;
  int local_98;
  HDC local_94;
  int local_90;
  int local_8c;
  HDC local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  if ((param_2 == (HANDLE)0x0) || (param_1 == (int *)0x0)) {
    local_98 = -0x7fffbffb;
  }
  else {
    (**(code **)(*param_1 + 0x6c))(param_1);
    local_88 = CreateCompatibleDC((HDC)0x0);
    if (local_88 == (HDC)0x0) {
      OutputDebugStringA("createcompatible dc failed\n");
    }
    SelectObject(local_88,param_2);
    GetObjectA(param_2,0x18,local_b0);
    if (param_5 == 0) {
      local_8c = local_ac;
    }
    else {
      local_8c = param_5;
    }
    wSrc = local_8c;
    if (param_6 == 0) {
      local_90 = local_a8;
    }
    else {
      local_90 = param_6;
    }
    hSrc = local_90;
    local_84 = 0x7c;
    local_80 = 6;
    (**(code **)(*param_1 + 0x58))(param_1,&local_84);
    local_98 = (**(code **)(*param_1 + 0x44))(param_1,&local_94);
    if (local_98 == 0) {
      StretchBlt(local_94,0,0,local_78,local_7c,local_88,param_3,param_4,wSrc,hSrc,0xcc0020);
      (**(code **)(*param_1 + 0x68))(param_1,local_94);
    }
    DeleteDC(local_88);
  }
  return local_98;
}

// ============================================================================
// Address: 0x40d3a0 | Symbol: DDColorMatch
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint DDColorMatch(int *param_1,COLORREF param_2)

{
  int iVar1;
  COLORREF local_94;
  uint local_8c;
  HDC local_88;
  undefined4 local_84 [9];
  uint *local_60;
  uint local_30;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_8c = 0xffffffff;
  if ((param_2 != 0xffffffff) &&
     (iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_88), iVar1 == 0)) {
    local_94 = GetPixel(local_88,0,0);
    SetPixel(local_88,0,0,param_2);
    (**(code **)(*param_1 + 0x68))(param_1,local_88);
  }
  local_84[0] = 0x7c;
  do {
    iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_84,0,0);
  } while (iVar1 == -0x7789fde4);
  if (iVar1 == 0) {
    local_8c = *local_60;
    if (local_30 < 0x20) {
      local_8c = (1 << ((byte)local_30 & 0x1f)) - 1U & local_8c;
    }
    (**(code **)(*param_1 + 0x80))(param_1,0);
  }
  if ((param_2 != 0xffffffff) &&
     (iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_88), iVar1 == 0)) {
    SetPixel(local_88,0,0,local_94);
    (**(code **)(*param_1 + 0x68))(param_1,local_88);
  }
  return local_8c;
}

// ============================================================================
// Address: 0x40d500 | Symbol: DDSetColorKey
// ============================================================================
void DDSetColorKey(int *param_1,undefined4 param_2)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = DDColorMatch(param_1,param_2);
  local_8 = local_c;
  (**(code **)(*param_1 + 0x74))(param_1,8,&local_c);
  return;
}
