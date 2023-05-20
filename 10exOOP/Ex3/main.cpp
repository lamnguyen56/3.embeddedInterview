/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-20
 * @desc [Calculate the circumference and area of a circle]
 */

#include <bits/stdc++.h>
using namespace std;

/*Class Circle*/
class Circle {
private:
    double radius;
public:
    Circle(double r);
    double getRadius();
    double getArea();
    double getCircumference();
};

/*
* Class: Circle
* Description: The constructor implementation for the Circle class
*/
Circle::Circle(double r) {
    radius = r;
}

/*
* Class: Circle
* Function: getRadius
* Description: This method get Radius
* Input:
*   no input
* Output:
*   return: radius
*/
double Circle::getRadius(){
    return radius;
}

/*
* Class: Circle
* Function: getArea
* Description: This method get Area of the Circle
* Input:
*   no input
* Output:
*   return: Area
*/
double Circle::getArea(){
    return M_PI * radius * radius;
}

/*
* Class: Circle
* Function: getCircumference
* Description: This method get Circumference of the Circle
* Input:
*   no input
* Output:
*   return: Circumference
*/
double Circle::getCircumference(){
    return 2 * M_PI * radius;
}

int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    Circle circle(radius);

    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Area: " << circle.getArea() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;

    return 0;
}

