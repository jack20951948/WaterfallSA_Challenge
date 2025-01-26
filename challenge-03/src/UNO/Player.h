#ifndef PLAYER_H
#define PLAYER_H

#include "UNOCard.h"

class Player {
public:
    virtual UNOCard* makeDecision() = 0; // Pure virtual function
    virtual void setName() = 0;
    std::string getName();
    std::vector<UNOCard*>* getHandCards();
    void addCardToHand(UNOCard* card);
    void printHandCard();
    bool checkWin();

    Player();
    ~Player();
protected:
    std::string name;
    std::vector<UNOCard*>* handCard;
};

#endif // PLAYER_H
