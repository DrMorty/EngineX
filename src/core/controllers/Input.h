#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <map>

enum KeyCode {
    W = sf::Keyboard::Key::W,
    A = sf::Keyboard::Key::A,
    S = sf::Keyboard::Key::S, 
    D = sf::Keyboard::Key::D,
    Space = sf::Keyboard::Key::Space
};

namespace engine
{
    class Input
    {
     public:
        static bool getKey(KeyCode key);
        static bool getKeyDown(KeyCode key);
        static bool getKeyUp(KeyCode key);

        static void keyPressed(sf::Keyboard::Key key);
        static void keyReleased(sf::Keyboard::Key key);

        static std::map<KeyCode, bool> isKeyHold;

     private:
        Input();
        static KeyCode convertFromSfmlKey(sf::Keyboard::Key key);
    };
}

#endif