#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <vector>
#include "CardRank.hpp"
#include "CardSuit.hpp"

class Card {
private:
    Suit suit;
    Rank rank;
public:
    Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }
    std::string toString() const {
        static const char* suitSymbols[] = { "C", "D", "H", "S" };
        static const char* rankNames[] = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2" };
        return std::string(suitSymbols[static_cast<int>(suit)]) + "[" + rankNames[static_cast<int>(rank)] + "]";
    }  
};

#endif // CARD_HPP