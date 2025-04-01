#include "StraightPatternHandler.hpp"
#include <set>

bool compare(const Card& a, const Card& b) {
    if (a.getRank() != b.getRank()) {
        return a.getRank() < b.getRank();
    }
    return a.getSuit() < b.getSuit();
}

CardPattern StraightPatternHandler::isValidPattern(const vector<Card>& cards) {
    if (cards.size() < 5) {
        return nextHandler ? nextHandler->isValidPattern(cards) : CardPattern::UNSUPPORTED;
    }

    // Sort the cards based on rank
    vector<Card> sortedCards = cards;
    std::sort(sortedCards.begin(), sortedCards.end(), compare);

    // Check for regular straight pattern
    bool isRegularStraight = true;
    for (size_t i = 1; i < sortedCards.size(); ++i) {
        if (static_cast<int>(sortedCards[i].getRank()) != static_cast<int>(sortedCards[i - 1].getRank()) + 1) {
            isRegularStraight = false;
            break;
        }
    }

    if (isRegularStraight) {
        return CardPattern::STRAIGHT;
    }

    // Check for special wrap-around straight patterns like Q, K, A, 2, 3
    // Create a set of ranks for efficient lookup
    std::set<Rank> rankSet;
    for (const auto& card : sortedCards) {
        rankSet.insert(card.getRank());
    }

    // Check for the specific pattern: Q, K, A, 2, 3
    if (rankSet.size() == 5 && 
        rankSet.count(Rank::QUEEN) && 
        rankSet.count(Rank::KING) && 
        rankSet.count(Rank::ACE) && 
        rankSet.count(Rank::TWO) && 
        rankSet.count(Rank::THREE)) {
        return CardPattern::STRAIGHT;
    } else if (rankSet.size() == 5 && 
        rankSet.count(Rank::KING) &&
        rankSet.count(Rank::ACE) &&
        rankSet.count(Rank::TWO) &&
        rankSet.count(Rank::THREE) &&
        rankSet.count(Rank::FOUR)) {
        return CardPattern::STRAIGHT;
    } else if (rankSet.size() == 5 &&
        rankSet.count(Rank::ACE) &&
        rankSet.count(Rank::TWO) &&
        rankSet.count(Rank::THREE) &&
        rankSet.count(Rank::FOUR) &&
        rankSet.count(Rank::FIVE)) {
        return CardPattern::STRAIGHT;
    } else if (rankSet.size() == 5 &&
        rankSet.count(Rank::TWO) &&
        rankSet.count(Rank::THREE) &&
        rankSet.count(Rank::FOUR) &&
        rankSet.count(Rank::FIVE) &&
        rankSet.count(Rank::SIX)) {
        return CardPattern::STRAIGHT;
    }

    return nextHandler ? nextHandler->isValidPattern(cards) : CardPattern::UNSUPPORTED;
}