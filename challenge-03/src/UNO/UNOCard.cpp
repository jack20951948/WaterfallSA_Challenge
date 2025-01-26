#include "UNOCard.h"

UNOCard::UNOCard(int number, UNOCardColor suit) {
    setNumber(number);
    setSuit(suit);
}

UNOCard::~UNOCard() {
    std::cout << "Card destructor" << std::endl;
}

std::string UNOCard::getSuitString() {
    switch (static_cast<int>(suit)) {
    case static_cast<int>(UNOCardColor::BLUE):
        return "BLUE";
    case static_cast<int>(UNOCardColor::RED):
        return "RED";
    case static_cast<int>(UNOCardColor::YELLOW):
        return "YELLOW";
    case static_cast<int>(UNOCardColor::GREEN):
        return "GREEN";

    // This default case is added to avoid compilation error
    default:
        return " ";
    }
}

int UNOCard::getNumber() {
    return number;
}

void UNOCard::setNumber(int number) {
    if (number < 0 || number > 9) {
        throw "Invalid number";
    }
    this->number = number;
}

UNOCardColor UNOCard::getSuit() {
    return suit;
}

void UNOCard::setSuit(UNOCardColor suit) {
    this->suit = suit;
}