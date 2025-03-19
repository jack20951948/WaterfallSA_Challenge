#ifndef SHOWDOWN_HUMAN_PLAYER_H
#define SHOWDOWN_HUMAN_PLAYER_H

#include "ShowdownPlayer.h"

class ShowdownHumanPlayer : public ShowdownPlayer {
public:
    std::unique_ptr<PokerCard> makeDecision() override;
    void setName() override;
};

#endif // SHOWDOWN_HUMAN_PLAYER_H
