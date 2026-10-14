// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XEnemy.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XEnemy.h"

// ============================================================================
// Address: 0x41b670 | Symbol: XEnemyList::XEnemyList
// ============================================================================
undefined4 * XEnemyList__XEnemyList(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_8;
  
  *in_ECX = XEnemyList::vftable;
  in_ECX[1] = param_1;
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    in_ECX[local_8 + 2] = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x41b6c0 | Symbol: XEnemyList::~XEnemyList
// ============================================================================
void XEnemyList___XEnemyList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00471860;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XEnemyList::vftable;
  XEnemyList__Empty(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41b710 | Symbol: XEnemyList::CreateEnemy
// ============================================================================
undefined4 XEnemyList__CreateEnemy(char param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
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
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047196c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = XEnemyList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (iVar1 < 0) {
    uVar3 = 0;
  }
  else {
    if (param_1 == 'a') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 0;
      if (iVar2 == 0) {
        local_20 = 0;
      }
      else {
        local_20 = XEnemy_Ghost__XEnemy_Ghost(*(undefined4 *)(in_ECX + 4));
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_20;
    }
    else if (param_1 == 'b') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 1;
      if (iVar2 == 0) {
        local_28 = 0;
      }
      else {
        local_28 = XEnemy_Cube__XEnemy_Cube(*(undefined4 *)(in_ECX + 4));
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_28;
    }
    else if (param_1 == 'c') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 2;
      if (iVar2 == 0) {
        local_30 = 0;
      }
      else {
        local_30 = XEnemy_Kurage__XEnemy_Kurage(*(undefined4 *)(in_ECX + 4));
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_30;
    }
    else if (param_1 == 'd') {
      iVar2 = FUN_0042d23e(0x98);
      local_8 = 3;
      if (iVar2 == 0) {
        local_38 = 0;
      }
      else {
        local_38 = XEnemy_UFO__XEnemy_UFO(*(undefined4 *)(in_ECX + 4));
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_38;
    }
    else if (param_1 == 'e') {
      iVar2 = FUN_0042d23e(0x98);
      local_8 = 4;
      if (iVar2 == 0) {
        local_40 = 0;
      }
      else {
        local_40 = XEnemy_Sesame__XEnemy_Sesame(*(undefined4 *)(in_ECX + 4));
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_40;
    }
    else if (param_1 == 'm') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 5;
      if (iVar2 == 0) {
        local_48 = 0;
      }
      else {
        local_48 = XNeedleBall__XNeedleBall(*(undefined4 *)(in_ECX + 4),0);
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_48;
    }
    else if (param_1 == 'n') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 6;
      if (iVar2 == 0) {
        local_50 = 0;
      }
      else {
        local_50 = XNeedleBall__XNeedleBall(*(undefined4 *)(in_ECX + 4),2);
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_50;
    }
    else if (param_1 == 'o') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 7;
      if (iVar2 == 0) {
        local_58 = 0;
      }
      else {
        local_58 = XNeedleBallFast__XNeedleBallFast(*(undefined4 *)(in_ECX + 4),0);
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_58;
    }
    else if (param_1 == 'p') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 8;
      if (iVar2 == 0) {
        local_60 = 0;
      }
      else {
        local_60 = XNeedleBallFast__XNeedleBallFast(*(undefined4 *)(in_ECX + 4),2);
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_60;
    }
    else if (param_1 == 'q') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 9;
      if (iVar2 == 0) {
        local_68 = 0;
      }
      else {
        local_68 = XNeedleBox__XNeedleBox(*(undefined4 *)(in_ECX + 4));
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_68;
    }
    else if (param_1 == 'r') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 10;
      if (iVar2 == 0) {
        local_70 = 0;
      }
      else {
        local_70 = XNeedleBoxDrop__XNeedleBoxDrop(*(undefined4 *)(in_ECX + 4));
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_70;
    }
    else if (param_1 == 'x') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 0xb;
      if (iVar2 == 0) {
        local_78 = 0;
      }
      else {
        local_78 = XGate__XGate(*(undefined4 *)(in_ECX + 4),0);
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_78;
    }
    else if (param_1 == 'y') {
      iVar2 = FUN_0042d23e(0x90);
      local_8 = 0xc;
      if (iVar2 == 0) {
        local_80 = 0;
      }
      else {
        local_80 = XGate__XGate(*(undefined4 *)(in_ECX + 4),1);
      }
      *(undefined4 *)(in_ECX + 8 + iVar1 * 4) = local_80;
    }
    uVar3 = *(undefined4 *)(in_ECX + 8 + iVar1 * 4);
  }
  ExceptionList = local_10;
  return uVar3;
}

// ============================================================================
// Address: 0x41bca0 | Symbol: XEnemyList::GetAt
// ============================================================================
undefined4 XEnemyList__GetAt(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8 + param_1 * 4);
}

// ============================================================================
// Address: 0x41bcc0 | Symbol: XEnemyList::Empty
// ============================================================================
void XEnemyList__Empty(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      puVar1 = *(undefined4 **)(in_ECX + 8 + local_8 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      *(undefined4 *)(in_ECX + 8 + local_8 * 4) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x41bd30 | Symbol: XEnemyList::CheckCollisionWithPac
// ============================================================================
void XEnemyList__CheckCollisionWithPac(void)

{
  int iVar1;
  int in_ECX;
  int local_c;
  
  iVar1 = XPac__GetState();
  if (((iVar1 != 0) && (iVar1 = XPac__GetState(), iVar1 != 4)) &&
     (iVar1 = XPac__GetState(), iVar1 != 5)) {
    for (local_c = 0; local_c < 0x1e; local_c = local_c + 1) {
      if (((*(int *)(in_ECX + 8 + local_c * 4) != 0) && (iVar1 = XEnemyBase__GetState(), iVar1 != 0)
          ) && ((iVar1 = XEnemyBase__GetState(), iVar1 != 4 &&
                (iVar1 = JObject3DBase__CheckCollisionRadius
                                   (*(undefined4 *)(in_ECX + 8 + local_c * 4)), iVar1 != 0)))) {
        XPac__StartDying();
        return;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x41be10 | Symbol: XEnemyList::ProcessRotate
// ============================================================================
void XEnemyList__ProcessRotate(undefined4 param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      XEnemyBase__ProcessRotate(param_1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x41be60 | Symbol: XEnemyList::ProcessFrame
// ============================================================================
void XEnemyList__ProcessFrame(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      XEnemyBase__ProcessFrame();
      iVar2 = XEnemyBase__GetState();
      if (iVar2 == 0) {
        puVar1 = *(undefined4 **)(in_ECX + 8 + local_8 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(in_ECX + 8 + local_8 * 4) = 0;
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x41bf00 | Symbol: XEnemyList::Render
// ============================================================================
void XEnemyList__Render(void)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x14))();
    }
  }
  return;
}

// ============================================================================
// Address: 0x41bf50 | Symbol: XEnemyList::GetNullIndex
// ============================================================================
int XEnemyList__GetNullIndex(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x1d < local_8) {
      return -1;
    }
    if (*(int *)(in_ECX + 8 + local_8 * 4) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x41bf90 | Symbol: XEnemyBase::XEnemyBase
// ============================================================================
undefined4 * XEnemyBase__XEnemyBase(int param_1,undefined2 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004719ab;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  JObject3DX__JObject3DX(*(undefined4 *)(param_1 + 4),param_2);
  local_8 = 0;
  *in_ECX = XEnemyBase::vftable;
  in_ECX[0x17] = param_1;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0xffffffff;
  in_ECX[0x1b] = 0xffffffff;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  in_ECX[0x1f] = 0xffffffff;
  iVar2 = FUN_0042d23e(0x88,uVar1);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JObject3D_Shadow__JObject3D_Shadow
                         (*(undefined4 *)(param_1 + 4),0x3f800000,0x3f800000);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x20] = local_1c;
  in_ECX[0x21] = 1;
  in_ECX[0x22] = 1;
  in_ECX[0x23] = 1;
  (**(code **)(*(int *)in_ECX[0x20] + 0x20))(0xa3,0,0,0x3f800000,0x3f800000);
  in_ECX[0x18] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41c140 | Symbol: XEnemyBase::~XEnemyBase
// ============================================================================
void XEnemyBase___XEnemyBase(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemyBase::vftable;
  if (in_ECX[0x20] != 0) {
    if ((undefined4 *)in_ECX[0x20] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x20])(1);
    }
    in_ECX[0x20] = 0;
  }
  JObject3DX___JObject3DX();
  return;
}

// ============================================================================
// Address: 0x41c1b0 | Symbol: XEnemyBase::Render
// ============================================================================
void XEnemyBase__Render(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) != 0) {
    JObject3DX__Render();
    uVar1 = _D3DVECTOR___D3DVECTOR
                      (*(undefined4 *)(in_ECX + 8),0x3f800000,*(undefined4 *)(in_ECX + 0x10));
    JObject3DBase__SetWorldPos(uVar1);
    (**(code **)(**(int **)(in_ECX + 0x80) + 0x14))();
  }
  return;
}

// ============================================================================
// Address: 0x41c230 | Symbol: XEnemyBase::GetState
// ============================================================================
undefined4 XEnemyBase__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x60);
}

// ============================================================================
// Address: 0x41c250 | Symbol: XEnemyBase::Breakable
// ============================================================================
undefined4 XEnemyBase__Breakable(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x88);
}

// ============================================================================
// Address: 0x41c270 | Symbol: XEnemyBase::SetMapPos
// ============================================================================
void XEnemyBase__SetMapPos(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x68) = param_1;
  *(undefined4 *)(in_ECX + 0x6c) = param_2;
  return;
}

// ============================================================================
// Address: 0x41c290 | Symbol: XEnemyBase::SetDirection
// ============================================================================
void XEnemyBase__SetDirection(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x84) != 0) {
    if (param_1 == 0) {
      JObject3DBase__RotateTo(1,0);
    }
    else if (param_1 == 1) {
      JObject3DBase__RotateTo(1,0x3fc90fdb);
    }
    else if (param_1 == 2) {
      JObject3DBase__RotateTo(1,0x40490fdb);
    }
    else if (param_1 == 3) {
      JObject3DBase__RotateTo(1,0x4096cbe4);
    }
  }
  *(int *)(in_ECX + 0x7c) = param_1;
  return;
}

