#ifndef MATCHMAKINGSYSTEM_H
#define MATCHMAKINGSYSTEM_H

#include "Individual.hpp"
#include "IMatchmakingStrategy.hpp"
#include <vector>

using namespace std;
class MatchmakingSystem {
public:
    Individual Match(Individual individual);
    void AddUser(Individual individual);
    void SetStrategy(IMatchmakingStrategy *pStrategy);
    MatchmakingSystem();
    MatchmakingSystem(IMatchmakingStrategy *pStrategy);
private:
    vector<Individual> individuals;
    IMatchmakingStrategy *pStrategy;
};

#endif // MATCHMAKINGSYSTEM_H