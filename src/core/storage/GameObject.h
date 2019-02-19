#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

#include <memory>

class GameObject
{
 public:
    GameObject();
    GameObject(std::string t_name);
    ~GameObject();

    std::string name;

    bool isDrawable;
    std::shared_ptr<sf::Sprite> sprite;

    void setSprite(const sf::Texture& texture);

 private:
};

#endif