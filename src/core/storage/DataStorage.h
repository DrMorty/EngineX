#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <map>
#include <string>
#include <memory>

#include "GameObject.h"

namespace engine
{   
    struct WindowSettings
    {
        std::string name;

        int width;
        int height;
    };

    const WindowSettings DEFAULT_WINDOW_SETTINGS = {"Default", 1200, 800};


    class DataStorage
    {
    public:

        DataStorage(WindowSettings windowSettings = DEFAULT_WINDOW_SETTINGS);
        ~DataStorage();

        sf::RenderWindow& getWindowInstance();
        std::map<std::string, GameObject>& getGameObjects();

        std::map<std::string, GameObject> gameObjects;

    private:
        sf::RenderWindow windowInstance;
    };
}

#endif