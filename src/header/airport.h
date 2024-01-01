#ifndef AIRPORT_AIRPORT_H
#define AIRPORT_AIRPORT_H
#include <string>

#include "coordinate.h"


using namespace std;

class Airport {
private:
    string code;
    string name;
    string city;
    string country;
    Coordinate coordinate;
    double leti, longi;

public:
    /**
     *
     * @param code code of the airport
     * @param name name of the airport
     * @param city city of the airport
     * @param country country of the airport
     * @param lati latitude of the airport
     * @param longi longitude of the airport
     */
    Airport(string code, string name, string city, string country, double lati, double longi);

    /**
     * @brief construct a new airport
     */
    Airport();

    /**
     * @brief returns the code of the airport
     * Complexity: O(1)
     * @return code of the airport
     */
    string getCode();

    /**
     * @brief returns the name of the airport
     * Complexity: O(1)
     * @return name of the airport
     */
    string getName();

    /**
     * @brief returns the city of the airport
     * Complexity: O(1)
     * @return city of the airport
     */
    string getCity();

    /**
     * @brief returns the country of the airport
     * Complexity: O(1)
     * @return country of the airport
     */
    string getCountry();
    Coordinate getCoordinate();
    void setCode(string code);
    void setName(string name);
    void setCity(string city);
    void setCountry(string country);
    void setCoordinate(double lati, double longi);
    bool operator > (const Airport e) const;
    bool operator < (const Airport e) const;

    /**
     * @brief compares two aiports and verifies if they are the same
     * @param e
     * @return "true" if the airports are equal
     */
    bool operator == (const Airport e) const;

};

#endif //AIRPORT_AIRPORT_H
