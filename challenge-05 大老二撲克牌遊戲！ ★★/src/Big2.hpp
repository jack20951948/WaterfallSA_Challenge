#ifndef BIG2_HPP
#define BIG2_HPP
#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"

class Big2
{
private:
    vector<Player> players; // Vector to hold players
    Deck deck; // Deck of cards
    int round = 0; // Current round number
    int currentPlayerIndex; // Index of the current player
    vector<Card> topPlay;
    int topPlayerIndex;
    int passCount = 0;
public:
    Big2(/* args */);
    ~Big2();
    void start();
    void setTopPlay(const vector<Card>& play);
    vector<Card> getTopPlay() const { return topPlay; }
    void setTopPlayerIndex(int index);
    int getTopPlayerIndex() const { return topPlayerIndex; }
    void setPassCount(int count);
    int getPassCount() const { return passCount; }
};

#endif // BIG2_HPP