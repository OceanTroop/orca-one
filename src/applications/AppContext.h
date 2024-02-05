#pragma once

#include "../domain/entities/DeviceBase.h"
#include "services/gui/ScreenManager.h"

using namespace Domain::Entities;
using namespace Applications::Services::GUI;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        class AppContext
        {
        private:
            DeviceBase *_device;
            ScreenManager *_screenManager;

        public:
            static std::shared_ptr<AppContext> newAppContext();
            
            void setDevice(DeviceBase *device);
            DeviceBase *getDevice();

            void setScreeManager(ScreenManager *screenManager);
            ScreenManager *getScreeManager();
        };
    }
#ifdef __cplusplus
}
#endif