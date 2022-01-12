#pragma once

#include <SDL2/SDL.h>
#include "World.h"
#include "Objects/Types.h"
#include "Objects/Square.h"

class Viewer
{
    public:
        Viewer(uint32_t width, uint32_t height);
        ~Viewer();

        void resize(uint32_t n_width, uint32_t n_height);

        void draw_square(Square s);
        void draw(World & world);

    private:
        SDL_Window *window { 0 };
        SDL_Renderer *renderer { 0 };

        uint32_t m_width { 0 };
        uint32_t m_height { 0 };
};
