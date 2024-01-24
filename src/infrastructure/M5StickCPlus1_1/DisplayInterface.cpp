#include "DisplayInterface.h"

using namespace Infrastructure::M5StickCPlus1_1;

void DisplayInterface::begin()
{
    Domain::Entities::DisplayInterfaceBase::begin();

    _tft->setRotation(3);
}