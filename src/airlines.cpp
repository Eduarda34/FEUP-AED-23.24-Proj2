#include "header/airlines.h"
#include <iostream>
#include <string>

using namespace std;

Airlines::Airlines(string name, string code, string country) {
    this->name = name;
    this->code = code;
    this->country = country;
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