// Date: 2024-12-19
#include <iostream>
#include "Big2.hpp"
#include "FullHouseCardPattern.hpp"
#include "StraightCardPattern.hpp"
#include "PairCardPattern.hpp"
#include "SingleCardPattern.hpp"
#include "UnsupportedCardPattern.hpp"
using namespace std;

int main() {
    // Create a chain of responsibility for card pattern handlers
    CardPattern* patternHandler = 
        new FullHouseCardPattern(
            new StraightCardPattern(
                new PairCardPattern(
                    new SingleCardPattern(
                        new UnsupportedCardPattern()
                    )
                )
            )
        );
    Big2 game(patternHandler); // Create a Big2 game instance with the pattern handler
    game.start();
    return 0;
}
