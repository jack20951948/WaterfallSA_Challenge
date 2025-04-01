#ifndef FULLHOUSEPATTERNHANDLER_HPP
#define FULLHOUSEPATTERNHANDLER_HPP

#include "CardPatternHandler.hpp"

class FullHousePatternHandler : public CardPatternHandler {
public:
    FullHousePatternHandler() : CardPatternHandler() {}
    FullHousePatternHandler(CardPatternHandler* handler) : CardPatternHandler(handler) {}
    CardPattern isValidPattern(const vector<Card>& cards) override;
};

#endif // FULLHOUSEPATTERNHANDLER_HPP