#ifndef CARD_H
#define CARD_H

class Card {
    public:
        virtual void printCard() = 0;
        virtual ~Card() = default;
    };
    

#endif // CARD_H