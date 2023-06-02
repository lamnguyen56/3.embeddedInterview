#include <iostream>
#include <vector>

using namespace std;

class Menu {
public:
    int id;
    double price;
    string name;

    Menu(int id, double price, string name) {
        this->id = id;
        this->price = price;
        this->name = name;
    }
};

class Manager {
//private:
   

public:
 vector<Menu> menu;
    void addItem(Menu item) {
        menu.push_back(item);
    }

    void updateItem(int itemId, Menu newItem) {
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].id == itemId) {
                menu[i] = newItem;
                break;
            }
        }
    }

    void deleteItem(int itemId) {
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i].id == itemId) {
                menu.erase(menu.begin() + i);
                break;
            }
        }
    }

    void displayMenu() {
        for (const auto& item : menu) {
            cout << "ID: " << item.id << ", Name: " << item.name << ", Price: " << item.price << endl;
        }
    }
};

class Table {
private:
    bool isReserved;

public:
    Table() {
        isReserved = true;
    }

    void reserveTable() {
        isReserved = true;
    }

    void releaseTable() {
        isReserved = false;
    }

    bool isTableReserved() {
        return isReserved;
    }
};

class Staff {
private:
    Manager manager;
    

public:
vector<Table> tables;
    vector<pair<int, Menu>> orders;
    Staff(Manager manager, vector<Table> tables) {
        this->manager = manager;
        this->tables = tables;
    }

    void placeOrder(int tableNumber, int itemId) {
        Table& table = tables[tableNumber];
        if (!table.isTableReserved()) {
            cout << "Table " << tableNumber << " is not reserved." << endl;
            return;
        }

        Menu* item = nullptr;
        for (auto& menu_item : manager.menu) {
            if (menu_item.id == itemId) {
                item = &menu_item;
                break;
            }
        }

        if (item == nullptr) {
            cout << "Invalid item ID." << endl;
            return;
        }

        orders.push_back(make_pair(tableNumber, *item));
        cout << "Item '" << item->name << "' added to table " << tableNumber << "." << endl;
    }

    void updateOrder(int tableNumber, int itemId, int newItemId) {
        for (auto& order : orders) {
            if (order.first == tableNumber && order.second.id == itemId) {
                Menu* newItem = nullptr;
                for (auto& menu_item : manager.menu) {
                    if (menu_item.id == newItemId) {
                        newItem = &menu_item;
                        break;
                    }
                }

                if (newItem == nullptr) {
                    cout << "Invalid new item ID." << endl;
                    return;
                }

                order.second = *newItem;
                cout << "Item in table " << tableNumber << " updated to '" << newItem->name << "'." << endl;
                return;
            }
        }

        cout << "Order not found." << endl;
    }

    void deleteOrder(int tableNumber, int itemId) {
        for (auto iter = orders.begin(); iter != orders.end(); ++iter) {
            if (iter->first == tableNumber && iter->second.id == itemId) {
                orders.erase(iter);
                cout << "Item '" << iter->second.name << "' removed from table " << tableNumber << "." << endl;
                return;
            }
        }

        cout << "Order not found." << endl;
    }

    void displayOrders() {
        for (const auto& order : orders) {
            cout << "Table: " << order.first << ", Item: " << order.second.name << endl;
        }
    }

    void calculateTotal(int tableNumber) {
        double total = 0;
        for (const auto& order : orders) {
            if (order.first == tableNumber) {
                total += order.second.price;
            }
        }

        cout << "Total for table " << tableNumber << ": " << total << endl;
    }
};

