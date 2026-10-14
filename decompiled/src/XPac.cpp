// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: XPac.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "XPac.h"

// ============================================================================
// Address: 0x426a70 | Symbol: GetVectorFromDir
// ============================================================================
undefined4 GetVectorFromDir(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    _D3DVECTOR___D3DVECTOR(0,0,0x3f800000);
  }
  else if (param_2 == 1) {
    _D3DVECTOR___D3DVECTOR(0x3f800000,0,0);
  }
  else if (param_2 == 2) {
    _D3DVECTOR___D3DVECTOR(0,0,0xbf800000);
  }
  else if (param_2 == 3) {
    _D3DVECTOR___D3DVECTOR(0xbf800000,0,0);
  }
  else {
    _D3DVECTOR___D3DVECTOR(0,0,0);
  }
  return param_1;
}

// ============================================================================
// Address: 0x426b70 | Symbol: XPacFireList::XPacFireList
// ============================================================================
undefined4 * XPacFireList__XPacFireList(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_8;
  
  *in_ECX = XPacFireList::vftable;
  in_ECX[1] = param_1;
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    in_ECX[local_8 + 2] = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x426bc0 | Symbol: XPacFireList::~XPacFireList
// ============================================================================
void XPacFireList___XPacFireList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_004722a0;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = XPacFireList::vftable;
  XPacFireList__Empty(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x426c10 | Symbol: XPacFireList::CreateFire
// ============================================================================
void XPacFireList__CreateFire(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_48 [12];
  undefined1 local_3c [12];
  undefined1 local_30 [12];
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004722d4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = XPacFireList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
  if (-1 < local_18) {
    uVar3 = 0;
    uVar2 = 100;
    uVar1 = 0xee;
    XApplication__GetSoundList(0xee,100,0);
    JSoundList__Play(uVar1,uVar2,uVar3);
    local_1c = FUN_0042d23e(0x98);
    local_8 = 0;
    if (local_1c == 0) {
      local_20 = 0;
    }
    else {
      uVar1 = XPac__GetFaceDirection();
      local_20 = XPacFire__XPacFire(*(undefined4 *)(local_14 + 4),uVar1);
    }
    local_24 = local_20;
    local_8 = 0xffffffff;
    *(undefined4 *)(local_14 + 8 + local_18 * 4) = local_20;
    uVar1 = JObject3DBase__GetWorldPos(local_48);
    JObject3DBase__SetWorldPos(uVar1);
    uVar1 = XPac__GetFaceDirection();
    GetVectorFromDir(local_30,uVar1);
    FUN_00413780(local_3c,local_30,0x41a00000);
    JObject3DBase__ShiftWorldPos(local_3c);
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x426d50 | Symbol: XPacFireList::Empty
// ============================================================================
void XPacFireList__Empty(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
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
// Address: 0x426dc0 | Symbol: XPacFireList::CheckCollisionWithEnemy
// ============================================================================
void XPacFireList__CheckCollisionWithEnemy(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_20 [12];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = in_ECX;
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    if ((*(int *)(local_c + 8 + local_8 * 4) != 0) && (iVar1 = XPacFire__GetState(), iVar1 != 0)) {
      for (local_14 = 0; local_14 < 0x1e; local_14 = local_14 + 1) {
        local_10 = XEnemyList__GetAt(local_14);
        if ((((local_10 != 0) && (iVar1 = XEnemyBase__GetState(), iVar1 != 0)) &&
            (iVar1 = XEnemyBase__GetState(), iVar1 != 4)) &&
           (iVar1 = JObject3DBase__CheckCollisionRadius(*(undefined4 *)(local_c + 8 + local_8 * 4)),
           iVar1 != 0)) {
          iVar1 = XEnemyBase__Breakable();
          if (iVar1 != 0) {
            uVar2 = XPacFire__GetDirection();
            XEnemyBase__DecreaseShield(uVar2);
            puVar3 = (undefined4 *)JObject3DBase__GetWorldPos(local_20);
            XParticleList__CreatePacFireHit(*puVar3,puVar3[1],puVar3[2]);
          }
          XPacFire__SetState(0);
        }
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x426ef0 | Symbol: XPacFireList::ProcessFrame
// ============================================================================
void XPacFireList__ProcessFrame(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      XPacFire__ProcessFrame();
      iVar2 = XPacFire__GetState();
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
// Address: 0x426f90 | Symbol: XPacFireList::Render
// ============================================================================
void XPacFireList__Render(undefined4 param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 8 + local_8 * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 8 + local_8 * 4) + 0x24))(param_1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x426ff0 | Symbol: XPacFireList::GetNullIndex
// ============================================================================
int XPacFireList__GetNullIndex(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (2 < local_8) {
      return -1;
    }
    if (*(int *)(in_ECX + 8 + local_8 * 4) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x427030 | Symbol: XPacFire::XPacFire
// ============================================================================
undefined4 * XPacFire__XPacFire(int param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004722fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  JObject3D_Particle__JObject3D_Particle(*(undefined4 *)(param_1 + 4),0x41c00000,0x41c00000);
  local_8 = 0;
  *in_ECX = XPacFire::vftable;
  in_ECX[0x22] = param_1;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = param_2;
  JObject3DBase__SetCollisionRadius(0x41000000);
  in_ECX[0x23] = 1;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x427110 | Symbol: XPacFire::~XPacFire
// ============================================================================
void XPacFire___XPacFire(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XPacFire::vftable;
  JObject3D_Particle___JObject3D_Particle();
  return;
}

// ============================================================================
// Address: 0x427130 | Symbol: XPacFire::Render2
// ============================================================================
void XPacFire__Render2(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  int local_c;
  
  if (in_ECX[0x23] != 0) {
    JObject3D_Rect___SetWorldTransform2(param_1);
    (**(code **)(*in_ECX + 0x18))();
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      if (local_c == 0) {
        (**(code **)(*in_ECX + 0x20))(0xa1,0,0,0x3f800000,0x3f800000);
      }
      else {
        XPacFire___SetTextureRandomly();
      }
      if ((short)in_ECX[0xe] != 0) {
        piVar1 = (int *)CD3DApplication__GetD3DDevice();
        uVar2 = D3DTextr_GetSurface((short)in_ECX[0xe]);
        (**(code **)(*piVar1 + 0x8c))(piVar1,0,uVar2);
      }
      piVar1 = (int *)CD3DApplication__GetD3DDevice();
      (**(code **)(*piVar1 + 0x68))(piVar1,4,0x1e2,in_ECX[0xb],in_ECX[10],in_ECX[0xd],in_ECX[0xc],0)
      ;
    }
    piVar1 = (int *)CD3DApplication__GetD3DDevice();
    (**(code **)(*piVar1 + 0x8c))(piVar1,0,0);
    (**(code **)(*in_ECX + 0x1c))();
    JObject3DBase___ResetWorldTransform();
  }
  return;
}

// ============================================================================
// Address: 0x4272a0 | Symbol: XPacFire::GetState
// ============================================================================
undefined4 XPacFire__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x8c);
}

// ============================================================================
// Address: 0x4272c0 | Symbol: XPacFire::SetState
// ============================================================================
void XPacFire__SetState(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x8c) = param_1;
  return;
}

// ============================================================================
// Address: 0x4272e0 | Symbol: XPacFire::GetDirection
// ============================================================================
undefined4 XPacFire__GetDirection(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x94);
}

// ============================================================================
// Address: 0x427300 | Symbol: XPacFire::ProcessFrame
// ============================================================================
void XPacFire__ProcessFrame(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_2c [12];
  undefined1 local_20 [12];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x90) + 1;
  if (*(int *)(in_ECX + 0x8c) == 1) {
    local_14 = 0x40200000;
    local_8 = in_ECX;
    uVar1 = GetVectorFromDir(local_2c,*(undefined4 *)(in_ECX + 0x94),0x40200000);
    FUN_00413780(local_20,uVar1);
    JObject3DBase__ShiftWorldPos(local_20);
    local_10 = XMap__ConvertPosXToMapX(*(undefined4 *)(local_8 + 8));
    local_c = XMap__ConvertPosZToMapZ(*(undefined4 *)(local_8 + 0x10));
    iVar2 = XMap__IsBlocked_Fire(local_10,local_c);
    if (iVar2 != 0) {
      *(undefined4 *)(local_8 + 0x8c) = 0;
      *(undefined4 *)(local_8 + 0x90) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x427400 | Symbol: XPacFire::_SetTextureRandomly
// ============================================================================
void XPacFire___SetTextureRandomly(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = Random(9,0x3eaaaaab);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0,0,0x3eaaaaab,0x3eaaaaab);
  }
  else if (iVar1 == 1) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3eaaaaab,0,0x3f2aaaab,0x3eaaaaab);
  }
  else if (iVar1 == 2) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3f2aaaab,0,0x3f800000,0x3eaaaaab);
  }
  else if (iVar1 == 3) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0,0x3eaaaaab,0x3eaaaaab,0x3f2aaaab);
  }
  else if (iVar1 == 4) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3eaaaaab,0x3eaaaaab,0x3f2aaaab,0x3f2aaaab);
  }
  else if (iVar1 == 5) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3f2aaaab,0x3eaaaaab,0x3f800000,0x3f2aaaab);
  }
  else if (iVar1 == 6) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0,0x3f2aaaab,0x3eaaaaab,0x3f800000);
  }
  else if (iVar1 == 7) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3eaaaaab,0x3f2aaaab,0x3f2aaaab,0x3f800000);
  }
  else if (iVar1 == 8) {
    (**(code **)(*in_ECX + 0x20))(0xa0,0x3f2aaaab,0x3f2aaaab,0x3f800000,0x3f800000);
  }
  return;
}

