#ifndef COLLISIONHANDLER_HPP
#define COLLISIONHANDLER_HPP

class Sprite;

class CollisionHandler {
protected:
    CollisionHandler* next = nullptr;
public:
    virtual bool collision(Sprite* c1, Sprite* c2, std::function<void(Sprite)> removeSprite) = 0;
    CollisionHandler() : next(nullptr) {}
    CollisionHandler(CollisionHandler* handler) : next(handler) {}
};

#endif