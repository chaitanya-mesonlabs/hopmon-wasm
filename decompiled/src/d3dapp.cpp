// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: d3dapp.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "d3dapp.h"

// ============================================================================
// Address: 0x402300 | Symbol: CD3DApplication::Initialize3DEnvironment
// ============================================================================
int CD3DApplication__Initialize3DEnvironment(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int *in_ECX;
  int local_10;
  
  if (*(int *)(in_ECX[0xb] + 0x498) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 2;
  }
  if (in_ECX[0x32] == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = 4;
  }
  local_10 = CD3DFramework7__Initialize
                       (in_ECX[10],*(undefined4 *)(in_ECX[0xb] + 0x11c),
                        *(undefined4 *)(in_ECX[0xb] + 0x28),in_ECX[0xb] + 0x418,
                        *(int *)(in_ECX[0xb] + 0x494) == 0 | bVar2 | bVar1);
  if (-1 < local_10) {
    iVar3 = CD3DFramework7__GetDirectDraw();
    in_ECX[0xc] = iVar3;
    iVar3 = CD3DFramework7__GetDirect3D();
    in_ECX[0xd] = iVar3;
    iVar3 = CD3DFramework7__GetD3DDevice();
    in_ECX[0xe] = iVar3;
    iVar3 = CD3DFramework7__GetRenderSurface();
    in_ECX[0xf] = iVar3;
    iVar3 = CD3DFramework7__GetRenderSurfaceLeft();
    in_ECX[0x10] = iVar3;
    in_ECX[0x11] = 0x7c;
    (**(code **)(*(int *)in_ECX[0xf] + 0x58))(in_ECX[0xf],in_ECX + 0x11);
    local_10 = (**(code **)(*in_ECX + 4))();
    if (-1 < local_10) {
      return 0;
    }
    (**(code **)(*in_ECX + 8))();
    CD3DFramework7__DestroyObjects();
  }
  if (*(int *)(in_ECX[0xb] + 0x118) != 0) {
    CD3DApplication__DisplayFrameworkError(local_10,2);
    D3DEnum_SelectDefaultDevice(in_ECX + 0xb,3);
    local_10 = CD3DApplication__Initialize3DEnvironment();
  }
  return local_10;
}

// ============================================================================
// Address: 0x4024c0 | Symbol: CD3DApplication::Change3DEnvironment
// ============================================================================
int CD3DApplication__Change3DEnvironment(void)

