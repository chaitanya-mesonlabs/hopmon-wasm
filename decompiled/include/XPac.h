// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XPac.h
// Generated from PDB Type Stream

#ifndef XPAC_H_
#define XPAC_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XPac (size: 144 bytes)
class XPac {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XPac();
    virtual /* method */ ~XPac();
    virtual /* method */ Render();
    /* method */ Reset();
    /* method */ GetState();
    /* method */ GetFaceDirection();
    /* method */ SetMapPos();
    /* method */ GetMapPosX();
    /* method */ GetMapPosZ();
    /* method */ GetFireEnergy();
    /* method */ ResetFireEnergy();
    /* method */ SetFaceDirection();
    /* method */ StartMoving();
    /* method */ StartArrow();
    /* method */ StartDying();
    /* method */ ProcessRotate();
    /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x05C */ 0x176B game;
    /* +0x060 */ 0x179F state;
    /* +0x064 */ 0x0075 (unsigned) localTime;
    /* +0x068 */ 0x0074 (int) mapPosX;
    /* +0x06C */ 0x0074 (int) mapPosZ;
    /* +0x070 */ 0x0074 (int) faceDirection;
    /* +0x074 */ 0x0074 (int) moveDirection;
    /* +0x078 */ 0x12F3 refrencePos;
    /* +0x084 */ 0x180D shadow;
    /* +0x088 */ 0x0075 (unsigned) pacMoveFrame;
    /* +0x08C */ 0x0074 (int) fireEnergy;

};

// Class: XPacFire (size: 152 bytes)
class XPacFire {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XPacFire();
    virtual /* method */ ~XPacFire();
    virtual /* method */ Render2();
    /* method */ GetState();
    /* method */ SetState();
    /* method */ GetDirection();
    /* method */ ProcessFrame();
    /* method */ _SetTextureRandomly();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x088 */ 0x176B game;
    /* +0x08C */ 0x1791 state;
    /* +0x090 */ 0x0075 (unsigned) localTime;
    /* +0x094 */ 0x0074 (int) direction;

};

// Class: XPacFireList (size: 20 bytes)
class XPacFireList {
public:
    /* method */ XPacFireList();
    virtual /* method */ ~XPacFireList();
    /* method */ CreateFire();
    /* method */ Empty();
    /* method */ CheckCollisionWithEnemy();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ GetNullIndex();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x176B game;
    /* +0x008 */ 0x1905 fireArray;

};

#endif // XPAC_H_
