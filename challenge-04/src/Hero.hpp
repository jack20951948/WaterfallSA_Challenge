#ifndef HERO_HPP
#define HERO_HPP

#include "Sprite.hpp"

class Hero : public Sprite {
private:
    int hp;
public:
    Hero(int position);
    int getHp();
    void setHp(int hp);
    void takeDamage(int damage);
    void heal(int hp);
};

#endif