#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include <vector>

#include "../storage/GameObject.h"

namespace engine
{   
    class PhysicsManager
    {
    public:
        void updatePhysics();

        void registerCollider(BoxCollider* collider);
        void unregisterCollider(BoxCollider* collider);

    private:
        std::vector<BoxCollider*> colliders;

        void detectCollisions();
        bool isCollision(BoxCollider* first, BoxCollider* second);
        
        CollisionDetails getCollisionDetails(BoxCollider* first, BoxCollider* second);
    };
}

#endif 