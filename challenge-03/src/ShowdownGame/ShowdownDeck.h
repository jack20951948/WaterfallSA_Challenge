#ifndef SHOWDOWNDECK_H
#define SHOWDOWNDECK_H

#include "PokerCard.h"
#include "../Deck.h"

class ShowdownDeck: public Deck {
public:
    void createDeck() override;
};

#endif // SHOWDOWNDECK_H