#include<iostream>
using namespace std;

class Apartment{
private:
    int apartmentID;
    string address;
    string* ownerName;

public:
    Apartment(int id,string a,string name):
    apartmentID(id),address(a),
    ownerName(new string(name)){}

    Apartment(const Apartment &A){
        apartmentID=A.apartmentID;
        address=A.address;
        ownerName=new string(*(A.ownerName));
    }

    ~Apartment(){
        delete ownerName;
    }

    void display() const{
        cout<<"Apartment ID:"<<apartmentID<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Owner's Name:"<<*ownerName<<endl;
    }
};
int main(){
    Apartment a(101,"12th Street london","Jon mclean");
    a.display();

    Apartment a2(a);
    a.display();

    return 0;
}