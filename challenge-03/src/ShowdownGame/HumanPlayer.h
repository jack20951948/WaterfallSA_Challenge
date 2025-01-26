#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    void makeDecision() override;
    void setName() override;
};

#endif // HUMANPLAYER_H
