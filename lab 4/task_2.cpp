#include<iostream>
using namespace std;
class Car{
    private:
        string brand;
        string model;
        float price;
        bool availability;
        float finalPrice=0;
    public:
        Car(){
            brand="Unknown";
            model="generic";
            price=0;
            availability=true;
        }
        Car(string b,string m,float p,bool a){
            brand=b;
            model=m;
            price=p;
            availability=a;
        }
        void applyDiscount(){
            int days=0;
            cout<<"Enter the number of days you want to ret car for:";
            cin>>days;
            float discount=0;
            if(days>5){
                discount=0.05;

            }else if(days>10){
                discount=0.10;
            }

            finalPrice=price*days*(1-discount);
        }
        bool availabilitycheck(){
            return availability;
        }
        void Requestrental(){
            if(availability){
                availability=false;
                cout<<"Car is rented successfully\n";
            }else{
                cout<<"Car is not available\n";
            }
            
        }
        
        void returnCar() {
            availability = true;
            cout << "Car returned successfully." << endl;
        }

        void Display(){
            cout<<"Brand: "<<brand<<endl;
            cout<<"Model: "<<model<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Final price: "<<finalPrice<<endl;
        }

};
int main(){
    Car c1("Toyota","Corolla 1.6",10000,true);
    c1.Display();
    c1.applyDiscount();
    cout<<"is car available:"<<c1.availabilitycheck()<<endl;
    c1.Requestrental();
    cout<<"is car available:"<<c1.availabilitycheck()<<endl;
    c1.Display();


}