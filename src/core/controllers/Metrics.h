#ifndef METRICS_H
#define METRICS_H

#include "Time.h"

namespace engine
{
    class Metrics
    {
     public:
        static void updateMetrics();
        static void updateFPS(int& frames, float& elapsed);

        static void enableLogging();
        static void disableLogging();

        static int fps;

     private:
        static bool isActiveLogging;
        Metrics();
    };
}

#endif