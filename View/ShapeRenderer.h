#ifndef PHY_RENDERER_H
#define PHY_RENDERER_H

#include <SDL.h>
#include "../Interfaces/Shape.h"
#include "../Model/Shapes/Square.h"

class ShapeRenderer {
    public:
    ShapeRenderer(SDL_Renderer *renderer) : m_renderer(renderer) {}
    ~ShapeRenderer();

    void clear();
    void present();

    void render(Square *s);
    void render(Shape *s);

    private:
    
    SDL_Renderer *m_renderer {};
};

#endif