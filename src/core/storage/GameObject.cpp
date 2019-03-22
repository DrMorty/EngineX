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

            if (component->typeName == typeid(BoxCollider).name())
            {
                unregisterColliderForThisObject(component.get());
                continue;
            }

            if (component->typeName == typeid(RigidBody).name())
            {
                unregisterRigidBodyForThisObject(component.get());
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

    void GameObject::registerColliderForThisObject(GameObjectComponent* collider)
    {
        static_cast<BoxCollider*>(collider)->setColliderBySprite();
        Engine::instance()->physicsManager->registerCollider(static_cast<BoxCollider*>(collider));   
    }

    void GameObject::registerRigidBodyForThisObject(GameObjectComponent* rigidBody)
    {
        Engine::instance()->physicsManager->registerRigidBody(static_cast<RigidBody*>(rigidBody));
    }

    void GameObject::unregisterScriptForThisObject(GameObjectComponent* script)
    {
        Engine::instance()->logicsManager->unregisterScript(static_cast<Script*>(script));
    }

    void GameObject::unregisterRendererForThisObject(GameObjectComponent* renderer)
    {
        Engine::instance()->renderManager->unregisterRenderer(static_cast<Renderer2D*>(renderer));
    }

    void GameObject::unregisterColliderForThisObject(GameObjectComponent* collider)
    {
        Engine::instance()->physicsManager->unregisterCollider(static_cast<BoxCollider*>(collider));
    }

    void GameObject::unregisterRigidBodyForThisObject(GameObjectComponent* rigidBody)
    {
        Engine::instance()->physicsManager->unregisterRigidBody(static_cast<RigidBody*>(rigidBody));
    }

}