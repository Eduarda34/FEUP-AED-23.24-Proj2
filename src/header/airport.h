#ifndef AIRPORT_AIRPORT_H
#define AIRPORT_AIRPORT_H
#include <string>

#include "coordinate.h"


using namespace std;

class Airport {
private:
    string code;
    string name;
    string city;
    string country;
    Coordinate coordinate;
    double leti, longi;

public:
    Airport(string code, string name, string city, string country, double lati, double longi);
    string getCode();
    string getName();
    string getCity();
    string getCountry();
    Coordinate getCoordinate();
    void setCode(string code);
    void setName(string name);
    void setCity(string city);
    void setCountry(string country);
    void setCoordinate(double lati, double longi);

};

#endif //AIRPORT_AIRPORT_H
