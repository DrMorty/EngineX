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
        {
            if (component->typeName == typeid(Renderer2D).name())
            {
                unregisterRendererForThisObject(component.get());
                continue;
            }

            unregisterScriptForThisObject(component.get());
        }

        m_components.clear();
    };

    void GameObject::registerScriptForThisObject(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->registerScript(static_cast<Script*>(script));
    }

    void GameObject::registerRendererForThisObject(GameObjectComponent* renderer)
    {
        Engine::instance()->renderManager->registerRenderer(static_cast<Renderer2D*>(renderer));
    }

    void GameObject::unregisterRendererForThisObject(GameObjectComponent* renderer)
    {
        Engine::instance()->renderManager->unregisterRenderer(static_cast<Renderer2D*>(renderer));
    }

    void GameObject::unregisterScriptForThisObject(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->unregisterScript(static_cast<Script*>(script));
    }
}