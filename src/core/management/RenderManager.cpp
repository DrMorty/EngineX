#include "RenderManager.h"
#include "../Engine.h"

RenderManager::RenderManager(WindowSettings windowSettings) : windowInstance(sf::RenderWindow(sf::VideoMode(windowSettings.width, windowSettings.height), windowSettings.name))
{
}

void RenderManager::renderDrawableObjects() 
{
    windowInstance.clear();

    for (auto [name, object] : Engine::instance() -> dataStorage -> gameObjects)
    {
        if (object.isDrawable)
            renderObject(object);
    };

    windowInstance.display();
}   

void RenderManager::renderObject(const GameObject& object)
{
    if (object.sprite)
        windowInstance.draw(*object.sprite);
}