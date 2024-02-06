#pragma once

#include <WString.h>
#include <map>

#include "Language.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class Settings
        {
        public:
            Language language;
            std::map<String, String> custom;
        };
    }
#ifdef __cplusplus
}
#endif