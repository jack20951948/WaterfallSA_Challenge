#ifndef PAIRCARDPATTERN_HPP
#define PAIRCARDPATTERN_HPP

#include "CardPattern.hpp"
#include "UnsupportedCardPattern.hpp"

class PairCardPattern : public CardPattern {
public:
    PairCardPattern() : CardPattern() { patternName = "對子"; }
    PairCardPattern(CardPattern* handler) : CardPattern(handler) { patternName = "對子"; }
    CardPattern* isValidPattern(const vector<Card>& cards) override;
    bool isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) override;
};

#endif // PAIRCARDPATTERN_HPP