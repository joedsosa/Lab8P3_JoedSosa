#ifndef ROCKET_H
#define ROCKET_H

#include <string>
#include <iostream>
#include <string>
using namespace std;
class Rocket {
public:
    Rocket(const string& name, float leftWing, float rightWing, int fuelAmount);

    const string& getName() const;
    float getLeftWing() const;
    float getRightWing() const;
    int getFuelAmount() const;

private:
    string name;
    float leftWing;
    float rightWing;
    int fuelAmount;
};

#endif  // ROCKET_H
