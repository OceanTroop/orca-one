#include "AboutApp.h"
#include "AboutScreen.h"

using namespace Applications::Settings::About;

void AboutApp::app_main(std::shared_ptr<AppContext> appContext)
{
    appContext->getScreeManager()->setCurrentScreen<AboutScreen>();
}