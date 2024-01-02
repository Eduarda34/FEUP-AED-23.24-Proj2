#ifndef AIRPORT_COORDINATE_H
#define AIRPORT_COORDINATE_H

#include <set>
#include <cmath>
#include <vector>
using namespace std;


class Coordinate {
private:
    double lati;
    double longi;
public:
    Coordinate();

    /**
     *
     * @param lati latitude of the airport
     * @param longi longitude of the airport
     */
    Coordinate(double lati, double longi);
    double getLati();
    double getLongi();
    void setLati(double lati);
    void setLongi(double longi);


    /**
     * @brief calculates the distance between two geographic coordinates
     * @param c
     * @return distance between the two points in kilometers
     */
    double distance(Coordinate c);

    /**
     * @brief find the closest point
     * @param c
     * @return closest one
     */
    Coordinate closest(vector<Coordinate> c);

    /**
     *
     * @param e
     * @return "true" if 'lati' and 'longi' of Coordinate are equals
     */
    bool operator == (const Coordinate e) const;

    /**
     * @brief converts an angle in degrees to radians
     * @param angle
     * @return angle converted to radians
     */
    double convert(const double angle);
};

#endif //AIRPORT_COORDINATE_H
