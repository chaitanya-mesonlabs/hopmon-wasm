#ifndef HOPMON_STORAGE_H
#define HOPMON_STORAGE_H

#include <cstdint>
#include <string>

struct GameSaveData {
    int maxLevel = 1;
    int soundVolume = 100;
    int musicVolume = 80;
    uint32_t highScore = 0;
};

class Storage {
public:
    static bool Load(GameSaveData& outData);
    static bool Save(const GameSaveData& inData);
};

#endif // HOPMON_STORAGE_H
