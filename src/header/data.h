#ifndef AIRPORT_DATA_H
#define AIRPORT_DATA_H
#include <iostream>
#include <string>
#include "airport.h"


using namespace std;

class Data {
private:
    int readAirp();
    int readAirl();
    Data();

public:
    Airport getAirp(string);
};

#endif //AIRPORT_DATA_H
