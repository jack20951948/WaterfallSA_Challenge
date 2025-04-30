#include "SingleCardPattern.hpp"

CardPattern* SingleCardPattern::isValidPattern(const vector<Card>& cards) {
    if (cards.size() == 1) {
        return this;
    } else {
        return nextHandler->isValidPattern(cards);
    }
}

bool SingleCardPattern::isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) {
    if (cards1.size() != 1 || cards2.size() != 1) {
        throw std::invalid_argument("Both card sets must contain exactly one card.");
    }
    if (cards1[0].getRank() == cards2[0].getRank()) {
        return cards1[0].getSuit() > cards2[0].getSuit(); // Compare suits if ranks are equal
    }
    return cards1[0].getRank() > cards2[0].getRank(); // Compare ranks
}