#ifndef MOVETANKBACKWARD_HPP
#define MOVETANKBACKWARD_HPP

#include "Command.hpp"
#include "Tank.hpp"

class MoveTankBackward : public Command {
private:
    Tank* tank; // Pointer to the Tank object
public:
    MoveTankBackward(Tank* tank) : tank(tank) {}
    void action() override {
        tank->move_backward();
    }
    void undo() override {
        tank->move_forward();
    }
};

#endif // MOVETANKBACKWARD_HPP