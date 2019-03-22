#include <iostream>

#include "core/Engine.h"

class TestScript : public Script
{
 public:
    void start()
    {
        object->transform.position.x = 400.0f;
        object->transform.position.y = 300.0f;
    }

    void update()
    {
        if (engineX::Input::getKey(KeyCode::W))
            object->transform.position.y -= 0.1;

        if (engineX::Input::getKey(KeyCode::S))
            object->transform.position.y += 0.1;

        if (engineX::Input::getKey(KeyCode::A))
            object->transform.position.x -= 0.1;

        if (engineX::Input::getKey(KeyCode::D))
            object->transform.position.x += 0.1;

        if (engineX::Input::getKeyDown(KeyCode::Space))
            velocityY = -400;

        object->transform.position.y += velocityY * engineX::Time::deltaTime;
        velocityY += engineX::Time::deltaTime * 400;

        if (object->transform.position.y > 400)
            object->transform.position.y = 400; 

        timeToSelfDestroy -= engineX::Time::deltaTime;

        if (timeToSelfDestroy <= 0)
            engineX::deleteObject(object); 
    }

    float velocityY = 0;
    float timeToSelfDestroy = 3;
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

    engineX::getObject("test").addComponent<TestScript>();

    engineX::runScene();

    return 0;
}
