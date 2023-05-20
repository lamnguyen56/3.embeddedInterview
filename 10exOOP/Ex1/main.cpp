/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-20
 * @desc [Calculate the distance and area of the triangle]
 */
#include <iostream>
#include <cmath>

using namespace std;

/*Class Point*/
class Point {
    private:
        double x;
        double y;
    public:
        Point(double x = 0, double y = 0);
        double distance(Point p);
};

/*
* Class: Triangle
* Description: Inherit from class point. 
*/
class Triangle : public Point {
    public:
        bool checkTriangle(Point a, Point b, Point c);
        double areaTriangle(Point a, Point b, Point c);
};

/*
* Class: Point
* Description: The constructor implementation for the Point class
*/
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

/*
* Class: Point
* Function: distance
* Description: This method calculates the distance between two points
* Input:
*   Point p
* Output:
*   return: distancs
*/
double Point::distance(Point p) {
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

/*
* Class: Triangle
* Function: checkTriangle
* Description: This method checks whether the given three points form a valid triangle.
* Input:
*   3 points
* Output:
*   return: 1 : Triangle
            0 : Not Triangle
*/
bool Triangle::checkTriangle(Point a, Point b, Point c) {
    double distanceAB, distanceBC, distanceAC;

    distanceAB = a.distance(b);
    distanceBC = b.distance(c);
    distanceAC = c.distance(a);

    return (distanceAB + distanceBC > distanceAC) &&
           (distanceAB + distanceAC > distanceBC) &&
           (distanceAC + distanceBC > distanceAB);
}

/*
* Class: Triangle
* Function: areaTriangle
* Description:  This method calculates the area of the triangle formed by the three given points.
*               The area is computed using Heron's formula and returned.
* Input:
*   3 points
* Output:
*   return: area of triangle
*/
double Triangle::areaTriangle(Point a, Point b, Point c) {
    if (checkTriangle(a, b, c)) {
        double distanceAB, distanceBC, distanceAC;

        distanceAB = a.distance(b);
        distanceBC = b.distance(c);
        distanceAC = c.distance(a);

        double s = (distanceAB + distanceBC + distanceAC) / 2;
        return sqrt(s * (s - distanceAB) * (s - distanceBC) * (s - distanceAC));
    } else {
        return -1;
    }
}

int main() {
    Point a;
    Point b(2, 3);
    Point c(7, 8);

    Triangle tg;

    cout << "Distance between A and B: " << a.distance(b) << endl;
    cout << "Distance between B and C: " << b.distance(c) << endl;
    cout << "Distance between C and A: " << c.distance(a) << endl;

    if (tg.checkTriangle(a, b, c)) {
        cout << "Area of Triangle: " << tg.areaTriangle(a, b, c) << endl;
    } else {
        cout << "These are not 3 points of a Triangle!" << endl;
    }

    return 0;
}
