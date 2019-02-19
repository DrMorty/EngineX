#include "core/Engine.h"
#include <iostream>

Engine* Engine::m_instance = 0;

int main()
{
    Engine::instance() -> initialize();
    Engine::instance() -> dataStorage->gameObjects["test"] = GameObject("testHAHAHA");

    sf::Texture texture;
    texture.loadFromFile("logo.png");

    Engine::instance() -> dataStorage->gameObjects["test"].setSprite(texture);
    Engine::instance() -> run();

    return 0;
}
