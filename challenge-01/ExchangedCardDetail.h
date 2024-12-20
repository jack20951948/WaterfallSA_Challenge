#ifndef EXCHANGEDCARDDETAIL_H
#define EXCHANGEDCARDDETAIL_H

#include "Card.h"

class ExchangedCardDetail {
public:
    int getRoundLeft();
    void setRoundLeft(int roundLeft);
    bool isExchanger();
    void setExchanger(bool exchanged);
    ExchangedCardDetail();
private:
    int roundLeft;
    bool isTheExchanger;
};

#endif // EXCHANGEDCARDDETAIL_H