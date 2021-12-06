#pragma once

#include "../Model/Shapes/Square.h"
#include "../Model/World.h"
#include "../View/Screen.h"
#include "../Interfaces/Vector2D.h"

class Brain {
    public:
    Brain(World *world, Screen *screen)
        : m_world(world)
        , m_screen(screen)
    {}

    ~Brain();

    // Forces
    void applyForces();

    // Input


    // Brain
    void start();

    private:
    bool m_running { true };

    World *m_world {};
    Screen *m_screen {};
};