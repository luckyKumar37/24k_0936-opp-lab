#include <iostream>
using namespace std;

class InvalidTemperatureException : public exception
{
private:
    string message;
public:
    InvalidTemperatureException(const string &msg) : message(msg) {}
};

template<class T>
class CovrtToFahrenheit
{
private:
    T celsius;

public:
    CovrtToFahrenheit(T c)
    {
        if(c < -273.15)
        {
            throw InvalidTemperatureException("Invalid temperature: below absolute zero");
        }
    }

    T convert()
    {
        return (celsius * 9 / 5) + 32;
    }
};

int main()
{
    try
    {
        CovrtToFahrenheit<double> temp(-300);
        cout << "Temperature in Fahrenheit: " << temp.convert() << endl;
    }
    catch (const InvalidTemperatureException &e)
    {
        cout <<"Caught InvalidTemperatureException -"<< e.what() << endl;
    }
    return 0;
}