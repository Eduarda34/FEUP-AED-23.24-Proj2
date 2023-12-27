#include "header/manager.h"
#include "header/airlines.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

//Reads the csv files and fills the list airports with the elements of the class airport
//Time Complexity O(n), being n the number of lines of airports.csv
void manager::buildAirports() {
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
    }
    sort(airports.begin(), airports.end());
}

void manager::buildAirlines() {
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

void manager::buildFlights() {
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
        airportsGraph.addEdge(sourceAirport, targetAirport, takenAirline);
    }
    cout << "Acabou";
}


Airport manager::findAirport(string code) {
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
Airlines manager::findAirlines(string code) {
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



Graph<Airport> manager::getAirports() {
    return airportsGraph;
}



