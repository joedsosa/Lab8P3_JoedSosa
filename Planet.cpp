#include "Planet.h"

Planet::Planet(string& name, int fuelRequired, int asteroidProbability)
    : name(name), fuelRequired(fuelRequired), asteroidProbability(asteroidProbability) {}

string& Planet::getName(){
    return name;
}

int Planet::getFuelRequired(){
    return fuelRequired;
}

int Planet::getAsteroidProbability(){
    return asteroidProbability;
}
