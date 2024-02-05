#pragma once

#include <WString.h>
#include <map>

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        enum TranslateLanguage
        {
            English,
            PortuguesBrazil
        };

        class Translate
        {
        protected:
            std::map<String, String> _texts;

        public:
            virtual TranslateLanguage getLanguage() = 0;

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