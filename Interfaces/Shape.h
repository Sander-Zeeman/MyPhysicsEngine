#pragma once

#include <string>
#include "Vector2D.h"

class Shape {
    public:
    virtual ~Shape() {};

    virtual bool clicked(float x, float y) = 0;
    virtual std::string shape() = 0;
    uint32_t mass() { return m_mass; }

    virtual void applyForce(Vector2D force) = 0;

    protected:
    uint32_t m_mass { 0 };
};