// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XMapObject.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XMapObject.h"

// ============================================================================
// Address: 0x425620 | Symbol: XMapObjectList::XMapObjectList
// ============================================================================
undefined4 * XMapObjectList__XMapObjectList(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_8;
  
  *in_ECX = XMapObjectList::vftable;
  in_ECX[1] = param_1;
  for (local_8 = 0; local_8 < 0x19; local_8 = local_8 + 1) {
    in_ECX[local_8 + 2] = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x425670 | Symbol: XMapObjectList::~XMapObjectList
// ============================================================================
void XMapObjectList___XMapObjectList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00472060;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XMapObjectList::vftable;
  XMapObjectList__Empty(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x4256c0 | Symbol: XMapObjectList::CreateMapObject
// ============================================================================
undefined4 XMapObjectList__CreateMapObject(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
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
  puStack_c = &LAB_00472118;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 'Z') {
    uVar1 = 0;
  }
  else {
    iVar2 = XMapObjectList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
    if (iVar2 < 0) {
      uVar1 = 0;
    }
    else {
      if (param_1 == 'A') {
        iVar3 = FUN_0042d23e(0x70);
        local_8 = 0;
        if (iVar3 == 0) {
          local_20 = 0;
        }
        else {
          local_20 = XCannonUp__XCannonUp(*(undefined4 *)(in_ECX + 4));
        }
        *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_20;
      }
      else if (param_1 == 'N') {
        iVar3 = FUN_0042d23e(0x70);
        local_8 = 1;
        if (iVar3 == 0) {
          local_28 = 0;
        }
        else {
          local_28 = XCannon__XCannon(*(undefined4 *)(in_ECX + 4),0);
        }
        *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_28;
      }
      else if (param_1 == 'S') {
        iVar3 = FUN_0042d23e(0x70);
        local_8 = 2;
        if (iVar3 == 0) {
          local_30 = 0;
        }
        else {
          local_30 = XCannon__XCannon(*(undefined4 *)(in_ECX + 4),2);
        }
        *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_30;
      }
      else if (param_1 == 'E') {
        iVar3 = FUN_0042d23e(0x70);
        local_8 = 3;
        if (iVar3 == 0) {
          local_38 = 0;
        }
        else {
          local_38 = XCannon__XCannon(*(undefined4 *)(in_ECX + 4),1);
        }
        *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_38;
      }
      else if (param_1 == 'W') {
        iVar3 = FUN_0042d23e(0x70);
        local_8 = 4;
        if (iVar3 == 0) {
          local_40 = 0;
        }
        else {
          local_40 = XCannon__XCannon(*(undefined4 *)(in_ECX + 4),3);
        }
        *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_40;
      }
      else if (param_1 == 'V') {
        iVar3 = FUN_0042d23e(0x70);
        local_8 = 5;
        if (iVar3 == 0) {
          local_48 = 0;
        }
        else {
          local_48 = XVolcano__XVolcano(*(undefined4 *)(in_ECX + 4));
        }
        *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_48;
      }
      else if (param_1 == '!') {
        iVar3 = FUN_0042d23e(0x70);
        local_8 = 6;
        if (iVar3 == 0) {
          local_50 = 0;
        }
        else {
          local_50 = XSteam__XSteam(*(undefined4 *)(in_ECX + 4));
        }
        *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_50;
      }
      else if (param_1 == 'P') {
        iVar3 = XApplication__GetCurrentWorld();
        if (iVar3 == 0) {
          iVar3 = FUN_0042d23e(0x70);
          local_8 = 7;
          if (iVar3 == 0) {
            local_58 = 0;
          }
          else {
            local_58 = XPole__XPole(*(undefined4 *)(in_ECX + 4));
          }
          *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_58;
        }
        else {
          iVar3 = XApplication__GetCurrentWorld();
          if (iVar3 == 1) {
            iVar3 = FUN_0042d23e(0x70);
            local_8 = 8;
            if (iVar3 == 0) {
              local_60 = 0;
            }
            else {
              local_60 = XTree__XTree(*(undefined4 *)(in_ECX + 4));
            }
            *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_60;
          }
          else {
            iVar3 = FUN_0042d23e(0x70);
            local_8 = 9;
            if (iVar3 == 0) {
              local_68 = 0;
            }
            else {
              local_68 = XShortPole__XShortPole(*(undefined4 *)(in_ECX + 4));
            }
            *(undefined4 *)(in_ECX + 8 + iVar2 * 4) = local_68;
          }
        }
      }
      uVar1 = *(undefined4 *)(in_ECX + 8 + iVar2 * 4);
    }
  }
  ExceptionList = local_10;
  return uVar1;
}

// ============================================================================
// Address: 0x425b00 | Symbol: XMapObjectList::Empty
// ============================================================================
void XMapObjectList__Empty(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x19; local_8 = local_8 + 1) {
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
// Address: 0x425b70 | Symbol: XMapObjectList::ProcessRotate
// ============================================================================
void XMapObjectList__ProcessRotate(undefined4 param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x19; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x20))(param_1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x425bd0 | Symbol: XMapObjectList::ProcessFrame
// ============================================================================
void XMapObjectList__ProcessFrame(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x19; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x24))();
      iVar2 = XMapObjectBase__GetState();
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
// Address: 0x425c70 | Symbol: XMapObjectList::Render
// ============================================================================
void XMapObjectList__Render(void)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x19; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x14))();
    }
  }
  return;
}

