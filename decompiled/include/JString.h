// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JString.h
// Generated from PDB Type Stream

#ifndef JSTRING_H_
#define JSTRING_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JString (size: 8 bytes)
class JString {
public:
    enum StripType { /* values in PDB enum */ };

public:
    /* method */ JString();
    /* method */ operator=();
    /* method */ operator+=();
    virtual /* method */ ~JString();
    /* method */ c_str();
    /* method */ Length();
    /* method */ FindChar();
    /* method */ IsEqualTo();
    /* method */ ExtractString();
    /* method */ ReplaceChar();
    /* method */ ToUpper();
    /* method */ ToLower();
    /* method */ Strip();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x0470 (char*) buffer;

};

#endif // JSTRING_H_
