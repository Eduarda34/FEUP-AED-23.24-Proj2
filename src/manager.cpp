#include "header/manager.h"
#include "header/airlines.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include <map>

using namespace std;

//Reads the csv files and fills the list airports with the elements of the class airport
//Time Complexity O(n), being n the number of lines of airports.csv
void Manager::buildAirports() {
    ifstream airportsData("../dataset/airports.csv");
    string line, code,name,city,country,latitude,longitude;
    getline(airportsData, line);
    while (getline(airportsData, line)) {
        istringstream info(line);
        getline(info, code, ',');
        getline(info, name, ',');
        getline(info, city, ',');
        getline(info, country, ',');
        getline(info, latitude, ',');
        getline(info, longitude, '\r');
        float fLatitude = stof(latitude);
        float fLongitude = stof(longitude);
        Airport airport = Airport(code, name, city, country, fLatitude, fLongitude);
        airports.push_back(airport);
        airportsGraph.addVertex(airport);
        airportsUndirectedGraph.addVertex(airport);
        traffic.push_back(pair<Airport, int>(airport, 0));
    }
    sort(airports.begin(), airports.end());
}

//Reads the csv files and fills the list airlines with the elements of the class airport
//Time Complexity O(n), being n the number of lines of airlines.csv
void Manager::buildAirlines() {
    ifstream airportsData("../dataset/airlines.csv");
    string line, code,name,callsign,country;
    getline(airportsData, line);
    while (getline(airportsData, line)) {
        istringstream info(line);
        getline(info, code, ',');
        getline(info, name, ',');
        getline(info, callsign, ',');
        getline(info, country, ',');
        Airlines airline = Airlines(name, code, callsign, country);
        airlines.push_back(airline);
    }
    sort(airlines.begin(), airlines.end());
}


//Reads the flights.csv files and fills the graph
//Time Complexity O(n * 2 log(h) * log(y)), being n the number of lines of flights.csv, h the size of the list of airports and y the size of the list of airlines
void Manager::buildFlights() {
    ifstream airportsData("../dataset/flights.csv");
    string line, source,target, airline;
    getline(airportsData, line);
    while (getline(airportsData, line)) {
        istringstream info(line);
        getline(info, source, ',');
        getline(info, target, ',');
        getline(info, airline, ',');
        Airport sourceAirport = findAirport(source);
        Airport targetAirport = findAirport(target);
        Airlines takenAirline = findAirlines(airline);
        cities.insert(targetAirport.getCity());
        cities.insert(sourceAirport.getCity());
        airportsGraph.addEdge(sourceAirport, targetAirport, takenAirline);
        airportsUndirectedGraph.addEdge(sourceAirport, targetAirport, takenAirline);
        airportsUndirectedGraph.addEdge(targetAirport, sourceAirport, takenAirline);
        for(auto &i : traffic) {
            if (i.first.getCode() == source) {
                i.second++;
            }
        }
        for(auto &i : traffic) {
            if (i.first.getCode() == target) {
                i.second++;
            }
        }
    }
}


Airport Manager::findAirport(string code) {
    int left = 0;
    int right = airports.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (airports[mid].getCode() == code) {
            return airports[mid];
        }
        if (airports[mid].getCode() < code) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
}
Airlines Manager::findAirlines(string code) {
    int left = 0;
    int right = airlines.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (airlines[mid].getCode() == code) {
            return airlines[mid];
        }
        if (airlines[mid].getCode() < code) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
}



vector<Airport> Manager::getAirports() {
    return airports;
}

list<string> Manager::airportFromCountry(string country){
    //retorna os aeroportos de um pais
    list<string> lista;
    for (auto b : airports) {
        if (b.getCountry() == country) {
            lista.push_back(b.getName());
        }
    }
    return lista;
}

int Manager::numberAirports() {
    return airports.size();
}

int Manager::numberFlights() {
    int count = 0;
    for (auto a : airports){
        count += airportsGraph.findVertex(a)->getAdj().size();
    }
    return count;
}

//Search the graph fpr the right vertex and then returns the flights
// Time complexity O(n) being n the size of the graph vertex set
vector<Edge<Airport>> Manager::getFlightsOutAnAirportByName(string name) {
    for (auto i : airportsGraph.getVertexSet()) {
        if (i->getInfo().getName() == name) {
            return i->getAdj();
        }
    }
    return vector<Edge<Airport>>();
}

