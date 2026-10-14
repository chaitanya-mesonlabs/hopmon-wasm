#include "InputDevice.h"

InputDevice& InputDevice::Instance() {
    static InputDevice dev;
    return dev;
}

InputDevice::InputDevice() {}
InputDevice::~InputDevice() {}

void InputDevice::Init() {
    currentKeys_ = 0;
    previousKeys_ = 0;
}

void InputDevice::Update() {
    previousKeys_ = currentKeys_;
}

bool InputDevice::IsPressed(KeyAction action) const {
    return (currentKeys_ & action) != 0;
}

bool InputDevice::IsJustPressed(KeyAction action) const {
    return ((currentKeys_ & action) != 0) && ((previousKeys_ & action) == 0);
}

void InputDevice::SetKeyState(KeyAction action, bool pressed) {
    if (pressed) {
        currentKeys_ |= action;
    } else {
        currentKeys_ &= ~action;
    }
}

void InputDevice::SetVirtualDPad(float dx, float dy, bool firePressed) {
    if (dy < -0.3f) currentKeys_ |= KEY_UP;
    else currentKeys_ &= ~KEY_UP;

    if (dy > 0.3f) currentKeys_ |= KEY_DOWN;
    else currentKeys_ &= ~KEY_DOWN;

    if (dx < -0.3f) currentKeys_ |= KEY_LEFT;
    else currentKeys_ &= ~KEY_LEFT;

    if (dx > 0.3f) currentKeys_ |= KEY_RIGHT;
    else currentKeys_ &= ~KEY_RIGHT;

    if (firePressed) currentKeys_ |= KEY_FIRE;
    else currentKeys_ &= ~KEY_FIRE;
}
