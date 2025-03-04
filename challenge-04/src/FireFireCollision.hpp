#ifndef FIREFIRECOLLISION_HPP
#define FIREFIRECOLLISION_HPP

#include "CollisionHandler.hpp"
#include <iostream>
#include <functional>

class FireFireCollision : public CollisionHandler {
public:
    FireFireCollision(): CollisionHandler() {}
    FireFireCollision(CollisionHandler* handler): CollisionHandler(handler) {}
    bool collision(Sprite* c1, Sprite* c2, std::function<void(Sprite)> removeSprite) {
        if (c1->getType() == "Fire" && c2->getType() == "Fire") {
            // Fire and Fire collide
            std::cout << "Fire and Fire collide!" << std::endl;
            return false;
        } else {
            if (next != nullptr) {
                return next->collision(c1, c2, removeSprite);
            } else {
                throw "Unsupported Collision!";
            }
        }
    }
};

#endif