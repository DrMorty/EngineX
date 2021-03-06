#include "Input.h"

#include "../Engine.h"

namespace engine
{
    std::map<KeyCode, bool> Input::isKeyHold;
    std::map<KeyCode, bool> Input::isPressedOnce;

    bool Input::getKey(KeyCode key)
    {
        return isKeyHold[key];
    }

    bool Input::getKeyDown(KeyCode key)
    {
        auto keyPressedEvents = Engine::instance()->logicsManager->eventManager.getAllEventsOfType(sf::Event::KeyPressed);

        for (auto& event : keyPressedEvents)
            if (event.key.code == key && isPressedOnce[key])
                return true;
                
        return false;
    }

    bool Input::getKeyUp(KeyCode key)
    {
        auto keyPressedEvents = Engine::instance()->logicsManager->eventManager.getAllEventsOfType(sf::Event::KeyReleased);

        for (auto& event : keyPressedEvents)
            if (event.key.code == key)
                return true;

        return false;
    }

    void Input::keyPressed(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        isPressedOnce[keyCode] = true;

        if (isKeyHold[keyCode])
            isPressedOnce[keyCode] = false;

        isKeyHold[keyCode] = true;
    }

    void Input::keyReleased(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        isPressedOnce[keyCode] = false;
        isKeyHold[keyCode] = false;
    }

    Input::Input()
    {
    }

    KeyCode Input::convertFromSfmlKey(sf::Keyboard::Key key)
    {
        switch(key)
        {
            case KeyCode::W:        return W;
            case KeyCode::A:        return A;
            case KeyCode::S:        return S;
            case KeyCode::D:        return D;
            case KeyCode::Space:    return Space;
        }
    }
}