#include "TVBGoneApp.h"
#include "TVBGoneMenuScreen.h"

using namespace Applications::Infrared::TVBGone;

void TVBGoneApp::app_main(std::shared_ptr<AppContext> appContext)
{
    appContext->getScreeManager()->setCurrentScreen<TVBGoneMenuScreen>();
}