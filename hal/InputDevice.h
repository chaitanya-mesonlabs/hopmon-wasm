#ifndef HOPMON_INPUT_DEVICE_H
#define HOPMON_INPUT_DEVICE_H

#include <cstdint>

enum KeyAction {
    KEY_UP       = 1 << 0,
    KEY_DOWN     = 1 << 1,
    KEY_LEFT     = 1 << 2,
    KEY_RIGHT    = 1 << 3,
    KEY_FIRE     = 1 << 4,
    KEY_CONFIRM  = 1 << 5,
    KEY_CANCEL   = 1 << 6,
    KEY_PAUSE    = 1 << 7
};

class InputDevice {
public:
    static InputDevice& Instance();

    void Init();
    void Update();

    bool IsPressed(KeyAction action) const;
    bool IsJustPressed(KeyAction action) const;

    // Called by SDL2 event handler
    void SetKeyState(KeyAction action, bool pressed);
    void SetVirtualDPad(float dx, float dy, bool firePressed);

private:
    InputDevice();
    ~InputDevice();

    uint32_t currentKeys_ = 0;
    uint32_t previousKeys_ = 0;
};

#endif // HOPMON_INPUT_DEVICE_H
