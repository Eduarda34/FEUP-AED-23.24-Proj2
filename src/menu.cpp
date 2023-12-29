#include "header/menu.h"

void Menu::startMenu() {
    int option;
    cout << "Welcome to our App" << endl
         << "What would you like to do?" << endl
         << endl
         << "1 Get number of airports/available flights" << endl
         << "2 Get number of flights out of an airport" << endl;

    cin >> option;

    switch (option) {
        case 1:
            startOption1Menu();
            break;
        case 2:
            startOption2Menu();
            break;
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
            break;
        case 2:
            cout << manager.numberFlights();
            break;
    }
}

void Menu::startOption2Menu() {
    int option;
    string input;
    cout << "You want to insert the name or code of the Airport?" << endl
         << "1 Name" << endl
         << "2 Code" << endl;

    cin >> option;

    switch (option) {
        case 1:
            cout << "insert the name of the airport" << endl;
            cin >> input;
            cout << "There are " << manager.getNumberOfAirlinesOutAnAirportByName(input) << " flights from " << manager.getNumberOfAirlinesOutAnAirportByName(input) << " airlines" << endl;
        case 2:
            cout << "insert the code of the airport" << endl;
            cin >> input;
            cout << "There are " << manager.getNumberOfAirlinesOutAnAirportByCode(input) << " flights from " << manager.getNumberOfAirlinesOutAnAirportByCode(input) << " airlines " << endl;
    }

}

Menu::Menu(Manager manager) {
    this->manager = manager;
}