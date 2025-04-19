#include <iostream>
using namespace std;

class ManuItem
{
protected:
    string dishName;
    double price;

public:
    ManuItem(string dishName, double price) : dishName(dishName), price(price) {}
    virtual void ShowDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public ManuItem
{
public:
    Appetizer(string dishName, double price) : ManuItem(dishName, price) {}
    void ShowDetails()
    {
        cout << "Appetizer: " << dishName << ", Price: $" << price << endl;
    }
    void prepare()
    {
        cout << "Preparing appetizer: " << dishName << endl;
    }
};

class MainCourse : public ManuItem
{
public:
    MainCourse(string dishName, double price) : ManuItem(dishName, price) {}
    void ShowDetails()
    {
        cout << "Main Course: " << dishName << ", Price: $" << price << endl;
    }
    void prepare()
    {
        cout << "Preparing main course: " << dishName << endl;
    }
};
int main()
{
    ManuItem *item1 = new Appetizer("Bruschetta", 8.99);
    ManuItem *item2 = new MainCourse("Grilled Salmon", 19.99);
    item1->ShowDetails();
    item1->prepare();
    item2->ShowDetails();
    item2->prepare();

    
    delete item1;
    delete item2;   
    return 0;
}