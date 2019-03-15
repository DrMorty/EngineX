#ifndef GAME_OBJECT_COMPONENT_H
#define GAME_OBJECT_COMPONENT_H

#include <string>

namespace engine
{   
    class GameObject;

    class GameObjectComponent
    {
    public:
        std::string typeName = "";
        GameObject* object = 0;
    private:
    };
}

#endif