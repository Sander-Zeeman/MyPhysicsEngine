#ifndef PHY_WORLD_H
#define PHY_WORLD_H

#include "../Interfaces/IObserved.h"
#include "../Interfaces/Shape.h"
#include "../Interfaces/Vector2D.h"
#include "Nature.h"

#include <stdint.h>
#include <list>

class World : public IObserved {
    public:
    World() {};
    virtual ~World() {};

    Vector2D gravity(Shape *s);
    Vector2D resultantForce(Shape *s);

    void add_shape(Shape *s);
    void remove_shape(Shape *s);
    std::list<Shape*> shapes() { return m_shapes; }

    void add_observer(IObserver *o) override;
    void remove_observer(IObserver *o) override;
    void notify() override;

    private:
    uint32_t m_data { 14 };

    std::list<IObserver*> m_observers {};
    std::list<Shape*> m_shapes {};
};

#endif