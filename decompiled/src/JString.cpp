// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JString.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JString.h"

// ============================================================================
// Address: 0x4138b0 | Symbol: JString::JString
// ============================================================================
undefined4 * JString__JString(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = JString::vftable;
  in_ECX[1] = 0;
  uVar1 = FUN_0042d2b4(1);
  in_ECX[1] = uVar1;
  *(undefined1 *)in_ECX[1] = 0;
  return in_ECX;
}

// ============================================================================
// Address: 0x413900 | Symbol: FUN_00413900
// ============================================================================
undefined4 * FUN_00413900(undefined1 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = JString::vftable;
  in_ECX[1] = 0;
  uVar1 = FUN_0042d2b4(2);
  in_ECX[1] = uVar1;
  *(undefined1 *)in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX[1] + 1) = 0;
  return in_ECX;
}

// ============================================================================
// Address: 0x413970 | Symbol: FUN_00413970
// ============================================================================
undefined4 * FUN_00413970(char *param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = JString::vftable;
  in_ECX[1] = 0;
  if (param_1 == (char *)0x0) {
    uVar2 = FUN_0042d2b4(1);
    in_ECX[1] = uVar2;
    *(undefined1 *)in_ECX[1] = 0;
  }
  else {
    sVar1 = _strlen(param_1);
    uVar2 = FUN_0042d2b4(sVar1 + 1);
    in_ECX[1] = uVar2;
    _strcpy((char *)in_ECX[1],param_1);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x413a00 | Symbol: FUN_00413a00
// ============================================================================
undefined4 * FUN_00413a00(long param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = JString::vftable;
  in_ECX[1] = 0;
  FID_conflict___ltoa(param_1,&DAT_0048e350,10);
  sVar1 = _strlen(&DAT_0048e350);
  uVar2 = FUN_0042d2b4(sVar1 + 1);
  in_ECX[1] = uVar2;
  _strcpy((char *)in_ECX[1],&DAT_0048e350);
  return in_ECX;
}

// ============================================================================
// Address: 0x413a80 | Symbol: FUN_00413a80
// ============================================================================
undefined4 * FUN_00413a80(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = JString::vftable;
  in_ECX[1] = 0;
  JString__operator_(param_1);
  return in_ECX;
}

// ============================================================================
// Address: 0x413ab0 | Symbol: JString::operator=
// ============================================================================
int JString__operator_(int param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    thunk_FUN_00451f46(*(undefined4 *)(in_ECX + 4));
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  if (*(int *)(param_1 + 4) != 0) {
    sVar1 = _strlen(*(char **)(param_1 + 4));
    uVar2 = FUN_0042d2b4(sVar1 + 1);
    *(undefined4 *)(in_ECX + 4) = uVar2;
    _strcpy(*(char **)(in_ECX + 4),*(char **)(param_1 + 4));
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x413b30 | Symbol: JString::operator+=
// ============================================================================
int JString__operator__(char param_1)

{
  size_t sVar1;
  char *_Dest;
  size_t _Count;
  int in_ECX;
  
  sVar1 = _strlen(*(char **)(in_ECX + 4));
  _Dest = (char *)FUN_0042d2b4(sVar1 + 2);
  _Count = _strlen(*(char **)(in_ECX + 4));
  _strncpy(_Dest,*(char **)(in_ECX + 4),_Count);
  _Dest[sVar1] = param_1;
  _Dest[sVar1 + 1] = '\0';
  if (*(int *)(in_ECX + 4) != 0) {
    thunk_FUN_00451f46(*(undefined4 *)(in_ECX + 4));
  }
  *(char **)(in_ECX + 4) = _Dest;
  return in_ECX;
}

// ============================================================================
// Address: 0x413bd0 | Symbol: FUN_00413bd0
// ============================================================================
int FUN_00413bd0(int param_1)

{
  size_t sVar1;
  size_t sVar2;
  char *_Dest;
  size_t sVar3;
  size_t sVar4;
  int in_ECX;
  char *_Source;
  
  sVar1 = _strlen(*(char **)(in_ECX + 4));
  sVar2 = _strlen(*(char **)(param_1 + 4));
  _Dest = (char *)FUN_0042d2b4(sVar1 + sVar2 + 1);
  sVar3 = _strlen(*(char **)(in_ECX + 4));
  _strncpy(_Dest,*(char **)(in_ECX + 4),sVar3);
  sVar3 = _strlen(*(char **)(param_1 + 4));
  _Source = *(char **)(param_1 + 4);
  sVar4 = _strlen(*(char **)(in_ECX + 4));
  _strncpy(_Dest + sVar4,_Source,sVar3);
  _Dest[sVar1 + sVar2] = '\0';
  if (*(int *)(in_ECX + 4) != 0) {
    thunk_FUN_00451f46(*(undefined4 *)(in_ECX + 4));
  }
  *(char **)(in_ECX + 4) = _Dest;
  return in_ECX;
}

// ============================================================================
// Address: 0x413cb0 | Symbol: JString::~JString
// ============================================================================
void JString___JString(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JString::vftable;
  if (in_ECX[1] != 0) {
    thunk_FUN_00451f46(in_ECX[1]);
  }
  in_ECX[1] = 0;
  return;
}

// ============================================================================
// Address: 0x413cf0 | Symbol: JString::c_str
// ============================================================================
undefined4 JString__c_str(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}

// ============================================================================
// Address: 0x413d10 | Symbol: JString::Length
// ============================================================================
void JString__Length(void)

{
  int in_ECX;
  
  _strlen(*(char **)(in_ECX + 4));
  return;
}

// ============================================================================
// Address: 0x413d30 | Symbol: JString::FindChar
// ============================================================================
int JString__FindChar(char param_1,uint param_2)

{
  size_t sVar1;
  int iVar2;
  int in_ECX;
  
  sVar1 = _strlen(*(char **)(in_ECX + 4));
  if (param_2 < sVar1) {
    iVar2 = strchr(*(int *)(in_ECX + 4) + param_2,(int)param_1);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = iVar2 - *(int *)(in_ECX + 4);
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

// ============================================================================
// Address: 0x413d90 | Symbol: JString::IsEqualTo
// ============================================================================
bool JString__IsEqualTo(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _strcmp(*(char **)(in_ECX + 4),*(char **)(param_1 + 4));
  return iVar1 == 0;
}

// ============================================================================
// Address: 0x413dd0 | Symbol: JString::ExtractString
// ============================================================================
undefined4 JString__ExtractString(undefined4 param_1,uint param_2,uint param_3)

{
  undefined1 local_28 [8];
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470ead;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  JString__JString(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  local_20 = _strlen(*(char **)(local_18 + 4));
  for (local_14 = param_2; (local_14 < local_20 && (local_14 <= param_3)); local_14 = local_14 + 1)
  {
    JString__operator__(*(undefined1 *)(*(int *)(local_18 + 4) + local_14));
  }
  FUN_00413a80(local_28);
  local_1c = local_1c | 1;
  local_8 = 0xffffffff;
  JString___JString();
  ExceptionList = local_10;
  return param_1;
}

// ============================================================================
// Address: 0x413e90 | Symbol: JString::ReplaceChar
// ============================================================================
void JString__ReplaceChar(char param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  int in_ECX;
  
  while (puVar1 = (undefined1 *)strchr(*(undefined4 *)(in_ECX + 4),(int)param_1),
        puVar1 != (undefined1 *)0x0) {
    *puVar1 = param_2;
  }
  return;
}

// ============================================================================
// Address: 0x413ee0 | Symbol: JString::ToUpper
// ============================================================================
void JString__ToUpper(void)

{
  int in_ECX;
  
  __strupr(*(char **)(in_ECX + 4));
  return;
}

// ============================================================================
// Address: 0x413f00 | Symbol: JString::ToLower
// ============================================================================
void JString__ToLower(void)

{
  int in_ECX;
  
  __strlwr(*(char **)(in_ECX + 4));
  return;
}

// ============================================================================
// Address: 0x413f20 | Symbol: JString::Strip
// ============================================================================
void JString__Strip(int param_1,char param_2)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  size_t local_20;
  uint local_1c;
  size_t local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470eef;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  local_18 = _strlen(*(char **)(in_ECX + 4));
  if ((local_18 != 0) && ((param_1 == 0 || (param_1 == 2)))) {
    for (local_1c = 0;
        (local_1c < local_18 && (*(char *)(*(int *)(local_14 + 4) + local_1c) == param_2));
        local_1c = local_1c + 1) {
    }
    if ((local_1c == 0) || (local_18 <= local_1c)) {
      if (local_18 <= local_1c) {
        FUN_00413970(&PTR_00473bac);
        local_8 = 1;
        JString__operator_(local_30);
        local_8 = 0xffffffff;
        JString___JString(uVar1);
      }
    }
    else {
      JString__ExtractString(local_28,local_1c,local_18 - 1);
      local_8 = 0;
      JString__operator_(local_28);
      local_8 = 0xffffffff;
      JString___JString(uVar1);
    }
  }
  local_18 = _strlen(*(char **)(local_14 + 4));
  if ((local_18 != 0) && ((local_20 = local_18, param_1 == 1 || (param_1 == 2)))) {
    do {
      local_20 = local_20 - 1;
      if ((int)local_20 < 0) break;
    } while (*(char *)(*(int *)(local_14 + 4) + local_20) == param_2);
    if (((int)local_20 < 0) || ((int)(local_18 - 1) <= (int)local_20)) {
      if ((int)local_20 < 0) {
        FUN_00413970(0x473bad);
        local_8 = 3;
        JString__operator_(local_40);
        local_8 = 0xffffffff;
        JString___JString();
      }
    }
    else {
      JString__ExtractString(local_38,0,local_20);
      local_8 = 2;
      JString__operator_(local_38);
      local_8 = 0xffffffff;
      JString___JString();
    }
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x414110 | Symbol: FUN_00414110
// ============================================================================
undefined4 FUN_00414110(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined1 local_1c [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470f19;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  FUN_00413a80(param_2);
  local_8 = 0;
  FUN_00413bd0(param_3);
  FUN_00413a80(local_1c);
  local_14 = local_14 | 1;
  local_8 = 0xffffffff;
  JString___JString(uVar1);
  ExceptionList = local_10;
  return param_1;
}

// ============================================================================
// Address: 0x4141a0 | Symbol: ByteToHex
// ============================================================================
/* WARNING: Removing unreachable block (ram,0x004141e7) */

undefined4 ByteToHex(undefined4 param_1,byte param_2)

{
  undefined1 local_24 [8];
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470f43;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  local_18 = (int)(uint)param_2 >> 4;
  local_1c = param_2 & 0x8000000f;
  JString__JString(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  JString__operator__(s_0123456789ABCDEF_00486cd8[local_18]);
  JString__operator__(s_0123456789ABCDEF_00486cd8[local_1c]);
  FUN_00413a80(local_24);
  local_14 = local_14 | 1;
  local_8 = 0xffffffff;
  JString___JString();
  ExceptionList = local_10;
  return param_1;
}

// ============================================================================
// Address: 0x414260 | Symbol: HexToByte
// ============================================================================
char HexToByte(void)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470f6d;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00413970(s_0123456789ABCDEF_00486cd8);
  local_8 = 0;
  uVar6 = 0;
  puVar2 = (undefined1 *)JString__c_str(0,uVar1);
  iVar3 = JString__FindChar(*puVar2,uVar6);
  uVar6 = 0;
  iVar4 = JString__c_str(0);
  iVar4 = JString__FindChar(*(undefined1 *)(iVar4 + 1),uVar6);
  if ((iVar3 < 0) || (iVar4 < 0)) {
    local_8 = 0xffffffff;
    JString___JString();
    cVar5 = '?';
  }
  else {
    cVar5 = (char)(iVar3 << 4) + (char)iVar4;
    local_8 = 0xffffffff;
    JString___JString();
  }
  ExceptionList = local_10;
  return cVar5;
}

// ============================================================================
// Address: 0x414340 | Symbol: EncryptString
// ============================================================================
undefined4 EncryptString(undefined4 param_1,undefined4 param_2)

{
  FUN_00413a80(param_2);
  return param_1;
}

// ============================================================================
// Address: 0x414370 | Symbol: DecryptString
// ============================================================================
undefined4 DecryptString(undefined4 param_1,undefined4 param_2)

{
  FUN_00413a80(param_2);
  return param_1;
}

// ============================================================================
// Address: 0x4143a0 | Symbol: GetJustPath
// ============================================================================
undefined4 GetJustPath(undefined4 param_1)

{
  int iVar1;
  undefined1 local_20 [8];
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470f97;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 0;
  local_14 = JString__Length(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  do {
    local_14 = local_14 + -1;
    if (local_14 < 1) break;
    iVar1 = JString__c_str();
  } while (*(char *)(iVar1 + local_14) != '\\');
  if (local_14 < 1) {
    FUN_00413970(&DAT_00473bb0);
  }
  else {
    JString__ExtractString(local_20,0,local_14);
    local_8 = 0;
    FUN_00413a80(local_20);
    local_18 = local_18 | 1;
    local_8 = 0xffffffff;
    JString___JString();
  }
  ExceptionList = local_10;
  return param_1;
}

// ============================================================================
// Address: 0x414480 | Symbol: GetCurrentPath
// ============================================================================
undefined4 GetCurrentPath(undefined4 param_1)

{
  uint uVar1;
  DWORD DVar2;
  undefined1 local_24 [8];
  undefined1 local_1c [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470fc9;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  DVar2 = GetModuleFileNameA((HMODULE)0x0,&DAT_0048e378,1000);
  if (DVar2 == 0) {
    FUN_00413970(&DAT_00473bb4);
  }
  else {
    FUN_00413970(&DAT_0048e378);
    local_8 = 0;
    GetJustPath(local_24,local_1c,uVar1);
    local_8 = CONCAT31(local_8._1_3_,2);
    JString___JString();
    FUN_00413a80(local_24);
    local_14 = local_14 | 1;
    local_8 = 0xffffffff;
    JString___JString();
  }
  ExceptionList = local_10;
  return param_1;
}

// ============================================================================
// Address: 0x414550 | Symbol: ConvertToFullPath
// ============================================================================
undefined4 ConvertToFullPath(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 local_74 [8];
  undefined1 local_6c [8];
  undefined1 local_64 [8];
  undefined1 local_5c [8];
  undefined1 local_54 [8];
  undefined1 local_4c [8];
  undefined1 local_44 [8];
  undefined1 local_3c [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047102b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0;
  GetCurrentPath(local_44,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  JString__JString();
  local_8._0_1_ = 1;
  if (param_3 == 0) {
    local_34 = FUN_00414110(local_74,local_44,param_2);
    local_8._0_1_ = 7;
    local_30 = local_34;
    JString__operator_(local_34);
    local_8 = CONCAT31(local_8._1_3_,1);
    JString___JString();
  }
  else {
    FUN_00413900(0x22);
    local_8._0_1_ = 2;
    FUN_00413900(0x22);
    local_8._0_1_ = 3;
    local_1c = FUN_00414110(local_6c,local_4c,local_44,param_2,local_54);
    local_8._0_1_ = 4;
    local_18 = local_1c;
    local_24 = FUN_00414110(local_64,local_1c);
    local_8._0_1_ = 5;
    local_20 = local_24;
    local_2c = FUN_00414110(local_5c,local_24);
    local_8._0_1_ = 6;
    local_28 = local_2c;
    JString__operator_(local_2c);
    local_8._0_1_ = 5;
    JString___JString();
    local_8._0_1_ = 4;
    JString___JString();
    local_8._0_1_ = 3;
    JString___JString();
    local_8._0_1_ = 2;
    JString___JString();
    local_8 = CONCAT31(local_8._1_3_,1);
    JString___JString();
  }
  FUN_00413a80(local_3c);
  local_14 = local_14 | 1;
  local_8 = local_8 & 0xffffff00;
  JString___JString();
  local_8 = 0xffffffff;
  JString___JString();
  ExceptionList = local_10;
  return param_1;
}

// ============================================================================
// Address: 0x4146f0 | Symbol: _ByteXOR
// ============================================================================
void _ByteXOR(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < param_3; local_8 = local_8 + 1) {
    uVar2 = JString__Length();
    bVar1 = *(byte *)(param_1 + local_8);
    iVar3 = JString__c_str();
    *(byte *)(param_2 + local_8) = bVar1 ^ *(byte *)(iVar3 + local_8 % uVar2);
  }
  return;
}

// ============================================================================
// Address: 0x414750 | Symbol: JString::
// ============================================================================
undefined4 JString__(uint param_1)

{
  undefined4 in_ECX;
  
  JString___JString();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,8);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x414780 | Symbol: strchr
// ============================================================================
void strchr(undefined4 param_1,undefined4 param_2)

{
  FUN_00430f20(param_1,param_2);
  return;
}
