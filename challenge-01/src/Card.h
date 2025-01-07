#ifndef CARD_H
#define CARD_H

#include <iostream>
#include "CardSuit.h"
#include "CardRank.h"

class Card
{
private:
    CardRank rank;
    CardSuit suit;
public:
    Card(CardRank rank, CardSuit suit);
    ~Card();
    CardRank getRank();
    CardSuit getSuit();
    std::string getRankString();
    std::string getSuitString();

};

#endif // CARD_H