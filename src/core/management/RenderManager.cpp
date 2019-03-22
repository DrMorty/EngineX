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

        for (auto  renderer : renderers)
            renderer->draw(window);

        window.display();
    }   

    void RenderManager::renderObject(sf::Drawable& object)
    {
        Engine::instance()->dataStorage->getWindowInstance().draw(object);
    }

    void RenderManager::registerRenderer(Renderer2D* renderer)
    {
        renderers.push_back(renderer);
    }

    void RenderManager::unregisterRenderer(Renderer2D* renderer)
    {
        renderers.erase(remove(renderers.begin(), renderers.end(), renderer), renderers.end());
    }
}