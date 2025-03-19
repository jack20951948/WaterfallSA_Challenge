#ifndef UNO_AIPLAYER_H
#define UNO_AIPLAYER_H

#include "UNOPlayer.h"

class UNOAIPlayer : public UNOPlayer {
public:
    std::unique_ptr<UNOCard> makeDecision() override;
    void setName() override;
};

#endif // UNO_AIPLAYER_H
