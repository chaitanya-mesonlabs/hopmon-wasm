// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JWinReg.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JWinReg.h"

// ============================================================================
// Address: 0x4156c0 | Symbol: JWinReg::JWinReg
// ============================================================================
undefined4 * JWinReg__JWinReg(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JWinReg::vftable;
  in_ECX[1] = 0;
  return in_ECX;
}

// ============================================================================
// Address: 0x4156f0 | Symbol: JWinReg::~JWinReg
// ============================================================================
void JWinReg___JWinReg(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_004711c0;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JWinReg::vftable;
  JWinReg__Close(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x415740 | Symbol: JWinReg::Create
// ============================================================================
bool JWinReg__Create(HKEY param_1)

{
  PHKEY phkResult;
  LPCSTR lpSubKey;
  LSTATUS LVar1;
  int in_ECX;
  DWORD Reserved;
  LPSTR lpClass;
  DWORD dwOptions;
  REGSAM samDesired;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  LPDWORD lpdwDisposition;
  
  JWinReg__Close();
  lpdwDisposition = (LPDWORD)0x0;
  phkResult = (PHKEY)(in_ECX + 4);
  lpSecurityAttributes = (LPSECURITY_ATTRIBUTES)0x0;
  samDesired = 0xf003f;
  dwOptions = 0;
  lpClass = (LPSTR)0x0;
  Reserved = 0;
  lpSubKey = (LPCSTR)JString__c_str();
  LVar1 = RegCreateKeyExA(param_1,lpSubKey,Reserved,lpClass,dwOptions,samDesired,
                          lpSecurityAttributes,phkResult,lpdwDisposition);
  return LVar1 == 0;
}

// ============================================================================
// Address: 0x4157a0 | Symbol: JWinReg::Open
// ============================================================================
bool JWinReg__Open(HKEY param_1)

{
  PHKEY phkResult;
  LPCSTR lpSubKey;
  LSTATUS LVar1;
  int in_ECX;
  DWORD ulOptions;
  REGSAM samDesired;
  
  JWinReg__Close();
  phkResult = (PHKEY)(in_ECX + 4);
  samDesired = 0xf003f;
  ulOptions = 0;
  lpSubKey = (LPCSTR)JString__c_str();
  LVar1 = RegOpenKeyExA(param_1,lpSubKey,ulOptions,samDesired,phkResult);
  return LVar1 == 0;
}

// ============================================================================
// Address: 0x415800 | Symbol: JWinReg::Close
// ============================================================================
bool JWinReg__Close(void)

{
  LSTATUS LVar1;
  int in_ECX;
  bool bVar2;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar2 = false;
  }
  else {
    LVar1 = RegCloseKey(*(HKEY *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
    bVar2 = LVar1 == 0;
  }
  return bVar2;
}

// ============================================================================
// Address: 0x415850 | Symbol: JWinReg::SetString
// ============================================================================
bool JWinReg__SetString(void)

{
  int iVar1;
  DWORD cbData;
  BYTE *lpData;
  LPCSTR lpValueName;
  LSTATUS LVar2;
  int in_ECX;
  bool bVar3;
  DWORD Reserved;
  DWORD dwType;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar3 = false;
  }
  else {
    iVar1 = JString__Length();
    cbData = iVar1 + 1;
    lpData = (BYTE *)JString__c_str();
    dwType = 1;
    Reserved = 0;
    lpValueName = (LPCSTR)JString__c_str();
    LVar2 = RegSetValueExA(*(HKEY *)(in_ECX + 4),lpValueName,Reserved,dwType,lpData,cbData);
    bVar3 = LVar2 == 0;
  }
  return bVar3;
}

// ============================================================================
// Address: 0x4158c0 | Symbol: JWinReg::GetString
// ============================================================================
bool JWinReg__GetString(void)

{
  LPCSTR pCVar1;
  undefined4 uVar2;
  int in_ECX;
  bool bVar3;
  LPDWORD pDVar4;
  DWORD *lpType;
  LPDWORD lpType_00;
  LPBYTE pBVar5;
  DWORD *pDVar6;
  DWORD local_20;
  LSTATUS local_1c;
  int local_18;
  DWORD local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004711ea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 4) == 0) {
    bVar3 = false;
  }
  else {
    local_18 = in_ECX;
    _memset(&DAT_0048eb50,0,0x100);
    local_14 = 0;
    local_20 = 0;
    pDVar6 = &local_14;
    pBVar5 = (LPBYTE)0x0;
    lpType = &local_20;
    pDVar4 = (LPDWORD)0x0;
    pCVar1 = (LPCSTR)JString__c_str();
    local_1c = RegQueryValueExA(*(HKEY *)(local_18 + 4),pCVar1,pDVar4,lpType,pBVar5,pDVar6);
    if (local_1c == 0) {
      if (local_20 == 1) {
        if (local_14 < 0x100) {
          pDVar6 = &local_14;
          pBVar5 = &DAT_0048eb50;
          lpType_00 = (LPDWORD)0x0;
          pDVar4 = (LPDWORD)0x0;
          pCVar1 = (LPCSTR)JString__c_str();
          local_1c = RegQueryValueExA(*(HKEY *)(local_18 + 4),pCVar1,pDVar4,lpType_00,pBVar5,pDVar6)
          ;
          uVar2 = FUN_00413970(&DAT_0048eb50);
          local_8 = 0;
          JString__operator_(uVar2);
          local_8 = 0xffffffff;
          JString___JString();
          bVar3 = local_1c == 0;
        }
        else {
          bVar3 = false;
        }
      }
      else {
        bVar3 = false;
      }
    }
    else {
      bVar3 = false;
    }
  }
  ExceptionList = local_10;
  return bVar3;
}

