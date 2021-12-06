#include "Brain.h"

Brain::~Brain() {}

void Brain::start() {
    while (m_running) {
        applyForces();

        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type) {
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_1)
                    m_world->add_shape(new Square(100, 100, 100, 100, 1));
                
                if (event.key.keysym.scancode == SDL_SCANCODE_2)
                    m_world->add_shape(new Square(250, 100, 100, 100, 5));
                
                if (event.key.keysym.scancode == SDL_SCANCODE_3)
                    m_world->add_shape(new Square(400, 100, 100, 100, 10));
                
                if (event.key.keysym.scancode == SDL_SCANCODE_4)
                    m_world->add_shape(new Square(650, 100, 100, 100, 20));
        }

        SDL_Delay(1000.0 / 30);
 
    }
}

void Brain::applyForces() {
    for (Shape *s : m_world->shapes()) {
        Vector2D resultantForce = m_world->resultantForce(s);
        s->applyForce(resultantForce);
    }
}