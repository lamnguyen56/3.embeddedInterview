/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-21
 * @desc [description]
 */

#include <iostream>
#include <ctime>

using namespace std;

/*Class Date*/
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 1, int month = 1, int year = 2000);
    int getDay() const; 
    int getMonth() const; 
    int getYear() const; 
    void calculateHoliday();
};

/*Class Person*/
class Person : public Date {
public:
    Person(int day, int month, int year) : Date(day, month, year) {}
    void calculateAge();
};

/*
* Class: Date
* Description: The constructor implementation for the Date class
*/
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

/*
* Class: Date
* Function: getDay
* Description: This method get the day
* Input:
*   none
* Output:
*   return day
*/
int Date::getDay() const {
    return day;
}

/*
* Class: Date
* Function: getMonth
* Description: This method get month
* Input:
*   none
* Output:
*   return month
*/
int Date::getMonth() const {
    return month;
}

/*
* Class: Date
* Function: getYear
* Description: This method get year
* Input:
*   none
* Output:
*   return year
*/
int Date::getYear() const {
    return year;
}

/*
* Class: Date
* Function: calculateHoliday
* Description: This method calculate hoilday
* Input:
*   none
* Output:
*   calculate holiday and print
*/
void Date::calculateHoliday() {
    if ((this->month == 1 && this->day == 1) || (this->day == 30 && this->month == 4)) {
        cout << "Date: " << getDay() << "/" << getMonth() << " is a holiday" << endl;
    } else {
        cout << "Date: " << getDay() << "/" << getMonth() << " is not a holiday" << endl;
    }
}

/*
* Class: Person
* Function: calculateAge
* Description: This method calculate Age
* Input:
*   none
* Output:
*   return age of person
*/
void Person::calculateAge() {
    // Lấy ngày, tháng, năm hiện tại
    time_t now = time(0);
    tm* currentDate = localtime(&now);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;

    int age = currentYear - getYear();

    // Kiểm tra nếu tháng và ngày hiện tại chưa vượt qua tháng và ngày của sinh nhật trong năm nay
    if (currentMonth < getMonth() || (currentMonth == getMonth() && currentDay < getDay())) {
        age--;
    }

    cout << "Tuoi cua nguoi: " << age << endl;
}

int main() {

    Person lam(5, 6, 2001);
    Person binh(30, 8, 2000);

    // Tính tuổi của người
    lam.calculateAge();
    binh.calculateAge();

    // Kiểm tra ngày có phải là ngày nghỉ lễ hay không
    lam.calculateHoliday();
    binh.calculateHoliday();

    return 0;
}
