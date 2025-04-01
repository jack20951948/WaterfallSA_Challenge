#ifndef PAIRPATTERNHANDLER_HPP
#define PAIRPATTERNHANDLER_HPP

#include "CardPatternHandler.hpp"

class PairPatternHandler : public CardPatternHandler {
public:
    PairPatternHandler() : CardPatternHandler() {}
    PairPatternHandler(CardPatternHandler* handler) : CardPatternHandler(handler) {}
    CardPattern isValidPattern(const vector<Card>& cards) override;
};

#endif // PAIRPATTERNHANDLER_HPP