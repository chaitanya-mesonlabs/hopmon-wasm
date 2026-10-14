#ifndef HOPMON_AUDIO_DEVICE_H
#define HOPMON_AUDIO_DEVICE_H

#include <cstdint>
#include <string>

class AudioDevice {
public:
    static AudioDevice& Instance();

    bool Init();
    void PlaySFX(int sfxId, float pan = 0.0f, float volume = 1.0f);
    void PlayBGM(int trackId); // 1 = Music01, 2 = Music02, etc.
    void StopBGM();
    void SetSFXVolume(float volume);
    void SetBGMVolume(float volume);

private:
    AudioDevice();
    ~AudioDevice();

    float sfxVolume_ = 1.0f;
    float bgmVolume_ = 0.8f;
    int currentBgmTrack_ = -1;
};

#endif // HOPMON_AUDIO_DEVICE_H
