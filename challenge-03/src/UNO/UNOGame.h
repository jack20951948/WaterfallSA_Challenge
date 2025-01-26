#ifndef UNOGAME_H
#define UNOGAME_H

#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "UNODeck.h"
#include <iostream>

class UNOGame {
public:
    UNOGame();
    void setPlayers(Player* players[], int numPlayers);
    void startGame();
    bool checkIfValidCard(UNOCard* card);
private:
    void showWinner();
    Player* players[4];
    UNODeck* deck;
    UNOCard** cardsOnTable = NULL;
    UNOCard* roundCard;
};;

#endif // UNOGAME_H
