#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

#include <SDL2/SDL.h>
#include "../hal/GfxDevice.h"
#include "../hal/XFileParser.h"
#include "../hal/AudioDevice.h"
#include "../hal/InputDevice.h"
#include "../hal/Storage.h"

struct Projectile {
    float x, z;
    float dirX, dirZ;
    float speed = 10.0f;
    int life = 70;
    bool active = false;
};

struct Enemy {
    float x, z;
    float targetX, targetZ;
    float speed = 2.0f;
    int type = 0; // 0=Cube, 1=Ghost, 2=UFO
    int hp = 1;
    bool active = true;
    bool moving = false;
    int dir = 0;
    int moveTimer = 0;
};

struct Particle {
    float x, y, z;
    float vx, vy, vz;
    float life = 1.0f;
    Vec4 color;
    bool active = false;
};

struct Crystal {
    int gx, gz;
    float worldX = 0.0f;
    float worldZ = 0.0f;
    bool carried = false;
    bool deposited = false;
};

struct GameState {
    SDL_Window* window = nullptr;
    bool running = true;
    uint32_t frameCount = 0;

    int currentLevel = 1;
    int lives = 3;
    int score = 0;
    float fireEnergy = 100.0f;

    // Player (Hopmon)
    float playerX = 0.0f;
    float playerZ = 0.0f;
    float playerY = 0.0f;
    float startX = 0.0f;
    float startZ = 0.0f;
    float targetX = 0.0f;
    float targetZ = 0.0f;
    float stepProgress = 0.0f;
    float playerRotY = 0.0f;
    float targetRotY = 0.0f;
    int faceDir = 2; // 0=N, 1=E, 2=S, 3=W
    bool moving = false;
    int animFrame = 0;
    int invulnTimer = 0;

    int carriedCount = 0;
    int depositedCount = 0;
    int totalCrystals = 0;
    bool portalActive = false;
    bool levelCleared = false;
    int levelClearTimer = 0;

    std::vector<std::string> mapLines;
    int mapWidth = 0;
    int mapHeight = 0;
    float halfWidth = 0.0f;
    float halfHeight = 0.0f;
    int exitGX = 0;
    int exitGZ = 0;
    float exitWorldX = 0.0f;
    float exitWorldZ = 0.0f;

    // Meshes
    LoadedMesh meshPac[4];
    LoadedMesh meshCrystal;
    LoadedMesh meshEnemyA; // Cube
    LoadedMesh meshEnemyB; // Ghost
    LoadedMesh meshEnemyD; // UFO
    LoadedMesh meshCannon;

    // Sliced Textures
    uint32_t texFloor = 0;
    uint32_t texWallTop = 0;
    uint32_t texWallSide = 0;
    uint32_t texBridgeH = 0;
    uint32_t texBridgeV = 0;
    uint32_t texWarp = 0;
    uint32_t texHole = 0;
    uint32_t texConvUp = 0;
    uint32_t texConvRight = 0;
    uint32_t texConvDown = 0;
    uint32_t texConvLeft = 0;
    uint32_t texShadow = 0;
    uint32_t texBgGrid = 0;

    // Procedural Buffers
    uint32_t quadMeshId = 0;
    uint32_t wallTopMeshId = 0;
    uint32_t wallSidesMeshId = 0;
    uint32_t shadowMeshId = 0;
    uint32_t projMeshId = 0;
    uint32_t bgGridMeshId = 0;

    std::vector<Crystal> crystals;
    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;
    std::vector<Particle> particles;
};

static GameState gGame;

static inline float GridToWorldX(int gx, float halfW) {
    return (gx * 40.0f + 20.0f) - halfW;
}

static inline float GridToWorldZ(int gz, float halfH) {
    return (gz * 40.0f + 20.0f) - halfH;
}

static inline int WorldToGridX(float wx, float halfW) {
    return (int)roundf((wx + halfW - 20.0f) / 40.0f);
}

static inline int WorldToGridZ(float wz, float halfH) {
    return (int)roundf((wz + halfH - 20.0f) / 40.0f);
}

