// Date: 2025-01-08
#include <iostream>
#include "Individual.hpp"
#include "MatchmakingSystem.hpp"
#include "DistanceBased.hpp"
#include "ReversedDistanceBased.hpp"
#include "HabitBased.hpp"
#include "ReversedHabitBased.hpp"

using namespace std;

int main() {
    cout << "Hello, World!\n";
    
    // Create 10 individuals
    Individual David(Gender::MALE, 18, "I am David.", {"Reading", "Coding", "Gaming", "Hiking", "Swimming"}, Coordinate(0, 0));
    Individual Alice(Gender::FEMALE, 20, "I am Alice.", {"Reading", "Swimming", "Dancing", "Cooking", "Painting"}, Coordinate(1, 2));
    Individual Robin(Gender::MALE, 22, "I am Robin.", {"Coding", "Swimming", "Running", "Gaming", "Reading"}, Coordinate(2, 4));
    Individual John(Gender::MALE, 25, "I am John.", {"Running", "Gaming", "Hiking", "Reading", "Swimming"}, Coordinate(3, 6));
    Individual Emma(Gender::FEMALE, 19, "I am Emma.", {"Dancing", "Reading", "Cooking", "Painting", "Swimming"}, Coordinate(4, 8));
    Individual Olivia(Gender::FEMALE, 21, "I am Olivia.", {"Cooking", "Swimming", "Reading", "Dancing", "Hiking"}, Coordinate(5, 10));
    Individual Liam(Gender::MALE, 23, "I am Liam.", {"Hiking", "Coding", "Gaming", "Reading", "Swimming"}, Coordinate(6, 12));
    Individual Sophia(Gender::FEMALE, 24, "I am Sophia.", {"Painting", "Running", "Reading", "Cooking", "Swimming"}, Coordinate(7, 14));
    Individual Noah(Gender::MALE, 26, "I am Noah.", {"Gaming", "Reading", "Hiking", "Swimming", "Coding"}, Coordinate(8, 16));
    Individual Ava(Gender::FEMALE, 22, "I am Ava.", {"Swimming", "Dancing", "Reading", "Cooking", "Painting"}, Coordinate(9, 18));
    Individual William(Gender::MALE, 27, "I am William.", {"Coding", "Hiking", "Gaming", "Reading", "Swimming"}, Coordinate(10, 20));

    // Create a matchmaking system with the DistanceBased strategy
    MatchmakingSystem matchmakingSystem = MatchmakingSystem(new DistanceBased());
    // MatchmakingSystem matchmakingSystem = MatchmakingSystem(new ReversedDistanceBased());
    // MatchmakingSystem matchmakingSystem = MatchmakingSystem(new HabitBased());
    // MatchmakingSystem matchmakingSystem = MatchmakingSystem(new ReversedHabitBased());
    matchmakingSystem.AddUser(David);
    matchmakingSystem.AddUser(Alice);
    matchmakingSystem.AddUser(Robin);
    matchmakingSystem.AddUser(John);
    matchmakingSystem.AddUser(Emma);
    matchmakingSystem.AddUser(Olivia);
    matchmakingSystem.AddUser(Liam);
    matchmakingSystem.AddUser(Sophia);
    matchmakingSystem.AddUser(Noah);
    matchmakingSystem.AddUser(Ava);
    matchmakingSystem.AddUser(William);

    Individual Jack(Gender::MALE, 28, "I am Jack.", {"Coding", "Hiking", "Gaming", "Reading", "Swimming"}, Coordinate(11, 22));
    matchmakingSystem.AddUser(Jack);
    Individual match = matchmakingSystem.Match(Jack);

    cout << "Matched with: " << match.getIntro() << endl;

    return 0;
}
