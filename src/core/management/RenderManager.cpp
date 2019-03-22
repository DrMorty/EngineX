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

        for (auto renderer : renderers)
            renderer->draw(window);

        for (auto collider : colliders)
            renderCollider(collider);

        window.display();
    }   

    void RenderManager::renderObject(sf::Drawable& object)
    {
        Engine::instance()->dataStorage->getWindowInstance().draw(object);
    }

    void RenderManager::renderCollider(BoxCollider* collider)
    {
        sf::Vertex lines[] = 
        {
            sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->leftTop.y)),
            sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->rightDown.y)),

            sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->leftTop.y)),
            sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->leftTop.y)),

            sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->leftTop.y)),
            sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->rightDown.y)),

            sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->rightDown.y)),
            sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->rightDown.y)),
        };

        for (auto& line : lines)
            line.position += collider->object->transform.position;

        Engine::instance()->dataStorage->getWindowInstance().draw(lines, 8, sf::Lines);
    }

    void RenderManager::registerRenderer(Renderer2D* renderer)
    {
        renderers.push_back(renderer);
    }

    void RenderManager::unregisterRenderer(Renderer2D* renderer)
    {
        renderers.erase(remove(renderers.begin(), renderers.end(), renderer), renderers.end());
    }

    void RenderManager::registerCollider(BoxCollider* collider)
    {
        colliders.push_back(collider);
    }

    void RenderManager::unregisterCollider(BoxCollider* collider)
    {
        colliders.erase(remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }
}