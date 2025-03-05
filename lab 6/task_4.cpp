#include<iostream>
using namespace std;

class Account{
protected:
    int accountNumber;
    float balance;
    
public:
    Account(int number,float b):
    accountNumber(number),balance(b){}

    void display() const{
        cout<<"Account no:"<<accountNumber<<endl;
        cout<<"Balance:"<<balance<<endl;
    }
};

class SavingAccount : private Account{
private:
    float interestRate;

public:
    SavingAccount(int number,float b,float rate):
    Account(number,b),interestRate(rate){}

    void display() const{
        Account::display();
        cout<<"Interest Rate:"<<interestRate<<endl;
    }
};

class CheckingAccount : private Account{
private:
    float overDraftLimit;

public:
    CheckingAccount(int number,float b,float limit):
    Account(number,b),overDraftLimit(limit){}

    void display() const{
        Account::display();
        cout<<"Over Draft Limit:"<<overDraftLimit<<endl;
    }
};

int main(){
    SavingAccount s(101, 5000.0, 3.5);
    CheckingAccount c(102, 2000.0, 1000.0);

    cout<<"Saving Account\n";
    s.display();
    cout << "-------------------" << endl;

    cout<<"Checking Account\n";
    c.display();

    return 0;
}
