# Hopmon 3D (2002) — WebAssembly Port

A modern C++17 and WebAssembly (Wasm) port of **Hopmon**, the classic 3D arcade action game originally developed in 2002 by **JJ Soft / Saito Games** (James Saito, music by T. Kinoshita).

Play directly in your browser with hardware-accelerated WebGL 2.0, authentic 3D Gouraud-shaded characters, original soundtrack, and responsive controls.

---

## Overview

In *Hopmon*, you control a cheerful yellow creature who must navigate 3D grid labyrinths, collect crystals, and bring them back to the **Green Star Warp Zone (`*`)**. 

Unlike standard collection games, Hopmon **stacks collected crystals vertically on his head**, hopping with them in tow. Only after depositing all level crystals onto the Star Warp Zone does the exit portal illuminate to warp you to the next stage.

---

## Features

- **100% Decompiled & Restored**: Re-engineered from the original 2002 Win32 PE32 executable and unstripped `Hopmon.pdb` debug database.
- **Authentic Visuals & Textures**:
  - Blue cobblestone corridors with dark mortar lines.
  - Dual-textured 3D walls: grey stone slab tops and sandstone brick facades.
  - Green Star Warp Zone, conveyor belt directional arrows, and hazard pits.
  - Deep space void grid background floor.
- **3D Character Shading**:
  - Hopmon with his soft golden yellow body, brown ear tufts, black cat eyes, white sclera reflections, and blue feet.
  - Parabolic hop arc kinematics ($y = 16 \cdot \sin(\pi \cdot t)$) with squash-and-stretch landing.
  - Planar drop shadows that scale dynamically with jump height.
- **Combat & Enemy AI**:
  - Active patrolling enemies: wandering Cubes, floating Ghosts, and hovering UFOs.
  - Glowing energy projectiles (<kbd>Space</kbd> / <kbd>Z</kbd>) with segmented recharge gauge, wall deflections, and particle explosions.
- **Authentic Soundtrack & Audio**:
  - Complete 13-track General MIDI soundtrack rendered with the **Roland GS Sound Set** (`Music01.mp3` through `Music04.mp3`).
  - Spatial sound effects for hopping, crystal pickups, shooting, hits, and level clear fanfares.
- **Multi-Level Progression**:
  - 71 stage maps extracted from original `RT_RCDATA` resources (Levels 1 to 45).

---

## Controls

| Action | Primary Key | Secondary Key |
| :--- | :--- | :--- |
| **Move Hopmon** | <kbd>▲</kbd> <kbd>▼</kbd> <kbd>◀</kbd> <kbd>▶</kbd> | <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> |
| **Shoot Projectile** | <kbd>Space</kbd> | <kbd>Z</kbd> / <kbd>Shift</kbd> |
| **Deposit Crystals** | Walk onto Green Star (`*`) | — |
| **Skip / Next Level** | <kbd>Enter</kbd> | — |

---

## Quick Start (Playing in Browser)

The game runs as a static WebAssembly bundle requiring no installation:

```bash
# Start any local HTTP server in the web/ directory:
python3 -m http.server 8080 --directory web
```

Open **`http://localhost:8080/`** in Chrome, Firefox, Safari, or Edge.

---

## Building from Source

### Prerequisites
- [Emscripten SDK](https://emscripten.org/) (`emcc` / `em++` 3.x or 4.x+)

### Compile to WebAssembly
```bash
em++ -std=c++17 -O2 \
  src/main.cpp \
  hal/GfxDevice.cpp \
  hal/XFileParser.cpp \
  hal/AudioDevice.cpp \
  hal/InputDevice.cpp \
  hal/Storage.cpp \
  -Ihal/ \
  -sUSE_SDL=2 \
  -sUSE_WEBGL2=1 \
  -sALLOW_MEMORY_GROWTH=1 \
  -sINITIAL_MEMORY=64MB \
  --preload-file assets@assets \
  --shell-file web/shell.html \
  -o web/index.html
```

---

## Directory Structure

```
hopmon/
├── README.md                     # This file
├── PORT_PLAN.md                  # Comprehensive 460-line reverse engineering & porting plan
├── assets/                       # Extracted game assets
│   ├── models/                   # 27 DirectX .X 3D meshes (Pac_1.x … Pac_4.x, etc.)
│   ├── textures/                 # Sliced textures (floor, walls, star, conveyors)
│   ├── audio/                    # 18 WAV sound effects
│   ├── music/                    # 4 original MIDI files + rendered MP3 tracks
│   └── maps/                     # 71 stage layouts (map_*.txt)
├── hal/                          # Platform Abstraction Layer
│   ├── GfxDevice.h / .cpp        # WebGL 2 fixed-function shader emulator
│   ├── XFileParser.h / .cpp      # DirectX .X mesh & material parser
│   ├── AudioDevice.h / .cpp      # Web Audio SFX & BGM streamer
│   ├── InputDevice.h / .cpp      # Keyboard, touch, and gamepad mapping
│   └── Storage.h / .cpp          # localStorage save state
├── src/
│   └── main.cpp                  # Game loop, Hopmon physics, enemy AI, stage rules
└── web/                          # Web deployment files
    ├── index.html                # Canvas container & player shell
    ├── index.js                  # Emscripten runtime glue
    ├── index.wasm                # 537 KB WebAssembly binary
    └── index.data                # Preloaded virtual filesystem
```

---

## Credits & Licensing

- **Original Game**: Copyright &copy; 2001–2009 **Saito Games** (James Saito).
- **Original Music**: Composed by **T. Kinoshita**.
- **Port**: Decompiled, modernized, and ported to WebAssembly for educational and preservation purposes.
