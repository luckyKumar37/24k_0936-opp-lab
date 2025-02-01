#include<iostream>
using namespace std;
struct Product
{
    int productID;
    string name;
    int quantity;
    float price;
};
void input(Product *p1,int n){
    for(int i=0;i<n;i++){
        cout<<"For product "<<i+1<<endl;
        cout<<"Enter name:";
        cin.ignore();
        getline(cin,p1[i].name);
        cout<<"Enter product id:";
        cin>>p1[i].productID;
        cout<<"Enter quantity:";
        cin>>p1[i].quantity;
        cout<<"Enter price:";
        cin>>p1[i].price;
    }
}
void display(Product *p1,int n){
    for(int i=0;i<n;i++){
        cout<<"For Product "<<i+1<<endl;
        cout<<"name:"<<p1[i].name<<endl;
        cout<<"product id:"<<p1[i].productID<<endl;
        cout<<"price:"<<p1[i].price<<endl;
        cout<<"Quantity:"<<p1[i].quantity<<endl;
        cout<<"total value:"<<p1[i].quantity*p1[i].price<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of product you want to input:";
    cin>>n;
    Product* products=new Product[n];
    input(products,n);
    display(products,n);
    delete[] products;
}