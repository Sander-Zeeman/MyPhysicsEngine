#include "Viewer.h"

Viewer::Viewer(uint32_t width, uint32_t height) 
    : m_width(width)
    , m_height(height)
{}

Viewer::~Viewer() {}

void Viewer::merge_masks(bool *buffer, const bool *mask)
{
    for (uint32_t y = 0; y < m_height; y++) {
        for (uint32_t x = 0; x < m_width; x++) {
            uint32_t i = y * m_width + x;
            buffer[i] = buffer[i] | mask[i];
        }
    }
}

void Viewer::draw_buffer(const bool *buffer)
{
    printf("\033[2J");
    for (uint32_t y = 0; y < m_height; y++)
    {
        for (uint32_t x = 0; x < m_width; x++)
        {
            putchar(buffer[y*m_width + x] ? OCCUPIED : FREE);
        }
        putchar('\n');
    }
}

void Viewer::draw(World & world) {
    bool *buffer = new bool[m_width * m_height];
    bool *final_buffer = new bool[m_width * m_height];
    for (Object *o : world.objects()) {
        o->mask(buffer, 0, 0, m_width, m_height);
        merge_masks(final_buffer, buffer);
    }
    delete [] buffer;
    
    draw_buffer(final_buffer);
    delete [] final_buffer;
}
