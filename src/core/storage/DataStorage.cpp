#include "DataStorage.h"

namespace engine
{   
    DataStorage::DataStorage(WindowSettings windowSettings) : windowInstance(sf::RenderWindow(sf::VideoMode(windowSettings.width, windowSettings.height), windowSettings.name))
    {
    }

    DataStorage::~DataStorage()
    {
    }

    sf::RenderWindow& DataStorage::getWindowInstance()
    {
        return windowInstance;
    }

    std::map<std::string, GameObject>& DataStorage::getGameObjects()
    {
        return gameObjects;
    }
}