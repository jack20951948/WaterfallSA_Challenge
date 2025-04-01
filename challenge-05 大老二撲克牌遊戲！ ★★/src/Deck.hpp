#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Card.hpp"

using namespace std;

class Deck
{
private:
    vector<Card> cards; // Vector to hold the cards
public:
    Deck();
    ~Deck();
    void shuffle(); // Shuffle the deck
    Card deal(); // Deal a card
    bool isEmpty() const; // Check if the deck is empty
    void printDeck() const; // Print the deck for debugging}
};

#endif // DECK_HPP