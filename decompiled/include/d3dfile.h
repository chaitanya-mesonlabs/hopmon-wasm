// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: d3dfile.h
// Generated from PDB Type Stream

#ifndef D3DFILE_H_
#define D3DFILE_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: CD3DFile (size: 4 bytes)
class CD3DFile {
public:
    /* method */ GetMeshVertices();
    /* method */ GetMeshIndices();
    /* method */ FindObject();
    /* method */ EnumObjects();
    /* method */ Scale();
    /* method */ Shift();
    /* method */ RotateX();
    /* method */ RotateY();
    /* method */ RotateZ();
    /* method */ GetBoxMin();
    /* method */ GetBoxMax();
    /* method */ LoadFromFile();
    /* method */ LoadFromResource();
    /* method */ Render();
    /* method */ CD3DFile();
    /* method */ ~CD3DFile();
    /* method */ __vecDelDtor();

public:
    /* +0x000 */ 0x18E4 m_pRoot;

};

// Class: CD3DFileObject (size: 2612 bytes)
class CD3DFileObject {
public:
    /* method */ AddNext();
    /* method */ AddChild();
    /* method */ SetName();
    /* method */ SetMatrix();
    /* method */ SetNormals();
    /* method */ SetTextureCoords();
    /* method */ SetMaterialData();
    /* method */ AddFace();
    /* method */ ComputeNormals();
    /* method */ SetMeshGeometry();
    /* method */ GetName();
    /* method */ GetNext();
    /* method */ GetChild();
    /* method */ GetMatrix();
    /* method */ GetMeshGeometry();
    /* method */ Render();
    /* method */ EnumObjects();
    /* method */ CD3DFileObject();
    /* method */ ~CD3DFileObject();
    /* method */ __vecDelDtor();

public:
    /* +0x000 */ 0x18A2 m_strName;
    /* +0x050 */ 0x18E4 m_pNext;
    /* +0x054 */ 0x18E4 m_pChild;
    /* +0x058 */ 0x12C5 m_mat;
    /* +0x098 */ 0x0074 (int) m_bHasMeshData;
    /* +0x09C */ 0x0022 (unsigned long) m_dwNumVertices;
    /* +0x0A0 */ 0x18E6 m_pVertices;
    /* +0x0A4 */ 0x0022 (unsigned long) m_dwNumIndices;
    /* +0x0A8 */ 0x0421 (unsigned short*) m_pIndices;
    /* +0x0AC */ 0x0022 (unsigned long) m_dwNumMaterials;
    /* +0x0B0 */ 0x1948 m_Material;
    /* +0xA30 */ 0x0074 (int) m_bHasAlpha;

};

#endif // D3DFILE_H_
