#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <vector>
#include "Gender.hpp"
#include "Coordinate.hpp"

using namespace std;

class Individual {
public:
    Individual(Gender gender, int age, string intro, vector<string> habits, Coordinate coord);
    int getId();
    Gender getGender();
    int getAge();
    string getIntro();
    vector<string> getHabits();
    Coordinate getCoord();
    void setGender(Gender gender);
    void setAge(int age);
    void setIntro(string intro);
    void setHabits(vector<string> habits);
    void setCoord(Coordinate coord);
private:
    int id;
    Gender gender;
    int age;
    string intro;
    vector<string> habits;
    Coordinate coord;
};

#endif // INDIVIDUAL_H