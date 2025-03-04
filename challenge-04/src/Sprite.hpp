#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include <functional>
#include "CollisionHandler.hpp"

class Sprite {
private:
    int position;
    std::string type;
public:
    Sprite(int position, std::string type);
    int getPosition();
    std::string getType();
    void setPosition(int position);
    bool collision(Sprite* sprite, std::function<void(Sprite)> removeSprite);
};

#endif