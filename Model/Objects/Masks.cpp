#include "Square.h"
#include <cstring>
#include <cstdio>
void Square::mask(bool *buffer, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
    uint32_t x_start = x > m_x ? x : m_x;
    uint32_t y_start = y > m_y ? y : m_y;
    uint32_t x_end = x + w < m_x + m_w ? x + w : m_x + m_w;
    uint32_t y_end = y + h < m_y + m_h ? y + h : m_y + m_h;

    memset(buffer, false, (w-x) * (h-y));
    for (uint32_t y_i = y_start; y_i < y_end; y_i++)
        for (uint32_t x_i = x_start; x_i < x_end; x_i++)
            buffer[y_i*w + x_i] = true;
}
