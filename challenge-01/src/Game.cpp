#include "Game.h"
#include <iostream>

Game::Game() {
    setRoundLeft(13);
}

void Game::setRoundLeft(int roundLeft) {
    if (roundLeft < 0) {
        throw "Round left cannot be negative";
    }
    this->roundLeft = roundLeft;
}

int Game::getRoundLeft() {
    return roundLeft;
}

void Game::setPlayers(Player* players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        this->players[i] = players[i];
    }
}

Player* Game::competeForRoundWinner(Player* players[]) {
    Player* winner = players[0];
    for (int i = 1; i < 4; i++) {
        if (players[i]->show()->getRank() > winner->show()->getRank()) {
            winner = players[i];
        } else if (players[i]->show()->getRank() == winner->show()->getRank()) {
            if (players[i]->show()->getSuit() > winner->show()->getSuit()) {
                winner = players[i];
            }
        }
    }
    return winner;
}

void Game::showWinner() {
    Player* winner = players[0];
    for (int i = 1; i < 4; i++) {
        if (players[i]->getScore() > winner->getScore()) {
            winner = players[i];
        }
    }
    std::cout << "The winner is: " << winner->getName() << std::endl;
}

void Game::startGame() {
    // create players
    Player* players[4] = {new HumanPlayer(), new AIPlayer(), new AIPlayer(), new AIPlayer()};
    setPlayers(players, 4);

    // ask players to name themselves
    for (int i = 0; i < 4; i++) {
        players[i]->setName();
    }

    // create a deck
    deck = new Deck();

    // shuffle the deck
    deck->shuffle();

    // players draw cards
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            players[j]->addCardToHand(deck->drawCard());
        }
    }

    // print the cards in each player's hand
    for (int i = 0; i < 4; i++) {
        std::cout << players[i]->getName() << "'s hand cards: ";
        players[i]->printHandCard();
    }

    // if the game rounds are not left
    while (getRoundLeft() > 0) {
        
        // each player takes a turn
        for (int i = 0; i < 4; i++) {
            // if the player's exchanged card round is not left, reset the exchanged card
            players[i]->exchangeRelationshipCheck();
            // if the player has not exchanged cards, it can choose to exchange cards with any other player for 3 rounds every game
            if (!players[i]->isExchanged() && players[i]->getPlayerToExchange() == nullptr) {
                std::cout << players[i]->getName() << ", do you want to exchange cards at this round? one player can only exchange once. (y/n): ";
                char choice;
                // if the player is human, ask for input
                if (dynamic_cast<HumanPlayer*>(players[i])) {
                    std::cin >> choice;
                } else {
                    // if the player is AI, randomly choose to exchange or not
                    choice = rand() % 2 == 0 ? 'y' : 'n';
                    std::cout << choice << std::endl;
                }
                if (choice == 'y') {
                    std::cout << players[i]->getName() << ", please choose a player to exchange cards with: ";
                    int playerIndex;
                    // if the player is human, ask for input
                    if (dynamic_cast<HumanPlayer*>(players[i])) {
                        std::cin >> playerIndex;
                    } else {
                        // if the player is AI, randomly choose a player to exchange cards with
                        playerIndex = rand() % 4;
                        while (playerIndex == i || players[playerIndex]->getPlayerToExchange() != nullptr) {
                            playerIndex = rand() % 4;
                        }
                        std::cout << playerIndex << std::endl;
                    }
                    // exchange cards
                    players[i]->exchangeHands(players[playerIndex]);
                } else {
                    std::cout << players[i]->getName() << " chose not to exchange cards." << std::endl;
                }
            }
            
            players[i]->makeDecision();
        }

        // Show the cards played by each player
        for (int i = 0; i < 4; i++) {
            std::cout << players[i]->getName() << " played: " << players[i]->show()->getSuitString() << " " << players[i]->show()->getRankString() << std::endl;
        }

        // find the winner of this round
        Player* winner = competeForRoundWinner(players);
        std::cout << "The winner of this round is: " << winner->getName() << std::endl;

        // update score
        winner->addScore();

        // update roundLeft
        setRoundLeft(getRoundLeft() - 1);
    }

    // show the winner
    showWinner();
}
