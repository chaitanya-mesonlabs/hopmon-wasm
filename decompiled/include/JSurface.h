// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JSurface.h
// Generated from PDB Type Stream

#ifndef JSURFACE_H_
#define JSURFACE_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JSurface (size: 32 bytes)
class JSurface {
public:
    /* method */ JSurface();
    virtual /* method */ ~JSurface();
    /* method */ GetResID();
    /* method */ GetDDSurface();
    /* method */ GetWidth();
    /* method */ GetHeight();
    /* method */ UseColorKey();
    /* method */ SetColorKey();
    /* method */ Restore();
    /* method */ Invalidate();
    /* method */ _Create();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1447 app;
    /* +0x008 */ 0x0021 (unsigned short) resId;
    /* +0x00C */ 0x11B9 lpSurface;
    /* +0x010 */ 0x0074 (int) width;
    /* +0x014 */ 0x0074 (int) height;
    /* +0x018 */ 0x0074 (int) useColorKey;
    /* +0x01C */ 0x0022 (unsigned long) colorKey;

};

// Class: JSurfaceList (size: 12 bytes)
class JSurfaceList {
public:
    /* method */ JSurfaceList();
    virtual /* method */ ~JSurfaceList();
    /* method */ CreateSurface();
    /* method */ DestroySurface();
    /* method */ DestroyAllSurfaces();
    /* method */ GetByResId();
    /* method */ GetByIndex();
    /* method */ RestoreAllSurfaces();
    /* method */ InvalidateAllSurfaces();
    /* method */ FindIndexOfResId();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1447 app;
    /* +0x008 */ 0x165D list;

};

#endif // JSURFACE_H_
