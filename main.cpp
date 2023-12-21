#include <iostream>
#include <iostream>
#include "src/header/manager.h"

int main() {
    manager myManager;
    myManager.buildAirports();
    list<Airport> airports = myManager.getAirports();
    for (Airport a: airports) {
        cout  << a.getCode() << " " << a.getName() << " " << a.getCity() << " " << a.getCountry() << endl;
    }
    return 0;

}
