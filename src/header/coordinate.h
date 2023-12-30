#ifndef AIRPORT_COORDINATE_H
#define AIRPORT_COORDINATE_H

#include <set>
#include <cmath>
using namespace std;


class Coordinate {
private:
    double lati;
    double longi;
public:
    Coordinate();
    Coordinate(double lati, double longi);
    double getLati();
    double getLongi();
    void setLati(double lati);
    void setLongi(double longi);
    Coordinate closest(set<Coordinate> c);
};

#endif //AIRPORT_COORDINATE_H
