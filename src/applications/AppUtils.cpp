#include "AppUtils.h"
#include "AppContext.h"

using namespace Applications;

void AppUtils::runApplication(std::shared_ptr<AppBase> app)
{
    auto context = AppContext::newAppContext();
    app->app_main(context);
}
