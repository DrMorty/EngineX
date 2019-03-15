#include <iostream>

#include "core/Engine.h"

class TestScript : public Script
{
 public:
    void start()
    {
    }

    void update()
    {
        std::cout << "helo" << std::endl;
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
