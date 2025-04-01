#include "FullHousePatternHandler.hpp"
#include <map>

CardPattern FullHousePatternHandler::isValidPattern(const vector<Card>& cards) {
    if (cards.size() != 5) {
        return nextHandler ? nextHandler->isValidPattern(cards) : CardPattern::UNSUPPORTED;
    }

    // Count the occurrences of each rank
    std::map<Rank, int> rankCount;
    for (const auto& card : cards) {
        rankCount[card.getRank()]++;
    }

    // Check for a full house pattern (3 of one rank and 2 of another)
    bool hasThreeOfAKind = false;
    bool hasPair = false;

    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            hasThreeOfAKind = true;
        } else if (pair.second == 2) {
            hasPair = true;
        }
    }

    if (hasThreeOfAKind && hasPair) {
        return CardPattern::FULL_HOUSE;
    } else {
        return nextHandler ? nextHandler->isValidPattern(cards) : CardPattern::UNSUPPORTED;
    }
}