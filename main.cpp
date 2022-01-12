#define FPS 10.0f
#define TPF 1000.0f / FPS

#define SDL_VIEW

#ifdef CMD_VIEW

#include "View/CMD/Viewer.h"

#else

#ifdef SDL_VIEW
#include "View/SDL/Viewer.h"
#endif

#endif


#include <SDL2/SDL.h>

#include "Model/World.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s",
                SDL_GetError());
        return 1;
    }

    World *world = new World();
    Viewer *viewer = new Viewer(640, 480);

    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        uint32_t start = SDL_GetTicks();

        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                #ifdef SDL_VIEW
                case SDL_WINDOWEVENT:
                    if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                    {
                        viewer->resize(e.window.data1, e.window.data2);
                    }
                #endif
                default:
                    break;
            }
        }

        world->update();
        viewer->draw(*world);

        uint32_t delta = SDL_GetTicks() - start;
        if (delta < TPF)
            SDL_Delay(TPF - delta);
    }

    delete viewer;
    delete world;
    SDL_Quit();

    return 0;
}
