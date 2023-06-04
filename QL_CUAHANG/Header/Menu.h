#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>

//using namespace std;

class Menu {
public:
    int id;
    double price;
    std::string name;

    Menu(int id, double price, std::string name);
};

#endif  // MENU_H
