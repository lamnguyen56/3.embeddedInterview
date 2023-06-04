#include <iostream>
#include <vector>
#include "Manager.h"
#include "Staff.h"

using namespace std;

int main() {
    std::vector<Menu> menu;
    std::vector<Table> tables(2, Table());  // 2 tables in the restaurant
    tables[0].reserveTable();
    tables[1].reserveTable();

    Manager manager(menu);
    Staff staff(menu, tables);

    // Rest of the code...
    int choice;
    while (true) {
        std::cout << "\nRestaurant Management System" << std::endl;
        std::cout << "1. Manager Mode" << std::endl;
        std::cout << "2. Staff Mode" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Select mode: ";
        std::cin >> choice;
            
            int i = 0;
            
            int i1 = 0;
            
        if (choice == 1) {
            while(i == 0 ){
            std::cout << "\nManager Mode" << std::endl;
            std::cout << "1. Add Item" << std::endl;
            std::cout << "2. Update Item" << std::endl;
            std::cout << "3. Delete Item" << std::endl;
            std::cout << "4. Display Menu" << std::endl;
            std::cout << "5. Back" << std::endl;
           std::cout << "Select an action: ";
            int managerChoice;
            std::cin >> managerChoice;

            if (managerChoice == 1) {
                
                

                int itemId;
                double itemPrice;
                string itemName;
                std::cout << "Enter item ID: ";
                std::cin >> itemId;
                std::cout << "Enter item name: ";
                std::cin.ignore();
                getline(std::cin, itemName);
                std::cout << "Enter item price: ";
                std::cin >> itemPrice;
                
                Menu newItem(itemId, itemPrice, itemName);
                manager.addItem(newItem);
                std::cout << "Item added." << std::endl;
            } else if (managerChoice == 2) {
                int itemId, newItemId;
                double newItemPrice;
                std::string newItemName;
                std::cout << "Enter item ID to update: ";
                std::cin >> itemId;
                std::cout << "Enter new item ID: ";
                std::cin >> newItemId;
                std::cout << "Enter new item name: ";
                std::cin.ignore();
                getline(std::cin, newItemName);
                std::cout << "Enter new item price: ";
                std::cin >> newItemPrice;
                
                
                Menu newItem(newItemId, newItemPrice, newItemName);
                manager.updateItem(itemId, newItem);
                std::cout << "Item updated." << std::endl;
            } else if (managerChoice == 3) {
                int itemId;
                std::cout << "Enter item ID to delete: ";
                std::cin >> itemId;
                manager.deleteItem(itemId);
                std::cout << "Item deleted." << std::endl;
            } else if (managerChoice == 4) {
                std::cout << "\nMenu:" << std::endl;
                manager.displayMenu();
            } else if (managerChoice == 5) {
                i=1;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
            }
        } else if (choice == 2) {

                while (i1 == 0){

            std::cout << "\nStaff Mode" << std::endl;
            std::cout << "1. Place Order" << std::endl;
            std::cout << "2. Update Order" << std::endl;
            std::cout << "3. Delete Order" << std::endl;
            std::cout << "4. Display Orders" << std::endl;
            std::cout << "5. Calculate Total" << std::endl;
            std::cout << "6. Back" << std::endl;
           std::cout << "Select an action: ";
            int staffChoice;
            std::cin >> staffChoice;

            if (staffChoice == 1) {
                int tableNumber, itemId;
                std::cout << "Enter table number: ";
                std::cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    std::cout << "Table " << tableNumber << " is not reserved." << std::endl;
                    continue;
                }
                std::cout << "Enter item ID to order: ";
                std::cin >> itemId;
                staff.placeOrder(tableNumber, itemId);
            } else if (staffChoice == 2) {
                int tableNumber, itemId, newItemId;
                std::cout << "Enter table number: ";
                std::cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    std::cout << "Table " << tableNumber << " is not reserved." << std::endl;
                    continue;
                }
                std::cout << "Enter item ID to update: ";
                std::cin >> itemId;
                std::cout << "Enter new item ID: ";
                std::cin >> newItemId;
                staff.updateOrder(tableNumber, itemId, newItemId);
            } else if (staffChoice == 3) {
                int tableNumber, itemId;
                std::cout << "Enter table number: ";
                std::cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    std::cout << "Table " << tableNumber << " is not reserved." << std::endl;
                    continue;
                }
                std::cout << "Enter item ID to delete: ";
                std::cin >> itemId;
                staff.deleteOrder(tableNumber, itemId);
            } else if (staffChoice == 4) {
                std::cout << "\nOrders:" << std::endl;
                staff.displayOrders();
            } else if (staffChoice == 5) {
                int tableNumber;
                std::cout << "Enter table number: ";
                std::cin >> tableNumber;
                if (!tables[tableNumber].isTableReserved()) {
                    std::cout << "Table " << tableNumber << " is not reserved." << std::endl;
                    continue;
                }
                staff.calculateTotal(tableNumber);
            } else if (staffChoice == 6) {
                i1=1;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
                }
        } else if (choice == 3) {
            std::cout << "Exiting..." << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}
