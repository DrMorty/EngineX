#include "GameObject.h"
#include <iostream>
#include <string>

GameObject::GameObject()
{  
};

GameObject::GameObject(std::string t_name) : name(t_name) 
{
};

GameObject::~GameObject() 
{
};

void GameObject::setSprite(const sf::Texture& texture)
{
    if (!sprite)
    {
        sprite = std::make_shared<sf::Sprite>(sf::Sprite(texture));
        return;
    }

    sprite->setTexture(texture);
}