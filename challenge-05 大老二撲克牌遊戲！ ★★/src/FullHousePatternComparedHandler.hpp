#ifndef FULLHOUSEPATTERNCOMPAREDHANDLER_HPP
#define FULLHOUSEPATTERNCOMPAREDHANDLER_HPP

#include "CardPatternComparedHandler.hpp"
#include <map>

class FullHousePatternComparedHandler : public CardPatternComparedHandler
{
public:
    FullHousePatternComparedHandler() : CardPatternComparedHandler() {}
    FullHousePatternComparedHandler(CardPatternComparedHandler* handler) : CardPatternComparedHandler(handler) {}
    bool isFrontGreater(const std::vector<Card>& cards1, const std::vector<Card>& cards2, CardPattern pattern) override {
        if (pattern != CardPattern::FULL_HOUSE) {
            return nextHandler ? nextHandler->isFrontGreater(cards1, cards2, pattern) : false;
        }
        // compare the biggest card of the full house
        if (cards1.size() != 5 || cards2.size() != 5) {
            throw std::invalid_argument("Both card sets must contain exactly five cards.");
        }
        // full house is 3 of a kind and 2 of a kind
        std::map<Rank, int> rankCount1;
        std::map<Rank, int> rankCount2;
        for (const auto& card : cards1) {
            rankCount1[card.getRank()]++;
        }
        for (const auto& card : cards2) {
            rankCount2[card.getRank()]++;
        }
        Rank threeOfAKindRank1, threeOfAKindRank2;
        Rank pairRank1, pairRank2;
        for (const auto& pair : rankCount1) {
            if (pair.second == 3) {
                threeOfAKindRank1 = pair.first;
            } else if (pair.second == 2) {
                pairRank1 = pair.first;
            }
        }
        for (const auto& pair : rankCount2) {
            if (pair.second == 3) {
                threeOfAKindRank2 = pair.first;
            } else if (pair.second == 2) {
                pairRank2 = pair.first;
            }
        }
        // Only compare the rank of the three of a kind because it is not possible to have two full house with the same three of a kind
        return threeOfAKindRank1 > threeOfAKindRank2;
    }
};

#endif // FULLHOUSEPATTERNCOMPAREDHANDLER_HPP