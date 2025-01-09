#include "Individual.hpp"

int Individual::getId() {
    return this->id;
}

Gender Individual::getGender() {
    return this->gender;
}

int Individual::getAge() {
    return this->age;
}

string Individual::getIntro() {
    return this->intro;
}

vector<string> Individual::getHabits() {
    return this->habits;
}

Coordinate Individual::getCoord() {
    return this->coord;
}

void Individual::setGender(Gender gender) {
    this->gender = gender;
}

void Individual::setAge(int age) {
    if (age < 18) {
        throw "Age must be greater than or equal to 18";
    } else {
        this->age = age;
    }
}

void Individual::setIntro(string intro) {
    // Check if intro is less than 200 words
    int wordCount = 0;
    for (int i = 0; i < intro.length(); i++) {
        if (intro[i] == ' ') {
            wordCount++;
        }
    }
    if (wordCount >= 200 - 1) {
        throw "Intro must be less than 200 words";
    } else {
        this->intro = intro;
    }
}

void Individual::setHabits(vector<string> habits) {
    // iterate through habits and check if each habit is less than 10 words
    for (int i = 0; i < habits.size(); i++) {
        int wordCount = 0;
        for (int j = 0; j < habits[i].length(); j++) {
            if (habits[i][j] == ' ') {
                wordCount++;
            }
        }
        if (wordCount >= 10 - 1) {
            throw "Each habit must be less than 10 words";
        }
    }
    this->habits = habits;
}

void Individual::setCoord(Coordinate coord) {
    this->coord = coord;
}

Individual::Individual(Gender gender, int age, string intro, vector<string> habits, Coordinate coord)
    : coord(coord) {
    // ues current time as seed for random generator, id is a random integer greater than 0.
    srand(time(0));
    this->id = rand() % 1000 + 1;
    setGender(gender);
    setAge(age);
    setIntro(intro);
    setHabits(habits);
}