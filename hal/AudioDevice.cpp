#include "AudioDevice.h"
#include <iostream>

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>

EM_JS(void, JS_InitAudio, (), {
    if (!window.hopmonAudio) {
        window.hopmonAudio = {
            ctx: null,
            sfxBuffers: {},
            bgmAudio: null,
            initCtx: function() {
                if (!this.ctx) {
                    var AudioCtx = window.AudioContext || window.webkitAudioContext;
                    if (AudioCtx) this.ctx = new AudioCtx();
                }
                if (this.ctx && this.ctx.state === 'suspended') {
                    this.ctx.resume();
                }
            },
            playSFX: function(id, pan, vol) {
                this.initCtx();
                if (!this.ctx) return;
                var sfxNum = (id < 10 ? '0' + id : id);
                var url = 'assets/audio/sfx_' + sfxNum + '.wav';
                if (!this.sfxBuffers[id]) {
                    var self = this;
                    fetch(url).then(function(r) { return r.arrayBuffer(); })
                              .then(function(b) { return self.ctx.decodeAudioData(b); })
                              .then(function(buf) {
                                  self.sfxBuffers[id] = buf;
                                  self.triggerSFX(buf, pan, vol);
                              }).catch(function(e) { /* ignore */ });
                } else {
                    this.triggerSFX(this.sfxBuffers[id], pan, vol);
                }
            },
            triggerSFX: function(buf, pan, vol) {
                var src = this.ctx.createBufferSource();
                src.buffer = buf;
                var gain = this.ctx.createGain();
                gain.gain.value = vol;
                if (this.ctx.createStereoPanner) {
                    var panner = this.ctx.createStereoPanner();
                    panner.pan.value = Math.max(-1.0, Math.min(1.0, pan));
                    src.connect(panner);
                    panner.connect(gain);
                } else {
                    src.connect(gain);
                }
                gain.connect(this.ctx.destination);
                src.start(0);
            },
            playBGM: function(trackId) {
                if (this.bgmAudio) {
                    this.bgmAudio.pause();
                }
                var filename = 'Music0' + trackId + '.mid';
                console.log('Playing BGM track:', filename);
                if (window.playMidiTrack) {
                    window.playMidiTrack(trackId);
                }
            },
            stopBGM: function() {
                if (window.stopMidiTrack) {
                    window.stopMidiTrack();
                }
            }
        };
        // Auto resume audio on first user gesture
        var resumeFn = function() {
            if (window.hopmonAudio && window.hopmonAudio.ctx && window.hopmonAudio.ctx.state === 'suspended') {
                window.hopmonAudio.ctx.resume();
            }
        };
        window.addEventListener('click', resumeFn, { once: true });
        window.addEventListener('keydown', resumeFn, { once: true });
    }
});

EM_JS(void, JS_PlaySFX, (int sfxId, float pan, float vol), {
    if (window.hopmonAudio) {
        window.hopmonAudio.playSFX(sfxId, pan, vol);
    }
});

EM_JS(void, JS_PlayBGM, (int trackId), {
    if (window.hopmonAudio) {
        window.hopmonAudio.playBGM(trackId);
    }
});

EM_JS(void, JS_StopBGM, (), {
    if (window.hopmonAudio) {
        window.hopmonAudio.stopBGM();
    }
});
#endif

AudioDevice& AudioDevice::Instance() {
    static AudioDevice dev;
    return dev;
}

AudioDevice::AudioDevice() {}
AudioDevice::~AudioDevice() {}

bool AudioDevice::Init() {
#if defined(__EMSCRIPTEN__)
    JS_InitAudio();
#endif
    return true;
}

void AudioDevice::PlaySFX(int sfxId, float pan, float volume) {
    if (sfxId < 0 || sfxId >= 18) return;
#if defined(__EMSCRIPTEN__)
    JS_PlaySFX(sfxId, pan, volume * sfxVolume_);
#endif
}

void AudioDevice::PlayBGM(int trackId) {
    if (currentBgmTrack_ == trackId) return;
    currentBgmTrack_ = trackId;
#if defined(__EMSCRIPTEN__)
    JS_PlayBGM(trackId);
#endif
}

void AudioDevice::StopBGM() {
    currentBgmTrack_ = -1;
#if defined(__EMSCRIPTEN__)
    JS_StopBGM();
#endif
}

void AudioDevice::SetSFXVolume(float volume) {
    sfxVolume_ = volume;
}

void AudioDevice::SetBGMVolume(float volume) {
    bgmVolume_ = volume;
}