// ============================================================================
// Address: 0x4159f0 | Symbol: JWinReg::SetBinary
// ============================================================================
bool JWinReg__SetBinary(undefined4 param_1,BYTE *param_2,DWORD param_3)

{
  LPCSTR lpValueName;
  LSTATUS LVar1;
  int in_ECX;
  bool bVar2;
  DWORD Reserved;
  DWORD dwType;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar2 = false;
  }
  else {
    dwType = 3;
    Reserved = 0;
    lpValueName = (LPCSTR)JString__c_str();
    LVar1 = RegSetValueExA(*(HKEY *)(in_ECX + 4),lpValueName,Reserved,dwType,param_2,param_3);
    bVar2 = LVar1 == 0;
  }
  return bVar2;
}

// ============================================================================
// Address: 0x415a50 | Symbol: JWinReg::GetBinary
// ============================================================================
bool JWinReg__GetBinary(undefined4 param_1,LPBYTE param_2,DWORD param_3)

{
  LPCSTR pCVar1;
  LSTATUS LVar2;
  int in_ECX;
  bool bVar3;
  LPDWORD pDVar4;
  DWORD *pDVar5;
  LPBYTE lpData;
  DWORD *pDVar6;
  DWORD local_c;
  DWORD local_8;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar3 = false;
  }
  else {
    local_8 = 0;
    local_c = 0;
    pDVar6 = &local_8;
    lpData = (LPBYTE)0x0;
    pDVar5 = &local_c;
    pDVar4 = (LPDWORD)0x0;
    pCVar1 = (LPCSTR)JString__c_str();
    LVar2 = RegQueryValueExA(*(HKEY *)(in_ECX + 4),pCVar1,pDVar4,pDVar5,lpData,pDVar6);
    if (LVar2 == 0) {
      if (local_c == 3) {
        if (local_8 == param_3) {
          pDVar6 = &local_8;
          pDVar5 = &local_c;
          pDVar4 = (LPDWORD)0x0;
          pCVar1 = (LPCSTR)JString__c_str();
          LVar2 = RegQueryValueExA(*(HKEY *)(in_ECX + 4),pCVar1,pDVar4,pDVar5,param_2,pDVar6);
          bVar3 = LVar2 == 0;
        }
        else {
          bVar3 = false;
        }
      }
      else {
        bVar3 = false;
      }
    }
    else {
      bVar3 = false;
    }
  }
  return bVar3;
}

// ============================================================================
// Address: 0x415b10 | Symbol: JWinReg::SetByte
// ============================================================================
bool JWinReg__SetByte(undefined4 param_1,BYTE *param_2)

{
  LPCSTR lpValueName;
  LSTATUS LVar1;
  int in_ECX;
  bool bVar2;
  DWORD Reserved;
  DWORD dwType;
  DWORD cbData;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar2 = false;
  }
  else {
    cbData = 1;
    dwType = 3;
    Reserved = 0;
    lpValueName = (LPCSTR)JString__c_str();
    LVar1 = RegSetValueExA(*(HKEY *)(in_ECX + 4),lpValueName,Reserved,dwType,param_2,cbData);
    bVar2 = LVar1 == 0;
  }
  return bVar2;
}

// ============================================================================
// Address: 0x415b70 | Symbol: JWinReg::GetByte
// ============================================================================
bool JWinReg__GetByte(undefined4 param_1,LPBYTE param_2)

