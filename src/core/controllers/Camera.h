#ifndef CAMERA_H
#define CAMERA_H

#include "../common/math/Math.h"

namespace engine
{
    class Camera
    {
     public:
        static Vector3 projectionToCamera(Vector3 objectPosition);

     private:
        Camera();

        static Vector3 position;
    };
}

#endif