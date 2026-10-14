// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JDinput.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JDinput.h"

// ============================================================================
// Address: 0x40d900 | Symbol: JDInput::JDInput
// ============================================================================
undefined4 * JDInput__JDInput(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_10;
  int local_c;
  
  *in_ECX = JDInput::vftable;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[0x128] = 1;
  in_ECX[0x129] = 1;
  _memset(in_ECX + 8,0,0x240);
  _memset(in_ECX + 0x98,0,0x240);
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    in_ECX[local_c + 4] = 0;
  }
  DAT_0048e238 = in_ECX[1];
  DAT_0048e23c = 0;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    *(undefined4 *)(&DAT_0048e240 + local_10 * 4) = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x40d9f0 | Symbol: JDInput::~JDInput
// ============================================================================
void JDInput___JDInput(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00470ae0;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JDInput::vftable;
  JDInput__Destroy(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40da40 | Symbol: JDInput::Create
// ============================================================================
undefined4 JDInput__Create(void)

{
  LONG LVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  LVar1 = GetWindowLongA(*(HWND *)(in_ECX + 4),-6);
  iVar2 = DirectInputCreateEx(LVar1,0x700,&DAT_00475268,in_ECX + 8,0);
  if (iVar2 < 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = JDInput___CreateKeyboard();
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      JDInput___CreateJoystick();
      uVar3 = 1;
    }
  }
  return uVar3;
}

// ============================================================================
// Address: 0x40dab0 | Symbol: JDInput::Destroy
// ============================================================================
void JDInput__Destroy(void)

{
  int in_ECX;
  undefined4 local_c;
  
  JDInput__SetAcquireJoystick(0);
  JDInput__SetAcquireKeyboard(0);
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (*(int *)(in_ECX + 0x10 + local_c * 4) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x10 + local_c * 4) + 8))
                (*(undefined4 *)(in_ECX + 0x10 + local_c * 4));
      *(undefined4 *)(in_ECX + 0x10 + local_c * 4) = 0;
    }
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 8))(*(undefined4 *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 8))(*(undefined4 *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}

// ============================================================================
// Address: 0x40db70 | Symbol: JDInput::UpdateInputState
// ============================================================================
void JDInput__UpdateInputState(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_c;
  
  puVar2 = (undefined4 *)(in_ECX + 0x20);
  puVar3 = (undefined4 *)(in_ECX + 0x260);
  for (iVar1 = 0x90; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _memset((void *)(in_ECX + 0x20),0,0x240);
  if (((*(int *)(in_ECX + 0xc) != 0) &&
      (iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x24))
                         (*(undefined4 *)(in_ECX + 0xc),0x100,in_ECX + 0x20),
      *(int *)(in_ECX + 0x4a0) != 0)) && ((iVar1 == -0x7ff8ffe2 || (iVar1 == -0x7ff8fff4)))) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(*(undefined4 *)(in_ECX + 0xc));
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x24))
              (*(undefined4 *)(in_ECX + 0xc),0x100,in_ECX + 0x20);
  }
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    if (*(int *)(in_ECX + 0x10 + local_c * 4) != 0) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x10 + local_c * 4) + 100))
                        (*(undefined4 *)(in_ECX + 0x10 + local_c * 4));
      if (iVar1 < 0) {
        if (*(int *)(in_ECX + 0x4a4) != 0) {
          (**(code **)(**(int **)(in_ECX + 0x10 + local_c * 4) + 0x1c))
                    (*(undefined4 *)(in_ECX + 0x10 + local_c * 4));
        }
      }
      else {
        iVar1 = (**(code **)(**(int **)(in_ECX + 0x10 + local_c * 4) + 0x24))
                          (*(undefined4 *)(in_ECX + 0x10 + local_c * 4),0x50,
                           in_ECX + 0x120 + local_c * 0x50);
        if ((*(int *)(in_ECX + 0x4a4) != 0) && ((iVar1 == -0x7ff8ffe2 || (iVar1 == -0x7ff8fff4)))) {
          (**(code **)(**(int **)(in_ECX + 0x10 + local_c * 4) + 0x1c))
                    (*(undefined4 *)(in_ECX + 0x10 + local_c * 4));
          (**(code **)(**(int **)(in_ECX + 0x10 + local_c * 4) + 0x24))
                    (*(undefined4 *)(in_ECX + 0x10 + local_c * 4),0x50,
                     in_ECX + 0x120 + local_c * 0x50);
        }
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x40dd50 | Symbol: JDInput::SetAcquireKeyboard
// ============================================================================
void JDInput__SetAcquireKeyboard(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x4a0) = param_1;
  if (*(int *)(in_ECX + 0xc) != 0) {
    if (*(int *)(in_ECX + 0x4a0) == 0) {
      (**(code **)(**(int **)(in_ECX + 0xc) + 0x20))(*(undefined4 *)(in_ECX + 0xc));
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(*(undefined4 *)(in_ECX + 0xc));
    }
  }
  return;
}

