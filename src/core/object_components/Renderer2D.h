#ifndef RENDERER_2D_H
#define RENDERER_2D_H

#include <SFML/Graphics.hpp>

#include "GameObjectComponent.h"

class Renderer2D : public GameObjectComponent
{
 public:
    ~Renderer2D() 
    {};

    void setSprite(const sf::Texture& t_texture);
    void setTexture(const sf::Texture& t_texture);
    void draw(sf::RenderWindow& windowInstance);

 private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif