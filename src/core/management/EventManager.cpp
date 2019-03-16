#include <SFML/Graphics.hpp>

#include "EventManager.h"
#include "../Engine.h"

namespace engine
{
    void EventManager::pollEvents()
    {
        sf::Event event;
        auto& window = Engine::instance()->dataStorage->getWindowInstance();

        while(window.pollEvent(event))
        {
            newEventsPerFrame.push_back(event);
        }
    }

    void EventManager::clearEvents()
    {
        newEventsPerFrame.clear();
    }
}