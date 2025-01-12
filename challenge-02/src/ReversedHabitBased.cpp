#include "ReversedHabitBased.hpp"

Individual ReversedHabitBased::Match(Individual individual, vector<Individual>& individuals) {
    // Find the individual with the least similar habits
    Individual similarIndividual = individuals[0];
    vector<string> habits1 = individual.getHabits();
    int minSimilarity = habits1.size();
    for (int i = 0; i < individuals.size(); i++) {
        vector<string> habits2 = individuals[i].getHabits();
        int similarity = 0;
        for (int j = 0; j < habits1.size(); j++) {
            for (int k = 0; k < habits2.size(); k++) {
                if (habits1[j] == habits2[k]) {
                    similarity++;
                }
            }
        }
        if (similarity < minSimilarity && individuals[i].getId() != individual.getId()) {
            minSimilarity = similarity;
            similarIndividual = individuals[i];
        }
    }
    return similarIndividual;
}