#pragma once

#if defined(M5CARDPUTER)

#include "infrastructure/M5Cardputer/Device.h"
using namespace Infrastructure::M5Cardputer;

#elif defined(M5STICKCPLUS)

#include "infrastructure/M5StickCPlus/Device.h"
using namespace Infrastructure::M5StickCPlus;

#endif

Device device = Device();
