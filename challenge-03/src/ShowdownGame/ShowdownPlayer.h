#ifndef SHOWDOWN_PLAYER_H
#define SHOWDOWN_PLAYER_H

#include "../Player.h"
#include "PokerCard.h"

class ShowdownPlayer: public Player<PokerCard> {
public:
    Card* show();
    int getScore();
    void addScore();
protected:
    int score; // 0~13
    Card* roundCard;
};

#endif // SHOWDOWN_PLAYER_H
