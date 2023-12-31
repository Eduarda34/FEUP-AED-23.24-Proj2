#ifndef PROJECT2_MANAGER_H
#define PROJECT2_MANAGER_H

#include <list>
#include <set>
#include <unordered_map>
#include <map>
#include "airport.h"
#include "graph.h"
#include "airlines.h"

using namespace std;

class Manager {
private:
    Graph<Airport> airportsGraph; //Airports as Vertex
    Graph<Airport> airportsUndirectedGraph;
    vector<Airport> airports;
    vector<Airlines> airlines;
    set<string> cities;
    vector<pair<Airport, int>> traffic;
public:
    void buildAirports();
    void buildAirlines();
    void buildFlights();
    vector<Airport> getAirports();
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
    pair<pair<Airport, Airport>, int> bestFLight(set<Airport> a1, set<Airport> a2);
    vector<pair<Airport, int>> getTraffic();
    void dfsArticulationPoints(Vertex<Airport>* v, Vertex<Airport>* parent, set<Airport>& articulationPoints, map<Airport, int>& disc, map<Airport, int>& low);
    set<Airport> findArticulationPoints();
    set<Airport> findAirportsByCity(string city);
    pair<vector<pair<Airport, Airport>>, int> longestTrips();
};

#endif //PROJECT2_MANAGER_H
