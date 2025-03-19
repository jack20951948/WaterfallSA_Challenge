// Date: 2024-12-19
#include <iostream>
#include "UNO/UNOGame.h"
using namespace std;

int main() {
    cout << "Hello, World!";
    // UNOPlayer* players[4] = {new UNOHumanPlayer(), new UNOAIPlayer(), new UNOAIPlayer(), new UNOAIPlayer()};

    std::vector<std::unique_ptr<Player<UNOCard>>> players;
    players.push_back(std::make_unique<UNOHumanPlayer>());
    players.push_back(std::make_unique<UNOAIPlayer>());
    players.push_back(std::make_unique<UNOAIPlayer>());
    players.push_back(std::make_unique<UNOAIPlayer>());

    
    UNOGame game;

    game.setPlayers(std::move(players));

    game.playGame();

    return 0;
}
