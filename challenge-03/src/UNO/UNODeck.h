#ifndef UNODECK_H
#define UNODECK_H

#include "UNOCard.h"

class UNODeck {
public:
    UNODeck(int numberAmount, int colorAmount);
    ~UNODeck();
    void shuffle();
    UNOCard* drawCard();
    void addCards(UNOCard** cards, int amount);
private:
    UNOCard** cards;
    int numberAmount;
    int colorAmount;
    int cardLeft = 0;
};

#endif // UNODECK_H