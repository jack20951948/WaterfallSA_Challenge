#include "Card.h"

Card::Card(CardRank rank, CardSuit suit) {
    this->rank = rank;
    this->suit = suit;
}

Card::~Card() {
    std::cout << "Card destructor" << std::endl;
}

std::string Card::getRankString() {
    switch (static_cast<int>(rank)) {
    case static_cast<int>(CardRank::TWO):
        return "2";
    case static_cast<int>(CardRank::THREE):
        return "3";
    case static_cast<int>(CardRank::FOUR):
        return "4";
    case static_cast<int>(CardRank::FIVE):
        return "5";
    case static_cast<int>(CardRank::SIX):
        return "6";
    case static_cast<int>(CardRank::SEVEN):
        return "7";
    case static_cast<int>(CardRank::EIGHT):
        return "8";
    case static_cast<int>(CardRank::NINE):
        return "9";
    case static_cast<int>(CardRank::TEN): 
        return "10";
    case static_cast<int>(CardRank::JACK):
        return "J";
    case static_cast<int>(CardRank::QUEEN):
        return "Q";
    case static_cast<int>(CardRank::KING):
        return "K";
    case static_cast<int>(CardRank::ACE):
        return "A";
    
    default:
        return " ";
    }
}

std::string Card::getSuitString() {
    switch (static_cast<int>(suit)) {
    case static_cast<int>(CardSuit::CLUB):
        return "CLUB";
    case static_cast<int>(CardSuit::DIAMOND):
        return "DIAMOND";
    case static_cast<int>(CardSuit::HEART):
        return "HEART";
    case static_cast<int>(CardSuit::SPADE):
        return "SPADE";

    // This default case is added to avoid compilation error
    default:
        return " ";
    }
}

CardRank Card::getRank() {
    return rank;
}

CardSuit Card::getSuit() {
    return suit;
}