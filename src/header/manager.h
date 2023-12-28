#ifndef PROJECT2_MANAGER_H
#define PROJECT2_MANAGER_H

#include <list>
#include "airport.h"
#include "graph.h"
#include "airlines.h"

using namespace std;

class Manager {
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
    list<string> airportFromCountry(string country);
    int numberAirports();
    int numberFlights();
};

#endif //PROJECT2_MANAGER_H
