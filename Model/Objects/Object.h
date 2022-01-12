#pragma once

#include <stdint.h>
#include "Types.h"

class Object
{
    public:
        virtual ~Object() {}
        virtual void mask(bool *buffer, uint32_t x, uint32_t y, uint32_t w, uint32_t h) = 0;
        virtual ObjectType type() = 0;
};
