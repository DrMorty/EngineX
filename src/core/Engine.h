#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "management/RenderManager.h"
#include "management/LogicsManager.h"
#include "storage/DataStorage.h"

#include "object_components/Script.h"
#include "object_components/Renderer2D.h"

#include "controllers/InputController.h"

using engine::Renderer2D;
using engine::Script;

namespace engine
{
    class Engine
    {
    public: 

        static Engine* instance();
        ~Engine();

        void run();

        std::unique_ptr<RenderManager> renderManager;
        std::unique_ptr<LogicsManager> logicsManager;
        std::unique_ptr<DataStorage> dataStorage;

    private:
        Engine();

        static Engine* m_instance;
    };
}

namespace engineX
{
    using namespace engine;

    static InputController input;

    void createObject(std::string name);
    GameObject& getObject(std::string name);

    //void destroyObject(std::string name);
    //void destroyObject(GameObject& object);

    void runScene();
}

#endif