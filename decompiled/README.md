# Hopmon Decompilation Project

Decompiled from `Hopmon.exe` (JJ Soft, 2002) using Ghidra decompiler assisted by full symbol, type, and module metadata extracted from `Hopmon.pdb`.

---

## 1. Package Inventory

The archive `/Users/chaitanyamalhotra/Downloads/hopmon_package.zip` contained:

| File | Size | Role | Description |
| :--- | :--- | :--- | :--- |
| `Hopmon.exe` | 3.1 MB | Binary | Win32 x86 PE executable (compiled with MSVC / DirectX 7 SDK) |
| `Hopmon.pdb` | 6.7 MB | Debug Symbols | Complete unstripped PDB 7.0 with all function names, signatures, class definitions, and member offsets |
| `Manual_E.htm` | 6.6 KB | Documentation | English game manual and control guide |
| `Manual_J.htm` | 7.0 KB | Documentation | Japanese game manual and control guide |
| `Music01.mid` | 22.4 KB | Audio | Title screen / Main theme MIDI music |
| `Music02.mid` | 37.8 KB | Audio | Stage gameplay track 1 |
| `Music03.mid` | 56.1 KB | Audio | Stage gameplay track 2 |
| `Music04.mid` | 34.8 KB | Audio | Ending / High-score theme |

---

## 2. Codebase Organization

The decompiled source code is organized into 29 modules across 3 main categories:

### A. Primary Game Modules (`src/X*.cpp`, `include/X*.h`) - 414 Functions
1. **`XAppMain`** (29 functions)
   - Application entry point (`WinMain`).
   - Single-instance mutex check: `"JJsoft Hopmon Mutex"`.
   - `XApplication` main window, message pump, DirectX 7 device lifecycle, and frame scheduler.
   - `XFPSDisplay` overlay rendering.
2. **`XTitle`** (32 functions)
   - Title screen state machine (`XTitleObject`).
   - Animated background (`XTitleBackground`), logo sequence (`XLogoObject`), level selection menu (`XSelectLevelObject`).
   - Ending sequence display (`XEndingObject`).
3. **`XRegister`** (8 functions)
   - Shareware registration dialog handler (`_ChangeRegisterProc`, `_ExecuteRgisterDialog`).
   - Key verification (`_CheckRegistrationKey`) and licensing status (`IsRegistered`).
4. **`XGame`** (23 functions)
   - Game session controller (`XGameObject`).
   - Stage lifecycle, score counter, collected crystals, camera orientation (`XCamera`), and in-game HUD (`XStatusDisplay`).
5. **`XMap`** (53 functions)
   - Grid-based 3D tile map system (`XMap`).
   - Map loading, tile properties (passable, pit, wall, ice, conveyor belts), grid collision detection, and mini-map preview (`XPreviewMap`).
6. **`XMapObject`** (42 functions)
   - Interactive map entities inheriting `XMapObjectBase`.
   - Stationary hazards and mechanisms: `XCannon`, `XCannonUp`, `XSteam`, `XVolcano`, `XPole`, `XShortPole`, `XGate`, and `XTree`.
7. **`XPac`** (37 functions)
   - Protagonist character Hopmon (`XPac`).
   - Movement, jumping, grid navigation, rotation physics, health, and shooting energy.
   - Projectile weapon system: `XPacFire` and container `XPacFireList`.
8. **`XEnemy`** (91 functions)
   - Base enemy AI framework (`XEnemyBase`, `XEnemyList`).
   - Specific enemy behaviors:
     - `XEnemy_Cube`: Wandering block enemy.
     - `XEnemy_Ghost`: Phasing enemy tracker.
     - `XEnemy_Kurage`: Jellyfish floating patroller.
     - `XEnemy_Sesame`: Fast chaser.
     - `XEnemy_UFO`: Hovering flying enemy.
     - `XNeedleBall`, `XNeedleBallFast`: Rolling spiked hazards.
     - `XNeedleBox`, `XNeedleBoxDrop`: Dropping spike traps.
   - Enemy projectiles: `XEnemyFire_Cannon`, `XEnemyFire_CannonUp`, `XEnemyFire_Steam`, `XEnemyFire_UFO`.
9. **`XChara`** (99 functions)
   - 3D character mesh animation, keyframe interpolation, and model rendering.
   - Collectible items: `XCrystal`, `XCrystalList`.
   - Particle effect systems: `XParticleBase`, `XParticleList`, `XParticle_EnemyExplode`, `XParticle_EnemyFireSmokeGreen`, `XParticle_EnemyFireSmokePurple`, `XParticle_PacFireHit`.

---

### B. Custom Engine Utilities (`src/J*.cpp`, `include/J*.h`) - 289 Functions
1. **`JWinReg`** (17 functions): Registry persistence for user settings, controls, and high scores under `Software\\JJsoft\\Hopmon`.
2. **`JSurface`** (24 functions): DirectDraw surface allocation, bitmap texture loading, and palette management.
3. **`JString` & `JStringList`** (45 functions): Dynamic string buffers and list containers.
4. **`JStandard`** (7 functions): Fast memory, math, and string helper routines.
5. **`JSprite`** (27 functions): 2D HUD sprite rendering, billboarding, and 2D-in-3D projections.
6. **`JSound`** (23 functions): DirectSound sound effect loader and 3D positional audio player.
7. **`JObject3D`** (82 functions): 3D hierarchy, bounding boxes, mesh transformation, shadows (`JObject3D_Shadow`), and rectangular sprites (`JObject3D_Rect`).
8. **`JMidi`** (14 functions): Background music MIDI sequencer and DirectMusic playback.
9. **`JList`** (13 functions): Generic linked-list and numeric node lists (`JBaseList`, `JNumber`).
10. **`JDinput`** (24 functions): DirectInput keyboard, mouse, and game controller input polling.
11. **`JAscii`** (13 functions): Bitmap text font rendering.

---

### C. DirectX 7 SDK Framework (`src/d3d*.cpp`, `src/ddutil.cpp`) - 197 Functions
Standard Microsoft DirectX 7 sample library components customized for Hopmon:
- **`d3dapp`** (55 functions): `CD3DApplication` base class wrapping Win32 windows, DirectDraw7, and Direct3D7 device initialization.
- **`d3dfile`** (53 functions): Parser for DirectX `.X` 3D mesh files (`CD3DFile`, `CD3DFileObject`).
- **`d3dframe`** (18 functions): Direct3D frame hierarchy and bone hierarchy transforms (`CD3DFramework7`).
- **`d3dmath`** (15 functions): 3D vector and matrix math operations (`D3DMath_VectorMatrixMultiply`, etc.).
- **`d3dtextr`** (21 functions): Texture cache manager (`CD3DTextureManager`).
- **`d3dutil`** (15 functions): General D3D utility functions.
- **`ddutil`** (6 functions): DirectDraw surface creation and bitmap blitting helpers.
- **`d3denum`** (14 functions): Direct3D 7 display mode, device, and driver enumeration.

---

## 3. Directory Layout

```
hopmon/
├── Hopmon.exe                     # Original executable
├── Hopmon.pdb                     # Original debug database
├── Manual_E.htm                   # English documentation
├── Manual_J.htm                   # Japanese documentation
├── Music01.mid - Music04.mid      # Audio assets
└── decompiled/
    ├── README.md                  # This document
    ├── include/                   # 24 Recovered C++ headers with full class definitions
    └── src/                       # 29 Decompiled C++ implementation files (900 functions)
```
