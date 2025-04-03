#include<iostream>
using namespace std;

class Vector2D
{
private:
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D &v)
    {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(const Vector2D &v)
    {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(double scalar)
    {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double DotProduct(const Vector2D &v1, const Vector2D &v2);

    friend void operator<<(ostream &out, const Vector2D &v)
    {
        cout<<"("<<v.x<<", "<<v.y<<")"<<endl;
    }

};

double DotProduct(const Vector2D &v1, const Vector2D &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

int main()
{
    Vector2D v1(3, 4), v2(1, 2);
    Vector2D v3 = v1 + v2;
    cout << "Addition: ";
    cout << v3;

    Vector2D v4 = v1 - v2;
    cout << "Subtraction: ";
    cout << v4;

    Vector2D v5 = v1 * 2;
    cout << "Scalar Multiplication: ";
    cout << v5;

    double dotProduct = DotProduct(v1, v2);
    cout << "Dot Product: " << dotProduct << endl;

    return 0;
}