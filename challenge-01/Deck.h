#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
public:
    Deck();
    ~Deck();
    void shuffle();
    Card* drawCard();
private:
    Card* cards[52];
};

#endif // DECK_H