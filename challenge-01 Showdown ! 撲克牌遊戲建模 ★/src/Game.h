#ifndef GAME_H
#define GAME_H

#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Deck.h"
#include <iostream>

class Game {
public:
    Game();
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

#endif // GAME_H
