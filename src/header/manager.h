#ifndef PROJECT2_MANAGER_H
#define PROJECT2_MANAGER_H

#include <list>
#include "airport.h"
#include "graph.h"

using namespace std;

class manager {
private:
    Graph<Airport> airportsGraph; //Airports as Vertex
public:
    void buildAirports();
    Graph<Airport> getAirports();
};

#endif //PROJECT2_MANAGER_H
