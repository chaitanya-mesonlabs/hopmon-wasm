// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XAppMain.h
// Generated from PDB Type Stream

#ifndef XAPPMAIN_H_
#define XAPPMAIN_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XApplication (size: 512 bytes)
class XApplication {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XApplication();
    virtual /* method */ ~XApplication();
    /* method */ LoadWinRegData();
    /* method */ SaveWinRegData();
    /* method */ SetState();
    /* method */ GetCurrentWorld();
    /* method */ GetDInput();
    /* method */ GetMidiList();
    /* method */ GetSoundList();
    /* method */ GetSurfaceList();
    virtual /* method */ Create();
    virtual /* method */ MsgProc();
    virtual /* method */ OneTimeSceneInit();
    virtual /* method */ InitDeviceObjects();
    virtual /* method */ DeleteDeviceObjects();
    virtual /* method */ Render();
    virtual /* method */ FrameMove();
    virtual /* method */ FinalCleanup();
    virtual /* method */ RestoreSurfaces();
    /* method */ ConfirmDevice();
    /* method */ _DisableStickyKeys();
    /* method */ _RestoreStickyKeys();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x1A8 */ 0x0074 (int) currentLevel;
    /* +0x1AC */ 0x0074 (int) maxSelLevel;
    /* +0x1B0 */ 0x128B maxFreeLevel;
    /* +0x1B4 */ 0x128B maxLevel;
    /* +0x1B8 */ 0x128D tempList;
    /* +0x1BC */ 0x1296 prevStikeyKeys;
    /* +0x1C4 */ 0x1297 prevFilterKeys;
    /* +0x1DC */ 0x1298 prevToggleKeys;
    /* +0x1E4 */ 0x1272 state;
    /* +0x1E8 */ 0x1045 dinput;
    /* +0x1EC */ 0x1281 midiList;
    /* +0x1F0 */ 0x1284 soundList;
    /* +0x1F4 */ 0x122A surfaceList;
    /* +0x1F8 */ 0x129A processObj;
    /* +0x1FC */ 0x129C fpsDisplay;

};

// Class: XFPSDisplay (size: 16 bytes)
class XFPSDisplay {
public:
    /* method */ XFPSDisplay();
    virtual /* method */ ~XFPSDisplay();
    /* method */ Render();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1003 app;
    /* +0x008 */ 0x14BB textFPS;
    /* +0x00C */ 0x14CA numFPS;

};

#endif // XAPPMAIN_H_
