// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JStringList.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JStringList.h"

// ============================================================================
// Address: 0x4147a0 | Symbol: JStringList::JStringList
// ============================================================================
undefined4 * JStringList__JStringList(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JStringList::vftable;
  JBaseList__JBaseList();
  return in_ECX;
}

// ============================================================================
// Address: 0x4147d0 | Symbol: JStringList::~JStringList
// ============================================================================
void JStringList___JStringList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00471050;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JStringList::vftable;
  JStringList__Empty(uVar1);
  JBaseList___JBaseList();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x414830 | Symbol: JStringList::Count
// ============================================================================
void JStringList__Count(void)

{
  JBaseList__Count();
  return;
}

// ============================================================================
// Address: 0x414850 | Symbol: JStringList::IsEmpty
// ============================================================================
void JStringList__IsEmpty(void)

{
  JBaseList__IsEmpty();
  return;
}

// ============================================================================
// Address: 0x414870 | Symbol: Concurrency::details::SchedulerBase::JStringList::Append
// ============================================================================
/* Library Function - Single Match
    public: void __thiscall Concurrency::details::SchedulerBase::AddContext(class
   Concurrency::details::InternalContextBase *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
Concurrency::details::SchedulerBase::JStringList__Append
          (SchedulerBase *this,InternalContextBase *param_1)

{
  int iVar1;
  undefined4 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471081;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_0042d23e(8,DAT_00486cf0 ^ (uint)&stack0xfffffffc,this);
  local_8 = 0;
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_00413a80(param_1);
  }
  local_8 = 0xffffffff;
  JBaseList__Append(local_18);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x414900 | Symbol: JStringList::Remove
// ============================================================================
void JStringList__Remove(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)JBaseList__GetData(param_1);
  if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  JBaseList__Remove(param_1);
  return;
}

// ============================================================================
// Address: 0x414960 | Symbol: JStringList::Empty
// ============================================================================
void JStringList__Empty(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint local_8;
  
  for (local_8 = 0; uVar1 = JBaseList__Count(), local_8 < uVar1; local_8 = local_8 + 1) {
    puVar2 = (undefined4 *)JBaseList__GetData(local_8);
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      (**(code **)*puVar2)(1);
    }
  }
  JBaseList__Empty();
  return;
}

// ============================================================================
// Address: 0x4149e0 | Symbol: JStringList::GetString
// ============================================================================
undefined4 JStringList__GetString(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = JBaseList__GetData(param_1);
  return uVar1;
}

// ============================================================================
// Address: 0x414a10 | Symbol: GetStringListFromResource
// ============================================================================
undefined4 GetStringListFromResource(SchedulerBase *param_1,ushort param_2)

{
  uint uVar1;
  int iVar2;
  InternalContextBase local_40 [8];
  InternalContextBase local_38 [16];
  undefined4 local_28;
  LPVOID local_24;
  HGLOBAL local_20;
  HRSRC local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004710bb;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = FindResourceA((HMODULE)0x0,(LPCSTR)(uint)param_2,(LPCSTR)0xa);
  if (local_1c == (HRSRC)0x0) {
    local_28 = 0;
  }
  else {
    local_20 = LoadResource((HMODULE)0x0,local_1c);
    if (local_20 == (HGLOBAL)0x0) {
      local_28 = 0;
    }
    else {
      local_24 = LockResource(local_20);
      if (local_24 == (LPVOID)0x0) {
        local_28 = 0;
      }
      else {
        JStringList__Empty(uVar1);
        FUN_00413970(local_24);
        local_8 = 0;
        local_14 = 0;
        while( true ) {
          uVar1 = JString__Length();
          if (uVar1 <= local_14) break;
          local_18 = JString__FindChar(10,local_14);
          if (local_18 < 0) {
            iVar2 = JString__Length();
            JString__ExtractString(local_40,local_14,iVar2 + -1);
            local_8._0_1_ = 2;
            Concurrency::details::SchedulerBase::JStringList__Append(param_1,local_40);
            local_8 = (uint)local_8._1_3_ << 8;
            JString___JString();
            break;
          }
          JString__ExtractString(local_38,local_14,local_18);
          local_8._0_1_ = 1;
          JString__ReplaceChar(0xd,10);
          JString__Strip(1,10);
          Concurrency::details::SchedulerBase::JStringList__Append(param_1,local_38);
          local_14 = local_18 + 1;
          local_8 = (uint)local_8._1_3_ << 8;
          JString___JString();
        }
        local_28 = 1;
        local_8 = 0xffffffff;
        JString___JString();
      }
    }
  }
  ExceptionList = local_10;
  return local_28;
}

// ============================================================================
// Address: 0x414ba0 | Symbol: GetStringListFromFile
// ============================================================================
undefined4 GetStringListFromFile(SchedulerBase *param_1)

{
  char *_Filename;
  int iVar1;
  int iVar2;
  char *_Mode;
  undefined1 local_38 [8];
  InternalContextBase local_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  FILE *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004710f5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _Mode = "r";
  _Filename = (char *)JString__c_str(&DAT_00473bc0,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_14 = _fopen(_Filename,_Mode);
  if (local_14 == (FILE *)0x0) {
    local_28 = 0;
  }
  else {
    JStringList__Empty();
    local_18 = 0;
    FUN_00413970(&DAT_00473bc2);
    local_8._0_1_ = 0;
    local_8._1_3_ = 0;
    while (local_18 == 0) {
      local_1c = FUN_0044d714(&DAT_0048e768,1000,local_14);
      if (local_1c == 0) {
        iVar1 = JString__Length();
        if (iVar1 != 0) {
          Concurrency::details::SchedulerBase::JStringList__Append(param_1,local_30);
        }
        local_18 = 1;
      }
      else {
        local_24 = FUN_00413970(&DAT_0048e768);
        local_8._0_1_ = 1;
        local_20 = local_24;
        JString__operator_(local_24);
        local_8._0_1_ = 0;
        JString___JString();
        iVar1 = JString__Length();
        if (iVar1 != 0) {
          iVar1 = JString__c_str();
          iVar2 = JString__Length();
          if (*(char *)(iVar1 + -1 + iVar2) == '\n') {
            JString__ReplaceChar(0xd,0x20);
            JString__ReplaceChar(10,0x20);
            Concurrency::details::SchedulerBase::JStringList__Append(param_1,local_30);
            FUN_00413970(&DAT_00473bc3);
            local_8._0_1_ = 2;
            JString__operator_(local_38);
            local_8._0_1_ = 0;
            JString___JString();
          }
        }
      }
    }
    _fclose(local_14);
    local_28 = 1;
    local_8 = 0xffffffff;
    JString___JString();
  }
  ExceptionList = local_10;
  return local_28;
}

// ============================================================================
// Address: 0x414d40 | Symbol: PutStringListToFile
// ============================================================================
undefined4 PutStringListToFile(void)

{
  char *_Filename;
  FILE *_File;
  undefined4 uVar1;
  uint uVar2;
  char *_Mode;
  uint local_8;
  
  _Mode = "w";
  _Filename = (char *)JString__c_str();
  _File = _fopen(_Filename,_Mode);
  if (_File == (FILE *)0x0) {
    uVar1 = 0;
  }
  else {
    local_8 = 0;
    while( true ) {
      uVar2 = JStringList__Count();
      if (uVar2 <= local_8) break;
      JStringList__GetString(local_8);
      uVar1 = JString__c_str();
      fprintf(_File,L"猥\nȸH䷰AʀH噠AˈH嚐A̐H巰A䅓呉䝏䵁卅䡟偏位彎䱃十S潈浰湯",
              uVar1);
      local_8 = local_8 + 1;
    }
    _fclose(_File);
    uVar1 = 1;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x414dd0 | Symbol: GetStringListFromBinaryFile
// ============================================================================
undefined4 GetStringListFromBinaryFile(void)

{
  return 0;
}

// ============================================================================
// Address: 0x414de0 | Symbol: PutStringListToBinaryFile
// ============================================================================
undefined4 PutStringListToBinaryFile(void)

{
  return 0;
}

// ============================================================================
// Address: 0x414df0 | Symbol: JStringList::
// ============================================================================
undefined4 JStringList__(uint param_1)

{
  undefined4 in_ECX;
  
  JStringList___JStringList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x10);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x414e20 | Symbol: _vfprintf_l
// ============================================================================
/* Library Function - Single Match
    __vfwprintf_l
   
   Library: Visual Studio 2019 Release */

int __cdecl _vfprintf_l(FILE *_File,wchar_t *_Format,_locale_t _Locale,va_list _ArgList)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)__local_stdio_printf_options(_File,_Format,_Locale,_ArgList);
  iVar2 = ___stdio_common_vfwprintf(*puVar1,puVar1[1]);
  return iVar2;
}

// ============================================================================
// Address: 0x414e50 | Symbol: fprintf
// ============================================================================
/* Library Function - Multiple Matches With Different Base Names
    _fprintf
    _fwprintf
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

int __cdecl fprintf(FILE *_File,wchar_t *_Format,...)

{
  int iVar1;
  
  iVar1 = _vfprintf_l(_File,_Format,(_locale_t)0x0,&stack0x0000000c);
  return iVar1;
}
