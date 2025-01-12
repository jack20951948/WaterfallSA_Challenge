#ifndef HabitBased_H
#define HabitBased_H

#include "IMatchmakingStrategy.hpp"

class HabitBased : public IMatchmakingStrategy {
public:
    Individual Match(Individual individual, vector<Individual>& individuals) override;
};

#endif // HabitBased_H