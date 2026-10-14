// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: JMidi.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "JMidi.h"

// ============================================================================
// Address: 0x40ef30 | Symbol: JMidiList::JMidiList
// ============================================================================
undefined4 * JMidiList__JMidiList(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470b94;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = JMidiList::vftable;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0xffffffff;
  iVar2 = FUN_0042d23e(0x10,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    local_1c = JStringList__JStringList();
  }
  in_ECX[4] = local_1c;
  ExceptionList = local_10;
  return in_ECX;
}

// ============================================================================
// Address: 0x40efe0 | Symbol: JMidiList::~JMidiList
// ============================================================================
void JMidiList___JMidiList(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = JMidiList::vftable;
  if ((in_ECX[4] != 0) && ((undefined4 *)in_ECX[4] != (undefined4 *)0x0)) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  return;
}

// ============================================================================
// Address: 0x40f040 | Symbol: JMidiList::Append
// ============================================================================
void JMidiList__Append(undefined4 param_1)

{
  uint uVar1;
  InternalContextBase local_1c [8];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470bbe;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00413970(param_1);
  local_8 = 0;
  Concurrency::details::SchedulerBase::JStringList__Append
            (*(SchedulerBase **)(local_14 + 0x10),local_1c);
  local_8 = 0xffffffff;
  JString___JString(uVar1);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40f0b0 | Symbol: JMidiList::Play
// ============================================================================
void JMidiList__Play(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 local_1c [8];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470be8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (-1 < param_1) {
    iVar1 = JStringList__Count(DAT_00486cf0 ^ (uint)&stack0xfffffffc);
    if ((param_1 < iVar1) && (*(int *)(local_14 + 0xc) != param_1)) {
      JMidiList__Stop();
      uVar3 = 1;
      uVar2 = JStringList__GetString(param_1);
      ConvertToFullPath(local_1c,uVar2,uVar3);
      local_8 = 0;
      uVar2 = JString__c_str();
      PlayMidi(*(undefined4 *)(local_14 + 4),uVar2);
      *(int *)(local_14 + 0xc) = param_1;
      if (*(int *)(local_14 + 8) != 0) {
        PauseMidi();
      }
      local_8 = 0xffffffff;
      JString___JString();
    }
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40f180 | Symbol: JMidiList::Replay
// ============================================================================
void JMidiList__Replay(void)

{
  int in_ECX;
  
  if (-1 < *(int *)(in_ECX + 0xc)) {
    ReplayMidi(*(undefined4 *)(in_ECX + 4));
    if (*(int *)(in_ECX + 8) != 0) {
      PauseMidi();
    }
  }
  return;
}

// ============================================================================
// Address: 0x40f1c0 | Symbol: JMidiList::Pause
// ============================================================================
void JMidiList__Pause(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 1;
  if (-1 < *(int *)(in_ECX + 0xc)) {
    PauseMidi();
  }
  return;
}

// ============================================================================
// Address: 0x40f1f0 | Symbol: JMidiList::Resume
// ============================================================================
void JMidiList__Resume(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  if (-1 < *(int *)(in_ECX + 0xc)) {
    ResumeMidi(*(undefined4 *)(in_ECX + 4));
  }
  return;
}

// ============================================================================
// Address: 0x40f220 | Symbol: JMidiList::Stop
// ============================================================================
void JMidiList__Stop(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0xffffffff;
  StopMidi();
  return;
}

// ============================================================================
// Address: 0x40f240 | Symbol: PlayMidi
// ============================================================================
undefined4 PlayMidi(HWND param_1,int param_2)

{
  undefined4 uVar1;
  MCIERROR MVar2;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    sprintf(&DAT_0048e250,"open %s type sequencer alias MUSIC",param_2);
    MVar2 = mciSendStringA("close all",(LPSTR)0x0,0,(HWND)0x0);
    if (MVar2 == 0) {
      MVar2 = mciSendStringA(&DAT_0048e250,(LPSTR)0x0,0,(HWND)0x0);
      if (MVar2 == 0) {
        MVar2 = mciSendStringA("play MUSIC from 0 notify",(LPSTR)0x0,0,param_1);
        if (MVar2 == 0) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

// ============================================================================
// Address: 0x40f2c0 | Symbol: PauseMidi
// ============================================================================
bool PauseMidi(void)

{
  MCIERROR MVar1;
  
  MVar1 = mciSendStringA("stop MUSIC",(LPSTR)0x0,0,(HWND)0x0);
  return MVar1 == 0;
}

// ============================================================================
// Address: 0x40f2f0 | Symbol: ResumeMidi
// ============================================================================
bool ResumeMidi(HWND param_1)

{
  MCIERROR MVar1;
  
  MVar1 = mciSendStringA("play MUSIC notify",(LPSTR)0x0,0,param_1);
  return MVar1 == 0;
}

// ============================================================================
// Address: 0x40f320 | Symbol: StopMidi
// ============================================================================
bool StopMidi(void)

{
  MCIERROR MVar1;
  
  MVar1 = mciSendStringA("close all",(LPSTR)0x0,0,(HWND)0x0);
  return MVar1 == 0;
}

// ============================================================================
// Address: 0x40f350 | Symbol: ReplayMidi
// ============================================================================
bool ReplayMidi(HWND param_1)

{
  MCIERROR MVar1;
  
  MVar1 = mciSendStringA("play MUSIC from 0 notify",(LPSTR)0x0,0,param_1);
  return MVar1 == 0;
}

// ============================================================================
// Address: 0x40f380 | Symbol: JMidiList::
// ============================================================================
undefined4 JMidiList__(uint param_1)

{
  undefined4 in_ECX;
  
  JMidiList___JMidiList();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x14);
  }
  return in_ECX;
}
