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

    /**
     * @return airport vector
     */
    vector<Airport> getAirports();

    /**
     * @brief implements a binary search looking for an Airport that matches the code provided
     * @param code
     * @return corresponding airport object
     */
    Airport findAirport(string code);
    Airport findAirportByName(string name);

    /**
     * @brief Binary search on the airlines vector to find an airline that matches the given code
     * @param name
     * @return corresponding airline
     */
    Airlines findAirlines(string name);
    list<string> airportFromCountry(string country);

    /**
     * @return number of airports stored in the vector
     */
    int numberAirports();

    /**
     * @brief count the number of flights
     * @return total number of flights
     */
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

    /**
     * @brief counts the number of flights leaving a specific city
     * @param city
     * @return number of flights leaving the specified city
     */
    int numberOfFlightsOutOfTheCity(string city);

    /**
     * @brief counts the number of flights arriving at a specific city
     * @param city
     * @return number of flights arriving at the specified city
     */
    int numberOfFlightIntoTheCity(string city);
    int numberOfFlightsPerAirlineName(string name);

    /**
     * @brief counts the number of flights associated with a particular airline (by code)
     * @param code
     * @return number of flights associated with the airline (by code)
     */
    int numberOfFlightsPerAirlineCode(string code);

    /**
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

    /**
     *
     * @param airport
     * @return set of airports
     */
    set<Airport> airportDest(Airport airport);
    set<Airport> reachableAirports(string code, int n);

    /**
     * @brief calculates the airport reachable
     * @param n
     * @param a
     * @return result of the set
     */
    set<Airport> findReachableAirports(int n, set<Airport> a);
    set<string> reachableCities(string code, int n);
    set<string> reachableCountries(string code, int n);
    vector<vector<Airport>> bestFLight(set<Airport> a1, set<Airport> a2);
    vector<pair<Airport, int>> getTraffic();

    /**
     * @brief implements dfs to find articulation points
     * @param v
     * @param parent
     * @param articulationPoints
     * @param disc
     * @param low
     */
    void dfsArticulationPoints(Vertex<Airport>* v, Vertex<Airport>* parent, set<Airport>& articulationPoints, map<Airport, int>& disc, map<Airport, int>& low);
    set<Airport> findArticulationPoints();

    /**
     * @brief find a set of airports that are located in a specific city
     * @param city
     * @return set that contains all airports found in the specified city
     */
    set<Airport> findAirportsByCity(string city);
    pair<vector<pair<Airport, Airport>>, int> longestTrips();
    vector<Airport> bestFLight(Airport a1, Airport a2);

    /**
     * @brief calculate the best flight route between two sets of airports
     * @param a1
     * @param a2
     * @param edges
     * @return set that contains all paths with the fewest stops
     */
    set<vector<Airport>> bestFLight(set<Airport> a1, set<Airport> a2, vector<string> edges);

    /**
     * @brief find the pair of airports that have the longest trip between them (length of that trip)
     *
     * @return pair that contains a vector of airport pairs (longest trip(s)) and an integer (length of these longest trips)
     */
    vector<Airlines> getAirlines();
};

#endif //PROJECT2_MANAGER_H
