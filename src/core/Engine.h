#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "management/RenderManager.h"
#include "management/EventManager.h"
#include "storage/DataStorage.h"

class Engine
{
 public: 

    static Engine* instance();
    ~Engine();

    void initialize();
    void run();

    std::unique_ptr<RenderManager> renderManager;
    std::unique_ptr<EventManager> eventManager;
    std::unique_ptr<DataStorage> dataStorage;

 private:
    Engine();

    static Engine* m_instance;
};

#endif