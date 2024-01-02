#ifndef AIRPORT_MENU_H
#define AIRPORT_MENU_H

#include <iostream>
#include "manager.h"

using namespace std;

class Menu {
private:
    Manager manager;
    vector<string> edges;
    set<Airport> airports1;
    set<Airport> airports2;
public:
    Menu(Manager manager);

    /**
     * start the menu
     */
    void startMenu();

    /**
     * @brief displays menu to the user
     */
    void startOption1Menu();

    /**
     * @brief prompts the user for the name or code of an airport and calls another function to continue the program
     */
    void startOption2Menu();

    /**
     * @brief filter or select airlines and prepare a set of information to be used later
     */
    void startOption4Menu();

    /**
     * @brief display a specific menu related to different information about an airport provided as an argument
     * @param a
     */
    void startOption3Menu(Airport a);

    /**
     * @brief check the number of flights based on a city or airline
     */
    void startOption5Menu();
    void startOption6Menu(set<Airport> airports);

    void start();

    /**
     * @brief presents options to the user related to destinations (city name, airport code or coordinates)
     */
    void startOption7Menu();
    void startOption8Menu();

    void startOption6Menu(set<Airport> airports, vector<string> edges);

    void startOption4Menu(vector<string> edges);
    void startOption9Menu();
    void startOption10Menu();

    /**
     * @brief read the user choice to define the origin of the flight (by city name, airport code or coordinates)
     */
    void startOption6Menu();
};
#endif //AIRPORT_MENU_H
