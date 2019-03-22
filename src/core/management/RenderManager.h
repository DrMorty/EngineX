#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SFML/Graphics.hpp>
#include "../object_components/Renderer2D.h"

namespace engine
{   
    class RenderManager
    {
    public:
        RenderManager();

        void renderDrawableObjects();
        void renderObject(sf::Drawable& object);

        void registerRenderer(Renderer2D* renderer);

    private:

        std::vector<Renderer2D*> renderers;
    };
}

#endif