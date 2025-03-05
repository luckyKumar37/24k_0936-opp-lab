#include<iostream>
#include<algorithm>
using namespace std;

class Product{
private:
    int Id;
    string name;
    int quantity;

public:
    Product(){}
    Product(int id,string n,int q):
    Id(id),name(n),quantity(q){}

    void display() const{
        cout<<"Product Id:"<<Id<<endl;
        cout<<"Product name:"<<name<<endl;
        cout<<"Quantity:"<<quantity<<endl;
    }

    int getId() const{
        return Id;
    }
    string getname() const{
        return name;
    }
};

class Inventory{
private:
    Product products[10];
    int noOfProduct=0;
public:
    void addproduct(int id,string n,int q){
        products[noOfProduct++]=Product(id,n,q);
    }

    void Sort(){
        for(int i=0;i<noOfProduct;i++){
            for(int j=i+1;j<noOfProduct;j++){
                if(products[i].getname()>products[j].getname()){
                    Product temp=products[i];
                    products[i]=products[j];
                    products[j]=temp;
                }
            }
        }
        display();
    }

    void SearchProduct(int id){
        for(int i=0;i<noOfProduct;i++){
            if(products[i].getId()==id){
                products[i].display();
                break;
            }
        }
    }

    void display() const{
        for(int i=0;i<noOfProduct;i++){
            products[i].display();
        }
    }
};
int main(){
    Inventory inv;

    inv.addproduct(103, "Laptop", 5);
    inv.addproduct(101, "Mouse", 20);
    inv.addproduct(105, "Keyboard", 10);
    inv.addproduct(102, "Monitor", 8);

    cout<<"Normal Dispaly of Inventory:\n";
    inv.display();


    cout<<"\n\nSorted dispaly of Inventory\n";
    inv.Sort();


    cout<<"\n\nSearch result\n";
    inv.SearchProduct(102);


}