#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <SFML/Graphics.hpp>

enum KeyCode {
    W = sf::Keyboard::Key::W,
    A = sf::Keyboard::Key::A,
    S = sf::Keyboard::Key::S, 
    D = sf::Keyboard::Key::D,
    Space = sf::Keyboard::Key::Space
};

namespace engine
{
    class InputController
    {
     public:
        bool getKeyDown(KeyCode key);
    };
}

#endif