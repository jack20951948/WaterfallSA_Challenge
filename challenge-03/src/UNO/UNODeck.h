#ifndef UNODECK_H
#define UNODECK_H

#include "UNOCard.h"
#include "../Deck.h"

class UNODeck : public Deck {
public:
    void createDeck() override;
};

#endif // UNODECK_H