#ifndef BIG2_HPP
#define BIG2_HPP
#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "CardPatternHandler.hpp"
#include "FullHousePatternHandler.hpp"
#include "StraightPatternHandler.hpp"
#include "PairPatternHandler.hpp"
#include "SinglePatternHandler.hpp"
#include "CardPatternComparedHandler.hpp"
#include "SinglePatternComparedHandler.hpp"
#include "PairPatternComparedHandler.hpp"
#include "FullHousePatternComparedHandler.hpp"
#include "StraightPatternComparedHandler.hpp"

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
    CardPatternHandler* patternHandler; // Handler for card patterns
    CardPatternComparedHandler* comparedHandler; // Handler for comparing card patterns
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
    bool hasClub3(vector<Card>& cards) const;
    CardPattern isValidPattern(const vector<Card>& cards);
    bool isBiggerThanTopPlay(const vector<Card>& cards, CardPattern pattern);
};

#endif // BIG2_HPP