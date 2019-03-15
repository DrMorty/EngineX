#include <iostream>
#include <string>

#include "GameObject.h"
#include "../Engine.h"

GameObject::GameObject()
{  
};

GameObject::GameObject(std::string t_name) : name(t_name) 
{
    for (auto component : m_components)
        delete component;
};

GameObject::~GameObject() 
{
};

void GameObject::registerScriptForThisObject(GameObjectComponent* script)
{
    Engine::instance()->logicsManager->registerScript(static_cast<Script*>(script));
}