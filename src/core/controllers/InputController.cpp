#include "InputController.h"

#include "../Engine.h"

namespace engine
{
    bool InputController::getKeyDown(KeyCode key)
    {
        auto keyPressedEvents = Engine::instance()->logicsManager->eventManager.getAllEventsOfType(sf::Event::KeyPressed);

        for (auto& event : keyPressedEvents)
            if (event.key.code == key)
                return true;

        return false;
    }
}