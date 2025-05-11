#ifndef TANK_HPP
#define TANK_HPP

#include <iostream>

class Tank {
public:
    void move_forward() {
        std::cout << "The tank has moved forward." << std::endl;
    };
    void move_backward() {
        std::cout << "The tank has moved backward." << std::endl;
    };
};

#endif // TANK_HPP