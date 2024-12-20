#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    // Create a deck of 52 cards
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[index] = new Card(static_cast<CardRank>(j), static_cast<CardSuit>(i));
            index++;
        }
    }
}

Deck::~Deck() {
    for (int i = 0; i < 52; i++) {
        delete cards[i];
    }
}

void Deck::shuffle() {
    // Shuffle the deck
    for (int i = 0; i < 52; i++) {
        int randomIndex = rand() % 52;
        Card* temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

Card* Deck::drawCard() {
    // Draw a card from the deck
    Card* card = cards[0];
    for (int i = 0; i < 51; i++) {
        cards[i] = cards[i + 1];
    }
    cards[51] = nullptr;
    return card;
}