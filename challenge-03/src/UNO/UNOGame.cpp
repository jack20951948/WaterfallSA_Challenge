#include "UNOGame.h"

UNOGame::UNOGame() {
    cardsOnTable = new UNOCard*[1];
}

void UNOGame::setPlayers(Player* players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        this->players[i] = players[i];
    }
}

bool UNOGame::checkIfValidCard(UNOCard* card) {
    if (card->getNumber() == roundCard->getNumber() || card->getSuit() == roundCard->getSuit()) {
        return true;
    }
    return false;
}

void UNOGame::startGame() {
    // create players
    Player* players[4] = {new HumanPlayer(), new AIPlayer(), new AIPlayer(), new AIPlayer()};
    setPlayers(players, 4);

    // ask players to name themselves
    for (int i = 0; i < 4; i++) {
        players[i]->setName();
    }

    // create a deck
    deck = new UNODeck(10, 4);
    
    // shuffle the deck
    deck->shuffle();

    // deal cards to players
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            players[i]->addCardToHand(deck->drawCard());
        }
    }

    // start the game
    int currentPlayerIndex = 0;

    // draw a card from the deck
    roundCard = deck->drawCard();
    cardsOnTable[0] = roundCard;
    std::cout << "The round card is: " << roundCard->getSuitString() << "-" << roundCard->getNumber() << std::endl;

    for (int i = 0; i < 4; i++) {
        if (players[i]->checkWin()) {
            showWinner();
            return;
        }
        while (true) {
            UNOCard* card = players[currentPlayerIndex]->makeDecision();
            if (checkIfValidCard(card)) {
                roundCard = card;
                std::cout << "The round card is: " << roundCard->getSuitString() << "-" << roundCard->getNumber() << std::endl;
                if (players[currentPlayerIndex]->checkWin()) {
                    showWinner();
                    return;
                }
                break;
            } else {
                std::cout << "Invalid card! Please play a valid card!" << std::endl;

                // ask the player if they want to draw a card
                std::cout << "Do you want to draw a card? (y/n): ";
                char choice;
                std::cin >> choice;
                if (choice == 'y') {
                    players[currentPlayerIndex]->addCardToHand(deck->drawCard());
                }
            }
        }
    }
}