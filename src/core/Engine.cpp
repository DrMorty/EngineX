#include "Engine.h"

#include <exception>

namespace engine
{    
    class EngineException: public std::exception
    {
    };

    EngineException GameObjectAlreadyExist;

    Engine* Engine::m_instance = 0;

    Engine::Engine()
    {
        logicsManager = std::make_unique<LogicsManager>();
        renderManager = std::make_unique<RenderManager>();
        physicsManager = std::make_unique<PhysicsManager>();
        dataStorage = std::make_unique<DataStorage>();
    };

    Engine::~Engine()
    {
    };

    Engine* Engine::instance()
    {
        if (!m_instance)
        {
            m_instance = new Engine();
        }

        return m_instance;
    }

    void Engine::run()
    {
        for(;;)
        {
            renderManager -> renderDrawableObjects();
            physicsManager -> updatePhysics();
            logicsManager -> updateLogics();
        }
    };
}

namespace engineX
{
    void createObject(std::string name)
    {
        auto& v = Engine::instance()->dataStorage->getGameObjects();

        if (v.find(name) != v.end())
            throw GameObjectAlreadyExist;

        v.try_emplace(name, name);
    }

    GameObject& getObject(std::string name)
    {
        return Engine::instance()->dataStorage->gameObjects[name];
    }

    void deleteObject(std::string name)
    {
        Engine::instance()->dataStorage->gameObjects.erase(name);
    }

    void deleteObject(GameObject* object)
    {
        Engine::instance()->dataStorage->gameObjects.erase(object->name);
    }

    void runScene()
    {
        Engine::instance()->run();
    }
}