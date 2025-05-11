#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <iostream>
#include <vector>
#include <map>
#include "Command.hpp"

class MainController {
public:
    MainController();
    void reset_commands();
    void undo();
    void redo();
    void exec_command(char key);
    void add_command(char key, Command* command);
    void show_commands();
    void set_macro(char key, std::vector<Command*> commands);
};
#endif // MAINCONTROLLER_HPP