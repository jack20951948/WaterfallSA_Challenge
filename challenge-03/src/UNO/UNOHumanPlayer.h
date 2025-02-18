#ifndef UNO_HUMANPLAYER_H
#define UNO_HUMANPLAYER_H

#include "UNOPlayer.h"

class UNOHumanPlayer : public UNOPlayer {
public:
    std::unique_ptr<UNOCard> makeDecision() override;
    void setName() override;
};

#endif // UNO_HUMANPLAYER_H
