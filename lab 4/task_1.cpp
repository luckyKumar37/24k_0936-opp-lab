#include<iostream>
using namespace std;
class Car{
    private:
        string brand;
        string model;
        float price;
        bool availability;
    public:
        Car(){
            brand="Unknown";
            model="generic";
            price=0;
            availability=true;
        }
        bool availabilitycheck(){
            return availability;
        }
        
        void Requestrental(){
            if(availability){
                availability=false;
            }else{
                cout<<"Car is not available\n";
            }
            
        }
};
int main(){
    Car c1;
    c1.availabilitycheck();
    c1.Requestrental();
    c1.availabilitycheck();
    c1.Requestrental();

}
