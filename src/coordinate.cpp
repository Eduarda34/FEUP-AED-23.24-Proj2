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

vector<Coordinate> Coordinate::closest(vector<Coordinate> c) {
    vector<Coordinate> cor;
    double distance = 1000000000000000000; //MAX FLOAT
    for (auto coor : c){
        if (coor.distance(*this) < distance){
            cor.clear();
            cor.push_back(coor);
            distance = coor.distance(*this);
        }
    }
    return cor;
}

double Coordinate::distance(Coordinate c) {
        const double R = 6371.01; // Radius of the Earth in kilometers

        double dLat = M_PI*(c.lati - this->lati)/180;
        double dLon = M_PI*(c.longi - this->longi)/180;

        double a = sin(dLat / 2) * sin(dLat / 2) + cos(this->lati) * cos(c.lati) * sin(dLon / 2) * sin(dLon / 2);

        double cc = 2 * atan2(sqrt(a), sqrt(1 - a));

        return R * cc;
    }

bool Coordinate::operator==(const Coordinate e) const {
    return (this->lati == e.lati && this->longi == e.longi);
}

