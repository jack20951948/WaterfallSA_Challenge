#include "ExchangedCardDetail.h"

int ExchangedCardDetail::getRoundLeft() {
    return roundLeft;
}

void ExchangedCardDetail::setRoundLeft(int roundLeft) {
    if (roundLeft < 0) {
        throw "Round left cannot be negative";
    }
    if (roundLeft > 3) {
        throw "Round left cannot be greater than 3";
    }
    this->roundLeft = roundLeft;
}

bool ExchangedCardDetail::isExchanger() {
    return isTheExchanger;
}

void ExchangedCardDetail::setExchanger(bool exchanged) {
    isTheExchanger = exchanged;
}

ExchangedCardDetail::ExchangedCardDetail() {
    setRoundLeft(3);
    setExchanger(false);
}