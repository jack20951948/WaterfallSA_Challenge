# include "UNOPlayer.h"

bool UNOPlayer::checkWin() {
    return hand.empty();
}

bool UNOPlayer::checkAnyValidCard(std::unique_ptr<UNOCard>& card) {
    for (const auto& handCard : hand) {
        UNOCard* handUNOCard = dynamic_cast<UNOCard*>(handCard.get());
        if (handUNOCard && (handUNOCard->getNumber() == card->getNumber() || handUNOCard->getColor() == card->getColor())) {
            return true;
        }
    }
    return false;
}