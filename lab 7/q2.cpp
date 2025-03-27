#include<iostream>
#include<string>
using namespace std;

class product
{
protected:
    int productID;
    string productName;
    float productPrice;
    int productQuantity;

public:
    product(int id, string name, float price, int quantity)
    {
        productID = id;
        productName = name;
        productPrice = price;
        productQuantity = quantity;
    }

    virtual void applyDiscount()
    {
        productPrice = productPrice - (productPrice * 0.1);
    }

    virtual void calculateTotalPrice(int quantity)
    {
        cout << "Total Price: " << productPrice * quantity << endl;
    }

    virtual void display()
    {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Product Price: " << productPrice << endl;
        cout << "Product Quantity: " << productQuantity << endl;
    }

    product operator+(product &p)
    {
        return product(0, "bulk purchase", productPrice + p.productPrice, 0);
    }

    friend void operator<< (ostream& COUT,product &p)
    {
        COUT<<"product Name: "<<p.productName<<endl;
        COUT<<"product Price: "<<p.productPrice<<endl;
    }
};

class Electronics: public product
{
    string warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, float price, int quantity, string warranty, string brandName): product(id, name, price, quantity)
    {
        warrantyPeriod = warranty;
        brand = brandName;
    }

    void display() override
    {
        product::display();
        cout << "Warranty Period: " << warrantyPeriod << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing: public product
{
    string size;
    string material;
    string color;

public:
    Clothing(int id, string name, float price, int quantity, string clothSize, string clothMaterial, string clothColor): product(id, name, price, quantity)
    {
        size = clothSize;
        material = clothMaterial;
        color = clothColor;
    }

    void applyDiscount() override
    {
        productPrice = productPrice - (productPrice * 0.2);
    }

    void display() override
    {
        product::display();
        cout << "Size: " << size << endl;
        cout << "Material: " << material << endl;
        cout << "Color: " << color << endl;
    }
};

class FoodItem: public product
{
    string expiryDate;
    int calories;

public:
    FoodItem(int id, string name, float price, int quantity, string date, int cal): product(id, name, price, quantity)
    {
        expiryDate = date;
        calories = cal;
    }

    void calculateTotalPrice(int quantity) override
    {
        productPrice= productPrice - (productPrice * 0.5);
        cout << "Total Price: " << productPrice * quantity<< endl;
    }

    void display() override
    {
        product::display();
        cout << "Expiry Date: " << expiryDate << endl;
        cout << "Calories: " << calories << endl;
    }
};

class Book: public product
{
    string author;
    string genre;

public:
    Book(int id, string name, float price, int quantity, string bookAuthor, string bookGenre): product(id, name, price, quantity)
    {
        author = bookAuthor;
        genre = bookGenre;
    }

    void display() override
    {
        product::display();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main()
{
    Electronics e1(1, "Laptop", 50000, 10, "1 year", "Dell");
    Clothing c1(2, "Shirt", 1000, 20, "M", "Cotton", "Blue");
    FoodItem f1(3, "Biscuits", 50, 100, "12/12/2022", 100);
    Book b1(4, "Harry Potter", 500, 5, "J.K. Rowling", "Fantasy");

    e1.display();
    cout << endl;
    c1.display();
    cout << endl;
    f1.display();
    cout << endl;
    b1.display();
    cout << endl;

    e1.applyDiscount();
    c1.applyDiscount();
    f1.calculateTotalPrice(5);

    product p1 = e1 + c1;
    cout<<p1;

    cout << endl;
    cout << "Displaying using friend function: " << endl;
    cout << e1;
    cout << c1;
    cout << f1;
    cout << b1;

    return 0;
}

