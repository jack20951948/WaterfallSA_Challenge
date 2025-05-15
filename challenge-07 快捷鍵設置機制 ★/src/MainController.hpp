#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP

#include <iostream>
#include <vector>
#include <map>
#include "Command.hpp"

class MainController {
private:
    std::map<char, std::vector<Command*>> command_map; // Map to store commands
    std::vector<std::vector<Command*>> s1; // Stack for undo/redo
    std::vector<std::vector<Command*>> s2; // Stack for redo

public:
    MainController();
    ~MainController(); // Destructor to clean up commands
    void reset_commands();
    void undo();
    void redo();
    void exec_command(char key);
    void add_command(char key, std::vector<Command*> command);
    void show_commands();
};
#endif // MAINCONTROLLER_HPP