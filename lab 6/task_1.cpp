#include<iostream>
using namespace std;

class Employee{
protected:
    string name;
    float salary;

public:
    Employee(string n,float s):name(n),salary(s){}

    void display() const{
        cout<<"Name:"<<name<<endl;
        cout<<"Salary:"<<salary<<endl;
    }
};

class Manager : private Employee{
private:
    float bonus;

public:
    Manager(string n,float s,float b)
    :Employee(n,s)
    ,bonus(b){}

    void display() const{
        Employee::display();
        cout<<"Bonus:"<<bonus<<endl;
    }
};
int main(){
    Manager m1("William",500000,50000);
    m1.display();
}