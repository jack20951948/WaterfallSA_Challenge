#ifndef UNSUPPORTEDCARDPATTERN_HPP
#define UNSUPPORTEDCARDPATTERN_HPP

#include "CardPattern.hpp"

class UnsupportedCardPattern : public CardPattern {
public:
    UnsupportedCardPattern() : CardPattern() { patternName = "Unsupported"; }
    UnsupportedCardPattern(CardPattern* handler) : CardPattern(handler) { patternName = "Unsupported"; }
    CardPattern* isValidPattern(const vector<Card>& cards) override {
        return this;
    }
    bool isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) override {
        return false;
    }
};

#endif // UNSUPPORTEDCARDPATTERN_HPP