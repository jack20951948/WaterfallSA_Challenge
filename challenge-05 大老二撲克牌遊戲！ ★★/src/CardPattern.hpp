#ifndef CARDPATTERN_HPP
#define CARDPATTERN_HPP

#include <iostream>
#include <vector>
#include "Card.hpp"

using namespace std;
class CardPattern
{
protected:
    CardPattern* nextHandler; // Pointer to the next handler in the chain
    string patternName; // Name of the card pattern
public:
    CardPattern() : nextHandler(nullptr) {} // Constructor to initialize the next handler to nullptr
    CardPattern(CardPattern* handler) : nextHandler(handler) {} // Constructor to set the next handler
    string getPatternName() const { return patternName; } // Getter for the pattern name
    virtual CardPattern* isValidPattern(const vector<Card>& cards) = 0; // Pure virtual function to check if the pattern is valid
    virtual bool isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) = 0; // Pure virtual function to compare card patterns
};

#endif // CARDPATTERN_HPP