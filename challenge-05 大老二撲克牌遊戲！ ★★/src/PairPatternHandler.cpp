#include "PairPatternHandler.hpp"

CardPattern PairPatternHandler::isValidPattern(const vector<Card>& cards) {
    if (cards.size() == 2 && cards[0].getRank() == cards[1].getRank()) {
        return CardPattern::PAIR;
    } else if (nextHandler != nullptr) {
        return nextHandler->isValidPattern(cards);
    } else {
        return CardPattern::UNSUPPORTED;
    }
}