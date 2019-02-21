#include <iostream>

#include "core/Engine.h"
#include "core/object_components/Renderer2D.h"

Engine* Engine::m_instance = 0;

int main()
{
    Engine::instance()->initialize();
    Engine::instance()->dataStorage->gameObjects["test"] = GameObject("testHAHAHA");
    Engine::instance()->dataStorage->gameObjects["test"].addComponent<Renderer2D>();
    
    sf::Texture texture;
    texture.loadFromFile("logo.png");

    Engine::instance()->dataStorage->gameObjects["test"].getComponent<Renderer2D>()->setSprite(texture);
    Engine::instance()->run();

    return 0;
}
