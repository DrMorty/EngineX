#include <iostream>
#include <cstdlib>
#include <string>

#include "core/Engine.h"

class PlatformBehaviour : public Script
{
 public:
    void start()
    {
        object->addComponent<BoxCollider>();
        object->getComponent<BoxCollider>()->enableHighlight();
        object->getComponent<BoxCollider>()->setCollider(-150, 20, 150, -20);

        object->transform.position.y = -350;
    }

    void update()
    {
        if (engineX::Input::getKey(KeyCode::A))
            object->transform.position.x -= 0.5;

        if (engineX::Input::getKey(KeyCode::D))
            object->transform.position.x += 0.5;
    }
};

class BlockBehaviour : public Script
{
 public:
    void start()
    {
        object->addComponent<BoxCollider>();
        object->getComponent<BoxCollider>()->enableHighlight();
        object->getComponent<BoxCollider>()->setCollider(-50, 15, 50, -15);
    }

    void update()
    {
    }

    void onCollision(CollisionDetails& details)
    {
        engineX::deleteObject(object);
    }

};

class BallBehaviour : public Script
{
 public:
    void start()
    {
        object->addComponent<BoxCollider>();
        object->getComponent<BoxCollider>()->enableHighlight();
        object->getComponent<BoxCollider>()->isDynamic = false;
        object->getComponent<BoxCollider>()->setCollider(-10, 10, 10, -10);

        object->addComponent<RigidBody>();
        object->getComponent<RigidBody>()->velocity = sf::Vector2f(80, 80);
        object->getComponent<RigidBody>()->isGravity = false;
    }

    void update()
    {
        if (object->transform.position.x > 600 || object->transform.position.x < -600)
            object->getComponent<RigidBody>()->velocity.x *= -1.0f;

        if (object->transform.position.y > 400)
            object->getComponent<RigidBody>()->velocity.y *= -1.0f;
    
        if (object->transform.position.y < -400)
            std::cout << "Game Over" << std::endl;
    }

    void onCollision(CollisionDetails& details)
    {
        object->getComponent<RigidBody>()->velocity.y *= -1;
    }
};

int main()
{
    // Create logo background
    engineX::createObject("test");

    sf::Texture texture;
    texture.loadFromFile("logo.png");

    engineX::getObject("test").transform.position.y = 250;
    engineX::getObject("test").addComponent<Renderer2D>();
    engineX::getObject("test").getComponent<Renderer2D>()->setSprite(texture);

    // Construct and create object platform
    engineX::createObject("platform");
    engineX::getObject("platform").addComponent<PlatformBehaviour>();

    engineX::createObject("ball");
    engineX::getObject("ball").addComponent<BallBehaviour>();

    engineX::getObject("ball").transform.position = engine::Vector3(0, -300);
    

    // Construct and create blocks
    for (int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::string objName = std::to_string(i) + "block" + std::to_string(j);

            engineX::createObject(objName);

            engineX::getObject(objName).transform.position.y = 50 - 50 * j;
            engineX::getObject(objName).transform.position.x = -350 + i * 150;

            engineX::getObject(objName).addComponent<BlockBehaviour>();
            
        }
    }

    engineX::runScene();

    return 0;
}
