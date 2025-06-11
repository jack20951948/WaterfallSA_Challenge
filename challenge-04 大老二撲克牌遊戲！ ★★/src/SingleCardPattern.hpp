#ifndef SINGLECARDPATTERN_HPP
#define SINGLECARDPATTERN_HPP

#include "CardPattern.hpp"
#include "UnsupportedCardPattern.hpp"

class SingleCardPattern : public CardPattern {
public:
    SingleCardPattern() : CardPattern() { patternName = "單張"; }
    SingleCardPattern(CardPattern* handler) : CardPattern(handler) { patternName = "單張"; }
    CardPattern* isValidPattern(const vector<Card>& cards) override;
    bool isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) override;
};

#endif // SINGLECARDPATTERN_HPP