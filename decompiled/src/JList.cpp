// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JList.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JList.h"

// ============================================================================
// Address: 0x40eb90 | Symbol: JBaseList::JBaseList
// ============================================================================
undefined4 * JBaseList__JBaseList(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JBaseList::vftable;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  return in_ECX;
}

// ============================================================================
// Address: 0x40ebc0 | Symbol: JBaseList::~JBaseList
// ============================================================================
void JBaseList___JBaseList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00470b60;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JBaseList::vftable;
  JBaseList__Empty(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40ec10 | Symbol: JBaseList::GetData
// ============================================================================
undefined4 JBaseList__GetData(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)JBaseList__GetItemAt(param_1);
  return *puVar1;
}

// ============================================================================
// Address: 0x40ec40 | Symbol: JBaseList::Count
// ============================================================================
undefined4 JBaseList__Count(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}

// ============================================================================
// Address: 0x40ec60 | Symbol: JBaseList::IsEmpty
// ============================================================================
bool JBaseList__IsEmpty(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) == 0;
}

// ============================================================================
// Address: 0x40ec90 | Symbol: JBaseList::Append
// ============================================================================
void JBaseList__Append(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_0042d23e(8);
  *puVar1 = param_1;
  puVar1[1] = 0;
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 **)(in_ECX + 8) = puVar1;
  }
  else {
    iVar2 = JBaseList__GetLastItem();
    *(undefined4 **)(iVar2 + 4) = puVar1;
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return;
}

// ============================================================================
// Address: 0x40ed00 | Symbol: JBaseList::InsertBefore
// ============================================================================
void JBaseList__InsertBefore(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_0042d23e(8);
  *puVar1 = param_2;
  uVar2 = JBaseList__GetItemAt(param_1);
  puVar1[1] = uVar2;
  if (param_1 == 0) {
    *(undefined4 **)(in_ECX + 8) = puVar1;
  }
  else {
    iVar3 = JBaseList__GetItemAt(param_1 + -1);
    *(undefined4 **)(iVar3 + 4) = puVar1;
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return;
}

// ============================================================================
// Address: 0x40ed80 | Symbol: JBaseList::Remove
// ============================================================================
void JBaseList__Remove(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = JBaseList__GetItemAt(param_1);
  uVar1 = *(undefined4 *)(iVar2 + 4);
  if (param_1 == 0) {
    *(undefined4 *)(in_ECX + 8) = uVar1;
  }
  else {
    iVar3 = JBaseList__GetItemAt(param_1 + -1);
    *(undefined4 *)(iVar3 + 4) = uVar1;
  }
  FUN_0042d26e(iVar2,8);
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
  return;
}

// ============================================================================
// Address: 0x40ee00 | Symbol: JBaseList::Empty
// ============================================================================
void JBaseList__Empty(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = *(int *)(in_ECX + 8);
  while (local_8 != 0) {
    iVar1 = *(int *)(local_8 + 4);
    FUN_0042d26e(local_8,8);
    local_8 = iVar1;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}

// ============================================================================
// Address: 0x40ee60 | Symbol: JBaseList::GetFirstItem
// ============================================================================
undefined4 JBaseList__GetFirstItem(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}

// ============================================================================
// Address: 0x40ee80 | Symbol: JBaseList::GetLastItem
// ============================================================================
int JBaseList__GetLastItem(void)

{
  int in_ECX;
  undefined4 local_8;
  
  if (*(int *)(in_ECX + 4) == 0) {
    local_8 = 0;
  }
  else {
    for (local_8 = *(int *)(in_ECX + 8); *(int *)(local_8 + 4) != 0; local_8 = *(int *)(local_8 + 4)
        ) {
    }
  }
  return local_8;
}

// ============================================================================
// Address: 0x40eec0 | Symbol: JBaseList::GetItemAt
// ============================================================================
int JBaseList__GetItemAt(int param_1)

{
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = *(int *)(in_ECX + 8);
  for (; local_8 != param_1; local_8 = local_8 + 1) {
    local_c = *(int *)(local_c + 4);
  }
  return local_c;
}

// ============================================================================
// Address: 0x40ef00 | Symbol: JBaseList::
// ============================================================================
undefined4 JBaseList__(uint param_1)

{
  undefined4 in_ECX;
  
  JBaseList___JBaseList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0xc);
  }
  return in_ECX;
}
