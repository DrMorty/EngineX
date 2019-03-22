#include "LogicsManager.h"

#include "../object_components/Script.h"
#include "../Engine.h"

namespace engine
{   
    void LogicsManager::callUpdateForScripts()
    {  
        for (auto  script : scripts)
            script->update();
    }

    void LogicsManager::callStartForScripts()
    {  
        for (auto  script : notStartedScripts)
            script->start();

        notStartedScripts.clear();
    }

    void LogicsManager::updateLogics()
    {
        Time::updateTime();
        
        eventManager.pollEvents();

        callStartForScripts();
        callUpdateForScripts();
        
        eventManager.clearEvents();
    }

    void LogicsManager::registerScript(Script* script)
    {
        notStartedScripts.push_back(script);
        scripts.push_back(script);
    }

    void LogicsManager::unregisterScript(Script* script)
    {
        scripts.erase(remove(scripts.begin(), scripts.end(), script), scripts.end());
    }
}