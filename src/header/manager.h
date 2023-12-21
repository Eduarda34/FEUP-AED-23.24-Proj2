#ifndef PROJECT2_MANAGER_H
#define PROJECT2_MANAGER_H

#include <list>
#include "airport.h"

using namespace std;

class manager {
private:
    list<Airport> airports; //Lista de aeroportos para retirar informações extra quando necessario
public:
    void buildAirports();
    list<Airport> getAirports();
};

#endif //PROJECT2_MANAGER_H
