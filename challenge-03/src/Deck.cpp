#include "Deck.h"

Deck::Deck(int numberAmount, int colorAmount) {
    // Create a deck of cards
    cardLeft = colorAmount * numberAmount;
    cards = new Card*[cardLeft];
    int index = 0;
    for (int i = 0; i < colorAmount; i++) {
        for (int j = 0; j < numberAmount; j++) {
            cards[index] = createCard(j, i);
            index++;
        }
    }
}

Deck::~Deck() {
    for (int i = 0; i < cardLeft; i++) {
        delete cards[i];
    }
}

void Deck::shuffle() {
    // Shuffle the deck
    for (int i = 0; i < cardLeft; i++) {
        int randomIndex = rand() % (cardLeft);
        Card* temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

Card* Deck::drawCard() {
    // Draw a card from the deck
    if (cardLeft == 0) {
        return nullptr;
    }
    Card* card = cards[0];
    for (int i = 0; i < (cardLeft) - 1; i++) {
        cards[i] = cards[i + 1];
    }
    cards[(cardLeft) - 1] = nullptr;
    cardLeft--;
    return card;
}

void Deck::addCards(Card** cards, int amount) {
    Card** temp = new Card*[cardLeft];
    for (int i = 0; i < cardLeft; i++) {
        temp[i] = this->cards[i];
    }
    delete[] this->cards;
    this->cards = new Card*[cardLeft + amount];
    for (int i = 0; i < cardLeft; i++) {
        this->cards[i] = temp[i];
    }
    for (int i = 0; i < amount; i++) {
        this->cards[cardLeft + i] = cards[i];
    }
    cardLeft += amount;
}