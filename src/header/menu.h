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
<<<<<<< HEAD
>>>>>>> 3e60753 (3.5 and other things)
=======
    void startOption5Menu();
>>>>>>> 4525f2a (3.5 and fix)
};
#endif //AIRPORT_MENU_H
