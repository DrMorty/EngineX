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
        Vector3 textureSize = texture.getSize();
        Vector3 newPosition = Camera::projectionToCamera(object->transform.position - Vector3(textureSize.x, -textureSize.y) / 2);

        sprite.setPosition(newPosition);
        Engine::instance()->renderManager->renderObject(sprite);
    }

    sf::Texture& Renderer2D::getTexture()
    {
        return texture;
    }
}