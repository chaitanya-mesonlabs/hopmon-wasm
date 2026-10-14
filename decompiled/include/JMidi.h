// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JMidi.h
// Generated from PDB Type Stream

#ifndef JMIDI_H_
#define JMIDI_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JMidiList (size: 20 bytes)
class JMidiList {
public:
    /* method */ JMidiList();
    virtual /* method */ ~JMidiList();
    /* method */ Append();
    /* method */ Play();
    /* method */ Replay();
    /* method */ Pause();
    /* method */ Resume();
    /* method */ Stop();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x10DF hWind;
    /* +0x008 */ 0x0074 (int) paused;
    /* +0x00C */ 0x0074 (int) currentMidiIndex;
    /* +0x010 */ 0x128D midiFileList;

};

#endif // JMIDI_H_
