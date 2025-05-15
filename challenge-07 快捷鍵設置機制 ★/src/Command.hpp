#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
public:
    virtual void action() = 0; // Pure virtual function
    virtual void undo() = 0; // Pure virtual function for undo
    virtual ~Command() {} // Virtual destructor
};

#endif // COMMAND_HPP