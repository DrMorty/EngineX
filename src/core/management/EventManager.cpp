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

    std::vector<sf::Event> EventManager::getAllEventsOfType(sf::Event::EventType type)
    {
        std::vector<sf::Event> eventsOfType;

        for (auto& event : newEventsPerFrame)
            if (event.type == type)
                eventsOfType.push_back(event);

        return eventsOfType;
    }
}