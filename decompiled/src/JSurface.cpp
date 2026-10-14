// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JSurface.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JSurface.h"

// ============================================================================
// Address: 0x414e90 | Symbol: JSurface::JSurface
// ============================================================================
undefined4 * JSurface__JSurface(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = JSurface::vftable;
  in_ECX[1] = param_1;
  *(undefined2 *)(in_ECX + 2) = param_2;
  in_ECX[3] = 0;
  in_ECX[4] = 0xffffffff;
  in_ECX[5] = 0xffffffff;
  in_ECX[6] = param_3;
  in_ECX[7] = 0xffffffff;
  JSurface___Create();
  return in_ECX;
}

// ============================================================================
// Address: 0x414f00 | Symbol: JSurface::~JSurface
// ============================================================================
void JSurface___JSurface(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00471120;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JSurface::vftable;
  if (in_ECX[3] != 0) {
    (**(code **)(*(int *)in_ECX[3] + 8))(in_ECX[3],uVar1);
    in_ECX[3] = 0;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x414f70 | Symbol: JSurface::GetResID
// ============================================================================
undefined2 JSurface__GetResID(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 8);
}

// ============================================================================
// Address: 0x414f90 | Symbol: JSurface::GetDDSurface
// ============================================================================
undefined4 JSurface__GetDDSurface(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}

// ============================================================================
// Address: 0x414fb0 | Symbol: JSurface::GetWidth
// ============================================================================
undefined4 JSurface__GetWidth(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}

// ============================================================================
// Address: 0x414fd0 | Symbol: JSurface::GetHeight
// ============================================================================
undefined4 JSurface__GetHeight(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}

// ============================================================================
// Address: 0x414ff0 | Symbol: JSurface::UseColorKey
// ============================================================================
undefined4 JSurface__UseColorKey(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}

// ============================================================================
// Address: 0x415010 | Symbol: JSurface::SetColorKey
// ============================================================================
void JSurface__SetColorKey(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  if (*(int *)(in_ECX + 0x18) != 0) {
    DDSetColorKey(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x1c));
  }
  return;
}

// ============================================================================
// Address: 0x415050 | Symbol: JSurface::Restore
// ============================================================================
bool JSurface__Restore(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 8))(*(undefined4 *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  JSurface___Create();
  return *(int *)(in_ECX + 0xc) != 0;
}

// ============================================================================
// Address: 0x4150b0 | Symbol: CDocObjectServer::JSurface::Invalidate
// ============================================================================
/* Library Function - Single Match
    public: void __thiscall CDocObjectServer::ReleaseDocSite(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug, Visual Studio 2010 Debug */

void __thiscall CDocObjectServer::JSurface__Invalidate(CDocObjectServer *this)

{
  if (*(int *)(this + 0xc) != 0) {
    (**(code **)(**(int **)(this + 0xc) + 8))(*(undefined4 *)(this + 0xc));
    *(undefined4 *)(this + 0xc) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x4150f0 | Symbol: JSurface::_Create
// ============================================================================
void JSurface___Create(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = CD3DApplication__GetDDraw(*(undefined2 *)(in_ECX + 8),in_ECX + 0x10,in_ECX + 0x14);
  uVar1 = DDLoadBitmap(uVar1);
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  if (*(int *)(in_ECX + 0x18) != 0) {
    DDSetColorKey(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x1c));
  }
  return;
}

// ============================================================================
// Address: 0x415150 | Symbol: JSurfaceList::JSurfaceList
// ============================================================================
undefined4 * JSurfaceList__JSurfaceList(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471151;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JSurfaceList::vftable;
  in_ECX[1] = param_1;
  iVar2 = FUN_0042d23e(0xc,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JBaseList__JBaseList();
  }
  in_ECX[2] = local_1c;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4151f0 | Symbol: JSurfaceList::~JSurfaceList
// ============================================================================
void JSurfaceList___JSurfaceList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0047116e;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JSurfaceList::vftable;
  JSurfaceList__DestroyAllSurfaces(uVar1);
  if (in_ECX[2] != 0) {
    if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[2])(1);
    }
    in_ECX[2] = 0;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x415280 | Symbol: JSurfaceList::CreateSurface
// ============================================================================
bool JSurfaceList__CreateSurface(undefined2 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047119f;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = JSurfaceList__FindIndexOfResId(param_1);
  iVar3 = FUN_0042d23e(0x20,uVar1,uVar2);
  local_8 = 0;
  if (iVar3 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JSurface__JSurface(*(undefined4 *)(in_ECX + 4),param_1,param_2);
  }
  local_8 = 0xffffffff;
  iVar3 = JSurface__GetDDSurface();
  if (iVar3 != 0) {
    JBaseList__Append(local_1c);
  }
  ExceptionList = local_10;
  return iVar3 != 0;
}

// ============================================================================
// Address: 0x415340 | Symbol: JSurfaceList::DestroySurface
// ============================================================================
void JSurfaceList__DestroySurface(undefined2 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = JSurfaceList__FindIndexOfResId(param_1);
  if (-1 < iVar1) {
    puVar2 = (undefined4 *)JBaseList__GetData(iVar1);
    if ((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
      (**(code **)*puVar2)(1);
    }
    JBaseList__Remove(iVar1);
  }
  return;
}

// ============================================================================
// Address: 0x4153c0 | Symbol: JSurfaceList::DestroyAllSurfaces
// ============================================================================
void JSurfaceList__DestroyAllSurfaces(void)

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
// Address: 0x415450 | Symbol: JSurfaceList::GetByResId
// ============================================================================
undefined4 JSurfaceList__GetByResId(short param_1)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)JBaseList__GetFirstItem();
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = *local_8;
    sVar2 = JSurface__GetResID();
    if (sVar2 == param_1) break;
    local_8 = (undefined4 *)local_8[1];
  }
  return uVar1;
}

