#include "header/airport.h"

Airport::Airport(string code, string name, string city, string country, double lati, double longi){
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->coordinate = Coordinate(lati, longi);
}

string Airport::getCode(){
    return this->code;
}

string Airport::getName(){
    return this->name;
}

string Airport::getCity(){
    return this->city;
}

string Airport::getCountry(){
    return this->country;
}

Coordinate Airport::getCoordinate(){
    return this->coordinate;
}
