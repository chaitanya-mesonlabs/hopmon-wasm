// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: d3dframe.h
// Generated from PDB Type Stream

#ifndef D3DFRAME_H_
#define D3DFRAME_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: CD3DFramework7 (size: 68 bytes)
class CD3DFramework7 {
public:
    /* method */ CreateZBuffer();
    /* method */ CreateFullscreenBuffers();
    /* method */ CreateWindowedBuffers();
    /* method */ CreateClipperForBackBuffer();
    /* method */ CreateDirectDraw();
    /* method */ CreateDirect3D();
    /* method */ CreateEnvironment();
    /* method */ GetDirectDraw();
    /* method */ GetDirect3D();
    /* method */ GetD3DDevice();
    /* method */ GetFrontBuffer();
    /* method */ GetBackBuffer();
    /* method */ GetRenderSurface();
    /* method */ GetRenderSurfaceLeft();
    /* method */ RestoreSurfaces();
    /* method */ ShowFrame();
    /* method */ FlipToGDISurface();
    /* method */ IsFullscreen();
    /* method */ IsStereo();
    /* method */ Move();
    /* method */ Initialize();
    /* method */ DestroyObjects();
    /* method */ CD3DFramework7();
    /* method */ ~CD3DFramework7();
    /* method */ GetRenderWidth();
    /* method */ GetRenderHeight();
    /* method */ __vecDelDtor();

public:
    /* +0x000 */ 0x10DF m_hWnd;
    /* +0x004 */ 0x0074 (int) m_bIsFullscreen;
    /* +0x008 */ 0x0074 (int) m_bIsStereo;
    /* +0x00C */ 0x0022 (unsigned long) m_dwRenderWidth;
    /* +0x010 */ 0x0022 (unsigned long) m_dwRenderHeight;
    /* +0x014 */ 0x108F m_rcScreenRect;
    /* +0x024 */ 0x152E m_pDD;
    /* +0x028 */ 0x12B8 m_pD3D;
    /* +0x02C */ 0x157C m_pd3dDevice;
    /* +0x030 */ 0x11B9 m_pddsFrontBuffer;
    /* +0x034 */ 0x11B9 m_pddsBackBuffer;
    /* +0x038 */ 0x11B9 m_pddsBackBufferLeft;
    /* +0x03C */ 0x11B9 m_pddsZBuffer;
    /* +0x040 */ 0x0022 (unsigned long) m_dwDeviceMemType;

};

#endif // D3DFRAME_H_
