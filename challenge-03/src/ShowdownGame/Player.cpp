# include "Player.h"

Player::Player() {
    score = 0;
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
        std::cout << i << ": " << (*handCard)[i]->getSuitString() << "-" << (*handCard)[i]->getRankString() << ", ";
    }
    std::cout << std::endl;
}

Card* Player::show() {
    return roundCard;
}

int Player::getScore() {
    return score;
}

void Player::addScore() {
    if (score <= 13)
        score++;
    else
        throw "Score is out of range";
}