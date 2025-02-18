#include "UNODeck.h"

void UNODeck::createDeck() {
    std::vector<UNOCardColor> colors = {UNOCardColor::RED, UNOCardColor::BLUE, UNOCardColor::GREEN, UNOCardColor::YELLOW};
    for (const auto& color : colors) {
        for (int number = 0; number <= 9; ++number) {
            cards.push_back(std::make_unique<UNOCard>(color, number));
        }
    }
}