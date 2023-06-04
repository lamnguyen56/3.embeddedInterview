#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>
#include "Menu.h"
//using namespace std;
class Manager {
private:
    std::vector<Menu>& menu;

public:
    Manager(std::vector<Menu>& menu);

    void addItem(Menu item);
    void updateItem(int itemId, Menu newItem);
    void deleteItem(int itemId);
    void displayMenu();
};

#endif  // MANAGER_H
