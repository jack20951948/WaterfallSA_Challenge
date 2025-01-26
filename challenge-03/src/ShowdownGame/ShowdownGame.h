#ifndef SHOWDOWNGAME_H
#define SHOWDOWNGAME_H

#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Deck.h"
#include <iostream>

class ShowdownGame {
public:
    ShowdownGame();
    void setRoundLeft(int roundLeft);
    int getRoundLeft();
    void setPlayers(Player* players[], int numPlayers);
    void startGame();
private:
    Player* competeForRoundWinner(Player* players[]);
    void showWinner();
    int roundLeft;
    Player* players[4];
    Deck* deck;
};;

#endif // SHOWDOWNGAME_H
