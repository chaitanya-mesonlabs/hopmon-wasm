// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XEnemy.h
// Generated from PDB Type Stream

#ifndef XENEMY_H_
#define XENEMY_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XEnemyBase (size: 144 bytes)
class XEnemyBase {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XEnemyBase();
    virtual /* method */ ~XEnemyBase();
    virtual /* method */ Render();
    /* method */ GetState();
    /* method */ Breakable();
    /* method */ SetMapPos();
    /* method */ SetDirection();
    /* method */ StartMoving();
    /* method */ StartDying();
    /* method */ StartFiring();
    /* method */ DecreaseShield();
    /* method */ ProcessRotate();
    virtual /* method */ SubProcessDyingRotate();
    virtual /* method */ SubProcessMoveRotate();
    virtual /* method */ SubProcessFireRotate();
    /* method */ ProcessFrame();
    virtual /* method */ SubProcessDying();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    virtual /* method */ SubProcessFire();
    /* method */ IsBlocked();
    /* method */ FindDirectionToPac();
    /* method */ DefaultProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x05C */ 0x176B game;
    /* +0x060 */ 0x1866 state;
    /* +0x064 */ 0x0075 (unsigned) localTime;
    /* +0x068 */ 0x0074 (int) mapPosX;
    /* +0x06C */ 0x0074 (int) mapPosZ;
    /* +0x070 */ 0x12F3 refrencePos;
    /* +0x07C */ 0x0074 (int) direction;
    /* +0x080 */ 0x180D shadow;
    /* +0x084 */ 0x0074 (int) faceToDir;
    /* +0x088 */ 0x0074 (int) breakable;
    /* +0x08C */ 0x0074 (int) shield;

};

// Class: XEnemyList (size: 128 bytes)
class XEnemyList {
public:
    /* method */ XEnemyList();
    virtual /* method */ ~XEnemyList();
    /* method */ CreateEnemy();
    /* method */ GetAt();
    /* method */ Empty();
    /* method */ CheckCollisionWithPac();
    /* method */ ProcessRotate();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ GetNullIndex();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x176B game;
    /* +0x008 */ 0x18D2 enemyArray;

};

// Class: XEnemyFireBase (size: 160 bytes)
class XEnemyFireBase {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XEnemyFireBase();
    virtual /* method */ ~XEnemyFireBase();
    virtual /* method */ Render2();
    /* method */ GetState();
    /* method */ SetState();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x088 */ 0x176B game;
    /* +0x08C */ 0x17AD state;
    /* +0x090 */ 0x0075 (unsigned) localTime;
    /* +0x094 */ 0x12F3 refrencePos;

};

// Class: XEnemyFireList (size: 248 bytes)
class XEnemyFireList {
public:
    /* method */ XEnemyFireList();
    virtual /* method */ ~XEnemyFireList();
    /* method */ CheckCollisionWithPac();
    /* method */ Empty();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ CreateCannonUpFire();
    /* method */ CreateVolcanoFire();
    /* method */ CreateCannonFire();
    /* method */ CreateUFOFire();
    /* method */ CreateSteamFire();
    /* method */ GetNullIndex();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x176B game;
    /* +0x008 */ 0x1824 fireArray;

};

// Class: XEnemy_Cube (size: 144 bytes)
class XEnemy_Cube {
public:
    /* method */ XEnemy_Cube();
    virtual /* method */ ~XEnemy_Cube();
    virtual /* method */ SubProcessMoveRotate();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XEnemy_Ghost (size: 144 bytes)
class XEnemy_Ghost {
public:
    /* method */ XEnemy_Ghost();
    virtual /* method */ ~XEnemy_Ghost();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XEnemy_Kurage (size: 144 bytes)
class XEnemy_Kurage {
public:
    /* method */ XEnemy_Kurage();
    virtual /* method */ ~XEnemy_Kurage();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XEnemy_Sesame (size: 152 bytes)
class XEnemy_Sesame {
public:
    /* method */ XEnemy_Sesame();
    virtual /* method */ ~XEnemy_Sesame();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x090 */ 0x0074 (int) moveCountDown;
    /* +0x094 */ 0x0074 (int) movePhase;

};

// Class: XEnemy_UFO (size: 152 bytes)
class XEnemy_UFO {
public:
    /* method */ XEnemy_UFO();
    virtual /* method */ ~XEnemy_UFO();
    virtual /* method */ SubProcessMoveRotate();
    virtual /* method */ SubProcessFireRotate();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    virtual /* method */ SubProcessFire();
    /* method */ StartMoving_UFO();
    /* method */ IsBlocked_UFO();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x090 */ 0x0074 (int) moveCount;
    /* +0x094 */ 0x0074 (int) countDownToFire;

};

// Class: XNeedleBall (size: 144 bytes)
class XNeedleBall {
public:
    /* method */ XNeedleBall();
    virtual /* method */ ~XNeedleBall();
    virtual /* method */ SubProcessMoveRotate();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XNeedleBallFast (size: 144 bytes)
class XNeedleBallFast {
public:
    /* method */ XNeedleBallFast();
    virtual /* method */ ~XNeedleBallFast();
    virtual /* method */ SubProcessMoveRotate();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XNeedleBox (size: 144 bytes)
class XNeedleBox {
public:
    /* method */ XNeedleBox();
    virtual /* method */ ~XNeedleBox();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XNeedleBoxDrop (size: 144 bytes)
class XNeedleBoxDrop {
public:
    /* method */ XNeedleBoxDrop();
    virtual /* method */ ~XNeedleBoxDrop();
    virtual /* method */ SubProcessMove();
    virtual /* method */ SubProcessWait();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XEnemyFire_Cannon (size: 172 bytes)
class XEnemyFire_Cannon {
public:
    /* method */ XEnemyFire_Cannon();
    virtual /* method */ ~XEnemyFire_Cannon();
    /* method */ SetValues();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x0A0 */ 0x12F3 dirVector;

};

// Class: XEnemyFire_CannonUp (size: 176 bytes)
class XEnemyFire_CannonUp {
public:
    /* method */ XEnemyFire_CannonUp();
    virtual /* method */ ~XEnemyFire_CannonUp();
    /* method */ SetValues();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x0A0 */ 0x0040 (float) distance;
    /* +0x0A4 */ 0x12F3 dirVector;

};

// Class: XEnemyFire_Steam (size: 160 bytes)
class XEnemyFire_Steam {
public:
    /* method */ XEnemyFire_Steam();
    virtual /* method */ ~XEnemyFire_Steam();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XEnemyFire_UFO (size: 176 bytes)
class XEnemyFire_UFO {
public:
    /* method */ XEnemyFire_UFO();
    virtual /* method */ ~XEnemyFire_UFO();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x0A0 */ 0x12F3 dirVector;
    /* +0x0AC */ 0x0074 (int) turned;

};

#endif // XENEMY_H_
