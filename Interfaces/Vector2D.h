#ifndef PHY_VECTOR2_H
#define PHY_VECTOR2_H

class Vector2D {
    public:
    Vector2D() : Vector2D(0, 0) {}

    Vector2D(uint32_t x, uint32_t y)
        : m_x(x)
        , m_y(y)
    {}

    ~Vector2D() {}

    uint32_t x() { return m_x; }
    uint32_t y() { return m_y; }

    private:
    uint32_t m_x {};
    uint32_t m_y {};
};

#endif