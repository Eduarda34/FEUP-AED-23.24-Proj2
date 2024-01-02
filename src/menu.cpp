#include <limits>
#include "header/menu.h"
void Menu::start() {
    manager.buildAirports();
    manager.buildAirlines();
    manager.buildFlights();
}
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
         << "5 Maximum trip" << endl
         << "6 Top-k Airport with most traffic" << endl
         << "7 Get essential airports" << endl
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
            break;
        case 4:
            startOption4Menu();
            break;
        case 5:
            startOption8Menu();
            break;
        case 6:
            startOption9Menu();
            break;
        case 7:
            startOption10Menu();
            break;
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
    int option, stops;
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
            cout << endl << "End" << endl;
            startMenu();
            break;
        case 2:
            cout << manager.getNumberOfAirlinesOutAnAirportByCode(a.getCode());
            cout << endl << "End" << endl;
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
                            cout << endl << "End" << endl;
                            startMenu();
                            break;
                        default:
                            cout << endl << "End" << endl;
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
        case 4:
            cout << "Whats the code of the source airport?" << endl;
            cin >> input;
            cout << "How many stops?" << endl;
            cin >> stops;
            set<Airport> k = manager.reachableAirports(input, stops);
            for (auto i: k) {
                cout << i.getCode() << endl;
            }
            cout << k.size() << endl;
            cout << "Want to see cities or countries?" << endl
                 << "1 Cities" << endl
                 << "2 Countries" << endl
                 << "3 No" << endl;
            cin >> option;
            switch(option) {
                case 1:
                    for(auto i: manager.findCities(k)) {
                        cout << i << endl;
                    }
                    startMenu();
                    break;
                case 2:
                    for(auto i: manager.findCountries(k)) {
                        cout << i << endl;
                    }
                    startMenu();
                    break;
                case 3:
                    startMenu();
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

void Menu::startOption6Menu() {
    vector<Coordinate> coordinates;
    int option;
    string input;
    double t;
    double g;
    Coordinate c;
    Coordinate cords;
    cout << "Insert the option you want for the source" << endl
         << "1 City" << endl
         << "2 Airport" << endl
         << "3 Coordinates" << endl;

    cin >> option;
    switch (option) {
        case 1:
            cout << "Insert the name of the city" << endl;
            getline(cin>>ws, input);
            for (auto a: manager.findAirportsByCity(input)) {
                airports1.insert(a);
            }
            startOption7Menu();
            break;
        case 2:
            cout << "Insert the code of the airport" << endl;
            cin >> input;
            airports1.insert(manager.findAirport(input));
            startOption7Menu();
            break;
        case 3:
            cout << "Insert latitude and longitude" << endl;
            cin >> t;
            cin >> g;
            c = Coordinate(t, g);
            for (auto a : manager.getAirports()){
                coordinates.push_back(a.getCoordinate());
            }
            cords = c.closest(coordinates);
            for (auto a : manager.getAirports()){
                    if (a.getCoordinate() == cords){
                        airports1.insert(a);
                    }
                }
            startOption7Menu();
            break;
        default:
            startMenu();
            break;
    }
}

void Menu::startOption7Menu() {
    vector<Coordinate> coordinates;
    int option;
    string input;
    int flag = 0;
    double t;
    double g;
    Coordinate c;
    Coordinate cords;
    cout << "Insert the option you want for the destination" << endl
         << "1 City" << endl
         << "2 Airport" << endl
         << "3 Coordinates" << endl;

    cin >> option;
    switch (option) {
        case 1:
            cout << "Insert the name of the city" << endl;
            getline(cin>>ws, input);
            for (auto a: manager.findAirportsByCity(input)) {
                airports2.insert(a);
            }
            for (auto a: manager.bestFLight(airports1, airports2, edges)) {
                flag = 0;
                for (auto b: a) {
                    if (flag == 0) {
                        cout << b.getName();
                        flag = 1;
                    } else {
                        cout << " -> " << b.getName();
                    }
                }
                cout << endl << "with " << a.size() - 1 << " flights" << endl;
            }
            break;
        case 2:
            cout << "Insert the code of the airport" << endl;
            cin >> input;
            airports2.insert(manager.findAirport(input));
            for (auto a: manager.bestFLight(airports1, airports2, edges)) {
                flag = 0;
                for (auto b: a) {
                    if (flag == 0) {
                        cout << b.getName();
                        flag = 1;
                    } else {
                        cout << " -> " << b.getName();
                    }
                }
                cout << endl << "with " << a.size() - 1 << " flights" << endl;
            }
            break;
        case 3:
            cout << "Insert latitude and longitude" << endl;
            cin >> t;
            cin >> g;
            c = Coordinate(t, g);
            for (auto a: manager.getAirports()) {
                coordinates.push_back(a.getCoordinate());
            }
            cords = c.closest(coordinates);
            for (auto a: manager.getAirports()) {
                if (a.getCoordinate() == cords) {
                    airports2.insert(a);
                }
            }

            for (auto a: manager.bestFLight(airports1, airports2, edges)) {
                flag = 0;
                for (auto b: a) {
                    if (flag == 0) {
                        cout << b.getName();
                        flag = 1;
                    } else {
                        cout << " -> " << b.getName();
                    }
                }
                cout << endl << "with " << a.size() - 1 << " flights" << endl;
            }
            break;
        default :
            startMenu();
            break;
    }
}




Menu::Menu(Manager manager) {
    this->manager = manager;
}

void Menu::startOption4Menu() {
    edges.clear();
   int option;
   string input;
   vector <string> inputs;
   edges.clear();
   int flag = 0;
    cout << "Do you want to filter airlines ?" << endl
         << "1 Yes" << endl
         << "2 No" << endl;
    cin >> option;
    switch (option){
        case 1:
            cout << "1 Remove airlines" << endl
                 << "2 Choose airlines" << endl;
            cin >> option;
            switch(option){
                case 1:
                    cout << "Insert the code of the airline" << endl
                            << "Insert End to stop" << endl;
                    cin >> input;
                    while(input != "End") {
                        edges.push_back(input);
                        cin >> input;
                    }
                    break;
                case 2:
                    cout << "Insert the code of the airline" << endl
                         << "Insert End to stop" << endl;
                    cin >> input;
                    while(input != "End") {
                        inputs.push_back(input);
                        cin >> input;
                    }
                    for (auto a: manager.getAirlines()){
                        for (auto in : inputs) {
                            if (a.getCode() != in) {
                                edges.push_back(a.getCode());
                            }
                        }
                    }
                    break;
            }
            startOption6Menu();
            break;
        case 2:
            startOption6Menu();
            break;
        default:
            startMenu();
            break;
    }
}

void Menu::startOption8Menu() {
   for (auto i: manager.longestTrips().first) {
       cout << i.first.getCode() << " -> " << i.second.getCode() << endl;
   }
   cout << "Having " << manager.longestTrips().second << " stops" << endl;
   startMenu();
}

void Menu::startOption9Menu() {
    int option;
    cout << "Whats the value of k?" << endl;
    cin >> option;
    cout << manager.getTraffic()[option].first.getCode() << "with " << manager.getTraffic()[option].second << " flights";
    startMenu();
}
void Menu::startOption10Menu() {
    for (auto i : manager.findArticulationPoints()) {
        cout << i.getCode() << endl;
    }
    cout << manager.findArticulationPoints().size();
    startMenu();
};