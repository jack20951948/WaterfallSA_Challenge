#ifndef IMATCHMAKINGSTRATEGY_H
#define IMATCHMAKINGSTRATEGY_H

#include "Individual.hpp"

class IMatchmakingStrategy {
public:
    virtual Individual Match(Individual individual, vector<Individual>& individuals) = 0;
};


#endif // IMATCHMAKINGSTRATEGY_H