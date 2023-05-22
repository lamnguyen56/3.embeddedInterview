/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-05-22
 * @desc [description]
 */

#include <iostream>

/*
Tạo một lớp tài khoản ngân hàng với các thuộc tính số tài khoản, tên tài
 khoản và  số dư, và các phương thức để rút, nộp tiền và kiểm tra số dư trong tài khoản.
*/
using namespace std;

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

AccountBank :: AccountBank(string accName, uint16_t accNum, uint16_t accBal){
    this->accountName = accName;
    this->accountBalance = accBal;
    this->accountNumber = accNum;
}

void AccountBank :: withdrawMoney(uint16_t money){
    this->accountBalance = this->accountBalance - money;
    cout << "You have withdrawn " << "$" << money << endl;
}

void AccountBank :: depositMoney(uint16_t money){
    this->accountBalance = this->accountBalance + money;
    cout << "You have deposited $" << money << " into your account " << endl;
}

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
