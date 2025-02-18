# include "ShowdownPlayer.h"

ShowdownPlayer::ShowdownPlayer(): Player<PokerCard>() {
    score = 0;
}

PokerCard* ShowdownPlayer::show() {
    return roundCard;
}

int ShowdownPlayer::getScore() {
    return score;
}

void ShowdownPlayer::addScore() {
    if (score <= 13)
        score++;
    else
        throw "Score is out of range";
}