/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-22
 * @desc [description]
 */
#include <iostream>

using namespace std;

/*Class Car*/
class Car{
    private:
        string color;
        string engineType;
        int odometer;
    public:
        Car(string color, string engineType, int odometer);
        int maintenanceCost();
        int getOdometer();
        void printInfo();
};

/*
* Class: CAr
* Description: The constructor implementation for the Car class
*/
Car :: Car(string color, string engineType, int odometer){
    this->color = color;
    this->engineType = engineType;
    this->odometer = odometer;
}

/*
* Class: Car
* Function: maintenanceCost
* Description: This method maintenance cost of the car
* Input:
*   no input
* Output:
*   return cost
*/
int Car::maintenanceCost(){
    // Giả sử chi phí bảo trì là 1000 * số km đã đi
    return 1000*this->odometer;
}

/*
* Class: Car
* Function: getOdometer
* Description: This method get Odometer
* Input:
*   no input
* Output:
*   return odometer
*/
int Car :: getOdometer(){
    return this->odometer;
}

/*
* Class: Car
* Function: printInfo
* Description: This method print Information Car
* Input:
*   no input
* Output:
*   None
*/
void Car :: printInfo(){
    cout << "Color: " << this->color << endl;
    cout << "Type of Engine: " << this->engineType << endl;
    cout << "Odometer: " << this->odometer << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    Car audi("Grey", "V8", 20000);
    audi.printInfo();
    cout << "Maintenance cost for " << audi.getOdometer() << " km is " << audi.maintenanceCost() << endl;
    return 0;
}
