#ifndef CONNECTTELECOM_HPP
#define CONNECTTELECOM_HPP

#include "Command.hpp"
#include "Telecom.hpp"

class ConnectTelecom : public Command {
private:
    Telecom* telecom; // Pointer to the Telecom object
public:
    ConnectTelecom(Telecom* telecom) : telecom(telecom) {}
    void action() override {
        telecom->connect();
    }
};

#endif // CONNECTTELECOM_HPP