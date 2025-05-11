#include <iostream>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception
{
private:
    string message;
public:
    DimensionMismatchException(const string &msg) : message(msg) {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

template<class T>
class Matrix
{
    T **matrix;
    int rows;
    int cols;

public:
    Matrix(int r,int c):rows(r),cols(c)
    {
        matrix = new T*[rows];
        for(int i=0;i<rows;i++)
            matrix[i] = new T[cols];
    }
    ~Matrix()
    {
        for(int i=0;i<rows;i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    void setMatrix()
    {
        cout<<"Enter the elements of the matrix:"<<endl;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cin>>matrix[i][j];
            }
        }
    }

    void display()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    friend Matrix<T> operator+(Matrix &m1, Matrix &m2)
    {
        if(m1.rows != m2.rows || m1.cols != m2.cols)
        {
            throw DimensionMismatchException("Matrix dimensions do not match for addition");
        }
        Matrix result(m1.rows, m1.cols);
        for(int i=0;i<m1.rows;i++)
        {
            for(int j=0;j<m1.cols;j++)
            {
                result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            }
        }

        return result;
    }

};



int main()
{
    Matrix<int> m1(2,2);
    Matrix<int> m2(2,2);

    m1.setMatrix();
    m2.setMatrix();

    cout << "Matrix 1:" << endl;
    m1.display();
    cout << "Matrix 2:" << endl;
    m2.display();

    try
    {
        Matrix<int> m3 = m1 + m2;
        cout << "Resultant Matrix after addition:" << endl;
        m3.display();
    }
    catch (DimensionMismatchException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}