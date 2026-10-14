// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XChara.h
// Generated from PDB Type Stream

#ifndef XCHARA_H_
#define XCHARA_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XParticleBase (size: 160 bytes)
class XParticleBase {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XParticleBase();
    virtual /* method */ ~XParticleBase();
    virtual /* method */ Render2();
    /* method */ GetState();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x088 */ 0x176B game;
    /* +0x08C */ 0x18AA state;
    /* +0x090 */ 0x0075 (unsigned) localTime;
    /* +0x094 */ 0x12F3 refrencePos;

};

// Class: XParticleList (size: 612 bytes)
class XParticleList {
public:
    /* method */ XParticleList();
    virtual /* method */ ~XParticleList();
    /* method */ Empty();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ CreateEnemyExplode();
    /* method */ CreateEnemyFireSmokePurple();
    /* method */ CreateEnemyFireSmokeGreen();
    /* method */ CreatePacFireHit();
    /* method */ CreatePacVanish();
    /* method */ GetNullIndex();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x176B game;
    /* +0x008 */ 0x0021 (unsigned short) _arrayPointer;
    /* +0x00C */ 0x1941 particleArray;

};

// Class: XCrystal (size: 136 bytes)
class XCrystal {
public:
    enum STATE { /* values in PDB enum */ };

public:
    /* method */ XCrystal();
    virtual /* method */ ~XCrystal();
    virtual /* method */ Render();
    /* method */ GetState();
    /* method */ SetState();
    /* method */ GetTakenPosition();
    /* method */ StartTaken();
    /* method */ StartVanishing();
    /* method */ StartGameOver();
    /* method */ ProcessRotate();
    /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x05C */ 0x176B game;
    /* +0x060 */ 0x17FC state;
    /* +0x064 */ 0x0075 (unsigned) localTime;
    /* +0x068 */ 0x180D shadow;
    /* +0x06C */ 0x0074 (int) takenPosition;
    /* +0x070 */ 0x12F3 dirVector;
    /* +0x07C */ 0x12F3 referencePos;

};

// Class: XCrystalList (size: 136 bytes)
class XCrystalList {
public:
    /* method */ XCrystalList();
    virtual /* method */ ~XCrystalList();
    /* method */ CreateCrystal();
    /* method */ Empty();
    /* method */ CheckCollisionWithPac();
    /* method */ DoVanishCrystal();
    /* method */ StartGameOver();
    /* method */ GetTakenCount();
    /* method */ GetCrystalLeft();
    /* method */ ProcessRotate();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ GetNullIndex();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x176B game;
    /* +0x008 */ 0x192F crystalArray;
    /* +0x080 */ 0x0074 (int) takenCount;
    /* +0x084 */ 0x0074 (int) crystalLeft;

};

// Class: XParticle_EnemyExplode (size: 172 bytes)
class XParticle_EnemyExplode {
public:
    /* method */ XParticle_EnemyExplode();
    virtual /* method */ ~XParticle_EnemyExplode();
    /* method */ SetDirVector();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x0A0 */ 0x12F3 dirVector;

};

// Class: XParticle_EnemyFireSmokeGreen (size: 160 bytes)
class XParticle_EnemyFireSmokeGreen {
public:
    /* method */ XParticle_EnemyFireSmokeGreen();
    virtual /* method */ ~XParticle_EnemyFireSmokeGreen();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XParticle_EnemyFireSmokePurple (size: 160 bytes)
class XParticle_EnemyFireSmokePurple {
public:
    /* method */ XParticle_EnemyFireSmokePurple();
    virtual /* method */ ~XParticle_EnemyFireSmokePurple();
    virtual /* method */ ProcessFrame();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: XParticle_PacFireHit (size: 168 bytes)
class XParticle_PacFireHit {
public:
    /* method */ XParticle_PacFireHit();
    virtual /* method */ ~XParticle_PacFireHit();
    virtual /* method */ Render2();
    virtual /* method */ ProcessFrame();
    /* method */ _SetTextureRandomly();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x0A0 */ 0x0075 (unsigned) processFrame;
    /* +0x0A4 */ 0x0075 (unsigned) renderCount;

};

#endif // XCHARA_H_
