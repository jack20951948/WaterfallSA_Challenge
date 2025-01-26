#ifndef UNO_CARD_H
#define UNO_CARD_H

#include <iostream>
#include "UNOCardColor.h"

class UNOCard
{
private:
    int number;
    UNOCardColor suit;
public:
    UNOCard(int number, UNOCardColor suit);
    ~UNOCard();
    int getNumber();
    void setNumber(int number);
    UNOCardColor getSuit();
    void setSuit(UNOCardColor suit);
    std::string getSuitString();

};

#endif // UNO_CARD_H