// ============================================================================
// Address: 0x4154a0 | Symbol: JSurfaceList::GetByIndex
// ============================================================================
undefined4 JSurfaceList__GetByIndex(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = JBaseList__Count();
  if (param_1 < uVar1) {
    uVar2 = JBaseList__GetData(param_1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x4154d0 | Symbol: JSurfaceList::RestoreAllSurfaces
// ============================================================================
undefined4 JSurfaceList__RestoreAllSurfaces(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    uVar1 = JBaseList__Count();
    if (uVar1 <= local_8) {
      return 1;
    }
    uVar2 = JBaseList__GetData(local_8);
    iVar3 = JSurface__Restore(uVar2);
    if (iVar3 == 0) break;
    local_8 = local_8 + 1;
  }
  return 0;
}

// ============================================================================
// Address: 0x415540 | Symbol: JSurfaceList::InvalidateAllSurfaces
// ============================================================================
void JSurfaceList__InvalidateAllSurfaces(void)

{
  uint uVar1;
  CDocObjectServer *this;
  undefined4 local_8;
  
  local_8 = 0;
  while( true ) {
    uVar1 = JBaseList__Count();
    if (uVar1 <= local_8) break;
    this = (CDocObjectServer *)JBaseList__GetData(local_8);
    CDocObjectServer::JSurface__Invalidate(this);
    local_8 = local_8 + 1;
  }
  return;
}

// ============================================================================
// Address: 0x415590 | Symbol: JSurfaceList::FindIndexOfResId
// ============================================================================
int JSurfaceList__FindIndexOfResId(short param_1)

{
  short sVar1;
  int local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)JBaseList__GetFirstItem();
  local_c = 0;
  while( true ) {
    if (local_8 == (undefined4 *)0x0) {
      return -1;
    }
    sVar1 = JSurface__GetResID(*local_8);
    if (sVar1 == param_1) break;
    local_c = local_c + 1;
    local_8 = (undefined4 *)local_8[1];
  }
  return local_c;
}

// ============================================================================
// Address: 0x415600 | Symbol: FillBufferRect
// ============================================================================
bool FillBufferRect(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_70 [20];
  undefined4 local_20;
  
  local_70[0] = 100;
  local_20 = DDColorMatch(param_1,param_3);
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,param_2,0,0,0x1000400,local_70);
  return iVar1 == 0;
}

// ============================================================================
// Address: 0x415660 | Symbol: JSurface::
// ============================================================================
undefined4 JSurface__(uint param_1)

{
  undefined4 in_ECX;
  
  JSurface___JSurface();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x20);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x415690 | Symbol: JSurfaceList::
// ============================================================================
undefined4 JSurfaceList__(uint param_1)

{
  undefined4 in_ECX;
  
  JSurfaceList___JSurfaceList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0xc);
  }
  return in_ECX;
}
