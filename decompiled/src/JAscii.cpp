// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JAscii.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JAscii.h"

// ============================================================================
// Address: 0x40d540 | Symbol: JNumber::JNumber
// ============================================================================
undefined4 * JNumber__JNumber(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470ab4;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JNumber::vftable;
  iVar2 = FUN_0042d23e(0x2c,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JSprite__JSprite(param_1,param_2,param_3);
  }
  in_ECX[1] = local_1c;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 1;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x40d610 | Symbol: JNumber::~JNumber
// ============================================================================
void JNumber___JNumber(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JNumber::vftable;
  if (in_ECX[1] != 0) {
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[1])(1);
    }
    in_ECX[1] = 0;
  }
  return;
}

// ============================================================================
// Address: 0x40d670 | Symbol: JNumber::SetPosition
// ============================================================================
void JNumber__SetPosition(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_2;
  return;
}

// ============================================================================
// Address: 0x40d690 | Symbol: JNumber::SetDisplayZero
// ============================================================================
void JNumber__SetDisplayZero(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}

// ============================================================================
// Address: 0x40d6b0 | Symbol: JNumber::SetNumDigits
// ============================================================================
void JNumber__SetNumDigits(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}

// ============================================================================
// Address: 0x40d6d0 | Symbol: JNumber::SetNumber
// ============================================================================
void JNumber__SetNumber(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  return;
}

// ============================================================================
// Address: 0x40d6f0 | Symbol: JNumber::Draw
// ============================================================================
void JNumber__Draw(undefined4 param_1)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int local_18;
  int local_10;
  int local_c;
  
  FID_conflict___ltoa(*(long *)(in_ECX + 0x18),&DAT_0048e210,10);
  sVar1 = _strlen(&DAT_0048e210);
  local_c = *(int *)(in_ECX + 8);
  if ((0 < *(int *)(in_ECX + 0x14)) && ((int)sVar1 < *(int *)(in_ECX + 0x14))) {
    iVar3 = *(int *)(in_ECX + 0x14);
    for (local_18 = 0; local_18 < (int)(iVar3 - sVar1); local_18 = local_18 + 1) {
      JSprite__SetCurrentFrame(0);
      JSprite__SetPosition(local_c,*(undefined4 *)(in_ECX + 0xc));
      if (*(int *)(in_ECX + 0x10) != 0) {
        JSprite__Draw(param_1);
      }
      iVar2 = JNumber__GetDigitWidth();
      local_c = iVar2 + local_c;
    }
  }
  for (local_10 = 0; local_10 < (int)sVar1; local_10 = local_10 + 1) {
    if ((int)(sVar1 - local_10) <= *(int *)(in_ECX + 0x14)) {
      JSprite__SetCurrentFrame((char)(&DAT_0048e210)[local_10] + -0x30);
      JSprite__SetPosition(local_c,*(undefined4 *)(in_ECX + 0xc));
      JSprite__Draw(param_1);
      iVar3 = JNumber__GetDigitWidth();
      local_c = iVar3 + local_c;
    }
  }
  return;
}

// ============================================================================
// Address: 0x40d830 | Symbol: JNumber::GetPosX
// ============================================================================
undefined4 JNumber__GetPosX(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}

// ============================================================================
// Address: 0x40d850 | Symbol: JNumber::GetPosY
// ============================================================================
undefined4 JNumber__GetPosY(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}

// ============================================================================
// Address: 0x40d870 | Symbol: JNumber::GetDigitWidth
// ============================================================================
int JNumber__GetDigitWidth(void)

{
  int iVar1;
  
  iVar1 = JSprite__GetWidth();
  return iVar1 / 3;
}

// ============================================================================
// Address: 0x40d890 | Symbol: JNumber::GetWidth
// ============================================================================
int JNumber__GetWidth(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = JNumber__GetDigitWidth();
  return iVar1 * *(int *)(in_ECX + 0x14);
}

// ============================================================================
// Address: 0x40d8b0 | Symbol: JNumber::GetHeight
// ============================================================================
void JNumber__GetHeight(void)

{
  JSprite__GetHeight();
  return;
}

// ============================================================================
// Address: 0x40d8d0 | Symbol: JNumber::
// ============================================================================
undefined4 JNumber__(uint param_1)

{
  undefined4 in_ECX;
  
  JNumber___JNumber();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x1c);
  }
  return in_ECX;
}