// ============================================================================
// Address: 0x40ddb0 | Symbol: JDInput::GetKeyboardState
// ============================================================================
byte JDInput__GetKeyboardState(int param_1)

{
  byte bVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = *(byte *)(in_ECX + param_1 + 0x20) & 0x80;
  }
  return bVar1;
}

// ============================================================================
// Address: 0x40dde0 | Symbol: JDInput::GetKeyboardPressed
// ============================================================================
undefined4 JDInput__GetKeyboardPressed(int param_1)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    local_c = 0;
  }
  else if (((*(byte *)(in_ECX + param_1 + 0x260) & 0x80) == 0) &&
          ((*(byte *)(in_ECX + param_1 + 0x20) & 0x80) != 0)) {
    local_c = 1;
  }
  else {
    local_c = 0;
  }
  return local_c;
}

// ============================================================================
// Address: 0x40de40 | Symbol: JDInput::GetKeyboardReleased
// ============================================================================
undefined4 JDInput__GetKeyboardReleased(int param_1)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    local_c = 0;
  }
  else if (((*(byte *)(in_ECX + param_1 + 0x260) & 0x80) == 0) ||
          ((*(byte *)(in_ECX + param_1 + 0x20) & 0x80) != 0)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}

// ============================================================================
// Address: 0x40dea0 | Symbol: JDInput::GetKeyboardBuffer
// ============================================================================
void JDInput__GetKeyboardBuffer(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_38 [8];
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470b0a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xc) != 0) {
    local_24 = 0xffffffff;
    local_18 = in_ECX;
    local_1c = (**(code **)(**(int **)(in_ECX + 0xc) + 0x28))
                         (*(undefined4 *)(in_ECX + 0xc),0x10,0,&local_24,1,
                          DAT_00486cf0 ^ (uint)&stack0xfffffffc);
    if (local_1c < 0) {
      if ((*(int *)(local_18 + 0x4a0) != 0) && (local_1c == -0x7ff8ffe2)) {
        (**(code **)(**(int **)(local_18 + 0xc) + 0x1c))(*(undefined4 *)(local_18 + 0xc));
      }
    }
    else {
      local_2c = FUN_0042d2b4(-(uint)((int)((ulonglong)local_24 * 0x10 >> 0x20) != 0) |
                              (uint)((ulonglong)local_24 * 0x10));
      local_28 = local_2c;
      local_1c = (**(code **)(**(int **)(local_18 + 0xc) + 0x28))
                           (*(undefined4 *)(local_18 + 0xc),0x10,local_2c,&local_24,0);
      if (local_1c < 0) {
        if ((*(int *)(local_18 + 0x4a0) != 0) && (local_1c == -0x7ff8ffe2)) {
          (**(code **)(**(int **)(local_18 + 0xc) + 0x1c))(*(undefined4 *)(local_18 + 0xc));
        }
      }
      else {
        FUN_00413970(&PTR_004739cc);
        local_8 = 0;
        JString__operator_(local_38);
        local_8 = 0xffffffff;
        JString___JString();
        for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
          if (((*(uint *)(local_28 + 4 + local_20 * 0x10) & 0x80) != 0) &&
             (local_11 = ConvertKeyCodeToAscii(*(undefined4 *)(local_28 + local_20 * 0x10)),
             local_11 != '\0')) {
            JString__operator__(local_11);
            uVar1 = JString__Length();
            if (0xf < uVar1) break;
          }
        }
        local_30 = local_28;
        thunk_FUN_00451f46(local_28);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40e070 | Symbol: JDInput::ClearKeyboardBuffer
// ============================================================================
void JDInput__ClearKeyboardBuffer(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_20 [12];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470b34;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xc) != 0) {
    for (local_14 = 0; local_14 < 10; local_14 = local_14 + 1) {
      JString__JString(uVar1);
      local_8 = 0;
      JDInput__GetKeyboardBuffer(local_20);
      local_8 = 0xffffffff;
      JString___JString();
    }
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40e100 | Symbol: JDInput::SetAcquireJoystick
// ============================================================================
void JDInput__SetAcquireJoystick(undefined4 param_1)

{
  int in_ECX;
  undefined4 local_8;
  
  *(undefined4 *)(in_ECX + 0x4a4) = param_1;
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 0x10 + local_8 * 4) != 0) {
      if (*(int *)(in_ECX + 0x4a4) == 0) {
        (**(code **)(**(int **)(in_ECX + 0x10 + local_8 * 4) + 0x20))
                  (*(undefined4 *)(in_ECX + 0x10 + local_8 * 4));
      }
      else {
        (**(code **)(**(int **)(in_ECX + 0x10 + local_8 * 4) + 0x1c))
                  (*(undefined4 *)(in_ECX + 0x10 + local_8 * 4));
      }
    }
  }
  return;
}