// ============================================================================
// Address: 0x41c330 | Symbol: XEnemyBase::StartMoving
// ============================================================================
void XEnemyBase__StartMoving(int param_1)

{
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x60) == 1) {
    local_c = *(int *)(in_ECX + 0x68);
    local_10 = *(int *)(in_ECX + 0x6c);
    if (param_1 == 0) {
      local_10 = local_10 + -1;
    }
    else if (param_1 == 1) {
      local_c = local_c + 1;
    }
    else if (param_1 == 2) {
      local_10 = local_10 + 1;
    }
    else if (param_1 == 3) {
      local_c = local_c + -1;
    }
    XMap__UpdateEnemyMap
              (*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),local_c,local_10);
    *(int *)(in_ECX + 0x68) = local_c;
    *(int *)(in_ECX + 0x6c) = local_10;
    XEnemyBase__SetDirection(param_1);
    *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x60) = 2;
    *(undefined4 *)(in_ECX + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41c420 | Symbol: XEnemyBase::StartDying
// ============================================================================
void XEnemyBase__StartDying(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  XMap__ZeroEnemyMap(*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c));
  JObject3DX__SetCurrentFrame(0);
  uVar1 = param_1 + 2U & 0x80000003;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
  }
  XEnemyBase__SetDirection(uVar1);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x60) = 4;
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

// ============================================================================
// Address: 0x41c4a0 | Symbol: XEnemyBase::StartFiring
// ============================================================================
void XEnemyBase__StartFiring(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x60) = 3;
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

// ============================================================================
// Address: 0x41c4e0 | Symbol: XEnemyBase::DecreaseShield
// ============================================================================
void XEnemyBase__DecreaseShield(undefined4 param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + -1;
  if (*(int *)(in_ECX + 0x8c) < 1) {
    XEnemyBase__StartDying(param_1);
  }
  return;
}

// ============================================================================
// Address: 0x41c520 | Symbol: XEnemyBase::ProcessRotate
// ============================================================================
void XEnemyBase__ProcessRotate(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[0x18] == 4) {
    (**(code **)(*in_ECX + 0x20))(param_1);
  }
  else if (in_ECX[0x18] == 2) {
    (**(code **)(*in_ECX + 0x24))(param_1);
  }
  else if (in_ECX[0x18] == 3) {
    (**(code **)(*in_ECX + 0x28))(param_1);
  }
  return;
}

// ============================================================================
// Address: 0x41c580 | Symbol: XEnemyBase::SubProcessDyingRotate
// ============================================================================
void XEnemyBase__SubProcessDyingRotate(int param_1)

{
  int *in_ECX;
  float fVar1;
  
  fVar1 = (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.13962634;
  if (in_ECX[0x1f] == 0) {
    (**(code **)(*in_ECX + 0xc))(0,-fVar1);
  }
  else if (in_ECX[0x1f] == 2) {
    (**(code **)(*in_ECX + 0xc))(0,fVar1);
  }
  else if (in_ECX[0x1f] == 1) {
    (**(code **)(*in_ECX + 0xc))(2,fVar1);
  }
  else if (in_ECX[0x1f] == 3) {
    (**(code **)(*in_ECX + 0xc))
              (2,-fVar1,(double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)],0x3e0efa35);
  }
  return;
}

// ============================================================================
// Address: 0x41c670 | Symbol: XEnemyBase::SubProcessMoveRotate
// ============================================================================
void XEnemyBase__SubProcessMoveRotate(void)

{
  return;
}

