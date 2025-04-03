#include<iostream>
using namespace std;

class Account
{
private:
    int AccountNo;
    double balance;

public:
    Account(int accNo, double bal) : AccountNo(accNo), balance(bal) {}

    friend class Manager;
    friend void TransferFunds(Account &fromAcc, Account &toAcc, double amount);

};

class Manager
{
    public:
    void deposit(Account &acc, double amount)
    {
        acc.balance += amount;
    }
    void withdraw(Account &acc, double amount)
    {
        if (amount <= acc.balance)
            acc.balance -= amount;
        else
            cout << "Insufficient balance" << endl;
    }

    void display(Account &acc)
    {
        cout << "Account No: " << acc.AccountNo << endl;
        cout << "Balance: " << acc.balance << endl;
    }

};

void TransferFunds(Account &fromAcc, Account &toAcc, double amount)
{
    if (amount <= fromAcc.balance)
    {
        fromAcc.balance -= amount;
        toAcc.balance += amount;
    }
    else
        cout << "Insufficient balance" << endl;
}

int main()
{
    Account acc1(101, 5000.0), acc2(102, 3000.0);
    Manager mgr;

    cout << "Before Transfer:" << endl;
    mgr.display(acc1);
    mgr.display(acc2);

    TransferFunds(acc1, acc2, 2000.0);

    cout << "After Transfer:" << endl;
    mgr.display(acc1);
    mgr.display(acc2);

    mgr.deposit(acc1, 1000.0);
    cout << "After Deposit:" << endl;
    mgr.display(acc1);  


    mgr.withdraw(acc2, 500.0);
    cout << "After Withdrawal:" << endl;
    mgr.display(acc2);    

    return 0;
}
