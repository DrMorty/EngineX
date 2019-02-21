#ifndef GAME_OBJECT_COMPONENT_H
#define GAME_OBJECT_COMPONENT_H

#include <string>

class GameObjectComponent
{
 public:
    GameObjectComponent(std::string t_typeName) : typeName(t_typeName)
    {}

    std::string typeName;
 private:
};

#endif