int main() {
    Manager manager;
    vector<Table> tables(2);  // 2 tables in the restaurant
    Staff staff(manager, tables);

    Menu item1(1, 10, "Item 1");
    Menu item2(2, 15, "Item 2");
    Menu item3(3, 20, "Item 3");
    manager.addItem(item1);
    manager.addItem(item2);
    manager.addItem(item3);

    while (true) {
        cout << "\nRestaurant Management System" << endl;
        cout << "1. Manager Mode" << endl;
        cout << "2. Staff Mode" << endl;
        cout << "3. Exit" << endl;
        cout << "Select mode: ";
        int choice;
        cin >> choice;
int i = 0;
            int i1 = 0;
        if (choice == 1) {
            while(i == 0 ){
            cout << "\nManager Mode" << endl;
            cout << "1. Add Item" << endl;
            cout << "2. Update Item" << endl;
            cout << "3. Delete Item" << endl;
            cout << "4. Display Menu" << endl;
            cout << "5. Back" << endl;
            cout << "Select an action: ";
            int managerChoice;
            cin >> managerChoice;

            if (managerChoice == 1) {
                int itemId;
                double itemPrice;
                string itemName;
                cout << "Enter item ID: ";
                cin >> itemId;
                cout << "Enter item price: ";
                cin >> itemPrice;
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, itemName);
                Menu newItem(itemId, itemPrice, itemName);
                manager.addItem(newItem);
                cout << "Item added." << endl;
            } else if (managerChoice == 2) {
                int itemId, newItemId;
                double newItemPrice;
                string newItemName;
                cout << "Enter item ID to update: ";
                cin >> itemId;
                cout << "Enter new item price: ";
                cin >> newItemPrice;
                cout << "Enter new item name: ";
                cin.ignore();
                getline(cin, newItemName);
                cout << "Enter new item ID: ";
                cin >> newItemId;
                Menu newItem(newItemId, newItemPrice, newItemName);
                manager.updateItem(itemId, newItem);
                cout << "Item updated." << endl;
            } else if (managerChoice == 3) {
                int itemId;
                cout << "Enter item ID to delete: ";
                cin >> itemId;
                manager.deleteItem(itemId);
                cout << "Item deleted." << endl;
            } else if (managerChoice == 4) {
                cout << "\nMenu:" << endl;
                manager.displayMenu();
            } else if (managerChoice == 5) {
                i=1;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
            }
        } else if (choice == 2) {
            while (i1 == 0){
            
            
            cout << "\nStaff Mode" << endl;
            cout << "1. Place Order" << endl;
            cout << "2. Update Order" << endl;
            cout << "3. Delete Order" << endl;
            cout << "4. Display Orders" << endl;
            cout << "5. Calculate Total" << endl;
            cout << "6. Back" << endl;
            cout << "Select an action: ";
            int staffChoice;
            cin >> staffChoice;
            
           if (staffChoice == 1) {
                int tableNumber, itemId;
                cout << "Enter table number: ";
                cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    cout << "Table " << tableNumber << " is not reserved." << endl;
                    continue;
                }
                cout << "Enter item ID to order: ";
                cin >> itemId;
                staff.placeOrder(tableNumber, itemId);
            } else if (staffChoice == 2) {
                int tableNumber, itemId, newItemId;
                cout << "Enter table number: ";
                cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    cout << "Table " << tableNumber << " is not reserved." << endl;
                    continue;
                }
                cout << "Enter item ID to update: ";
                cin >> itemId;
                cout << "Enter new item ID: ";
                cin >> newItemId;
                staff.updateOrder(tableNumber, itemId, newItemId);
            } else if (staffChoice == 3) {
                int tableNumber, itemId;
                cout << "Enter table number: ";
                cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    cout << "Table " << tableNumber << " is not reserved." << endl;
                    continue;
                }
                cout << "Enter item ID to delete: ";
                cin >> itemId;
                staff.deleteOrder(tableNumber, itemId);
            } else if (staffChoice == 4) {
                cout << "\nOrders:" << endl;
                staff.displayOrders();
            } else if (staffChoice == 5) {
                int tableNumber;
                cout << "Enter table number: ";
                cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    cout << "Table " << tableNumber << " is not reserved." << endl;
                    continue;
                }
                staff.calculateTotal(tableNumber);
            } else if (staffChoice == 6) {
                i1 == 1;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
            }
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
