#include <iostream>

#include "src/header/manager.h"
#include "src/header/menu.h"

int main() {
    Manager manager = Manager();
    manager.buildAirports();
    manager.buildAirlines();
    manager.buildFlights();
    Menu menu = Menu(manager);
    cout << manager.reachableAirports("CDG", 100).size();
    menu.startMenu();
}