//Search the graph fpr the right vertex and then returns the flights
// Time complexity O(n) being n the size of the graph vertex set
vector<Edge<Airport>> Manager::getFlightsOutAnAirportByCode(string code) {
    for (auto i : airportsGraph.getVertexSet()) {
        if (i->getInfo().getCode() == code) {
            return i->getAdj();
        }
    }
    return vector<Edge<Airport>>();
}

//Returns the number of flights
// Time complexity O(n) being n the size of the graph vertex set
int Manager::getNumberOfFlightsOutAnAirportByName(string name) {
    return getFlightsOutAnAirportByName(name).size();
}


//Returns the number of flights
// Time complexity O(n) being n the size of the graph vertex set
int Manager::getNumberOfFlightsOutAnAirportByCode(string code) {
    return getFlightsOutAnAirportByCode(code).size();
}

//Returns the number of airlines
// Time complexity O(n) being n the size of the graph vertex set
int Manager::getNumberOfAirlinesOutAnAirportByName(string name) {
    set<Airlines> airlines;
    vector<Edge<Airport>> flights = getFlightsOutAnAirportByName(name);
    for (auto i: flights) {
        airlines.insert(i.getWeight());
    }
    return airlines.size();
}

//Returns the number of airlines
// Time complexity O(n) being n the size of the graph vertex set
int Manager::getNumberOfAirlinesOutAnAirportByCode(string code) {
    set<Airlines> airlines;
    vector<Edge<Airport>> flights = getFlightsOutAnAirportByCode(code);
    for (auto i: flights) {
        airlines.insert(i.getWeight());
    }
    return airlines.size();
}

int Manager::numberOfFlightsOutOfTheCity(string city) {
    int counter = 0;
    vector<Vertex<Airport>*> vertexes = airportsGraph.getVertexSet();
    for (auto i : vertexes) {
        string h = i->getInfo().getCity();
        if (h == city) {
            counter++;
        }
    }
    return counter;
}

int Manager::numberOfFlightIntoTheCity(string city) {
    int counter = 0;
    vector<Vertex<Airport>*> vertexes = airportsGraph.getVertexSet();
    for (auto i : vertexes) {
        for (auto j : i->getAdj()) {
            string h = j.getDest()->getInfo().getCity();
            if (h == city) {
                counter++;
            }
        }
    }
    return counter;
}
int Manager::numberOfFlightsPerAirlineName(string name) {
    int count = 0;
    for (auto i : airportsGraph.getVertexSet()) {
        for (auto j : i->getAdj()) {
            if (j.getDest()->getInfo().getName() == name) {
                count++;
            }
        }
    }
    return count;
}
int Manager::numberOfFlightsPerAirlineCode(string code) {
    int count = 0;
    for (auto i : airportsGraph.getVertexSet()) {
        for (auto j : i->getAdj()) {
            if (j.getDest()->getInfo().getCode() == code) {
                count++;
            }
        }
    }
    return count;
}
set<string> Manager::findCountries(set<Airport> airports){
    //retorna uma lista de paises recebendo uma lista de airports
    set<string> countries;
    for (Airport airport : airports){
        if (find(countries.begin(),countries.end(),airport.getCountry())==countries.end()){
            countries.insert(airport.getCountry());
        }
    }
    return countries;
}

set<string> Manager::findCities(set<Airport> airports){
    //retorna uma lista de cidades recebendo uma lista de airports
    set<string> cities;
    for (Airport airport : airports){
        if (find(cities.begin(),cities.end(),airport.getCity())==cities.end()){
            cities.insert(airport.getCity());
        }
    }
    return cities;

}

set<string> Manager::countriesFromAirport(string acode){
    set<Airport> airports;
    Airport a = findAirport(acode);
    auto airport = airportsGraph.findVertex(a);
    for (auto e: airport->getAdj()){
        airports.insert(e.getDest()->getInfo());
    }
    return findCountries(airports);
}

set<Airport> Manager::airportDest(Airport airport){
    set<Airport> set;
    auto a = airportsGraph.findVertex(airport);
    for (auto e : a->getAdj()){
        set.insert(e.getDest()->getInfo());
    }
    return set;
}

