#ifndef SHOWDOWNDECK_H
#define SHOWDOWNDECK_H

#include "PokerCard.h"
#include "Deck.h"

class ShowdownDeck: public Deck {
public:
    ShowdownDeck(int rankAmount, int suitAmount): Deck(rankAmount, suitAmount) {};
    Card* createCard(int rank, int suit);
};

#endif // SHOWDOWNDECK_H