// ============================================================================
// Address: 0x40e190 | Symbol: JDInput::GetJoyButtonState
// ============================================================================
byte JDInput__GetJoyButtonState(int param_1,int param_2)

{
  byte bVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10 + param_1 * 4) == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = *(byte *)(in_ECX + param_1 * 0x50 + 0x150 + param_2) & 0x80;
  }
  return bVar1;
}

// ============================================================================
// Address: 0x40e1d0 | Symbol: JDInput::GetJoyButtonPressed
// ============================================================================
undefined4 JDInput__GetJoyButtonPressed(int param_1,int param_2)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x10 + param_1 * 4) == 0) {
    local_c = 0;
  }
  else if (((*(byte *)(in_ECX + param_1 * 0x50 + 0x390 + param_2) & 0x80) == 0) &&
          ((*(byte *)(in_ECX + param_1 * 0x50 + 0x150 + param_2) & 0x80) != 0)) {
    local_c = 1;
  }
  else {
    local_c = 0;
  }
  return local_c;
}

// ============================================================================
// Address: 0x40e240 | Symbol: JDInput::GetJoyButtonReleased
// ============================================================================
undefined4 JDInput__GetJoyButtonReleased(int param_1,int param_2)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x10 + param_1 * 4) == 0) {
    local_c = 0;
  }
  else if (((*(byte *)(in_ECX + param_1 * 0x50 + 0x390 + param_2) & 0x80) == 0) ||
          ((*(byte *)(in_ECX + param_1 * 0x50 + 0x150 + param_2) & 0x80) != 0)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}

// ============================================================================
// Address: 0x40e2b0 | Symbol: JDInput::GetJoyDirState
// ============================================================================
bool JDInput__GetJoyDirState(int param_1,int param_2)

{
  bool bVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10 + param_1 * 4) == 0) {
    bVar1 = false;
  }
  else if (param_2 == 0) {
    bVar1 = *(int *)(in_ECX + 0x124 + param_1 * 0x50) < -800;
  }
  else if (param_2 == 2) {
    bVar1 = 800 < *(int *)(in_ECX + 0x124 + param_1 * 0x50);
  }
  else if (param_2 == 3) {
    bVar1 = *(int *)(in_ECX + 0x120 + param_1 * 0x50) < -800;
  }
  else if (param_2 == 1) {
    bVar1 = 800 < *(int *)(in_ECX + 0x120 + param_1 * 0x50);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

// ============================================================================
// Address: 0x40e3a0 | Symbol: JDInput::GetJoyDirPressed
// ============================================================================
undefined4 JDInput__GetJoyDirPressed(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x10 + param_1 * 4) == 0) {
    local_c = 0;
  }
  else {
    iVar1 = JDInput___GetJoyDirStatePrev(param_1,param_2);
    if ((iVar1 == 0) && (iVar1 = JDInput__GetJoyDirState(param_1,param_2), iVar1 != 0)) {
      local_c = 1;
    }
    else {
      local_c = 0;
    }
  }
  return local_c;
}

