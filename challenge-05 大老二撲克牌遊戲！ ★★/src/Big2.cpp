#include "Big2.hpp"

Big2::Big2(/* args */)
{
    // Constructor implementation
}

Big2::~Big2()
{
    // Destructor implementation
}

void Big2::setTopPlayerIndex(int index) {
    topPlayerIndex = index;
}

void Big2::setTopPlay(const vector<Card>& play) {
    topPlay = play;
}

void Big2::setPassCount(int count) {
    if (count < 0 || count > 3) {
        throw std::out_of_range("Pass count must be between 0 and 3");
    }
    passCount = count;
}

CardPattern Big2::isValidPattern(const vector<Card>& cards) {
    if (patternHandler) {
        return patternHandler->isValidPattern(cards);
    }
    return CardPattern::UNSUPPORTED;
}

void Big2::start() {
    // Add game logic here
    deck.shuffle();
    deck.printDeck(); // Print the shuffled deck

    //set up players
    for (int i = 0; i < 4; ++i) {
        std::string playerName;
        std::cin >> playerName;
        players.emplace_back(playerName);
    }
    for (int i = 0; i < 52; ++i) {
        players[i % 4].dealCard(deck.deal());
    }
    for (auto& player : players) {
        player.sortHandCards();
    }

    // Game loop
    while (true) {
        cout << "新的回合開始了。" << endl;
        // first round
        if (round == 0) {
            for (int i = 0; i < 4; ++i) {
                if (players[i].hasClub3()) {
                    setTopPlayerIndex(i);
    
                }
            }
        }

        currentPlayerIndex = (topPlayerIndex + 1) % 4;

        // if pass count is 3, reset the pass count
        if (passCount == 3) {
            passCount = 0;
            currentPlayerIndex = topPlayerIndex;
            // reset the top play
            topPlay.clear();
        }

        // player turn
        Player& currentPlayer = players[currentPlayerIndex];
        cout << "輪到" << currentPlayer.getName() << "了" << endl;
        currentPlayer.showHand();
        vector<int> indices;
        int index;
        while (true) {
            cin >> index;
            if (index == -1) {
                // player pass
                passCount++;
                cout << "玩家 " << currentPlayer.getName() << " PASS." << endl;
                break;
            } else if (index >= 0 && index < currentPlayer.getHandCardAmount()) {
                indices.push_back(index);
            } else {
                cout << "無效的索引，請重新輸入：" << endl;
                continue;
            }
            if (cin.peek() == '\n') {
                break;
            }
        }
        // check if the player has played cards


        vector<Card> playedCards = currentPlayer.play(indices);
        cout << "玩家 " << currentPlayer.getName() << " 打出了 " << "<牌型>" << " ";
        for (const auto& card : playedCards) {
            cout << card.toString() << " ";
        }
        cout << endl;


    }

}