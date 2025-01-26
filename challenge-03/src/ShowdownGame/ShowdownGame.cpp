#include "ShowdownGame.h"
#include <iostream>

ShowdownGame::ShowdownGame() {
    setRoundLeft(13);
}

void ShowdownGame::setRoundLeft(int roundLeft) {
    if (roundLeft < 0) {
        throw "Round left cannot be negative";
    }
    this->roundLeft = roundLeft;
}

int ShowdownGame::getRoundLeft() {
    return roundLeft;
}

void ShowdownGame::setPlayers(Player* players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        this->players[i] = players[i];
    }
}

Player* ShowdownGame::competeForRoundWinner(Player* players[]) {
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

void ShowdownGame::showWinner() {
    Player* winner = players[0];
    for (int i = 1; i < 4; i++) {
        if (players[i]->getScore() > winner->getScore()) {
            winner = players[i];
        }
    }
    std::cout << "The winner is: " << winner->getName() << std::endl;
}

void ShowdownGame::startGame() {
    // create players
    Player* players[4] = {new HumanPlayer(), new AIPlayer(), new AIPlayer(), new AIPlayer()};
    setPlayers(players, 4);

    // ask players to name themselves
    for (int i = 0; i < 4; i++) {
        players[i]->setName();
    }

    // create a deck
    std::cout << "Creating a deck..." << std::endl;
    deck = new Deck(13, 4);

    std::cout << "Shuffling the deck..." << std::endl;
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
