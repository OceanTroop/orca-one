#pragma once

#include <WString.h>
#include <map>

#include "Translate.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        class TranslateEnglish : public Translate
        {
        public:
            TranslateEnglish();

            Language getLanguage()
            {
                return Language::English;
            }
        };
    }
#ifdef __cplusplus
}
#endif