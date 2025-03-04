#ifndef WORLD_HPP
#define WORLD_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "Sprite.hpp"


class World {
private:
    std::vector<std::shared_ptr<Sprite>> sprites;
public:
    World();
    ~World();
    void addSprite(std::shared_ptr<Sprite> sprite);
    void removeSprite(const Sprite& sprite);
    void Start();
    void printSprites();
    void run(int start, int end);

    // checkCollision(Sprite* sprite1, Sprite* sprite2, func removeSprite);
    bool checkCollision(Sprite* sprite1, Sprite* sprite2, std::function<void(Sprite)> removeSprite);
};

#endif