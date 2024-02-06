#pragma once

#include <WString.h>
#include <map>

#include "../domain/entities/Language.h"
using namespace Domain::Entities;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        class Translate
        {
        protected:
            std::map<String, String> _texts;

        public:
            virtual Language getLanguage() = 0;

            String t(String key)
            {
                return translate(key);
            }

            String translate(String key)
            {
                auto pair = _texts.find(key);

                if (pair != _texts.end())
                {
                    return pair->second;
                }

                return "";
            }
        };
    }
#ifdef __cplusplus
}
#endif