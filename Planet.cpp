#include "Planet.h"

Planet::Planet(const std::string& name, int fuelRequired, int asteroidProbability)
    : name(name), fuelRequired(fuelRequired), asteroidProbability(asteroidProbability) {}

const std::string& Planet::getName() const {
    return name;
}

int Planet::getFuelRequired() const {
    return fuelRequired;
}

int Planet::getAsteroidProbability() const {
    return asteroidProbability;
}
