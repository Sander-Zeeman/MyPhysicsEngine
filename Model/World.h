#pragma once

#include "Square.h"
#include <vector>

class World
{
    public:
        World();
        ~World();

        void update_square(Square *s);
        void update();
        
        std::vector<Object*> objects() { return m_objects; };

    private:
        std::vector<Object*> m_objects;
};
