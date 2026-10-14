// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JList.h
// Generated from PDB Type Stream

#ifndef JLIST_H_
#define JLIST_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JBaseList (size: 12 bytes)
class JBaseList {
public:
    /* method */ JBaseList();
    virtual /* method */ ~JBaseList();
    /* method */ GetData();
    /* method */ Count();
    /* method */ IsEmpty();
    /* method */ Append();
    /* method */ InsertBefore();
    /* method */ Remove();
    /* method */ Empty();
    /* method */ GetFirstItem();
    /* method */ GetLastItem();
    /* method */ GetItemAt();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x0022 (unsigned long) count;
    /* +0x008 */ 0x112F firstItem;

};

// Class: JNumber (size: 28 bytes)
class JNumber {
public:
    /* method */ JNumber();
    virtual /* method */ ~JNumber();
    /* method */ SetPosition();
    /* method */ SetDisplayZero();
    /* method */ SetNumDigits();
    /* method */ SetNumber();
    /* method */ Draw();
    /* method */ GetPosX();
    /* method */ GetPosY();
    /* method */ GetDigitWidth();
    /* method */ GetWidth();
    /* method */ GetHeight();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x14BB numberSprite;
    /* +0x008 */ 0x0074 (int) posX;
    /* +0x00C */ 0x0074 (int) posY;
    /* +0x010 */ 0x0074 (int) displayZero;
    /* +0x014 */ 0x0074 (int) numDigits;
    /* +0x018 */ 0x0074 (int) number;

};

#endif // JLIST_H_
