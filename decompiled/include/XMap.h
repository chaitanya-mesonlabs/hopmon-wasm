// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XMap.h
// Generated from PDB Type Stream

#ifndef XMAP_H_
#define XMAP_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XMap (size: 44 bytes)
class XMap {
public:
    /* method */ XMap();
    virtual /* method */ ~XMap();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ GetChipSize();
    /* method */ IsBlocked_Pac();
    /* method */ IsBlocked_Fire();
    /* method */ IsBlocked_Enemy();
    /* method */ IsBlocked_UFO();
    /* method */ IsWarpZone();
    /* method */ IsArrow();
    /* method */ GetArrowDirection();
    /* method */ ConvertPosXToMapX();
    /* method */ ConvertPosZToMapZ();
    /* method */ UpdateEnemyMap();
    /* method */ ZeroEnemyMap();
    /* method */ UpdateUFOMap();
    /* method */ _LoadMapArray();
    /* method */ _CreateMapObject();
    /* method */ _CreateBackground();
    /* method */ _ConvertMapItemToInt();
    /* method */ _CreateFloor();
    /* method */ _CreateWalls();
    /* method */ _IsOutsideMap();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1003 app;
    /* +0x008 */ 0x0420 (unsigned char*) mapArray;
    /* +0x00C */ 0x0420 (unsigned char*) enemyMapArray;
    /* +0x010 */ 0x0420 (unsigned char*) ufoMapArray;
    /* +0x014 */ 0x1545 mapObject;
    /* +0x018 */ 0x16F2 background;
    /* +0x01C */ 0x0040 (float) chipSize;
    /* +0x020 */ 0x0074 (int) mapSizeX;
    /* +0x024 */ 0x0074 (int) mapSizeZ;
    /* +0x028 */ 0x0021 (unsigned short) mapTextureId;

};

// Class: XPreviewMap (size: 32 bytes)
class XPreviewMap {
public:
    /* method */ XPreviewMap();
    virtual /* method */ ~XPreviewMap();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ _LoadMapArray();
    /* method */ _CreateMapObject();
    /* method */ _ConvertMapItemToInt();
    /* method */ _CreateFloor();
    /* method */ _CreateWalls();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1003 app;
    /* +0x008 */ 0x0420 (unsigned char*) mapArray;
    /* +0x00C */ 0x1545 mapObject;
    /* +0x010 */ 0x0040 (float) chipSize;
    /* +0x014 */ 0x0074 (int) mapSizeX;
    /* +0x018 */ 0x0074 (int) mapSizeZ;
    /* +0x01C */ 0x0021 (unsigned short) mapTextureId;

};

#endif // XMAP_H_
