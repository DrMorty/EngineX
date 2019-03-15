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

    createObject("test");
    getObject("test").addComponent<Renderer2D>();
    getObject("test").addComponent<TestScript>();
    getObject("test").getComponent<Renderer2D>()->setSprite(texture);

    runScene();

    return 0;
}
