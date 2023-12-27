#include "header/airlines.h"
#include <iostream>
#include <string>


using namespace std;


Airlines::Airlines(string name, string code,string callsign, string country) {
    this->name = name;
    this->code = code;
    this->country = country;
    this->callsign = callsign;
}

string Airlines::getCode() {
    return this->code;
}

string Airlines::getName() {
    return this->name;
}

string Airlines::getCountry() {
    return this->country;
}

bool Airlines::operator > (const Airlines e) const {
    return this->code > e.code;
}

bool Airlines::operator < (const Airlines e) const {
    return this->code < e.code;
}

bool Airlines::operator == (const Airlines e) const {
    return this->code == e.code;
}