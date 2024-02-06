#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#include "AbstractGuiModule.h"
#include "../../AppContext.h"

using namespace Domain::Entities;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class ProgressBar : public AbstractGuiModule
        {
        protected:
            int _borderColor = DEFAULT_PRIMARY_COLOR;
            int _progressColor = DEFAULT_PRIMARY_COLOR;
            int _textColor = DEFAULT_PRIMARY_COLOR;
            int _invertedTextColor = DEFAULT_INVERTED_COLOR;
            int _width = -1;
            int _height = -1;
            int _x = -1;
            int _y = -1;
            int _progress;
            std::function<void()> _onClick = nullptr;

        public:
            void render(std::shared_ptr<TFT_eSPI> tft);

            void setBorderColor(int color);
            void setProgressColor(int color);
            void setTextColor(int color);
            void setInvertedTextColor(int color);
            void setSize(int width, int height);
            void setPosition(int x, int y);
            void setProgress(int progress);
        };
    }

#ifdef __cplusplus
}
#endif