#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <iostream>

template <typename T>
class Player {
protected:
    std::string name;
    std::vector<std::unique_ptr<T>> hand;
public:
    virtual ~Player() = default;
    virtual std::unique_ptr<T> makeDecision() = 0;
    virtual void setName() = 0;
    std::string getName() { return name; }
    void addCardToHand(std::unique_ptr<T> card) {
        hand.push_back(std::move(card));
    }
    void printHand() {
        for (const auto& card : hand) {
            card->printCard();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    bool checkWin() { return hand.empty(); }
};

#endif // PLAYER_H
