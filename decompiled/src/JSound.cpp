// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JSound.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JSound.h"

// ============================================================================
// Address: 0x412140 | Symbol: JSound::JSound
// ============================================================================
undefined4 *
JSound__JSound(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470db0;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JSound::vftable;
  in_ECX[1] = param_1;
  *(undefined2 *)(in_ECX + 2) = param_3;
  in_ECX[3] = param_4;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 7) = 100;
  JBaseList__JBaseList(uVar1);
  local_8 = 0;
  JSound__CreateWaveData(param_2);
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4121f0 | Symbol: FUN_004121f0
// ============================================================================
undefined4 * FUN_004121f0(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470ddd;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JSound::vftable;
  in_ECX[1] = param_1;
  *(undefined2 *)(in_ECX + 2) = param_2;
  in_ECX[3] = param_3;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  JBaseList__JBaseList(uVar1);
  local_8 = 0;
  FUN_00412670(*(undefined2 *)(in_ECX + 2));
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x4122a0 | Symbol: JSound::~JSound
// ============================================================================
void JSound___JSound(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 *in_ECX;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00470dfa;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JSound::vftable;
  if (in_ECX[5] != 0) {
    FUN_0042d26e(in_ECX[5],1,uVar1);
    in_ECX[5] = 0;
  }
  local_18 = 0;
  while( true ) {
    uVar1 = JBaseList__Count();
    if (uVar1 <= local_18) break;
    piVar2 = (int *)JBaseList__GetData(local_18);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    local_18 = local_18 + 1;
  }
  JBaseList__Empty();
  JBaseList___JBaseList();
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x412380 | Symbol: JSound::GetResId
// ============================================================================
undefined2 JSound__GetResId(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 8);
}

// ============================================================================
// Address: 0x4123a0 | Symbol: JSound::SetVolume
// ============================================================================
void JSound__SetVolume(byte param_1)

{
  int in_ECX;
  
  if (param_1 < 0x65) {
    *(byte *)(in_ECX + 0x1c) = param_1;
  }
  else {
    *(undefined1 *)(in_ECX + 0x1c) = 100;
  }
  return;
}

// ============================================================================
// Address: 0x4123d0 | Symbol: JSound::Play
// ============================================================================
void JSound__Play(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c) != '\0') {
    piVar1 = (int *)JBaseList__GetData(*(undefined4 *)(in_ECX + 0x18));
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
      (**(code **)(*piVar1 + 0x34))(piVar1,0);
      (**(code **)(*piVar1 + 0x3c))
                (piVar1,(int)(((float)*(byte *)(in_ECX + 0x1c) / 100.0) * 10000.0) + -10000);
      iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,0,0,param_1 == 1);
      if (iVar2 == -0x7787ff6a) {
        (**(code **)(*piVar1 + 0x50))(piVar1);
        JSound__FillDSBuffer();
      }
    }
    *(uint *)(in_ECX + 0x18) = (*(int *)(in_ECX + 0x18) + 1U) % *(uint *)(in_ECX + 0xc);
  }
  return;
}

// ============================================================================
// Address: 0x4124d0 | Symbol: JSound::Stop
// ============================================================================
void JSound__Stop(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 local_c;
  
  local_c = 0;
  while( true ) {
    uVar1 = JBaseList__Count();
    if (uVar1 <= local_c) break;
    piVar2 = (int *)JBaseList__GetData(local_c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x48))(piVar2);
      (**(code **)(*piVar2 + 0x34))(piVar2,0);
    }
    local_c = local_c + 1;
  }
  return;
}

// ============================================================================
// Address: 0x412540 | Symbol: JSound::CreateWaveData
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void JSound__CreateWaveData(LPSTR param_1)

{
  HMMIO hmmio;
  LONG LVar1;
  MMRESULT MVar2;
  undefined4 uVar3;
  int in_ECX;
  _MMCKINFO local_44;
  char local_30 [20];
  _MMCKINFO local_1c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  hmmio = mmioOpenA(param_1,(LPMMIOINFO)0x0,0x10000);
  _memset(&local_1c,0,0x14);
  local_1c.fccType = 0x45564157;
  mmioDescend(hmmio,&local_1c,(MMCKINFO *)0x0,0x20);
  _memset(&local_44,0,0x14);
  local_44.ckid = 0x20746d66;
  mmioDescend(hmmio,&local_44,&local_1c,0);
  LVar1 = mmioRead(hmmio,local_30,0x12);
  mmioAscend(hmmio,&local_44,0);
  local_44.ckid = 0x61746164;
  MVar2 = mmioDescend(hmmio,&local_44,&local_1c,0x10);
  *(DWORD *)(in_ECX + 0x10) = local_44.cksize;
  uVar3 = FUN_0042d2b4(local_44.cksize,LVar1);
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  LVar1 = mmioRead(hmmio,*(HPSTR *)(in_ECX + 0x14),*(LONG *)(in_ECX + 0x10));
  JSound__CreateDSBuffer(LVar1,uVar3,MVar2);
  JSound__FillDSBuffer();
  return;
}

