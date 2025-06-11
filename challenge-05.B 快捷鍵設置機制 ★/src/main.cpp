#include <iostream>
#include <vector>
#include "MainController.hpp"
#include "Tank.hpp"
#include "Telecom.hpp"
#include "ResetMainControlKeyboard.hpp"
#include "MoveTankForward.hpp"
#include "MoveTankBackward.hpp"
#include "ConnectTelecom.hpp"
#include "DisconnectTelecom.hpp"

void show_commands() {
    std::cout << "(0) MoveTankForward" << std::endl;
    std::cout << "(1) MoveTankBackward" << std::endl;
    std::cout << "(2) ConnectTelecom" << std::endl;
    std::cout << "(3) DisconnectTelecom" << std::endl;
    std::cout << "(4) ResetMainControlKeyboard" << std::endl;
}

Command* getCommand(int index, Tank* tank, Telecom* telecom) {
    switch (index) {
        case 0:
            return new MoveTankForward(tank);
        case 1:
            return new MoveTankBackward(tank);
        case 2:
            return new ConnectTelecom(telecom);
        case 3:
            return new DisconnectTelecom(telecom);
        case 4:
            return new ResetMainControlKeyboard(nullptr); // No action needed for reset
        default:
            std::cout << "Invalid command index." << std::endl;
            return nullptr;
    }
}

int main() {
    MainController mainController;
    Tank tank;
    Telecom telecom;

    while (true) {
        mainController.show_commands();
        std::cout << "(1) 快捷鍵設置 (2) Undo (3) Redo (字母) 按下按鍵:";
        char command;
        std::cin >> command;
        if (command == '1') {
            std::cout << "設置巨集指令 (y/n)：";
            char isMacro;
            std::cin >> isMacro;
            std::cout << "Key: ";
            char key;
            std::cin >> key;
            if (isMacro == 'y') {
                std::cout << "要將哪些指令設置成快捷鍵 a 的巨集（輸入多個數字，以空白隔開）:" << std::endl;
                show_commands();
                std::vector<Command*> macroCommands;
                int index;
                while (std::cin >> index && std::cin.peek() != '\n') {
                    if (index < 0 || index >= 5) {
                        std::cout << "Invalid index." << std::endl;
                        break;
                    }
                    Command* command = getCommand(index, &tank, &telecom);
                    macroCommands.push_back(command);
                }
                Command* command = getCommand(index, &tank, &telecom);
                macroCommands.push_back(command); // Add reset command to macro
                mainController.add_command(key, macroCommands);
            } else {
                std::cout << "要將哪一道指令設置到快捷鍵 " << key << " 上:" << std::endl;
                show_commands();
                int index;
                std::cin >> index;
                if (index < 0 || index >= 5) {
                    std::cout << "Invalid index." << std::endl;
                    continue;
                }
                std::vector<Command*> commands;
                Command* command = getCommand(index, &tank, &telecom);
                commands.push_back(command);
                mainController.add_command(key, commands);
            }
        } else if (command == '2') {
            mainController.undo();
        } else if (command == '3') {
            mainController.redo();
        } else {
            mainController.exec_command(command);
        }
    }
    return 0;
}