#ifndef FIRE_HPP
#define FIRE_HPP

#include "Sprite.hpp"

class Fire : public Sprite {
public:
    Fire(int position) : Sprite(position, "Fire") {}
};

#endif