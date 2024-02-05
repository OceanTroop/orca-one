#pragma once

#include <functional>
#include <vector>

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class EventHandler
        {
        public:
            void addHandler(std::function<void()> handler);
            void fireEvent();

        private:
            std::vector<std::function<void()>> _handlers = std::vector<std::function<void()>>();
        };
    }
#ifdef __cplusplus
}
#endif