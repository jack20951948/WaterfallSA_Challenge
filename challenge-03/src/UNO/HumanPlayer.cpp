#include "HumanPlayer.h"
#include <iostream>

void HumanPlayer::setName() {
    std::cout << "HumanPlayer, please enter your name: ";
    std::cin >> this->name;
    std::cout << "HumanPlayer's name is " << this->name << std::endl;
}

UNOCard* HumanPlayer::makeDecision() {
    // check if the player has any card in hand
    if ((*getHandCards()).size() == 0) {
        std::cout << "Player has no card in hand!" << std::endl;
        return;
    }

    std::cout << "it's your turn!" << std::endl;

    std::cout << "The cards in your hand are: ";
    printHandCard();

    // ask the player to choose a card to play
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
    UNOCard* roundCard = (*handCard)[cardIndex];
    (*handCard).erase((*handCard).begin() + cardIndex);

    return roundCard;
}
