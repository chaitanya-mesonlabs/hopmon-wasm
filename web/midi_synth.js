// Hopmon Authentic Audio Engine
(function() {
    var bgmAudio = null;

    window.playMidiTrack = function(trackId) {
        if (!bgmAudio) {
            bgmAudio = new Audio();
            bgmAudio.loop = true;
        }
        var num = (trackId < 10 ? '0' + trackId : trackId);
        var src = 'assets/music/Music' + num + '.mp3';
        console.log("Playing original Hopmon BGM:", src);
        bgmAudio.src = src;
        bgmAudio.volume = 0.75;
        bgmAudio.play().catch(function(e) {
            console.log("Audio waiting for first user click to play");
        });
    };

    window.stopMidiTrack = function() {
        if (bgmAudio) bgmAudio.pause();
    };

    // Unlock on click/key
    function unlock() {
        if (bgmAudio && bgmAudio.paused) {
            bgmAudio.play().catch(function() {});
        }
        if (window.hopmonAudio && window.hopmonAudio.ctx && window.hopmonAudio.ctx.state === 'suspended') {
            window.hopmonAudio.ctx.resume();
        }
    }
    document.addEventListener("click", unlock, { once: true });
    document.addEventListener("keydown", unlock, { once: true });
})();
