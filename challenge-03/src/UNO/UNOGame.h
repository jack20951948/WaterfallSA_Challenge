#ifndef UNOGAME_H
#define UNOGAME_H

#include "UNOHumanPlayer.h"
#include "UNOAIPlayer.h"
#include "UNODeck.h"
#include "../Game.h"
#include <iostream>

class UNOGame : public Game<UNOCard> {
public:
    UNOGame();
protected:
    void createDeck() override;
    void startGame() override;
    void addCardToTable(std::unique_ptr<UNOCard> card);
    bool checkIfValidCard(std::unique_ptr<UNOCard>& card);
    std::vector<std::unique_ptr<UNOCard>> getCardsOnTableToDeck();
private:
    std::vector<std::unique_ptr<UNOCard>> cardsOnTable;
};

#endif // UNOGAME_H
