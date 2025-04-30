#include "PairCardPattern.hpp"

CardPattern* PairCardPattern::isValidPattern(const vector<Card>& cards) {
    if (cards.size() == 2 && cards[0].getRank() == cards[1].getRank()) {
        return this;
    } else {
        return nextHandler->isValidPattern(cards);
    }
}

bool PairCardPattern::isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) {
    if (cards1.size() != 2 || cards2.size() != 2) {
        throw std::invalid_argument("Both card sets must contain exactly two cards.");
    }
    if (cards1[0].getRank() == cards2[0].getRank()) {
        return cards1[0].getSuit() > cards2[0].getSuit(); // Compare suits if ranks are equal
    }
    return cards1[0].getRank() > cards2[0].getRank(); // Compare ranks
}