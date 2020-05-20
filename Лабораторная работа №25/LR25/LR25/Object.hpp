#pragma once
#include "Event.hpp"

class Object
{
public:
    Object(void);
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual ~Object(void);
    virtual void HandEvent(const TEvent& e) = 0;
};
