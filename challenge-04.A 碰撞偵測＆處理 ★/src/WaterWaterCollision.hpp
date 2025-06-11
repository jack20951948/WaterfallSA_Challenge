#ifndef WATERWATERCOLLISION_HPP
#define WATERWATERCOLLISION_HPP

#include "CollisionHandler.hpp"
#include <iostream>
#include <functional>

class WaterWaterCollision : public CollisionHandler {
public:
    WaterWaterCollision(): CollisionHandler() {}
    WaterWaterCollision(CollisionHandler* handler): CollisionHandler(handler) {}
    bool collision(Sprite* c1, Sprite* c2, std::function<void(Sprite)> removeSprite) {
        if (c1->getType() == "Water" && c2->getType() == "Water") {
            // Water and Water collide
            std::cout << "Water and Water collide!" << std::endl;
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