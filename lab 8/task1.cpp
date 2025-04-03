#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex &comp2)
    {
        return Complex(real + comp2.real, imag + comp2.imag);
    }

    Complex operator-(const Complex &comp2)
    {
        return Complex(real - comp2.real, imag - comp2.imag);
    }

    Complex operator*(const Complex &comp2)
    {
        return Complex(real * comp2.real -imag * comp2.imag,real * comp2.imag + imag * comp2.real);
    }

    Complex operator/(const Complex &comp2)
    {
        double denominator = comp2.real * comp2.real + comp2.imag * comp2.imag;
        return Complex((real * comp2.real + imag * comp2.imag) / denominator, (imag * comp2.real - real * comp2.imag) / denominator);
    }

    friend void operator<<(ostream &out, const Complex &comp2)
    {
        cout<<comp2.real<<" + "<<comp2.imag<<"i"<<endl;
    }

    friend double Magnitude(Complex &comp2)
    {
        return sqrt(comp2.real * comp2.real + comp2.imag * comp2.imag);
    }
};

int main()
{
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;
    cout << "Addition: ";
    cout << c3;

    Complex c4 = c1 - c2;
    cout << "Subtraction: ";
    cout << c4;

    Complex c5 = c1 * c2;
    cout << "Multiplication: ";
    cout << c5;

    Complex c6 = c1 / c2;
    cout << "Division: ";
    cout << c6;

    double mag = Magnitude(c1);
    cout << "Magnitude of first complex number: " << mag << endl;

    return 0;
}