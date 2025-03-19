#include "HumanPlayer.h"
#include <iostream>

void HumanPlayer::setName() {
    std::cout << "HumanPlayer, please enter your name: ";
    std::cin >> this->name;
    std::cout << "HumanPlayer's name is " << this->name << std::endl;
}

void HumanPlayer::makeDecision() {
    if ((*getHandCards()).size() == 0) {
        std::cout << "Player has no card in hand!" << std::endl;
        return;
    }
    std::cout << "it's your turn!" << std::endl;
    std::cout << "The cards in your hand are: ";
    printHandCard();
    std::cout << "Please enter the index of the card you want to play: ";
    int cardIndex;
    // keep asking for input if the input is invalid
    while (true) {
        std::cin >> cardIndex;
        if (cardIndex < 0 || cardIndex >= (*handCard).size()) {
            std::cout << "Invalid input! Please enter the index of the card you want to play: ";
        } else {
            break;
        }
    }
    roundCard = (*handCard)[cardIndex];
    (*handCard).erase((*handCard).begin() + cardIndex);
}
