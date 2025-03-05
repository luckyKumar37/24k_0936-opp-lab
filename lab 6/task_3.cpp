#include<iostream>
using namespace std;

class Person{
protected:
    string name;
    int age;

public:
    Person(string n,int a):name(n),age(a){}

    void display() const{
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
    }
};

class Teacher : protected Person{
protected:
    string subject;

public:
    Teacher(string n,int a,string s):
    Person(n,a),subject(s){}

    void display() const{
        Person::display();
        cout<<"Subject:"<<subject<<endl;
    }
};

class Researcher: protected Teacher{
protected:
    string researchArea;

public:
    Researcher(string n,int a,string s,string research):
    Teacher(n,a,s),researchArea(research){}

    void display() const{
        Teacher::display();
        cout<<"Research Area:"<<researchArea<<endl;
    }
};

class Professor : protected Researcher{
private:
    int publications;

public:
    Professor(string n,int a,string s,string research,int p):
    Researcher(n,a,s,research),publications(p){}

    void display() const{
        Researcher::display();
        cout<<"Publication:"<<publications<<endl;
    }
};

int main() {
    Professor prof("Dr. John Doe", 50, "Computer Science", "Artificial Intelligence", 100);
    
    prof.display();

    return 0;
}
