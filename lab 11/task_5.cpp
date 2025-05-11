#include <iostream>
using namespace std;

class NegativeStockException : public exception
{};

class OverCapacityException : public exception
{};

template<class T>
class InventoryItem
{
private:
    T stock;
    T maxStock;
public:
    InventoryItem(T s) : stock(s),maxStock(100)
    {
        cout<< "Attemting to set stock: " << s <<"(max "<<maxStock<<")"<< endl;
        if(stock > maxStock)
        {
            throw OverCapacityException();
        }
        else if(stock < 0)
        {
            throw NegativeStockException();
        }
    }


};
int main()
{
    try
    {
        InventoryItem<int> item(150);
    }
    catch(const OverCapacityException& e)
    {
        cout << "Caught OverCapacityException "<<e.what() << endl;
    }
    catch(const NegativeStockException& e)
    {
        cout << "Caught NegativeStockException "<<e.what() << endl;
    }
    return 0;
}