#ifndef PHY_SQUARE_H
#define PHY_SQUARE_H

#include "../../Interfaces/Shape.h"

class Square : public Shape {
    public:
    Square(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t m);
    virtual ~Square() {};

    uint32_t x() { return m_x; }
    uint32_t y() { return m_y; }
    uint32_t w() { return m_w; }
    uint32_t h() { return m_h; }

    bool clicked(float x, float y) override;
    std::string shape() override { return "Square"; }
    void applyForce(Vector2D force) override;

    private:
    uint32_t m_x { 0 };
    uint32_t m_y { 0 };
    uint32_t m_w { 0 };
    uint32_t m_h { 0 };
};

#endif