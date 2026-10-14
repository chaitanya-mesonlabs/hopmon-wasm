// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: d3dframe.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "d3dframe.h"

// ============================================================================
// Address: 0x408370 | Symbol: CD3DFramework7::CreateZBuffer
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CD3DFramework7__CreateZBuffer(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_170 [68];
  uint local_12c;
  undefined4 local_84;
  undefined4 local_80;
  int local_3c [3];
  undefined4 local_30;
  uint local_1c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0xc))(*(undefined4 *)(in_ECX + 0x2c),local_170);
  if ((local_12c & 0x8000) == 0) {
    local_84 = 0x7c;
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x58))(*(undefined4 *)(in_ECX + 0x34),&local_84);
    local_80 = 0x1007;
    local_1c = *(uint *)(in_ECX + 0x40) | 0x20000;
    local_3c[0] = 0;
    (**(code **)(**(int **)(in_ECX + 0x28) + 0x18))
              (*(undefined4 *)(in_ECX + 0x28),param_1,EnumZBufferFormatsCallback,local_3c);
    if (local_3c[0] == 0) {
      local_30 = 0x10;
      (**(code **)(**(int **)(in_ECX + 0x28) + 0x18))
                (*(undefined4 *)(in_ECX + 0x28),param_1,EnumZBufferFormatsCallback,local_3c);
      if (local_3c[0] == 0) {
        return 0x82000005;
      }
    }
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x18))
                      (*(undefined4 *)(in_ECX + 0x24),&local_84,in_ECX + 0x3c,0);
    if (iVar2 < 0) {
      if (iVar2 == -0x7789fe84) {
        uVar1 = 0x8876017c;
      }
      else {
        uVar1 = 0x82000005;
      }
    }
    else {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x34) + 0xc))
                        (*(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x3c));
      if (iVar2 < 0) {
        uVar1 = 0x82000005;
      }
      else {
        if ((*(int *)(in_ECX + 8) != 0) &&
           (iVar2 = (**(code **)(**(int **)(in_ECX + 0x38) + 0xc))
                              (*(undefined4 *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x3c)),
           iVar2 < 0)) {
          return 0x82000005;
        }
        iVar2 = (**(code **)(**(int **)(in_ECX + 0x2c) + 0x20))
                          (*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x34),0);
        if (iVar2 < 0) {
          uVar1 = 0x82000005;
        }
        else {
          uVar1 = 0;
        }
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x408580 | Symbol: CD3DFramework7::CreateFullscreenBuffers
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CD3DFramework7__CreateFullscreenBuffers(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_b0;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_90;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  SetRect((LPRECT)(in_ECX + 0x14),0,0,*(int *)(param_1 + 0xc),*(int *)(param_1 + 8));
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x14);
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x20) - *(int *)(in_ECX + 0x18);
  local_b0 = 0;
  if (((*(int *)(in_ECX + 0xc) == 0x140) && (*(int *)(in_ECX + 0x10) == 200)) &&
     (*(int *)(param_1 + 0x54) == 8)) {
    local_b0 = 1;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x54))
                    (*(undefined4 *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0xc),
                     *(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(param_1 + 0x54),
                     *(undefined4 *)(param_1 + 0x18),local_b0);
  if (iVar1 < 0) {
    uVar2 = 0x8200000a;
  }
  else {
    _memset(&local_a4,0,0x7c);
    local_a4 = 0x7c;
    local_a0 = 0x21;
    local_3c = 0x2218;
    local_90 = 1;
    if (*(int *)(in_ECX + 8) != 0) {
      local_3c = 0x6218;
      local_38 = local_38 | 0x80000;
    }
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x18))
                      (*(undefined4 *)(in_ECX + 0x24),&local_a4,in_ECX + 0x30,0);
    if (iVar1 < 0) {
      if (iVar1 == -0x7789fe84) {
        uVar2 = 0x8876017c;
      }
      else {
        uVar2 = 0x82000008;
      }
    }
    else {
      local_18 = 4;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 0x30))
                        (*(undefined4 *)(in_ECX + 0x30),&local_18,in_ECX + 0x34);
      if (iVar1 < 0) {
        uVar2 = 0x8200000b;
      }
      else {
        (**(code **)(**(int **)(in_ECX + 0x34) + 4))(*(undefined4 *)(in_ECX + 0x34));
        if (*(int *)(in_ECX + 8) != 0) {
          local_28 = 0;
          local_24 = 0x80000;
          local_20 = 0;
          local_1c = 0;
          iVar1 = (**(code **)(**(int **)(in_ECX + 0x34) + 0x30))
                            (*(undefined4 *)(in_ECX + 0x34),&local_28,in_ECX + 0x38);
          if (iVar1 < 0) {
            return 0x8200000b;
          }
          (**(code **)(**(int **)(in_ECX + 0x38) + 4))(*(undefined4 *)(in_ECX + 0x38));
        }
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x408850 | Symbol: CD3DFramework7::CreateWindowedBuffers
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CD3DFramework7__CreateWindowedBuffers(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int *local_8c;
  undefined4 *local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_1c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_88 = in_ECX;
  GetClientRect((HWND)*in_ECX,(LPRECT)(in_ECX + 5));
  ClientToScreen((HWND)*local_88,(LPPOINT)(local_88 + 5));
  ClientToScreen((HWND)*local_88,(LPPOINT)(local_88 + 7));
  local_88[3] = local_88[7] - local_88[5];
  local_88[4] = local_88[8] - local_88[6];
  _memset(&local_84,0,0x7c);
  local_84 = 0x7c;
  local_80 = 1;
  local_1c = 0x200;
  iVar1 = (**(code **)(*(int *)local_88[9] + 0x18))(local_88[9],&local_84,local_88 + 0xc,0);
  if (iVar1 < 0) {
    if (iVar1 == -0x7789fe84) {
      uVar2 = 0x8876017c;
    }
    else {
      uVar2 = 0x82000008;
    }
  }
  else {
    iVar1 = (**(code **)(*(int *)local_88[9] + 0x10))(local_88[9],0,&local_8c,0);
    if (iVar1 < 0) {
      uVar2 = 0x82000009;
    }
    else {
      (**(code **)(*local_8c + 0x20))(local_8c,0,*local_88);
      (**(code **)(*(int *)local_88[0xc] + 0x70))(local_88[0xc],local_8c);
      if (local_8c != (int *)0x0) {
        (**(code **)(*local_8c + 8))(local_8c);
        local_8c = (int *)0x0;
      }
      local_80 = 7;
      local_78 = local_88[3];
      local_7c = local_88[4];
      local_1c = 0x2040;
      iVar1 = (**(code **)(*(int *)local_88[9] + 0x18))(local_88[9],&local_84,local_88 + 0xd,0);
      if (iVar1 < 0) {
        if (iVar1 == -0x7789fe84) {
          uVar2 = 0x8876017c;
        }
        else {
          uVar2 = 0x8200000b;
        }
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x408aa0 | Symbol: CD3DFramework7::CreateClipperForBackBuffer
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CD3DFramework7__CreateClipperForBackBuffer(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_3c = in_ECX;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x10))
                    (*(undefined4 *)(in_ECX + 0x24),0,&local_40,0);
  if (iVar1 < 0) {
    uVar2 = 0x8200000b;
  }
  else {
    _memset(&local_38,0,0x30);
    local_38 = 0x20;
    local_34 = 1;
    local_30 = 1;
    local_2c = 0x10;
    local_28 = 0;
    local_24 = 0;
    local_20 = *(undefined4 *)(local_3c + 0xc);
    local_1c = *(undefined4 *)(local_3c + 0x10);
    local_18 = 0;
    local_14 = 0;
    local_10 = *(undefined4 *)(local_3c + 0xc);
    local_c = *(undefined4 *)(local_3c + 0x10);
    iVar1 = (**(code **)(*local_40 + 0x1c))(local_40,&local_38,0);
    if (iVar1 < 0) {
      uVar2 = 0x8200000b;
    }
    else {
      iVar1 = (**(code **)(**(int **)(local_3c + 0x34) + 0x70))
                        (*(undefined4 *)(local_3c + 0x34),local_40);
      if (iVar1 < 0) {
        uVar2 = 0x8200000b;
      }
      else {
        if (local_40 != (int *)0x0) {
          (**(code **)(*local_40 + 8))(local_40);
        }
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x408bd0 | Symbol: CD3DFramework7::CreateDirectDraw
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CD3DFramework7__CreateDirectDraw(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  uint local_8c;
  undefined4 local_84 [21];
  uint local_30;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  iVar1 = DirectDrawCreateEx(param_1,in_ECX + 9,&DAT_00475fe8,0);
  if (iVar1 < 0) {
    uVar2 = 0x82000001;
  }
  else {
    local_8c = 8;
    if (in_ECX[1] != 0) {
      local_8c = 0x13;
    }
    if ((param_2 & 8) == 0) {
      local_8c = local_8c | 0x800;
    }
    iVar1 = (**(code **)(*(int *)in_ECX[9] + 0x50))(in_ECX[9],*in_ECX,local_8c);
    if (iVar1 < 0) {
      uVar2 = 0x82000002;
    }
    else {
      if (in_ECX[1] == 0) {
        local_84[0] = 0x7c;
        (**(code **)(*(int *)in_ECX[9] + 0x30))(in_ECX[9],local_84);
        if (local_30 < 9) {
          return 0x8200000e;
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x408cd0 | Symbol: CD3DFramework7::CreateDirect3D
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CD3DFramework7__CreateDirect3D(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  iVar1 = (**(code **)**(undefined4 **)(in_ECX + 0x24))
                    (*(undefined4 *)(in_ECX + 0x24),&DAT_00475dd8,in_ECX + 0x28);
  if (iVar1 < 0) {
    uVar2 = 0x82000003;
  }
  else {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x10))
                      (*(undefined4 *)(in_ECX + 0x28),param_1,*(undefined4 *)(in_ECX + 0x34),
                       in_ECX + 0x2c);
    if (iVar1 < 0) {
      uVar2 = 0x82000004;
    }
    else {
      local_20 = 0;
      local_1c = 0;
      local_18 = *(undefined4 *)(in_ECX + 0xc);
      local_14 = *(undefined4 *)(in_ECX + 0x10);
      local_10 = 0;
      local_c = 0x3f800000;
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x2c) + 0x34))
                        (*(undefined4 *)(in_ECX + 0x2c),&local_20);
      if (iVar1 < 0) {
        uVar2 = 0x82000007;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

// ============================================================================
// Address: 0x408db0 | Symbol: CD3DFramework7::CreateEnvironment
// ============================================================================
int CD3DFramework7__CreateEnvironment
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int in_ECX;
  int local_8;
  
  iVar1 = IsEqualGUID(param_2,&DAT_00475da8);
  if (iVar1 == 0) {
    iVar1 = IsEqualGUID(param_2,&DAT_00475d68);
    if (iVar1 == 0) {
      *(undefined4 *)(in_ECX + 0x40) = 0x800;
    }
    else {
      *(undefined4 *)(in_ECX + 0x40) = 0x4000;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x40) = 0x4000;
  }
  local_8 = CD3DFramework7__CreateDirectDraw(param_1,param_4);
  if (-1 < local_8) {
    if ((param_4 & 1) == 0) {
      local_8 = CD3DFramework7__CreateWindowedBuffers();
    }
    else {
      local_8 = CD3DFramework7__CreateFullscreenBuffers(param_3);
    }
    if (((-1 < local_8) && (local_8 = CD3DFramework7__CreateClipperForBackBuffer(), -1 < local_8))
       && (local_8 = CD3DFramework7__CreateDirect3D(param_2), -1 < local_8)) {
      if ((param_4 & 4) != 0) {
        local_8 = CD3DFramework7__CreateZBuffer(param_2);
      }
      if (-1 < local_8) {
        local_8 = 0;
      }
    }
  }
  return local_8;
}

// ============================================================================
// Address: 0x408eb0 | Symbol: CD3DFramework7::RestoreSurfaces
// ============================================================================
undefined4 CD3DFramework7__RestoreSurfaces(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x24) + 100))(*(undefined4 *)(in_ECX + 0x24));
  return 0;
}

// ============================================================================
// Address: 0x408ee0 | Symbol: CD3DFramework7::ShowFrame
// ============================================================================
undefined4 CD3DFramework7__ShowFrame(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x30) == 0) {
    uVar1 = 0x8200000f;
  }
  else if (*(int *)(in_ECX + 4) == 0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 0x14))
                      (*(undefined4 *)(in_ECX + 0x30),in_ECX + 0x14,*(undefined4 *)(in_ECX + 0x34),0
                       ,0x1000000,0);
  }
  else if (*(int *)(in_ECX + 8) == 0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 0x2c))(*(undefined4 *)(in_ECX + 0x30),0,1);
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 0x2c))(*(undefined4 *)(in_ECX + 0x30),0,0x11);
  }
  return uVar1;
}

