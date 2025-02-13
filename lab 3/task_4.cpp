#include<iostream>
using namespace std;
class Car{
    private:
        string Brand;
        string Model;
        float fuelCapacity;
        float currentFuelLevel;

    public:
        Car(){
            fuelCapacity=40;
            currentFuelLevel=0;
        }
        Car(string b,string m,float current){
            Brand=b;
            Model=m;
            fuelCapacity=40;
            currentFuelLevel=current;
        }
        void fuelUsed(float n){
            if(currentFuelLevel-n>=0){
                currentFuelLevel-=n;
            }else{
                cout<<"Invalid Fuel use\n";
            }
        }

        void Refuel(float n){
            if(n+currentFuelLevel<=fuelCapacity){
                currentFuelLevel+=n;
            }else{
                cout<<"Invalid fuel capacity\n";
            }
        }

        void fuelStatus(){
            if(currentFuelLevel==fuelCapacity){
                cout<<"Fuel tank is full\n";
            }else{
                cout<<"The current fuel level is "+to_string(currentFuelLevel)+" litres\n";
            }
        }


};
int main(){
    Car c1("Honda","Suv",20);
    c1.fuelUsed(10);
    c1.Refuel(15);
    c1.fuelStatus();
}