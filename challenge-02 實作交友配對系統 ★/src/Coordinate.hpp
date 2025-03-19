#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
public:
    Coordinate(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
private:
    int x;
    int y;
};

#endif // COORDINATE_H