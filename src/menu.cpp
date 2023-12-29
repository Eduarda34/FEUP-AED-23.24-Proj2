#include "header/menu.h"

void Menu::startMenu() {
    int option;
    cout << "Welcome to our App" << endl
         << "What would you like to do?" << endl
         << endl
         << "1 Get number of airports/available flights" << endl
         << "2 Get number of flights out of an airport" << endl
         << "3 Get number of flights from a city/airline" << endl;

    cin >> option;

    switch (option) {
        case 1:
            startOption1Menu();
            break;
        case 2:
            startOption2Menu();
            break;
        case 3:
            startOption3Menu();
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

void Menu::startOption3Menu() {
    int option, option2;
    string input;
    cout << "Do you want to check the number of flights of a city or airline?" << endl
         << "1 City" << endl
         << "2 Airline" << endl;

    cin >> option;

    switch (option) {
        case 1:
            cout << "What is the name of the city?" << endl;
            cin >> input;
            cout << "Do you want to check the n umber of flights in/out or both ?" << endl
                 << "1 In" << endl
                 << "2 Out" << endl
                 << "3 Both" << endl;

            cin >> option2;
            switch (option2) {
                case 1:
                    cout << manager.numberOfFlightIntoTheCity(input);
                    break;
                case 2:
                    cout << manager.numberOfFlightsOutOfTheCity(input);
                    break;
                case 3:
                    cout << manager.numberOfFlightsOutOfTheCity(input) + manager.numberOfFlightIntoTheCity(input);
                    break;
            }
            break;
        case 2:
            cout << "Whats the code of the airline?" << endl;
            cin >> input;
            cout << manager.numberOfFlightsPerAirlineCode(input);
    }
}

Menu::Menu(Manager manager) {
    this->manager = manager;
}