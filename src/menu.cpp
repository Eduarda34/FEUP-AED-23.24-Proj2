#include "header/menu.h"

void Menu::startMenu() {
    int option;
    cout << "Welcome to our App" << endl
         << "What would you like to do?" << endl
         << endl
         << "1 Get number of airports/available flights" << endl;

    cin >> option;

    switch (option) {
        case 1:
          startOption1Menu();
    }
}

void Menu::startOption1Menu() {
    int option;
    cout << "You wish to :" << endl
         << endl
         << "1 Get global number of Airports" << endl
         << "2 Get global number of available flights" << endl;

    cin >> option;

    switch (option) {
        case 1:
            cout << manager.numberAirports();
        case 2:
            cout << manager.numberFlights();
    }
}

Menu::Menu(Manager manager) {
    this->manager = manager;
}