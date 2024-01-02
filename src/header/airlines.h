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


    /**
     * @brief returns the name of the airline
     * Complexity: O(1)
     * @return name of the airline
     */
    string getName() const;

    /**
     * @brief returns the code of the airline
     * Complexity: O(1)
     * @return code of the airlines
     */
    string getCode() const;

    /**
     * @brief returns the country of the airline
     * Complexity: O(1)
     * @return country of the airline
     */
    string getCountry();
    bool operator > (const Airlines e) const;
    bool operator < (const Airlines e) const;
    bool operator == (const Airlines e) const;
};

#endif //AIRPORT_AIRLINES_H
