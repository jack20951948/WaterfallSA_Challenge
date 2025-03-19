#include "Coordinate.hpp"

Coordinate::Coordinate(int x, int y) {
    setX(x);
    setY(y);
}

int Coordinate::getX() {
    return this->x;
}

int Coordinate::getY() {
    return this->y;
}

void Coordinate::setX(int x) {
    this->x = x;
}

void Coordinate::setY(int y) {
    this->y = y;
}