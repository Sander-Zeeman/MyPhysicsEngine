#include "World.h"
#include "Objects/Square.h"

World::World() {
    m_objects.push_back(new Square(3,6,6,6));
    m_objects.push_back(new Square(3,120,40,50));
}

World::~World() {
    for (Object *o : m_objects)
        delete o;
}

void World::update_square(Square *s)
{
    s->set_x(s->x() + 50);
}

void World::update() {
    for (Object *o : m_objects)
    {
        assert(e_SIZE == 1);
        switch(o->type())
        {
            case e_SQUARE:
                update_square(static_cast<Square*>(o));
                break;
            default:
                assert(false);
        }
    }
}
