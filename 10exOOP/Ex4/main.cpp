/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-20
 * @desc [description]
 */
#include <iostream>
#include <string>

using namespace std;

/*Class Animal*/
class Animal {
private:
    string name;
    int age;
    double weight;

public:
    Animal(const string& name, int age, double weight);
    string getName();
    double calculateBMI();
    bool compareAge( Animal& other);
    bool compareWeight( Animal& other);
};

/*
* Class: Animal
* Description: The constructor implementation for the Animal class
*/
Animal::Animal(const  string& name, int age, double weight) {
    this->name = name;
    this->age = age;
    this->weight = weight;
}

/*
* Class: Animal
* Function: getName
* Description: This function use for get name of animal
* Input:
*   Don't have input parameters
* Output:
*   return: name of animal
*/
string Animal::getName()  {
    return name;
}

/*
* Class: Animal
* Function: calculateBMI
* Description: This function use for calculate BMI of animal
* Input:
*   Don't have input parameters
* Output:
*   return: BMI
*/
double Animal::calculateBMI()  {
    double height = 1.0; // Giả sử chiều cao = 1
    return weight / (height * height);
}

/*
* Class: Animal
* Function: compareAge
* Description: This function use for compareAge of animal
* Input:
*   Animal& other
* Output:
*   return: 1: if age < other.age
            0: otherwise
*/
bool Animal::compareAge( Animal& other)  {
    return age < other.age;
}

/*
* Class: Animal
* Function: compareWeight
* Description: This function use for compareWeight of animal
* Input:
*   Animal& other
* Output:
*   return: 1: if weight < other.weigh
            0: otherwise
*/
bool Animal::compareWeight( Animal& other)  {
    return weight < other.weight;
}

int main() {
    Animal dog("Dog", 5, 10.5);
    Animal cat("Cat", 3, 7.2);

    cout << "Dog's BMI: " << dog.calculateBMI() << endl;
    cout << "Cat's BMI: " << cat.calculateBMI() << endl;

    if (dog.compareAge(cat)) {
        cout << dog.getName() << " is younger than " << cat.getName() << endl;
    } else {
        cout << dog.getName() << " is older than " << cat.getName() << endl;
    }

    if (dog.compareWeight(cat)) {
        cout << dog.getName() << " weighs less than " << cat.getName() << endl;
    } else {
        cout << dog.getName() << " weighs more than " << cat.getName() << endl;
    }

    return 0;
}

