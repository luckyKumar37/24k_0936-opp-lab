#include <iostream>
using namespace std;

class Shipment
{
protected:
    string TrackingNumber;
    double Weight;

public:
    Shipment(string trackingNumber, double weight) : TrackingNumber(trackingNumber), Weight(weight) {}
    virtual void estimatedeliveryTime() = 0;
    virtual void ShowDetails() = 0;
};

class AirFreight : public Shipment
{
public:
    AirFreight(string trackingNumber, double weight) : Shipment(trackingNumber, weight) {}
    void estimatedeliveryTime()
    {
        cout << "Estimated delivery time for Air Freight: 2-3 days" << endl;
    }
    void ShowDetails()
    {
        cout << "Air Freight Shipment Details:" << endl;
        cout << "Tracking Number: " << TrackingNumber << endl;
        cout << "Weight: " << Weight << " kg" << endl;
    }
};
class GroundSHipment : public Shipment
{
public:
    GroundSHipment(string trackingNumber, double weight) : Shipment(trackingNumber, weight) {}
    void estimatedeliveryTime()
    {
        cout << "Estimated delivery time for Ground Shipment: 5-7 days" << endl;
    }
    void ShowDetails()
    {
        cout << "Ground Shipment Details:" << endl;
        cout << "Tracking Number: " << TrackingNumber << endl;
        cout << "Weight: " << Weight << " kg" << endl;
    }
};
int main()
{
    Shipment *shipment1 = new AirFreight("AF12345", 10.5);
    Shipment *shipment2 = new GroundSHipment("GS67890", 20.0);
    shipment1->estimatedeliveryTime();
    shipment1->ShowDetails();

    shipment2->estimatedeliveryTime();
    shipment2->ShowDetails();

    delete shipment1;
    delete shipment2;
    return 0;
}