#ifndef ReverseHabitBased_H
#define ReverseHabitBased_H

#include "IMatchmakingStrategy.hpp"

class ReversedHabitBased : public IMatchmakingStrategy {
public:
    Individual Match(Individual individual, vector<Individual>& individuals) override;
};

#endif // ReverseHabitBased_H