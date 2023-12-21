#ifndef AIRPORT_AIRLINES_H
#define AIRPORT_AIRLINES_H
#include <iostream>
#include <string>

using namespace std;

class Airlines {
private:
    string name;
    string code;
    string country;

public:
    Airlines(string name, string code, string country);
    string getName();
    string getCode();
    string getCountry();
};

#endif //AIRPORT_AIRLINES_H
