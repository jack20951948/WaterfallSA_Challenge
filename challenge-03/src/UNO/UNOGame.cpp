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
    if (card->getNumber() == cardsOnTable[0]->getNumber() || card->getSuit() == cardsOnTable[0]->getSuit()) {
        return true;
    }
    return false;
}

void UNOGame::addCardToTable(UNOCard* card) {
    if (cardOnTableAmount == 0) {
        cardsOnTable[0] = card;
        cardOnTableAmount++;
    } else {
        UNOCard** temp = new UNOCard*[cardOnTableAmount];
        for (int i = 0; i < cardOnTableAmount; i++) {
            temp[i] = cardsOnTable[i];
        }
        delete[] cardsOnTable;
        cardsOnTable = new UNOCard*[cardOnTableAmount + 1];
        for (int i = 0; i < cardOnTableAmount; i++) {
            cardsOnTable[i + 1] = temp[i];
        }
        cardsOnTable[0] = card;
        cardOnTableAmount++;
    }
}

std::pair<UNOCard**, int> UNOGame::getCardsOnTableToDeck() {
    // get the cards except for first card on the table to the deck
    UNOCard** temp = new UNOCard*[cardOnTableAmount - 1];
    for (int i = 1; i < cardOnTableAmount; i++) {
        temp[i - 1] = cardsOnTable[i];
    }
    int tempAmount = cardOnTableAmount;
    cardOnTableAmount = 1;
    return std::make_pair(temp, tempAmount - 1);
}

void UNOGame::showWinner(Player* winner) {
    std::cout << "The winner is: " << winner->getName() << std::endl;
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
    addCardToTable(deck->drawCard());
    // cardsOnTable[0] = roundCard;
    std::cout << "\nThe round card is: " << cardsOnTable[0]->getSuitString() << "-" << cardsOnTable[0]->getNumber() << std::endl << std::endl;

    for (int i = 0; i < 4; i++) {
        if (players[i]->checkWin()) {
            showWinner(players[i]);
            return;
        }
        while (true) {
            std::cout << "\nThe card on the table is: " << cardsOnTable[0]->getSuitString() << "-" << cardsOnTable[0]->getNumber() << std::endl << std::endl;
            if (players[currentPlayerIndex]->checkAnyValidCard(cardsOnTable[0])) {
                UNOCard* card = players[currentPlayerIndex]->makeDecision();
                if (checkIfValidCard(card)) {
                    addCardToTable(card);
                    std::cout << "Your card is: " << card->getSuitString() << "-" << card->getNumber() << std::endl;
                    if (players[currentPlayerIndex]->checkWin()) {
                        showWinner(players[currentPlayerIndex]);
                        return;
                    }
                    currentPlayerIndex = (currentPlayerIndex + 1) % 4;
                    continue;
                } else {
                    std::cout << "Invalid card! Please play a valid card!" << std::endl;
                    players[currentPlayerIndex]->addCardToHand(card);
                }
            } else {
                // no valid card in hand
                std::cout << "No valid card in hand!" << std::endl;
                // draw a card from the deck
                if (deck->drawCard() == nullptr) {
                    // no more cards in the deck
                    std::cout << "No more cards in the deck!" << std::endl;
                    std::cout << "Adding cards from the table to the deck..." << std::endl;
                    std::pair<UNOCard**, int> cardsToDeck = getCardsOnTableToDeck();
                    deck->addCards(cardsToDeck.first, cardsToDeck.second);
                    deck->shuffle();
                } else {
                    players[currentPlayerIndex]->addCardToHand(deck->drawCard());
                }
            }
        }
    }
}