// ============================================================================
// Address: 0x425cc0 | Symbol: XMapObjectList::GetNullIndex
// ============================================================================
int XMapObjectList__GetNullIndex(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x18 < local_8) {
      return -1;
    }
    if (*(int *)(in_ECX + 8 + local_8 * 4) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x425d00 | Symbol: XMapObjectBase::XMapObjectBase
// ============================================================================
undefined4 * XMapObjectBase__XMapObjectBase(int param_1,undefined2 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00472157;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  JObject3DX__JObject3DX(*(undefined4 *)(param_1 + 4),param_2);
  local_8 = 0;
  *in_ECX = XMapObjectBase::vftable;
  in_ECX[0x17] = param_1;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0xffffffff;
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
  in_ECX[0x1b] = local_1c;
  (**(code **)(*(int *)in_ECX[0x1b] + 0x20))(0xa3,0,0,0x3f800000,0x3f800000);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  in_ECX[0x18] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x425e60 | Symbol: XMapObjectBase::~XMapObjectBase
// ============================================================================
void XMapObjectBase___XMapObjectBase(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XMapObjectBase::vftable;
  if (in_ECX[0x1b] != 0) {
    if ((undefined4 *)in_ECX[0x1b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x1b])(1);
    }
    in_ECX[0x1b] = 0;
  }
  JObject3DX___JObject3DX();
  return;
}

// ============================================================================
// Address: 0x425ec0 | Symbol: XMapObjectBase::Render
// ============================================================================
void XMapObjectBase__Render(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) != 0) {
    JObject3DX__Render();
    uVar1 = _D3DVECTOR___D3DVECTOR
                      (*(undefined4 *)(in_ECX + 8),0x3f800000,*(undefined4 *)(in_ECX + 0x10));
    JObject3DBase__SetWorldPos(uVar1);
    (**(code **)(**(int **)(in_ECX + 0x6c) + 0x14))();
  }
  return;
}

// ============================================================================
// Address: 0x425f30 | Symbol: XMapObjectBase::GetState
// ============================================================================
undefined4 XMapObjectBase__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x60);
}

// ============================================================================
// Address: 0x425f50 | Symbol: XMapObjectBase::SetDirection
// ============================================================================
void XMapObjectBase__SetDirection(int param_1,int param_2)

