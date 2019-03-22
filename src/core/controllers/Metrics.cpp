#include "Metrics.h"
#include <iostream>

namespace engine
{
    int Metrics::fps = 0;
    bool Metrics::isActiveLogging = false;

    void Metrics::updateMetrics()
    {
        static int frames = 0;
        static float elapsedTime = 0;
        
        elapsedTime += Time::deltaTime;
        frames++;

        if (elapsedTime >= 1.0f)
            updateFPS(frames, elapsedTime);
    }

    void Metrics::updateFPS(int& frames, float& elapsed)
    {
        fps = frames / elapsed;

        frames = 0;
        elapsed = 0;

        if (isActiveLogging)
            std::cout << "FPS: " << fps << std::endl;
    }

    void Metrics::enableLogging()
    {
        isActiveLogging = true;
    }

    void Metrics::disableLogging()
    {
        isActiveLogging = false;
    }
}