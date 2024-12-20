#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "ExchangedCardDetail.h"

class Player {
public:
    virtual void makeDecision() = 0; // Pure virtual function
    virtual void setName() = 0;
    std::string getName();
    bool isExchanged();
    void setExchanged(bool exchanged);
    Player* getPlayerToExchange();
    std::vector<Card*>* getHandCards();
    void exchangeHands(Player* playerToExchange);
    void exchangeRelationshipCheck();
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
    bool hasExchanged;
    Player* playerToExchange;
    ExchangedCardDetail* exchangedCardDetail;
};

#endif // PLAYER_H
