#ifndef ReversedDistanceBased_H
#define ReversedDistanceBased_H

#include "IMatchmakingStrategy.hpp"

class ReversedDistanceBased : public IMatchmakingStrategy {
public:
    Individual Match(Individual individual, vector<Individual>& individuals) override;
};

#endif // ReversedDistanceBased_H