// ============================================================================
// Address: 0x412670 | Symbol: FUN_00412670
// ============================================================================
void FUN_00412670(ushort param_1)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *local_20;
  int *local_1c;
  int local_18;
  int *local_8;
  
  hResInfo = FindResourceA((HMODULE)0x0,(LPCSTR)(uint)param_1,"WAVE");
  hResData = LoadResource((HMODULE)0x0,hResInfo);
  puVar1 = LockResource(hResData);
  uVar5 = *puVar1;
  local_8 = puVar1 + 3;
  piVar4 = (int *)((int)puVar1 + puVar1[1] + 8);
  local_20 = (int *)0x0;
  local_1c = (int *)0x0;
  local_18 = 0;
  do {
    if (piVar4 <= local_8) break;
    piVar3 = local_8 + 2;
    if (*local_8 == 0x20746d66) {
      if (local_20 == (int *)0x0) {
        local_20 = piVar3;
      }
    }
    else if ((*local_8 == 0x61746164) && (local_1c == (int *)0x0)) {
      local_1c = piVar3;
      local_18 = local_8[1];
    }
    local_8 = (int *)((local_8[1] + 1U & 0xfffffffe) + (int)piVar3);
  } while ((local_20 == (int *)0x0) || (local_1c == (int *)0x0));
  *(int *)(in_ECX + 0x10) = local_18;
  uVar2 = FUN_0042d2b4(local_18);
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  FUN_004307f0(*(undefined4 *)(in_ECX + 0x14),local_1c,local_18,uVar2,piVar4,uVar5);
  JSound__CreateDSBuffer();
  JSound__FillDSBuffer();
  return;
}

// ============================================================================
// Address: 0x4127d0 | Symbol: JSound::CreateDSBuffer
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void JSound__CreateDSBuffer(void)

{
  undefined4 local_48;
  uint local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 *local_2c;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  _memset(&local_18,0,0x10);
  local_18 = 1;
  local_16 = 1;
  local_14 = 0x5622;
  local_c = 1;
  local_10 = 0x5622;
  local_a = 8;
  _memset(&local_3c,0,0x24);
  local_3c = 0x24;
  local_38 = 0x80;
  local_34 = *(undefined4 *)(local_40 + 0x10);
  local_2c = &local_18;
  for (local_44 = 0; local_44 < *(uint *)(local_40 + 0xc); local_44 = local_44 + 1) {
    (**(code **)(**(int **)(local_40 + 4) + 0xc))
              (*(undefined4 *)(local_40 + 4),&local_3c,&local_48,0);
    JBaseList__Append(local_48);
  }
  return;
}

// ============================================================================
// Address: 0x4128c0 | Symbol: JSound::FillDSBuffer
// ============================================================================
void JSound__FillDSBuffer(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int *local_8;
  
  local_10 = 0;
  local_c = in_ECX;
  while( true ) {
    uVar1 = JBaseList__Count();
    if (uVar1 <= local_10) break;
    local_8 = (int *)JBaseList__GetData(local_10);
    if (local_8 != (int *)0x0) {
      iVar2 = (**(code **)(*local_8 + 0x2c))
                        (local_8,0,*(undefined4 *)(local_c + 0x10),&local_20,&local_18,&local_14,
                         &local_1c,0);
      if (iVar2 == -0x7787ff6a) {
        (**(code **)(*local_8 + 0x50))(local_8);
        (**(code **)(*local_8 + 0x2c))
                  (local_8,0,*(undefined4 *)(local_c + 0x10),&local_20,&local_18,&local_14,&local_1c
                   ,0);
      }
      FUN_004307f0(local_20,*(undefined4 *)(local_c + 0x14),local_18);
      if (local_14 != 0) {
        FUN_004307f0(local_14,*(int *)(local_c + 0x14) + local_18,local_1c);
      }
      (**(code **)(*local_8 + 0x4c))(local_8,local_20,local_18,local_14,local_1c);
    }
    local_10 = local_10 + 1;
  }
  return;
}

// ============================================================================
// Address: 0x4129e0 | Symbol: JSoundList::JSoundList
// ============================================================================
undefined4 * JSoundList__JSoundList(undefined4 param_1)

