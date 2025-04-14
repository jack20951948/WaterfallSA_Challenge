#ifndef CARDPATTERNCOMPAREDHANDLER_HPP
#define CARDPATTERNCOMPAREDHANDLER_HPP

#include <iostream>
#include <vector>
#include "Card.hpp"
#include "CardPattern.hpp"

class CardPatternComparedHandler
{
protected:
    CardPatternComparedHandler* nextHandler; // Pointer to the next handler in the chain
public:
    CardPatternComparedHandler() : nextHandler(nullptr) {} // Constructor to initialize the next handler to nullptr
    CardPatternComparedHandler(CardPatternComparedHandler* handler) : nextHandler(handler) {} // Constructor to set the next handler
    ~CardPatternComparedHandler() {
        if (nextHandler) {
            delete nextHandler; // Clean up the next handler if it exists
        }
    } // Virtual destructor for proper cleanup of derived classes
    virtual bool isFrontGreater(const std::vector<Card>& cards1, const std::vector<Card>& cards2, CardPattern pattern) = 0;
};

#endif // CARDPATTERNCOMPAREDHANDLER_HPP