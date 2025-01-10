#ifndef MATCHMAKINGSYSTEM_H
#define MATCHMAKINGSYSTEM_H

#include "Individual.hpp"
#include <vector>

using namespace std;
class MatchmakingSystem {
public:
    Match(Individual individual);
    AddUser(Individual individual);
private:
    vector<Individual> individuals;
};

#endif // MATCHMAKINGSYSTEM_H