#ifndef SCRIPT_H
#define SCRIPT_H

#include "GameObjectComponent.h"
#include "BoxCollider.h"

namespace engine
{   
    class Script : public GameObjectComponent
    {
    public:

        virtual void start() = 0;
        virtual void update() = 0;   

        Script()
        {
        }

        ~Script()
        {
        }

        virtual void onCollision(CollisionDetails& details)
        {
        }
    };
}

#endif