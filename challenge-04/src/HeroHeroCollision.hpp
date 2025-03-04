#ifndef HEROHEROCOLLISION_HPP
#define HEROHEROCOLLISION_HPP

#include "CollisionHandler.hpp"
#include <iostream>
#include <functional>

class HeroHeroCollision : public CollisionHandler {
public:
    HeroHeroCollision(): CollisionHandler() {}
    HeroHeroCollision(CollisionHandler* handler): CollisionHandler(handler) {}
    bool collision(Sprite* c1, Sprite* c2, std::function<void(Sprite)> removeSprite) {
        if (c1->getType() == "Hero" && c2->getType() == "Hero") {
            // Hero and Hero collide
            std::cout << "Hero and Hero collide!" << std::endl;
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