// ============================================================================
// Address: 0x427700 | Symbol: XPac::XPac
// ============================================================================
undefined4 * XPac__XPac(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0047233a;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  JObject3DX__JObject3DX(*(undefined4 *)(param_1 + 4),0x94);
  local_8 = 0;
  *in_ECX = XPac::vftable;
  in_ECX[0x17] = param_1;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0xffffffff;
  in_ECX[0x1b] = 0xffffffff;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  _D3DVECTOR___D3DVECTOR(0,0,0);
  iVar2 = FUN_0042d23e(0x88,uVar1);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JObject3D_Shadow__JObject3D_Shadow
                         (*(undefined4 *)(param_1 + 4),0x42200000,0x42200000);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x21] = local_1c;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  JObject3DX__AppendExtraFrame(0x95);
  JObject3DX__AppendExtraFrame(0x96);
  JObject3DX__AppendExtraFrame(199);
  JObject3DX__RotateBy(0,0xbfc90fdb);
  JObject3DX__ScaleBy(0x42340000);
  JObject3DBase__SetCollisionRadius(0x41500000);
  (**(code **)(*(int *)in_ECX[0x21] + 0x20))(0xa3,0,0,0x3f800000,0x3f800000);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x427910 | Symbol: XPac::~XPac
// ============================================================================
void XPac___XPac(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = XPac::vftable;
  if (in_ECX[0x21] != 0) {
    if ((undefined4 *)in_ECX[0x21] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x21])(1);
    }
    in_ECX[0x21] = 0;
  }
  JObject3DX___JObject3DX();
  return;
}

