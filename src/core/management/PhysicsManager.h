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

        void registerRigidBody(RigidBody* rigidBody);
        void unregisterRigidBody(RigidBody* rigidBody);

    private:
        std::vector<BoxCollider*> colliders;
        std::vector<RigidBody*> rigidBodies;

        void calculatePhysics();
        void detectCollisions();
        void resolveCollision(CollisionDetails& details);

        bool isCollision(BoxCollider* first, BoxCollider* second);

        CollisionDetails getCollisionDetails(BoxCollider* first, BoxCollider* second);
    };
}

#endif 