{
  int iVar1;
  DWORD DVar2;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 8))();
  iVar1 = CD3DFramework7__DestroyObjects();
  if (iVar1 < 0) {
    CD3DApplication__DisplayFrameworkError(iVar1,1);
    SendMessageA((HWND)in_ECX[10],0x10,0,0);
  }
  else {
    if (DAT_00486000 != *(int *)(in_ECX[0xb] + 0x494)) {
      if (*(int *)(in_ECX[0xb] + 0x494) == 0) {
        DAT_00487f2c = GetWindowLongA((HWND)in_ECX[10],-0x10);
        GetWindowRect((HWND)in_ECX[10],(LPRECT)&DAT_00487f30);
        SetWindowLongA((HWND)in_ECX[10],-0x10,-0x6ff80000);
      }
      else {
        SetWindowLongA((HWND)in_ECX[10],-0x10,DAT_00487f2c);
        SetWindowPos((HWND)in_ECX[10],(HWND)0xfffffffe,DAT_00487f30,DAT_00487f34,
                     DAT_00487f38 - DAT_00487f30,DAT_00487f3c - DAT_00487f34,0x40);
      }
      DAT_00486000 = *(int *)(in_ECX[0xb] + 0x494);
    }
    iVar1 = CD3DApplication__Initialize3DEnvironment();
    if (iVar1 < 0) {
      CD3DApplication__DisplayFrameworkError(iVar1,1);
      SendMessageA((HWND)in_ECX[10],0x10,0,0);
    }
    else {
      if (in_ECX[4] == 0) {
        in_ECX[5] = 1;
        DVar2 = timeGetTime();
        in_ECX[6] = (DVar2 - in_ECX[7]) + in_ECX[6];
        DVar2 = timeGetTime();
        in_ECX[7] = DVar2;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}

// ============================================================================
// Address: 0x402650 | Symbol: CD3DApplication::Render3DEnvironment
// ============================================================================
int CD3DApplication__Render3DEnvironment(void)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  uint uVar4;
  
  DVar1 = timeGetTime();
  if (DVar1 < (uint)in_ECX[8]) {
    in_ECX[8] = DVar1;
  }
  uVar4 = DVar1 - in_ECX[8];
  if (uVar4 < 10) {
    iVar2 = 0;
  }
  else {
    uVar3 = uVar4 / 10;
    in_ECX[8] = DVar1 - uVar4 % 10;
    iVar2 = (**(code **)(*(int *)in_ECX[0xc] + 0x68))(in_ECX[0xc],uVar3);
    if (iVar2 < 0) {
      if ((iVar2 == -0x7789ff1f) || (iVar2 == -0x7789fdbb)) {
        iVar2 = 0;
      }
      else if ((iVar2 == -0x7789fdb5) && (*(int *)(in_ECX[0xb] + 0x494) != 0)) {
        iVar2 = CD3DApplication__Change3DEnvironment();
      }
    }
    else {
      if ((in_ECX[4] != 0) || (in_ECX[5] != 0)) {
        iVar2 = (**(code **)(*in_ECX + 0x10))(uVar3);
        if (iVar2 < 0) {
          return iVar2;
        }
        in_ECX[5] = 0;
      }
      if (((in_ECX[0x33] == 0) || (*(int *)(in_ECX[0xb] + 0x498) == 0)) ||
         (*(int *)(in_ECX[0xb] + 0x494) != 0)) {
        if (in_ECX[0x33] != 0) {
          (**(code **)(*(int *)in_ECX[0xe] + 0x2c))(in_ECX[0xe],2,in_ECX + 0x5a);
        }
        iVar2 = (**(code **)(*in_ECX + 0xc))();
      }
      else {
        (**(code **)(*(int *)in_ECX[0xe] + 0x2c))(in_ECX[0xe],2,in_ECX + 0x3a);
        iVar2 = (**(code **)(*(int *)in_ECX[0xe] + 0x20))(in_ECX[0xe],in_ECX[0x10],0);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = (**(code **)(*in_ECX + 0xc))();
        if (iVar2 < 0) {
          return iVar2;
        }
        (**(code **)(*(int *)in_ECX[0xe] + 0x2c))(in_ECX[0xe],2,in_ECX + 0x4a);
        iVar2 = (**(code **)(*(int *)in_ECX[0xe] + 0x20))(in_ECX[0xe],in_ECX[0xf],0);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = (**(code **)(*in_ECX + 0xc))();
      }
      if (-1 < iVar2) {
        CD3DApplication__UpdateStats();
        iVar2 = CD3DFramework7__ShowFrame();
        if (iVar2 < 0) {
          if (iVar2 != -0x7789fe3e) {
            return iVar2;
          }
          CD3DFramework7__RestoreSurfaces();
          (**(code **)(*in_ECX + 0x14))();
        }
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

// ============================================================================
// Address: 0x402900 | Symbol: CD3DApplication::Cleanup3DEnvironment
// ============================================================================
void CD3DApplication__Cleanup3DEnvironment(void)

{
  int *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*in_ECX + 8))();
    if (in_ECX[1] != 0) {
      if ((shared_ptr<__ExceptionPtr> *)in_ECX[1] != (shared_ptr<__ExceptionPtr> *)0x0) {
        std::shared_ptr<__ExceptionPtr>::CD3DFramework7__((shared_ptr<__ExceptionPtr> *)in_ECX[1],1)
        ;
      }
      in_ECX[1] = 0;
    }
    (**(code **)(*in_ECX + 0x18))();
  }
  D3DEnum_FreeResources();
  return;
}

// ============================================================================
// Address: 0x402990 | Symbol: CD3DApplication::DisplayFrameworkError
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CD3DApplication__DisplayFrameworkError(int param_1,int param_2)

{
  int in_ECX;
  CHAR local_208 [512];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  if (param_1 < -0x7dffffff) {
    if (param_1 == -0x7e000000) {
      lstrcpyA(local_208,
               "Generic initialization error.\n\nEnable debug output for detailed information.");
      goto LAB_00402c78;
    }
    if (param_1 < -0x7efffffe) {
      if (param_1 == -0x7effffff) {
        lstrcpyA(local_208,"Could not create DirectDraw!");
        goto LAB_00402c78;
      }
      if (param_1 == -0x7ff8fff2) {
        lstrcpyA(local_208,"Not enough memory!");
        goto LAB_00402c78;
      }
    }
    else {
      if (param_1 == -0x7efffffe) {
        lstrcpyA(local_208,
                 "Enumeration failed. Your system may be in an\nunstable state and need to be rebooted"
                );
        goto LAB_00402c78;
      }
      if (param_1 == -0x7efffffd) {
        lstrcpyA(local_208,
                 "Could not find any compatible devices.\n\nTry enabling the reference rasterizer using\nEnableRefRast.reg."
                );
        goto LAB_00402c78;
      }
      if (param_1 == -0x7efffffc) {
        lstrcpyA(local_208,"Could not find any compatible Direct3D\ndevices.");
        goto LAB_00402c78;
      }
    }
  }
  else if (param_1 < -0x7789fe83) {
    if (param_1 == -0x7789fe84) {
      lstrcpyA(local_208,"There was insufficient video memory to use the\nhardware device.");
      goto LAB_00402c78;
    }
    switch(param_1) {
    case -0x7dffffff:
      lstrcpyA(local_208,"No DirectDraw");
      break;
    case -0x7dfffffe:
      lstrcpyA(local_208,"Could not set Cooperative Level");
      break;
    case -0x7dfffffd:
      lstrcpyA(local_208,"No Direct3D");
      break;
    case -0x7dfffffc:
      lstrcpyA(local_208,"Could not create the Direct3DDevice object.");
      if (param_2 == 2) {
        lstrcatA(local_208,
                 "\nThe 3D hardware chipset may not support\nrendering in the current display mode."
                );
      }
      break;
    case -0x7dfffffb:
      lstrcpyA(local_208,"No ZBuffer");
      break;
    case -0x7dfffffa:
      lstrcpyA(local_208,
               "Invalid Z-buffer depth. Try switching modes\nfrom 16- to 32-bit (or vice versa)");
      break;
    case -0x7dfffff9:
      lstrcpyA(local_208,"No Viewport");
      break;
    case -0x7dfffff8:
      lstrcpyA(local_208,"No primary");
      break;
    case -0x7dfffff7:
      lstrcpyA(local_208,"No Clipper");
      break;
    case -0x7dfffff6:
      lstrcpyA(local_208,"Bad display mode");
      break;
    case -0x7dfffff5:
      lstrcpyA(local_208,"No backbuffer");
      break;
    case -0x7dfffff4:
      lstrcpyA(local_208,
               "A DDraw object has a non-zero reference\ncount (meaning it was not properly cleaned up)."
              );
      break;
    case -0x7dfffff3:
      lstrcpyA(local_208,"No render target");
      break;
    case -0x7dfffff2:
      lstrcpyA(local_208,
               "This game requires a 16-bit (or higher) display mode\nto run in a window.\n\nPlease switch your desktop settings accordingly."
              );
      break;
    default:
      goto switchD_00402a71_default;
    }
    goto LAB_00402c78;
  }
switchD_00402a71_default:
  lstrcpyA(local_208,"Generic application error.\n\nEnable debug output for detailed information.");
LAB_00402c78:
  if (param_2 == 1) {
    lstrcatA(local_208,"\n\nThis game will now exit.");
    MessageBoxA((HWND)0x0,local_208,*(LPCSTR *)(in_ECX + 0xc4),0x10);
  }
  else {
    if (param_2 == 2) {
      lstrcatA(local_208,"\n\nSwitching to software rasterizer.");
    }
    MessageBoxA((HWND)0x0,local_208,*(LPCSTR *)(in_ECX + 0xc4),0x30);
  }
  return;
}

// ============================================================================
// Address: 0x402d30 | Symbol: CD3DApplication::OnQuerySuspend
// ============================================================================
undefined4 CD3DApplication__OnQuerySuspend(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x30))(1);
  return 1;
}

