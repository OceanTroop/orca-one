#pragma once

#include "DeviceBase.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class AppContext
        {
        private:
            std::shared_ptr<DeviceBase> _device;

        public:
            void setDevice(std::shared_ptr<DeviceBase> device);
            std::shared_ptr<DeviceBase> getDevice();
        };
    }
#ifdef __cplusplus
}
#endif