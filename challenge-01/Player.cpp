# include "Player.h"

Player::Player() {
    score = 0;
    setExchanged(false);
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

bool Player::isExchanged() {
    return hasExchanged;
}

void Player::setExchanged(bool exchanged) {
    hasExchanged = exchanged;
}

Player* Player::getPlayerToExchange() {
    return playerToExchange;
}

std::vector<Card*>* Player::getHandCards() {
    return handCard;
}

void Player::addCardToHand(Card* card) {
    (*handCard).push_back(card);
}

void Player::exchangeHands(Player* playerToExchange) {
    if (getPlayerToExchange() != nullptr) {
        throw "Player has already exchanged cards";
    }
    if (playerToExchange->getPlayerToExchange() != nullptr) {
        throw "Player to exchange has already exchanged cards";
    }
    std::cout << "Player " << name << " is exchanging cards with " << playerToExchange->getName() << std::endl;
    std::vector<Card*>* temp = handCard;
    handCard = playerToExchange->handCard;
    playerToExchange->handCard = temp;

    exchangedCardDetail->setExchanger(true);
    setExchanged(true);
    Player::playerToExchange = playerToExchange;
    playerToExchange->playerToExchange = this;
    exchangedCardDetail = new ExchangedCardDetail();
    playerToExchange->exchangedCardDetail = exchangedCardDetail;
}

void Player::exchangeRelationshipCheck() {
    if (exchangedCardDetail == nullptr) {
        return;
    }
    if (playerToExchange == nullptr) {
        return;
    }
    if (playerToExchange->exchangedCardDetail == nullptr) {
        return;
    }
    if (exchangedCardDetail->getRoundLeft() > 0) {
        if (exchangedCardDetail->isExchanger()) {
            exchangedCardDetail->setRoundLeft(exchangedCardDetail->getRoundLeft() - 1);
        }
        std::cout << "Player " << name << " has " << exchangedCardDetail->getRoundLeft() << " rounds left to exchange with " << playerToExchange->getName() << std::endl;
    } else {
        exchangedCardDetail->setExchanger(false);
        exchangedCardDetail = nullptr;
        playerToExchange->exchangedCardDetail = nullptr;
        std::vector<Card*>* temp = handCard;
        handCard = playerToExchange->handCard;
        playerToExchange->handCard = temp;
        playerToExchange->playerToExchange = nullptr;
        playerToExchange = nullptr;
    }
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