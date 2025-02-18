# include "Player.h"

Player::Player() {
    handCard = new std::vector<Card*>();
}

Player::~Player() {
    for (int i = 0; i < (*handCard).size(); i++) {
        delete (*handCard)[i];
    }
}

std::string Player::getName() {
    return name;
}

std::vector<Card*>* Player::getHandCards() {
    return handCard;
}

void Player::addCardToHand(Card* card) {
    (*handCard).push_back(card);
}

void Player::printHandCard() {
    for (int i = 0; i < (*handCard).size(); i++) {
        std::cout << i << ": ";
        (*handCard)[i]->printCard();
        std::cout << ", ";
    }
    std::cout << std::endl;
}

bool Player::checkWin() {
    return (*handCard).size() == 0;
}