{
  undefined4 *in_ECX;
  int local_c;
  
  *in_ECX = JSoundList::vftable;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  for (local_c = 0; local_c < 0x1e; local_c = local_c + 1) {
    in_ECX[local_c + 3] = 0;
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x412a40 | Symbol: JSoundList::~JSoundList
// ============================================================================
void JSoundList___JSoundList(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00470e17;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JSoundList::vftable;
  JSoundList__StopAll(uVar1);
  for (local_18 = 0; local_18 < 0x1e; local_18 = local_18 + 1) {
    if (in_ECX[local_18 + 3] != 0) {
      if ((undefined4 *)in_ECX[local_18 + 3] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[local_18 + 3])(1);
      }
      in_ECX[local_18 + 3] = 0;
    }
  }
  if (in_ECX[2] != 0) {
    (**(code **)(*(int *)in_ECX[2] + 8))(in_ECX[2]);
    in_ECX[2] = 0;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x412b20 | Symbol: JSoundList::Create
// ============================================================================
undefined4 JSoundList__Create(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = Ordinal_1(0,in_ECX + 8,0);
  if (iVar1 < 0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    uVar2 = 0;
  }
  else {
    iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))
                      (*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 4),1);
    if (iVar1 < 0) {
      if (*(int *)(in_ECX + 8) != 0) {
        (**(code **)(**(int **)(in_ECX + 8) + 8))(*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = 0;
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x412bb0 | Symbol: JSoundList::CreateSound
// ============================================================================
void JSoundList__CreateSound(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470e48;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 8) != 0) &&
     (iVar1 = JSoundList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc), -1 < iVar1)) {
    iVar2 = FUN_0042d23e(0x2c);
    local_8 = 0;
    if (iVar2 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = JSound__JSound(*(undefined4 *)(in_ECX + 8),param_1,param_2,param_3);
    }
    *(undefined4 *)(in_ECX + 0xc + iVar1 * 4) = local_1c;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x412c70 | Symbol: FUN_00412c70
// ============================================================================
void FUN_00412c70(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470e79;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(in_ECX + 8) != 0) &&
     (iVar1 = JSoundList__GetNullIndex(DAT_00486cf0 ^ (uint)&stack0xfffffffc), -1 < iVar1)) {
    iVar2 = FUN_0042d23e(0x2c);
    local_8 = 0;
    if (iVar2 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = FUN_004121f0(*(undefined4 *)(in_ECX + 8),param_1,param_2);
    }
    *(undefined4 *)(in_ECX + 0xc + iVar1 * 4) = local_1c;
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x412d20 | Symbol: JSoundList::Play
// ============================================================================
void JSoundList__Play(undefined2 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != 0) && (iVar1 = JSoundList__FindIndexOfResId(param_1), -1 < iVar1)) {
    JSound__SetVolume(param_2);
    JSound__Play(param_3);
  }
  return;
}

// ============================================================================
// Address: 0x412d80 | Symbol: JSoundList::Stop
// ============================================================================
void JSoundList__Stop(undefined2 param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != 0) && (iVar1 = JSoundList__FindIndexOfResId(param_1), -1 < iVar1)) {
    JSound__Stop();
  }
  return;
}

// ============================================================================
// Address: 0x412dc0 | Symbol: JSoundList::StopAll
// ============================================================================
void JSoundList__StopAll(void)

{
  int in_ECX;
  undefined4 local_8;
  
  for (local_8 = 0; local_8 < 0x1e; local_8 = local_8 + 1) {
    if (*(int *)(in_ECX + 0xc + local_8 * 4) != 0) {
      JSound__Stop();
    }
  }
  return;
}

// ============================================================================
// Address: 0x412e10 | Symbol: JSoundList::GetNullIndex
// ============================================================================
int JSoundList__GetNullIndex(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x1d < local_8) {
      return -1;
    }
    if (*(int *)(in_ECX + 0xc + local_8 * 4) == 0) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x412e60 | Symbol: JSoundList::FindIndexOfResId
// ============================================================================
int JSoundList__FindIndexOfResId(short param_1)

{
  short sVar1;
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x1d < local_8) {
      return -1;
    }
    if ((*(int *)(in_ECX + 0xc + local_8 * 4) != 0) &&
       (sVar1 = JSound__GetResId(), sVar1 == param_1)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}

// ============================================================================
// Address: 0x412ed0 | Symbol: JSound::
// ============================================================================
undefined4 JSound__(uint param_1)

{
  undefined4 in_ECX;
  
  JSound___JSound();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x2c);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x412f00 | Symbol: JSoundList::
// ============================================================================
undefined4 JSoundList__(uint param_1)

{
  undefined4 in_ECX;
  
  JSoundList___JSoundList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x84);
  }
  return in_ECX;
}
