#include "Sprite.hpp"

Sprite::Sprite(int position, std::string type) {
    this->type = type;
    setPosition(position);
}

int Sprite::getPosition() {
    return position;
}

std::string Sprite::getType() {
    return type;
}

void Sprite::setPosition(int position) {

    if (position >= 0 && position <= 29) {
        this->position = position;
    } else {
        throw "Position must be between 0 and 29";
    }
}

bool Sprite::collision(Sprite* sprite, std::function<void(Sprite)> removeSprite) {
    return collisionHandler->collision(this, sprite, removeSprite);
}