// ============================================================================
// Address: 0x408f70 | Symbol: CD3DFramework7::FlipToGDISurface
// ============================================================================
undefined4 CD3DFramework7__FlipToGDISurface(int param_1)

{
  undefined4 *in_ECX;
  
  if ((in_ECX[9] != 0) && (in_ECX[1] != 0)) {
    (**(code **)(*(int *)in_ECX[9] + 0x28))(in_ECX[9]);
    if (param_1 != 0) {
      DrawMenuBar((HWND)*in_ECX);
      RedrawWindow((HWND)*in_ECX,(RECT *)0x0,(HRGN)0x0,0x400);
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x408fd0 | Symbol: CD3DFramework7::Move
// ============================================================================
void CD3DFramework7__Move(int param_1,int param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 1) {
    SetRect((LPRECT)(in_ECX + 0x14),param_1,param_2,param_1 + *(int *)(in_ECX + 0xc),
            param_2 + *(int *)(in_ECX + 0x10));
  }
  return;
}

// ============================================================================
// Address: 0x409020 | Symbol: CD3DFramework7::Initialize
// ============================================================================
int CD3DFramework7__Initialize(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int *in_ECX;
  uint local_c;
  
  if (((param_1 == 0) || (param_3 == 0)) || ((param_4 == 0 && ((param_5 & 1) != 0)))) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *in_ECX = param_1;
    in_ECX[2] = 0;
    local_c = (uint)((param_5 & 1) != 0);
    in_ECX[1] = local_c;
    if ((((param_5 & 2) != 0) && ((param_5 & 1) != 0)) &&
       ((*(uint *)(param_4 + 0x6c) & 0x80000) != 0)) {
      in_ECX[2] = 1;
    }
    iVar1 = CD3DFramework7__CreateEnvironment(param_2,param_3,param_4,param_5);
    if (iVar1 < 0) {
      CD3DFramework7__DestroyObjects();
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}

// ============================================================================
// Address: 0x4090e0 | Symbol: CD3DFramework7::DestroyObjects
// ============================================================================
undefined4 CD3DFramework7__DestroyObjects(void)

{
  undefined4 *in_ECX;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  if (in_ECX[9] != 0) {
    (**(code **)(*(int *)in_ECX[9] + 0x50))(in_ECX[9],*in_ECX,8);
  }
  if (in_ECX[0xb] != 0) {
    local_10 = (**(code **)(*(int *)in_ECX[0xb] + 8))(in_ECX[0xb]);
  }
  in_ECX[0xb] = 0;
  if (in_ECX[0xd] != 0) {
    (**(code **)(*(int *)in_ECX[0xd] + 8))(in_ECX[0xd]);
    in_ECX[0xd] = 0;
  }
  if (in_ECX[0xe] != 0) {
    (**(code **)(*(int *)in_ECX[0xe] + 8))(in_ECX[0xe]);
    in_ECX[0xe] = 0;
  }
  if (in_ECX[0xf] != 0) {
    (**(code **)(*(int *)in_ECX[0xf] + 8))(in_ECX[0xf]);
    in_ECX[0xf] = 0;
  }
  if (in_ECX[0xc] != 0) {
    (**(code **)(*(int *)in_ECX[0xc] + 8))(in_ECX[0xc]);
    in_ECX[0xc] = 0;
  }
  if (in_ECX[10] != 0) {
    (**(code **)(*(int *)in_ECX[10] + 8))(in_ECX[10]);
    in_ECX[10] = 0;
  }
  if (in_ECX[9] != 0) {
    local_c = (**(code **)(*(int *)in_ECX[9] + 8))(in_ECX[9]);
  }
  in_ECX[9] = 0;
  if ((local_c == 0) && (local_10 == 0)) {
    local_14 = 0;
  }
  else {
    local_14 = 0x8200000c;
  }
  return local_14;
}

// ============================================================================
// Address: 0x409260 | Symbol: CMFCToolTipInfo::CD3DFramework7::CD3DFramework7
// ============================================================================
/* Library Function - Single Match
    public: __thiscall CMFCToolTipInfo::CMFCToolTipInfo(void)
   
   Library: Visual Studio 2010 Debug */

CMFCToolTipInfo * __thiscall CMFCToolTipInfo::CD3DFramework7__CD3DFramework7(CMFCToolTipInfo *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  return this;
}

// ============================================================================
// Address: 0x4092f0 | Symbol: std::shared_ptr<__ExceptionPtr>::CD3DFramework7::~CD3DFramework7
// ============================================================================
/* Library Function - Single Match
    public: __thiscall std::shared_ptr<class __ExceptionPtr>::~shared_ptr<class
   __ExceptionPtr>(void)
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2015 Release, Visual Studio 2017 Debug, Visual
   Studio 2017 Release */

void __thiscall
std::shared_ptr<__ExceptionPtr>::CD3DFramework7___CD3DFramework7(shared_ptr<__ExceptionPtr> *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00470a00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CD3DFramework7__DestroyObjects(DAT_00486cf0 ^ (uint)&stack0xfffffffc,this);
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x409340 | Symbol: CD3DFramework7::GetRenderWidth
// ============================================================================
undefined4 CD3DFramework7__GetRenderWidth(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}

// ============================================================================
// Address: 0x409360 | Symbol: CD3DFramework7::GetRenderHeight
// ============================================================================
undefined4 CD3DFramework7__GetRenderHeight(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}

// ============================================================================
// Address: 0x409380 | Symbol: EnumZBufferFormatsCallback
// ============================================================================
undefined4 EnumZBufferFormatsCallback(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2[3] == param_1[3]) {
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
