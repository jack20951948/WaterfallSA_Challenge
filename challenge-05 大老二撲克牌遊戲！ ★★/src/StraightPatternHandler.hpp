#ifndef STRAIGHTPATTERNHANDLER_HPP
#define STRAIGHTPATTERNHANDLER_HPP

#include "CardPatternHandler.hpp"

class StraightPatternHandler : public CardPatternHandler {
public:
    StraightPatternHandler() : CardPatternHandler() {}
    StraightPatternHandler(CardPatternHandler* handler) : CardPatternHandler(handler) {}
    CardPattern isValidPattern(const vector<Card>& cards) override;
};

#endif // STRAIGHTPATTERNHANDLER_HPP