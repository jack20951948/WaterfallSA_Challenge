#include "Deck.hpp"

Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
}

Deck::~Deck() {
    // No dynamic memory allocation, so nothing to clean up
    // The vector will automatically clean up its contents
    // when it goes out of scope
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::deal() {
    if (isEmpty()) {
        throw std::out_of_range("No cards left in the deck");
    }
    // Deal the top card
    Card dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}

bool Deck::isEmpty() const {
    return cards.empty();
}

void Deck::printDeck() const {
    for (const auto& card : cards) {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;
}