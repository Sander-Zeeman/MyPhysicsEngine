#define FPS 2
#define TPF 1000.0f / FPS

#ifndef CMD_VIEW
    #define CMD_VIEW 1
#endif

#include <SDL2/SDL.h>

#include "Model/World.h"
#include "View/CMD/Viewer.h"

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        SDL_Log("Unable to initialize SDL (CMD_VIEW: %s): %s",
                CMD_VIEW ? "enabled" : "disabled",
                SDL_GetError());
        return 1;
    }

    World *world = new World();
    Viewer *viewer = new Viewer();

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
            }
        }

        world->update();
        viewer->draw(*world);

        uint32_t delta = SDL_GetTicks() - start;
        if (delta < TPF)
            SDL_Delay(TPF - delta);
    }

    SDL_Quit();

    delete viewer;
    delete world;

    return 0;
}