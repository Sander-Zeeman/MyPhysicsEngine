#pragma once

#include "Object.h"

class Square : public Object
{
    public:
        Square(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
            : m_x(x)
            , m_y(y)
            , m_w(w)
            , m_h(h) {}
        ~Square() {}

        void mask(bool *buffer, uint32_t x, uint32_t y, uint32_t w, uint32_t h);
        ObjectType type() { return e_SQUARE; };

        void set_x(uint32_t n_x) { m_x = n_x; }
        void set_y(uint32_t n_y) { m_y = n_y; }

        uint32_t x() { return m_x; }
        uint32_t y() { return m_y; }
        uint32_t w() { return m_w; }
        uint32_t h() { return m_h; }
    private:
        uint32_t m_x { 0 };
        uint32_t m_y { 0 };
        uint32_t m_w { 0 };
        uint32_t m_h { 0 };    
};
