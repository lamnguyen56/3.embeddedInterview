/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-20
 * @desc [Caculate Periameter, Area, Diagonal of Rectangle and cheking Square]
 */

#include <bits/stdc++.h>

using namespace std;
/*Class Rectangle*/
class Rectangle
{
private:
    double length;
    double width;
public:
    Rectangle(double length, double width);
    double calPerimeter();
    double calArea();
    double calDiagonal();
    void checkSquare();
};

/*
* Class: Rectangle
* Description: The constructor implementation for the Rectangle class 
*/
Rectangle::Rectangle(double length, double width){
    this->length = length;
    this->width = width;
}

/*
* Class: Rectangle
* Function: calPerimeter
* Description: This method calculates the Perimeter of the Rectangle
* Input:
*   no input
* Output:
*   return: Perimeter
*/
double Rectangle::calPerimeter(){
    return (double)((this->length + this->width) * 2);
}

/*
* Class: Rectangle
* Function: calArea
* Description: This method calculates the Area of the Rectangle
* Input:
*   no input
* Output:
*   return: Area
*/
double Rectangle::calArea(){
    return (double)(this->length * this->width);
}

/*
* Class: Rectangle
* Function: calDiagonal
* Description: This method calculates the Diagonal of the Rectangle. Using Pythagorean theorem
* Input:
*   no input
* Output:
*   return: Diagonal
*/
double Rectangle::calDiagonal(){
    return (double)(sqrt(pow(this->length, 2) + pow(this->width, 2)));
}

/*
* Class: Rectangle
* Function: checkSquare
* Description: Here is the method to check if it is a square
*/
void Rectangle::checkSquare(){
    if(this->length == this->width){
        printf("This is square\n");
    }
    else{
        printf("This is not square\n");
    }
}

 int main(int argc, char const *argv[])
 {
    Rectangle rec(5, 3);

    cout << "Perimeter is: " << rec.calPerimeter() << endl;
    cout << "Area is: " << rec.calArea() << endl;
    cout << "Diagonal is: " << rec.calDiagonal() << endl;
    rec.checkSquare();
    return 0;
 }
 


