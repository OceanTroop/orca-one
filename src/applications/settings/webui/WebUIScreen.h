#pragma once

#include "../../services/gui/Screen.h"
#include "../../../utility/FileUtility.h"
#include "../../../utility/DirectoryWebServer.h"

using namespace Applications::Services::GUI;
using namespace Utility;

#define BASE_PATH "/applications/settings/webui/"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Settings::WebUI
    {
        class WebUIScreen : public Screen
        {
        private:
            String _ssid;
            String _ssidPassword;
            DirectoryWebServer *_webServer;
            void handleSettingsGet();
            void handleSettingsPost();
            void startServer();
            void stopServer();

        public:
            WebUIScreen(std::shared_ptr<TFT_eSPI> tft);

            ~WebUIScreen()
            {
                this->stopServer();
            }

            void render(std::shared_ptr<TFT_eSPI> tft);
            void buttonSelectPressed();
        };
    }

#ifdef __cplusplus
}
#endif