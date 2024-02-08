#ifdef M5CARDPUTER

#include "ButtonsInterface.h"

using namespace Infrastructure::M5Cardputer;

ButtonsInterface::ButtonsInterface() : ButtonsInterfaceBase()
{
}

void ButtonsInterface::begin()
{
}

void ButtonsInterface::loop()
{
    if (this->_keyboard == nullptr)
        this->_keyboard = DeviceBase::getInstance()->getInterfaces().keyboardInterface;

    if (this->_keyboard->isKeyPressed(';'))
        this->_onClickPrevious.fireEvent();

    if (this->_keyboard->isKeyPressed('.'))
        this->_onClickNext.fireEvent();

    if (this->_keyboard->isKeyPressed('`'))
        this->_onClickBack.fireEvent();

    this->_buttonSelect.read();
    if (this->_buttonSelect.isPressed())
        this->_onClickSelect.fireEvent();
}

#endif