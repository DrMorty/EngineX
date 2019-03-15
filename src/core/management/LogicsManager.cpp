#include "LogicsManager.h"

#include "../object_components/Script.h"
#include "../Engine.h"

namespace engine
{   
    void LogicsManager::updateObjectScripts()
    {  
        for (auto  script : scripts)
        {
            static_cast<Script*>(script)->update();
        }; 
    }

    void LogicsManager::registerScript(GameObjectComponent* script)
    {
        scripts.push_back(script);
    }
}