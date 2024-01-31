#include "KeyboardInterface.h"

using namespace Infrastructure::M5Cardputer;

void KeyboardInterface::begin()
{
    this->Keyboard.begin();
}

void KeyboardInterface::loop()
{
    this->Keyboard.updateKeyList();
    this->Keyboard.updateKeysState();
}

uint8_t KeyboardInterface::isPressed()
{
    return this->Keyboard.isPressed();
}

bool KeyboardInterface::isChange()
{
    return this->Keyboard.isChange();
}

bool KeyboardInterface::isKeyPressed(char c)
{
    return this->Keyboard.isKeyPressed(c);
}

bool KeyboardInterface::capslocked()
{
    return this->Keyboard.capslocked();
}
