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

    void PhysicsManager::registerRigidBody(RigidBody* rigidBody)
    {
        rigidBodies.push_back(rigidBody);
    }

    void PhysicsManager::unregisterRigidBody(RigidBody* rigidBody)
    {
        rigidBodies.erase(remove(rigidBodies.begin(), rigidBodies.end(), rigidBody), rigidBodies.end());
    }


    void PhysicsManager::updatePhysics()
    {
        detectCollisions();
        calculatePhysics();
    }

    void PhysicsManager::calculatePhysics()
    {
        for (auto rigidBody : rigidBodies)
        {
            rigidBody->prevPosition = rigidBody->object->transform.position;

            if (rigidBody->isGravity)
                rigidBody->velocity -= Vector3(0, rigidBody->gravityValue);

            rigidBody->object->transform.position += rigidBody->velocity * Time::deltaTime;
        }
            
    }

    void PhysicsManager::detectCollisions()
    {
        for (auto firstCollider : colliders)
            for (auto secondCollider : colliders)
            {
                if (!firstCollider->object->hasComponent<RigidBody>())
                    continue;

                if (firstCollider == secondCollider)
                    continue;

                if (isCollision(firstCollider, secondCollider))
                {
                    auto firstObjectDetails = getCollisionDetails(firstCollider, secondCollider);
                    resolveCollision(firstObjectDetails);

                    auto secondObjectDetails = firstObjectDetails;
                    secondObjectDetails.collider1 = firstObjectDetails.collider2;
                    secondObjectDetails.collider2 = firstObjectDetails.collider1;
                    secondObjectDetails.collisionTrajectory = -1.0f * firstObjectDetails.collisionTrajectory;

                    Engine::instance()->logicsManager->callOnCollisionForObject(firstCollider->object, firstObjectDetails);
                    Engine::instance()->logicsManager->callOnCollisionForObject(secondCollider->object, secondObjectDetails);       
                }
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

        if (rightDown1.y > leftTop2.y)
            return false;

        if (leftTop1.y < rightDown2.y)
            return false;

        return true;
    }

    CollisionDetails PhysicsManager::getCollisionDetails(BoxCollider* first, BoxCollider* second)
    {
        auto collisionPosition = first->object->transform.position;

        auto v = collisionPosition - first->object->getComponent<RigidBody>()->prevPosition;
        float v_len = sqrt(v.x*v.x+v.y*v.y);
        auto trajectory = v / v_len;

        for (int i = 1; isCollision(first, second); i++) 
            first->object->transform.position -= trajectory * i;

        auto d = collisionPosition - first->object->transform.position;

        return CollisionDetails(first, second, sqrt(d.x*d.x+d.y*d.y), trajectory);
    }

    void PhysicsManager::resolveCollision(CollisionDetails& details)
    {
        if (!details.collider1->isDynamic)
            return;

        if (!details.collider2->object->hasComponent<RigidBody>())
        {
            details.collider1->object->getComponent<RigidBody>()->velocity = Vector3();
            return;
        }

        //Add impulse resolving
        details.collider1->object->getComponent<RigidBody>()->velocity = Vector3();
    }
}