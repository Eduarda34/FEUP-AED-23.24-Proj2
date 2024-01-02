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
    /**
     * Reads the cvs files and fills the list airports with the elements of the class airport
     * Complexity: O(n)
     */
    void buildAirports();

    /**
     * Reads the csv files and fills the list airlines with the elements of the class airport
     * Complexity: O(n)
     */
    void buildAirlines();

    /**
     * Reads the flights.csv files and fills the graph
     * Complexity: O(n * 2log(h) * log(y))
     */
    void buildFlights();
    vector<Airport> getAirports();
    Airport findAirport(string code);
    Airport findAirportByName(string name);
    Airlines findAirlines(string name);
    list<string> airportFromCountry(string country);
    int numberAirports();
    int numberFlights();

    /**
     * Search the graph fpr the right vertex and then returns the flights
     * Complexity: O(n)
     * @param name
     * @return vector<Edge<Airport>>
     */
    vector<Edge<Airport>> getFlightsOutAnAirportByName(string name);

    /**
     * Search the graph fpr the right vertex and then returns the flights
     * Complexity: O(n)
     * @param code
     * @return
     */
    vector<Edge<Airport>> getFlightsOutAnAirportByCode(string code);

    /**
     * Complexity: O(n)
     * @param name
     * @return number of flights
     */
    int getNumberOfFlightsOutAnAirportByName(string name);

    /**
     * Complexity: O(n)
     * @param code
     * @return number of flights
     */
    int getNumberOfFlightsOutAnAirportByCode(string code);
    int getNumberOfAirlinesOutAnAirportByName(string name);

    /**
     * Complexity: O(n)
     * @param code
     * @return number of airlines
     */
    int getNumberOfAirlinesOutAnAirportByCode(string code);
    int numberOfFlightsOutOfTheCity(string city);
    int numberOfFlightIntoTheCity(string city);
    int numberOfFlightsPerAirlineName(string name);
    int numberOfFlightsPerAirlineCode(string code);

    /**
     *
     * @param airports
     * @return list of countries
     */
    set<string> findCountries(set<Airport> airports);
    set<string> countriesFromAirport(string acode);

    /**
     *
     * @param airports
     * @return list of cities
     */
    set<string> findCities(set<Airport> airports);
    set<Airport> airportDest(Airport airport);
    set<Airport> reachableAirports(string code, int n);
    set<Airport> findReachableAirports(int n, set<Airport> a);
    set<string> reachableCities(string code, int n);
    set<string> reachableCountries(string code, int n);
    vector<vector<Airport>> bestFLight(set<Airport> a1, set<Airport> a2);
    vector<pair<Airport, int>> getTraffic();
    void dfsArticulationPoints(Vertex<Airport>* v, Vertex<Airport>* parent, set<Airport>& articulationPoints, map<Airport, int>& disc, map<Airport, int>& low);
    set<Airport> findArticulationPoints();
    set<Airport> findAirportsByCity(string city);
    pair<vector<pair<Airport, Airport>>, int> longestTrips();

    vector<Airport> bestFLight(Airport a1, Airport a2);


    set<vector<Airport>> bestFLight(set<Airport> a1, set<Airport> a2, vector<string> edges);

    vector<Airlines> getAirlines();
};

#endif //PROJECT2_MANAGER_H
