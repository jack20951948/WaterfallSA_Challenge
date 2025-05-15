#include "MainController.hpp"
#include "Command.hpp"

MainController::MainController() {}

MainController::~MainController() {
    for (auto& pair : command_map) {
        for (auto& command : pair.second) {
            delete command; // Clean up dynamically allocated commands
        }
    }
    command_map.clear(); // Clear the command map
    s1.clear(); // Clear the undo stack
    s2.clear(); // Clear the redo stack
}

void MainController::reset_commands() {
    command_map.clear();
}

void MainController::undo() {
    if (s1.empty()) {
        std::cout << "No command to undo." << std::endl;
        return;
    }
    std::vector<Command*> commands = s1.back();
    s1.pop_back();
    // pop every command from the vector's back and call undo
    std::vector<Command*> commands2;
    while (!commands.empty()) {
        Command* command = commands.back();
        commands.pop_back();
        command->undo(); // Undo the command
        commands2.push_back(command); // Store the command for redo
    }
    s2.push_back(commands2); // Push to redo stack
}

void MainController::redo() {
    if (s2.empty()) {
        std::cout << "No command to redo." << std::endl;
        return;
    }
    std::vector<Command*> commands = s2.back();
    s2.pop_back();
    std::vector<Command*> commands2;
    while (!commands.empty()) {
        Command* command = commands.back();
        commands.pop_back();
        command->action(); // Execute the command
        commands2.push_back(command); // Store the command for undo
    }
    s1.push_back(commands); // Push to undo stack
}

void MainController::exec_command(char key) {
    auto it = command_map.find(key);
    if (it != command_map.end()) {
        std::vector<Command*> commands = it->second;
        for (auto& command : commands) {
            command->action(); // Execute the command
        }
        s1.push_back(commands); // Push to undo stack
        s2.clear(); // Clear redo stack
    } else {
        std::cout << "Command not found." << std::endl;
    }
}

void MainController::add_command(char key, std::vector<Command*> commands) {
    command_map[key] = commands; // Add command to the map
}

void MainController::show_commands() {
    for (const auto& commands : command_map) {
        std::cout << commands.first << ": ";
        for (int i = 0; i < commands.second.size(); ++i) {
            if (i != 0) {
                std::cout << " & ";
            }
            std::cout << typeid(*commands.second[i]).name(); // Show command type
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}