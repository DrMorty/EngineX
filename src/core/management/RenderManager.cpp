#include "RenderManager.h"
#include "../object_components/Renderer2D.h"
#include "../Engine.h"

namespace engine
{   
    RenderManager::RenderManager(WindowSettings windowSettings) : windowInstance(sf::RenderWindow(sf::VideoMode(windowSettings.width, windowSettings.height), windowSettings.name))
    {
    }

    void RenderManager::renderDrawableObjects() 
    {
        windowInstance.clear();

        for (auto [name, object] : Engine::instance() -> dataStorage -> gameObjects)
        {
            if (object.hasComponent<Renderer2D>())
                object.getComponent<Renderer2D>()->draw(windowInstance);
        };

        windowInstance.display();
    }   

    void RenderManager::renderObject(sf::Drawable& object)
    {
        windowInstance.draw(object);
    }
}