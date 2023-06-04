#ifndef TABLE_H
#define TABLE_H

#include <iostream>
//using namespace std;
class Table {
private:
    bool isReserved;

public:
    Table();

    void reserveTable();
    void releaseTable();
    bool isTableReserved();
};

#endif  // TABLE_H