// ============================================================================
// Address: 0x402d60 | Symbol: CD3DApplication::OnResumeSuspend
// ============================================================================
undefined4 CD3DApplication__OnResumeSuspend(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x30))(0);
  return 1;
}

// ============================================================================
// Address: 0x402d90 | Symbol: CD3DApplication::SetViewParams
// ============================================================================
void CD3DApplication__SetViewParams
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_50 [12];
  undefined1 local_44 [12];
  undefined1 local_38 [12];
  undefined1 local_2c [12];
  undefined1 local_20 [12];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  operator-(&local_14,param_2,param_1);
  puVar1 = (undefined4 *)CrossProduct(local_38,&local_14,param_3);
  local_14 = *puVar1;
  local_10 = puVar1[1];
  local_c = puVar1[2];
  uVar2 = Normalize(local_44,&local_14,param_4);
  puVar1 = (undefined4 *)FUN_00403fb0(local_50,uVar2);
  local_14 = *puVar1;
  local_10 = puVar1[1];
  local_c = puVar1[2];
  FUN_00404050(local_20,param_1,&local_14);
  operator-(local_2c,param_1,&local_14);
  D3DUtil_SetViewMatrix(local_8 + 0xe8,local_20,param_2,param_3);
  D3DUtil_SetViewMatrix(local_8 + 0x128,local_2c,param_2,param_3);
  D3DUtil_SetViewMatrix(local_8 + 0x168,param_1,param_2,param_3);
  return;
}

// ============================================================================
// Address: 0x402ea0 | Symbol: CD3DApplication::UpdateStats
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CD3DApplication__UpdateStats(void)

{
  DWORD DVar1;
  int in_ECX;
  float fVar2;
  undefined1 local_58 [80];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  DVar1 = timeGetTime();
  fVar2 = (float)((double)(int)DVar1 + (double)(&DAT_00473840)[-((int)DVar1 >> 0x1f)]) * 0.001;
  DAT_00487f48 = DAT_00487f48 + 1;
  if (1.0 < fVar2 - _DAT_00487f44) {
    *(float *)(in_ECX + 0x24) =
         (float)((double)DAT_00487f48 + (double)(&DAT_00473840)[-(DAT_00487f48 >> 0x1f)]) /
         (fVar2 - _DAT_00487f44);
    DAT_00487f48 = 0;
    _DAT_00487f44 = fVar2;
  }
  if (*(int *)(in_ECX + 0xd0) != 0) {
    sprintf(local_58,"%7.02f fps (%dx%dx%d)",(double)*(float *)(in_ECX + 0x24),
            *(undefined4 *)(in_ECX + 0x50),*(undefined4 *)(in_ECX + 0x4c),
            *(undefined4 *)(in_ECX + 0x98));
    CD3DApplication__OutputText(0,0,local_58);
  }
  return;
}

// ============================================================================
// Address: 0x402fd0 | Symbol: CD3DApplication::OutputText
// ============================================================================
void CD3DApplication__OutputText(int param_1,int param_2,LPCSTR param_3)

{
  int iVar1;
  UINT UVar2;
  int in_ECX;
  INT *pIVar3;
  HDC local_c;
  int local_8;
  
  local_8 = in_ECX;
  if (*(int *)(in_ECX + 0x3c) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0x44))(*(undefined4 *)(in_ECX + 0x3c),&local_c)
    ;
    if (-1 < iVar1) {
      SetTextColor(local_c,0xffff);
      SetBkMode(local_c,1);
      pIVar3 = (INT *)0x0;
      UVar2 = lstrlenA(param_3);
      ExtTextOutA(local_c,param_1,param_2,0,(RECT *)0x0,param_3,UVar2,pIVar3);
      (**(code **)(**(int **)(local_8 + 0x3c) + 0x68))(*(undefined4 *)(local_8 + 0x3c),local_c);
    }
  }
  if (*(int *)(local_8 + 0x40) != 0) {
    iVar1 = (**(code **)(**(int **)(local_8 + 0x40) + 0x44))
                      (*(undefined4 *)(local_8 + 0x40),&local_c);
    if (-1 < iVar1) {
      SetTextColor(local_c,0xff00ff);
      SetBkMode(local_c,1);
      pIVar3 = (INT *)0x0;
      UVar2 = lstrlenA(param_3);
      ExtTextOutA(local_c,param_1,param_2,0,(RECT *)0x0,param_3,UVar2,pIVar3);
      (**(code **)(**(int **)(local_8 + 0x40) + 0x68))(*(undefined4 *)(local_8 + 0x40),local_c);
    }
  }
  return;
}

