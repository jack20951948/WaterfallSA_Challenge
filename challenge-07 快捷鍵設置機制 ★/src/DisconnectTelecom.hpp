#ifndef DISCONNECTTELECOM_HPP
#define DISCONNECTTELECOM_HPP

#include "Command.hpp"
#include "Telecom.hpp"

class DisconnectTelecom : public Command {
private:
    Telecom* telecom; // Pointer to the Telecom object
public:
    DisconnectTelecom(Telecom* telecom) : telecom(telecom) {}
    void action() override {
        telecom->disconnect();
    }
};

#endif // DISCONNECTTELECOM_HPP