#include<iostream>
using namespace std;

class Doctor{
private:
    string name;
    string specialization;
    string experience;

public:
    Doctor(){}
    Doctor(string n,string s,string e):
    name(n),specialization(s),experience(e){}

    void display() const{
        cout<<"Doctor's Name:"<<name<<endl;
        cout<<"Specialization:"<<specialization<<endl;
        cout<<"Experience:"<<experience<<endl;
    }
};

class Hospital{
private:
    string name;
    Doctor *doctors;
    int noOfDoctors;

public:
    Hospital(string n):
    name(n),noOfDoctors(0),
    doctors(new Doctor[20]){}

    ~Hospital(){
        delete[] doctors;
    }
    void addDoctor(const Doctor &d){
        doctors[noOfDoctors++]=d;
    }

    void display() const{
        cout<<"Hospital's Name:"<<name<<endl;
        cout<<"list of doctors\n";
        for(int i=0;i<noOfDoctors;i++){
            doctors[i].display();
        }
    }
};
int main(){
    Doctor d1("Marvin","cardio","3.5 years");
    Doctor d2("Martin","Pediatrician","2 years");
     
    Hospital h1("St Louis");
    h1.addDoctor(d1);
    h1.addDoctor(d2);
    h1.display();

}