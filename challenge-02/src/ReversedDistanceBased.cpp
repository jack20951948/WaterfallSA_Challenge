#include "ReversedDistanceBased.hpp"

Individual ReversedDistanceBased::Match(Individual individual, vector<Individual>& individuals) {
    // Find the geo farthest individual to the given individual (x ^ 2 + y ^ 2)
    Individual farthestIndividual = individuals[0];
    double x1 = individual.getCoord().getX();
    double y1 = individual.getCoord().getY();
    double x2 = farthestIndividual.getCoord().getX();
    double y2 = farthestIndividual.getCoord().getY();
    double maxDistance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    for (int i = 1; i < individuals.size(); i++) {
        x2 = individuals[i].getCoord().getX();
        y2 = individuals[i].getCoord().getY();
        double distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (distance > maxDistance && individuals[i].getId() != individual.getId()) {
            maxDistance = distance;
            farthestIndividual = individuals[i];
        }
    }
    return farthestIndividual;
}