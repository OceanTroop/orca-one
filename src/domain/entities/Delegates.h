#pragma once

#include "AppContext.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities::Delegates
    {
        using OnExecute = void (*)(std::shared_ptr<AppContext> appContext);
    }

#ifdef __cplusplus
}
#endif
