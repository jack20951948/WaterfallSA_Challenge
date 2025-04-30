#ifndef FULLHOUSECARDPATTERN_HPP
#define FULLHOUSECARDPATTERN_HPP

#include "CardPattern.hpp"
#include "UnsupportedCardPattern.hpp"

class FullHouseCardPattern : public CardPattern {
public:
    FullHouseCardPattern() : CardPattern() { patternName = "葫蘆"; }
    FullHouseCardPattern(CardPattern* handler) : CardPattern(handler) { patternName = "葫蘆"; }
    CardPattern* isValidPattern(const vector<Card>& cards) override;
    bool isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) override;
};

#endif // FULLHOUSECARDPATTERN_HPP