// ============================================================================
// Address: 0x4030e0 | Symbol: CD3DApplication::Create
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CD3DApplication__Create(HINSTANCE param_1)

{
  int iVar1;
  HWND pHVar2;
  HMENU pHVar3;
  DWORD DVar4;
  DWORD dwStyle;
  undefined4 *in_ECX;
  uint bMenu;
  WNDCLASSA local_84;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  CMFCToolTipInfo *local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 *local_28;
  tagRECT local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470804;
  local_10 = ExceptionList;
  local_14 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = in_ECX;
  local_2c = D3DEnum_EnumerateDevices(in_ECX[0x39],local_14);
  if (local_2c < 0) {
    CD3DApplication__DisplayFrameworkError(local_2c,1);
  }
  else {
    local_34 = (uint)(local_28[0x36] != 0);
    if (local_28[0x37] == 0) {
      local_38 = 0;
    }
    else {
      local_38 = 2;
    }
    local_30 = local_34 | local_38;
    local_2c = D3DEnum_SelectDefaultDevice(local_28 + 0xb,local_30);
    if (local_2c < 0) {
      CD3DApplication__DisplayFrameworkError(local_2c,1);
    }
    else {
      iVar1 = D3DEnum_UserChangeDeviceOnDesktop(local_28 + 0xb);
      if (iVar1 < 0) {
        local_2c = -0x7fffbffb;
      }
      else {
        local_2c = (**(code **)*local_28)();
        if (local_2c < 0) {
          CD3DApplication__DisplayFrameworkError(local_2c,1);
        }
        else {
          local_3c = (CMFCToolTipInfo *)FUN_0042d23e(0x44);
          local_8 = 0;
          if (local_3c == (CMFCToolTipInfo *)0x0) {
            local_40 = 0;
          }
          else {
            local_40 = CMFCToolTipInfo::CD3DFramework7__CD3DFramework7(local_3c);
          }
          local_44 = local_40;
          local_8 = 0xffffffff;
          local_28[1] = local_40;
          if (local_40 == 0) {
            CD3DApplication__DisplayFrameworkError(0x8007000e,1);
            local_2c = -0x7ff8fff2;
          }
          else {
            local_84.style = 0;
            local_84.lpfnWndProc = WndProc;
            local_84.cbClsExtra = 0;
            local_84.cbWndExtra = 0;
            local_84.hInstance = param_1;
            local_84.hIcon = LoadIconA(param_1,(LPCSTR)0x65);
            local_84.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
            local_84.hbrBackground = GetStockObject(0);
            local_84.lpszMenuName = (LPCSTR)0x0;
            local_84.lpszClassName = (LPCSTR)local_28[0x30];
            RegisterClassA(&local_84);
            local_54 = 0x90000000;
            pHVar2 = CreateWindowExA(0,(LPCSTR)local_28[0x30],(LPCSTR)local_28[0x31],0x90000000,
                                     -0x80000000,-0x80000000,0,0,(HWND)0x0,(HMENU)0x0,param_1,
                                     (LPVOID)0x0);
            local_28[10] = pHVar2;
            UpdateWindow((HWND)local_28[10]);
            SetRect(&local_24,0,0,(uint)*(ushort *)(local_28 + 0x38),
                    (uint)*(ushort *)((int)local_28 + 0xe2));
            pHVar3 = GetMenu((HWND)local_28[10]);
            local_48 = (uint)(pHVar3 != (HMENU)0x0);
            DVar4 = GetWindowLongA((HWND)local_28[10],-0x14);
            bMenu = local_48;
            dwStyle = GetWindowLongA((HWND)local_28[10],-0x10);
            AdjustWindowRectEx(&local_24,dwStyle,bMenu,DVar4);
            local_50 = local_24.right - local_24.left;
            local_4c = local_24.bottom - local_24.top;
            iVar1 = GetSystemMetrics(0);
            local_5c = (iVar1 - local_50) / 2;
            iVar1 = GetSystemMetrics(1);
            local_58 = (iVar1 - local_4c) / 2;
            SetWindowPos((HWND)local_28[10],(HWND)0x0,local_5c,local_58,local_50,local_4c,0x54);
            local_2c = CD3DApplication__Initialize3DEnvironment();
            if (local_2c < 0) {
              CD3DApplication__DisplayFrameworkError(local_2c,1);
              CD3DApplication__Cleanup3DEnvironment();
              local_2c = -0x7fffbffb;
            }
            else {
              DVar4 = timeGetTime();
              local_28[6] = DVar4;
              DVar4 = timeGetTime();
              local_28[8] = DVar4;
              local_28[3] = 1;
              local_2c = 0;
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return local_2c;
}

// ============================================================================
// Address: 0x403460 | Symbol: CD3DApplication::Run
// ============================================================================
WPARAM CD3DApplication__Run(void)

{
  int iVar1;
  tagMSG local_34;
  int local_18;
  HACCEL local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = LoadAcceleratorsA((HINSTANCE)0x0,(LPCSTR)0x71);
  PeekMessageA(&local_34,(HWND)0x0,0,0,0);
  while (local_34.message != 0x12) {
    if (*(int *)(local_8 + 8) == 0) {
      local_c = GetMessageA(&local_34,(HWND)0x0,0,0);
    }
    else {
      local_c = PeekMessageA(&local_34,(HWND)0x0,0,0,1);
    }
    if (local_c == 0) {
      if (((*(int *)(local_8 + 8) != 0) && (*(int *)(local_8 + 0xc) != 0)) &&
         (iVar1 = CD3DApplication__Render3DEnvironment(), iVar1 < 0)) {
        DestroyWindow(*(HWND *)(local_8 + 0x28));
      }
    }
    else {
      if (*(int *)(local_8 + 0xd4) == 0) {
        local_10 = 0;
      }
      else {
        local_10 = TranslateAcceleratorA(*(HWND *)(local_8 + 0x28),local_14,&local_34);
      }
      local_18 = local_10;
      if (local_10 == 0) {
        TranslateMessage(&local_34);
        DispatchMessageA(&local_34);
      }
    }
  }
  return local_34.wParam;
}

// ============================================================================
// Address: 0x403560 | Symbol: CD3DApplication::MsgProc
// ============================================================================
LRESULT CD3DApplication__MsgProc(HWND param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  DWORD DVar2;
  HINSTANCE hInstance;
  LRESULT LVar3;
  int *in_ECX;
  LPCSTR lpTemplateName;
  code *lpDialogFunc;
  LPARAM dwInitParam;
  uint local_24;
  uint local_20;
  
  if (param_2 < 0x85) {
    if (param_2 == 0x84) {
      if (*(int *)(in_ECX[0xb] + 0x494) == 0) {
        return 1;
      }
    }
    else {
      switch(param_2) {
      case 2:
        CD3DApplication__Cleanup3DEnvironment();
        PostQuitMessage(0);
        return 0;
      case 3:
        if (((in_ECX[1] != 0) && (in_ECX[2] != 0)) &&
           ((in_ECX[3] != 0 && (*(int *)(in_ECX[0xb] + 0x494) != 0)))) {
          CD3DFramework7__Move((int)(short)param_4,(int)(short)((uint)param_4 >> 0x10));
        }
        break;
      case 5:
        if ((param_3 == 4) || (param_3 == 1)) {
          in_ECX[2] = 0;
        }
        else {
          in_ECX[2] = 1;
        }
        if (((in_ECX[2] != 0) && (in_ECX[3] != 0)) && (*(int *)(in_ECX[0xb] + 0x494) != 0)) {
          in_ECX[3] = 0;
          iVar1 = CD3DApplication__Change3DEnvironment();
          if (iVar1 < 0) {
            return 0;
          }
          in_ECX[3] = 1;
        }
        break;
      case 0xf:
        if ((in_ECX[1] != 0) && (in_ECX[3] == 0)) {
          if (*(int *)(in_ECX[0xb] + 0x494) == 0) {
            CD3DFramework7__FlipToGDISurface(1);
          }
          else {
            CD3DFramework7__ShowFrame();
          }
        }
        break;
      case 0x10:
        DestroyWindow(param_1);
        return 0;
      case 0x20:
        if (((in_ECX[2] != 0) && (in_ECX[3] != 0)) && (*(int *)(in_ECX[0xb] + 0x494) == 0)) {
          SetCursor((HCURSOR)0x0);
          return 1;
        }
        break;
      case 0x24:
        *(undefined4 *)(param_4 + 0x18) = 100;
        *(undefined4 *)(param_4 + 0x1c) = 100;
      }
    }
    goto switchD_004035a2_caseD_4;
  }
  if (0x212 < param_2) {
    if (param_2 == 0x218) {
      if (param_3 == 0) {
        LVar3 = (**(code **)(*in_ECX + 0x1c))(param_4);
        return LVar3;
      }
      if (param_3 == 7) {
        LVar3 = (**(code **)(*in_ECX + 0x20))(param_4);
        return LVar3;
      }
    }
    else if (param_2 == 0x231) {
      if (in_ECX[4] != 0) {
        DVar2 = timeGetTime();
        in_ECX[7] = DVar2;
      }
    }
    else if ((param_2 == 0x232) && (in_ECX[4] != 0)) {
      DVar2 = timeGetTime();
      in_ECX[6] = (DVar2 - in_ECX[7]) + in_ECX[6];
    }
    goto switchD_004035a2_caseD_4;
  }
  if (param_2 == 0x212) {
    (**(code **)(*in_ECX + 0x30))(0);
    goto switchD_004035a2_caseD_4;
  }
  if (param_2 != 0x111) {
    if (param_2 == 0x112) {
      if (param_3 < 0xf031) {
        if (((param_3 == 0xf030) || (param_3 == 0xf000)) || (param_3 == 0xf010)) {
LAB_0040385b:
          if (*(int *)(in_ECX[0xb] + 0x494) == 0) {
            return 1;
          }
        }
      }
      else if (param_3 == 0xf170) goto LAB_0040385b;
    }
    else if (param_2 == 0x211) {
      (**(code **)(*in_ECX + 0x30))(1);
    }
    goto switchD_004035a2_caseD_4;
  }
  switch(param_3 & 0xffff) {
  case 0x9c41:
    (**(code **)(*in_ECX + 0x30))(1);
    dwInitParam = 0;
    lpDialogFunc = AboutProc;
    lpTemplateName = (LPCSTR)0x8f;
    hInstance = (HINSTANCE)GetWindowLongA(param_1,-6);
    DialogBoxParamA(hInstance,lpTemplateName,param_1,lpDialogFunc,dwInitParam);
    (**(code **)(*in_ECX + 0x30))(0);
    LVar3 = 0;
    break;
  case 0x9c42:
    if ((in_ECX[2] != 0) && (in_ECX[3] != 0)) {
      (**(code **)(*in_ECX + 0x30))(1);
      iVar1 = D3DEnum_UserChangeDevice(in_ECX + 0xb);
      if ((-1 < iVar1) && (iVar1 = CD3DApplication__Change3DEnvironment(), iVar1 < 0)) {
        return 0;
      }
      (**(code **)(*in_ECX + 0x30))(0);
    }
    LVar3 = 0;
    break;
  case 0x9c43:
    if ((in_ECX[2] != 0) && (in_ECX[3] != 0)) {
      in_ECX[3] = 0;
      local_24 = (uint)(*(int *)(in_ECX[0xb] + 0x494) == 0);
      *(uint *)(in_ECX[0xb] + 0x494) = local_24;
      iVar1 = CD3DApplication__Change3DEnvironment();
      if (iVar1 < 0) {
        return 0;
      }
      in_ECX[3] = 1;
    }
    LVar3 = 0;
    break;
  case 0x9c44:
    local_20 = (uint)(in_ECX[4] == 0);
    in_ECX[4] = local_20;
    if (in_ECX[4] == 0) {
      DVar2 = timeGetTime();
      in_ECX[7] = DVar2;
    }
    else {
      DVar2 = timeGetTime();
      in_ECX[6] = (DVar2 - in_ECX[7]) + in_ECX[6];
    }
  default:
switchD_004035a2_caseD_4:
    LVar3 = DefWindowProcA(param_1,param_2,param_3,param_4);
    break;
  case 0x9c45:
    if (in_ECX[4] == 0) {
      DVar2 = timeGetTime();
      in_ECX[6] = (DVar2 - (in_ECX[7] + 100)) + in_ECX[6];
    }
    DVar2 = timeGetTime();
    in_ECX[7] = DVar2;
    in_ECX[4] = 0;
    in_ECX[5] = 1;
    goto switchD_004035a2_caseD_4;
  case 0x9c46:
    SendMessageA(param_1,0x10,0,0);
    LVar3 = 0;
  }
  return LVar3;
}

// ============================================================================
// Address: 0x403b30 | Symbol: CD3DApplication::Pause
// ============================================================================
void CD3DApplication__Pause(int param_1)

{
  DWORD DVar1;
  int in_ECX;
  uint local_10;
  int local_c;
  
  if (param_1 == 0) {
    local_c = -1;
  }
  else {
    local_c = 1;
  }
  DAT_00487f40 = DAT_00487f40 + local_c;
  local_10 = (uint)(DAT_00487f40 == 0);
  *(uint *)(in_ECX + 0xc) = local_10;
  if ((param_1 != 0) && (DAT_00487f40 == 1)) {
    if (*(int *)(in_ECX + 4) != 0) {
      CD3DFramework7__FlipToGDISurface(1);
    }
    if (*(int *)(in_ECX + 0x10) != 0) {
      DVar1 = timeGetTime();
      *(DWORD *)(in_ECX + 0x1c) = DVar1;
    }
  }
  if ((DAT_00487f40 == 0) && (*(int *)(in_ECX + 0x10) != 0)) {
    DVar1 = timeGetTime();
    *(DWORD *)(in_ECX + 0x18) = (DVar1 - *(int *)(in_ECX + 0x1c)) + *(int *)(in_ECX + 0x18);
  }
  return;
}

// ============================================================================
// Address: 0x403bf0 | Symbol: CD3DApplication::CD3DApplication
// ============================================================================
undefined4 * CD3DApplication__CD3DApplication(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = CD3DApplication::vftable;
  _D3DMATRIX___D3DMATRIX();
  _D3DMATRIX___D3DMATRIX();
  _D3DMATRIX___D3DMATRIX();
  in_ECX[1] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 1;
  in_ECX[5] = 0;
  in_ECX[9] = 0;
  in_ECX[0x30] = "D3D Window Class";
  in_ECX[0x31] = "D3D Application";
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  *(undefined2 *)(in_ECX + 0x38) = 0x280;
  *(undefined2 *)((int)in_ECX + 0xe2) = 0x1e0;
  in_ECX[0x39] = 0;
  DAT_00487f28 = in_ECX;
  return in_ECX;
}

// ============================================================================
// Address: 0x403d50 | Symbol: CD3DApplication::GetHWND
// ============================================================================
undefined4 CD3DApplication__GetHWND(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}

// ============================================================================
// Address: 0x403d70 | Symbol: CD3DApplication::GetD3DDevice
// ============================================================================
undefined4 CD3DApplication__GetD3DDevice(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x38);
}

// ============================================================================
// Address: 0x403d90 | Symbol: CD3DApplication::GetDDraw
// ============================================================================
undefined4 CD3DApplication__GetDDraw(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}

// ============================================================================
// Address: 0x403db0 | Symbol: CD3DApplication::GetBackBuffer
// ============================================================================
undefined4 CD3DApplication__GetBackBuffer(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3c);
}

// ============================================================================
// Address: 0x403dd0 | Symbol: CD3DApplication::GetScreenWidth
// ============================================================================
void CD3DApplication__GetScreenWidth(void)

{
  CD3DFramework7__GetRenderWidth();
  return;
}

// ============================================================================
// Address: 0x403df0 | Symbol: CD3DApplication::GetScreenHeight
// ============================================================================
void CD3DApplication__GetScreenHeight(void)

{
  CD3DFramework7__GetRenderHeight();
  return;
}

// ============================================================================
// Address: 0x403e10 | Symbol: CD3DApplication::GetFPS
// ============================================================================
int CD3DApplication__GetFPS(void)

{
  int in_ECX;
  
  return (int)(*(float *)(in_ECX + 0x24) + 0.5);
}

// ============================================================================
// Address: 0x403e30 | Symbol: CD3DApplication::DisplayFPS
// ============================================================================
undefined4 CD3DApplication__DisplayFPS(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(in_ECX + 0x2c) + 0x49c);
  }
  return uVar1;
}

// ============================================================================
// Address: 0x403e60 | Symbol: AboutProc
// ============================================================================
bool AboutProc(HWND param_1,int param_2,short param_3)

{
  if ((param_2 == 0x111) && ((param_3 == 1 || (param_3 == 2)))) {
    EndDialog(param_1,1);
  }
  return param_2 == 0x110;
}

// ============================================================================
// Address: 0x403ec0 | Symbol: WndProc
// ============================================================================
void WndProc(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  if (DAT_00487f28 == (int *)0x0) {
    DefWindowProcA(param_1,param_2,param_3,param_4);
  }
  else {
    (**(code **)(*DAT_00487f28 + 0x2c))(param_1,param_2,param_3,param_4);
  }
  return;
}

// ============================================================================
// Address: 0x403f10 | Symbol: _D3DMATRIX::_D3DMATRIX
// ============================================================================
undefined4 _D3DMATRIX___D3DMATRIX(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}

// ============================================================================
// Address: 0x403f20 | Symbol: _D3DVECTOR::_D3DVECTOR
// ============================================================================
undefined4 * _D3DVECTOR___D3DVECTOR(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  return in_ECX;
}

// ============================================================================
// Address: 0x403f60 | Symbol: FUN_00403f60
// ============================================================================
undefined4 FUN_00403f60(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}

// ============================================================================
// Address: 0x403f70 | Symbol: _D3DVECTOR::operator[]
// ============================================================================
int _D3DVECTOR__operator__(int param_1)

{
  int in_ECX;
  
  return in_ECX + param_1 * 4;
}

// ============================================================================
// Address: 0x403f90 | Symbol: FUN_00403f90
// ============================================================================
int FUN_00403f90(int param_1)

{
  int in_ECX;
  
  return in_ECX + param_1 * 4;
}

// ============================================================================
// Address: 0x403fb0 | Symbol: FUN_00403fb0
// ============================================================================
undefined4 FUN_00403fb0(undefined4 param_1,float *param_2,float param_3)

{
  _D3DVECTOR___D3DVECTOR(param_3 * *param_2,param_3 * param_2[1],param_3 * param_2[2]);
  return param_1;
}

// ============================================================================
// Address: 0x404000 | Symbol: operator-
// ============================================================================
undefined4 operator-(undefined4 param_1,float *param_2,float *param_3)

{
  _D3DVECTOR___D3DVECTOR(*param_2 - *param_3,param_2[1] - param_3[1],param_2[2] - param_3[2]);
  return param_1;
}

// ============================================================================
// Address: 0x404050 | Symbol: FUN_00404050
// ============================================================================
undefined4 FUN_00404050(undefined4 param_1,float *param_2,float *param_3)

{
  _D3DVECTOR___D3DVECTOR(*param_2 + *param_3,param_2[1] + param_3[1],param_2[2] + param_3[2]);
  return param_1;
}

// ============================================================================
// Address: 0x4040a0 | Symbol: operator/
// ============================================================================
undefined4 operator/(undefined4 param_1,float *param_2,float param_3)

{
  _D3DVECTOR___D3DVECTOR(*param_2 / param_3,param_2[1] / param_3,param_2[2] / param_3);
  return param_1;
}

// ============================================================================
// Address: 0x4040f0 | Symbol: std::shared_ptr<__ExceptionPtr>::CD3DFramework7::
// ============================================================================
/* Library Function - Single Match
    public: void * __thiscall std::shared_ptr<class __ExceptionPtr>::`scalar deleting
   destructor'(unsigned int)
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2015 Release, Visual Studio 2017 Debug, Visual
   Studio 2017 Release */

void * __thiscall
std::shared_ptr<__ExceptionPtr>::CD3DFramework7__(shared_ptr<__ExceptionPtr> *this,uint param_1)

{
  CD3DFramework7___CD3DFramework7(this);
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(this,0x44);
  }
  return this;
}

// ============================================================================
// Address: 0x404120 | Symbol: CrossProduct
// ============================================================================
undefined4 * CrossProduct(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  FUN_00403f60();
  pfVar5 = (float *)FUN_00403f90(1);
  pfVar6 = (float *)FUN_00403f90(2);
  fVar1 = *pfVar5;
  fVar2 = *pfVar6;
  pfVar5 = (float *)FUN_00403f90(2);
  pfVar6 = (float *)FUN_00403f90(1);
  fVar3 = *pfVar5;
  fVar4 = *pfVar6;
  pfVar5 = (float *)_D3DVECTOR__operator__(0);
  *pfVar5 = fVar1 * fVar2 - fVar3 * fVar4;
  pfVar5 = (float *)FUN_00403f90(2);
  pfVar6 = (float *)FUN_00403f90(0);
  fVar1 = *pfVar5;
  fVar2 = *pfVar6;
  pfVar5 = (float *)FUN_00403f90(0);
  pfVar6 = (float *)FUN_00403f90(2);
  fVar3 = *pfVar5;
  fVar4 = *pfVar6;
  pfVar5 = (float *)_D3DVECTOR__operator__(1);
  *pfVar5 = fVar1 * fVar2 - fVar3 * fVar4;
  pfVar5 = (float *)FUN_00403f90(0);
  pfVar6 = (float *)FUN_00403f90(1);
  fVar1 = *pfVar5;
  fVar2 = *pfVar6;
  pfVar5 = (float *)FUN_00403f90(1);
  pfVar6 = (float *)FUN_00403f90(0);
  fVar3 = *pfVar5;
  fVar4 = *pfVar6;
  pfVar5 = (float *)_D3DVECTOR__operator__(2);
  *pfVar5 = fVar1 * fVar2 - fVar3 * fVar4;
  *param_1 = local_28;
  param_1[1] = local_24;
  param_1[2] = local_20;
  return param_1;
}

// ============================================================================
// Address: 0x404280 | Symbol: CD3DApplication::DeleteDeviceObjects
// ============================================================================
undefined4 CD3DApplication__DeleteDeviceObjects(void)

{
  return 0;
}

// ============================================================================
// Address: 0x404290 | Symbol: CD3DApplication::FinalCleanup
// ============================================================================
undefined4 CD3DApplication__FinalCleanup(void)

{
  return 0;
}

// ============================================================================
// Address: 0x4042a0 | Symbol: CD3DApplication::FrameMove
// ============================================================================
undefined4 CD3DApplication__FrameMove(void)

{
  return 0;
}

// ============================================================================
// Address: 0x4042b0 | Symbol: CD3DFramework7::GetD3DDevice
// ============================================================================
undefined4 CD3DFramework7__GetD3DDevice(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}

// ============================================================================
// Address: 0x4042d0 | Symbol: CD3DFramework7::GetDirect3D
// ============================================================================
undefined4 CD3DFramework7__GetDirect3D(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}

// ============================================================================
// Address: 0x4042f0 | Symbol: CD3DFramework7::GetDirectDraw
// ============================================================================
undefined4 CD3DFramework7__GetDirectDraw(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}

// ============================================================================
// Address: 0x404310 | Symbol: CD3DFramework7::GetRenderSurface
// ============================================================================
undefined4 CD3DFramework7__GetRenderSurface(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x34);
}

