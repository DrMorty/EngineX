#ifndef LOGICS_MANAGER_H
#define LOGICS_MANAGER_H

#include <vector>

#include "../object_components/GameObjectComponent.h"

namespace engine
{   
    class LogicsManager
    {
    public:
        void updateObjectScripts();
        void registerScript(GameObjectComponent* script);
    private:
        std::vector<GameObjectComponent*> scripts;
    };
}

#endif 