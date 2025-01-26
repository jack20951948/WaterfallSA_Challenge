#include "UNODeck.h"

UNODeck::UNODeck(int numberAmount, int colorAmount) {
    // Create a deck of cards
    cards = new UNOCard*[colorAmount * numberAmount];
    int index = 0;
    for (int i = 0; i < colorAmount; i++) {
        for (int j = 0; j < numberAmount; j++) {
            cards[index] = new UNOCard(j, static_cast<UNOCardColor>(i));
            index++;
        }
    }
}

UNODeck::~UNODeck() {
    for (int i = 0; i < colorAmount * numberAmount; i++) {
        delete cards[i];
    }
}

void UNODeck::shuffle() {
    // Shuffle the deck
    for (int i = 0; i < colorAmount * numberAmount; i++) {
        int randomIndex = rand() % (colorAmount * numberAmount);
        UNOCard* temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

UNOCard* UNODeck::drawCard() {
    // Draw a card from the deck
    UNOCard* card = cards[0];
    for (int i = 0; i < (colorAmount * numberAmount) - 1; i++) {
        cards[i] = cards[i + 1];
    }
    cards[(colorAmount * numberAmount) - 1] = nullptr;
    return card;
}