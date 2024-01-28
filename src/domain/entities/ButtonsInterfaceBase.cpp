#include "ButtonsInterfaceBase.h"

using namespace Domain::Entities;

InterfaceType ButtonsInterfaceBase::getType()
{
    return InterfaceType::Buttons;
}

void ButtonsInterfaceBase::registerOnClickPrevious(std::function<void()> handler)
{
    this->_onClickPrevious.addHandler(handler);
}

void ButtonsInterfaceBase::registerOnClickSelect(std::function<void()> handler)
{
    this->_onClickSelect.addHandler(handler);
}

void ButtonsInterfaceBase::registerOnClickBack(std::function<void()> handler)
{
    this->_onClickBack.addHandler(handler);
}

void ButtonsInterfaceBase::registerOnClickNext(std::function<void()> handler)
{
    this->_onClickNext.addHandler(handler);
}
