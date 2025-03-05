#include<iostream>
using namespace std;

class Device{
protected:
    int deviceId;
    bool status;

public:

    Device(){}
    Device(int id,bool s):deviceId(id),status(s){}

    void display() const{
        cout<<"Device ID:"<<deviceId<<endl;
        cout<<"Status:"<<(status ? "ON":"Off")<<endl;
    }
};

class SmartPhone :virtual protected Device{
protected:
    float screenSize;

public:
    SmartPhone(int id,bool s,float size):
    Device(id,s),screenSize(size){}

};

class SmartWatch :virtual protected Device{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id,bool s,bool rate):
    Device(id,s),heartRateMonitor(rate){}
};

class SmartWearable : virtual protected SmartPhone,virtual protected SmartWatch{
protected:
    int stepcounter;

public:
    SmartWearable(int id,bool s,float size,bool rate,int count):
    Device(id,s),SmartPhone(id,s,size),SmartWatch(id,s,rate),
    stepcounter(count){}

    void display() const{
        Device::display();
        cout<<"Screen Size:"<<screenSize<<" Inches"<<endl;
        cout<<"Heart Rate Moniter:"<<(heartRateMonitor ? "Yes":"No")<<endl;
        cout<<"Step Count:"<<stepcounter<<endl;

    }

};
int main(){
    SmartWearable s1(104,true,4.2,true,2000);
    s1.display();
    return 0;
}