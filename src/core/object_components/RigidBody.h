#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "GameObjectComponent.h"
#include "../common/math/Math.h"

namespace engine
{   
    class RigidBody : public GameObjectComponent
    {
    public:
        ~RigidBody() 
        {};

        float gravityValue = 1.0f;
        bool isGravity = true;

        float mass = 1.0f;

        Vector3 velocity;
        Vector3 prevPosition;

    private:
        
    };
}

#endif