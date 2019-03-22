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
        sf::Vector2f newPosition = object->transform.position;
        newPosition -= sf::Vector2f(texture.getSize().x / 2.0, texture.getSize().y / 2.0);

        sprite.setPosition(newPosition);
        Engine::instance()->renderManager->renderObject(sprite);
    }

    sf::Texture& Renderer2D::getTexture()
    {
        return texture;
    }
}