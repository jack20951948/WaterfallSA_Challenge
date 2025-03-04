#include "World.hpp"
#include "Hero.hpp"
#include "Water.hpp"
#include "Fire.hpp"

World::World() {
    Hero hero1(0);
    Hero hero2(4);
    Hero hero3(20);
    Hero hero4(29);
    Water water1(7);
    Water water2(3);
    Water water3(15);
    Fire fire1(22);
    Fire fire2(13);
    Fire fire3(19);

    try {
        addSprite(hero1);
        addSprite(hero2);
        addSprite(hero3);
        addSprite(hero4);
        addSprite(water1);
        addSprite(water2);
        addSprite(water3);
        addSprite(fire1);
        addSprite(fire2);
        addSprite(fire3);
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
        exit(1);
    }
    
}

void World::addSprite(Sprite sprite) {
    // Check if the sprite's position is already occupied
    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i].getPosition() == sprite.getPosition()) {
            throw "Position already occupied!";
        }
    }
    sprites.push_back(sprite);
}

void World::removeSprite(Sprite sprite) {
    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i].getPosition() == sprite.getPosition()) {
            sprites.erase(sprites.begin() + i);
        }
    }
}

bool World::checkCollision(Sprite* sprite1, Sprite* sprite2, std::function<void(Sprite)> removeSprite) {
    if (sprite1->collision(sprite2)) {
        removeSprite(*sprite1);
        removeSprite(*sprite2);
        return true;
    }
    return false;
}

void World::printSprites() {
    for (int i = 0; i < sprites.size(); i++) {
        std::cout << "Sprite type: " << sprites[i].getType() << " at position: " << sprites[i].getPosition() << std::endl;
    }
}

World::~World() {
    sprites.clear();
}

void World::Start() {
    printSprites();

    
}