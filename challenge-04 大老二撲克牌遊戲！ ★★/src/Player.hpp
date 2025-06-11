#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "Card.hpp"

using namespace std;
class Player {
private:
    string name;
    vector<Card> handCards;
    
public:
    Player(string name) : name(name) {}
    ~Player() {}

    string getName() const;
    void setName(const string& newName);
    void showHand() const;
    int getHandCardAmount() const { return handCards.size(); }
    void dealCard(const Card& card);
    void sortHandCards();
    vector<Card> play(const vector<int>& indices);
    bool isHandCardEmpty() const;
    bool hasClub3() const;
};

#endif // PLAYER_HPP