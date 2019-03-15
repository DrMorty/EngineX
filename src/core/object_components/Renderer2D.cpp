#include <iostream>

#include "Renderer2D.h"
#include "../Engine.h"

namespace engine
{   
    void Renderer2D::setSprite(const sf::Texture& t_texture)
    {
        texture = t_texture;
        sprite.setTexture(texture);
    }

    void Renderer2D::setTexture(const sf::Texture& t_texture)
    {
        setSprite(t_texture);
    }

    void Renderer2D::draw(sf::RenderWindow& windowInstance)
    {
        sprite.setPosition(object->transform.position);
        Engine::instance()->renderManager->renderObject(sprite);
    }
}