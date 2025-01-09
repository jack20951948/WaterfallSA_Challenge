// Date: 2025-01-08
#include <iostream>
#include "Individual.hpp"
using namespace std;

int main() {
    cout << "Hello, World!";
    Individual individual(Gender::MALE, 18, "Hello World", vector<string>{"Reading", "Coding"}, Coordinate(0, 0));
    return 0;
}
