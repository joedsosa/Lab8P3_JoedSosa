#include "Rocket.h"

Rocket::Rocket(const string& name, float leftWing, float rightWing, int fuelAmount)
    : name(name), leftWing(leftWing), rightWing(rightWing), fuelAmount(fuelAmount) {}

const string& Rocket::getName() const {
    return name;
}
const string& Rocket::getName() const {
    return name;
}

float Rocket::getLeftWing() const {
    return leftWing;
}

float Rocket::getRightWing() const {
    return rightWing;
}

int Rocket::getFuelAmount() const {
    return fuelAmount;
}
