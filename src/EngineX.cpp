#include <iostream>

#include "core/Engine.h"

class TestScript : public Script
{
 public:
    void start()
    {
        object->transform.position.y = 100;
    }

    void update()
    {
        if (engineX::Input::getKey(KeyCode::W))
            object->transform.position.y += 0.1;

        if (engineX::Input::getKey(KeyCode::S))
            object->transform.position.y -= 0.1;

        if (engineX::Input::getKey(KeyCode::A))
            object->transform.position.x -= 0.1;

        if (engineX::Input::getKey(KeyCode::D))
            object->transform.position.x += 0.1;

        if (engineX::Input::getKeyDown(KeyCode::Space))
            object->getComponent<RigidBody>()->velocity.y -= -500; 
    }
};

int main()
{
    sf::Texture texture;
    texture.loadFromFile("logo.png");

    engineX::createObject("test");
    
    engineX::getObject("test").addComponent<Renderer2D>();
    engineX::getObject("test").getComponent<Renderer2D>()->setSprite(texture);

    engineX::getObject("test").addComponent<BoxCollider>();
    engineX::getObject("test").getComponent<BoxCollider>()->enableHighlight();

    engineX::getObject("test").addComponent<RigidBody>();

    engineX::getObject("test").addComponent<TestScript>();

    engineX::createObject("ground");

    engineX::getObject("ground").addComponent<BoxCollider>();
    engineX::getObject("ground").getComponent<BoxCollider>()->enableHighlight();
    engineX::getObject("ground").getComponent<BoxCollider>()->setCollider(-200, -300, 200, -400);

    engineX::runScene();

    return 0;
}
