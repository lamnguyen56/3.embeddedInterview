/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-20
 */
#include <iostream>
#include <string>

using namespace std;
/*Class Person*/
class Person {
private:
    string name;
    int age;
    string address;

public:
    Person(const string& name, int age, const string& address);
    void printInfo();
};

/*
* Class: Persion
* Description: The constructor implementation for the Animal class
*/
Person::Person(const string& name, int age, const string& address) {
    this->name = name;
    this->age = age;
    this->address = address;
}

/*
* Class: Persion
* Function: printInfo
* Description: This function use for print information of Persion
* Input:
*   Don't have input parameters
* Output:
*   Print: Nanme, Age, Address
*/
void Person::printInfo() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Address: " << address << endl;
}

int main() {
    Person person("Lam Nguyen", 23, "123 District 2");

    person.printInfo();


    return 0;
}
