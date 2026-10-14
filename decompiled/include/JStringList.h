// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JStringList.h
// Generated from PDB Type Stream

#ifndef JSTRINGLIST_H_
#define JSTRINGLIST_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JStringList (size: 16 bytes)
class JStringList {
public:
    /* method */ JStringList();
    virtual /* method */ ~JStringList();
    /* method */ Count();
    /* method */ IsEmpty();
    /* method */ Append();
    /* method */ Remove();
    /* method */ Empty();
    /* method */ GetString();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1499 list;

};

#endif // JSTRINGLIST_H_
