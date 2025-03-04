#ifndef COLLISIONHANDLER_HPP
#define COLLISIONHANDLER_HPP

#include "Sprite.hpp"

class CollisionHandler {
protected:
    CollisionHandler* next;
public:
    virtual bool collision(Sprite* c1, Sprite* c2) = 0;
};

#endif