#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <iostream>

#include "../object_components/GameObjectComponent.h"
#include "../object_components/Script.h"

namespace engine
{   
    class Transform
    {
    public:
        sf::Vector2<float> position = {0.0, 0.0};
        sf::Vector2<float> rotation = {0.0, 0.0};
        sf::Vector2<float> scale = {1.0, 1.0};
    };

    class GameObject
    {
    public:
        GameObject();
        GameObject(std::string t_name);
        ~GameObject();

        template <typename ComponentType>
        void addComponent();

        template <typename ComponentType>
        ComponentType* getComponent();

        template <typename ComponentType>
        bool hasComponent();

        void setSprite(const sf::Texture& texture);

        std::string name;
        Transform transform;

    private:
        void registerScriptForThisObject(GameObjectComponent* script);

        std::vector<GameObjectComponent*> m_components;
    };

    template <typename ComponentType>
    void GameObject::addComponent()
    {
        auto component = new ComponentType;
        component->typeName = typeid(ComponentType).name();
        component->object = this;

        m_components.push_back(component);

        if (std::is_base_of<Script, ComponentType>())
            registerScriptForThisObject(component);
    }

    template <typename ComponentType>
    ComponentType* GameObject::getComponent()
    {
        for (auto component : m_components)
            if (component->typeName == typeid(ComponentType).name())
            {
                ComponentType* casted = static_cast<ComponentType*>(component);
                return casted;
            }
    }

    template <typename ComponentType>
    bool GameObject::hasComponent()
    {
        for (auto component : m_components)
            if (component->typeName == typeid(ComponentType).name())
            {
                return true;
            }

        return false;
    }
}
#endif