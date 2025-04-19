#include <iostream>
using namespace std;

class WhetherSensor
{
public:
    virtual void ReadData()=0;
    virtual void printReport()=0;
};
class Termometer : public WhetherSensor
{
public:
    void ReadData()
    {
        cout << "Reading temperature data..." << endl;
    }
    void printReport()
    {
        cout << "Temperature report generated." << endl;
    }
};
class Barometer : public WhetherSensor
{
public:
    void ReadData()
    {
        cout << "Reading pressure data..." << endl;
    }
    void printReport()
    {
        cout << "Pressure report generated." << endl;
    }
};
int main()
{
    WhetherSensor *sensor1 = new Termometer();
    WhetherSensor *sensor2 = new Barometer();   
    sensor1->ReadData();
    sensor1->printReport(); 
    sensor2->ReadData();
    sensor2->printReport();

    
    delete sensor1;
    delete sensor2;
    return 0;
}