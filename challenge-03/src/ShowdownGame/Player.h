#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
public:
    virtual void makeDecision() = 0; // Pure virtual function
    virtual void setName() = 0;
    std::string getName();
    std::vector<Card*>* getHandCards();
    void addCardToHand(Card* card);
    void printHandCard();
    Card* show();
    int getScore();
    void addScore();

    Player();
    ~Player();
protected:
    std::string name;
    int score; // 0~13
    std::vector<Card*>* handCard;
    Card* roundCard;
};

#endif // PLAYER_H
