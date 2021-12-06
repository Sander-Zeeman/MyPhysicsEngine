#ifndef PHY_SCREEN_H
#define PHY_SCREEN_H

#include <SDL.h>
#include <stdint.h>
#include<iostream>
#include "ShapeRenderer.h"
#include "../Model/World.h"
#include "../Interfaces/IObserver.h"

class Screen : public IObserver {
    public:
        Screen();
        Screen(const char title[]);
        Screen(const char title[], uint32_t width, uint32_t height);

	    virtual ~Screen();

        uint32_t width() { return m_width; }
        uint32_t height() { return m_height; }

        void setWorld(World *w);

        void render();
        void update() override;

    private:
        void initialize_window(const char title[]);

    private:
        uint32_t m_width { 640 };
        uint32_t m_height { 480 };
        uint32_t m_resolution { 1 };

        World *m_world {};
        SDL_Window *m_window {};
        ShapeRenderer *m_shapeRenderer {};
};

#endif
