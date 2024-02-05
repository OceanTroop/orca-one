#ifdef M5CARDPUTER

#include "DisplayInterface.h"

using namespace Infrastructure::M5Cardputer;

void DisplayInterface::begin()
{
    Domain::Entities::DisplayInterfaceBase::begin();

    _tft->setRotation(1);
}

DisplaySettings DisplayInterface::getSettings()
{
    DisplaySettings settings;
    
    settings.width = 240;
    settings.height = 135;
    settings.menuItemsToShow = 4;
    
    return settings;
}

#endif