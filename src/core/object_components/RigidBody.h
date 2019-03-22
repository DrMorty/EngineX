#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include <SFML/Graphics.hpp>

#include "GameObjectComponent.h"

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

        sf::Vector2f velocity;

        sf::Vector2f prevPosition;

    private:
        
    };
}

#endif