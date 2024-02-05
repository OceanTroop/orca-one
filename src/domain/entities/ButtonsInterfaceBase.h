#pragma once

#include "IInterface.h"
#include "InterfaceType.h"
#include "EventHandler.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class ButtonsInterfaceBase : public IInterface
        {
        public:
            InterfaceType getType();

            virtual bool hasNext() = 0;
            virtual bool hasPrevious() = 0;
            virtual bool hasSelect() = 0;
            virtual bool hasBack() = 0;

            void registerOnClickNext(std::function<void()> handler);
            void registerOnClickPrevious(std::function<void()> handler);
            void registerOnClickSelect(std::function<void()> handler);
            void registerOnClickBack(std::function<void()> handler);

        protected:
            EventHandler _onClickNext = EventHandler();
            EventHandler _onClickPrevious = EventHandler();
            EventHandler _onClickSelect = EventHandler();
            EventHandler _onClickBack = EventHandler();
        };
    }
#ifdef __cplusplus
}
#endif
