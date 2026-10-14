// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JWinReg.h
// Generated from PDB Type Stream

#ifndef JWINREG_H_
#define JWINREG_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JWinReg (size: 8 bytes)
class JWinReg {
public:
    /* method */ JWinReg();
    virtual /* method */ ~JWinReg();
    /* method */ Create();
    /* method */ Open();
    /* method */ Close();
    /* method */ SetString();
    /* method */ GetString();
    /* method */ SetBinary();
    /* method */ GetBinary();
    /* method */ SetByte();
    /* method */ GetByte();
    /* method */ SetWord();
    /* method */ GetWord();
    /* method */ SetDWord();
    /* method */ GetDWord();
    /* method */ DeleteValue();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1A19 currentKey;

};

#endif // JWINREG_H_