// ============================================================================
// Address: 0x427980 | Symbol: XPac::Render
// ============================================================================
void XPac__Render(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) != 0) {
    JObject3DX__Render();
    uVar1 = _D3DVECTOR___D3DVECTOR
                      (*(undefined4 *)(in_ECX + 8),0x3f800000,*(undefined4 *)(in_ECX + 0x10));
    JObject3DBase__SetWorldPos(uVar1);
    (**(code **)(**(int **)(in_ECX + 0x84) + 0x14))();
  }
  return;
}

// ============================================================================
// Address: 0x427a00 | Symbol: XPac::Reset
// ============================================================================
void XPac__Reset(void)

{
  int in_ECX;
  
  JObject3DBase__ShiftWorldPos_OnGround();
  FUN_0040f7e0(1,0x40400000);
  JObject3DBase__RotateTo(1,0);
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  JObject3DX__SetCurrentFrame(0);
  *(undefined4 *)(in_ECX + 0x60) = 1;
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}

// ============================================================================
// Address: 0x427a70 | Symbol: XPac::GetState
// ============================================================================
undefined4 XPac__GetState(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x60);
}

// ============================================================================
// Address: 0x427a90 | Symbol: XPac::GetFaceDirection
// ============================================================================
undefined4 XPac__GetFaceDirection(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x70);
}

// ============================================================================
// Address: 0x427ab0 | Symbol: XPac::SetMapPos
// ============================================================================
void XPac__SetMapPos(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x68) = param_1;
  *(undefined4 *)(in_ECX + 0x6c) = param_2;
  return;
}

// ============================================================================
// Address: 0x427ad0 | Symbol: XPac::GetMapPosX
// ============================================================================
undefined4 XPac__GetMapPosX(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x68);
}

// ============================================================================
// Address: 0x427af0 | Symbol: XPac::GetMapPosZ
// ============================================================================
undefined4 XPac__GetMapPosZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x6c);
}

