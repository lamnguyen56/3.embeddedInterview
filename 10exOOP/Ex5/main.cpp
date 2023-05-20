/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-20
 */
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string address;

public:
    Person(const string& name, int age, const string& address);
    void printInfo();
};

Person::Person(const string& name, int age, const string& address) {
    this->name = name;
    this->age = age;
    this->address = address;
}

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
