#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {
public:
    UNOCard* makeDecision() override;
    void setName() override;
};

#endif // AIPLAYER_H
