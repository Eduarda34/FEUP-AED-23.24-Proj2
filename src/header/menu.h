#ifndef AIRPORT_MENU_H
#define AIRPORT_MENU_H

#include <iostream>
#include "manager.h"

using namespace std;

class Menu {
private:
    Manager manager;
public:
    Menu(Manager manager);
    void startMenu();
    void startOption1Menu();
    void startOption2Menu();
};
#endif //AIRPORT_MENU_H