// ============================================================================
// Address: 0x427b10 | Symbol: XPac::GetFireEnergy
// ============================================================================
undefined4 XPac__GetFireEnergy(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x8c);
}

// ============================================================================
// Address: 0x427b30 | Symbol: XPac::ResetFireEnergy
// ============================================================================
void XPac__ResetFireEnergy(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  return;
}

// ============================================================================
// Address: 0x427b50 | Symbol: XPac::SetFaceDirection
// ============================================================================
void XPac__SetFaceDirection(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x70) = param_1;
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
  return;
}

// ============================================================================
// Address: 0x427be0 | Symbol: XPac::StartMoving
// ============================================================================
void XPac__StartMoving(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_10;
  int local_c;
  
  if ((-1 < param_1) && (*(int *)(in_ECX + 0x60) == 1)) {
    XPac__SetFaceDirection(param_1);
    *(int *)(in_ECX + 0x74) = param_1;
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
    iVar1 = XMap__IsBlocked_Pac(local_c,local_10);
    if (iVar1 == 0) {
      uVar4 = 0;
      uVar3 = 100;
      uVar2 = 0xff;
      XApplication__GetSoundList(0xff,100,0);
      JSoundList__Play(uVar2,uVar3,uVar4);
      *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 8);
      *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 0xc);
      *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x10);
      *(int *)(in_ECX + 0x68) = local_c;
      *(int *)(in_ECX + 0x6c) = local_10;
      iVar1 = XCrystalList__GetTakenCount();
      *(int *)(in_ECX + 0x88) = iVar1 * 3 + 0x28;
      *(undefined4 *)(in_ECX + 0x60) = 2;
      *(undefined4 *)(in_ECX + 100) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x427d10 | Symbol: XPac::StartArrow
// ============================================================================
void XPac__StartArrow(int param_1)

{
  int iVar1;
  int in_ECX;
  int local_10;
  int local_c;
  
  if ((-1 < param_1) && (*(int *)(in_ECX + 0x60) == 1)) {
    *(int *)(in_ECX + 0x74) = param_1;
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
    iVar1 = XMap__IsBlocked_Pac(local_c,local_10);
    if (iVar1 == 0) {
      JObject3DX__SetCurrentFrame(3);
      *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 8);
      *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 0xc);
      *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x10);
      *(int *)(in_ECX + 0x68) = local_c;
      *(int *)(in_ECX + 0x6c) = local_10;
      *(undefined4 *)(in_ECX + 0x60) = 3;
      *(undefined4 *)(in_ECX + 100) = 0;
    }
  }
  return;
}

// ============================================================================
// Address: 0x427e00 | Symbol: XPac::StartDying
// ============================================================================
void XPac__StartDying(void)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*(int *)(in_ECX + 0x60) != 0) && (*(int *)(in_ECX + 0x60) != 5)) {
    XApplication__GetMidiList();
    JMidiList__Stop();
    uVar3 = 0;
    uVar2 = 100;
    uVar1 = 0xef;
    XApplication__GetSoundList(0xef,100,0);
    JSoundList__Play(uVar1,uVar2,uVar3);
    XCamera__StartGameOver();
    XCrystalList__StartGameOver();
    JObject3DX__SetCurrentFrame(3);
    *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(in_ECX + 8);
    *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 0xc);
    *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x60) = 5;
    *(undefined4 *)(in_ECX + 100) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x427eb0 | Symbol: XPac::ProcessRotate
// ============================================================================
void XPac__ProcessRotate(int param_1)

