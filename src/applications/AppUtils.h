#pragma once

#include <memory>

#include "AppBase.h"

using namespace Applications;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        class AppUtils
        {
        public:
            static void runApplication(std::shared_ptr<AppBase> app);
        };
    }

#ifdef __cplusplus
}
#endif