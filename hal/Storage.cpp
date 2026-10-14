#include "Storage.h"
#include <iostream>

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>

EM_JS(int, JS_LoadInt, (const char* key, int defVal), {
    var k = UTF8ToString(key);
    var v = localStorage.getItem(k);
    return v !== null ? parseInt(v, 10) : defVal;
});

EM_JS(void, JS_SaveInt, (const char* key, int val), {
    var k = UTF8ToString(key);
    localStorage.setItem(k, val.toString());
});
#endif

bool Storage::Load(GameSaveData& outData) {
#if defined(__EMSCRIPTEN__)
    outData.maxLevel = JS_LoadInt("hopmon_max_level", 1);
    outData.highScore = (uint32_t)JS_LoadInt("hopmon_high_score", 0);
    outData.soundVolume = JS_LoadInt("hopmon_sfx_vol", 100);
    outData.musicVolume = JS_LoadInt("hopmon_bgm_vol", 80);
    return true;
#else
    return false;
#endif
}

bool Storage::Save(const GameSaveData& inData) {
#if defined(__EMSCRIPTEN__)
    JS_SaveInt("hopmon_max_level", inData.maxLevel);
    JS_SaveInt("hopmon_high_score", (int)inData.highScore);
    JS_SaveInt("hopmon_sfx_vol", inData.soundVolume);
    JS_SaveInt("hopmon_bgm_vol", inData.musicVolume);
    return true;
#else
    return false;
#endif
}
