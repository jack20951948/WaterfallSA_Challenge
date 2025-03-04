#include "World.hpp"
#include "Hero.hpp"
#include "Water.hpp"
#include "Fire.hpp"

World::World() {
    auto hero1 = std::make_shared<Hero>(0);
    auto hero2 = std::make_shared<Hero>(4);
    auto hero3 = std::make_shared<Hero>(20);
    auto hero4 = std::make_shared<Hero>(29);
    auto water1 = std::make_shared<Water>(7);
    auto water2 = std::make_shared<Water>(3);
    auto water3 = std::make_shared<Water>(15);
    auto fire1 = std::make_shared<Fire>(22);
    auto fire2 = std::make_shared<Fire>(13);
    auto fire3 = std::make_shared<Fire>(19);

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

void World::addSprite(std::shared_ptr<Sprite> sprite) {
    // Check if the sprite's position is already occupied
    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i]->getPosition() == sprite->getPosition()) {
            throw "Position already occupied!";
        }
    }
    sprites.push_back(sprite);
}

void World::removeSprite(const Sprite& sprite) {
    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i]->getPosition() == sprite.getPosition()) {
            sprites.erase(sprites.begin() + i);
        }
    }
}

bool World::checkCollision(Sprite* sprite1, Sprite* sprite2, std::function<void(Sprite)> removeSprite) {
    return sprite1->collision(sprite2, removeSprite);
}

void World::printSprites() {
    for (int i = 0; i < sprites.size(); i++) {
        std::cout << sprites[i] << " Sprite type: " << sprites[i]->getType() << " at position: " << sprites[i]->getPosition();
        if (sprites[i]->getType() == "Hero") {
            Hero* hero = dynamic_cast<Hero*>(sprites[i].get());
            std::cout << " HP: " << hero->getHp();
        }
        std::cout << std::endl;
    }
}

World::~World() {
    sprites.clear();
}

void World::run(int start, int end) {
    for (int i = 0; i < sprites.size(); i++) {
        if (sprites[i]->getPosition() == start) {
            std::cout << "Sprite type: " << sprites[i]->getType() << " at position: " << sprites[i]->getPosition() << std::endl;
            for (int j = 0; j < sprites.size(); j++) {
                if (sprites[j]->getPosition() == end) {
                    std::cout << "Sprite type: " << sprites[j]->getType() << " at position: " << sprites[j]->getPosition() << std::endl;
                    try {
                        if (checkCollision(sprites[i].get(), sprites[j].get(), std::bind(&World::removeSprite, this, std::placeholders::_1))) {
                            sprites[i]->setPosition(end);
                        }
                    } catch (const char* msg) {
                        std::cerr << msg << std::endl;
                        return;
                    }
                    return;
                }
            }
            sprites[i]->setPosition(end);
            return;
        }
    }
}

void World::Start() {
    while (true) {
        printSprites();
    
        int start, end;
        while (true) {
            std::cout << "\nEnter two numbers to move (0-29): ";
            std::cin >> start >> end;
            if (start >= 0 && start <= 29 && end >= 0 && end <= 29) {
                break;
            } else {
                std::cerr << "Invalid move! Please enter numbers between 0 and 29." << std::endl;
            }
        }
    
        run(start, end);
        std::cout << "============================" << std::endl;
    }
}