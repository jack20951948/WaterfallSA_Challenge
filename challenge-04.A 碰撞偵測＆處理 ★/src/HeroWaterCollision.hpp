#ifndef HEROWATERCOLLISION_HPP
#define HEROWATERCOLLISION_HPP

#include "CollisionHandler.hpp"
#include "Hero.hpp"
#include <iostream>
#include <functional>

class HeroWaterCollision : public CollisionHandler {
public:
    HeroWaterCollision(): CollisionHandler() {}
    HeroWaterCollision(CollisionHandler* handler): CollisionHandler(handler) {}
    bool collision(Sprite* c1, Sprite* c2, std::function<void(Sprite)> removeSprite) {
        if (c1->getType() == "Hero" && c2->getType() == "Water" ||
            c1->getType() == "Water" && c2->getType() == "Hero") {
            // Hero and Water collide
            std::cout << "Hero and Water collide!" << std::endl;
            if (c1->getType() == "Hero") {
                Hero* hero = dynamic_cast<Hero*>(c1);
                if (hero) {
                    hero->heal(10);
                }
                removeSprite(*c2);
                return true;
            } else {
                Hero* hero = dynamic_cast<Hero*>(c2);
                if (hero) {
                    hero->heal(10);
                }
                removeSprite(*c1);
                return false;
            }
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