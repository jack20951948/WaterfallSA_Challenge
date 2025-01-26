#include "AIPlayer.h"
#include <iostream>

void AIPlayer::setName() {
    std::cout << "AIPlayer, please enter your name: ";
    this->name = "AIPlayer" + std::to_string(rand() % 100);
    std::cout << "AIPlayer's name is " << this->name << std::endl;
}

UNOCard* AIPlayer::makeDecision() {
    // check if the player has any card in hand
    if ((*getHandCards()).size() == 0) {
        std::cout << "Player has no card in hand!" << std::endl;
        return;
    }

    // AIPlayer randomly choose a card to play
    std::cout << "AIPlayer is playing!" << std::endl;
    int cardIndex = rand() % (*handCard).size();
    UNOCard* roundCard = (*handCard)[cardIndex];

    // remove the card from hand
    (*handCard).erase((*handCard).begin() + cardIndex);
    return roundCard;
}