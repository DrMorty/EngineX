#include "RenderManager.h"
#include "../object_components/Renderer2D.h"
#include "../Engine.h"

namespace engine
{   
    RenderManager::RenderManager()
    {
    }

    void RenderManager::renderDrawableObjects() 
    {
        auto& window = Engine::instance()->dataStorage->getWindowInstance();

        window.clear();

        for (auto& [name, object] : Engine::instance() -> dataStorage -> gameObjects)
        {
            if (object.hasComponent<Renderer2D>())
                object.getComponent<Renderer2D>()->draw(window);
        };

        window.display();
    }   

    void RenderManager::renderObject(sf::Drawable& object)
    {
        Engine::instance()->dataStorage->getWindowInstance().draw(object);
    }
}