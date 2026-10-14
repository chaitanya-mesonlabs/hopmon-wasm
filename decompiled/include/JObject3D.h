// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: JObject3D.h
// Generated from PDB Type Stream

#ifndef JOBJECT3D_H_
#define JOBJECT3D_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: JObject3DBase (size: 40 bytes)
class JObject3DBase {
public:
    /* method */ JObject3DBase();
    virtual /* method */ ~JObject3DBase();
    /* method */ SetWorldPos();
    /* method */ ShiftWorldPos();
    /* method */ ShiftWorldPos_OnGround();
    /* method */ GetWorldPos();
    /* method */ SetCollisionRadius();
    /* method */ CheckCollisionRadius();
    /* method */ ScaleTo();
    /* method */ RotateTo();
    virtual /* method */ Shift();
    virtual /* method */ ScaleBy();
    virtual /* method */ RotateBy();
    virtual /* method */ GetBox();
    virtual /* method */ Render();
    virtual /* method */ _SetRenderState();
    virtual /* method */ _ResetRenderState();
    /* method */ _SetWorldTransform();
    /* method */ _ResetWorldTransform();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x1447 app;
    /* +0x008 */ 0x12F3 worldPos;
    /* +0x014 */ 0x0040 (float) collisionRadius;
    /* +0x018 */ 0x0040 (float) rotatedAngleX;
    /* +0x01C */ 0x0040 (float) rotatedAngleY;
    /* +0x020 */ 0x0040 (float) rotatedAngleZ;
    /* +0x024 */ 0x0040 (float) scaledSize;

};

// Class: JObject3D (size: 136 bytes)
class JObject3D {
public:
    enum FILTER_STATE { /* values in PDB enum */ };
    enum ALPHA_STATE { /* values in PDB enum */ };

public:
    /* method */ JObject3D();
    virtual /* method */ ~JObject3D();
    virtual /* method */ Shift();
    virtual /* method */ ScaleBy();
    virtual /* method */ RotateBy();
    virtual /* method */ GetBox();
    virtual /* method */ Render();
    virtual /* method */ SetTexture();
    /* method */ SetColor();
    /* method */ SetAlpha();
    /* method */ SetAlphaFactor();
    /* method */ GetVertexCount();
    /* method */ GetVertexAt();
    /* method */ SetVertexAt();
    /* method */ GetIndexCount();
    /* method */ GetIndexAt();
    /* method */ SetIndexAt();
    /* method */ UsePerspective();
    /* method */ SetAlphaState();
    /* method */ SetFilterState();
    virtual /* method */ _SetRenderState();
    virtual /* method */ _ResetRenderState();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x028 */ 0x0022 (unsigned long) vertexCount;
    /* +0x02C */ 0x15BF vertexList;
    /* +0x030 */ 0x0022 (unsigned long) indexCount;
    /* +0x034 */ 0x0421 (unsigned short*) indexList;
    /* +0x038 */ 0x0021 (unsigned short) textureResId;
    /* +0x03C */ 0x0022 (unsigned long) stateLighting;
    /* +0x040 */ 0x0022 (unsigned long) statePerspective;
    /* +0x044 */ 0x0022 (unsigned long) stateAlphaBlend;
    /* +0x048 */ 0x0022 (unsigned long) stateSrcBlend;
    /* +0x04C */ 0x0022 (unsigned long) stateDestBlend;
    /* +0x050 */ 0x0022 (unsigned long) stateSpecular;
    /* +0x054 */ 0x0022 (unsigned long) stateZWriteEnable;
    /* +0x058 */ 0x0022 (unsigned long) stateColorOp;
    /* +0x05C */ 0x0022 (unsigned long) stateColorArg1;
    /* +0x060 */ 0x0022 (unsigned long) stateColorArg2;
    /* +0x064 */ 0x0022 (unsigned long) stateAlphaOp;
    /* +0x068 */ 0x0022 (unsigned long) stateAlphaArg1;
    /* +0x06C */ 0x0022 (unsigned long) stateAlphaArg2;
    /* +0x070 */ 0x0022 (unsigned long) stateMinFilter;
    /* +0x074 */ 0x0022 (unsigned long) stateMagFilter;
    /* +0x078 */ 0x0022 (unsigned long) stateMipFilter;
    /* +0x07C */ 0x0074 (int) usePerspective;
    /* +0x080 */ 0x15A2 alphaState;
    /* +0x084 */ 0x15A0 filterState;

};

// Class: JObject3DX (size: 92 bytes)
class JObject3DX {
public:
    /* method */ JObject3DX();
    virtual /* method */ ~JObject3DX();
    virtual /* method */ Shift();
    virtual /* method */ ScaleBy();
    virtual /* method */ RotateBy();
    virtual /* method */ GetBox();
    virtual /* method */ Render();
    /* method */ AppendExtraFrame();
    /* method */ SetCurrentFrame();
    /* method */ SetFlatShade();
    virtual /* method */ _SetRenderState();
    virtual /* method */ _ResetRenderState();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x028 */ 0x0074 (int) currentFrame;
    /* +0x02C */ 0x172C objArray;
    /* +0x054 */ 0x0074 (int) flatShade;
    /* +0x058 */ 0x0022 (unsigned long) stateShadeMode;

};

// Class: JObject3D_Particle (size: 136 bytes)
class JObject3D_Particle {
public:
    /* method */ JObject3D_Particle();
    virtual /* method */ ~JObject3D_Particle();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: JObject3D_Rect (size: 136 bytes)
class JObject3D_Rect {
public:
    /* method */ JObject3D_Rect();
    virtual /* method */ ~JObject3D_Rect();
    virtual /* method */ SetTexture();
    virtual /* method */ Render2();
    /* method */ _SetWorldTransform2();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: JObject3D_Shadow (size: 136 bytes)
class JObject3D_Shadow {
public:
    /* method */ JObject3D_Shadow();
    virtual /* method */ ~JObject3D_Shadow();
    /* method */ operator=();
    virtual /* method */ __vecDelDtor();

};

// Class: JObject3DList (size: 8 bytes)
class JObject3DList {
public:
    /* method */ JObject3DList();
    virtual /* method */ ~JObject3DList();
    /* method */ Append();
    /* method */ Empty();
    /* method */ Remove();
    /* method */ Count();
    /* method */ GetAt();
    /* method */ Render();
    /* method */ operator=();
    /* method */ __local_vftable_ctor_closure();
    virtual /* method */ __vecDelDtor();

public:
    /* +0x004 */ 0x165D list;

};

#endif // JOBJECT3D_H_
