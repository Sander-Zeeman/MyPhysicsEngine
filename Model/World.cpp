#include "World.h"

Vector2D World::gravity(Shape *s) {
    return Vector2D(0, s->mass() * Nature::g);
}

Vector2D World::resultantForce(Shape *s) {
    return gravity(s);
}

void World::add_shape(Shape *s) {
    m_shapes.push_back(s);
    notify();
}

void World::remove_shape(Shape *s) {
    m_shapes.remove(s);
    notify();
}

void World::add_observer(IObserver *o) {
    m_observers.push_back(o);
}

void World::remove_observer(IObserver *o) {
    m_observers.remove(o);
}

void World::notify() {
    for (IObserver *o : m_observers) {
        o->update();
    }
}
