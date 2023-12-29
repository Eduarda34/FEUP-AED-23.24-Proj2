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
<<<<<<< HEAD
    void startOption3Menu();
    void startOption4Menu();
=======
    void startOption3Menu(Airport a);
>>>>>>> 3e60753 (3.5 and other things)
};
#endif //AIRPORT_MENU_H
