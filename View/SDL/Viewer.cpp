#include "Viewer.h"

Viewer::Viewer(uint32_t width, uint32_t height)
    : m_width(width)
    , m_height(height)
{
    if (SDL_CreateWindowAndRenderer(
        m_width,
        m_height,
        SDL_WINDOW_RESIZABLE,
        &window,
        &renderer
    ) < 0)
    {
        SDL_Log("SDL could not create a window/renderer!: %s", SDL_GetError());
        exit(1);
    };

    SDL_SetWindowTitle(window, "PhysicsEngine");
}

Viewer::~Viewer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Viewer::resize(uint32_t n_width, uint32_t n_height)
{
    m_width = n_width;
    m_height = n_height;
}

void Viewer::draw_square(Square s)
{
    SDL_Rect rect = {
        static_cast<int32_t>(s.x()),
        static_cast<int32_t>(s.y()),
        static_cast<int32_t>(s.w()),
        static_cast<int32_t>(s.h()),
    };
    SDL_RenderFillRect(renderer, &rect);
}

void Viewer::draw(World & world)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0xAA, 0x55, 0xFF);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (Object *o : world.objects())
    {
        assert(e_SIZE == 1);
        switch(o->type())
        {
            case e_SQUARE:
                draw_square(*static_cast<Square*>(o));
                break;
            default:
                assert(false);
        }
    }

    SDL_RenderPresent(renderer);
}