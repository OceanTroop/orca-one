#pragma once

#include <memory>

#include "AppContext.h"

using namespace Applications;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        class AppBase
        {
        public:
            virtual void app_main(std::shared_ptr<AppContext> appContext) = 0;
        };
    }

#ifdef __cplusplus
}
#endif