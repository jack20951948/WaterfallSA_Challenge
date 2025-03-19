#ifndef DistanceBased_H
#define DistanceBased_H

#include "IMatchmakingStrategy.hpp"

class DistanceBased : public IMatchmakingStrategy {
public:
    Individual Match(Individual individual, vector<Individual>& individuals) override;
};

#endif // DistanceBased_H