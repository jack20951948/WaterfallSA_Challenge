#ifndef POKERCARD_H
#define POKERCARD_H

#include <iostream>
#include "CardSuit.h"
#include "CardRank.h"
#include "Card.h"

class PokerCard: public Card
{
private:
    CardRank rank;
    CardSuit suit;
public:
    PokerCard(CardRank rank, CardSuit suit);
    ~PokerCard();
    CardRank getRank();
    CardSuit getSuit();
    std::string getRankString();
    std::string getSuitString();
    void printCard();
};

#endif // POKERCARD_H