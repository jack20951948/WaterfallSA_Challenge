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
    return sprite1->collision(sprite2, removeSprite);
}

void World::printSprites() {
    for (int i = 0; i < sprites.size(); i++) {
        std::cout << "Sprite type: " << sprites[i].getType() << " at position: " << sprites[i].getPosition() << std::endl;
    }
}

World::~World() {
    sprites.clear();
}

void World::run(int start, int end) {
    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i].getPosition() == start) {
            std::cout << "Sprite type: " << sprites[i].getType() << " at position: " << sprites[i].getPosition() << std::endl;
            for (int j = 0; j < sprites.size(); j++) {
                if (sprites[j].getPosition() == end) {
                    std::cout << "Sprite type: " << sprites[j].getType() << " at position: " << sprites[j].getPosition() << std::endl;
                    try {
                        if (checkCollision(&sprites[i], &sprites[j], std::bind(&World::removeSprite, this, std::placeholders::_1))) {
                            sprites[i].setPosition(end);
                        }
                    } catch (const char* msg) {
                        std::cerr << msg << std::endl;
                        return;
                    }
                    break;
                }
            }
            sprites[i].setPosition(end);
            break;
        }
    }
}

void World::Start() {
    while (true) {
        printSprites();
    
        int start, end;
        std::cout << "Enter two number to move (0-29)";
        std::cin >> start >> end;
        if (start < 0 || start > 29 || end < 0 || end > 29) {
            std::cerr << "Invalid move!" << std::endl;
            return;
        }
    
        std::cout << start << " " << end << std::endl;
    
        run(start, end);
        std::cout << "============================" << std::endl;
    }
}