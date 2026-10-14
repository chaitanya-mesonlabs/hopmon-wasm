// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JSound.h
// Generated from PDB Type Stream

#ifndef JSOUND_H_
#define JSOUND_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JSound (size: 44 bytes)
class JSound {
public:
    /* method */ JSound();
    virtual /* method */ ~JSound();
    /* method */ GetResId();
    /* method */ SetVolume();
    /* method */ Play();
    /* method */ Stop();
    /* method */ CreateWaveData();
    /* method */ CreateDSBuffer();
    /* method */ FillDSBuffer();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x13D9 lpDSound;
    /* +0x008 */ 0x0021 (unsigned short) resId;
    /* +0x00C */ 0x0022 (unsigned long) count;
    /* +0x010 */ 0x0022 (unsigned long) waveLength;
    /* +0x014 */ 0x0420 (unsigned char*) waveData;
    /* +0x018 */ 0x0022 (unsigned long) playIndex;
    /* +0x01C */ 0x0020 (unsigned char) volume;
    /* +0x020 */ 0x1499 bufferList;

};

// Class: JSoundList (size: 132 bytes)
class JSoundList {
public:
    /* method */ JSoundList();
    virtual /* method */ ~JSoundList();
    /* method */ Create();
    /* method */ CreateSound();
    /* method */ Play();
    /* method */ Stop();
    /* method */ StopAll();
    /* method */ GetNullIndex();
    /* method */ FindIndexOfResId();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x10DF hWind;
    /* +0x008 */ 0x13D9 lpDSound;
    /* +0x00C */ 0x13DC soundArray;

};

#endif // JSOUND_H_