// ============================================================================
// Address: 0x40e400 | Symbol: JDInput::GetJoyDirReleased
// ============================================================================
undefined4 JDInput__GetJoyDirReleased(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0x10 + param_1 * 4) == 0) {
    local_c = 0;
  }
  else {
    iVar1 = JDInput___GetJoyDirStatePrev(param_1,param_2);
    if ((iVar1 == 0) || (iVar1 = JDInput__GetJoyDirState(param_1,param_2), iVar1 != 0)) {
      local_c = 0;
    }
    else {
      local_c = 1;
    }
  }
  return local_c;
}

// ============================================================================
// Address: 0x40e460 | Symbol: JDInput::_CreateKeyboard
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 JDInput___CreateKeyboard(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))
                    (*(undefined4 *)(in_ECX + 8),&DAT_00475118,&DAT_004751f8,in_ECX + 0xc,0);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x2c))
                      (*(undefined4 *)(in_ECX + 0xc),&DAT_00476058);
    if (iVar1 < 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x34))
                        (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 4),6);
      if (iVar1 < 0) {
        uVar2 = 0;
      }
      else {
        local_1c = 0x14;
        local_18 = 0x10;
        local_14 = 0;
        local_10 = 0;
        local_c = 0x100;
        (**(code **)(**(int **)(in_ECX + 0xc) + 0x18))(*(undefined4 *)(in_ECX + 0xc),1,&local_1c);
        if (*(int *)(in_ECX + 0x4a0) != 0) {
          (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(*(undefined4 *)(in_ECX + 0xc));
        }
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x40e570 | Symbol: JDInput::_CreateJoystick
// ============================================================================
undefined4 JDInput___CreateJoystick(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_8;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))
                    (*(undefined4 *)(in_ECX + 8),4,EnumJoysticksCallback,*(undefined4 *)(in_ECX + 8)
                     ,1);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    for (local_8 = 0; local_8 < (int)(uint)DAT_0048e23c; local_8 = local_8 + 1) {
      *(undefined4 *)(in_ECX + 0x10 + local_8 * 4) = *(undefined4 *)(&DAT_0048e240 + local_8 * 4);
      if (*(int *)(in_ECX + 0x4a4) != 0) {
        (**(code **)(**(int **)(in_ECX + 0x10 + local_8 * 4) + 0x1c))
                  (*(undefined4 *)(in_ECX + 0x10 + local_8 * 4));
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x40e610 | Symbol: JDInput::_GetJoyDirStatePrev
// ============================================================================
bool JDInput___GetJoyDirStatePrev(int param_1,int param_2)

{
  bool bVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10 + param_1 * 4) == 0) {
    bVar1 = false;
  }
  else if (param_2 == 0) {
    bVar1 = *(int *)(in_ECX + 0x364 + param_1 * 0x50) < -800;
  }
  else if (param_2 == 2) {
    bVar1 = 800 < *(int *)(in_ECX + 0x364 + param_1 * 0x50);
  }
  else if (param_2 == 3) {
    bVar1 = *(int *)(in_ECX + 0x360 + param_1 * 0x50) < -800;
  }
  else if (param_2 == 1) {
    bVar1 = 800 < *(int *)(in_ECX + 0x360 + param_1 * 0x50);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

// ============================================================================
// Address: 0x40e700 | Symbol: ConvertKeyCodeToAscii
// ============================================================================
undefined4 ConvertKeyCodeToAscii(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 2:
  case 0x4f:
    uVar1 = 0x31;
    break;
  case 3:
  case 0x50:
    uVar1 = 0x32;
    break;
  case 4:
  case 0x51:
    uVar1 = 0x33;
    break;
  case 5:
  case 0x4b:
    uVar1 = 0x34;
    break;
  case 6:
  case 0x4c:
    uVar1 = 0x35;
    break;
  case 7:
  case 0x4d:
    uVar1 = 0x36;
    break;
  case 8:
  case 0x47:
    uVar1 = 0x37;
    break;
  case 9:
  case 0x48:
    uVar1 = 0x38;
    break;
  case 10:
  case 0x49:
    uVar1 = 0x39;
    break;
  case 0xb:
  case 0x52:
    uVar1 = 0x30;
    break;
  case 0xc:
  case 0x4a:
    uVar1 = 0x2d;
    break;
  default:
    uVar1 = 0;
    break;
  case 0xe:
  case 0xcb:
    uVar1 = 8;
    break;
  case 0x10:
    uVar1 = 0x51;
    break;
  case 0x11:
    uVar1 = 0x57;
    break;
  case 0x12:
    uVar1 = 0x45;
    break;
  case 0x13:
    uVar1 = 0x52;
    break;
  case 0x14:
    uVar1 = 0x54;
    break;
  case 0x15:
    uVar1 = 0x59;
    break;
  case 0x16:
    uVar1 = 0x55;
    break;
  case 0x17:
    uVar1 = 0x49;
    break;
  case 0x18:
    uVar1 = 0x4f;
    break;
  case 0x19:
    uVar1 = 0x50;
    break;
  case 0x1c:
  case 0x9c:
    uVar1 = 10;
    break;
  case 0x1e:
    uVar1 = 0x41;
    break;
  case 0x1f:
    uVar1 = 0x53;
    break;
  case 0x20:
    uVar1 = 0x44;
    break;
  case 0x21:
    uVar1 = 0x46;
    break;
  case 0x22:
    uVar1 = 0x47;
    break;
  case 0x23:
    uVar1 = 0x48;
    break;
  case 0x24:
    uVar1 = 0x4a;
    break;
  case 0x25:
    uVar1 = 0x4b;
    break;
  case 0x26:
    uVar1 = 0x4c;
    break;
  case 0x2c:
    uVar1 = 0x5a;
    break;
  case 0x2d:
    uVar1 = 0x58;
    break;
  case 0x2e:
    uVar1 = 0x43;
    break;
  case 0x2f:
    uVar1 = 0x56;
    break;
  case 0x30:
    uVar1 = 0x42;
    break;
  case 0x31:
    uVar1 = 0x4e;
    break;
  case 0x32:
    uVar1 = 0x4d;
    break;
  case 0x34:
  case 0x53:
    uVar1 = 0x2e;
    break;
  case 0x39:
    uVar1 = 0x20;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x40e970 | Symbol: EnumJoysticksCallback
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 EnumJoysticksCallback(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_38 = (int *)0x0;
  iVar1 = (**(code **)(*param_2 + 0x24))(param_2,param_1 + 4,&DAT_00475228,&local_38,0);
  if (iVar1 < 0) {
    uVar2 = 1;
  }
  else {
    iVar1 = (**(code **)(*local_38 + 0x2c))(local_38,&DAT_00476070);
    if (iVar1 < 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = (**(code **)(*local_38 + 0x34))(local_38,DAT_0048e238,5);
      if (iVar1 < 0) {
        uVar2 = 1;
      }
      else {
        local_34 = 0x18;
        local_30 = 0x10;
        local_28 = 1;
        local_2c = 0;
        local_24 = 0xfffffc18;
        local_20 = 1000;
        iVar1 = (**(code **)(*local_38 + 0x18))(local_38,4,&local_34);
        if (iVar1 < 0) {
          uVar2 = 1;
        }
        else {
          local_2c = 4;
          iVar1 = (**(code **)(*local_38 + 0x18))(local_38,4,&local_34);
          if (iVar1 < 0) {
            uVar2 = 1;
          }
          else {
            local_1c = 0x14;
            local_18 = 0x10;
            local_10 = 1;
            local_14 = 0;
            local_c = 100;
            iVar1 = (**(code **)(*local_38 + 0x18))(local_38,5,&local_1c);
            if (iVar1 < 0) {
              uVar2 = 1;
            }
            else {
              local_14 = 4;
              iVar1 = (**(code **)(*local_38 + 0x18))(local_38,5,&local_1c);
              if (iVar1 < 0) {
                uVar2 = 1;
              }
              else {
                *(int **)(&DAT_0048e240 + (uint)DAT_0048e23c * 4) = local_38;
                DAT_0048e23c = DAT_0048e23c + 1;
                if (DAT_0048e23c < 4) {
                  uVar2 = 1;
                }
                else {
                  uVar2 = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x40eb50 | Symbol: JDInput::
// ============================================================================
undefined4 JDInput__(uint param_1)

{
  undefined4 in_ECX;
  
  JDInput___JDInput();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x4a8);
  }
  return in_ECX;
}
