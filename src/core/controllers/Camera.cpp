#include "Camera.h"
#include "../Engine.h"

namespace engine
{
    Vector3 Camera::position;

    Vector3 Camera::projectionToCamera(Vector3 objectPosition)
    {
        Vector3 windowSize = Engine::instance()->dataStorage->getWindowInstance().getSize();
        
        return Vector3(objectPosition.x, -objectPosition.y) + position + windowSize / 2;
    }
}