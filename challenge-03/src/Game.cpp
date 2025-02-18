#include "Game.h"

Game::Game(Player* players[], int numPlayers, int initPlayerHandCards) {
    setPlayers(players, numPlayers);
    setInitPlayerHandCards(initPlayerHandCards);
}

void Game::setInitPlayerHandCards(int initPlayerHandCards) {
    this->initPlayerHandCards = initPlayerHandCards;
}

int Game::getInitPlayerHandCards() {
    return initPlayerHandCards;
}

void Game::setPlayers(Player* players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        this->players[i] = players[i];
    }
}

void Game::showWinner(Player* winner) {
    std::cout << "The winner is: " << winner->getName() << std::endl;
}

void Game::playersGetHandCards() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < initPlayerHandCards; j++) {
            players[i]->addCardToHand(deck->drawCard());
        }
    }
}

void Game::prepareGame() {
    // ask players to name themselves
    for (int i = 0; i < 4; i++) {
        players[i]->setName();
    }

    std::cout << "Creating a deck..." << std::endl;

    createDeck();

    // shuffle the deck
    deck->shuffle();

    playersGetHandCards();
}