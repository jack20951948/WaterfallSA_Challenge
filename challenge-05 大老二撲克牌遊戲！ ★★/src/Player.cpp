#include "Player.hpp"

string Player::getName() const {
    return name;
}

void Player::setName(const string& newName) {
    name = newName;
}

void Player::showHand() const {
    for (int i = 0; i < handCards.size(); ++i) {
        cout << i << "    ";
    }
    cout << endl;
    for (const auto& card : handCards) {
        cout << card.toString() << " ";
    }
    cout << endl;
}

void Player::sortHandCards() {
    // Sort the hand cards based on rank and suit
    std::sort(handCards.begin(), handCards.end(), [](const Card& a, const Card& b) {
        if (a.getRank() != b.getRank()) {
            return a.getRank() < b.getRank();
        }
        return a.getSuit() < b.getSuit();
    });
}

void Player::dealCard(const Card& card) {
    handCards.push_back(card);
}

vector<Card> Player::play(const vector<int>& indices) {
    vector<Card> selectedCards;
    for (int index : indices) {
        if (index >= 0 && index < handCards.size()) {
            selectedCards.push_back(Card(handCards[index]));
        }
    }
    // Remove the selected cards from the hand
    for (int i = indices.size() - 1; i >= 0; --i) {
        int index = indices[i];
        if (index >= 0 && index < handCards.size()) {
            handCards.erase(handCards.begin() + index);
        }
    }
    return selectedCards;
}

bool Player::isHandCardEmpty() const {
    return handCards.empty();
}

bool Player::hasClub3() const {
    for (const auto& card : handCards) {
        if (card.getRank() == Rank::THREE && card.getSuit() == Suit::CLUBS) {
            return true;
        }
    }
    return false;
}