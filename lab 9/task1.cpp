#include <iostream>
using namespace std;

class Patient
{
protected:
    string name;
    int id;

public:
    Patient(string name, int id) : name(name), id(id) {}
    virtual void displayTreatment() = 0;
    virtual int calculateCost() = 0;

};

class InPatient : public Patient
{
public:
    InPatient(string name, int id) : Patient(name, id) {}
    void displayTreatment()
    {
        cout << "Inpatient treatment for " << name << endl;
    }
    int calculateCost()
    {
        return 1000;
    }
};

class OutPatient : public Patient
{
public:
    OutPatient(string name, int id) : Patient(name, id) {}
    void displayTreatment()
    {
        cout << "Outpatient treatment for " << name << endl;
    }
    int calculateCost()
    {
        return 500;
    }
};
int main()
{
    Patient *p1 = new InPatient("John Doe", 1);
    Patient *p2 = new OutPatient("Jane Smith", 2);

    p1->displayTreatment();
    cout << "Cost: $" << p1->calculateCost() << endl;   
    p2->displayTreatment();
    cout << "Cost: $" << p2->calculateCost() << endl;

    
    delete p1;
    delete p2;
    return 0;
}