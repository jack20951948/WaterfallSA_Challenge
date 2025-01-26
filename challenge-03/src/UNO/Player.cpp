# include "Player.h"

Player::Player() {
    handCard = new std::vector<UNOCard*>();
}

Player::~Player() {
    for (int i = 0; i < (*handCard).size(); i++) {
        delete (*handCard)[i];
    }
}

std::string Player::getName() {
    return name;
}

std::vector<UNOCard*>* Player::getHandCards() {
    return handCard;
}

void Player::addCardToHand(UNOCard* card) {
    (*handCard).push_back(card);
}

void Player::printHandCard() {
    for (int i = 0; i < (*handCard).size(); i++) {
        std::cout << i << ": " << (*handCard)[i]->getSuitString() << "-" << (*handCard)[i]->getNumber() << ", ";
    }
    std::cout << std::endl;
}

bool Player::checkWin() {
    return (*handCard).size() == 0;
}