// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JSprite.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JSprite.h"

// ============================================================================
// Address: 0x412f40 | Symbol: JSprite::JSprite
// ============================================================================
undefined4 * JSprite__JSprite(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = JSprite::vftable;
  in_ECX[1] = param_1;
  *(undefined2 *)(in_ECX + 2) = param_2;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0xffffffff;
  in_ECX[6] = 0xffffffff;
  in_ECX[7] = 0xffffffff;
  in_ECX[8] = 0xffffffff;
  in_ECX[9] = 0;
  in_ECX[10] = param_3;
  uVar1 = JSurfaceList__GetByResId(*(undefined2 *)(in_ECX + 2));
  uVar1 = JSurface__GetWidth(uVar1);
  in_ECX[5] = uVar1;
  iVar2 = JSurface__GetHeight();
  in_ECX[6] = iVar2 / (int)in_ECX[10];
  return in_ECX;
}

// ============================================================================
// Address: 0x413000 | Symbol: JSprite::~JSprite
// ============================================================================
void JSprite___JSprite(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JSprite::vftable;
  return;
}

// ============================================================================
// Address: 0x413020 | Symbol: JSprite::GetPosX
// ============================================================================
float10 JSprite__GetPosX(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0xc);
}

// ============================================================================
// Address: 0x413040 | Symbol: JSprite::GetPosY
// ============================================================================
float10 JSprite__GetPosY(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x10);
}

// ============================================================================
// Address: 0x413060 | Symbol: JSprite::GetPosIntX
// ============================================================================
void JSprite__GetPosIntX(void)

{
  float10 fVar1;
  
  fVar1 = (float10)JSprite__GetPosX();
  Round((float)fVar1);
  return;
}

// ============================================================================
// Address: 0x413080 | Symbol: JSprite::GetPosIntY
// ============================================================================
void JSprite__GetPosIntY(void)

{
  float10 fVar1;
  
  fVar1 = (float10)JSprite__GetPosY();
  Round((float)fVar1);
  return;
}

// ============================================================================
// Address: 0x4130a0 | Symbol: JSprite::GetCenterIntX
// ============================================================================
int JSprite__GetCenterIntX(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = JSprite__GetPosIntX();
  return *(int *)(in_ECX + 0x14) / 2 + iVar1;
}

// ============================================================================
// Address: 0x4130d0 | Symbol: JSprite::GetCenterIntY
// ============================================================================
int JSprite__GetCenterIntY(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = JSprite__GetPosIntY();
  return *(int *)(in_ECX + 0x18) / 2 + iVar1;
}

// ============================================================================
// Address: 0x413100 | Symbol: JSprite::GetWidth
// ============================================================================
undefined4 JSprite__GetWidth(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}

// ============================================================================
// Address: 0x413120 | Symbol: JSprite::GetHeight
// ============================================================================
undefined4 JSprite__GetHeight(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}

// ============================================================================
// Address: 0x413140 | Symbol: JSprite::GetCurrentFrame
// ============================================================================
undefined4 JSprite__GetCurrentFrame(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}

// ============================================================================
// Address: 0x413160 | Symbol: JSprite::GetNumFrames
// ============================================================================
undefined4 JSprite__GetNumFrames(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}

// ============================================================================
// Address: 0x413180 | Symbol: JSprite::SetPosition
// ============================================================================
void JSprite__SetPosition(int param_1,int param_2)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0xc) = (float)param_1;
  *(float *)(in_ECX + 0x10) = (float)param_2;
  return;
}

// ============================================================================
// Address: 0x4131b0 | Symbol: JSprite::SetPosX
// ============================================================================
void JSprite__SetPosX(int param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0xc) = (float)param_1;
  return;
}

// ============================================================================
// Address: 0x4131d0 | Symbol: JSprite::SetPosY
// ============================================================================
void JSprite__SetPosY(int param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x10) = (float)param_1;
  return;
}

// ============================================================================
// Address: 0x4131f0 | Symbol: JSprite::ShiftPosX
// ============================================================================
void JSprite__ShiftPosX(float param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0xc) = *(float *)(in_ECX + 0xc) + param_1;
  return;
}

// ============================================================================
// Address: 0x413220 | Symbol: JSprite::ShiftPosY
// ============================================================================
void JSprite__ShiftPosY(float param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x10) = *(float *)(in_ECX + 0x10) + param_1;
  return;
}

// ============================================================================
// Address: 0x413250 | Symbol: JSprite::SetCenterPos
// ============================================================================
void JSprite__SetCenterPos(int param_1,int param_2)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0xc) = (float)(param_1 - *(int *)(in_ECX + 0x14) / 2);
  *(float *)(in_ECX + 0x10) = (float)(param_2 - *(int *)(in_ECX + 0x18) / 2);
  return;
}

// ============================================================================
// Address: 0x4132a0 | Symbol: JSprite::SetCurrentFrame
// ============================================================================
void JSprite__SetCurrentFrame(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}