// ============================================================================
// Address: 0x404330 | Symbol: CD3DFramework7::GetRenderSurfaceLeft
// ============================================================================
undefined4 CD3DFramework7__GetRenderSurfaceLeft(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x38);
}

// ============================================================================
// Address: 0x404350 | Symbol: CD3DApplication::InitDeviceObjects
// ============================================================================
undefined4 CD3DApplication__InitDeviceObjects(void)

{
  return 0;
}

// ============================================================================
// Address: 0x404360 | Symbol: Magnitude
// ============================================================================
float10 Magnitude(void)

{
  float10 fVar1;
  
  fVar1 = (float10)SquareMagnitude();
  fVar1 = (float10)FUN_0044bca0((double)fVar1);
  return (float10)(float)fVar1;
}

// ============================================================================
// Address: 0x404390 | Symbol: Normalize
// ============================================================================
undefined4 Normalize(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)Magnitude(param_2);
  operator/(param_1,param_2,(float)fVar1);
  return param_1;
}

// ============================================================================
// Address: 0x4043c0 | Symbol: CD3DApplication::OneTimeSceneInit
// ============================================================================
undefined4 CD3DApplication__OneTimeSceneInit(void)

{
  return 0;
}

// ============================================================================
// Address: 0x4043d0 | Symbol: CD3DApplication::Render
// ============================================================================
undefined4 CD3DApplication__Render(void)

