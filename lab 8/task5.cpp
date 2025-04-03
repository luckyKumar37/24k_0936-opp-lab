#include<iostream>
using namespace std;

class Matrix2x2
{
private:
    double a, b, c, d;
public: 
    Matrix2x2(double a = 0, double b = 0, double c = 0, double d = 0) : a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(const Matrix2x2 &m)
    {
        return Matrix2x2(a + m.a, b + m.b, c + m.c, d + m.d);
    }

    Matrix2x2 operator-(const Matrix2x2 &m)
    {
        return Matrix2x2(a - m.a, b - m.b, c - m.c, d - m.d);
    }

    Matrix2x2 operator*(const Matrix2x2 &m)
    {
        return Matrix2x2(a * m.a + b * m.c, a * m.b + b * m.d, c * m.a + d * m.c, c * m.b + d * m.d);
    }

    friend void operator<<(ostream &out, const Matrix2x2 &m)
    {
        cout << "[" << m.a << " " << m.b << "]" << endl;
        cout << "[" << m.c << " " << m.d << "]" << endl;
    }

    friend double Determinant(const Matrix2x2 &m)
    {
        return m.a * m.d - m.b * m.c;
    }

    friend class MatrixHelper;
};

class MatrixHelper
{
    public:
        void updateElement(Matrix2x2 &m, int row, int col, double value)
        {
            if (row == 1 && col == 1)
            {
             m.a = value;
            }
            else if (row == 1 && col == 2)
            {
                m.b = value;
            }
            else if (row == 2 && col == 1)
            {            
                m.c = value;
            }
            else if (row == 2 && col == 2)
            {
                m.d = value;
            }
            else 
            {
                cout << "Invalid indices!" << endl;
            }
        }
};

int main()
{
    Matrix2x2 m1(1, 2, 3, 4), m2(5, 6, 7, 8);
    Matrix2x2 m3 = m1 + m2;
    cout<< "Initial matrices: " << endl;
    cout << "Matrix 1: " << endl;   
    cout << m1;
    cout << "Matrix 2: " << endl;
    cout << m2;
    cout << endl;
    cout << "Addition: " << endl;
    cout << m3;

    Matrix2x2 m4 = m1 - m2;
    cout << "Subtraction: " << endl;
    cout << m4;

    Matrix2x2 m5 = m1 * m2;
    cout << "Multiplication: " << endl;
    cout << m5;

    double det = Determinant(m1);
    cout << "Determinant of first matrix: " << det << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 1, 1, 10);
    cout << "Updated first matrix: " << endl;
    cout << m1;

    return 0;
}

