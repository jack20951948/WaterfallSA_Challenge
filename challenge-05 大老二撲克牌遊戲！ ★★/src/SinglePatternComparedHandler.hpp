#ifndef SINGLEPATTERNCOMPAREDHANDLER_HPP
#define SINGLEPATTERNCOMPAREDHANDLER_HPP

#include "CardPatternComparedHandler.hpp"

class SinglePatternComparedHandler : public CardPatternComparedHandler
{
public:
    SinglePatternComparedHandler() : CardPatternComparedHandler() {}
    SinglePatternComparedHandler(CardPatternComparedHandler* handler) : CardPatternComparedHandler(handler) {}
    bool isFrontGreater(const std::vector<Card>& cards1, const std::vector<Card>& cards2, CardPattern pattern) override {
        if (pattern != CardPattern::SINGLE) {
            return nextHandler ? nextHandler->isFrontGreater(cards1, cards2, pattern) : false;
        }

        if (cards1.size() != 1 || cards2.size() != 1) {
            throw std::invalid_argument("Both card sets must contain exactly one card.");
        }
        if (cards1[0].getRank() == cards2[0].getRank()) {
            return cards1[0].getSuit() > cards2[0].getSuit(); // Compare suits if ranks are equal
        }
        return cards1[0].getRank() > cards2[0].getRank(); // Compare ranks
    }
};

#endif // SINGLEPATTERNCOMPAREDHANDLER_HPP