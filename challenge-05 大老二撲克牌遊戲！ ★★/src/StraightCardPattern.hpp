#ifndef STRAIGHTCARDPATTERN_HPP
#define STRAIGHTCARDPATTERN_HPP

#include "CardPattern.hpp"
#include "UnsupportedCardPattern.hpp"

class StraightCardPattern : public CardPattern {
public:
    StraightCardPattern() : CardPattern() { patternName = "順子"; }
    StraightCardPattern(CardPattern* handler) : CardPattern(handler) { patternName = "順子"; }
    CardPattern* isValidPattern(const vector<Card>& cards) override;
    bool isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) override;
};

#endif // STRAIGHTCARDPATTERN_HPP