{
  LPCSTR pCVar1;
  LSTATUS LVar2;
  int in_ECX;
  bool bVar3;
  LPDWORD pDVar4;
  DWORD *lpType;
  LPDWORD lpType_00;
  LPBYTE lpData;
  DWORD *pDVar5;
  DWORD local_14;
  LSTATUS local_10;
  int local_c;
  DWORD local_8;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar3 = false;
  }
  else {
    local_8 = 0;
    local_14 = 0;
    pDVar5 = &local_8;
    lpData = (LPBYTE)0x0;
    lpType = &local_14;
    pDVar4 = (LPDWORD)0x0;
    local_c = in_ECX;
    pCVar1 = (LPCSTR)JString__c_str();
    local_10 = RegQueryValueExA(*(HKEY *)(local_c + 4),pCVar1,pDVar4,lpType,lpData,pDVar5);
    if (local_10 == 0) {
      if (local_14 == 3) {
        if (local_8 == 1) {
          pDVar5 = &local_8;
          lpType_00 = (LPDWORD)0x0;
          pDVar4 = (LPDWORD)0x0;
          pCVar1 = (LPCSTR)JString__c_str();
          LVar2 = RegQueryValueExA(*(HKEY *)(local_c + 4),pCVar1,pDVar4,lpType_00,param_2,pDVar5);
          bVar3 = LVar2 == 0;
        }
        else {
          bVar3 = false;
        }
      }
      else {
        bVar3 = false;
      }
    }
    else {
      bVar3 = false;
    }
  }
  return bVar3;
}

// ============================================================================
// Address: 0x415c20 | Symbol: JWinReg::SetWord
// ============================================================================
void JWinReg__SetWord(undefined4 param_1,ushort *param_2)

{
  uint local_8;
  
  local_8 = (uint)*param_2;
  JWinReg__SetDWord(param_1,&local_8);
  return;
}

// ============================================================================
// Address: 0x415c50 | Symbol: JWinReg::GetWord
// ============================================================================
bool JWinReg__GetWord(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = JWinReg__GetDWord(param_1,&local_8);
  if (iVar1 != 0) {
    *param_2 = (undefined2)local_8;
  }
  return iVar1 != 0;
}

// ============================================================================
// Address: 0x415c90 | Symbol: JWinReg::SetDWord
// ============================================================================
bool JWinReg__SetDWord(undefined4 param_1,BYTE *param_2)

{
  LPCSTR lpValueName;
  LSTATUS LVar1;
  int in_ECX;
  bool bVar2;
  DWORD Reserved;
  DWORD dwType;
  DWORD cbData;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar2 = false;
  }
  else {
    cbData = 4;
    dwType = 4;
    Reserved = 0;
    lpValueName = (LPCSTR)JString__c_str();
    LVar1 = RegSetValueExA(*(HKEY *)(in_ECX + 4),lpValueName,Reserved,dwType,param_2,cbData);
    bVar2 = LVar1 == 0;
  }
  return bVar2;
}

// ============================================================================
// Address: 0x415cf0 | Symbol: JWinReg::GetDWord
// ============================================================================
bool JWinReg__GetDWord(undefined4 param_1,LPBYTE param_2)

{
  LPCSTR pCVar1;
  LSTATUS LVar2;
  int in_ECX;
  bool bVar3;
  LPDWORD pDVar4;
  DWORD *lpType;
  LPDWORD lpType_00;
  LPBYTE lpData;
  DWORD *pDVar5;
  DWORD local_14;
  LSTATUS local_10;
  int local_c;
  DWORD local_8;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar3 = false;
  }
  else {
    local_8 = 0;
    local_14 = 0;
    pDVar5 = &local_8;
    lpData = (LPBYTE)0x0;
    lpType = &local_14;
    pDVar4 = (LPDWORD)0x0;
    local_c = in_ECX;
    pCVar1 = (LPCSTR)JString__c_str();
    local_10 = RegQueryValueExA(*(HKEY *)(local_c + 4),pCVar1,pDVar4,lpType,lpData,pDVar5);
    if (local_10 == 0) {
      if (local_14 == 4) {
        if (local_8 == 4) {
          pDVar5 = &local_8;
          lpType_00 = (LPDWORD)0x0;
          pDVar4 = (LPDWORD)0x0;
          pCVar1 = (LPCSTR)JString__c_str();
          LVar2 = RegQueryValueExA(*(HKEY *)(local_c + 4),pCVar1,pDVar4,lpType_00,param_2,pDVar5);
          bVar3 = LVar2 == 0;
        }
        else {
          bVar3 = false;
        }
      }
      else {
        bVar3 = false;
      }
    }
    else {
      bVar3 = false;
    }
  }
  return bVar3;
}

// ============================================================================
// Address: 0x415da0 | Symbol: JWinReg::DeleteValue
// ============================================================================
bool JWinReg__DeleteValue(void)

{
  LPCSTR lpValueName;
  LSTATUS LVar1;
  int in_ECX;
  bool bVar2;
  
  if (*(int *)(in_ECX + 4) == 0) {
    bVar2 = false;
  }
  else {
    lpValueName = (LPCSTR)JString__c_str();
    LVar1 = RegDeleteValueA(*(HKEY *)(in_ECX + 4),lpValueName);
    bVar2 = LVar1 == 0;
  }
  return bVar2;
}

// ============================================================================
// Address: 0x415df0 | Symbol: JWinReg::
// ============================================================================
undefined4 JWinReg__(uint param_1)

{
  undefined4 in_ECX;
  
  JWinReg___JWinReg();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,8);
  }
  return in_ECX;
}