static void CreateMeshes(GameState& state) {
    // 1. Standard Flat Quad (40x40 at y=0, UVs 0..1)
    std::vector<Vertex> qVerts = {
        { -20.0f, 0.0f, -20.0f,  0, 1, 0,  0.0f, 0.0f,  0xFFFFFFFF },
        {  20.0f, 0.0f, -20.0f,  0, 1, 0,  1.0f, 0.0f,  0xFFFFFFFF },
        {  20.0f, 0.0f,  20.0f,  0, 1, 0,  1.0f, 1.0f,  0xFFFFFFFF },
        { -20.0f, 0.0f,  20.0f,  0, 1, 0,  0.0f, 1.0f,  0xFFFFFFFF }
    };
    std::vector<uint16_t> qIdx = { 0, 1, 2, 0, 2, 3 };
    state.quadMeshId = GfxDevice::Instance().CreateMeshBuffer(qVerts, qIdx);

    // 2. Wall Top Quad (40x40 at y=40, UVs 0..1)
    std::vector<Vertex> wtVerts = {
        { -20.0f, 40.0f, -20.0f,  0, 1, 0,  0.0f, 0.0f,  0xFFFFFFFF },
        {  20.0f, 40.0f, -20.0f,  0, 1, 0,  1.0f, 0.0f,  0xFFFFFFFF },
        {  20.0f, 40.0f,  20.0f,  0, 1, 0,  1.0f, 1.0f,  0xFFFFFFFF },
        { -20.0f, 40.0f,  20.0f,  0, 1, 0,  0.0f, 1.0f,  0xFFFFFFFF }
    };
    state.wallTopMeshId = GfxDevice::Instance().CreateMeshBuffer(wtVerts, qIdx);

    // 3. Wall 4 Sides (40x40 each, UVs 0..1)
    std::vector<Vertex> wsVerts;
    std::vector<uint16_t> wsIdx;
    auto addSide = [&](Vec3 p0, Vec3 p1, Vec3 p2, Vec3 p3, Vec3 n) {
        uint16_t b = (uint16_t)wsVerts.size();
        wsVerts.push_back({ p0.x, p0.y, p0.z, n.x, n.y, n.z, 0.0f, 0.0f, 0xFFFFFFFF });
        wsVerts.push_back({ p1.x, p1.y, p1.z, n.x, n.y, n.z, 1.0f, 0.0f, 0xFFFFFFFF });
        wsVerts.push_back({ p2.x, p2.y, p2.z, n.x, n.y, n.z, 1.0f, 1.0f, 0xFFFFFFFF });
        wsVerts.push_back({ p3.x, p3.y, p3.z, n.x, n.y, n.z, 0.0f, 1.0f, 0xFFFFFFFF });
        wsIdx.push_back(b);     wsIdx.push_back(b + 1); wsIdx.push_back(b + 2);
        wsIdx.push_back(b);     wsIdx.push_back(b + 2); wsIdx.push_back(b + 3);
    };
    addSide({-20,0,20}, {20,0,20}, {20,40,20}, {-20,40,20}, {0,0,1});
    addSide({20,0,-20}, {-20,0,-20}, {-20,40,-20}, {20,40,-20}, {0,0,-1});
    addSide({-20,0,-20}, {-20,0,20}, {-20,40,20}, {-20,40,-20}, {-1,0,0});
    addSide({20,0,20}, {20,0,-20}, {20,40,-20}, {20,40,20}, {1,0,0});
    state.wallSidesMeshId = GfxDevice::Instance().CreateMeshBuffer(wsVerts, wsIdx);

    // 4. Planar Shadow Quad
    std::vector<Vertex> sVerts = {
        { -16.0f, 1.0f, -16.0f,  0, 1, 0,  0.0f, 0.0f,  0xFFFFFFFF },
        {  16.0f, 1.0f, -16.0f,  0, 1, 0,  1.0f, 0.0f,  0xFFFFFFFF },
        {  16.0f, 1.0f,  16.0f,  0, 1, 0,  1.0f, 1.0f,  0xFFFFFFFF },
        { -16.0f, 1.0f,  16.0f,  0, 1, 0,  0.0f, 1.0f,  0xFFFFFFFF }
    };
    state.shadowMeshId = GfxDevice::Instance().CreateMeshBuffer(sVerts, qIdx);

    // 5. Projectile Ball (Octahedron)
    std::vector<Vertex> pVerts = {
        {  0.0f,  5.0f,  0.0f,  0, 1, 0, 0, 0, 0xFFFFFF00 },
        { -4.0f,  0.0f, -4.0f, -1, 0,-1, 0, 0, 0xFFFFAA00 },
        {  4.0f,  0.0f, -4.0f,  1, 0,-1, 0, 0, 0xFFFFAA00 },
        {  4.0f,  0.0f,  4.0f,  1, 0, 1, 0, 0, 0xFFFFAA00 },
        { -4.0f,  0.0f,  4.0f, -1, 0, 1, 0, 0, 0xFFFFAA00 },
        {  0.0f, -5.0f,  0.0f,  0,-1, 0, 0, 0, 0xFFFF3300 }
    };
    std::vector<uint16_t> pIdx = {
        0, 1, 2,  0, 2, 3,  0, 3, 4,  0, 4, 1,
        5, 2, 1,  5, 3, 2,  5, 4, 3,  5, 1, 4
    };
    state.projMeshId = GfxDevice::Instance().CreateMeshBuffer(pVerts, pIdx);

    // 6. Purple Space Grid Floor (underneath the void, at y = -200)
    std::vector<Vertex> bgVerts = {
        { -1500.0f, -120.0f, -1500.0f,  0, 1, 0,   0.0f,   0.0f, 0xFFFFFFFF },
        {  1500.0f, -120.0f, -1500.0f,  0, 1, 0,  30.0f,   0.0f, 0xFFFFFFFF },
        {  1500.0f, -120.0f,  1500.0f,  0, 1, 0,  30.0f,  30.0f, 0xFFFFFFFF },
        { -1500.0f, -120.0f,  1500.0f,  0, 1, 0,   0.0f,  30.0f, 0xFFFFFFFF }
    };
    state.bgGridMeshId = GfxDevice::Instance().CreateMeshBuffer(bgVerts, qIdx);
}

static void SpawnExplosion(GameState& state, float x, float y, float z, const Vec4& color) {
    for (int i = 0; i < 24; ++i) {
        float angle = (float)i * (6.28318f / 24.0f);
        float speed = 2.0f + (float)(rand() % 30) * 0.1f;
        Particle p;
        p.x = x; p.y = y + 8.0f; p.z = z;
        p.vx = cosf(angle) * speed;
        p.vy = 2.5f + (float)(rand() % 35) * 0.1f;
        p.vz = sinf(angle) * speed;
        p.color = color;
        p.life = 1.0f;
        p.active = true;
        state.particles.push_back(p);
    }
}

