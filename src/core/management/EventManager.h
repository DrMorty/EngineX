#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <list>

namespace engine
{
    class EventManager
    {
     public:
        void pollEvents();
        void clearEvents();

     private:
        std::list<sf::Event> newEventsPerFrame;
    };
}

#endif