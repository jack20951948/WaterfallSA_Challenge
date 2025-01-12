#include "MatchmakingSystem.hpp"

Individual MatchmakingSystem::Match(Individual individual) {
    // delegate the matching to the strategy
    return pStrategy->Match(individual, individuals);
}

void MatchmakingSystem::AddUser(Individual individual) {
    // Add individual to the list of individuals
    individuals.push_back(individual);
}

MatchmakingSystem::MatchmakingSystem(IMatchmakingStrategy *pStrategy) {
    this->pStrategy = pStrategy;
}

void MatchmakingSystem::SetStrategy(IMatchmakingStrategy *pStrategy) {
    this->pStrategy = pStrategy;
}