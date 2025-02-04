#include "UNODeck.h"

UNODeck::UNODeck(int numberAmount, int colorAmount) {
    // Create a deck of cards
    cardLeft = colorAmount * numberAmount;
    cards = new UNOCard*[cardLeft];
    int index = 0;
    for (int i = 0; i < colorAmount; i++) {
        for (int j = 0; j < numberAmount; j++) {
            cards[index] = new UNOCard(j, static_cast<UNOCardColor>(i));
            index++;
        }
    }
}

UNODeck::~UNODeck() {
    for (int i = 0; i < cardLeft; i++) {
        delete cards[i];
    }
}

void UNODeck::shuffle() {
    // Shuffle the deck
    for (int i = 0; i < cardLeft; i++) {
        int randomIndex = rand() % (cardLeft);
        UNOCard* temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

UNOCard* UNODeck::drawCard() {
    // Draw a card from the deck
    if (cardLeft == 0) {
        return nullptr;
    }
    UNOCard* card = cards[0];
    for (int i = 0; i < (cardLeft) - 1; i++) {
        cards[i] = cards[i + 1];
    }
    cards[(cardLeft) - 1] = nullptr;
    cardLeft--;
    return card;
}

void UNODeck::addCards(UNOCard** cards, int amount) {
    UNOCard** temp = new UNOCard*[cardLeft];
    for (int i = 0; i < cardLeft; i++) {
        temp[i] = this->cards[i];
    }
    delete[] this->cards;
    this->cards = new UNOCard*[cardLeft + amount];
    for (int i = 0; i < cardLeft; i++) {
        this->cards[i] = temp[i];
    }
    for (int i = 0; i < amount; i++) {
        this->cards[cardLeft + i] = cards[i];
    }
    cardLeft += amount;
}