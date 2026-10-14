// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: XTitle.h
// Generated from PDB Type Stream

#ifndef XTITLE_H_
#define XTITLE_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: XTitleObject (size: 76 bytes)
class XTitleObject {
public:
    /* method */ XTitleObject();
    virtual /* method */ ~XTitleObject();
    virtual /* method */ ProcessFrame();
    virtual /* method */ Render();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x020 */ 0x14C6 camera;
    /* +0x024 */ 0x15CA pac;
    /* +0x028 */ 0x14C7 background;
    /* +0x02C */ 0x14BB cursorLeft;
    /* +0x030 */ 0x14BB cursorRight;
    /* +0x034 */ 0x15CB menuItems;
    /* +0x03C */ 0x14BB textHopmon;
    /* +0x040 */ 0x14BB textCopyright;
    /* +0x044 */ 0x14BB textUnreg;
    /* +0x048 */ 0x0074 (int) cursorPos;

};

// Class: XTitleBackground (size: 20 bytes)
class XTitleBackground {
public:
    /* method */ XTitleBackground();
    virtual /* method */ ~XTitleBackground();
    /* method */ ProcessFrame();
    /* method */ Render();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1003 app;
    /* +0x008 */ 0x16F2 backUpper;
    /* +0x00C */ 0x16F2 backLower;
    /* +0x010 */ 0x0040 (float) textureOffset;

};

// Class: XLogoObject (size: 44 bytes)
class XLogoObject {
public:
    /* method */ XLogoObject();
    virtual /* method */ ~XLogoObject();
    virtual /* method */ ProcessFrame();
    virtual /* method */ Render();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x020 */ 0x14C6 camera;
    /* +0x024 */ 0x14BB logo;
    /* +0x028 */ 0x16F2 backWhite;

};

// Class: XEndingObject (size: 136 bytes)
class XEndingObject {
public:
    /* method */ XEndingObject();
    virtual /* method */ ~XEndingObject();
    virtual /* method */ ProcessFrame();
    virtual /* method */ Render();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x020 */ 0x14C6 camera;
    /* +0x024 */ 0x1645 chara;
    /* +0x04C */ 0x14C7 background;
    /* +0x050 */ 0x14BB textCongra;
    /* +0x054 */ 0x14BB textStaff;
    /* +0x058 */ 0x14BB textCopyright;
    /* +0x05C */ 0x0074 (int) charaIndex;
    /* +0x060 */ 0x1646 charaMaxScale;

};

// Class: XSelectLevelObject (size: 96 bytes)
class XSelectLevelObject {
public:
    /* method */ XSelectLevelObject();
    virtual /* method */ ~XSelectLevelObject();
    virtual /* method */ ProcessFrame();
    virtual /* method */ Render();
    /* method */ CreatePreviewMap();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x020 */ 0x14C6 camera;
    /* +0x024 */ 0x14C7 background;
    /* +0x028 */ 0x14C8 map;
    /* +0x02C */ 0x14BB cursorLeft;
    /* +0x030 */ 0x14BB cursorRight;
    /* +0x034 */ 0x14BB cursor2Left;
    /* +0x038 */ 0x14BB cursor2Right;
    /* +0x03C */ 0x14C9 menuItems;
    /* +0x048 */ 0x14BB textUnreg;
    /* +0x04C */ 0x14BB textLevel;
    /* +0x050 */ 0x14BB levelLED;
    /* +0x054 */ 0x14CA numLevel;
    /* +0x058 */ 0x0074 (int) cursorPos;
    /* +0x05C */ 0x0074 (int) inSelectLevel;

};

// Class: XRegisterInfoObject (size: 64 bytes)
class XRegisterInfoObject {
public:
    /* method */ XRegisterInfoObject();
    virtual /* method */ ~XRegisterInfoObject();
    virtual /* method */ ProcessFrame();
    virtual /* method */ Render();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x020 */ 0x14C6 camera;
    /* +0x024 */ 0x14C7 background;
    /* +0x028 */ 0x14BB cursorLeft;
    /* +0x02C */ 0x14BB cursorRight;
    /* +0x030 */ 0x14BB menuBack;
    /* +0x034 */ 0x14BB screenShot1;
    /* +0x038 */ 0x14BB screenShot2;
    /* +0x03C */ 0x14BB regInfo;

};

#endif // XTITLE_H_
