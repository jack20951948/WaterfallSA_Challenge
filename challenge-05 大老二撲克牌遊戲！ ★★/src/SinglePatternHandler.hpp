#ifndef SINGLEPATTERNHANDLER_HPP
#define SINGLEPATTERNHANDLER_HPP

#include "CardPatternHandler.hpp"

class SinglePatternHandler : public CardPatternHandler {
public:
    SinglePatternHandler() : CardPatternHandler() {}
    SinglePatternHandler(CardPatternHandler* handler) : CardPatternHandler(handler) {}
    CardPattern isValidPattern(const vector<Card>& cards) override;
};

#endif // SINGLEPATTERNHANDLER_HPP