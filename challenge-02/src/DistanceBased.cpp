#include "DistanceBased.hpp"

Individual DistanceBased::Match(Individual individual, vector<Individual>& individuals) {
    // Find the geo closest individual to the given individual (x ^ 2 + y ^ 2)
    Individual closestIndividual = individuals[0];
    double x1 = individual.getCoord().getX();
    double y1 = individual.getCoord().getY();
    double x2 = closestIndividual.getCoord().getX();
    double y2 = closestIndividual.getCoord().getY();
    double minDistance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    for (int i = 1; i < individuals.size(); i++) {
        x2 = individuals[i].getCoord().getX();
        y2 = individuals[i].getCoord().getY();
        double distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (distance < minDistance && individuals[i].getId() != individual.getId()) {
            minDistance = distance;
            closestIndividual = individuals[i];
        }
    }
    return closestIndividual;
}