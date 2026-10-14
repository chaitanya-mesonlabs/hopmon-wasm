// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XMapObject.h
// Generated from PDB Type Stream

#ifndef XMAPOBJECT_H_
#define XMAPOBJECT_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XMapObjectBase (size: 112 bytes)
class XMapObjectBase {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XMapObjectBase();
    virtual /* method */ ~XMapObjectBase();
    virtual /* method */ Render();
    /* method */ GetState();
    /* method */ SetDirection();
    virtual /* method */ ProcessRotate();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x05C */ 0x176B game;
    /* +0x060 */ 0x1991 state;
    /* +0x064 */ 0x0075 (unsigned) localTime;
    /* +0x068 */ 0x0074 (int) direction;
    /* +0x06C */ 0x180D shadow;

};

// Class: XMapObjectList (size: 108 bytes)
class XMapObjectList {
public:
    /* method */ XMapObjectList();
    virtual /* method */ ~XMapObjectList();
    /* method */ CreateMapObject();
    /* method */ Empty();
    /* method */ ProcessRotate();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ GetNullIndex();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x176B game;
    /* +0x008 */ 0x1978 objArray;

};

// Class: XTree (size: 112 bytes)
class XTree {
public:
    /* method */ XTree();
    virtual /* method */ ~XTree();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XSteam (size: 112 bytes)
class XSteam {
public:
    /* method */ XSteam();
    virtual /* method */ ~XSteam();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XVolcano (size: 112 bytes)
class XVolcano {
public:
    /* method */ XVolcano();
    virtual /* method */ ~XVolcano();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XCannon (size: 112 bytes)
class XCannon {
public:
    /* method */ XCannon();
    virtual /* method */ ~XCannon();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XCannonUp (size: 112 bytes)
class XCannonUp {
public:
    /* method */ XCannonUp();
    virtual /* method */ ~XCannonUp();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XPole (size: 112 bytes)
class XPole {
public:
    /* method */ XPole();
    virtual /* method */ ~XPole();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XShortPole (size: 112 bytes)
class XShortPole {
public:
    /* method */ XShortPole();
    virtual /* method */ ~XShortPole();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XGate (size: 144 bytes)
class XGate {
public:
    /* method */ XGate();
    virtual /* method */ ~XGate();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

#endif // XMAPOBJECT_H_
