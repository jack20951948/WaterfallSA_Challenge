#include "FullHouseCardPattern.hpp"
#include <map>

CardPattern* FullHouseCardPattern::isValidPattern(const vector<Card>& cards) {
    if (cards.size() != 5) {
        return nextHandler->isValidPattern(cards);
    }

    // Count the occurrences of each rank
    std::map<Rank, int> rankCount;
    for (const auto& card : cards) {
        rankCount[card.getRank()]++;
    }

    // Check for a full house pattern (3 of one rank and 2 of another)
    if (rankCount.size() == 2 && 
        ((rankCount.begin()->second == 3 && std::next(rankCount.begin())->second == 2) || 
            (rankCount.begin()->second == 2 && std::next(rankCount.begin())->second == 3))) {
        return this;
    } else {
        return nextHandler->isValidPattern(cards);
    }
}

bool FullHouseCardPattern::isFrontGreater(const vector<Card>& cards1, const vector<Card>& cards2) {
    if (cards1.size() != 5 || cards2.size() != 5) {
        throw std::invalid_argument("Both card sets must contain exactly five cards.");
    }

    // Count the occurrences of each rank
    std::map<Rank, int> rankCount1;
    std::map<Rank, int> rankCount2;
    for (const auto& card : cards1) {
        rankCount1[card.getRank()]++;
    }
    for (const auto& card : cards2) {
        rankCount2[card.getRank()]++;
    }

    // Find the rank of the three of a kind and the pair
    Rank threeOfAKindRank1, threeOfAKindRank2;
    Rank pairRank1, pairRank2;

    for (const auto& entry : rankCount1) {
        if (entry.second == 3) {
            threeOfAKindRank1 = entry.first;
        } else if (entry.second == 2) {
            pairRank1 = entry.first;
        }
    }

    for (const auto& entry : rankCount2) {
        if (entry.second == 3) {
            threeOfAKindRank2 = entry.first;
        } else if (entry.second == 2) {
            pairRank2 = entry.first;
        }
    }

    // Compare the ranks of the three of a kind first
    if (threeOfAKindRank1 != threeOfAKindRank2) {
        return threeOfAKindRank1 > threeOfAKindRank2;
    }

    // If the three of a kind ranks are equal, compare the pairs
    return pairRank1 > pairRank2;
}