{
  int in_ECX;
  
  if (param_2 != 0) {
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
  *(int *)(in_ECX + 0x68) = param_1;
  return;
}

// ============================================================================
// Address: 0x425ff0 | Symbol: XMapObjectBase::ProcessRotate
// ============================================================================
void XMapObjectBase__ProcessRotate(void)

{
  return;
}

// ============================================================================
// Address: 0x426000 | Symbol: XMapObjectBase::ProcessFrame
// ============================================================================
void XMapObjectBase__ProcessFrame(void)

{
  return;
}

// ============================================================================
// Address: 0x426010 | Symbol: XVolcano::XVolcano
// ============================================================================
undefined4 * XVolcano__XVolcano(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00472181;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XMapObjectBase__XMapObjectBase(param_1,0xb0);
  local_8 = 0;
  *in_ECX = XVolcano::vftable;
  (**(code **)(*(int *)in_ECX[0x1b] + 8))(0,uVar1);
  JObject3DX__ScaleBy(0x43070000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40000000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4260d0 | Symbol: XVolcano::~XVolcano
// ============================================================================
void XVolcano___XVolcano(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XVolcano::vftable;
  XMapObjectBase___XMapObjectBase();
  return;
}

// ============================================================================
// Address: 0x4260f0 | Symbol: XVolcano::ProcessFrame
// ============================================================================
uint XVolcano__ProcessFrame(void)

{
  uint uVar1;
  uint in_ECX;
  
  *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 1;
  uVar1 = in_ECX;
  if ((*(int *)(in_ECX + 0x60) == 1) && (0x5db < *(uint *)(in_ECX + 100))) {
    if (*(uint *)(in_ECX + 100) < 0x9c4) {
      uVar1 = *(uint *)(in_ECX + 100) / 0x32;
      if (*(uint *)(in_ECX + 100) % 0x32 == 0) {
        uVar1 = XEnemyFireList__CreateVolcanoFire
                          (*(undefined4 *)(in_ECX + 8),*(float *)(in_ECX + 0xc) + 20.0,
                           *(undefined4 *)(in_ECX + 0x10));
      }
    }
    else {
      *(undefined4 *)(in_ECX + 100) = 0;
    }
  }
  return uVar1;
}

// ============================================================================
// Address: 0x4261a0 | Symbol: XCannonUp::XCannonUp
// ============================================================================
undefined4 * XCannonUp__XCannonUp(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004721ab;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XMapObjectBase__XMapObjectBase(param_1,0xa6);
  local_8 = 0;
  *in_ECX = XCannonUp::vftable;
  (**(code **)(*(int *)in_ECX[0x1b] + 8))(0x42700000,uVar1);
  JObject3DX__ScaleBy(0x42a00000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x426260 | Symbol: XCannonUp::~XCannonUp
// ============================================================================
void XCannonUp___XCannonUp(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XCannonUp::vftable;
  XMapObjectBase___XMapObjectBase();
  return;
}

// ============================================================================
// Address: 0x426280 | Symbol: XCannonUp::ProcessFrame
// ============================================================================
uint XCannonUp__ProcessFrame(void)

{
  uint uVar1;
  uint in_ECX;
  
  *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 1;
  uVar1 = in_ECX;
  if ((*(int *)(in_ECX + 0x60) == 1) &&
     (uVar1 = *(uint *)(in_ECX + 100) / 200, *(uint *)(in_ECX + 100) % 200 == 0)) {
    uVar1 = XEnemyFireList__CreateCannonUpFire
                      (*(undefined4 *)(in_ECX + 8),*(float *)(in_ECX + 0xc) + 10.0,
                       *(undefined4 *)(in_ECX + 0x10));
  }
  return uVar1;
}

// ============================================================================
// Address: 0x426310 | Symbol: XCannon::XCannon
// ============================================================================
undefined4 * XCannon__XCannon(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004721d5;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XMapObjectBase__XMapObjectBase(param_1,0xac);
  local_8 = 0;
  *in_ECX = XCannon::vftable;
  (**(code **)(*(int *)in_ECX[0x1b] + 8))(0x425c0000,uVar1);
  JObject3DX__ScaleBy(0x42a00000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  XMapObjectBase__SetDirection(param_2,1);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4263e0 | Symbol: XCannon::~XCannon
// ============================================================================
void XCannon___XCannon(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XCannon::vftable;
  XMapObjectBase___XMapObjectBase();
  return;
}

// ============================================================================
// Address: 0x426400 | Symbol: XCannon::ProcessFrame
// ============================================================================
uint XCannon__ProcessFrame(void)

{
  uint uVar1;
  uint in_ECX;
  
  *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 1;
  uVar1 = in_ECX;
  if ((*(int *)(in_ECX + 0x60) == 1) &&
     (uVar1 = *(uint *)(in_ECX + 100) / 0x1c2, *(uint *)(in_ECX + 100) % 0x1c2 == 0)) {
    uVar1 = XEnemyFireList__CreateCannonFire
                      (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                       *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x68));
  }
  return uVar1;
}

// ============================================================================
// Address: 0x426480 | Symbol: XPole::XPole
// ============================================================================
undefined4 * XPole__XPole(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004721ff;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XMapObjectBase__XMapObjectBase(param_1,0xa7);
  local_8 = 0;
  *in_ECX = XPole::vftable;
  (**(code **)(*(int *)in_ECX[0x1b] + 8))(0x42700000,uVar1);
  JObject3DX__ScaleBy(0x42f00000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x426540 | Symbol: XPole::~XPole
// ============================================================================
void XPole___XPole(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XPole::vftable;
  XMapObjectBase___XMapObjectBase();
  return;
}

// ============================================================================
// Address: 0x426560 | Symbol: XShortPole::XShortPole
// ============================================================================
undefined4 * XShortPole__XShortPole(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00472229;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XMapObjectBase__XMapObjectBase(param_1,0x13b);
  local_8 = 0;
  *in_ECX = XShortPole::vftable;
  (**(code **)(*(int *)in_ECX[0x1b] + 8))(0x425c0000,uVar1);
  JObject3DX__ScaleBy(0x43110000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x426620 | Symbol: XShortPole::~XShortPole
// ============================================================================
void XShortPole___XShortPole(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XShortPole::vftable;
  XMapObjectBase___XMapObjectBase();
  return;
}

// ============================================================================
// Address: 0x426640 | Symbol: XTree::XTree
// ============================================================================
undefined4 * XTree__XTree(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00472253;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XMapObjectBase__XMapObjectBase(param_1,0xa8);
  local_8 = 0;
  *in_ECX = XTree::vftable;
  (**(code **)(*(int *)in_ECX[0x1b] + 8))(0x42b40000,uVar1);
  JObject3DX__ScaleBy(0x43020000);
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x426700 | Symbol: XTree::~XTree
// ============================================================================
void XTree___XTree(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XTree::vftable;
  XMapObjectBase___XMapObjectBase();
  return;
}

// ============================================================================
// Address: 0x426720 | Symbol: XSteam::XSteam
// ============================================================================
undefined4 * XSteam__XSteam(undefined4 param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047227d;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  XMapObjectBase__XMapObjectBase(param_1,0xffff);
  local_8 = 0;
  *in_ECX = XSteam::vftable;
  (**(code **)(*(int *)in_ECX[0x1b] + 8))(0,uVar1);
  FUN_0040f750(1,0);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4267c0 | Symbol: XSteam::~XSteam
// ============================================================================
void XSteam___XSteam(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XSteam::vftable;
  XMapObjectBase___XMapObjectBase();
  return;
}

// ============================================================================
// Address: 0x4267e0 | Symbol: XSteam::ProcessFrame
// ============================================================================
uint XSteam__ProcessFrame(void)

{
  byte bVar1;
  uint in_ECX;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 1;
  uVar2 = in_ECX;
  if (*(int *)(in_ECX + 0x60) == 1) {
    if (*(int *)(in_ECX + 100) == 200) {
      bVar1 = XGameObject__GetVolumeOfPosition
                        (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                         *(undefined4 *)(in_ECX + 0x10));
      uVar4 = 0;
      uVar2 = (uint)bVar1;
      uVar3 = 0x13e;
      XApplication__GetSoundList(0x13e,uVar2,0);
      uVar2 = JSoundList__Play(uVar3,uVar2,uVar4);
    }
    if ((200 < *(uint *)(in_ECX + 100)) &&
       (uVar2 = *(uint *)(in_ECX + 100) / 10, *(uint *)(in_ECX + 100) % 10 == 0)) {
      uVar2 = XEnemyFireList__CreateSteamFire
                        (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc),
                         *(undefined4 *)(in_ECX + 0x10));
    }
    if (400 < *(uint *)(in_ECX + 100)) {
      *(undefined4 *)(in_ECX + 100) = 0;
      uVar2 = in_ECX;
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x4268c0 | Symbol: XCannon::
// ============================================================================
undefined4 XCannon__(uint param_1)

{
  undefined4 in_ECX;
  
  XCannon___XCannon();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x4268f0 | Symbol: XCannonUp::
// ============================================================================
undefined4 XCannonUp__(uint param_1)

{
  undefined4 in_ECX;
  
  XCannonUp___XCannonUp();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x426920 | Symbol: XMapObjectBase::
// ============================================================================
undefined4 XMapObjectBase__(uint param_1)

{
  undefined4 in_ECX;
  
  XMapObjectBase___XMapObjectBase();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x426950 | Symbol: Concurrency::details::_CancellationTokenRegistration::XMapObjectList::
// ============================================================================
/* Library Function - Single Match
    protected: virtual void * __thiscall
   Concurrency::details::_CancellationTokenRegistration::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::_CancellationTokenRegistration::XMapObjectList__
          (_CancellationTokenRegistration *this,uint param_1)

{
  XMapObjectList___XMapObjectList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x6c);
  }
  return this;
}

// ============================================================================
// Address: 0x426980 | Symbol: XPole::
// ============================================================================
undefined4 XPole__(uint param_1)

{
  undefined4 in_ECX;
  
  XPole___XPole();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x4269b0 | Symbol: XShortPole::
// ============================================================================
undefined4 XShortPole__(uint param_1)

{
  undefined4 in_ECX;
  
  XShortPole___XShortPole();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x4269e0 | Symbol: XSteam::
// ============================================================================
undefined4 XSteam__(uint param_1)

{
  undefined4 in_ECX;
  
  XSteam___XSteam();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x426a10 | Symbol: XTree::
// ============================================================================
undefined4 XTree__(uint param_1)

{
  undefined4 in_ECX;
  
  XTree___XTree();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x426a40 | Symbol: XVolcano::
// ============================================================================
undefined4 XVolcano__(uint param_1)

{
  undefined4 in_ECX;
  
  XVolcano___XVolcano();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x70);
  }
  return in_ECX;
}
