#include "DisplayInterface.h"

using namespace Infrastructure::M5StickCPlus1_1;

void DisplayInterface::begin()
{
    Domain::Entities::DisplayInterfaceBase::begin();

    _tft->setRotation(3);
}

DisplaySettings DisplayInterface::getSettings()
{
    DisplaySettings settings;
    
    settings.width = 135;
    settings.height = 240;
    settings.menuItemsToShow = 4;
    
    return settings;
}