Airport Manager::findAirportByName(string name) {
    for (auto a : airports){
        if (a.getName() == name){
            return a;
        }
    }
}
set<Airport> Manager::findAirportsByCity(string city) {
    set<Airport> airports2;
    for (auto a : airports){
        if (a.getCity() == city){
            airports2.insert(a);
        }
    }
    return airports2;
}

set<Airport> Manager::reachableAirports(string code, int n) {
    set<Airport> y;
    Airport air = findAirport(code);
    for(auto j : airportsGraph.findVertex(air)->getAdj()) {
        y.insert(j.getDest()->getInfo());
    }
    return findReachableAirports(n, y);
}

set<Airport> Manager::findReachableAirports(int n, set<Airport> a) {
    vector<Airport> toAdd;
    if (n == 0) {
        return a;
    }
    else {
        for (auto i : a) {
            for(auto j : airportsGraph.findVertex(i)->getAdj()) {
                toAdd.push_back(j.getDest()->getInfo());
            }
        }
        for (auto y : toAdd) {
            a.insert(y);
        }
        return findReachableAirports(n-1, a);
    }
}


    set<vector<Airport>> Manager::bestFLight(set<Airport> a1, set<Airport> a2, vector<string> edges) {
    int stops = INT32_MAX;
    set<vector<Airport>> res;
    for (auto a : a1) {
        for (auto b : a2) {
            auto currentPath = airportsGraph.newBfs(a, b, edges);
            if (currentPath[0].size() < stops) {
                stops = currentPath[0].size();
                res.clear();
                for (auto d : currentPath) {
                    res.insert(d);
                }
            }
            else if (currentPath[0].size() == stops) {
                for (auto c : currentPath) {
                    res.insert(c);
                }
            }
        }
    }
    return res;
}

vector<pair<Airport, int>> Manager::getTraffic() {
    sort(traffic.begin(), traffic.end(), [](pair<Airport, int> a1, pair<Airport, int> a2){
        return a1.second > a2.second;
    });
    return traffic;
}


set<string> reachableCities(string code);
set<string> reachableCountries(string code);



void Manager::dfsArticulationPoints(Vertex<Airport>* v, Vertex<Airport>* parent, set<Airport>& articulationPoints, map<Airport, int>& disc, map<Airport, int>& low) {
    static int time = 0;
    v->setVisited(true);
    disc[v->getInfo()] = low[v->getInfo()] = ++time;
    int children = 0;

    for (const Edge<Airport>& edge : v->getAdj()) {
        Vertex<Airport>* w = edge.getDest();

        if (!w->isVisited()) {
            children++;
            dfsArticulationPoints(w, v, articulationPoints, disc, low);
            low[v->getInfo()] = min(low[v->getInfo()], low[w->getInfo()]);

            if (parent == NULL && children > 1)
                articulationPoints.insert(v->getInfo());

            if (parent != NULL && low[w->getInfo()] >= disc[v->getInfo()])
                articulationPoints.insert(v->getInfo());
        } else if (w != parent){
            low[v->getInfo()] = min(low[v->getInfo()], disc[w->getInfo()]);
        }
    }
}

set<Airport> Manager::findArticulationPoints() {
    set<Airport> articulationPoints;
    map<Airport, int> disc;
    map<Airport, int> low;

    for (Vertex<Airport>* v : airportsUndirectedGraph.getVertexSet()) {
        if (!v->isVisited()) {
            dfsArticulationPoints(v, NULL, articulationPoints, disc, low);
        }
    }

    return articulationPoints;
}

pair<vector<pair<Airport, Airport>>, int> Manager::longestTrips() {
    pair<vector<pair<Airport, Airport>>, int> longestTripsSoFar;
    longestTripsSoFar.second = 0;
    for( auto i : airportsGraph.getVertexSet()) {
       for(auto k : airportsGraph.LongestBfs(i->getInfo())) {
           if (k.second > longestTripsSoFar.second) {
               vector<pair<Airport, Airport>> a;
               a.push_back(pair<Airport,Airport>(i->getInfo(),k.first->getInfo()));
               longestTripsSoFar.first = a;
               longestTripsSoFar.second = k.second;
           }
           else if(k.second == longestTripsSoFar.second) {
               longestTripsSoFar.first.push_back(pair<Airport, Airport>(i->getInfo(), k.first->getInfo()));
           }
       }
    }
    return longestTripsSoFar;
}
vector<Airlines> Manager::getAirlines(){
    return this->airlines;
}