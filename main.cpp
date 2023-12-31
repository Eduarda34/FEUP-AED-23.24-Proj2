#include <iostream>

#include "src/header/manager.h"
#include "src/header/menu.h"

int main() {
    Manager manager = Manager();
    manager.buildAirports();
    manager.buildAirlines();
    manager.buildFlights();
    vector<Coordinate> coordinates;
    vector<Airport> airports = manager.getAirports();
    set<Airport> airports2;
    double t;
    double g;
    cout << "Insert latitude and longitude" << endl;
    cin >> t;
    cin >> g;
    Coordinate c = Coordinate(t, g);
    for (auto a : manager.getAirports()){
        coordinates.push_back(a.getCoordinate());
    }
    vector<Coordinate> cords = c.closest(coordinates);
    for (auto a : airports){
        for (auto cr : cords){
            if (a.getCoordinate() == cr){
                airports2.insert(a);
            }
        }
    }
    for (auto a : airports2){
        cout << a.getName() << endl;
    }
    //Menu menu = Menu(manager);
    //menu.startMenu();
}
