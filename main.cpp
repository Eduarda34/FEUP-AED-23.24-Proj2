#include <iostream>

#include "src/header/manager.h"

int main() {
    manager myManager;
    myManager.buildAirlines();
    myManager.buildAirports();
    myManager.buildFlights();
    Airport a = myManager.findAirport("CDG");

    return 0;

}