static void LoadStage(GameState& state, int levelNum) {
    state.currentLevel = levelNum;
    state.crystals.clear();
    state.enemies.clear();
    state.projectiles.clear();
    state.particles.clear();
    state.carriedCount = 0;
    state.depositedCount = 0;
    state.portalActive = false;
    state.levelCleared = false;
    state.levelClearTimer = 0;

    std::string filename;
    if (levelNum == 1) filename = "assets/maps/map_265.txt";
    else if (levelNum == 2) filename = "assets/maps/map_266.txt";
    else if (levelNum == 3) filename = "assets/maps/map_267.txt";
    else filename = "assets/maps/map_148.txt";

    std::ifstream file(filename);
    if (!file.is_open()) return;

    state.mapLines.clear();
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.find('_') != std::string::npos) break;
        state.mapLines.push_back(line);
    }
    state.mapHeight = (int)state.mapLines.size();
    state.mapWidth = state.mapHeight > 0 ? (int)state.mapLines[0].size() : 0;
    state.halfWidth = (state.mapWidth * 40.0f) / 2.0f;
    state.halfHeight = (state.mapHeight * 40.0f) / 2.0f;

    for (int y = 0; y < state.mapHeight; ++y) {
        for (int x = 0; x < (int)state.mapLines[y].size(); ++x) {
            char c = state.mapLines[y][x];
            float wx = GridToWorldX(x, state.halfWidth);
            float wz = GridToWorldZ(y, state.halfHeight);

            if (c == '@' || c == 'P') {
                state.playerX = wx;
                state.playerZ = wz;
                state.startX = wx;
                state.startZ = wz;
                state.targetX = wx;
                state.targetZ = wz;
                state.playerY = 0.0f;
                state.moving = false;
                state.stepProgress = 0.0f;
            } else if (c == '$') {
                Crystal cr;
                cr.gx = x;
                cr.gz = y;
                cr.worldX = wx;
                cr.worldZ = wz;
                cr.carried = false;
                cr.deposited = false;
                state.crystals.push_back(cr);
            } else if (c == '*') {
                state.exitGX = x;
                state.exitGZ = y;
                state.exitWorldX = wx;
                state.exitWorldZ = wz;
            } else if (c == 'a' || c == 'b' || c == 'c') {
                Enemy en;
                en.x = wx;
                en.z = wz;
                en.targetX = wx;
                en.targetZ = wz;
                en.type = (c == 'a') ? 0 : (c == 'b' ? 1 : 2);
                en.hp = 1;
                en.active = true;
                en.dir = rand() % 4;
                state.enemies.push_back(en);
            }
        }
    }
    state.totalCrystals = (int)state.crystals.size();

    // Play authentic Stage BGM!
    AudioDevice::Instance().PlayBGM(2);

    std::cout << "Loaded Level " << levelNum << " (" << state.mapWidth << "x" << state.mapHeight 
              << "): " << state.totalCrystals << " crystals, " << state.enemies.size() << " enemies!" << std::endl;
}

static bool IsTilePassable(const GameState& state, int gx, int gz) {
    if (gz < 0 || gz >= state.mapHeight) return false;
    if (gx < 0 || gx >= (int)state.mapLines[gz].size()) return false;
    char c = state.mapLines[gz][gx];
    if (c == '.' || c == '1' || c == '2' || c == '3') return false;
    if (c >= 'A' && c <= 'Z' && c != 'P') return false;
    return true;
}

static void PlayerShoot(GameState& state) {
    if (state.fireEnergy < 25.0f || state.levelCleared) return;
    state.fireEnergy -= 25.0f;

    Projectile p;
    p.x = state.playerX;
    p.z = state.playerZ;

    if (state.faceDir == 0)      { p.dirX =  0.0f; p.dirZ = -1.0f; }
    else if (state.faceDir == 1) { p.dirX =  1.0f; p.dirZ =  0.0f; }
    else if (state.faceDir == 2) { p.dirX =  0.0f; p.dirZ =  1.0f; }
    else                         { p.dirX = -1.0f; p.dirZ =  0.0f; }

    p.life = 60;
    p.active = true;
    state.projectiles.push_back(p);
    AudioDevice::Instance().PlaySFX(2, 0.0f, 0.7f);
}

