#include "Staff.h"

Staff::Staff(std::vector<Menu>& menu, std::vector<Table> tables) : menu(menu), tables(tables) {}

void Staff::placeOrder(int tableNumber, int itemId) {

    if (!tables[tableNumber].isTableReserved()) {
        std::cout << "Table " << tableNumber << " is not reserved." << std::endl;
        return;
    }

    Menu* item = nullptr;
    for (auto& menu_item : menu) {
        if (menu_item.id == itemId) {
            item = &menu_item;
            break;
        }
    }

    if (item == nullptr) {
        std::cout << "Invalid item ID." << std::endl;
        return;
    }

    orders.push_back(std::make_pair(tableNumber, *item));
    std::cout << "Item '" << item->name << "' added to table " << tableNumber << "." << std::endl;
}

void Staff::updateOrder(int tableNumber, int itemId, int newItemId) {
    // Rest of the code...
     for (auto& order : orders) {
            if (order.first == tableNumber && order.second.id == itemId) {
                Menu* newItem = nullptr;
                for (auto& menu_item : menu) {
                    if (menu_item.id == newItemId) {
                        newItem = &menu_item;
                        break;
                    }
                }

                if (newItem == nullptr) {
                    std::cout << "Invalid new item ID." << std::endl;
                    return;
                }

                order.second = *newItem;
                std::cout << "Item in table " << tableNumber << " updated to '" << newItem->name << "'." << std::endl;
                return;
            }
        }

        std::cout << "Order not found." << std::endl;
    }


void Staff::deleteOrder(int tableNumber, int itemId) {
    // Rest of the code...
    for (auto iter = orders.begin(); iter != orders.end(); ++iter) {
            if (iter->first == tableNumber && iter->second.id == itemId) {
                orders.erase(iter);
                std::cout << "Item '" << iter->second.name << "' removed from table " << tableNumber << "." << std::endl;
                return;
            }
        }

        std::cout << "Order not found." << std::endl;
}

void Staff::displayOrders() {
    // Rest of the code...
    for (const auto& order : orders) {
            std::cout << "Table: " << order.first << ", Item: " << order.second.name << std::endl;
        }
}

void Staff::calculateTotal(int tableNumber) {
    // Rest of the code...
    double total = 0;
        for (const auto& order : orders) {
            if (order.first == tableNumber) {
                total += order.second.price;
            }
        }

        std::cout << "Total for table " << tableNumber << ": " << total << std::endl;
    }

