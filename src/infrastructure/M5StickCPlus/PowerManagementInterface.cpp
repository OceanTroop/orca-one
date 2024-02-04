#ifdef M5STICKCPLUS

#include "DisplayInterface.h"
#include "PowerManagementInterface.h"

using namespace Infrastructure::M5StickCPlus;

void PowerManagementInterface::begin()
{

#if defined(M5STICKCPLUS1_1)
    this->_axp.begin();
#elif defined(M5STICKCPLUS2)
    pinMode(POWER_HOLD_PIN, OUTPUT);
    digitalWrite(POWER_HOLD_PIN, HIGH);
#endif
}

void PowerManagementInterface::loop()
{
}

#endif