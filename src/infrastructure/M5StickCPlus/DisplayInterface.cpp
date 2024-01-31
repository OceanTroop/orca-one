#ifdef M5STICKCPLUS

#include "DisplayInterface.h"

using namespace Infrastructure::M5StickCPlus;

void DisplayInterface::begin()
{
    Domain::Entities::DisplayInterfaceBase::begin();

    _tft->setRotation(3);
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
