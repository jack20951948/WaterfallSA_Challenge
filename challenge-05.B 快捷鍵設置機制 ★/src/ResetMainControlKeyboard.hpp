#ifndef RESETMAINCONTROLKEYBOARD_HPP
#define RESETMAINCONTROLKEYBOARD_HPP

#include "Command.hpp"
#include "MainController.hpp"

class ResetMainControlKeyboard : public Command {
private:
    MainController* mainController; // Pointer to the MainController object
public:
    ResetMainControlKeyboard(MainController* mainController) : mainController(mainController) {}
    void action() override {
        mainController->reset_commands();
    }
    void undo() override {
        // No undo action for reset
    }
};

#endif // RESETMAINCONTROLKEYBOARD_HPP