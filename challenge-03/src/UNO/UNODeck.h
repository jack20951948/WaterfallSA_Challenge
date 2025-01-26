#ifndef UNODECK_H
#define UNODECK_H

#include "UNOCard.h"

class UNODeck {
public:
    UNODeck(int numberAmount, int colorAmount);
    ~UNODeck();
    void shuffle();
    UNOCard* drawCard();
private:
    UNOCard** cards;
    int numberAmount;
    int colorAmount;
};

#endif // UNODECK_H