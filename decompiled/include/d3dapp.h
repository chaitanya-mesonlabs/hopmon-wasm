// Recovered Header Definition from Hopmon.pdb (MSVC 7.0 / VS .NET 2002)
// Header: d3dapp.h
// Generated from PDB Type Stream

#ifndef D3DAPP_H_
#define D3DAPP_H_

#include <windows.h>
#include <d3d.h>
#include <dinput.h>
#include <dsound.h>

// Class: CD3DApplication (size: 424 bytes)
class CD3DApplication {
public:
    /* method */ Initialize3DEnvironment();
    /* method */ Change3DEnvironment();
    /* method */ Render3DEnvironment();
    /* method */ Cleanup3DEnvironment();
    /* method */ DisplayFrameworkError();
    virtual /* method */ OneTimeSceneInit();
    virtual /* method */ InitDeviceObjects();
    virtual /* method */ DeleteDeviceObjects();
    virtual /* method */ Render();
    virtual /* method */ FrameMove();
    virtual /* method */ RestoreSurfaces();
    virtual /* method */ FinalCleanup();
    virtual /* method */ OnQuerySuspend();
    virtual /* method */ OnResumeSuspend();
    /* method */ SetAppLeftViewMatrix();
    /* method */ SetAppRightViewMatrix();
    /* method */ SetAppViewMatrix();
    /* method */ SetViewParams();
    /* method */ UpdateStats();
    /* method */ OutputText();
    virtual /* method */ Create();
    virtual /* method */ Run();
    virtual /* method */ MsgProc();
    virtual /* method */ Pause();
    /* method */ CD3DApplication();
    /* method */ GetHWND();
    /* method */ GetD3DDevice();
    /* method */ GetDDraw();
    /* method */ GetBackBuffer();
    /* method */ GetScreenWidth();
    /* method */ GetScreenHeight();
    /* method */ GetFPS();
    /* method */ DisplayFPS();
    /* method */ operator=();

public:
    /* +0x004 */ 0x15D3 m_pFramework;
    /* +0x008 */ 0x0074 (int) m_bActive;
    /* +0x00C */ 0x0074 (int) m_bReady;
    /* +0x010 */ 0x0074 (int) m_bFrameMoving;
    /* +0x014 */ 0x0074 (int) m_bSingleStep;
    /* +0x018 */ 0x0022 (unsigned long) m_dwBaseTime;
    /* +0x01C */ 0x0022 (unsigned long) m_dwStopTime;
    /* +0x020 */ 0x0022 (unsigned long) m_dwLastFrameTime;
    /* +0x024 */ 0x0040 (float) m_fFPS;
    /* +0x028 */ 0x10DF m_hWnd;
    /* +0x02C */ 0x15DA m_pDeviceInfo;
    /* +0x030 */ 0x152E m_pDD;
    /* +0x034 */ 0x12B8 m_pD3D;
    /* +0x038 */ 0x157C m_pd3dDevice;
    /* +0x03C */ 0x11B9 m_pddsRenderTarget;
    /* +0x040 */ 0x11B9 m_pddsRenderTargetLeft;
    /* +0x044 */ 0x11CB m_ddsdRenderTarget;
    /* +0x0C0 */ 0x0470 (char*) m_strWinClassName;
    /* +0x0C4 */ 0x0470 (char*) m_strWindowTitle;
    /* +0x0C8 */ 0x0074 (int) m_bAppUseZBuffer;
    /* +0x0CC */ 0x0074 (int) m_bAppUseStereo;
    /* +0x0D0 */ 0x0074 (int) m_bShowStats;
    /* +0x0D4 */ 0x0074 (int) m_bUseAccelKeys;
    /* +0x0D8 */ 0x0074 (int) m_bStartHEL;
    /* +0x0DC */ 0x0074 (int) m_bStartFullScreen;
    /* +0x0E0 */ 0x0021 (unsigned short) m_wScreenWidth;
    /* +0x0E2 */ 0x0021 (unsigned short) m_wScreenHeight;
    /* +0x0E4 */ 0x15DC m_fnConfirmDevice;
    /* +0x0E8 */ 0x12C5 m_matLeftView;
    /* +0x128 */ 0x12C5 m_matRightView;
    /* +0x168 */ 0x12C5 m_matView;

};

#endif // D3DAPP_H_
