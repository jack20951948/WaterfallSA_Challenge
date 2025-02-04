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
    void addCardToTable(UNOCard* card);
    std::pair<UNOCard**, int> getCardsOnTableToDeck();
private:
    void showWinner(Player* winner);
    Player* players[4];
    UNODeck* deck;
    UNOCard** cardsOnTable = NULL;
    int cardOnTableAmount = 0;
};;

#endif // UNOGAME_H
