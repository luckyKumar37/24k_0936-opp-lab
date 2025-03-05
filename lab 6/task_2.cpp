#include<iostream>
using namespace std;

class Vehicle{
protected:
    string brand;
    int speed;

public:
    Vehicle(string b,int s):brand(b),speed(s){}

    void display() const{
        cout<<"Brand:"<<brand<<endl;
        cout<<"Speed:"<<speed<<endl;
    }
};

class Car: protected Vehicle{
protected:
    int seats;

public:
    Car(string b,int s,int seat):
    Vehicle(b,s),seats(seat){}

    void display() const{
        Vehicle::display();
        cout<<"no of Seats:"<<seats<<endl;
    }
};

class ElectricCar : private Car{
private:
    int batteryLife;

public:
    ElectricCar(string b,int s,int seat,int life):
    Car(b,s,seat),batteryLife(life){}

    void display() const{
        Car::display();
        cout<<"Battery Life:"<<batteryLife<<endl;
    }

};
int main(){
    ElectricCar myCar("Tesla", 200, 5, 400);
    
    myCar.display();

    return 0;
}