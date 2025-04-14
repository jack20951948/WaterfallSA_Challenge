#ifndef PAIRPATTERNCOMPAREDHANDLER_HPP
#define PAIRPATTERNCOMPAREDHANDLER_HPP

#include "CardPatternComparedHandler.hpp"

class PairPatternComparedHandler : public CardPatternComparedHandler
{
public:
    PairPatternComparedHandler() : CardPatternComparedHandler() {}
    PairPatternComparedHandler(CardPatternComparedHandler* handler) : CardPatternComparedHandler(handler) {}
    bool isFrontGreater(const std::vector<Card>& cards1, const std::vector<Card>& cards2, CardPattern pattern) override {
        if (pattern != CardPattern::PAIR) {
            return nextHandler ? nextHandler->isFrontGreater(cards1, cards2, pattern) : false;
        }
        if (cards1.size() != 2 || cards2.size() != 2) {
            throw std::invalid_argument("Both card sets must contain exactly two cards.");
        }
        return cards1[0].getRank() > cards2[0].getRank();
    }
};

#endif // PAIRPATTERNCOMPAREDHANDLER_HPP