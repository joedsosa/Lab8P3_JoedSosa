#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Planet.h"
#include "Rocket.h"
#include <iostream>
using namespace std;
void saveLog(const string& log) {
    ofstream outputFile("bitacora.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << log << endl;
        outputFile.close();
    }
    else {
        cout << "Error al abrir el archivo de bitacora." << endl;
    }

}
bool encounterAteriods(int asteroidProbability) {
    srand(static_cast<unsigned>(time(0)));
    int randomNum = rand() % 100 + 1;
    return randomNum <= asteroidProbability;

}
void performMission(const Rocket& rocket, const Planet& planet) {
    if (rocket.getFuelAmount() < planet.getFuelRequired()) {
        if (rocket.getLeftWing() <= 0 && rocket.getRightWing() <= 0) {
            saveLog("El cohete " + rocket.getName() + " se perdio ambas alas y no pudo llegar a " + planet.getName());
        }
        else if (rocket.getLeftWing() <= 0) {
            saveLog("El cohete " + rocket.getName() + " se perdio el ala izquierda y no pudo llegar a " + planet.getName());
        }
        else if (rocket.getRightWing() <= 0) {
            saveLog("El cohete " + rocket.getName() + " se perdió el ala derecha y no pudo llegar a " + planet.getName() + ".");
        }
        else {
            saveLog("El cohete " + rocket.getName() + " se quedo sin gasolina y no pudo llegar a" + planet.getName() + ".");
        }
    }
    else {
        if (planet.getName() == "Neptuno") {
            if (encounterAteriods(planet.getAsteroidProbability())) {
                saveLog("El cohete " + rocket.getName() + "se perdio en el silencioso espacio tratando de llegar a Neptuno.");
            }
            else {
                saveLog("El cohete " + rocket.getName() + " llego de manera milagrosa a Neptuno");
            }
        }
        else {
            saveLog("El cohete" + rocket.getName() + "llego con exito a " + planet.getName() + ".");
        }
    }
}
void deleteLog() {
    if (remove("bitacora.txt") == 0) {
        cout << "Archivo de bitacora borrado exitosamente." << endl;
    }
    else {
        cout << "Error al borrar el archivo de bitacora. " << endl;
    }
}
        void Menu() {
            cout << "----------Centro de Control Space Z-----------";
            cout << "1. Leer Archivo" << endl;
            cout << "2. Guardar Bitacora" << endl;
            cout << "3. Eliminar Bitacora" << endl;
            cout << "Salir" << endl;
        
}
void readFile(vector<Rocket>& rockets, vector<Planet>& planets) {
            ifstream inputFile("spaceZ.txt");
            if (inputFile.is_open()) {
                string line;
                while (getline(inputFile, line)) {
                    string name;
                    float leftWing, rightWing;
                    int fuelAmount;
                    string planetName;
                    sscanf(line.c_str(), "%s,%f,%f,%d,%s", name.c_str(), &leftWing, &rightWing, &fuelAmount, planetName.c_str());
                    rockets.push_back(Rocket(name, leftWing, rightWing, fuelAmount));
                    planets.push_back(Planet(planetName, 0, 0));
                }
                inputFile.close();
            }
            else {
                cout << "Error al abrir el archivo de datos. " << endl;
            }
        }

        void displayMenu() {
            vector<Rocket> rockets;
            vector<Planet> planets;

            readFile(rockets, planets);
            int choice;
            do {
                cout << "---------Centro de Control Space Z------------------" << endl;
                cout << "1. LeerArchivo" << endl;
                cout << "2. Guardar Bitacora" << endl;
                cout << "3. Eliminar Bitacora" << endl;
                cout << "4. SALIR " << endl;
                cout << "Ingrese su eleccion: ";
                cin >> choice;
                switch (choice) {
                case 1:
                    rockets.clear();
                    planets.clear();
                    readFile(rockets, planets);
                    break;
                case 2:
                    for (const auto& rocket : rockets) {
                        for (const auto& planet : planets) {
                            performMission(rocket, planet);
                        }
                }
                    break;
                case 3: 
                    deleteLog();
                    break;
                case 4: 
                    cout << "Saliendo del programa...." << endl;
                    break;
                default:
                    cout << "Opcion invalida. Intente de nuevo" << endl;
                    break;
            }
                cout << endl;
            } while (choice != 4);
        }
int main(){
    displayMenu();
    return 0;

}



