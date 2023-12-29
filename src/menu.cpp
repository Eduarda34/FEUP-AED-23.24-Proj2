#include "header/menu.h"

void Menu::startMenu() {
    int option;
    cout << endl
         << "Welcome to our App" << endl
         << "What would you like to do?" << endl
         << endl
         << "1 Get global number of airports/available flights" << endl
         << "2 See info about airport" << endl
         << "3 Check number of flights of city/airline "<< endl
         << "(Press any key other than 1, 2 or 3 to quit)" << endl;

    cin >> option;

    switch (option) {
        case 1:
            startOption1Menu();
            break;
        case 2:
            startOption2Menu();
            break;
        case 3:
            startOption5Menu();
        default:
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
            startMenu();
            break;
        case 2:
            cout << manager.numberFlights();
            startMenu();
            break;
        default:
            startMenu();
            break;
    }
}

void Menu::startOption2Menu() {
    int option;
    string input;
    Airport a = Airport();
    cout << "You want to insert the name or code of the Airport?" << endl
         << "1 Name" << endl
         << "2 Code" << endl;

    cin >> option;

    switch (option) {
        case 1:
            cout << "insert the name of the airport" << endl;
            cin >> input;
            a = manager.findAirportByName(input);
            startOption3Menu(a);
            break;
        case 2:
            cout << "insert the code of the airport" << endl;
            cin >> input;
            a = manager.findAirport(input);
            startOption3Menu(a);
            break;
        default:
            startMenu();
            break;
    }

}

void Menu::startOption3Menu(Airport a) {
    int option;
    string input;
    cout << "What would you like to do ?" << endl
         << endl
         << "1 Get number of flights out of airport" << endl
         << "2 Get number of airlines that do flights out of airport" << endl
         << "3 Get number of destinations out of airport in 1 flight" << endl
         << "4 Get number of destinations out of airport in x flights" << endl;

    cin >> option;

    switch (option) {
        case 1:
            cout << manager.getNumberOfFlightsOutAnAirportByCode(a.getCode());
            break;
        case 2:
            cout << manager.getNumberOfAirlinesOutAnAirportByCode(a.getCode());
            break;
        case 3:
            cout << "Do you want the destinations in :" << endl
                 << "1 Airports" << endl
                 << "2 Countries" << endl
                 << "3 Cities" << endl;

            cin >> option;

            switch (option) {
                case 1:
                    cout << "There are " << manager.airportDest(a).size() << " airports" << endl
                         << "Do you wish to see the name of the airports ?" << endl
                         << "1 Yes" << endl
                         << "2 No" << endl;

                    cin >> option;

                    switch (option) {
                        case 1:
                            for (auto a1: manager.airportDest(a)) {
                                cout << a1.getName() << endl;
                            }
                            startMenu();
                            break;
                        case 2:
                            startMenu();
                            break;
                        default:
                            startMenu();
                            break;
                    }
                    break;
                case 2:
                    cout << "There are " << manager.findCountries(manager.airportDest(a)).size() << " countries "
                         << endl
                         << "Do you wish to see the name of the countries ?" << endl
                         << "1 Yes" << endl
                         << "2 No" << endl;

                    cin >> option;

                    switch (option) {
                        case 1:
                            for (auto a1: manager.findCountries(manager.airportDest(a))) {
                                cout << a1 << endl;
                            }
                            startMenu();
                            break;
                        case 2:
                            startMenu();
                            break;
                        default:
                            startMenu();
                            break;
                    }
                case 3:
                    cout << "There are " << manager.findCities(manager.airportDest(a)).size() << " cities" << endl
                         << "Do you wish to see the name of the cities ?" << endl
                         << "1 Yes" << endl
                         << "2 No" << endl;

                    cin >> option;

                    switch (option) {
                        case 1:
                            for (auto a1: manager.findCities(manager.airportDest(a))) {
                                cout << a1 << endl;
                            }
                            startMenu();
                            break;
                        case 2:
                            startMenu();
                            break;
                        default:
                            startMenu();
                            break;
                    }
                    break;
            }
    }
}

void Menu::startOption5Menu() {
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
                    startMenu();
                    break;
                case 2:
                    cout << manager.numberOfFlightsOutOfTheCity(input);
                    startMenu();
                    break;
                case 3:
                    cout << manager.numberOfFlightsOutOfTheCity(input) + manager.numberOfFlightIntoTheCity(input);
                    startMenu();
                    break;
                default:
                    startMenu();
                    break;
            }
            break;
        case 2:
            cout << "Whats the code of the airline?" << endl;
            cin >> input;
            cout << manager.numberOfFlightsPerAirlineCode(input);
            startMenu();
            break;
        default:
            startMenu();
            break;
    }
}

Menu::Menu(Manager manager) {
    this->manager = manager;
}
