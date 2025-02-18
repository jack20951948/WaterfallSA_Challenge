#ifndef SHOWDOWNGAME_H
#define SHOWDOWNGAME_H

#include "ShowdownPlayer.h"
#include "../Game.h"
#include <iostream>

class ShowdownGame: public Game<PokerCard> {
public:
    ShowdownGame();
    void setRoundLeft(int roundLeft);
    int getRoundLeft();
    void createDeck() override;
    void startGame() override;
private:
    std::unique_ptr<ShowdownPlayer> competeForRoundWinner(vector<std::unique_ptr<ShowdownPlayer>>& players[]);
    int roundLeft;
};;

#endif // SHOWDOWNGAME_H
