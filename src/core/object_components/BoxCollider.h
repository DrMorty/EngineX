#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "GameObjectComponent.h"

#include "SFML/Graphics.hpp"

#include <iostream>

namespace engine
{   
    class BoxCollider : public GameObjectComponent
    {
     public:
        BoxCollider();
        ~BoxCollider() {};

        void setCollider(float x1, float y1, float x2, float y2);
        void setColliderBySprite();

        void enableHighlight();
        void disableHighlight();

        sf::Vector2f leftTop;
        sf::Vector2f rightDown;

     private:
        bool highlighted = false;
    };
}

#endif