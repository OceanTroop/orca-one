#pragma once

#include <iostream>
#include <WString.h>

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        enum Language
        {
            English,
            PortuguesBrazil
        };

        std::ostream &operator<<(std::ostream &os, Language language);
        String languageToString(Language language);
    }
#ifdef __cplusplus
}
#endif