static void MainLoopIteration() {
    InputDevice::Instance().Update();

    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        if (ev.type == SDL_QUIT) {
            gGame.running = false;
        } else if (ev.type == SDL_KEYDOWN) {
            if (ev.key.keysym.sym == SDLK_UP || ev.key.keysym.sym == SDLK_w)
                InputDevice::Instance().SetKeyState(KEY_UP, true);
            if (ev.key.keysym.sym == SDLK_DOWN || ev.key.keysym.sym == SDLK_s)
                InputDevice::Instance().SetKeyState(KEY_DOWN, true);
            if (ev.key.keysym.sym == SDLK_LEFT || ev.key.keysym.sym == SDLK_a)
                InputDevice::Instance().SetKeyState(KEY_LEFT, true);
            if (ev.key.keysym.sym == SDLK_RIGHT || ev.key.keysym.sym == SDLK_d)
                InputDevice::Instance().SetKeyState(KEY_RIGHT, true);
            if (ev.key.keysym.sym == SDLK_SPACE || ev.key.keysym.sym == SDLK_z || ev.key.keysym.sym == SDLK_LSHIFT) {
                InputDevice::Instance().SetKeyState(KEY_FIRE, true);
                PlayerShoot(gGame);
            }
            if (ev.key.keysym.sym == SDLK_RETURN) {
                LoadStage(gGame, (gGame.currentLevel % 3) + 1);
            }
        } else if (ev.type == SDL_KEYUP) {
            if (ev.key.keysym.sym == SDLK_UP || ev.key.keysym.sym == SDLK_w)
                InputDevice::Instance().SetKeyState(KEY_UP, false);
            if (ev.key.keysym.sym == SDLK_DOWN || ev.key.keysym.sym == SDLK_s)
                InputDevice::Instance().SetKeyState(KEY_DOWN, false);
            if (ev.key.keysym.sym == SDLK_LEFT || ev.key.keysym.sym == SDLK_a)
                InputDevice::Instance().SetKeyState(KEY_LEFT, false);
            if (ev.key.keysym.sym == SDLK_RIGHT || ev.key.keysym.sym == SDLK_d)
                InputDevice::Instance().SetKeyState(KEY_RIGHT, false);
            if (ev.key.keysym.sym == SDLK_SPACE || ev.key.keysym.sym == SDLK_z || ev.key.keysym.sym == SDLK_LSHIFT)
                InputDevice::Instance().SetKeyState(KEY_FIRE, false);
        }
    }

    gGame.frameCount++;

    if (gGame.fireEnergy < 100.0f) gGame.fireEnergy += 0.8f;
    if (gGame.invulnTimer > 0) gGame.invulnTimer--;

    // -------------------------------------------------------------
    // PLAYER MOVEMENT & SIGNATURE HOP
    // -------------------------------------------------------------
    if (!gGame.moving && !gGame.levelCleared) {
        int curGX = WorldToGridX(gGame.playerX, gGame.halfWidth);
        int curGZ = WorldToGridZ(gGame.playerZ, gGame.halfHeight);
        int nextGX = curGX;
        int nextGZ = curGZ;

        if (InputDevice::Instance().IsPressed(KEY_UP)) {
            nextGZ -= 1;
            gGame.targetRotY = 3.14159f;
            gGame.faceDir = 0;
        } else if (InputDevice::Instance().IsPressed(KEY_DOWN)) {
            nextGZ += 1;
            gGame.targetRotY = 0.0f;
            gGame.faceDir = 2;
        } else if (InputDevice::Instance().IsPressed(KEY_LEFT)) {
            nextGX -= 1;
            gGame.targetRotY = -1.57079f;
            gGame.faceDir = 3;
        } else if (InputDevice::Instance().IsPressed(KEY_RIGHT)) {
            nextGX += 1;
            gGame.targetRotY = 1.57079f;
            gGame.faceDir = 1;
        }

        if (nextGX != curGX || nextGZ != curGZ) {
            if (IsTilePassable(gGame, nextGX, nextGZ)) {
                gGame.targetX = GridToWorldX(nextGX, gGame.halfWidth);
                gGame.targetZ = GridToWorldZ(nextGZ, gGame.halfHeight);
                gGame.moving = true;
                gGame.stepProgress = 0.0f;
                AudioDevice::Instance().PlaySFX(0, 0.0f, 0.6f);
            }
        }
    } else if (gGame.moving) {
        float stepSpeed = 0.09f;
        gGame.stepProgress += stepSpeed;

        if (gGame.stepProgress >= 1.0f) {
            gGame.stepProgress = 1.0f;
            gGame.playerX = gGame.targetX;
            gGame.playerZ = gGame.targetZ;
            gGame.playerY = 0.0f;
            gGame.moving = false;

            int curGX = WorldToGridX(gGame.playerX, gGame.halfWidth);
            int curGZ = WorldToGridZ(gGame.playerZ, gGame.halfHeight);

            // 1. Crystal Pickup (Hopmon stacks crystal on head!)
            for (auto& c : gGame.crystals) {
                if (!c.carried && !c.deposited && c.gx == curGX && c.gz == curGZ) {
                    c.carried = true;
                    gGame.carriedCount++;
                    gGame.score += 50;
                    AudioDevice::Instance().PlaySFX(1, 0.0f, 0.9f);
                    SpawnExplosion(gGame, gGame.playerX, 10.0f, gGame.playerZ, {0.95f, 0.35f, 0.85f, 1.0f});
                }
            }

            // 2. Deposit Crystals at Green Star Warp Zone (*)
            if (curGX == gGame.exitGX && curGZ == gGame.exitGZ) {
                if (gGame.carriedCount > 0) {
                    for (auto& c : gGame.crystals) {
                        if (c.carried && !c.deposited) {
                            c.carried = false;
                            c.deposited = true;
                        }
                    }
                    gGame.score += gGame.carriedCount * 250;
                    gGame.depositedCount += gGame.carriedCount;
                    gGame.carriedCount = 0;
                    AudioDevice::Instance().PlaySFX(6, 0.0f, 1.0f); // Deposit chime

                    if (gGame.depositedCount >= gGame.totalCrystals) {
                        gGame.portalActive = true;
                        AudioDevice::Instance().PlaySFX(7, 0.0f, 1.0f); // Portal activated fanfare!
                    }
                } else if (gGame.portalActive && !gGame.levelCleared) {
                    gGame.levelCleared = true;
                    gGame.levelClearTimer = 110;
                    AudioDevice::Instance().PlaySFX(7, 0.0f, 1.0f);
                }
            }
        } else {
            float dx = gGame.targetX - gGame.playerX;
            float dz = gGame.targetZ - gGame.playerZ;
            gGame.playerX += dx * 0.22f;
            gGame.playerZ += dz * 0.22f;

            // Parabolic Hop Arc
            gGame.playerY = 16.0f * sinf(3.14159f * gGame.stepProgress);
        }
    }

    if (gGame.levelCleared) {
        gGame.levelClearTimer--;
        gGame.playerRotY += 0.25f;
        gGame.animFrame = 3; // Pac_4 victory frame
        if (gGame.levelClearTimer <= 0) {
            LoadStage(gGame, (gGame.currentLevel % 3) + 1);
        }
    } else {
        float rotDiff = gGame.targetRotY - gGame.playerRotY;
        while (rotDiff > 3.14159f) rotDiff -= 6.28318f;
        while (rotDiff < -3.14159f) rotDiff += 6.28318f;
        gGame.playerRotY += rotDiff * 0.32f;

        if (gGame.moving) {
            gGame.animFrame = (gGame.frameCount / 5) % 3;
        } else {
            gGame.animFrame = 0;
        }
    }

    // -------------------------------------------------------------
    // PROJECTILES
    // -------------------------------------------------------------
    for (auto& p : gGame.projectiles) {
        if (!p.active) continue;
        p.x += p.dirX * p.speed;
        p.z += p.dirZ * p.speed;
        p.life--;

        int pgx = WorldToGridX(p.x, gGame.halfWidth);
        int pgz = WorldToGridZ(p.z, gGame.halfHeight);

        if (!IsTilePassable(gGame, pgx, pgz) || p.life <= 0) {
            p.active = false;
            SpawnExplosion(gGame, p.x, 10.0f, p.z, {1.0f, 0.85f, 0.2f, 1.0f});
            AudioDevice::Instance().PlaySFX(3, 0.0f, 0.4f);
            continue;
        }

        for (auto& en : gGame.enemies) {
            if (!en.active) continue;
            float edx = en.x - p.x;
            float edz = en.z - p.z;
            if (sqrtf(edx*edx + edz*edz) < 24.0f) {
                en.hp--;
                p.active = false;
                if (en.hp <= 0) {
                    en.active = false;
                    gGame.score += 500;
                    SpawnExplosion(gGame, en.x, 15.0f, en.z, {1.0f, 0.3f, 0.2f, 1.0f});
                    AudioDevice::Instance().PlaySFX(4, 0.0f, 0.8f);
                }
                break;
            }
        }
    }

    // -------------------------------------------------------------
    // ENEMY PATROL
    // -------------------------------------------------------------
    for (auto& en : gGame.enemies) {
        if (!en.active) continue;

        if (!en.moving) {
            en.moveTimer++;
            if (en.moveTimer > 18) {
                en.moveTimer = 0;
                int egx = WorldToGridX(en.x, gGame.halfWidth);
                int egz = WorldToGridZ(en.z, gGame.halfHeight);
                int ndx = 0, ndz = 0;

                if (rand() % 4 == 0) en.dir = rand() % 4;

                if (en.dir == 0) ndz = -1;
                else if (en.dir == 1) ndx = 1;
                else if (en.dir == 2) ndz = 1;
                else ndx = -1;

                if (IsTilePassable(gGame, egx + ndx, egz + ndz)) {
                    en.targetX = GridToWorldX(egx + ndx, gGame.halfWidth);
                    en.targetZ = GridToWorldZ(egz + ndz, gGame.halfHeight);
                    en.moving = true;
                } else {
                    en.dir = (en.dir + 1) % 4;
                }
            }
        } else {
            float dx = en.targetX - en.x;
            float dz = en.targetZ - en.z;
            float dist = sqrtf(dx*dx + dz*dz);
            if (dist <= en.speed) {
                en.x = en.targetX;
                en.z = en.targetZ;
                en.moving = false;
            } else {
                en.x += (dx / dist) * en.speed;
                en.z += (dz / dist) * en.speed;
            }
        }

        if (gGame.invulnTimer <= 0 && !gGame.levelCleared) {
            float pdx = gGame.playerX - en.x;
            float pdz = gGame.playerZ - en.z;
            if (sqrtf(pdx*pdx + pdz*pdz) < 25.0f) {
                gGame.lives--;
                gGame.invulnTimer = 90;
                AudioDevice::Instance().PlaySFX(5, 0.0f, 1.0f);
                SpawnExplosion(gGame, gGame.playerX, 15.0f, gGame.playerZ, {1.0f, 0.1f, 0.1f, 1.0f});
                if (gGame.lives < 0) {
                    gGame.lives = 3;
                    gGame.score = 0;
                    LoadStage(gGame, 1);
                }
            }
        }
    }

    // Particles
    for (auto& pt : gGame.particles) {
        if (!pt.active) continue;
        pt.x += pt.vx;
        pt.y += pt.vy;
        pt.z += pt.vz;
        pt.vy -= 0.18f;
        pt.life -= 0.035f;
        if (pt.life <= 0.0f) pt.active = false;
    }

    // -------------------------------------------------------------
    // RENDER PASS (1:1 with original Hopmon view)
    // -------------------------------------------------------------
    GfxDevice::Instance().BeginScene(0.04f, 0.05f, 0.12f);

    // Elevated Isometric Tracking Camera (Looking down at ~42 degrees)
    Vec3 eye = { gGame.playerX, 310.0f, gGame.playerZ + 270.0f };
    Vec3 target = { gGame.playerX, 0.0f, gGame.playerZ - 10.0f };
    Vec3 up = { 0.0f, 1.0f, 0.0f };
    GfxDevice::Instance().SetTransformView(Mat4::LookAt(eye, target, up));

    // Directional Sun Light
    GfxDevice::Instance().SetLightDirection({ 0.35f, -0.85f, 0.45f });
    GfxDevice::Instance().SetLightDiffuse({ 1.0f, 0.98f, 0.92f, 1.0f });
    GfxDevice::Instance().SetAmbientLight({ 0.45f, 0.45f, 0.55f, 1.0f });

    // 0. Draw Deep Purple Space Grid Floor underneath the floating void
    GfxDevice::Instance().SetTexture(gGame.texBgGrid);
    Mat4 bgMat = Mat4::Identity();
    GfxDevice::Instance().SetTransformWorld(bgMat);
    GfxDevice::Instance().SetMaterialDiffuse({ 0.6f, 0.5f, 0.8f, 1.0f });
    GfxDevice::Instance().DrawMesh(gGame.bgGridMeshId);

    // 1. Draw Map Tiles with Authentic Sliced Textures
    for (int y = 0; y < gGame.mapHeight; ++y) {
        for (int x = 0; x < (int)gGame.mapLines[y].size(); ++x) {
            char c = gGame.mapLines[y][x];
            if (c == '.') continue; // Pit / Void

            float wx = GridToWorldX(x, gGame.halfWidth);
            float wz = GridToWorldZ(y, gGame.halfHeight);

            if (c == '1' || c == '2' || c == '3') {
                // 3D Wall Box
                Mat4 world = Mat4::Translation(wx, 0.0f, wz);
                GfxDevice::Instance().SetTransformWorld(world);
                GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });

                // Top: Grey Stone Slab (tile_wall_top.png)
                GfxDevice::Instance().SetTexture(gGame.texWallTop);
                GfxDevice::Instance().DrawMesh(gGame.wallTopMeshId);

                // Sides: Sandstone Bricks (tile_wall_side.png)
                GfxDevice::Instance().SetTexture(gGame.texWallSide);
                GfxDevice::Instance().DrawMesh(gGame.wallSidesMeshId);
            } else {
                Mat4 world = Mat4::Translation(wx, 0.0f, wz);
                GfxDevice::Instance().SetTransformWorld(world);

                if (c == '*') {
                    // Green Star Warp Zone (tile_warp.png)
                    if (gGame.portalActive) {
                        float pulse = 0.8f + 0.2f * sinf(gGame.frameCount * 0.15f);
                        GfxDevice::Instance().SetMaterialDiffuse({ 1.0f * pulse, 1.0f * pulse, 0.4f, 1.0f });
                    } else {
                        GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    }
                    GfxDevice::Instance().SetTexture(gGame.texWarp);
                } else if (c == '=') {
                    // Red Wooden Bridge (tile_bridge_h.png)
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texBridgeH);
                } else if (c == '+') {
                    // Red Wooden Bridge Vertical (tile_bridge_v.png)
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texBridgeV);
                } else if (c == '!') {
                    // Red Volcano Pit Hole (tile_hole.png)
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texHole);
                } else if (c == '[') {
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texConvUp);
                } else if (c == '>') {
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texConvRight);
                } else if (c == ']') {
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texConvDown);
                } else if (c == '<') {
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texConvLeft);
                } else {
                    // Normal Cobblestone Floor Tile (tile_floor.png)
                    GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
                    GfxDevice::Instance().SetTexture(gGame.texFloor);
                }
                GfxDevice::Instance().DrawMesh(gGame.quadMeshId);
            }
        }
    }

    // 2. Draw Crystals
    float crystalSpin = gGame.frameCount * 0.045f;
    float crystalBob = sinf(gGame.frameCount * 0.08f) * 4.0f;
    GfxDevice::Instance().SetTexture(0); // Pure Gouraud vertex colors from model materials!

    int stackIndex = 0;
    for (auto& c : gGame.crystals) {
        float cx, cy, cz;
        if (c.deposited) {
            // Deposited on the Green Star Warp Zone!
            cx = gGame.exitWorldX;
            cy = 8.0f;
            cz = gGame.exitWorldZ;
        } else if (c.carried) {
            // Stacked vertically on Hopmon's head (Iconic Hopmon feature!)
            cx = gGame.playerX;
            cy = gGame.playerY + 36.0f + (float)stackIndex * 20.0f;
            cz = gGame.playerZ;
            stackIndex++;
        } else {
            // Resting on the map
            cx = c.worldX;
            cy = 16.0f + crystalBob;
            cz = c.worldZ;
        }

        Mat4 world = Mat4::Multiply(
            Mat4::Multiply(Mat4::Scaling(28.0f, 28.0f, 28.0f), Mat4::RotationY(crystalSpin)),
            Mat4::Translation(cx, cy, cz)
        );
        GfxDevice::Instance().SetTransformWorld(world);
        GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
        GfxDevice::Instance().DrawMesh(gGame.meshCrystal.meshBufferId);
    }

    // 3. Draw Enemies (Gouraud Shaded with authentic model colors)
    for (const auto& en : gGame.enemies) {
        if (!en.active) continue;
        float enBob = (en.type == 2) ? sinf(gGame.frameCount * 0.1f) * 3.0f : 0.0f;
        Mat4 world = Mat4::Multiply(
            Mat4::Multiply(Mat4::Scaling(30.0f, 30.0f, 30.0f), Mat4::RotationY(en.dir * 1.57079f)),
            Mat4::Translation(en.x, 8.0f + enBob, en.z)
        );
        GfxDevice::Instance().SetTransformWorld(world);
        GfxDevice::Instance().SetTexture(0);
        GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });

        if (en.type == 0) GfxDevice::Instance().DrawMesh(gGame.meshEnemyA.meshBufferId);
        else if (en.type == 1) GfxDevice::Instance().DrawMesh(gGame.meshEnemyB.meshBufferId);
        else GfxDevice::Instance().DrawMesh(gGame.meshEnemyD.meshBufferId);

        // Enemy Shadow
        GfxDevice::Instance().SetTexture(gGame.texShadow);
        GfxDevice::Instance().SetAlphaTest(true, 0.1f);
        Mat4 shadowMat = Mat4::Multiply(Mat4::Scaling(0.85f, 1.0f, 0.85f), Mat4::Translation(en.x, 1.0f, en.z));
        GfxDevice::Instance().SetTransformWorld(shadowMat);
        GfxDevice::Instance().SetMaterialDiffuse({ 0.0f, 0.0f, 0.0f, 0.5f });
        GfxDevice::Instance().DrawMesh(gGame.shadowMeshId);
        GfxDevice::Instance().SetAlphaTest(false);
    }

    // 4. Draw Projectiles (Glowing energy orb)
    GfxDevice::Instance().SetTexture(0);
    for (const auto& p : gGame.projectiles) {
        if (!p.active) continue;
        Mat4 world = Mat4::Translation(p.x, 14.0f, p.z);
        GfxDevice::Instance().SetTransformWorld(world);
        GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 0.9f, 0.3f, 1.0f });
        GfxDevice::Instance().DrawMesh(gGame.projMeshId);
    }

    // 5. Draw Player Hopmon & Planar Shadow
    GfxDevice::Instance().SetTexture(gGame.texShadow);
    GfxDevice::Instance().SetAlphaTest(true, 0.1f);
    float shadowScale = std::max(0.4f, 1.0f - (gGame.playerY / 30.0f));
    Mat4 pShadow = Mat4::Multiply(Mat4::Scaling(shadowScale, 1.0f, shadowScale), Mat4::Translation(gGame.playerX, 1.0f, gGame.playerZ));
    GfxDevice::Instance().SetTransformWorld(pShadow);
    GfxDevice::Instance().SetMaterialDiffuse({ 0.0f, 0.0f, 0.0f, 0.6f });
    GfxDevice::Instance().DrawMesh(gGame.shadowMeshId);
    GfxDevice::Instance().SetAlphaTest(false);

    // Hopmon Model (Gouraud shaded: black cat eyes, white sclera, orange ears, blue feet, yellow body)
    if (gGame.meshPac[gGame.animFrame].meshBufferId > 0) {
        float sy = 35.0f;
        float sxz = 35.0f;
        if (gGame.moving) {
            float squash = sinf(3.14159f * gGame.stepProgress);
            sy = 35.0f * (1.0f + squash * 0.18f);
            sxz = 35.0f * (1.0f - squash * 0.09f);
        }

        Mat4 pScale = Mat4::Scaling(sxz, sy, sxz);
        Mat4 pRot = Mat4::RotationY(gGame.playerRotY);
        Mat4 pTrans = Mat4::Translation(gGame.playerX, gGame.playerY + 8.0f, gGame.playerZ);
        Mat4 world = Mat4::Multiply(Mat4::Multiply(pScale, pRot), pTrans);
        GfxDevice::Instance().SetTransformWorld(world);
        GfxDevice::Instance().SetTexture(0);

        if (gGame.invulnTimer > 0 && (gGame.frameCount / 4) % 2 == 0) {
            GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 0.3f, 0.3f, 0.5f });
        } else {
            GfxDevice::Instance().SetMaterialDiffuse({ 1.0f, 1.0f, 1.0f, 1.0f });
        }
        GfxDevice::Instance().DrawMesh(gGame.meshPac[gGame.animFrame].meshBufferId);
    }

    // 6. Draw Particles
    for (const auto& pt : gGame.particles) {
        if (!pt.active) continue;
        Mat4 world = Mat4::Multiply(Mat4::Scaling(pt.life * 0.6f, pt.life * 0.6f, pt.life * 0.6f), Mat4::Translation(pt.x, pt.y, pt.z));
        GfxDevice::Instance().SetTransformWorld(world);
        GfxDevice::Instance().SetMaterialDiffuse(pt.color);
        GfxDevice::Instance().DrawMesh(gGame.projMeshId);
    }

    // -------------------------------------------------------------
    // 2D HUD (Authentic Hopmon Layout from Screenshots)
    // -------------------------------------------------------------
    GfxDevice::Instance().Begin2D();

    // Top Header Banner (Transparent overlay)
    GfxDevice::Instance().DrawRect2D(0.0f, 0.0f, 640.0f, 32.0f, {0.02f, 0.03f, 0.07f, 0.85f});

    // Level indicator (Gold box with text area)
    GfxDevice::Instance().DrawRect2D(14.0f, 8.0f, 90.0f, 18.0f, {0.95f, 0.8f, 0.2f, 0.9f});
    GfxDevice::Instance().DrawRect2D(16.0f, 10.0f, 86.0f, 14.0f, {0.1f, 0.12f, 0.2f, 0.9f});

    // Crystals Indicator Box (Shows remaining crystals to deposit!)
    int remaining = gGame.totalCrystals - gGame.depositedCount;
    GfxDevice::Instance().DrawRect2D(230.0f, 8.0f, 180.0f, 18.0f, {0.95f, 0.8f, 0.2f, 0.9f});
    GfxDevice::Instance().DrawRect2D(232.0f, 10.0f, 176.0f, 14.0f, {0.1f, 0.12f, 0.2f, 0.9f});

    // Bottom-right: FIRE READY 10 Segmented Energy Cells
    int filledCells = (int)(gGame.fireEnergy / 10.0f);
    for (int i = 0; i < 10; ++i) {
        float cx = 500.0f + (float)i * 12.0f;
        if (i < filledCells) {
            GfxDevice::Instance().DrawRect2D(cx, 452.0f, 9.0f, 14.0f, {0.3f, 0.85f, 1.0f, 1.0f});
        } else {
            GfxDevice::Instance().DrawRect2D(cx, 452.0f, 9.0f, 14.0f, {0.15f, 0.25f, 0.4f, 0.8f});
        }
    }

    // Victory Banner
    if (gGame.levelCleared) {
        GfxDevice::Instance().DrawRect2D(120.0f, 190.0f, 400.0f, 90.0f, {0.0f, 0.0f, 0.0f, 0.85f});
        GfxDevice::Instance().DrawRect2D(120.0f, 190.0f, 400.0f, 4.0f, {1.0f, 0.85f, 0.2f, 1.0f});
        GfxDevice::Instance().DrawRect2D(120.0f, 276.0f, 400.0f, 4.0f, {1.0f, 0.85f, 0.2f, 1.0f});
    }

    GfxDevice::Instance().End2D();

    GfxDevice::Instance().EndScene();
    SDL_GL_SwapWindow(gGame.window);
}

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    gGame.window = SDL_CreateWindow(
        "Hopmon 3D (JJ Soft 2002) - WebAssembly Port",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    SDL_GLContext glContext = SDL_GL_CreateContext(gGame.window);
    GfxDevice::Instance().Init(640, 480);
    AudioDevice::Instance().Init();
    InputDevice::Instance().Init();

    CreateMeshes(gGame);

    // Load authentic sliced textures
    gGame.texFloor = GfxDevice::Instance().LoadTexture("assets/textures/tile_floor.png");
    gGame.texWallTop = GfxDevice::Instance().LoadTexture("assets/textures/tile_wall_top.png");
    gGame.texWallSide = GfxDevice::Instance().LoadTexture("assets/textures/tile_wall_side.png");
    gGame.texBridgeH = GfxDevice::Instance().LoadTexture("assets/textures/tile_bridge_h.png");
    gGame.texBridgeV = GfxDevice::Instance().LoadTexture("assets/textures/tile_bridge_v.png");
    gGame.texWarp = GfxDevice::Instance().LoadTexture("assets/textures/tile_warp.png");
    gGame.texHole = GfxDevice::Instance().LoadTexture("assets/textures/tile_hole.png");
    gGame.texConvUp = GfxDevice::Instance().LoadTexture("assets/textures/tile_conv_up.png");
    gGame.texConvRight = GfxDevice::Instance().LoadTexture("assets/textures/tile_conv_right.png");
    gGame.texConvDown = GfxDevice::Instance().LoadTexture("assets/textures/tile_conv_down.png");
    gGame.texConvLeft = GfxDevice::Instance().LoadTexture("assets/textures/tile_conv_left.png");
    gGame.texShadow = GfxDevice::Instance().LoadTexture("assets/textures/tex_160.png");
    gGame.texBgGrid = GfxDevice::Instance().LoadTexture("assets/textures/bg_grid.png");

    // Load 3D Models with Gouraud materials
    XFileParser::Load("assets/models/01_Pac_1.x", gGame.meshPac[0]);
    XFileParser::Load("assets/models/02_Pac_2.x", gGame.meshPac[1]);
    XFileParser::Load("assets/models/03_Pac_3.x", gGame.meshPac[2]);
    XFileParser::Load("assets/models/20_Pac_4.x", gGame.meshPac[3]);
    XFileParser::Load("assets/models/10_Original_Crystal.x", gGame.meshCrystal);
    XFileParser::Load("assets/models/04_Original_EnemyA.x", gGame.meshEnemyA);
    XFileParser::Load("assets/models/05_Original_EnemyB.x", gGame.meshEnemyB);
    XFileParser::Load("assets/models/12_Original_EnemyD.x", gGame.meshEnemyD);

    // Load Stage 1
    LoadStage(gGame, 1);

#if defined(__EMSCRIPTEN__)
    emscripten_set_main_loop(MainLoopIteration, 0, 1);
#else
    while (gGame.running) {
        MainLoopIteration();
        SDL_Delay(16);
    }
    SDL_DestroyWindow(gGame.window);
    SDL_Quit();
#endif
    return 0;
}
