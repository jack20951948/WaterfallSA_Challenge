#include "ShowdownDeck.h"

void ShowdownDeck::createDeck() {
    std::vector<CardSuit> suits = {
        CardSuit::SPADE,
        CardSuit::HEART,
        CardSuit::DIAMOND,
        CardSuit::CLUB,
    };
    std::vector<CardRank> ranks = {
        CardRank::ACE,
        CardRank::TWO,
        CardRank::THREE,
        CardRank::FOUR,
        CardRank::FIVE,
        CardRank::SIX,
        CardRank::SEVEN,
        CardRank::EIGHT,
        CardRank::NINE,
        CardRank::TEN,
        CardRank::JACK,
        CardRank::QUEEN,
        CardRank::KING,
    };
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            cards.push_back(std::make_unique<PokerCard>(rank, suit));
        }
    }
}