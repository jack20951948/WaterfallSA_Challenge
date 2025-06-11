#ifndef BIG2_HPP
#define BIG2_HPP
#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "SingleCardPattern.hpp"
#include "PairCardPattern.hpp"
#include "FullHouseCardPattern.hpp"
#include "StraightCardPattern.hpp"

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
    CardPattern* cardPatternHandler;
    CardPattern* topPlayCardPattern;
public:
    Big2(CardPattern* handler) : cardPatternHandler(handler) { topPlayCardPattern = nullptr; } // Constructor to set the card pattern handler
    // ~Big2();
    void start();
    void setTopPlay(const vector<Card>& play);
    vector<Card> getTopPlay() const { return topPlay; }
    void setTopPlayerIndex(int index);
    int getTopPlayerIndex() const { return topPlayerIndex; }
    void setPassCount(int count);
    int getPassCount() const { return passCount; }
    bool hasClub3(vector<Card>& cards) const;
    CardPattern* isValidPattern(const vector<Card>& cards);
    bool isBiggerThanTopPlay(const vector<Card>& cards);
};

#endif // BIG2_HPP