{
  int *in_ECX;
  float fVar1;
  
  if (in_ECX[0x18] == 4) {
    (**(code **)(*in_ECX + 0xc))
              (1,(float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.06981317
              );
  }
  else if (in_ECX[0x18] == 5) {
    fVar1 = (float)((double)param_1 + (double)(&DAT_00473840)[-(param_1 >> 0x1f)]) * 0.13962634;
    if (in_ECX[0x1c] == 0) {
      (**(code **)(*in_ECX + 0xc))(0,-fVar1);
    }
    else if (in_ECX[0x1c] == 2) {
      (**(code **)(*in_ECX + 0xc))(0,fVar1);
    }
    else if (in_ECX[0x1c] == 1) {
      (**(code **)(*in_ECX + 0xc))(2,fVar1);
    }
    else if (in_ECX[0x1c] == 3) {
      (**(code **)(*in_ECX + 0xc))(2,-fVar1);
    }
  }
  return;
}

// ============================================================================
// Address: 0x428010 | Symbol: XPac::ProcessFrame
// ============================================================================
uint XPac__ProcessFrame(void)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  uint in_ECX;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_d4 [12];
  undefined1 local_c8 [12];
  undefined1 local_bc [12];
  undefined1 local_b0 [12];
  undefined1 local_a4 [12];
  undefined1 local_98 [12];
  undefined1 local_8c [12];
  undefined1 local_80 [4];
  float local_7c;
  double local_74;
  double local_6c;
  double local_64;
  double local_5c;
  double local_54;
  double local_4c;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 1;
  local_8 = in_ECX;
  if ((*(int *)(in_ECX + 0x8c) < 1000) &&
     (*(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + 3, 1000 < *(int *)(in_ECX + 0x8c))) {
    uVar7 = 0;
    uVar6 = 100;
    uVar5 = 0xfe;
    XApplication__GetSoundList(0xfe,100,0);
    JSoundList__Play(uVar5,uVar6,uVar7);
    *(undefined4 *)(local_8 + 0x8c) = 1000;
  }
  if (*(int *)(local_8 + 0x60) == 2) {
    local_c = 0.0;
    local_10 = 0.0;
    if (*(uint *)(local_8 + 100) < *(uint *)(local_8 + 0x88)) {
      local_18 = *(int *)(local_8 + 100);
      local_4c = (double)local_18 + (double)(&DAT_00473840)[-(local_18 >> 0x1f)];
      local_1c = *(int *)(local_8 + 0x88);
      local_54 = (double)local_1c + (double)(&DAT_00473840)[-(local_1c >> 0x1f)];
      local_34 = (float)local_4c / (float)local_54;
      pfVar1 = (float *)XMap__GetChipSize();
      local_c = local_34 * *pfVar1;
      local_20 = *(int *)(local_8 + 100);
      local_5c = (double)local_20 + (double)(&DAT_00473840)[-(local_20 >> 0x1f)];
      local_24 = *(int *)(local_8 + 0x88);
      local_64 = (double)local_24 + (double)(&DAT_00473840)[-(local_24 >> 0x1f)];
      fVar4 = (float10)sinf(((float)local_5c / (float)local_64) * 3.1415927);
      local_38 = (float)fVar4;
      local_10 = local_38 * 15.0;
      local_28 = *(uint *)(local_8 + 0x88) / 5;
      if (*(uint *)(local_8 + 100) < local_28 << 1) {
        JObject3DX__SetCurrentFrame(1);
      }
      else if (*(uint *)(local_8 + 100) < local_28 * 3) {
        JObject3DX__SetCurrentFrame(0);
      }
      else {
        JObject3DX__SetCurrentFrame(2);
      }
    }
    else {
      pfVar1 = (float *)XMap__GetChipSize();
      local_c = *pfVar1;
      local_10 = 0.0;
      JObject3DX__SetCurrentFrame(0);
    }
    GetVectorFromDir(local_8c,*(undefined4 *)(local_8 + 0x74));
    FUN_00413780(local_80,local_8c,local_c);
    local_7c = local_10;
    uVar5 = FUN_00404050(local_bc,local_8 + 0x78,local_80);
    JObject3DBase__SetWorldPos(uVar5);
    uVar3 = *(uint *)(local_8 + 100);
    if (*(uint *)(local_8 + 0x88) <= uVar3) {
      *(undefined4 *)(local_8 + 0x60) = 1;
      *(undefined4 *)(local_8 + 100) = 0;
    }
  }
  else if (*(int *)(local_8 + 0x60) == 3) {
    local_14 = 0.0;
    if (*(uint *)(local_8 + 100) < 0x14) {
      local_2c = *(int *)(local_8 + 100);
      local_6c = (double)local_2c + (double)(&DAT_00473840)[-(local_2c >> 0x1f)];
      local_3c = (float)local_6c / 20.0;
      pfVar1 = (float *)XMap__GetChipSize();
      local_14 = local_3c * *pfVar1;
    }
    else {
      pfVar1 = (float *)XMap__GetChipSize();
      local_14 = *pfVar1;
    }
    GetVectorFromDir(local_98,*(undefined4 *)(local_8 + 0x74));
    FUN_00413780(local_a4,local_98,local_14);
    uVar5 = FUN_00404050(local_c8,local_8 + 0x78,local_a4);
    uVar3 = JObject3DBase__SetWorldPos(uVar5);
    if (0x13 < *(uint *)(local_8 + 100)) {
      JObject3DX__SetCurrentFrame(0);
      *(undefined4 *)(local_8 + 0x60) = 1;
      *(undefined4 *)(local_8 + 100) = 0;
      uVar3 = local_8;
    }
  }
  else if (*(int *)(local_8 + 0x60) == 4) {
    FUN_0040f7e0(1,0x3f333333);
    uVar3 = local_8;
    if (500.0 < *(float *)(local_8 + 0xc)) {
      XParticleList__CreatePacVanish
                (*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0xc),
                 *(undefined4 *)(local_8 + 0x10));
      uVar3 = XProcessObject__StartProcess(1);
      *(undefined4 *)(local_8 + 0x60) = 0;
    }
  }
  else {
    uVar3 = local_8;
    if (*(int *)(local_8 + 0x60) == 5) {
      local_30 = *(int *)(local_8 + 100);
      local_74 = (double)local_30 + (double)(&DAT_00473840)[-(local_30 >> 0x1f)];
      fVar4 = (float10)sinf(((float)local_74 / 200.0) * 3.1415927);
      local_40 = (float)fVar4;
      local_44 = local_40 * 140.0;
      _D3DVECTOR___D3DVECTOR(0,local_44,0);
      uVar5 = FUN_00404050(local_d4,local_8 + 0x78,local_b0);
      uVar3 = JObject3DBase__SetWorldPos(uVar5);
      if (*(float *)(local_8 + 0xc) - *(float *)(local_8 + 0x14) < 0.0) {
        XParticleList__CreateEnemyExplode
                  (*(undefined4 *)(local_8 + 8),*(undefined4 *)(local_8 + 0xc),
                   *(undefined4 *)(local_8 + 0x10));
        uVar3 = XProcessObject__StartProcess(2);
        *(undefined4 *)(local_8 + 0x60) = 0;
      }
    }
  }
  if (*(int *)(local_8 + 0x60) == 1) {
    iVar2 = XMap__IsWarpZone(*(undefined4 *)(local_8 + 0x68),*(undefined4 *)(local_8 + 0x6c));
    if (iVar2 == 0) {
      iVar2 = XMap__IsArrow(*(undefined4 *)(local_8 + 0x68),*(undefined4 *)(local_8 + 0x6c));
      uVar3 = 0;
      if (iVar2 != 0) {
        uVar5 = XMap__GetArrowDirection
                          (*(undefined4 *)(local_8 + 0x68),*(undefined4 *)(local_8 + 0x6c));
        uVar3 = XPac__StartArrow(uVar5);
      }
    }
    else {
      uVar3 = local_8;
      if ((*(int *)(local_8 + 100) != 0) &&
         (uVar3 = *(uint *)(local_8 + 100) / 0x50, *(uint *)(local_8 + 100) % 0x50 == 0)) {
        iVar2 = XCrystalList__GetCrystalLeft();
        if (iVar2 == 0) {
          uVar7 = 0;
          uVar6 = 100;
          uVar5 = 0xf0;
          XApplication__GetSoundList(0xf0,100,0);
          JSoundList__Play(uVar5,uVar6,uVar7);
          XCamera__StartLevelCompleted();
          JObject3DX__SetCurrentFrame(3);
          *(undefined4 *)(local_8 + 0x60) = 4;
          *(undefined4 *)(local_8 + 100) = 0;
          uVar3 = local_8;
        }
        else {
          uVar3 = XCrystalList__DoVanishCrystal();
        }
      }
    }
  }
  return uVar3;
}

// ============================================================================
// Address: 0x428650 | Symbol: XPac::
// ============================================================================
undefined4 XPac__(uint param_1)

{
  undefined4 in_ECX;
  
  XPac___XPac();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x90);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x428690 | Symbol: Concurrency::details::ThreadVirtualProcessor::XPacFire::
// ============================================================================
/* Library Function - Single Match
    public: virtual void * __thiscall Concurrency::details::ThreadVirtualProcessor::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void * __thiscall
Concurrency::details::ThreadVirtualProcessor::XPacFire__(ThreadVirtualProcessor *this,uint param_1)

{
  XPacFire___XPacFire();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x98);
  }
  return this;
}

// ============================================================================
// Address: 0x4286d0 | Symbol: XPacFireList::
// ============================================================================
undefined4 XPacFireList__(uint param_1)

{
  undefined4 in_ECX;
  
  XPacFireList___XPacFireList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x14);
  }
  return in_ECX;
}
