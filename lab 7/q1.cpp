#include<iostream>
#include<string>
using namespace std;

class Device
{
protected:
    int deviceID;
    string deviceName;
    string status;
public:
    Device(int id, string name, string stat)
    {
        deviceID = id;
        deviceName = name;
        status = stat;
    }

    virtual void TurnOn()
    {
        status = "ON";
    }
    virtual void TurnOff()
    {
        status = "OFF";
    }
    virtual string getStatus()
    {
        return status;
    }
    virtual void display()
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        cout << "Status: " << status << endl;
    }
    
};

class light: public Device
{
    int brightnessLevel;
    string colorMode;

public:

    light(int id, string name, string stat, int bright, string color): Device(id, name, stat)
    {
        brightnessLevel = bright;
        colorMode = color;
    }


    void display() override
    {
        Device::display();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }

};

class Thermostat: public Device
{
    int temperature;
    string mode;
    int targetTemperature;

public:
    
    Thermostat(int id, string name, string stat, int temp, string mod, int targetTemp): Device(id, name, stat)
    {
        temperature = temp;
        mode = mod;
        targetTemperature = targetTemp;
    }

    string getStatus() override
    {
        return to_string(temperature);
    }

    void display() override
    {
        Device::display();
        cout << "Temperature: " << temperature << endl;
        cout << "Mode: " << mode << endl;
        cout << "Target Temperature: " << targetTemperature << endl;
    }

};

class SecurityCamera: public Device
{
    string resolution;
    bool recordingStatus;
    string nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string stat, string res, bool rec, string night): Device(id, name, stat)
    {
        resolution = res;
        recordingStatus = rec;
        nightVisionEnabled = night;
    }

    void TurnOn() override
    {
        recordingStatus = true;
    }

    void display() override
    {
        Device::display();
        cout << "Resolution: " << resolution << endl;
        cout << "Recording Status: " << (recordingStatus?"ON":"OFF") << endl;
        cout << "Night Vision Enabled: " << nightVisionEnabled << endl;
    }
};

class SmartPlug: public Device
{
    int powerConsumption;
    string timerSetting;

public:
    SmartPlug(int id, string name, string stat, int power, string timer): Device(id, name, stat)
    {
        powerConsumption = power;
        timerSetting = timer;
    }

    void TurnOff() override
    {
        cout<<"loged power usage"<<endl;
        Device::TurnOff();
    }

    void display() override
    {
        Device::display();
        cout << "Power Consumption: " << powerConsumption << endl;
        cout << "Timer Setting: " << timerSetting << endl;
    }

};

int main()
{
    light livingRoomLight(1, "Living Room Light", "OFF", 75, "Warm White");
    Thermostat homeThermostat(2, "Home Thermostat", "ON", 22, "Cooling", 24);
    SecurityCamera frontDoorCamera(3, "Front Door Camera", "OFF", "1080p", false, "Enabled");
    SmartPlug kitchenPlug(4, "Kitchen Plug", "ON", 150, "2 hours");

    cout << "Living Room Light Details:" << endl;
    livingRoomLight.display();
    cout << endl;

    cout << "Home Thermostat Details:" << endl;
    homeThermostat.display();
    cout << endl;

    cout << "Front Door Camera Details:" << endl;
    frontDoorCamera.display();
    cout << endl;

    cout << "Kitchen Plug Details:" << endl;
    kitchenPlug.display();
    cout << endl;
    
    cout << "Turning on the Living Room Light..." << endl;
    livingRoomLight.TurnOn();
    livingRoomLight.display();
    cout << endl;

    cout << "Turning off the Kitchen Plug..." << endl;
    kitchenPlug.TurnOff();
    kitchenPlug.display();
    cout << endl;

    return 0;
}