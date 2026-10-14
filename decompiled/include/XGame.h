// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XGame.h
// Generated from PDB Type Stream

#ifndef XGAME_H_
#define XGAME_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XGameObject (size: 72 bytes)
class XGameObject {
public:
    /* method */ XGameObject();
    virtual /* method */ ~XGameObject();
    virtual /* method */ ProcessFrame();
    virtual /* method */ Render();
    /* method */ InitLevel();
    /* method */ GetCurrentLevel();
    /* method */ GetVolumeOfPosition();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x020 */ 0x14C6 camera;
    /* +0x024 */ 0x1917 map;
    /* +0x028 */ 0x138C pac;
    /* +0x02C */ 0x1887 enemyList;
    /* +0x030 */ 0x1889 mapObjList;
    /* +0x034 */ 0x1918 pacFireList;
    /* +0x038 */ 0x1919 enemyFireList;
    /* +0x03C */ 0x191B particleList;
    /* +0x040 */ 0x188B crystalList;
    /* +0x044 */ 0x191C statusDisplay;

};

// Class: XCamera (size: 120 bytes)
class XCamera {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XCamera();
    virtual /* method */ ~XCamera();
    /* method */ ResetForGame();
    /* method */ ResetForTitle();
    /* method */ DoSetTransform();
    /* method */ GetState();
    /* method */ GetViewDirection();
    /* method */ GetViewMatrix();
    /* method */ StartRotatingLeft();
    /* method */ StartRotatingRight();
    /* method */ StartLevelCompleted();
    /* method */ StartGameOver();
    /* method */ IncrVerticalAngle();
    /* method */ DecrVerticalAngle();
    /* method */ ProcessFrame();
    /* method */ UpdateViewMatrix();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1003 app;
    /* +0x008 */ 0x1383 state;
    /* +0x00C */ 0x0075 (unsigned) localTime;
    /* +0x010 */ 0x12F3 lookAtPos;
    /* +0x01C */ 0x12F3 refPos;
    /* +0x028 */ 0x0040 (float) distance;
    /* +0x02C */ 0x0040 (float) verticalAngle;
    /* +0x030 */ 0x0040 (float) horizontalAngle;
    /* +0x034 */ 0x0074 (int) viewDir;
    /* +0x038 */ 0x12C5 viewMatrix;

};

// Class: XStatusDisplay (size: 32 bytes)
class XStatusDisplay {
public:
    /* method */ XStatusDisplay();
    virtual /* method */ ~XStatusDisplay();
    /* method */ Draw();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x176B game;
    /* +0x008 */ 0x14BB textLevel;
    /* +0x00C */ 0x14BB textCrystals;
    /* +0x010 */ 0x14BB textFireReady;
    /* +0x014 */ 0x14BB fireLED;
    /* +0x018 */ 0x14CA numLevel;
    /* +0x01C */ 0x14CA numCrystals;

};

// Class: XProcessObject (size: 32 bytes)
class XProcessObject {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XProcessObject();
    virtual /* method */ ~XProcessObject();
    virtual /* method */ ProcessFrame();
    virtual /* method */ Render();
    /* method */ StartFadeIn();
    /* method */ StartFadeOut();
    /* method */ StartProcess();
    /* method */ ProcessFadeIn();
    /* method */ ProcessFadeOut();
    /* method */ _ResetFadeIn();
    /* method */ _ResetFadeOut();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1003 app;
    /* +0x008 */ 0x1752 state;
    /* +0x00C */ 0x0075 (unsigned) tick;
    /* +0x010 */ 0x14BB fadeLeft;
    /* +0x014 */ 0x14BB fadeRight;
    /* +0x018 */ 0x0074 (int) processType;
    /* +0x01C */ 0x0074 (int) processFinished;

};

#endif // XGAME_H_
