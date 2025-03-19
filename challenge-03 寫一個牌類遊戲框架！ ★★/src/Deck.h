#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>
#include <algorithm>

class Deck {
    protected:
        std::vector<std::unique_ptr<Card>> cards;
    public:
        virtual ~Deck() = default;
        void shuffle() {
            std::random_shuffle(cards.begin(), cards.end());
        }
        std::unique_ptr<Card> drawCard() {
            if (!cards.empty()) {
                auto card = std::move(cards.back());
                cards.pop_back();
                return card;
            }
            return nullptr;
        }
        void addCards(std::vector<std::unique_ptr<Card>> newCards) {
            cards.insert(cards.end(), std::make_move_iterator(newCards.begin()), std::make_move_iterator(newCards.end()));
        }
        virtual void createDeck() = 0;
    };

#endif // DECK_H