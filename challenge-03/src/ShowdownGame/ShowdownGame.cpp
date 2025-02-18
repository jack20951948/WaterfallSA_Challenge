#include "ShowdownGame.h"
#include <iostream>

ShowdownGame::ShowdownGame() {
    setRoundLeft(13);
    initHandCards = 13;
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

std::unique_ptr<ShowdownPlayer> ShowdownGame::competeForRoundWinner(std::vector<std::unique_ptr<ShowdownPlayer>> players) {
    std::vector<std::unique_ptr<ShowdownPlayer>> temp;
    for (int i = 0; i < 4; i++) {
        temp.push_back(std::move(players[i]));
    }
    std::unique_ptr<ShowdownPlayer> winner = std::move(temp[0]);
    for (int i = 1; i < 4; i++) {
        if (temp[i]->show()->getRank() > winner->show()->getRank()) {
            winner = std::move(temp[i]);
        } else if (temp[i]->show()->getRank() == winner->show()->getRank()) {
            if (temp[i]->show()->getSuit() > winner->show()->getSuit()) {
                winner = std::move(temp[i]);
            }
        }
    }
    return winner;
}

void ShowdownGame::startGame() {
    // find the winner of this round
    std::vector<std::unique_ptr<ShowdownPlayer>> showdownPlayers;
    for (auto& player : players) {
        showdownPlayers.push_back(std::unique_ptr<ShowdownPlayer>(dynamic_cast<ShowdownPlayer*>(player.release())));
    }

    // print the cards in each player's hand
    for (int i = 0; i < 4; i++) {
        std::cout << showdownPlayers[i]->getName() << "'s hand cards: ";
        showdownPlayers[i]->printHand();
    }

    // if the game rounds are not left
    while (getRoundLeft() > 0) {
        
        // each player takes a turn
        for (int i = 0; i < 4; i++) {
            showdownPlayers[i]->makeDecision();
        }

        // Show the cards played by each player
        for (int i = 0; i < 4; i++) {
            std::cout << showdownPlayers[i]->getName() << " played: " << showdownPlayers[i]->show()->getSuitString() << " " << showdownPlayers[i]->show()->getRankString() << std::endl;
        }

        ShowdownPlayer* winner = competeForRoundWinner(std::move(showdownPlayers)).release();
        std::cout << "The winner of this round is: " << winner->getName() << std::endl;

        // update score
        winner->addScore();

        // update roundLeft
        setRoundLeft(getRoundLeft() - 1);
    }

    // show the winner
    std::unique_ptr<ShowdownPlayer> gameWinner = std::move(showdownPlayers[0]);
    for (int i = 1; i < 4; i++) {
        if (showdownPlayers[i]->getScore() > gameWinner->getScore()) {
            gameWinner = std::move(showdownPlayers[i]);
        }
    }

    showWinner(std::move(gameWinner));
}
