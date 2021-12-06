#include "Square.h"

Square::Square(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t m) 
        : m_x(x)
        , m_y(y)
        , m_w(w)
        , m_h(h)
{
    m_mass = m;
}

bool Square::clicked(float x, float y) {
    if (x < m_x || x > m_x + m_w) return false;
    if (y < m_y || y > m_y + m_h) return false;
    return true;
}

void Square::applyForce(Vector2D force) {
    m_x += force.x();
    m_y += force.y();
}