#ifndef WATERFIRECOLLISION_HPP
#define WATERFIRECOLLISION_HPP

#include "CollisionHandler.hpp"
#include <iostream>
#include <functional>

class WaterFireCollision : public CollisionHandler {
public:
    bool collision(Sprite* c1, Sprite* c2, std::function<void(Sprite)> removeSprite) {
        if (c1->getType() == "Water" && c2->getType() == "Fire" ||
            c1->getType() == "Fire" && c2->getType() == "Water") {
            // Water and Fire collide
            std::cout << "Water and Fire collide!" << std::endl;
            removeSprite(*c1);
            removeSprite(*c2);
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