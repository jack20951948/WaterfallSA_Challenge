#include "StraightCardPattern.hpp"
#include <set>

CardPattern* StraightCardPattern::isValidPattern(const vector<Card>& cards) {
    if (cards.size() < 5) {
        return nextHandler->isValidPattern(cards);
    }

    // Sort the cards based on rank
    vector<Card> sortedCards = cards;
    std::sort(sortedCards.begin(), sortedCards.end(), [](const Card& a, const Card& b) {
        return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
    });

    // Check for regular straight pattern
    bool isRegularStraight = true;
    for (size_t i = 1; i < sortedCards.size(); ++i) {
        if (static_cast<int>(sortedCards[i].getRank()) != static_cast<int>(sortedCards[i - 1].getRank()) + 1) {
            isRegularStraight = false;
            break;
        }
    }

    if (isRegularStraight) {
        return this;
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
        return this;
    } else if (rankSet.size() == 5 && 
        rankSet.count(Rank::KING) &&
        rankSet.count(Rank::ACE) &&
        rankSet.count(Rank::TWO) &&
        rankSet.count(Rank::THREE) &&
        rankSet.count(Rank::FOUR)) {
        return this;
    } else if (rankSet.size() == 5 &&
        rankSet.count(Rank::ACE) &&
        rankSet.count(Rank::TWO) &&
        rankSet.count(Rank::THREE) &&
        rankSet.count(Rank::FOUR) &&
        rankSet.count(Rank::FIVE)) {
        return this;
    } else if (rankSet.size() == 5 &&
        rankSet.count(Rank::TWO) &&
        rankSet.count(Rank::THREE) &&
        rankSet.count(Rank::FOUR) &&
        rankSet.count(Rank::FIVE)) {
        return this;
    }

    return nextHandler->isValidPattern(cards);
}

bool StraightCardPattern::isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) {
    if (cards1.size() != 5 || cards2.size() != 5) {
        throw std::invalid_argument("Both card sets must contain exactly five cards.");
    }
    // Sort the cards based on rank
    std::vector<Card> sortedCards1 = cards1;
    std::vector<Card> sortedCards2 = cards2;
    std::sort(sortedCards1.begin(), sortedCards1.end(), [](const Card& a, const Card& b) {
        return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
    });
    std::sort(sortedCards2.begin(), sortedCards2.end(), [](const Card& a, const Card& b) {
        return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
    });
    
    // If the highest cards are equal, compare suits
    if (sortedCards1.back().getRank() == sortedCards2.back().getRank()) {
        return sortedCards1.back().getSuit() > sortedCards2.back().getSuit();
    } else {
        return sortedCards1.back().getRank() > sortedCards2.back().getRank();
    }
}