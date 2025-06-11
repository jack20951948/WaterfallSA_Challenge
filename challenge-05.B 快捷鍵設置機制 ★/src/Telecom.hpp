#ifndef TELECOM_HPP
#define TELECOM_HPP

#include <iostream>

class Telecom {
public:
    void connect() {
        std::cout << "The telecom has been turned on." << std::endl;
    }

    void disconnect() {
        std::cout << "The telecom has been turned off." << std::endl;
    }
};

#endif // TELECOM_HPP