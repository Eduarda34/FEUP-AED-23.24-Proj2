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

Coordinate Coordinate::closest(set<Coordinate> c) {
    Coordinate cor = Coordinate();
    double distance = MAXFLOAT;
    for (auto coor : c){
        if (((this->lati - coor.getLati())*(this->lati - coor.getLati()) + ((this->lati - coor.getLati())*(this->lati - coor.getLati()))) < distance) cor = coor;
    }
    return cor;
}