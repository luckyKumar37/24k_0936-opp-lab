#include<iostream>
using namespace std;

class Employee{
private:
    string name;
    string designation;

public:
    Employee(){}
    Employee(string name,string d):
    name(name),designation(d){}

    void display() const{
        cout<<"Employee Name:"<<name<<endl;
        cout<<"Designation:"<<designation<<endl;
    }
};

class Project{
private:
    string title;
    string deadline;
    Employee *employees;
    int noOfEmployees=0;

public:
    Project(string t,string d):
    title(t),deadline(d){
        employees=new Employee[10];
    }

    void addEmployee(const Employee &e){
        employees[noOfEmployees++]=e;
    }

    void display() const{
        cout<<"Project Title:"<<title<<endl;
        cout<<"Project Deadline:"<<deadline<<endl;
        cout<<"Employees in project:"<<endl;
        for(int i=0;i<noOfEmployees;i++){
            employees[i].display();
        }
    }
};
int main(){
    Employee e1("Steve","assistant Manager");
    Employee e2("Alex","Graphic designer");
    Employee e3("Mitchell","software developer");
     
    Project p1("Prirate game","12th December 2025");
    Project p2("Death shoot game","21 january 2026");

    p1.addEmployee(e1);
    p1.addEmployee(e3);
    p2.addEmployee(e2);
    p2.addEmployee(e1);
    p2.addEmployee(e3);
    cout<<"Project details\n";
    p1.display();

    cout<<"Project details\n";
    p2.display();
    return 0;
}