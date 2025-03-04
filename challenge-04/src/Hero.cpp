#include "Hero.hpp"

Hero::Hero(int position) : Sprite(position, "Hero") {
    setHp(30);
}

int Hero::getHp() {
    return hp;
}

void Hero::setHp(int hp) {
    if (hp > 0) {
        this->hp = hp;
    } else {
        throw "Hero is dead!";
    }
}

void Hero::takeDamage(int damage) {
    if (damage > 0) {
        setHp(getHp() - damage);
    }
}

void Hero::heal(int hp) {
    if (hp > 0) {
        setHp(getHp() + hp);
    }
}