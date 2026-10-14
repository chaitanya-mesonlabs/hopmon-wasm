// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JSprite.h
// Generated from PDB Type Stream

#ifndef JSPRITE_H_
#define JSPRITE_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JSprite (size: 44 bytes)
class JSprite {
public:
    /* method */ JSprite();
    virtual /* method */ ~JSprite();
    /* method */ GetPosX();
    /* method */ GetPosY();
    /* method */ GetPosIntX();
    /* method */ GetPosIntY();
    /* method */ GetCenterIntX();
    /* method */ GetCenterIntY();
    /* method */ GetWidth();
    /* method */ GetHeight();
    /* method */ GetCurrentFrame();
    /* method */ GetNumFrames();
    /* method */ SetPosition();
    /* method */ SetPosX();
    /* method */ SetPosY();
    /* method */ ShiftPosX();
    /* method */ ShiftPosY();
    /* method */ SetCenterPos();
    /* method */ SetCurrentFrame();
    /* method */ IncrCurrentFrame();
    /* method */ SetDrawSize();
    /* method */ Draw();
    /* method */ DrawScale();
    /* method */ DrawScaleX();
    /* method */ DrawScaleY();
    /* method */ DrawScaleXY();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x122A surfaceList;
    /* +0x008 */ 0x0021 (unsigned short) resId;
    /* +0x00C */ 0x0040 (float) posX;
    /* +0x010 */ 0x0040 (float) posY;
    /* +0x014 */ 0x0074 (int) width;
    /* +0x018 */ 0x0074 (int) height;
    /* +0x01C */ 0x0074 (int) drawWidth;
    /* +0x020 */ 0x0074 (int) drawHeight;
    /* +0x024 */ 0x0074 (int) currentFrame;
    /* +0x028 */ 0x0074 (int) numFrames;

};

#endif // JSPRITE_H_
