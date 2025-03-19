#ifndef WATER_HPP
#define WATER_HPP

#include "Sprite.hpp"

class Water : public Sprite {
public:
    Water(int position) : Sprite(position, "Water") {}
};

#endif