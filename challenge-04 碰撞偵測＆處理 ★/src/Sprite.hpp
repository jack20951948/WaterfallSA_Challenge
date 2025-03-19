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
    virtual ~Sprite() {} // Add a virtual destructor to make it polymorphic, which allows dynamic_cast to work correctly.
    int getPosition() const;
    std::string getType();
    void setPosition(int position);
    bool collision(Sprite* sprite, std::function<void(Sprite)> removeSprite);
};

#endif