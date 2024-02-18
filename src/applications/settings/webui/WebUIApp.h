#pragma once

#include "../../AppBase.h"

using namespace Applications;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Settings::WebUI
    {
        class WebUIApp : public AppBase
        {
        public:
            void app_main(std::shared_ptr<AppContext> appContext);
        };
    }

#ifdef __cplusplus
}
#endif