// ============================================================================
// Address: 0x41c680 | Symbol: XEnemyBase::SubProcessFireRotate
// ============================================================================
void XEnemyBase__SubProcessFireRotate(void)

{
  return;
}

// ============================================================================
// Address: 0x41c690 | Symbol: XEnemyBase::ProcessFrame
// ============================================================================
void XEnemyBase__ProcessFrame(void)

{
  int *in_ECX;
  
  in_ECX[0x19] = in_ECX[0x19] + 1;
  if (in_ECX[0x18] == 4) {
    (**(code **)(*in_ECX + 0x2c))();
  }
  else if (in_ECX[0x18] == 2) {
    (**(code **)(*in_ECX + 0x30))();
  }
  else if (in_ECX[0x18] == 3) {
    (**(code **)(*in_ECX + 0x38))();
  }
  if (in_ECX[0x18] == 1) {
    (**(code **)(*in_ECX + 0x34))();
  }
  return;
}

// ============================================================================
// Address: 0x41c710 | Symbol: XEnemyBase::SubProcessDying
// ============================================================================
void XEnemyBase__SubProcessDying(void)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 local_34 [12];
  undefined1 local_28 [12];
  double local_1c;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  
  local_c = *(int *)(in_ECX + 100);
  local_1c = (double)local_c + (double)(&DAT_00473840)[-(local_c >> 0x1f)];
  local_8 = in_ECX;
  fVar2 = (float10)sinf(((float)local_1c / 160.0) * 3.1415927);
  local_10 = (float)fVar2;
  local_14 = local_10 * 120.0;
  _D3DVECTOR___D3DVECTOR(0,local_14,0);
  uVar1 = FUN_00404050(local_34,local_8 + 0x70,local_28);
  JObject3DBase__SetWorldPos(uVar1);
  if (*(float *)(local_8 + 0xc) - *(float *)(local_8 + 0x14) < 0.0) {
    XParticleList__CreateEnemyExplode
              (*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0xc),
               *(undefined4 *)(local_8 + 0x10));
    *(undefined4 *)(local_8 + 0x60) = 0;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41c820 | Symbol: XEnemyBase::SubProcessMove
// ============================================================================
void XEnemyBase__SubProcessMove(void)

{
  return;
}

// ============================================================================
// Address: 0x41c830 | Symbol: XEnemyBase::SubProcessWait
// ============================================================================
void XEnemyBase__SubProcessWait(void)

{
  return;
}

// ============================================================================
// Address: 0x41c840 | Symbol: XEnemyBase::SubProcessFire
// ============================================================================
void XEnemyBase__SubProcessFire(void)

{
  return;
}

// ============================================================================
// Address: 0x41c850 | Symbol: XEnemyBase::IsBlocked
// ============================================================================
void XEnemyBase__IsBlocked(int param_1)

{
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *(int *)(in_ECX + 0x68);
  local_8 = *(int *)(in_ECX + 0x6c);
  if (param_1 == 0) {
    local_8 = local_8 + -1;
  }
  else if (param_1 == 1) {
    local_c = local_c + 1;
  }
  else if (param_1 == 2) {
    local_8 = local_8 + 1;
  }
  else if (param_1 == 3) {
    local_c = local_c + -1;
  }
  XMap__IsBlocked_Enemy(local_c,local_8);
  return;
}

// ============================================================================
// Address: 0x41c8d0 | Symbol: XEnemyBase::FindDirectionToPac
// ============================================================================
undefined4 XEnemyBase__FindDirectionToPac(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_8;
  
  iVar1 = XPac__GetMapPosX();
  iVar2 = XPac__GetMapPosZ();
  iVar3 = FUN_0044da60(iVar1 - *(int *)(in_ECX + 0x68));
  iVar4 = FUN_0044da60(iVar2 - *(int *)(in_ECX + 0x6c));
  local_8 = 0xffffffff;
  if ((iVar3 == 0) && (iVar4 == 0)) {
    local_8 = 0xffffffff;
  }
  else if (iVar4 < iVar3) {
    if (*(int *)(in_ECX + 0x68) < iVar1) {
      local_8 = 1;
    }
    else {
      local_8 = 3;
    }
  }
  else if (iVar3 < iVar4) {
    if (*(int *)(in_ECX + 0x6c) < iVar2) {
      local_8 = 2;
    }
    else {
      local_8 = 0;
    }
  }
  else if (iVar3 == iVar4) {
    iVar3 = Random(2);
    if (iVar3 == 0) {
      if (*(int *)(in_ECX + 0x68) < iVar1) {
        local_8 = 1;
      }
      else {
        local_8 = 3;
      }
    }
    else if (*(int *)(in_ECX + 0x6c) < iVar2) {
      local_8 = 2;
    }
    else {
      local_8 = 0;
    }
  }
  return local_8;
}

// ============================================================================
// Address: 0x41c9f0 | Symbol: XEnemyBase::DefaultProcessWait
// ============================================================================
void XEnemyBase__DefaultProcessWait(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004719d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JBaseList__JBaseList(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  uVar4 = *(int *)(in_ECX + 0x7c) + 1U & 0x80000003;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
  }
  uVar1 = *(int *)(in_ECX + 0x7c) + 2U & 0x80000003;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
  }
  uVar5 = *(int *)(in_ECX + 0x7c) + 3U & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  iVar2 = XEnemyBase__IsBlocked(*(undefined4 *)(in_ECX + 0x7c));
  if (iVar2 == 0) {
    JBaseList__Append(*(undefined4 *)(in_ECX + 0x7c));
    JBaseList__Append(*(undefined4 *)(in_ECX + 0x7c));
  }
  iVar2 = XEnemyBase__IsBlocked(uVar4);
  if (iVar2 == 0) {
    JBaseList__Append(uVar4);
  }
  iVar2 = XEnemyBase__IsBlocked(uVar5);
  if (iVar2 == 0) {
    JBaseList__Append(uVar5);
  }
  uVar4 = XEnemyBase__FindDirectionToPac();
  if (((-1 < (int)uVar4) && (uVar4 != uVar1)) && (iVar2 = XEnemyBase__IsBlocked(uVar4), iVar2 == 0))
  {
    JBaseList__Append(uVar4);
  }
  iVar2 = JBaseList__Count();
  if (iVar2 < 1) {
    iVar2 = XEnemyBase__IsBlocked(uVar1);
    if (iVar2 == 0) {
      XEnemyBase__StartMoving(uVar1);
    }
  }
  else {
    uVar3 = Random(iVar2);
    uVar3 = JBaseList__GetData(uVar3);
    XEnemyBase__StartMoving(uVar3);
  }
  local_8 = 0xffffffff;
  JBaseList___JBaseList();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41cb90 | Symbol: XEnemy_Ghost::XEnemy_Ghost
// ============================================================================
undefined4 * XEnemy_Ghost__XEnemy_Ghost(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004719ff;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0x9d);
  local_8 = 0;
  *in_ECX = XEnemy_Ghost::vftable;
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x42480000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x41100000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x21] = 1;
  uVar2 = Random(4);
  XEnemyBase__SetDirection(uVar2);
  in_ECX[0x23] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41ccb0 | Symbol: XEnemy_Ghost::~XEnemy_Ghost
