#include <iostream>

#include "src/header/manager.h"

int main() {
    manager myManager;
    myManager.buildAirlines();
    myManager.buildAirports();
    myManager.buildFlights();
    for (auto i : myManager.airportFromCountry("Portugal")){
        cout << i << "\n";
    }
    cout << myManager.numberFlights();
    return 0;

}
