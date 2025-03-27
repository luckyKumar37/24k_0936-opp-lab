#include<iostream>
#include<string>
using namespace std;

class person
{
protected:
    string name;
    int age;
    string contactNumber;
    string address;
public:
    person(string n, int a, string c, string ad)
    {
        name = n;
        age = a;
        contactNumber = c;
        address = ad;
    }
    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }

    virtual void updateInfo(string n, int a, string c, string ad)
    {
        name = n;
        age = a;
        contactNumber = c;
        address = ad;
    }

};

class patient: public person
{
    string patientID;
    string doctorAssigned;
    string medicalHistory;
public:
    patient(string n, int a, string c, string ad, string id, string doc, string med): person(n, a, c, ad)
    {
        patientID = id;
        doctorAssigned = doc;
        medicalHistory = med;
    }

    void display() override
    {
        person::display();
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
        cout << "Medical History: " << medicalHistory << endl;
    }

    void updateInfo(string n, int a, string c, string ad, string id, string doc, string med)
    {
        person::updateInfo(n, a, c, ad);
        patientID = id;
        doctorAssigned = doc;
        medicalHistory = med;
    }
};

class doctor: public person
{
    string specialization;
    float consultationFee;
    string patientlist[5];

public:
    doctor(string n, int a, string c, string ad, string spec, float fee): person(n, a, c, ad)
    {
        specialization = spec;
        consultationFee = fee;
        for(int i = 0; i < 5; i++)
        {
            patientlist[i] = "";
        }
    }

    void display() override
    {
        person::display();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Patient List: " << endl;
        for(int i = 0; i < 5; i++)
        {
            cout << patientlist[i] << endl;
        }
    }

    void addPatient(string patientName)
    {
        for(int i = 0; i < 5; i++)
        {
            if(patientlist[i] == "")
            {
                patientlist[i] = patientName;
                break;
            }
        }
    }

    void removePatient(string patientName)
    {
        for(int i = 0; i < 5; i++)
        {
            if(patientlist[i] == patientName)
            {
                patientlist[i] = "";
                break;
            }
        }
    }
};

class Nurse: public person
{
    string assignedWard;
    string shiftTiming;
public:
    Nurse(string n, int a, string c, string ad, string ward, string shift): person(n, a, c, ad)
    {
        assignedWard = ward;
        shiftTiming = shift;
    }

    void display() override
    {
        person::display();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timing: " << shiftTiming << endl;
    }


};

class Administator: public person
{
    string department;
    float salary;
public:
    Administator(string n, int a, string c, string ad, string dept, float sal): person(n, a, c, ad)
    {
        department = dept;
        salary = sal;
    }

    void display() override
    {
        person::display();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }

    void updateInfo(string n, int a, string c, string ad, string dept, float sal)
    {
        person::updateInfo(n, a, c, ad);
        department = dept;
        salary = sal;
    }
};

int main()
{
    patient p1("Ali", 25, "03001234567", "House 123, Street 45, Islamabad", "P001", "Dr. Ahmed", "None");
    doctor d1("Dr. Ahmed", 35, "03001234567", "House 123, Street 45, Islamabad", "Cardiologist", 5000);
    Nurse n1("Sara", 30, "03001234567", "House 123, Street 45, Islamabad", "Ward 1", "Morning");
    Administator a1("John", 40, "03001234567", "House 123, Street 45, Islamabad", "HR", 10000);

    cout << "Patient Details:" << endl;
    p1.display();
    cout << endl;

    cout << "Doctor Details:" << endl;
    d1.display();
    cout << endl;

    cout << "Nurse Details:" << endl;
    n1.display();
    cout << endl;

    cout << "Administator Details:" << endl;
    a1.display();
    cout << endl;

    cout << "Updating Patient Details:" << endl;
    p1.updateInfo("Ali", 25, "03001234567", "House 123, Street 45, Islamabad", "P001", "Dr. Ahmed", "Heart Disease");
    p1.display();
    cout << endl;

    cout << "Updating Administator Details:" << endl;
    a1.updateInfo("John", 40, "03001234567", "House 123, Street 45, Islamabad", "Finance", 15000);
    a1.display();
    cout << endl;

    cout << "Adding Patient to Doctor's List:" << endl;
    d1.addPatient("Ali");
    d1.display();
    cout << endl;

    cout << "Removing Patient from Doctor's List:" << endl;
    d1.removePatient("Ali");
    d1.display();
    cout << endl;

    return 0;
}