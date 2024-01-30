#ifdef M5STICKCPLUS1_1

#include "DisplayInterface.h"
#include "PowerManagementInterface.h"

using namespace Infrastructure::M5StickCPlus1_1;

void PowerManagementInterface::begin()
{
    this->_axp.begin();
}

void PowerManagementInterface::loop()
{
}

#endif