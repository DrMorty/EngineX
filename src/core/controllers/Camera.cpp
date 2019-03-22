#include "Camera.h"
#include "../Engine.h"

namespace engine
{
    sf::Vector2f Camera::position;

    sf::Vector2f Camera::projectionToCamera(sf::Vector2f objectPosition)
    {
        auto& window = Engine::instance()->dataStorage->getWindowInstance();
        
        return sf::Vector2f(objectPosition.x, -objectPosition.y) + position + sf::Vector2f(window.getSize() / 2u);
    }
}