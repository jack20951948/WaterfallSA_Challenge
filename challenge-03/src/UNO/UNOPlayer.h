#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H

#include "../Player.h"
#include "UNOCard.h"
#include <iostream>

class UNOPlayer : public Player<UNOCard> {
public:
    bool checkWin();
    bool checkAnyValidCard(std::unique_ptr<UNOCard>& card);
};

#endif // UNO_PLAYER_H
