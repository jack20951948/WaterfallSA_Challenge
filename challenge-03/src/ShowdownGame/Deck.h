#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
public:
    Deck(int rankAmount, int suitAmount);
    ~Deck();
    void shuffle();
    Card* drawCard();
private:
    Card** cards;
    int rankAmount;
    int suitAmount;
};

#endif // DECK_H