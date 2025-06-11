#ifndef MOVETANKFORWARD_HPP
#define MOVETANKFORWARD_HPP

#include "Command.hpp"
#include "Tank.hpp"

class MoveTankForward : public Command {
private:
    Tank* tank; // Pointer to the Tank object
public:
    MoveTankForward(Tank* tank) : tank(tank) {}
    void action() override {
        tank->move_forward();
    }
    void undo() override {
        tank->move_backward();
    }
};

#endif // MOVETANKFORWARD_HPP