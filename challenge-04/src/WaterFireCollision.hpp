#ifndef WATERFIRECOLLISION_HPP
#define WATERFIRECOLLISION_HPP

#include "CollisionHandler.hpp"
#include <iostream>

class WaterFireCollision : public CollisionHandler {
public:
    bool collision(Sprite* c1, Sprite* c2) {
        if (c1->getType() == "Water" && c2->getType() == "Fire" ||
            c1->getType() == "Fire" && c2->getType() == "Water") {
            // Water and Fire collide
            std::cout << "Water and Fire collide!" << std::endl;
            delete c1;
            delete c2;
            return false;
        } else {
            return next->collision(c1, c2);
        }
    }
};

#endif