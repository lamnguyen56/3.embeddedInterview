#include "Table.h"

Table::Table() {
    isReserved = false;
}

void Table::reserveTable() {
    isReserved = true;
}

void Table::releaseTable() {
    isReserved = false;
}

bool Table::isTableReserved() {
    return isReserved;
}
