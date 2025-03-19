#ifndef UNO_CARD_H
#define UNO_CARD_H

#include <iostream>
#include "UNOCardColor.h"
#include "../Card.h"

class UNOCard : public Card {
    public:
        UNOCard(UNOCardColor color, int number);
        void printCard() override;
        int getNumber();
        void setNumber(int number);
        UNOCardColor getColor();
        void setColor(UNOCardColor color);
        std::string getColorString();
    protected:
        UNOCardColor color;
        int number;
    };

#endif // UNO_CARD_H