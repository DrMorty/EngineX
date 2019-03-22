#include "PhysicsManager.h"

#include "../Engine.h"

#include <SFML/Graphics.hpp>
#include <cmath>

namespace engine
{
    void PhysicsManager::registerCollider(BoxCollider* collider)
    {
        colliders.push_back(collider);
    }

    void PhysicsManager::unregisterCollider(BoxCollider* collider)
    {
        collider->disableHighlight();
        colliders.erase(remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }

    void PhysicsManager::updatePhysics()
    {
        detectCollisions();
    }

    void PhysicsManager::detectCollisions()
    {
        for (auto firstCollider : colliders)
            for (auto secondCollider : colliders)
            {
                if (firstCollider == secondCollider)
                    continue;

                if (isCollision(firstCollider, secondCollider))
                    auto details = getCollisionDetails(firstCollider, secondCollider);
            }

    }

    bool PhysicsManager::isCollision(BoxCollider* first, BoxCollider* second)
    {
        sf::Vector2f leftTop1 = first->object->transform.position + first->leftTop;
        sf::Vector2f leftTop2 = second->object->transform.position + second->leftTop;

        sf::Vector2f rightDown1 = first->object->transform.position + first->rightDown;
        sf::Vector2f rightDown2 = second->object->transform.position + second->rightDown;

        if (rightDown1.x < leftTop2.x)
            return false;

        if (leftTop1.x > rightDown2.x)
            return false;

        if (rightDown1.y < leftTop2.y)
            return false;

        if (leftTop1.y > rightDown2.y)
            return false;

        return true;
    }

    CollisionDetails PhysicsManager::getCollisionDetails(BoxCollider* first, BoxCollider* second)
    {
        auto firstPositionInCollision = first->object->transform.position;
        auto v = firstPositionInCollision - second->object->transform.position;

        float v_len = sqrt(v.x*v.x+v.y*v.y);

        auto trajectory = v / v_len;

        for (int i = 1; isCollision(first, second); i++) 
            first->object->transform.position -= i * 1.0f * trajectory;

        auto d = firstPositionInCollision - first->object->transform.position;

        return CollisionDetails(first, second, sqrt(d.x*d.x+d.y*d.y), trajectory);
    }
}