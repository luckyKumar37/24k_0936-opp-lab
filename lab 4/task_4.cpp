#include<iostream>
using namespace std;
class Car{
    private:
        string brand;
        string model;
        float price;
        bool availability;
        float totalRevenue;
    public:
        Car(){
            brand="Unknown";
            model="generic";
            price=0;
            availability=true;
            totalRevenue=0.0;
        }
        Car(string b,string m,float p,bool a,float R){
            brand=b;
            model=m;
            price=p;
            availability=a;
            totalRevenue=R;
        }

        void rentCar(int days){
            if(!availability){
                cout<<"Car is not available\n";
                return;
            }
            float discount=0;
            if(days>5){
                discount=0.05;

            }else if(days>10){
                discount=0.10;
            }

            float finalPrice=price*days*(1-discount);

            this->totalRevenue+=finalPrice;
            this->availability=false;

        }

        void returnCar() {
            availability = true;
            cout << "Car returned successfully." << endl;
        }
        bool availabilitycheck(){
            return availability;
        }
        void Display(){
            cout<<"Brand: "<<brand<<endl;
            cout<<"Model: "<<model<<endl;
            cout<<"Price: "<<price<<endl;
            cout<<"Total Revenue: "<<totalRevenue<<endl;
        }

        
        Car(const Car &obj){
            brand=obj.brand;
            model=obj.model;
            price=obj.price;
            availability=obj.availability;
            totalRevenue=obj.totalRevenue;
        }

        ~Car(){
            cout<<"Object is Destroyed\n";
        }
};

int main(){
    Car c1("Toyota","Corolla 1.6",10000,true,0);
    c1.Display();
    c1.rentCar(10);
    c1.Display();
    

}