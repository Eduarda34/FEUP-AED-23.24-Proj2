#include <iostream>

#include "src/header/manager.h"

int main() {
    manager myManager;
    myManager.buildAirports();
    const vector<Vertex<Airport> *> &k = myManager.getAirports().getVertexSet();

    for (auto a = k.begin(); a != k.end(); ++a) {
        cout << (*a)->getInfo().getCode() << " " << (*a)->getInfo().getName() << " "
             << (*a)->getInfo().getCity() << " " << (*a)->getInfo().getCountry() << endl;
    }
    return 0;

}
