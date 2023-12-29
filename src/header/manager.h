#ifndef PROJECT2_MANAGER_H
#define PROJECT2_MANAGER_H

#include <list>
#include <set>
#include "airport.h"
#include "graph.h"
#include "airlines.h"

using namespace std;

class Manager {
private:
    Graph<Airport> airportsGraph; //Airports as Vertex
    vector<Airport> airports;
    vector<Airlines> airlines;
    set<string> cities;
public:
    void buildAirports();
    void buildAirlines();
    void buildFlights();
    Graph<Airport> getAirports();
    Airport findAirport(string code);
    Airport findAirportByName(string name);
    Airlines findAirlines(string name);
    list<string> airportFromCountry(string country);
    int numberAirports();
    int numberFlights();
    vector<Edge<Airport>> getFlightsOutAnAirportByName(string name);
    vector<Edge<Airport>> getFlightsOutAnAirportByCode(string code);
    int getNumberOfFlightsOutAnAirportByName(string name);
    int getNumberOfFlightsOutAnAirportByCode(string code);
    int getNumberOfAirlinesOutAnAirportByName(string name);
    int getNumberOfAirlinesOutAnAirportByCode(string code);
    int numberOfFlightsOutOfTheCity(string city);
    int numberOfFlightIntoTheCity(string city);
    int numberOfFlightsPerAirlineName(string name);
    int numberOfFlightsPerAirlineCode(string code);
    set<string> findCountries(set<Airport> airports);
    set<string> countriesFromAirport(string acode);
    set<string> findCities(set<Airport> airports);
    set<Airport> airportDest(Airport airport);
    set<Airport> reachableAirports(string code, int n);
    set<Airport> findReachableAirports(int n, set<Airport> a);
    set<string> reachableCities(string code, int n);
    set<string> reachableCountries(string code, int n);
};

#endif //PROJECT2_MANAGER_H
