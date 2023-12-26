#include "header/manager.h"
#include <fstream>
#include <sstream>
#include <string>

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
        airportsGraph.addVertex(airport);
    }
}

Graph<Airport> manager::getAirports() {
    return airportsGraph;
}


