#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class AbstractGuiModule
        {
        protected:
            String _id;

        public:
            virtual void render(std::shared_ptr<TFT_eSPI> tft) = 0;
            virtual void setId(String id);
            virtual const String getId();
        };
    }
#ifdef __cplusplus
}
#endif