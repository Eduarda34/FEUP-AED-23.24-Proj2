#ifndef AIRPORT_COORDINATE_H
#define AIRPORT_COORDINATE_H


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
};

#endif //AIRPORT_COORDINATE_H
