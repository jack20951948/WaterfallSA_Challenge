#ifndef POKERCARD_H
#define POKERCARD_H

#include <iostream>
#include "CardSuit.h"
#include "CardRank.h"
#include "../Card.h"

class PokerCard: public Card
{
public:
    PokerCard(CardRank rank, CardSuit suit);
    void printCard() override;
    CardRank getRank();
    void setRank(CardRank rank);
    CardSuit getSuit();
    void setSuit(CardSuit suit);
    std::string getRankString();
    std::string getSuitString();
protected:
        CardRank rank;
        CardSuit suit;
};

#endif // POKERCARD_H