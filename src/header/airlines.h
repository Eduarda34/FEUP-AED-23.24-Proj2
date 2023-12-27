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
    string callsign;

public:
    Airlines(string name, string code, string callsign, string country);
    string getName();
    string getCode();
    string getCountry();
    bool operator > (const Airlines e) const;
    bool operator < (const Airlines e) const;
    bool operator == (const Airlines e) const;
};

#endif //AIRPORT_AIRLINES_H
