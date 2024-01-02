#include <iostream>

#include "src/header/manager.h"
#include "src/header/menu.h"

int main() {
    Manager manager = Manager();
    Menu menu = Menu(manager);
    menu.start();
    menu.startMenu();
}
