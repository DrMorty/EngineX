#include <iostream>
#include <string>

#include "GameObject.h"
#include "../Engine.h"

namespace engine
{   
    GameObject::GameObject()
    {  
    };

    GameObject::GameObject(std::string t_name) : name(t_name) 
    {
    };

    GameObject::~GameObject() 
    {
        for (auto component : m_components)
            delete component;
    };

    void GameObject::registerScriptForThisObject(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->registerScript(static_cast<Script*>(script));
    }
}