#include "ShowdownAIPlayer.h"
#include <iostream>

void ShowdownAIPlayer::setName() {
    std::cout << "AIPlayer, please enter your name: ";
    this->name = "AIPlayer" + std::to_string(rand() % 100);
    std::cout << "AIPlayer's name is " << this->name << std::endl;
}

std::unique_ptr<PokerCard> ShowdownAIPlayer::makeDecision() {
    if (hand.empty()) {
        std::cout << "Player has no card in hand!" << std::endl;
        return nullptr;
    }
    int cardIndex = rand() % hand.size();
    auto chosenCard = std::move(hand[cardIndex]);
    hand.erase(hand.begin() + cardIndex);
    return chosenCard;
}