#ifndef CARDPATTERNHANDLER_HPP
#define CARDPATTERNHANDLER_HPP

#include <iostream>
#include <vector>

#include "Card.hpp"
#include "CardPattern.hpp"

using namespace std;
class CardPatternHandler {
protected:
    CardPatternHandler * nextHandler; // Pointer to the next handler in the chain
public:
    CardPatternHandler() : nextHandler(nullptr) {} // Constructor to initialize the next handler to nullptr
    CardPatternHandler(CardPatternHandler * handler) : nextHandler(handler) {} // Constructor to set the next handler
    virtual CardPattern isValidPattern(const vector<Card>& cards) = 0; // Pure virtual function to check if the pattern is valid
};

#endif // CARDPATTERNHANDLER_HPP