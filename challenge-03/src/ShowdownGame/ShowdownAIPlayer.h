#ifndef SHOWDOWN_AIPLAYER_H
#define SHOWDOWN_AIPLAYER_H

#include "ShowdownPlayer.h"

class ShowdownAIPlayer : public ShowdownPlayer {
public:
    std::unique_ptr<PokerCard> makeDecision() override;
    void setName() override;
};

#endif // SHOWDOWN_AIPLAYER_H
