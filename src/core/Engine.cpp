    #include "Engine.h"
    
    Engine::Engine()
    {

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

    void Engine::initialize()
    {
        eventManager = std::make_unique<EventManager>();
        renderManager = std::make_unique<RenderManager>();
        dataStorage = std::make_unique<DataStorage>();
    };

    void Engine::run()
    {
        for(;;)
        {
            renderManager -> renderDrawableObjects();
        }
    };