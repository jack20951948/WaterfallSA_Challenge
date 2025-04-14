#ifndef STRAIGHTPATTERNCOMPAREDHANDLER_HPP
#define STRAIGHTPATTERNCOMPAREDHANDLER_HPP

#include "CardPatternComparedHandler.hpp"

class StraightPatternComparedHandler : public CardPatternComparedHandler
{
public:
    StraightPatternComparedHandler() : CardPatternComparedHandler() {}
    StraightPatternComparedHandler(CardPatternComparedHandler* handler) : CardPatternComparedHandler(handler) {}
    bool isFrontGreater(const std::vector<Card>& cards1, const std::vector<Card>& cards2, CardPattern pattern) override {
        if (pattern != CardPattern::STRAIGHT) {
            return nextHandler ? nextHandler->isFrontGreater(cards1, cards2, pattern) : false;
        }
        // compare the biggest card of the straight
        if (cards1.size() != 5 || cards2.size() != 5) {
            throw std::invalid_argument("Both card sets must contain exactly five cards.");
        }
        // Sort the cards based on rank
        std::vector<Card> sortedCards1 = cards1;
        std::vector<Card> sortedCards2 = cards2;
        std::sort(sortedCards1.begin(), sortedCards1.end(), [](const Card& a, const Card& b) {
            return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
        });
        std::sort(sortedCards2.begin(), sortedCards2.end(), [](const Card& a, const Card& b) {
            return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
        });
        // Compare the highest card of each straight
        return sortedCards1.back().getRank() > sortedCards2.back().getRank();
    }
};

#endif // STRAIGHTPATTERNCOMPAREDHANDLER_HPP