{
  return 0;
}

// ============================================================================
// Address: 0x4043e0 | Symbol: CD3DApplication::RestoreSurfaces
// ============================================================================
undefined4 CD3DApplication__RestoreSurfaces(void)

{
  return 0;
}

// ============================================================================
// Address: 0x4043f0 | Symbol: SquareMagnitude
// ============================================================================
float10 SquareMagnitude(float *param_1)

{
  return (float10)(*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2]);
}

// ============================================================================
// Address: 0x404440 | Symbol: __local_stdio_printf_options
// ============================================================================
undefined * __local_stdio_printf_options(void)

{
  return &DAT_00487f20;
}

// ============================================================================
// Address: 0x404450 | Symbol: _vsnprintf_l
// ============================================================================
int _vsnprintf_l(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  uint *puVar1;
  int local_c;
  
  puVar1 = (uint *)__local_stdio_printf_options(param_1,param_2,param_3,param_4,param_5);
  local_c = ___stdio_common_vsprintf(*puVar1 | 1,puVar1[1]);
  if (local_c < 0) {
    local_c = -1;
  }
  return local_c;
}

// ============================================================================
// Address: 0x4044a0 | Symbol: _vsprintf_l
// ============================================================================
void _vsprintf_l(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  _vsnprintf_l(param_1,0xffffffff,param_2,param_3,param_4);
  return;
}

// ============================================================================
// Address: 0x4044c0 | Symbol: sprintf
// ============================================================================
undefined4 sprintf(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _vsprintf_l(param_1,param_2,0,&stack0x0000000c);
  return uVar1;
}
