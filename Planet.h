#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <iostream>
using namespace std;
class Planet {
public:
    Planet(string& name, int fuelRequired, int asteroidProbability);

    string& getName();
    int getFuelRequired();
    int getAsteroidProbability();
    
private:
    string name;
    int fuelRequired;
    int asteroidProbability;
};

#endif  // PLANET_H


