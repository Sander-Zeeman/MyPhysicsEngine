#pragma once

#include <cstdio>
#include "World.h"

#define OCCUPIED '#'
#define FREE ' '

class Viewer
{
    public:
        Viewer(uint32_t width, uint32_t height);
        ~Viewer();

        void draw(World & world);

    private:
        void merge_masks(bool *buffer, const bool *mask);
        void draw_buffer(const bool *buffer);

        uint32_t m_width { 0 };
        uint32_t m_height { 0 };
};
