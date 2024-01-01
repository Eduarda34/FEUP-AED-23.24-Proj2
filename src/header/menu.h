#ifndef AIRPORT_MENU_H
#define AIRPORT_MENU_H

#include <iostream>
#include "manager.h"

using namespace std;

class Menu {
private:
    Manager manager;
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
};
#endif //AIRPORT_MENU_H
