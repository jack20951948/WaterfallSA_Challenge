#include "AIPlayer.h"
#include <iostream>

void AIPlayer::setName() {
    std::cout << "AIPlayer, please enter your name: ";
    this->name = "AIPlayer" + std::to_string(rand() % 100);
    std::cout << "AIPlayer's name is " << this->name << std::endl;
}

void AIPlayer::makeDecision() {
    if ((*getHandCards()).size() == 0) {
        std::cout << "Player has no card in hand!" << std::endl;
        return;
    }
    std::cout << "AIPlayer is playing!" << std::endl;
    int cardIndex = rand() % (*handCard).size();
    roundCard = (*handCard)[cardIndex];
    (*handCard).erase((*handCard).begin() + cardIndex);
}