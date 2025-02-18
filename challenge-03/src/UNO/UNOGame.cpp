#include "UNOGame.h"

UNOGame::UNOGame() {
    cardsOnTable = std::vector<std::unique_ptr<UNOCard>>();
    initHandCards = 5;
}

bool UNOGame::checkIfValidCard(std::unique_ptr<UNOCard>& card) {
    if (card->getNumber() == cardsOnTable[0]->getNumber() || card->getColor() == cardsOnTable[0]->getColor()) {
        return true;
    }
    return false;
}

void UNOGame::addCardToTable(std::unique_ptr<UNOCard> card) {
    cardsOnTable.push_back(std::move(card));
}

std::vector<std::unique_ptr<UNOCard>> UNOGame::getCardsOnTableToDeck() {
    std::vector<std::unique_ptr<UNOCard>> temp;
    for (int i = 1; i < cardsOnTable.size(); i++) {
        temp.push_back(std::move(cardsOnTable[i]));
    }
    cardsOnTable.erase(cardsOnTable.begin() + 1, cardsOnTable.end());
    return temp;
}

void UNOGame::createDeck() {
    deck = std::make_unique<UNODeck>();
    deck->createDeck();
}

void UNOGame::startGame() {
    // start the game
    std::cout << "Starting the game..." << std::endl;
    int currentPlayerIndex = 0;

    // draw a card from the deck
    addCardToTable(std::unique_ptr<UNOCard>(static_cast<UNOCard*>(deck->drawCard().release())));
    std::cout << "\nThe round card is: " << cardsOnTable[0]->getColorString() << "-" << cardsOnTable[0]->getNumber() << std::endl << std::endl;

    for (int i = 0; i < 4; i++) {
        if (static_cast<UNOPlayer*>(players[i].get())->checkWin()) {
            showWinner(players[i]);
            return;
        }
        while (true) {
            std::cout << "\nThe card on the table is: " << cardsOnTable[0]->getColorString() << "-" << cardsOnTable[0]->getNumber() << std::endl << std::endl;
            if (static_cast<UNOPlayer*>(players[currentPlayerIndex].get())->checkAnyValidCard(cardsOnTable[0])) {
                std::unique_ptr<UNOCard> card = players[currentPlayerIndex].get()->makeDecision();
                // std::cout << "Player " << players[currentPlayerIndex]->getName() << " played: ";
                card->printCard();
                if (checkIfValidCard(card)) {
                    addCardToTable(std::move(card));
                    std::cout << "Your card is: ";
                    card->printCard();
                    std::cout << std::endl;
                    if (static_cast<UNOPlayer*>(players[currentPlayerIndex].get())->checkWin()) {
                        showWinner(players[currentPlayerIndex]);
                        return;
                    }
                    currentPlayerIndex = (currentPlayerIndex + 1) % 4;
                    continue;
                } else {
                    std::cout << "Invalid card! Please play a valid card!" << std::endl;
                    players[currentPlayerIndex]->addCardToHand(std::move(card));
                }
            } else {
                // no valid card in hand
                std::cout << "No valid card in hand!" << std::endl;
                // draw a card from the deck
                if (deck->drawCard() == nullptr) {
                    // no more cards in the deck
                    std::cout << "No more cards in the deck!" << std::endl;
                    std::cout << "Adding cards from the table to the deck..." << std::endl;
                    std::vector<std::unique_ptr<UNOCard>> cardsToDeck = getCardsOnTableToDeck();
                    std::vector<std::unique_ptr<Card>> cardsToDeckBase;
                    for (auto& card : cardsToDeck) {
                        cardsToDeckBase.push_back(std::move(card));
                    }
                    deck->addCards(std::move(cardsToDeckBase));
                    deck->shuffle();
                } else {
                    players[currentPlayerIndex]->addCardToHand(std::unique_ptr<UNOCard>(static_cast<UNOCard*>(deck->drawCard().release())));
                }
            }
        }
    }
}