// ============================================================================
void XEnemy_Ghost___XEnemy_Ghost(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemy_Ghost::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41ccd0 | Symbol: XEnemy_Ghost::SubProcessMove
// ============================================================================
void XEnemy_Ghost__SubProcessMove(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  undefined1 local_28 [12];
  double local_1c;
  float local_14;
  int local_10;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  local_8 = in_ECX;
  if (*(uint *)(in_ECX + 100) < 0x3c) {
    local_10 = *(int *)(in_ECX + 100);
    local_1c = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
    local_14 = (float)local_1c / 60.0;
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = local_14 * *pfVar1;
  }
  else {
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = *pfVar1;
  }
  uVar2 = GetVectorFromDir(local_34,*(undefined4 *)(local_8 + 0x7c),local_c);
  FUN_00413780(local_28,uVar2);
  uVar2 = FUN_00404050(local_40,local_8 + 0x70,local_28);
  JObject3DBase__SetWorldPos(uVar2);
  if (0x3b < *(uint *)(local_8 + 100)) {
    *(undefined4 *)(local_8 + 0x60) = 1;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41cdc0 | Symbol: XEnemy_Ghost::SubProcessWait
// ============================================================================
void XEnemy_Ghost__SubProcessWait(void)

{
  XEnemyBase__DefaultProcessWait();
  return;
}

// ============================================================================
// Address: 0x41cde0 | Symbol: XEnemy_Cube::XEnemy_Cube
// ============================================================================
undefined4 * XEnemy_Cube__XEnemy_Cube(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471a29;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0x149);
  local_8 = 0;
  *in_ECX = XEnemy_Cube::vftable;
  JObject3DX__AppendExtraFrame(0xa4);
  JObject3DX__SetCurrentFrame(1);
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x427c0000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x41200000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x21] = 0;
  uVar2 = Random(4);
  XEnemyBase__SetDirection(uVar2);
  in_ECX[0x23] = 2;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41cf20 | Symbol: XEnemy_Cube::~XEnemy_Cube
// ============================================================================
void XEnemy_Cube___XEnemy_Cube(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemy_Cube::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41cf40 | Symbol: XEnemy_Cube::SubProcessMoveRotate
// ============================================================================
void XEnemy_Cube__SubProcessMoveRotate(int param_1)

{
  int *in_ECX;
  float fVar1;
  
  fVar1 = (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.02685122;
  if (in_ECX[0x1f] == 0) {
    (**(code **)(*in_ECX + 0xc))(0,fVar1);
  }
  else if (in_ECX[0x1f] == 2) {
    (**(code **)(*in_ECX + 0xc))(0,-fVar1);
  }
  else if (in_ECX[0x1f] == 1) {
    (**(code **)(*in_ECX + 0xc))(2,-fVar1);
  }
  else if (in_ECX[0x1f] == 3) {
    (**(code **)(*in_ECX + 0xc))
              (2,fVar1,(double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)],0x3cdbf717);
  }
  return;
}

// ============================================================================
// Address: 0x41d030 | Symbol: XEnemy_Cube::SubProcessMove
// ============================================================================
void XEnemy_Cube__SubProcessMove(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_44 [12];
  undefined1 local_38 [12];
  undefined1 local_2c [12];
  double local_20;
  float local_18;
  uint local_14;
  int local_10;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  local_8 = in_ECX;
  if (*(uint *)(in_ECX + 100) < 0x41) {
    local_10 = *(int *)(in_ECX + 100);
    local_20 = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
    local_18 = (float)local_20 / 65.0;
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = local_18 * *pfVar1;
  }
  else {
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = *pfVar1;
  }
  uVar2 = GetVectorFromDir(local_38,*(undefined4 *)(local_8 + 0x7c),local_c);
  FUN_00413780(local_2c,uVar2);
  uVar2 = FUN_00404050(local_44,local_8 + 0x70,local_2c);
  JObject3DBase__SetWorldPos(uVar2);
  local_14 = (uint)(1 < *(int *)(local_8 + 0x8c));
  JObject3DX__SetCurrentFrame(local_14);
  if (0x40 < *(uint *)(local_8 + 100)) {
    *(undefined4 *)(local_8 + 0x60) = 1;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41d150 | Symbol: XEnemy_Cube::SubProcessWait
// ============================================================================
void XEnemy_Cube__SubProcessWait(void)

{
  XEnemyBase__DefaultProcessWait();
  return;
}

// ============================================================================
// Address: 0x41d170 | Symbol: XEnemy_Kurage::XEnemy_Kurage
// ============================================================================
undefined4 * XEnemy_Kurage__XEnemy_Kurage(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471a53;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0xaf);
  local_8 = 0;
  *in_ECX = XEnemy_Kurage::vftable;
  JObject3DX__AppendExtraFrame(0xae);
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x42a00000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x21] = 0;
  uVar2 = Random(4);
  XEnemyBase__SetDirection(uVar2);
  in_ECX[0x23] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41d2a0 | Symbol: XEnemy_Kurage::~XEnemy_Kurage
// ============================================================================
void XEnemy_Kurage___XEnemy_Kurage(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemy_Kurage::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41d2c0 | Symbol: XEnemy_Kurage::SubProcessMove
// ============================================================================
void XEnemy_Kurage__SubProcessMove(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  undefined1 local_54 [12];
  undefined1 local_48 [12];
  undefined1 local_3c [4];
  float local_38;
  double local_30;
  double local_28;
  float local_20;
  float local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  local_10 = 0.0;
  local_8 = in_ECX;
  if (*(uint *)(in_ECX + 100) < 0x50) {
    local_14 = *(int *)(in_ECX + 100);
    local_28 = (double)local_14 + (double)(&DAT_00473840)[-(local_14 >> 0x1f)];
    local_1c = (float)local_28 / 80.0;
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = local_1c * *pfVar1;
    local_18 = *(int *)(local_8 + 100);
    local_30 = (double)local_18 + (double)(&DAT_00473840)[-(local_18 >> 0x1f)];
    fVar3 = (float10)sinf(((float)local_30 / 80.0) * 3.1415927);
    local_20 = (float)fVar3;
    local_10 = local_20 * 47.0;
    JObject3DX__SetCurrentFrame(1);
  }
  else {
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = *pfVar1;
    local_10 = 0.0;
    JObject3DX__SetCurrentFrame(0);
  }
  uVar2 = GetVectorFromDir(local_48,*(undefined4 *)(local_8 + 0x7c),local_c);
  FUN_00413780(local_3c,uVar2);
  local_38 = local_10;
  uVar2 = FUN_00404050(local_54,local_8 + 0x70,local_3c);
  JObject3DBase__SetWorldPos(uVar2);
  if (0x4f < *(uint *)(local_8 + 100)) {
    *(undefined4 *)(local_8 + 0x60) = 1;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41d440 | Symbol: XEnemy_Kurage::SubProcessWait
// ============================================================================
void XEnemy_Kurage__SubProcessWait(void)

{
  int in_ECX;
  
  if (0x14 < *(uint *)(in_ECX + 100)) {
    XEnemyBase__DefaultProcessWait();
  }
  return;
}

// ============================================================================
// Address: 0x41d460 | Symbol: XEnemy_UFO::XEnemy_UFO
// ============================================================================
undefined4 * XEnemy_UFO__XEnemy_UFO(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471a7d;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0xad);
  local_8 = 0;
  *in_ECX = XEnemy_UFO::vftable;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42480000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x42700000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x42c80000);
  JObject3DBase__SetCollisionRadius(0x41900000);
  in_ECX[0x21] = 0;
  uVar2 = Random(4);
  XEnemyBase__SetDirection(uVar2);
  in_ECX[0x22] = 0;
  iVar3 = Random(6);
  in_ECX[0x25] = iVar3 + 3;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41d5b0 | Symbol: XEnemy_UFO::~XEnemy_UFO
// ============================================================================
void XEnemy_UFO___XEnemy_UFO(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemy_UFO::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41d5d0 | Symbol: XEnemy_UFO::SubProcessMoveRotate
// ============================================================================
void XEnemy_UFO__SubProcessMoveRotate(int param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))
            (1,(float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.017453292,
             (double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)],0x3c8efa35);
  return;
}

// ============================================================================
// Address: 0x41d640 | Symbol: XEnemy_UFO::SubProcessFireRotate
// ============================================================================
void XEnemy_UFO__SubProcessFireRotate(int param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))
            (1,(float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.04363323,
             (double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)],0x3d32b8c2);
  return;
}

// ============================================================================
// Address: 0x41d6b0 | Symbol: XEnemy_UFO::SubProcessMove
// ============================================================================
void XEnemy_UFO__SubProcessMove(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  undefined1 local_28 [12];
  double local_1c;
  float local_14;
  int local_10;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  local_8 = in_ECX;
  if (*(uint *)(in_ECX + 100) < 100) {
    local_10 = *(int *)(in_ECX + 100);
    local_1c = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
    local_14 = (float)local_1c / 100.0;
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = local_14 * *pfVar1;
  }
  else {
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = *pfVar1;
  }
  uVar2 = GetVectorFromDir(local_34,*(undefined4 *)(local_8 + 0x7c),local_c);
  FUN_00413780(local_28,uVar2);
  uVar2 = FUN_00404050(local_40,local_8 + 0x70,local_28);
  JObject3DBase__SetWorldPos(uVar2);
  if (99 < *(uint *)(local_8 + 100)) {
    *(int *)(local_8 + 0x90) = *(int *)(local_8 + 0x90) + 1;
    *(undefined4 *)(local_8 + 0x60) = 1;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41d7c0 | Symbol: XEnemy_UFO::SubProcessWait
// ============================================================================
void XEnemy_UFO__SubProcessWait(void)

{
  byte bVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_10;
  
  local_10 = *(int *)(in_ECX + 0x7c);
  if (2 < *(int *)(in_ECX + 0x90)) {
    *(undefined4 *)(in_ECX + 0x90) = 0;
    *(int *)(in_ECX + 0x94) = *(int *)(in_ECX + 0x94) + -1;
    if (*(int *)(in_ECX + 0x94) < 1) {
      iVar2 = Random(5);
      *(int *)(in_ECX + 0x94) = iVar2 + 2;
      iVar2 = XMap__IsBlocked_Fire(*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c));
      if (iVar2 == 0) {
        bVar1 = XGameObject__GetVolumeOfPosition
                          (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                           *(undefined4 *)(in_ECX + 0x10));
        uVar5 = 0;
        uVar3 = (uint)bVar1;
        uVar4 = 0x13f;
        XApplication__GetSoundList(0x13f,uVar3,0);
        JSoundList__Play(uVar4,uVar3,uVar5);
        XEnemyBase__StartFiring();
        return;
      }
    }
    iVar2 = Random(2);
    if (iVar2 == 0) {
      local_10 = XEnemyBase__FindDirectionToPac();
      if (local_10 < 0) {
        local_10 = Random(4);
      }
    }
    else {
      local_10 = Random(4);
    }
  }
  iVar2 = XEnemy_UFO__IsBlocked_UFO(local_10);
  if (iVar2 != 0) {
    local_10 = Random(4);
  }
  iVar2 = XEnemy_UFO__IsBlocked_UFO(local_10);
  if (iVar2 == 0) {
    XEnemy_UFO__StartMoving_UFO(local_10);
  }
  return;
}

// ============================================================================
// Address: 0x41d920 | Symbol: XEnemy_UFO::SubProcessFire
// ============================================================================
void XEnemy_UFO__SubProcessFire(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) == 0xaa) {
    XEnemyFireList__CreateUFOFire
              (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
               *(undefined4 *)(in_ECX + 0x10));
  }
  else if (299 < *(uint *)(in_ECX + 100)) {
    *(undefined4 *)(in_ECX + 0x60) = 1;
    *(undefined4 *)(in_ECX + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41d990 | Symbol: XEnemy_UFO::StartMoving_UFO
// ============================================================================
void XEnemy_UFO__StartMoving_UFO(int param_1)

{
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x60) == 1) {
    local_c = *(int *)(in_ECX + 0x68);
    local_10 = *(int *)(in_ECX + 0x6c);
    if (param_1 == 0) {
      local_10 = local_10 + -1;
    }
    else if (param_1 == 1) {
      local_c = local_c + 1;
    }
    else if (param_1 == 2) {
      local_10 = local_10 + 1;
    }
    else if (param_1 == 3) {
      local_c = local_c + -1;
    }
    XMap__UpdateUFOMap(*(undefined4 *)(in_ECX + 0x68),*(undefined4 *)(in_ECX + 0x6c),local_c,
                       local_10);
    *(int *)(in_ECX + 0x68) = local_c;
    *(int *)(in_ECX + 0x6c) = local_10;
    XEnemyBase__SetDirection(param_1);
    *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x60) = 2;
    *(undefined4 *)(in_ECX + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41da80 | Symbol: XEnemy_UFO::IsBlocked_UFO
// ============================================================================
void XEnemy_UFO__IsBlocked_UFO(int param_1)

{
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *(int *)(in_ECX + 0x68);
  local_8 = *(int *)(in_ECX + 0x6c);
  if (param_1 == 0) {
    local_8 = local_8 + -1;
  }
  else if (param_1 == 1) {
    local_c = local_c + 1;
  }
  else if (param_1 == 2) {
    local_8 = local_8 + 1;
  }
  else if (param_1 == 3) {
    local_c = local_c + -1;
  }
  XMap__IsBlocked_UFO(local_c,local_8);
  return;
}

// ============================================================================
// Address: 0x41db00 | Symbol: XEnemy_Sesame::XEnemy_Sesame
// ============================================================================
undefined4 * XEnemy_Sesame__XEnemy_Sesame(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471aa7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0x14a);
  local_8 = 0;
  *in_ECX = XEnemy_Sesame::vftable;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  JObject3DX__AppendExtraFrame(0x14b);
  JObject3DX__AppendExtraFrame(0xd2);
  JObject3DX__AppendExtraFrame(0xd4);
  JObject3DX__SetCurrentFrame(2);
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x42540000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x41100000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x21] = 1;
  uVar1 = Random(4);
  XEnemyBase__SetDirection(uVar1);
  in_ECX[0x23] = 2;
  iVar2 = Random(0xf);
  in_ECX[0x24] = iVar2 + 0xf;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41dc80 | Symbol: XEnemy_Sesame::~XEnemy_Sesame
// ============================================================================
void XEnemy_Sesame___XEnemy_Sesame(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XEnemy_Sesame::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41dca0 | Symbol: XEnemy_Sesame::SubProcessMove
// ============================================================================
void XEnemy_Sesame__SubProcessMove(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined1 local_40 [12];
  double local_34;
  double local_2c;
  float local_24;
  uint local_20;
  int local_1c;
  int local_18;
  float local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0x8c) < 2) {
    local_18 = 0;
  }
  else {
    local_18 = 2;
  }
  local_10 = local_18;
  local_8 = in_ECX;
  if (*(int *)(in_ECX + 0x94) == 0) {
    local_c = 0x46;
    if (*(uint *)(in_ECX + 100) < 0x23) {
      JObject3DX__SetCurrentFrame(local_18);
    }
    else {
      JObject3DX__SetCurrentFrame(local_18 + 1);
    }
  }
  else {
    local_c = 0x19;
    JObject3DX__SetCurrentFrame(local_18 + 1);
  }
  local_14 = 0.0;
  if (*(uint *)(local_8 + 100) < local_c) {
    local_1c = *(int *)(local_8 + 100);
    local_2c = (double)local_1c + (double)(&DAT_00473840)[-(local_1c >> 0x1f)];
    local_20 = local_c;
    local_34 = (double)(int)local_c + (double)(&DAT_00473840)[-((int)local_c >> 0x1f)];
    local_24 = (float)local_2c / (float)local_34;
    pfVar1 = (float *)XMap__GetChipSize();
    local_14 = local_24 * *pfVar1;
  }
  else {
    pfVar1 = (float *)XMap__GetChipSize();
    local_14 = *pfVar1;
  }
  uVar2 = GetVectorFromDir(local_4c,*(undefined4 *)(local_8 + 0x7c),local_14);
  FUN_00413780(local_40,uVar2);
  uVar2 = FUN_00404050(local_58,local_8 + 0x70,local_40);
  JObject3DBase__SetWorldPos(uVar2);
  if (local_c <= *(uint *)(local_8 + 100)) {
    *(int *)(local_8 + 0x90) = *(int *)(local_8 + 0x90) + -1;
    *(undefined4 *)(local_8 + 0x60) = 1;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41de50 | Symbol: XEnemy_Sesame::SubProcessWait
// ============================================================================
void XEnemy_Sesame__SubProcessWait(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x94) == 0) {
    if (*(int *)(in_ECX + 0x90) < 1) {
      *(undefined4 *)(in_ECX + 0x94) = 1;
    }
    else {
      XEnemyBase__DefaultProcessWait();
    }
  }
  else if (*(int *)(in_ECX + 0x94) == 1) {
    if (*(int *)(in_ECX + 0x8c) < 2) {
      local_c = 0;
    }
    else {
      local_c = 2;
    }
    JObject3DX__SetCurrentFrame(local_c);
    if (0xf9 < *(uint *)(in_ECX + 100)) {
      *(undefined4 *)(in_ECX + 0x90) = 10;
      *(undefined4 *)(in_ECX + 0x94) = 2;
    }
  }
  else {
    if (*(int *)(in_ECX + 0x90) < 1) {
      iVar1 = Random(0xf);
      *(int *)(in_ECX + 0x90) = iVar1 + 0xf;
      *(undefined4 *)(in_ECX + 0x94) = 0;
    }
    XEnemyBase__DefaultProcessWait();
  }
  return;
}

// ============================================================================
// Address: 0x41df30 | Symbol: XNeedleBall::XNeedleBall
// ============================================================================
undefined4 * XNeedleBall__XNeedleBall(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471ad1;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0xa5);
  local_8 = 0;
  *in_ECX = XNeedleBall::vftable;
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x41f00000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x21] = 0;
  XEnemyBase__SetDirection(param_2);
  in_ECX[0x22] = 0;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41e050 | Symbol: XNeedleBall::~XNeedleBall
// ============================================================================
void XNeedleBall___XNeedleBall(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XNeedleBall::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41e070 | Symbol: XNeedleBall::SubProcessMoveRotate
// ============================================================================
void XNeedleBall__SubProcessMoveRotate(int param_1)

{
  int *in_ECX;
  float fVar1;
  
  fVar1 = (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.03141593;
  if (in_ECX[0x1f] == 0) {
    (**(code **)(*in_ECX + 0xc))(0,fVar1);
  }
  else if (in_ECX[0x1f] == 2) {
    (**(code **)(*in_ECX + 0xc))(0,-fVar1);
  }
  else if (in_ECX[0x1f] == 1) {
    (**(code **)(*in_ECX + 0xc))(2,-fVar1);
  }
  else if (in_ECX[0x1f] == 3) {
    (**(code **)(*in_ECX + 0xc))
              (2,fVar1,(double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)],0x3d00adfd);
  }
  return;
}

// ============================================================================
// Address: 0x41e160 | Symbol: XNeedleBall::SubProcessMove
// ============================================================================
void XNeedleBall__SubProcessMove(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  undefined1 local_28 [12];
  double local_1c;
  float local_14;
  int local_10;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  local_8 = in_ECX;
  if (*(uint *)(in_ECX + 100) < 0x32) {
    local_10 = *(int *)(in_ECX + 100);
    local_1c = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
    local_14 = (float)local_1c / 50.0;
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = local_14 * *pfVar1;
  }
  else {
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = *pfVar1;
  }
  uVar2 = GetVectorFromDir(local_34,*(undefined4 *)(local_8 + 0x7c),local_c);
  FUN_00413780(local_28,uVar2);
  uVar2 = FUN_00404050(local_40,local_8 + 0x70,local_28);
  JObject3DBase__SetWorldPos(uVar2);
  if (0x31 < *(uint *)(local_8 + 100)) {
    *(undefined4 *)(local_8 + 0x60) = 1;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41e250 | Symbol: XNeedleBall::SubProcessWait
// ============================================================================
void XNeedleBall__SubProcessWait(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471afb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JBaseList__JBaseList(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  uVar1 = *(undefined4 *)(in_ECX + 0x7c);
  uVar2 = *(int *)(in_ECX + 0x7c) + 1U & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  uVar5 = *(int *)(in_ECX + 0x7c) + 2U & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  uVar4 = *(int *)(in_ECX + 0x7c) + 3U & 0x80000003;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
  }
  iVar3 = XEnemyBase__IsBlocked(uVar1);
  if (iVar3 == 0) {
    XEnemyBase__StartMoving(uVar1);
  }
  else {
    iVar3 = XEnemyBase__IsBlocked(uVar2);
    if (iVar3 == 0) {
      XEnemyBase__StartMoving(uVar2);
    }
    else {
      iVar3 = XEnemyBase__IsBlocked(uVar4);
      if (iVar3 == 0) {
        XEnemyBase__StartMoving(uVar4);
      }
      else {
        iVar3 = XEnemyBase__IsBlocked(uVar5);
        if (iVar3 == 0) {
          XEnemyBase__StartMoving(uVar5);
        }
      }
    }
  }
  local_8 = 0xffffffff;
  JBaseList___JBaseList();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41e370 | Symbol: XNeedleBallFast::XNeedleBallFast
// ============================================================================
undefined4 * XNeedleBallFast__XNeedleBallFast(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471b25;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0xb3);
  local_8 = 0;
  *in_ECX = XNeedleBallFast::vftable;
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x41f00000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x21] = 0;
  XEnemyBase__SetDirection(param_2);
  in_ECX[0x22] = 0;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41e490 | Symbol: XNeedleBallFast::~XNeedleBallFast
// ============================================================================
void XNeedleBallFast___XNeedleBallFast(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XNeedleBallFast::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41e4b0 | Symbol: XNeedleBallFast::SubProcessMoveRotate
// ============================================================================
void XNeedleBallFast__SubProcessMoveRotate(int param_1)

{
  int *in_ECX;
  float fVar1;
  
  fVar1 = (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.044879895;
  if (in_ECX[0x1f] == 0) {
    (**(code **)(*in_ECX + 0xc))(0,fVar1);
  }
  else if (in_ECX[0x1f] == 2) {
    (**(code **)(*in_ECX + 0xc))(0,-fVar1);
  }
  else if (in_ECX[0x1f] == 1) {
    (**(code **)(*in_ECX + 0xc))(2,-fVar1);
  }
  else if (in_ECX[0x1f] == 3) {
    (**(code **)(*in_ECX + 0xc))
              (2,fVar1,(double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)],0x3d37d3fb);
  }
  return;
}

// ============================================================================
// Address: 0x41e5a0 | Symbol: XNeedleBallFast::SubProcessMove
// ============================================================================
void XNeedleBallFast__SubProcessMove(void)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  undefined1 local_28 [12];
  double local_1c;
  float local_14;
  int local_10;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  local_8 = in_ECX;
  if (*(uint *)(in_ECX + 100) < 0x23) {
    local_10 = *(int *)(in_ECX + 100);
    local_1c = (double)local_10 + (double)(&DAT_00473840)[-(local_10 >> 0x1f)];
    local_14 = (float)local_1c / 35.0;
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = local_14 * *pfVar1;
  }
  else {
    pfVar1 = (float *)XMap__GetChipSize();
    local_c = *pfVar1;
  }
  uVar2 = GetVectorFromDir(local_34,*(undefined4 *)(local_8 + 0x7c),local_c);
  FUN_00413780(local_28,uVar2);
  uVar2 = FUN_00404050(local_40,local_8 + 0x70,local_28);
  JObject3DBase__SetWorldPos(uVar2);
  if (0x22 < *(uint *)(local_8 + 100)) {
    *(undefined4 *)(local_8 + 0x60) = 1;
    *(undefined4 *)(local_8 + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41e690 | Symbol: XNeedleBallFast::SubProcessWait
// ============================================================================
void XNeedleBallFast__SubProcessWait(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471b4f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JBaseList__JBaseList(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  uVar1 = *(undefined4 *)(in_ECX + 0x7c);
  uVar2 = *(int *)(in_ECX + 0x7c) + 1U & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  uVar5 = *(int *)(in_ECX + 0x7c) + 2U & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  uVar4 = *(int *)(in_ECX + 0x7c) + 3U & 0x80000003;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
  }
  iVar3 = XEnemyBase__IsBlocked(uVar1);
  if (iVar3 == 0) {
    XEnemyBase__StartMoving(uVar1);
  }
  else {
    iVar3 = XEnemyBase__IsBlocked(uVar2);
    if (iVar3 == 0) {
      XEnemyBase__StartMoving(uVar2);
    }
    else {
      iVar3 = XEnemyBase__IsBlocked(uVar4);
      if (iVar3 == 0) {
        XEnemyBase__StartMoving(uVar4);
      }
      else {
        iVar3 = XEnemyBase__IsBlocked(uVar5);
        if (iVar3 == 0) {
          XEnemyBase__StartMoving(uVar5);
        }
      }
    }
  }
  local_8 = 0xffffffff;
  JBaseList___JBaseList();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x41e7b0 | Symbol: XNeedleBox::XNeedleBox
// ============================================================================
undefined4 * XNeedleBox__XNeedleBox(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471b79;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0xb2);
  local_8 = 0;
  *in_ECX = XNeedleBox::vftable;
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x420c0000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x42700000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x22] = 0;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41e8b0 | Symbol: XNeedleBox::~XNeedleBox
// ============================================================================
void XNeedleBox___XNeedleBox(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XNeedleBox::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41e8d0 | Symbol: XNeedleBox::SubProcessMove
// ============================================================================
void XNeedleBox__SubProcessMove(void)

{
  undefined4 uVar1;
  int in_ECX;
  uint uVar2;
  float10 fVar3;
  undefined4 uVar4;
  undefined1 local_4c [12];
  undefined1 local_40 [12];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  float local_18;
  int local_14;
  float local_10;
  int local_c;
  byte local_5;
  
  local_20 = 200;
  local_24 = 0xf0;
  local_28 = 0x186;
  local_2c = 0x21c;
  local_10 = 0.0;
  local_c = in_ECX;
  if (199 < *(uint *)(in_ECX + 100)) {
    if (*(uint *)(in_ECX + 100) < 0xf0) {
      local_14 = *(int *)(in_ECX + 100) + -200;
      local_30 = 0x28;
      fVar3 = (float10)cosf(((float)local_14 / 40.0) * 1.5707964);
      local_18 = (float)fVar3;
      local_10 = 60.0 - local_18 * 60.0;
    }
    else if (*(uint *)(in_ECX + 100) < 0x186) {
      if (*(int *)(in_ECX + 100) == 0xf0) {
        local_5 = XGameObject__GetVolumeOfPosition
                            (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                             *(undefined4 *)(in_ECX + 0x10));
        uVar4 = 0;
        uVar2 = (uint)local_5;
        uVar1 = 0xf5;
        XApplication__GetSoundList(0xf5,uVar2,0);
        JSoundList__Play(uVar1,uVar2,uVar4);
      }
      local_10 = 60.0;
    }
    else if (*(uint *)(in_ECX + 100) < 0x21c) {
      local_1c = *(int *)(in_ECX + 100) + -0x186;
      local_34 = 0x96;
      local_10 = 60.0 - (float)local_1c * 0.4;
    }
  }
  _D3DVECTOR___D3DVECTOR(0,-local_10,0);
  uVar1 = FUN_00404050(local_4c,local_c + 0x70,local_40);
  JObject3DBase__SetWorldPos(uVar1);
  if (0x21b < *(uint *)(local_c + 100)) {
    *(undefined4 *)(local_c + 0x60) = 1;
    *(undefined4 *)(local_c + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41eaa0 | Symbol: XNeedleBox::SubProcessWait
// ============================================================================
void XNeedleBox__SubProcessWait(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x60) = 2;
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

// ============================================================================
// Address: 0x41eae0 | Symbol: XNeedleBoxDrop::XNeedleBoxDrop
// ============================================================================
undefined4 * XNeedleBoxDrop__XNeedleBoxDrop(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471ba3;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0xb1);
  local_8 = 0;
  *in_ECX = XNeedleBoxDrop::vftable;
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0x42200000,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x420c0000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x42700000);
  JObject3DBase__SetCollisionRadius(0x41700000);
  in_ECX[0x22] = 0;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41ebe0 | Symbol: XNeedleBoxDrop::~XNeedleBoxDrop
// ============================================================================
void XNeedleBoxDrop___XNeedleBoxDrop(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XNeedleBoxDrop::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41ec00 | Symbol: XNeedleBoxDrop::SubProcessMove
// ============================================================================
void XNeedleBoxDrop__SubProcessMove(void)

{
  undefined4 uVar1;
  int in_ECX;
  uint uVar2;
  float10 fVar3;
  undefined4 uVar4;
  undefined1 local_3c [12];
  undefined1 local_30 [12];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  int local_14;
  float local_10;
  int local_c;
  byte local_5;
  
  local_1c = 0x50;
  local_20 = 0x78;
  local_10 = 0.0;
  local_c = in_ECX;
  if (0x4f < *(uint *)(in_ECX + 100)) {
    if (*(uint *)(in_ECX + 100) < 0x78) {
      local_14 = *(int *)(in_ECX + 100) + -0x50;
      local_24 = 0x28;
      fVar3 = (float10)cosf(((float)local_14 / 40.0) * 1.5707964);
      local_18 = (float)fVar3;
      local_10 = 60.0 - local_18 * 60.0;
    }
    else {
      if (*(int *)(in_ECX + 100) == 0x78) {
        local_5 = XGameObject__GetVolumeOfPosition
                            (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                             *(undefined4 *)(in_ECX + 0x10));
        uVar4 = 0;
        uVar2 = (uint)local_5;
        uVar1 = 0xf5;
        XApplication__GetSoundList(0xf5,uVar2,0);
        JSoundList__Play(uVar1,uVar2,uVar4);
      }
      local_10 = 60.0;
    }
  }
  _D3DVECTOR___D3DVECTOR(0,-local_10,0);
  uVar1 = FUN_00404050(local_3c,local_c + 0x70,local_30);
  JObject3DBase__SetWorldPos(uVar1);
  return;
}

// ============================================================================
// Address: 0x41ed40 | Symbol: XNeedleBoxDrop::SubProcessWait
// ============================================================================
void XNeedleBoxDrop__SubProcessWait(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = XPac__GetMapPosX();
  iVar2 = XPac__GetMapPosZ();
  if ((iVar1 == *(int *)(in_ECX + 0x68)) && (iVar2 == *(int *)(in_ECX + 0x6c))) {
    *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x60) = 2;
    *(undefined4 *)(in_ECX + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x41edc0 | Symbol: XGate::XGate
// ============================================================================
undefined4 * XGate__XGate(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00471bcd;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XEnemyBase__XEnemyBase(param_1,0xb4);
  local_8 = 0;
  *in_ECX = XGate::vftable;
  (**(code **)(*(int *)in_ECX[0x20] + 8))(0,uVar1);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x420c0000);
  JObject3DBase__ShiftWorldPos_OnGround();
  JObject3DBase__SetCollisionRadius(0x41200000);
  in_ECX[0x21] = 1;
  XEnemyBase__SetDirection(param_2);
  in_ECX[0x23] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x41eec0 | Symbol: XGate::~XGate
// ============================================================================
void XGate___XGate(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XGate::vftable;
  XEnemyBase___XEnemyBase();
  return;
}

// ============================================================================
// Address: 0x41eee0 | Symbol: XEnemyBase::
// ============================================================================
undefined4 XEnemyBase__(uint param_1)

{
  undefined4 in_ECX;
  
  XEnemyBase___XEnemyBase();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x90);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x41ef20 | Symbol: XEnemyList::
// ============================================================================
undefined4 XEnemyList__(uint param_1)

{
  undefined4 in_ECX;
  
  XEnemyList___XEnemyList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x80);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x41ef60 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemy_Cube::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemy_Cube__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemy_Cube___XEnemy_Cube();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}

// ============================================================================
// Address: 0x41efa0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemy_Ghost::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemy_Ghost__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemy_Ghost___XEnemy_Ghost();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}

// ============================================================================
// Address: 0x41efe0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemy_Kurage::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemy_Kurage__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemy_Kurage___XEnemy_Kurage();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}

// ============================================================================
// Address: 0x41f020 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemy_Sesame::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemy_Sesame__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemy_Sesame___XEnemy_Sesame();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x98);
  }
  return this;
}

// ============================================================================
// Address: 0x41f060 | Symbol: Concurrency::details::ThreadVirtualProcessor::XEnemy_UFO::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XEnemy_UFO__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XEnemy_UFO___XEnemy_UFO();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x98);
  }
  return this;
}

// ============================================================================
// Address: 0x41f0a0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XGate::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XGate__(ThreadVirtualProcessor *this,uint param_1)

{
  XGate___XGate();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}

// ============================================================================
// Address: 0x41f0e0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XNeedleBall::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XNeedleBall__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XNeedleBall___XNeedleBall();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}

// ============================================================================
// Address: 0x41f120 | Symbol: Concurrency::details::ThreadVirtualProcessor::XNeedleBallFast::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XNeedleBallFast__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XNeedleBallFast___XNeedleBallFast();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}

// ============================================================================
// Address: 0x41f160 | Symbol: Concurrency::details::ThreadVirtualProcessor::XNeedleBox::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XNeedleBox__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XNeedleBox___XNeedleBox();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}

// ============================================================================
// Address: 0x41f1a0 | Symbol: Concurrency::details::ThreadVirtualProcessor::XNeedleBoxDrop::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XNeedleBoxDrop__
          (ThreadVirtualProcessor *this,uint param_1)

{
  XNeedleBoxDrop___XNeedleBoxDrop();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x90);
  }
  return this;
}
