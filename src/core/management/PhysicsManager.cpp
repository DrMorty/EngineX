#include "PhysicsManager.h"

#include "../Engine.h"

namespace engine
{
    void PhysicsManager::registerCollider(BoxCollider* collider)
    {
        colliders.push_back(collider);
    }

    void PhysicsManager::unregisterCollider(BoxCollider* collider)
    {
        colliders.erase(remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }

    void PhysicsManager::updatePhysics()
    {
        detectCollisions();
    }

    void PhysicsManager::detectCollisions()
    {

    }
}