#pragma once

#include "../launcher/Launcher.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        class TaskManager
        {
        private:
            static TaskManager *_instance;
            static bool _initialized;
            Launcher *_launcher;

        public:
            TaskManager();

            static TaskManager *getInstance();

            void begin();
            void loop();
        };
    }

#ifdef __cplusplus
}
#endif