#ifndef AIRPORT_COORDINATE_H
#define AIRPORT_COORDINATE_H

#include <set>
#include <cmath>
#include <vector>
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
    double distance(Coordinate c);
    vector<Coordinate> closest(vector<Coordinate> c);
    bool operator == (const Coordinate e) const;
};

#endif //AIRPORT_COORDINATE_H
