#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "GameObjectComponent.h"

#include "SFML/Graphics.hpp"

namespace engine
{   
    class BoxCollider : public GameObjectComponent
    {
     public:
        ~BoxCollider() 
        {};

        void setCollider(float x1, float y1, float x2, float y2);

        void enableHighlight();
        void disableHighlight();

        sf::Vector2f leftTop;
        sf::Vector2f rightDown;

     private:
        bool highlighted = false;
    };
}

#endif