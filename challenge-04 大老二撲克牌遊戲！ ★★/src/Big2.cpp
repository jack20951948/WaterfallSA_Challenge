#include "Big2.hpp"

// Big2::Big2(/* args */)
// {
//     // Create a chain of responsibility for card pattern handlers
//     patternHandler = 
//         new FullHousePatternHandler(
//             new StraightPatternHandler(
//                 new PairPatternHandler(
//                     new SinglePatternHandler()
//                 )
//             )
//         );

//     // Create a chain of responsibility for card pattern compared handlers
//     comparedHandler = 
//         new FullHousePatternComparedHandler(
//             new StraightPatternComparedHandler(
//                 new PairPatternComparedHandler(
//                     new SinglePatternComparedHandler()
//                 )
//             )
//         );
// }

// Big2::~Big2()
// {
//     // Destructor implementation
//     delete patternHandler;
//     delete comparedHandler;
// }

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

// CardPattern Big2::isValidPattern(const vector<Card>& cards) {
//     if (patternHandler) {
//         return patternHandler->isValidPattern(cards);
//     }
//     return CardPattern::UNSUPPORTED;
// }

CardPattern* Big2::isValidPattern(const vector<Card>& cards) {
    if (cardPatternHandler) {
        return cardPatternHandler->isValidPattern(cards);
    }
    return nullptr;
}

bool Big2::isBiggerThanTopPlay(const vector<Card>& cards) {
    if (topPlayCardPattern) {
        return topPlayCardPattern->isFrontGreater(cards, topPlay);
    }
    return false;
}

bool Big2::hasClub3(vector<Card>& cards) const {
    for (const auto& card : cards) {
        if (card.getRank() == Rank::THREE && card.getSuit() == Suit::CLUBS) {
            return true;
        }
    }
    return false;
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
        // first round
        if (round == 0 && getTopPlay().empty()) {
            cout << "新的回合開始了。" << endl;
            for (int i = 0; i < 4; ++i) {
                if (players[i].hasClub3()) {
                    setTopPlayerIndex(i);
    
                }
            }
        }

        // if pass count is 3, reset the pass count
        if (passCount == 3) {
            passCount = 0;
            // reset the top play
            topPlay.clear();
            round++;
            cout << "新的回合開始了。" << endl;
        }

        if (getTopPlay().empty()) {
            currentPlayerIndex = getTopPlayerIndex();
        }

        // player turn
        Player& currentPlayer = players[currentPlayerIndex];
        cout << "輪到" << currentPlayer.getName() << "了" << endl;
        currentPlayer.showHand();

        vector<Card> playedCards;

        bool isPass = false;
        do {
            vector<int> indices;
            int index;

            while (true) {
                cin >> index;
                if (index == -1) {
                    if (topPlay.empty()) {
                        cout << "你不能在新的回合中喊 PASS" << endl;
                        continue;
                    }
                    // player pass
                    passCount++;
                    isPass = true;
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
            if(isPass) {
                break;
            }
            // check if the player has played cards
            playedCards = currentPlayer.play(indices);
            topPlayCardPattern = isValidPattern(playedCards);
            if (topPlayCardPattern == nullptr || topPlayCardPattern->getPatternName() == "Unsupported") {
                cout << "此牌型不合法，請再嘗試一次。" << endl;
                for (const auto& card : playedCards) {
                    currentPlayer.dealCard(card);
                }
                currentPlayer.sortHandCards();
                playedCards.clear();
                continue;
            }
            if (round == 0 && getTopPlay().empty() && !hasClub3(playedCards)) {
                cout << "此牌型不合法，請再嘗試一次。" << endl;
                for (const auto& card : playedCards) {
                    currentPlayer.dealCard(card);
                }
                currentPlayer.sortHandCards();
                playedCards.clear();
                continue;
            }

            if (!getTopPlay().empty() && !isBiggerThanTopPlay(playedCards)) {
                cout << "此牌型不合法，請再嘗試一次。" << endl;
                for (const auto& card : playedCards) {
                    currentPlayer.dealCard(card);
                }
                currentPlayer.sortHandCards();
                playedCards.clear();
                continue;
            }
            break;
        } while (true);
        
        if (!isPass) {
            cout << "玩家 " << currentPlayer.getName() << " 打出了 " << topPlayCardPattern->getPatternName() << " ";
            for (const auto& card : playedCards) {
                cout << card.toString() << " ";
            }
            cout << endl;
            if(getTopPlay().empty()) {
                setTopPlay(playedCards);
                setTopPlayerIndex(currentPlayerIndex);
            } else {
                if (isBiggerThanTopPlay(playedCards)) {
                    setTopPlay(playedCards);
                    setTopPlayerIndex(currentPlayerIndex);
                }
            }
        }


        if (currentPlayer.isHandCardEmpty()) {
            cout << "遊戲結束，遊戲的勝利者為 " << currentPlayer.getName() << endl;
            break;
        }



        currentPlayerIndex = (currentPlayerIndex + 1) % 4;
    }

}