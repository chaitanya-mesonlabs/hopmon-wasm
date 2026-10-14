// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JDinput.h
// Generated from PDB Type Stream

#ifndef JDINPUT_H_
#define JDINPUT_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JDInput (size: 1192 bytes)
class JDInput {
public:
    /* method */ JDInput();
    virtual /* method */ ~JDInput();
    /* method */ Create();
    /* method */ Destroy();
    /* method */ UpdateInputState();
    /* method */ SetAcquireKeyboard();
    /* method */ GetKeyboardState();
    /* method */ GetKeyboardPressed();
    /* method */ GetKeyboardReleased();
    /* method */ GetKeyboardBuffer();
    /* method */ ClearKeyboardBuffer();
    /* method */ SetAcquireJoystick();
    /* method */ GetJoyButtonState();
    /* method */ GetJoyButtonPressed();
    /* method */ GetJoyButtonReleased();
    /* method */ GetJoyDirState();
    /* method */ GetJoyDirPressed();
    /* method */ GetJoyDirReleased();
    /* method */ _CreateKeyboard();
    /* method */ _CreateJoystick();
    /* method */ _GetJoyDirStatePrev();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x10DF hWind;
    /* +0x008 */ 0x139B lpInput;
    /* +0x00C */ 0x1381 lpKeyboard;
    /* +0x010 */ 0x16E4 lpJoystick;
    /* +0x020 */ 0x16E5 inputState1;
    /* +0x260 */ 0x16E5 inputState2;
    /* +0x4A0 */ 0x0074 (int) acquireKeyboard;
    /* +0x4A4 */ 0x0074 (int) acquireJoystick;

};

// Class: JINPUTSTATE (size: 576 bytes)
class JINPUTSTATE {
public:
    /* +0x000 */ 0x1677 keyState;
    /* +0x100 */ 0x1679 joyState;

};

#endif // JDINPUT_H_
