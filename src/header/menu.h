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
    /**
     *
     * @param manager
     */
    Menu(Manager manager);
    void startMenu();
    void startOption1Menu();
    void startOption2Menu();
    void startOption4Menu();
    void startOption3Menu(Airport a);
    void startOption5Menu();
    void startOption6Menu(set<Airport> airports);

    void start();

    void startOption7Menu();

    void startOption8Menu();

    void startOption6Menu(set<Airport> airports, vector<string> edges);

    void startOption4Menu(vector<string> edges);

    void startOption6Menu();
};
#endif //AIRPORT_MENU_H
