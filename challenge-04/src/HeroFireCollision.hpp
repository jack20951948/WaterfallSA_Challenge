#ifndef HEROFIRECOLLISION_HPP
#define HEROFIRECOLLISION_HPP

#include "CollisionHandler.hpp"
#include "Hero.hpp"
#include <iostream>
#include <functional>

class HeroFireCollision : public CollisionHandler {
public:
    HeroFireCollision(): CollisionHandler() {}
    HeroFireCollision(CollisionHandler* handler): CollisionHandler(handler) {}
    bool collision(Sprite* c1, Sprite* c2, std::function<void(Sprite)> removeSprite) {
        if (c1->getType() == "Hero" && c2->getType() == "Fire" ||
            c1->getType() == "Fire" && c2->getType() == "Hero") {
            // Hero and Fire collide
            std::cout << "Hero and Fire collide!" << std::endl;
            if (c1->getType() == "Hero") {
                Hero* hero = dynamic_cast<Hero*>(c1);
                if (hero) {
                    try {
                        hero->takeDamage(10);
                    } catch (const char* msg) {
                        std::cerr << msg << std::endl;
                        std::cout << c1 << std::endl;
                        removeSprite(*c1);
                        removeSprite(*c2);
                        return false;
                    }
                }
                removeSprite(*c2);
                return true;
            } else {
                Hero* hero = dynamic_cast<Hero*>(c2);
                if (hero) {
                    try {
                        hero->takeDamage(10);
                    } catch (const char* msg) {
                        std::cerr << msg << std::endl;
                        removeSprite(*c2);
                    }
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