#include "ShowdownDeck.h"
#include "Card.h"

Card* ShowdownDeck::createCard(int rank, int suit) {
    return new PokerCard(static_cast<CardRank>(rank), static_cast<CardSuit>(suit));
}