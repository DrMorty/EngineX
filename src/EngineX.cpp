#include <iostream>

#include "core/Engine.h"

class TestScript : public Script
{
 public:
    void start()
    {
        object->transform.position.y = 400.0f;
    }

    void update()
    {
        object->transform.position.x += 0.1;
    }
};

int main()
{
    sf::Texture texture;
    texture.loadFromFile("logo.png");

    engineX::createObject("test");
    
    engineX::getObject("test").addComponent<Renderer2D>();
    engineX::getObject("test").addComponent<TestScript>();
    engineX::getObject("test").getComponent<Renderer2D>()->setSprite(texture);

    engineX::runScene();

    return 0;
}
