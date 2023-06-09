#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <iostream>
using namespace std;
class Planet {
public:
    Planet(const string& name, int fuelRequired, int asteroidProbability);

    const string& getName() const;
    int getFuelRequired() const;
    int getAsteroidProbability() const;

private:
    string name;
    int fuelRequired;
    int asteroidProbability;
};

#endif  // PLANET_H


