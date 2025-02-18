#include "ShowdownHumanPlayer.h"
#include <iostream>

void ShowdownHumanPlayer::setName() {
    std::cout << "HumanPlayer, please enter your name: ";
    std::cin >> this->name;
    std::cout << "HumanPlayer's name is " << this->name << std::endl;
}

std::unique_ptr<PokerCard> ShowdownHumanPlayer::makeDecision() {
    if (hand.empty()) {
        std::cout << "Player has no card in hand!" << std::endl;
        return nullptr;
    }
    std::cout << "\nIt's your turn!" << std::endl;
    printHand();
    std::cout << "\nPlease enter the index of the card you want to play: ";
    int cardIndex;
    while (true) {
        std::cin >> cardIndex;
        if (cardIndex >= 0 && cardIndex < hand.size()) {
            break;
        }
        std::cout << "Invalid input! Please enter a valid index: ";
    }
    auto chosenCard = std::move(hand[cardIndex]);
    hand.erase(hand.begin() + cardIndex);
    std::cout << "You played: ";
    chosenCard->printCard();
    std::cout << std::endl;
    return chosenCard;
}