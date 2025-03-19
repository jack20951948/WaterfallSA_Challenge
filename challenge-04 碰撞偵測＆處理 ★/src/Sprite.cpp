#include "Sprite.hpp"
#include "WaterFireCollision.hpp"
#include "WaterWaterCollision.hpp"
#include "FireFireCollision.hpp"
#include "HeroHeroCollision.hpp"
#include "HeroFireCollision.hpp"
#include "HeroWaterCollision.hpp"

Sprite::Sprite(int position, std::string type) {
    this->type = type;
    setPosition(position);
}

int Sprite::getPosition () const {
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
    CollisionHandler* handler = new WaterFireCollision(new WaterWaterCollision(new FireFireCollision(new HeroHeroCollision(new HeroFireCollision(new HeroWaterCollision())))));
    return handler->collision(this, sprite, removeSprite);
}