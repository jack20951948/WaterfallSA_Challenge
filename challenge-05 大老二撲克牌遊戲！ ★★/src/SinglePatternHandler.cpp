#include "SinglePatternHandler.hpp"

CardPattern SinglePatternHandler::isValidPattern(const vector<Card>& cards) {
    if (cards.size() == 1) {
        return CardPattern::SINGLE;
    } else if (nextHandler != nullptr) {
        return nextHandler->isValidPattern(cards);
    } else {
        return CardPattern::UNSUPPORTED;
    }
}