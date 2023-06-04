#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <vector>
#include "Menu.h"
#include "Table.h"
//using namespace std;
class Staff {
private:
    std::vector<Menu>& menu;
    std::vector<Table> tables;
    std::vector<std::pair<int, Menu>> orders;

public:
    Staff(std::vector<Menu>& menu, std::vector<Table> tables);

    void placeOrder(int tableNumber, int itemId);
    void updateOrder(int tableNumber, int itemId, int newItemId);
    void deleteOrder(int tableNumber, int itemId);
    void displayOrders();
    void calculateTotal(int tableNumber);
};

#endif  // STAFF_H
