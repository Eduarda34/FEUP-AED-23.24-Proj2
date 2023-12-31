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
         << "4 See best flight option" << endl
         << "(Press any key other to quit)" << endl;

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
        case 4:
            startOption4Menu();
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
            cout << endl <<"End" << endl;
            startMenu();
            break;
        case 2:
            cout << manager.getNumberOfAirlinesOutAnAirportByCode(a.getCode());
            cout << endl <<"End" << endl;
            startMenu();
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
                            cout << endl <<"End" << endl;
                            startMenu();
                            break;
                        default:
                            cout << endl <<"End" << endl;
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
                        default:
                            cout << "End" << endl;
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
                        default:
                            cout << "End" << endl;
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
            cout << "Do you want to check the number of flights in/out or both ?" << endl
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

void Menu::startOption4Menu() {
    set<Airport> airports;
    vector<Coordinate> coordinates;
    int option;
    string input;
    cout << "Insert the option you want for the source" << endl
         << "1 City" << endl
         << "2 Airport" << endl
         << "3 Coordinates" << endl;

    cin >> option;
    switch (option) {
        case 1:
            cout << "Insert the name of the city" << endl;
            cin >> input;
            for (auto a : manager.findAirportsByCity(input)) {
                airports.insert(a);
            }
            startOption6Menu(airports);
            break;
        case 2:
            cout << "Insert the code of the airport" << endl;
            cin >> input;
            airports.insert(manager.findAirport(input));
            startOption6Menu(airports);
            break;
        case 3:
            double t;
            double g;
            cout << "Insert latitude and longitude" << endl;
            cin >> t;
            cin >> g;
            Coordinate c = Coordinate(t, g);
            for (auto a : manager.getAirports()){
                coordinates.push_back(a.getCoordinate());
            }
            vector<Coordinate> cords = c.closest(coordinates);
            for (auto a : airports){
                for (auto cr : coordinates){
                    if (a.getCoordinate() == cr){
                        airports.insert(a);
                    }
                }
            }
            startOption6Menu(airports);
            break;
    }
}

    void Menu::startOption6Menu(set<Airport> airports) {
        set<Airport> airports2;
        vector<Coordinate> coordinates;
        int option;
        string input;
        cout << "Insert the option you want for the destination" << endl
             << "1 City" << endl
             << "2 Airport" << endl
             << "3 Coordinates" << endl;

        cin >> option;
        switch (option) {
            case 1:
                cout << "Insert the name of the city" << endl;
                cin >> input;
                for (auto a : manager.findAirportsByCity(input)) {
                    airports2.insert(a);
                }
                cout << manager.bestFLight(airports, airports2).first.first.getName() << " to "
                     << manager.bestFLight(airports, airports2).first.second.getName() << " with "
                     << manager.bestFLight(airports, airports2).second << " flights" << endl;
                break;
            case 2:
                cout << "Insert the code of the airport" << endl;
                cin >> input;
                airports2.insert(manager.findAirport(input));
                cout << manager.bestFLight(airports, airports2).first.first.getName() << " to "
                     << manager.bestFLight(airports, airports2).first.second.getName() << " with "
                     << manager.bestFLight(airports, airports2).second << " flights" << endl;
                break;
            case 3:
                double t;
                double g;
                cout << "Insert latitude and longitude" << endl;
                cin >> t;
                cin >> g;
                Coordinate c = Coordinate(t, g);
                for (auto a : manager.getAirports()){
                    coordinates.push_back(a.getCoordinate());
                }
                vector<Coordinate> cords = c.closest(coordinates);
                for (auto a : airports){
                    for (auto cr : coordinates){
                        if (a.getCoordinate() == cr){
                            airports2.insert(a);
                        }
                    }
                }
                cout << manager.bestFLight(airports, airports2).first.first.getName() << " to "
                     << manager.bestFLight(airports, airports2).first.second.getName() << " with "
                     << manager.bestFLight(airports, airports2).second << " flights" << endl;
                break;
        }
    }




Menu::Menu(Manager manager) {
    this->manager = manager;
}
