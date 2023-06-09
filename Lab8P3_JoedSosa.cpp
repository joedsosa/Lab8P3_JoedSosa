#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Planet.h"
#include "Rocket.h"

using namespace std;

void saveLog(const string& log) {
    ofstream outputFile("bitacora.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << log << endl;
        outputFile.close();
    }
    else {
        cout << "Error al abrir el archivo de bitácora." << endl;
    }
}

bool encounterAsteroids(int asteroidProbability) {
    srand(static_cast<unsigned>(time(0)));
    int randomNum = rand() % 100 + 1;
    return randomNum <= asteroidProbability;
}

void performMission(Rocket& rocket, Planet& planet) {
    if (rocket.getFuelAmount() < planet.getFuelRequired()) {
        if (rocket.getLeftWing() <= 0 && rocket.getRightWing() <= 0) {
            saveLog("El cohete " + rocket.getName() + " se perdió ambas alas y no pudo llegar a " + planet.getName() + ".");
        }
        else if (rocket.getLeftWing() <= 0) {
            saveLog("El cohete " + rocket.getName() + " se perdió el ala izquierda y no pudo llegar a " + planet.getName() + ".");
        }
        else if (rocket.getRightWing() <= 0) {
            saveLog("El cohete " + rocket.getName() + " se perdió el ala derecha y no pudo llegar a " + planet.getName() + ".");
        }
        else {
            saveLog("El cohete " + rocket.getName() + " se quedó sin gasolina y no pudo llegar a " + planet.getName() + ".");
        }
    }
    else {
        if (planet.getName() == "Marte") {
            saveLog("El cohete " + rocket.getName() + " llegó con éxito a Marte.");
        }
        else if (planet.getName() == "Saturno") {
            if (encounterAsteroids(planet.getAsteroidProbability())) {
                rocket.setLeftWing(40);
                rocket.setRightWing(40);
                saveLog("El cohete " + rocket.getName() + " se encontró con una lluvia de asteroides en el camino a Saturno y sufrió daños en sus alas.");
            }
            else {
                saveLog("El cohete " + rocket.getName() + " llegó con éxito a Saturno.");
            }
        }
        else if (planet.getName() == "Neptuno") {
            if (encounterAsteroids(planet.getAsteroidProbability())) {
                saveLog("El cohete " + rocket.getName() + " se perdió en el silencioso espacio tratando de llegar a Neptuno.");
            }
            else {
                saveLog("El cohete " + rocket.getName() + " llegó de manera milagrosa a Neptuno.");
            }
        }
    }
}

void deleteLog() {
    if (remove("bitacora.txt") == 0) {
        cout << "Archivo de bitácora borrado exitosamente." << endl;
    }
    else {
        cout << "Error al borrar el archivo de bitácora." << endl;
    }
}

void Menu() {
    cout << "----------Centro de Control Space Z-----------" << endl;
    cout << "1. Leer Archivo" << endl;
    cout << "2. Guardar Bitácora" << endl;
    cout << "3. Eliminar Bitácora" << endl;
    cout << "Salir" << endl;
}

vector<string> split(string& line, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(line);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void readFile(vector<Rocket>& rockets, vector<Planet>& planets) {
    ifstream inputFile("spaceZ.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            vector<string> data = split(line, ',');
            if (data.size() == 5) {
                string name = data[0];
                int leftWing = stoi(data[1]);
                int rightWing = stoi(data[2]);
                int fuelAmount = stoi(data[3]);
                string planetName = data[4];
                rockets.push_back(Rocket(name, fuelAmount, leftWing, rightWing, planetName));
                planets.push_back(Planet(planetName, 0, 0));
            }
            else {
                cout << "Error: línea con formato incorrecto: " << line << endl;
            }
        }
        inputFile.close();
    }
    else {
        cout << "Error al abrir el archivo de datos." << endl;
    }
}

void displayMenu() {
    vector<Rocket> rockets;
    vector<Planet> planets;

    readFile(rockets, planets);
    int choice;
    do {
        Menu();
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
        case 1:
            rockets.clear();
            planets.clear();
            readFile(rockets, planets);
            break;
        case 2:
            for (auto& rocket : rockets) {
                for (auto& planet : planets) {
                    performMission(rocket, planet);
                }
            }
            break;
        case 3:
            deleteLog();
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            break;
        }

        cout << endl;
    } while (choice != 4);
}

int main() {
    displayMenu();
    return 0;
}
