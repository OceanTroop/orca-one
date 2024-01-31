#pragma once

#include <memory>

#include "AppBase.h"

using namespace Applications;

namespace Applications
{
    class AppUtils
    {
    public:
        static void runApplication(std::shared_ptr<AppBase> app);

        template <typename T>
        static void runApplication()
        {
            auto app = std::make_shared<T>();
            AppUtils::runApplication(app);
        }
    };
}
