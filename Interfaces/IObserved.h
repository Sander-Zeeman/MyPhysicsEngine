#pragma once

#include "IObserver.h"

class IObserved {
    public:
    virtual ~IObserved() {};
    virtual void add_observer(IObserver *o) = 0;
    virtual void remove_observer(IObserver *o) = 0;
    virtual void notify() = 0;
};