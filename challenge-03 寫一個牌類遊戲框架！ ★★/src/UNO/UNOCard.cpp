#include "UNOCard.h"

UNOCard::UNOCard(UNOCardColor color, int number) {
    setColor(color);
    setNumber(number);
}

std::string UNOCard::getColorString() {
    switch (static_cast<int>(color)) {
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

UNOCardColor UNOCard::getColor() {
    return color;
}

void UNOCard::setColor(UNOCardColor color) {
    this->color = color;
}

void UNOCard::printCard() {
    std::cout << getColorString() << "-" << number;
}