// Decompiled from Hopmon.exe (JJ Soft, 2002)
// Module: d3dtextr.cpp
// Symbols, types, and class layout recovered from Hopmon.pdb

#include "d3dtextr.h"

// ============================================================================
// Address: 0x40a6e0 | Symbol: D3DTextr_GetSurface
// ============================================================================
undefined4 D3DTextr_GetSurface(undefined2 param_1)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = FindTexture(param_1);
  if (iVar1 == 0) {
    local_c = 0;
  }
  else {
    local_c = *(undefined4 *)(iVar1 + 0x24);
  }
  return local_c;
}

// ============================================================================
// Address: 0x40a720 | Symbol: D3DTextr_Invalidate
// ============================================================================
undefined4 D3DTextr_Invalidate(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FindTexture(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x887600ff;
  }
  else {
    if (*(int *)(iVar1 + 0x24) != 0) {
      (**(code **)(**(int **)(iVar1 + 0x24) + 8))(*(undefined4 *)(iVar1 + 0x24));
      *(undefined4 *)(iVar1 + 0x24) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x40a770 | Symbol: D3DTextr_Restore
// ============================================================================
undefined4 D3DTextr_Restore(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FindTexture(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x887600ff;
  }
  else {
    uVar2 = TextureContainer__Restore(param_2);
  }
  return uVar2;
}

// ============================================================================
// Address: 0x40a7b0 | Symbol: D3DTextr_InvalidateAllTextures
// ============================================================================
undefined4 D3DTextr_InvalidateAllTextures(void)

{
  undefined4 local_8;
  
  for (local_8 = DAT_0048e008; local_8 != 0; local_8 = *(int *)(local_8 + 4)) {
    if (*(int *)(local_8 + 0x24) != 0) {
      (**(code **)(**(int **)(local_8 + 0x24) + 8))(*(undefined4 *)(local_8 + 0x24));
      *(undefined4 *)(local_8 + 0x24) = 0;
    }
  }
  return 0;
}

// ============================================================================
// Address: 0x40a800 | Symbol: D3DTextr_RestoreAllTextures
// ============================================================================
undefined4 D3DTextr_RestoreAllTextures(undefined4 param_1)

{
  undefined4 local_8;
  
  for (local_8 = DAT_0048e008; local_8 != 0; local_8 = *(int *)(local_8 + 4)) {
    D3DTextr_Restore(*(undefined2 *)(local_8 + 8),param_1);
  }
  return 0;
}

// ============================================================================
// Address: 0x40a840 | Symbol: D3DTextr_CreateTextureFromResource
// ============================================================================
undefined4 D3DTextr_CreateTextureFromResource(short param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  ushort local_2e;
  undefined4 *local_24;
  undefined4 *local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470a34;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    iVar2 = FindTexture(param_1,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0) {
      local_1c = FUN_0042d23e(0x30);
      local_8 = 0;
      if (local_1c == 0) {
        local_20 = (undefined4 *)0x0;
      }
      else {
        local_20 = (undefined4 *)TextureContainer__TextureContainer(param_1,param_3,param_2);
      }
      local_24 = local_20;
      local_8 = 0xffffffff;
      local_14 = local_20;
      if (local_20 == (undefined4 *)0x0) {
        uVar1 = 0x8007000e;
      }
      else {
        iVar2 = TextureContainer__LoadImageData();
        if (iVar2 < 0) {
          local_18 = local_14;
          if (local_14 != (undefined4 *)0x0) {
            (**(code **)*local_14)(1);
          }
          uVar1 = 0x80004005;
        }
        else {
          if (local_14[10] != 0) {
            GetObjectA((HANDLE)local_14[10],0x18,local_40);
            local_14[3] = local_3c;
            local_14[4] = local_38;
            local_14[6] = (uint)local_2e;
          }
          uVar1 = 0;
        }
      }
    }
    else {
      uVar1 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}

// ============================================================================
// Address: 0x40a970 | Symbol: D3DTextr_CreateEmptyTexture
// ============================================================================
undefined4
D3DTextr_CreateEmptyTexture
          (short param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00470a65;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    iVar2 = FindTexture(param_1,DAT_00486cf0 ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0) {
      iVar2 = FUN_0042d23e(0x30);
      local_8 = 0;
      if (iVar2 == 0) {
        local_1c = 0;
      }
      else {
        local_1c = TextureContainer__TextureContainer(param_1,param_5,param_4);
      }
      if (local_1c == 0) {
        uVar1 = 0x8007000e;
      }
      else {
        *(undefined4 *)(local_1c + 0xc) = param_2;
        *(undefined4 *)(local_1c + 0x10) = param_3;
        *(undefined4 *)(local_1c + 0x18) = 0x10;
        if ((*(uint *)(local_1c + 0x1c) & 4) != 0) {
          *(undefined4 *)(local_1c + 0x18) = 0x20;
        }
        if ((param_4 & 0x10) != 0) {
          *(undefined4 *)(local_1c + 0x20) = 1;
        }
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0x80004005;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}

// ============================================================================
// Address: 0x40aa80 | Symbol: D3DTextr_DestroyTexture
// ============================================================================
undefined4 D3DTextr_DestroyTexture(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FindTexture(param_1);
  if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  return 0;
}

// ============================================================================
// Address: 0x40aad0 | Symbol: TextureContainer::LoadImageData
// ============================================================================
undefined4 TextureContainer__LoadImageData(void)

{
  HMODULE hInst;
  HANDLE pvVar1;
  undefined4 uVar2;
  int in_ECX;
  LPCSTR name;
  UINT type;
  int cx;
  int cy;
  UINT fuLoad;
  
  fuLoad = 0x2000;
  cy = 0;
  cx = 0;
  type = 0;
  name = (LPCSTR)(uint)*(ushort *)(in_ECX + 8);
  hInst = GetModuleHandleA((LPCSTR)0x0);
  pvVar1 = LoadImageA(hInst,name,type,cx,cy,fuLoad);
  *(HANDLE *)(in_ECX + 0x28) = pvVar1;
  if (*(int *)(in_ECX + 0x28) == 0) {
    uVar2 = 0x80004001;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// ============================================================================
// Address: 0x40ab20 | Symbol: TextureContainer::Restore
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TextureContainer__Restore(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  uint local_1b4;
  uint local_1b0;
  uint local_1ac;
  uint local_1a8;
  uint local_1a4;
  uint local_1a0;
  uint local_19c;
  undefined4 local_198;
  undefined4 local_194;
  uint local_190;
  int local_18c;
  undefined1 *local_188;
  int *local_184;
  int *local_180;
  uint local_17c;
  uint local_178;
  int local_174;
  undefined1 local_170 [92];
  uint local_114;
  uint local_ec;
  uint local_e8;
  undefined1 local_ac [40];
  undefined1 local_84 [4];
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  undefined1 local_3c [32];
  uint local_1c;
  undefined4 local_18;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_174 = in_ECX;
  if (*(int *)(in_ECX + 0x24) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x24) + 8))(*(undefined4 *)(in_ECX + 0x24));
    *(undefined4 *)(local_174 + 0x24) = 0;
  }
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0xc))(param_1,local_170);
    if (iVar2 < 0) {
      iVar2 = -0x7fffbffb;
    }
    else {
      D3DUtil_InitSurfaceDesc(local_84,0,0);
      local_80 = 0x101007;
      local_1c = 0x1000;
      local_c = *(undefined4 *)(local_174 + 0x14);
      local_78 = *(uint *)(local_174 + 0xc);
      local_7c = *(uint *)(local_174 + 0x10);
      cVar1 = __(local_ac,&DAT_00475da8);
      if (cVar1 == '\0') {
        cVar1 = __(local_ac,&DAT_00475d68);
        if (cVar1 == '\0') {
          local_1c = local_1c | 0x800;
        }
        else {
          local_18 = 0x10;
        }
      }
      else {
        local_18 = 0x10;
      }
      if ((local_114 & 2) != 0) {
        for (local_78 = 1; local_78 < *(uint *)(local_174 + 0xc); local_78 = local_78 << 1) {
        }
        for (local_7c = 1; local_7c < *(uint *)(local_174 + 0x10); local_7c = local_7c << 1) {
        }
      }
      local_178 = local_ec;
      local_17c = local_e8;
      if (local_ec == 0) {
        local_19c = 0x100;
      }
      else {
        local_19c = local_ec;
      }
      if (local_78 < local_19c) {
        local_1a4 = local_78;
      }
      else {
        if (local_ec == 0) {
          local_1a0 = 0x100;
        }
        else {
          local_1a0 = local_ec;
        }
        local_1a4 = local_1a0;
      }
      local_78 = local_1a4;
      if (local_e8 == 0) {
        local_1a8 = 0x100;
      }
      else {
        local_1a8 = local_e8;
      }
      if (local_7c < local_1a8) {
        local_1b0 = local_7c;
      }
      else {
        if (local_e8 == 0) {
          local_1ac = 0x100;
        }
        else {
          local_1ac = local_e8;
        }
        local_1b0 = local_1ac;
      }
      local_7c = local_1b0;
      if ((local_114 & 0x20) != 0) {
        if (local_1b0 < local_1a4) {
          local_7c = local_1a4;
        }
        else {
          local_78 = local_1b0;
        }
      }
      local_18c = 0;
      local_188 = local_3c;
      local_198 = *(undefined4 *)(local_174 + 0x18);
      local_1b4 = (uint)(*(uint *)(local_174 + 0x18) < 9);
      local_190 = local_1b4;
      local_194 = *(undefined4 *)(local_174 + 0x20);
      if ((*(uint *)(local_174 + 0x1c) & 8) == 0) {
        if ((*(uint *)(local_174 + 0x1c) & 4) != 0) {
          local_198 = 0x20;
        }
      }
      else {
        local_198 = 0x10;
      }
      if (((*(uint *)(local_174 + 0x1c) & 3) != 0) && (local_1b4 != 0)) {
        if ((local_114 & 0x80) == 0) {
          local_194 = 1;
          local_190 = 0;
        }
        else {
          local_194 = 1;
          local_190 = 1;
        }
      }
      (**(code **)(*param_1 + 0x10))(param_1,TextureSearchCallback,&local_198);
      if (local_18c == 0) {
        local_190 = 0;
        local_198 = 0x10;
        (**(code **)(*param_1 + 0x10))(param_1,TextureSearchCallback,&local_198);
        if (local_18c == 0) {
          return -0x7fffbffb;
        }
      }
      (**(code **)(*param_1 + 0x24))(param_1,&local_180);
      (**(code **)(*local_180 + 0x90))(local_180,&local_184);
      (**(code **)(*local_180 + 8))(local_180);
      iVar2 = (**(code **)(*local_184 + 0x18))(local_184,local_84,local_174 + 0x24,0);
      (**(code **)(*local_184 + 8))(local_184);
      if (-1 < iVar2) {
        if (*(int *)(local_174 + 0x28) == 0) {
          if (*(int *)(local_174 + 0x2c) == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = TextureContainer__CopyRGBADataToSurface();
          }
        }
        else {
          iVar2 = TextureContainer__CopyBitmapToSurface();
        }
      }
    }
  }
  return iVar2;
}

// ============================================================================
// Address: 0x40afc0 | Symbol: TextureContainer::CopyBitmapToSurface
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TextureContainer__CopyBitmapToSurface(void)

{
  ushort uVar1;
  UINT UVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_55c [4];
  int local_558;
  int local_554;
  uint local_544;
  HDC local_540;
  uint local_53c;
  uint local_538;
  uint local_534;
  uint local_530;
  int local_52c;
  ushort local_528;
  uint local_524;
  HDC local_520;
  int *local_51c;
  uint *local_518;
  ushort *local_514;
  int *local_510;
  int *local_50c;
  int local_508;
  ushort local_504;
  undefined4 local_500 [2];
  uint local_4f8;
  uint local_4f4;
  int local_4f0;
  int local_4dc;
  int local_4ac;
  uint local_4a8;
  uint local_4a4;
  uint local_4a0;
  uint local_49c;
  undefined4 local_484;
  undefined4 local_480;
  int local_47c;
  int local_478;
  int local_430;
  int local_420;
  undefined4 local_41c;
  undefined4 local_418;
  RGBQUAD local_408 [256];
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_508 = in_ECX;
  (**(code **)(**(int **)(in_ECX + 0x24) + 0x90))(*(undefined4 *)(in_ECX + 0x24),&local_510);
  GetObjectA(*(HANDLE *)(local_508 + 0x28),0x18,local_55c);
  local_484 = 0x7c;
  (**(code **)(**(int **)(local_508 + 0x24) + 0x58))(*(undefined4 *)(local_508 + 0x24),&local_484);
  local_480 = 0x101007;
  local_41c = 0x1800;
  local_418 = 0;
  local_478 = local_558;
  local_47c = local_554;
  local_52c = (**(code **)(*local_510 + 0x18))(local_510,&local_484,&local_50c,0);
  if (local_52c < 0) {
    (**(code **)(*local_510 + 8))(local_510);
  }
  else {
    local_520 = CreateCompatibleDC((HDC)0x0);
    if (local_520 == (HDC)0x0) {
      (**(code **)(*local_50c + 8))(local_50c);
      (**(code **)(*local_510 + 8))(local_510);
    }
    else {
      SelectObject(local_520,*(HGDIOBJ *)(local_508 + 0x28));
      if (local_430 == 8) {
        local_530 = 0x44;
        UVar2 = GetDIBColorTable(local_520,0,0x100,local_408);
        for (local_504 = 0; local_504 < (ushort)UVar2; local_504 = local_504 + 1) {
          uVar1._0_1_ = local_408[local_504].rgbBlue;
          uVar1._1_1_ = local_408[local_504].rgbGreen;
          local_408[local_504] =
               (RGBQUAD)((uint)local_408[local_504] >> 0x10 & 0xff | ((int)(uint)uVar1 >> 8) << 8 |
                        ((uint)local_408[local_504] & 0xff) << 0x10);
          if ((*(uint *)(local_508 + 0x1c) & 3) != 0) {
            if ((*(uint *)(local_508 + 0x1c) & 2) == 0) {
              if (((*(uint *)(local_508 + 0x1c) & 1) != 0) &&
                 (local_408[local_504] != (RGBQUAD)0xffffff)) {
                local_408[local_504] = (RGBQUAD)((uint)local_408[local_504] | 0xff000000);
              }
            }
            else if (local_408[local_504] != (RGBQUAD)0x0) {
              local_408[local_504] = (RGBQUAD)((uint)local_408[local_504] | 0xff000000);
            }
          }
        }
        if ((*(uint *)(local_508 + 0x1c) & 3) != 0) {
          local_530 = local_530 | 0x400;
        }
        local_528 = (ushort)UVar2;
        (**(code **)(*local_510 + 0x14))(local_510,local_530,local_408,&local_51c,0);
        (**(code **)(*local_50c + 0x7c))(local_50c,local_51c);
        (**(code **)(**(int **)(local_508 + 0x24) + 0x7c))
                  (*(undefined4 *)(local_508 + 0x24),local_51c);
        if (local_51c != (int *)0x0) {
          (**(code **)(*local_51c + 8))(local_51c);
          local_51c = (int *)0x0;
        }
      }
      iVar3 = (**(code **)(*local_50c + 0x44))(local_50c,&local_540);
      if (-1 < iVar3) {
        BitBlt(local_540,0,0,local_558,local_554,local_520,0,0,0xcc0020);
        (**(code **)(*local_50c + 0x68))(local_50c,local_540);
      }
      DeleteDC(local_520);
      (**(code **)(**(int **)(local_508 + 0x24) + 0x14))
                (*(undefined4 *)(local_508 + 0x24),0,local_50c,0,0x1000000,0);
      (**(code **)(*local_50c + 8))(local_50c);
      if ((local_420 != 0) && ((*(uint *)(local_508 + 0x1c) & 3) != 0)) {
        local_500[0] = 0x7c;
        do {
          iVar3 = (**(code **)(**(int **)(local_508 + 0x24) + 100))
                            (*(undefined4 *)(local_508 + 0x24),0,local_500,0,0);
        } while (iVar3 == -0x7789fde4);
        local_544 = local_49c;
        local_538 = local_4a8 | local_4a4 | local_4a0;
        local_53c = 0;
        if ((*(uint *)(local_508 + 0x1c) & 1) != 0) {
          local_53c = local_538;
        }
        for (local_524 = 0; local_524 < local_4f8; local_524 = local_524 + 1) {
          local_514 = (ushort *)(local_524 * local_4f0 + local_4dc);
          local_518 = (uint *)(local_524 * local_4f0 + local_4dc);
          for (local_534 = 0; local_534 < local_4f4; local_534 = local_534 + 1) {
            if (local_4ac == 0x10) {
              *local_514 = *local_514 & (ushort)local_538;
              if (*local_514 != local_53c) {
                *local_514 = *local_514 | (ushort)local_49c;
              }
              local_514 = local_514 + 1;
            }
            if (local_4ac == 0x20) {
              *local_518 = *local_518 & local_538;
              if (*local_518 != local_53c) {
                *local_518 = *local_518 | local_49c;
              }
              local_518 = local_518 + 1;
            }
          }
        }
        (**(code **)(**(int **)(local_508 + 0x24) + 0x80))(*(undefined4 *)(local_508 + 0x24),0);
      }
      (**(code **)(*local_510 + 8))(local_510);
      local_52c = 0;
    }
  }
  return local_52c;
}

// ============================================================================
// Address: 0x40b630 | Symbol: TextureContainer::CopyRGBADataToSurface
// ============================================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 TextureContainer__CopyRGBADataToSurface(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int in_ECX;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  int local_ac;
  uint local_a4;
  int *local_a0;
  uint local_9c;
  byte local_95;
  int *local_94;
  undefined1 local_8f;
  byte local_8e;
  byte local_8d;
  int local_8c;
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  int local_60;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_8;
  
  local_8 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  local_8c = in_ECX;
  (**(code **)(**(int **)(in_ECX + 0x24) + 0x90))(*(undefined4 *)(in_ECX + 0x24),&local_a0);
  local_84 = 0x7c;
  (**(code **)(**(int **)(local_8c + 0x24) + 0x58))(*(undefined4 *)(local_8c + 0x24),&local_84);
  local_80 = 0x101007;
  local_1c = 0x1800;
  local_18 = 0;
  local_78 = *(uint *)(local_8c + 0xc);
  local_7c = *(uint *)(local_8c + 0x10);
  iVar5 = (**(code **)(*local_a0 + 0x18))(local_a0,&local_84,&local_94,0);
  if (iVar5 < 0) {
    (**(code **)(*local_a0 + 8))(local_a0);
  }
  else {
    do {
      iVar5 = (**(code **)(*local_94 + 100))(local_94,0,&local_84,0,0);
    } while (iVar5 == -0x7789fde4);
    local_ac = local_60;
    bVar8 = 8;
    bVar1 = 0;
    bVar9 = 8;
    bVar2 = 0;
    bVar10 = 8;
    bVar3 = 0;
    bVar11 = 8;
    bVar4 = 0;
    for (local_88 = local_2c; (local_88 != 0 && ((local_88 & 1) == 0)); local_88 = local_88 >> 1) {
      bVar1 = bVar1 + 1;
    }
    for (; local_88 != 0; local_88 = local_88 >> 1) {
      bVar8 = bVar8 - 1;
    }
    for (local_88 = local_28; (local_88 != 0 && ((local_88 & 1) == 0)); local_88 = local_88 >> 1) {
      bVar2 = bVar2 + 1;
    }
    for (; local_88 != 0; local_88 = local_88 >> 1) {
      bVar9 = bVar9 - 1;
    }
    for (local_88 = local_24; (local_88 != 0 && ((local_88 & 1) == 0)); local_88 = local_88 >> 1) {
      bVar3 = bVar3 + 1;
    }
    for (; local_88 != 0; local_88 = local_88 >> 1) {
      bVar10 = bVar10 - 1;
    }
    for (local_88 = local_20; (local_88 != 0 && ((local_88 & 1) == 0)); local_88 = local_88 >> 1) {
      bVar4 = bVar4 + 1;
    }
    for (; local_88 != 0; local_88 = local_88 >> 1) {
      bVar11 = bVar11 - 1;
    }
    for (local_a4 = 0; local_a4 < local_7c; local_a4 = local_a4 + 1) {
      for (local_9c = 0; local_9c < local_78; local_9c = local_9c + 1) {
        uVar7 = *(uint *)(*(int *)(local_8c + 0x2c) + (local_a4 * local_78 + local_9c) * 4);
        local_95 = (byte)(uVar7 >> 0x18);
        local_8d = (byte)(uVar7 >> 0x10);
        local_8e = (byte)(uVar7 >> 8);
        local_8f = (undefined1)uVar7;
        uVar12 = ((int)(uint)local_95 >> (bVar8 & 0x1f)) << (bVar1 & 0x1f) & local_2c;
        uVar6 = ((int)(uint)local_8d >> (bVar9 & 0x1f)) << (bVar2 & 0x1f) & local_28;
        uVar13 = ((int)(uint)local_8e >> (bVar10 & 0x1f)) << (bVar3 & 0x1f) & local_24;
        uVar7 = ((int)(uVar7 & 0xff) >> (bVar11 & 0x1f)) << (bVar4 & 0x1f) & local_20;
        if (local_30 == 0x20) {
          *(uint *)(local_ac + local_9c * 4) = uVar12 + uVar6 + uVar13 + uVar7;
        }
        else {
          *(short *)(local_ac + local_9c * 2) =
               (short)uVar12 + (short)uVar6 + (short)uVar13 + (short)uVar7;
        }
      }
      local_ac = local_ac + local_74;
    }
    (**(code **)(*local_94 + 0x80))(local_94,0);
    (**(code **)(**(int **)(local_8c + 0x24) + 0x14))
              (*(undefined4 *)(local_8c + 0x24),0,local_94,0,0x1000000,0);
    (**(code **)(*local_94 + 8))(local_94);
    (**(code **)(*local_a0 + 8))(local_a0);
  }
  return 0;
}

// ============================================================================
// Address: 0x40bbc0 | Symbol: TextureContainer::TextureContainer
// ============================================================================
undefined4 *
TextureContainer__TextureContainer(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = TextureContainer::vftable;
  *(undefined2 *)(in_ECX + 2) = param_1;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = param_2;
  in_ECX[6] = 0;
  in_ECX[7] = param_3;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[1] = DAT_0048e008;
  DAT_0048e008 = in_ECX;
  return in_ECX;
}

// ============================================================================
// Address: 0x40bc50 | Symbol: TextureContainer::~TextureContainer
// ============================================================================
void TextureContainer___TextureContainer(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00470a82;
  local_10 = ExceptionList;
  uVar1 = DAT_00486cf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = TextureContainer::vftable;
  if (in_ECX[9] != 0) {
    (**(code **)(*(int *)in_ECX[9] + 8))(in_ECX[9],uVar1);
    in_ECX[9] = 0;
  }
  if (in_ECX[0xb] != 0) {
    FUN_0042d26e(in_ECX[0xb],4);
    in_ECX[0xb] = 0;
  }
  DeleteObject((HGDIOBJ)in_ECX[10]);
  if (DAT_0048e008 == in_ECX) {
    DAT_0048e008 = (undefined4 *)in_ECX[1];
  }
  else {
    for (local_18 = DAT_0048e008; local_18 != (undefined4 *)0x0;
        local_18 = (undefined4 *)local_18[1]) {
      if ((undefined4 *)local_18[1] == in_ECX) {
        local_18[1] = in_ECX[1];
      }
    }
  }
  ExceptionList = local_10;
  return;
}

// ============================================================================
// Address: 0x40bd40 | Symbol: TextureSearchCallback
// ============================================================================
undefined4 TextureSearchCallback(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar1 = 1;
  }
  else if ((*(uint *)(param_1 + 4) & 0xe0000) == 0) {
    if (param_2[2] == 0) {
      if (*(uint *)(param_1 + 0xc) < 0x10) {
        uVar1 = 1;
      }
      else if (*(int *)(param_1 + 8) == 0) {
        if (*(int *)(param_1 + 0x1c) == 0xf000) {
          uVar1 = 1;
        }
        else if ((param_2[1] == 1) && ((*(uint *)(param_1 + 4) & 1) == 0)) {
          uVar1 = 1;
        }
        else if ((param_2[1] == 0) && ((*(uint *)(param_1 + 4) & 1) != 0)) {
          uVar1 = 1;
        }
        else if (*(int *)(param_1 + 0xc) == *param_2) {
          FUN_004307f0(param_2[4],param_1,0x20);
          param_2[3] = 1;
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
    else if ((*(uint *)(param_1 + 4) & 0x20) == 0) {
      uVar1 = 1;
    }
    else {
      FUN_004307f0(param_2[4],param_1,0x20);
      param_2[3] = 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

// ============================================================================
// Address: 0x40be70 | Symbol: FindTexture
// ============================================================================
int FindTexture(short param_1)

{
  int local_8;
  
  local_8 = DAT_0048e008;
  while( true ) {
    if (local_8 == 0) {
      return 0;
    }
    if (*(short *)(local_8 + 8) == param_1) break;
    local_8 = *(int *)(local_8 + 4);
  }
  return local_8;
}

// ============================================================================
// Address: 0x40beb0 | Symbol: CD3DTextureManager::CD3DTextureManager
// ============================================================================
undefined4 CD3DTextureManager__CD3DTextureManager(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}

// ============================================================================
// Address: 0x40bec0 | Symbol: CD3DTextureManager::~CD3DTextureManager
// ============================================================================
void CD3DTextureManager___CD3DTextureManager(void)

{
  if ((DAT_0048e008 != (undefined4 *)0x0) && (DAT_0048e008 != (undefined4 *)0x0)) {
    (**(code **)*DAT_0048e008)(1);
  }
  return;
}

// ============================================================================
// Address: 0x40bf00 | Symbol: TextureContainer::
// ============================================================================
undefined4 TextureContainer__(uint param_1)

{
  undefined4 in_ECX;
  
  TextureContainer___TextureContainer();
  if ((param_1 & 1) != 0) {
    FUN_0042d26e(in_ECX,0x30);
  }
  return in_ECX;
}

// ============================================================================
// Address: 0x4022e0 | Symbol: dynamic_initializer_for_g_StaticTextureEngine
// ============================================================================
void dynamic_initializer_for_g_StaticTextureEngine(void)

{
  CD3DTextureManager__CD3DTextureManager();
  _atexit(dynamic_atexit_destructor_for_g_StaticTextureEngine);
  return;
}

// ============================================================================
// Address: 0x472870 | Symbol: dynamic_atexit_destructor_for_g_StaticTextureEngine
// ============================================================================
void dynamic_atexit_destructor_for_g_StaticTextureEngine(void)

{
  CD3DTextureManager___CD3DTextureManager();
  return;
}
