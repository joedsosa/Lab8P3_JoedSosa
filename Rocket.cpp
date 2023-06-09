#include "Rocket.h"

Rocket::Rocket(string& name, int fuelAmount, int leftWing, int rightWing, const string& destinationPlanet)
    : name(name), fuelAmount(fuelAmount), leftWing(leftWing), rightWing(rightWing), destinationPlanet(destinationPlanet) {}

// Getters
string Rocket::getName(){
    return name;
}

int Rocket::getFuelAmount(){
    return fuelAmount;
}

int Rocket::getLeftWing(){
    return leftWing;
}

int Rocket::getRightWing(){
    return rightWing;
}

std::string Rocket::getDestinationPlanet(){
    return destinationPlanet;
}

// Setters
void Rocket::setName(string& name) {
    this->name = name;
}

void Rocket::setFuelAmount(int fuelAmount) {
    this->fuelAmount = fuelAmount;
}

void Rocket::setLeftWing(int leftWing) {
    this->leftWing = leftWing;
}

void Rocket::setRightWing(int rightWing) {
    this->rightWing = rightWing;
}

void Rocket::setDestinationPlanet(string& destinationPlanet) {
    this->destinationPlanet = destinationPlanet;
}
