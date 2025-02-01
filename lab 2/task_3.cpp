#include<iostream>
using namespace std;
struct Employee
{
    string name;
    int hoursWorked;
    int hourlyRate;
};
void displayEmployee(Employee e1){
    cout<<"Employee name:"<<e1.name<<endl;
    cout<<"hours worked:"<<e1.hoursWorked<<endl;
    cout<<"hourly rate:"<<e1.hourlyRate<<endl;
}
void totalSalary(Employee e1){
    cout<<"Total salary:"<<e1.hoursWorked*e1.hourlyRate<<endl;
}

int main(){
    int n;
    cout<<"Enter number of Employees you want register:";
    cin>>n;
    Employee *employees=new Employee[n];
    for(int i=0;i<n;i++){
        cout<<"for Employee "<<i+1<<endl;
        cout<<"Enter name:";
        cin.ignore();
        getline(cin,employees[i].name);
        cout<<"Enter hours worked:";
        cin>>employees[i].hoursWorked;
        cout<<"Enter hourly rate:";
        cin>>employees[i].hourlyRate;
    }
    for(int i=0;i<n;i++){
        displayEmployee(employees[i]);
        totalSalary(employees[i]);
    }
    delete[] employees;

}