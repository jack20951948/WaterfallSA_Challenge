#include "Deck.h"
#include "Card.h"

Deck::Deck(int rankAmount, int suitAmount) {
    // Create a deck of cards
    cards = new Card*[suitAmount * rankAmount];
    int index = 0;
    for (int i = 0; i < suitAmount; i++) {
        for (int j = 0; j < rankAmount; j++) {
            cards[index] = new Card(static_cast<CardRank>(j), static_cast<CardSuit>(i));
            index++;
        }
    }
}

Deck::~Deck() {
    for (int i = 0; i < suitAmount * rankAmount; i++) {
        delete cards[i];
    }
}

void Deck::shuffle() {
    // Shuffle the deck
    for (int i = 0; i < suitAmount * rankAmount; i++) {
        int randomIndex = rand() % (suitAmount * rankAmount);
        Card* temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

Card* Deck::drawCard() {
    // Draw a card from the deck
    Card* card = cards[0];
    for (int i = 0; i < (suitAmount * rankAmount) - 1; i++) {
        cards[i] = cards[i + 1];
    }
    cards[(suitAmount * rankAmount) - 1] = nullptr;
    return card;
}