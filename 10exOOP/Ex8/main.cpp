/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-22
 * @desc [Account Bank]
 */

#include <iostream>

using namespace std;

/*Class Accountbank*/
class AccountBank{
    private: 
        uint16_t accountNumber;
        uint16_t accountBalance;
        string accountName;
    public:
        AccountBank(string accName, uint16_t accNum, uint16_t accBal);
        void withdrawMoney(uint16_t money);
        void depositMoney(uint16_t money);
        void checkBalance();
};

/*
* Class: AccountBank
* Description: The constructor implementation for the AccountBank class
*/
AccountBank :: AccountBank(string accName, uint16_t accNum, uint16_t accBal){
    this->accountName = accName;
    this->accountBalance = accBal;
    this->accountNumber = accNum;
}

/*
* Class: AccountBank
* Function: withdrawMoney
* Description: This method with drarw money
* Input:
*   money
* Output:
*   
*/
void AccountBank :: withdrawMoney(uint16_t money){
    this->accountBalance = this->accountBalance - money;
    cout << "You have withdrawn " << "$" << money << endl;
}

/*
* Class: AccountBank
* Function: depositMoney
* Description: This method deposit money
* Input:
*   money
* Output:
*   
*/
void AccountBank :: depositMoney(uint16_t money){
    this->accountBalance = this->accountBalance + money;
    cout << "You have deposited $" << money << " into your account " << endl;
}

/*
* Class: AccountBank
* Function: checkBalance
* Description: This method check Balance
* Input:
*   None
* Output:
*   None
*/
void AccountBank :: checkBalance(){
    cout << this->accountName <<  " Balance: " << this->accountBalance << endl;
}

int main(int argc, char const *argv[])
{
    AccountBank lam("Lam", 0123, 100);
    
    lam.checkBalance();
    lam.depositMoney(100);
    lam.checkBalance();
    lam.withdrawMoney(50);
    lam.checkBalance();
    
    return 0;
}
