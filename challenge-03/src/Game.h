#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include <iostream>

template <typename T>
class Game {
    protected:
        std::vector<std::unique_ptr<Player<T>>> players;
        std::unique_ptr<Deck> deck;
    public:
        virtual ~Game() = default;
        void playGame() {
            prepareGame();
            startGame();
        }
        void setPlayers(std::vector<std::unique_ptr<Player<T>>> players) {
            this->players = std::move(players);
        }
        void prepareGame() {
            if (this->initHandCards < 1) {
                throw "Please setup players' init hand card amount!";
            }
            for (auto& player : players) {
                player->setName();
            }
            createDeck();
            deck->shuffle();
            for (auto& player : players) {
                for (int i = 0; i < this->initHandCards; ++i) {
                    player->addCardToHand(deck->drawCard());
                }
            }
        }
        void showWinner(std::unique_ptr<Player<T>> winner) {
            std::cout << "The winner is: " << winner->getName() << std::endl;
        }
    protected:
        virtual void startGame() = 0;
        virtual void createDeck() = 0;
        int initHandCards = 0;
    };

#endif // GAME_H
