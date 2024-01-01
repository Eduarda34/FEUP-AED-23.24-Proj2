#include <vector>
#include "header/coordinate.h"


using namespace std;
Coordinate::Coordinate(){
    this->lati = 0;
    this->longi = 0;
}
 Coordinate::Coordinate(double lati, double longi){
    this->lati = lati;
    this->longi = longi;
}
double Coordinate::getLati(){
    return this->lati;
}

double Coordinate::getLongi(){
    return this->longi;
}

void Coordinate::setLati(double lati){
    this->lati = lati;
}

void Coordinate::setLongi(double longi){
    this->longi = longi;
}

Coordinate Coordinate::closest(vector<Coordinate> c) {
    Coordinate cor;
    double distance = 1000000000000000000; //MAX FLOAT
    for (auto coor : c){
        if (coor.distance(*this) < distance){
            cor=coor;
            distance = coor.distance(*this);
        }
    }
    return cor;
}

double Coordinate::distance(Coordinate c) {
        const double R = 6371.01; // Radius of the Earth in kilometers

    const double lat_delta = convert(c.lati - this->lati);
    const double lon_delta = convert(c.longi - this->longi);
    const double converted_lat1 = convert(this->lati);
    const double converted_lat2 = convert(c.lati);

    const auto a =
            pow(sin(lat_delta / 2), 2) + cos(converted_lat1) * cos(converted_lat2) * pow(sin(lon_delta / 2), 2);

    const auto cc = 2 * atan2(sqrt(a), sqrt(1 - a));

        return R * cc;
    }

bool Coordinate::operator==(const Coordinate e) const {
    return (this->lati == e.lati && this->longi == e.longi);
}

double Coordinate::convert(const double angle) {
    return angle * (M_PI / 180);
}

