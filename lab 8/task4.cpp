#include<iostream>
using namespace std;

class Car
{
private:
    string Model;
    double price;

public:
    Car(string model, double price) : Model(model), price(price) {}

    friend class Inventorymanager;
    friend void ComparePrice(Car &car1, Car &car2);
};

class Inventorymanager
{
public:
    void updatePrice(Car &car, double newPrice)
    {
        car.price = newPrice;
    }
    void display(Car &car)
    {
        cout << "Model: " << car.Model << endl;
        cout << "Price: " << car.price<<"$" << endl;
    }
};

void ComparePrice(Car &car1, Car &car2)
{
    if (car1.price > car2.price)
    {
        cout << car1.Model << " is more expensive than " << car2.Model << endl;
    }
        
    else if (car1.price < car2.price)
    {
        cout << car2.Model << " is more expensive than " << car1.Model << endl;
    }
    else
    {
        cout << car1.Model << " and " << car2.Model << " have the same price." << endl;
    }
}

int main()
{
    Car car1("Toyota Corolla", 20000);
    Car car2("Honda Civic", 22000);

    Inventorymanager manager;

    cout << "Initial details of cars:" << endl;
    manager.display(car1);
    manager.display(car2);

    cout << endl << "Comparing prices:" << endl;
    ComparePrice(car1, car2);

    cout << endl << "Updating price of Toyota Corolla to 23000$" << endl;
    manager.updatePrice(car1, 23000);

    cout << endl << "Updated details of cars:" << endl;
    manager.display(car1);
}