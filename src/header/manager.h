#ifndef PROJECT2_MANAGER_H
#define PROJECT2_MANAGER_H

#include <list>
#include "airport.h"
#include "graph.h"
#include "airlines.h"

using namespace std;

class manager {
private:
    Graph<Airport> airportsGraph; //Airports as Vertex
    vector<Airport> airports;
    vector<Airlines> airlines;
public:
    void buildAirports();
    void buildAirlines();
    void buildFlights();
    Graph<Airport> getAirports();
    Airport findAirport(string name);
    Airlines findAirlines(string name);
};

#endif //PROJECT2_MANAGER_H
