#ifndef LOGICS_MANAGER_H
#define LOGICS_MANAGER_H

#include <vector>
#include <list>

#include "../storage/GameObject.h"
#include "EventManager.h"

namespace engine
{   
    class LogicsManager
    {
    public:
        void updateLogics();
        void callStartForScripts();
        void callUpdateForScripts();
        void registerScript(Script* script);

        EventManager eventManager;
    private:
        std::list<Script*> notStartedScripts;
        std::vector<Script*> scripts;
    };
}

#endif 