// ============================================================================
// Address: 0x4132c0 | Symbol: JSprite::IncrCurrentFrame
// ============================================================================
void JSprite__IncrCurrentFrame(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x24) = (*(int *)(in_ECX + 0x24) + 1) % *(int *)(in_ECX + 0x28);
  return;
}

// ============================================================================
// Address: 0x4132f0 | Symbol: CDockingPanesRow::JSprite::SetDrawSize
// ============================================================================
/* Library Function - Single Match
    public: void __thiscall CDockingPanesRow::SetExtra(int,enum AFX_ROW_ALIGNMENT)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CDockingPanesRow::JSprite__SetDrawSize(CDockingPanesRow *this,int param_1,AFX_ROW_ALIGNMENT param_2)

{
  *(int *)(this + 0x1c) = param_1;
  *(AFX_ROW_ALIGNMENT *)(this + 0x20) = param_2;
  return;
}

// ============================================================================
// Address: 0x413310 | Symbol: JSprite::Draw
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void JSprite__Draw(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  if (param_1 != (int *)0x0) {
    JSurfaceList__GetByResId(*(undefined2 *)(in_ECX + 8));
    uVar1 = JSurface__GetDDSurface();
    iVar2 = JSprite__GetPosIntX();
    local_24 = JSprite__GetPosIntY();
    if (*(int *)(in_ECX + 0x1c) < 0) {
      local_30 = *(int *)(in_ECX + 0x14);
    }
    else {
      local_30 = *(int *)(in_ECX + 0x1c);
    }
    if (*(int *)(in_ECX + 0x20) < 0) {
      local_34 = *(int *)(in_ECX + 0x18);
    }
    else {
      local_34 = *(int *)(in_ECX + 0x20);
    }
    local_18 = 0;
    local_14 = *(int *)(in_ECX + 0x24) * *(int *)(in_ECX + 0x18);
    local_10 = *(undefined4 *)(in_ECX + 0x14);
    local_c = *(int *)(in_ECX + 0x24) * *(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x18);
    local_20 = iVar2 + local_30;
    local_1c = local_24 + local_34;
    local_28 = iVar2;
    iVar2 = JSurface__UseColorKey();
    if (iVar2 == 0) {
      (**(code **)(*param_1 + 0x14))(param_1,&local_28,uVar1,&local_18,0x1000000,0);
    }
    else {
      (**(code **)(*param_1 + 0x14))(param_1,&local_28,uVar1,&local_18,0x1008000,0);
    }
  }
  return;
}

// ============================================================================
// Address: 0x413460 | Symbol: JSprite::DrawScale
// ============================================================================
void JSprite__DrawScale(undefined4 param_1,undefined4 param_2)

{
  JSprite__DrawScaleXY(param_1,param_2,param_2);
  return;
}

// ============================================================================
// Address: 0x413490 | Symbol: JSprite::DrawScaleX
// ============================================================================
void JSprite__DrawScaleX(undefined4 param_1,undefined4 param_2)

{
  JSprite__DrawScaleXY(param_1,param_2,0x3f800000);
  return;
}

// ============================================================================
// Address: 0x4134d0 | Symbol: JSprite::DrawScaleY
// ============================================================================
void JSprite__DrawScaleY(undefined4 param_1,undefined4 param_2)

{
  JSprite__DrawScaleXY(param_1,0x3f800000,param_2);
  return;
}

// ============================================================================
// Address: 0x413510 | Symbol: JSprite::DrawScaleXY
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void JSprite__DrawScaleXY(int *param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  if (param_1 != (int *)0x0) {
    uVar1 = JSurfaceList__GetByResId(*(undefined2 *)(in_ECX + 8));
    uVar2 = JSurface__GetDDSurface();
    iVar3 = Round((float)*(int *)(in_ECX + 0x14) * param_2,uVar2,uVar1);
    iVar4 = JSprite__GetCenterIntX();
    iVar4 = iVar4 - iVar3 / 2;
    iVar5 = Round((float)*(int *)(in_ECX + 0x18) * param_3);
    local_24 = JSprite__GetCenterIntY(uVar2,uVar1,iVar5);
    local_24 = local_24 - iVar5 / 2;
    local_20 = iVar4 + iVar3;
    local_1c = local_24 + iVar5;
    local_18 = 0;
    local_14 = *(int *)(in_ECX + 0x24) * *(int *)(in_ECX + 0x18);
    local_10 = *(undefined4 *)(in_ECX + 0x14);
    local_c = *(int *)(in_ECX + 0x24) * *(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x18);
    local_28 = iVar4;
    iVar3 = JSurface__UseColorKey();
    if (iVar3 == 0) {
      (**(code **)(*param_1 + 0x14))(param_1,&local_28,uVar2,&local_18,0x1000000,0);
    }
    else {
      (**(code **)(*param_1 + 0x14))(param_1,&local_28,uVar2,&local_18,0x1008000,0);
    }
  }
  return;
}

// ============================================================================
// Address: 0x413670 | Symbol: JSprite::
// ============================================================================
undefined4 JSprite__(uint param_1)

{
  undefined4 in_ECX;
  
  JSprite___JSprite();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x2c);
  }
  return in_ECX;
}
