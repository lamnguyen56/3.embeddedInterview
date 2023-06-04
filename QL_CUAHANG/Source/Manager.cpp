#include "Manager.h"

Manager::Manager(std::vector<Menu>& menu) : menu(menu) {}

void Manager::addItem(Menu item) {
    menu.push_back(item);
}

void Manager::updateItem(int itemId, Menu newItem) {
    for (int i = 0; i < menu.size(); i++) {
        if (menu[i].id == itemId) {
            menu[i] = newItem;
            break;
        }
    }
}

void Manager::deleteItem(int itemId) {
    for (int i = 0; i < menu.size(); i++) {
        if (menu[i].id == itemId) {
            menu.erase(menu.begin() + i);
            break;
        }
    }
}

void Manager::displayMenu() {
    for (const auto& item : menu) {
        std::cout << "ID: " << item.id << ", Name: " << item.name << ", Price: " << item.price << std::endl;
    }
}
