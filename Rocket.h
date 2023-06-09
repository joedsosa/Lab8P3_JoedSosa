#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>
using namespace std;
class Rocket {
private:
    string name;
    int fuelAmount;
    int leftWing;
    int rightWing;
    string destinationPlanet;

public:
    Rocket(string& name, int fuelAmount, int leftWing = 100, int rightWing = 100, const string& destinationPlanet = "");

    // Getters
    string getName();
    int getFuelAmount();
    int getLeftWing();
    int getRightWing();
    string getDestinationPlanet();

    // Setters
    void setName(string& name);
    void setFuelAmount(int fuelAmount);
    void setLeftWing(int leftWing);
    void setRightWing(int rightWing);
    void setDestinationPlanet(string& destinationPlanet);
};

#endif  // ROCKET_H
