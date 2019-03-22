#include "BoxCollider.h"

#include "../Engine.h"

namespace engine
{
    void BoxCollider::setCollider(float x1, float y1, float x2, float y2)
    {
        leftTop.x = x1;
        leftTop.y = y1;

        rightDown.x = x2;
        rightDown.y = y2;
    }

    void BoxCollider::enableHighlight()
    {
        if (!highlighted)
            Engine::instance()->renderManager->registerCollider(this);

        highlighted = true;
    }

    void BoxCollider::disableHighlight()
    {
        if (highlighted)
            Engine::instance()->renderManager->unregisterCollider(this);

        highlighted = false;
    }
}