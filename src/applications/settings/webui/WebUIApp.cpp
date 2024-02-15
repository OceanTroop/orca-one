#include "WebUIApp.h"
#include "WebUIScreen.h"

using namespace Applications::Settings::WebUI;

void WebUIApp::app_main(std::shared_ptr<AppContext> appContext)
{
    appContext->getScreeManager()->setCurrentScreen<WebUIScreen>();
}