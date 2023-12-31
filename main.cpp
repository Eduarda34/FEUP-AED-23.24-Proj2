#include <iostream>

#include "src/header/manager.h"
#include "src/header/menu.h"

int main() {
    Manager manager = Manager();
    manager.buildAirports();
    manager.buildAirlines();
    manager.buildFlights();
    cout << manager.findArticulationPoints().size();
    Menu menu = Menu(manager);

    //menu.startMenu();
}
