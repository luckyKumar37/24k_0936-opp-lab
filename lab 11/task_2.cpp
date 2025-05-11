#include <iostream>
using namespace std;

class QueueoverflowException : public exception
{
private:
    string message;

public:
    QueueoverflowException(const string &msg) : message(msg) {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }

};

class QueueunderflowException : public exception
{
private:
    string message; 
public:
    QueueunderflowException(const string &msg) : message(msg) {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

template<class T>
class Queue
{
private:
    T arr[10];
    int end;

public:
    Queue() : end(0) {}

    void enqueue(T value)
    {
        if (end < 10)
        {
            arr[end++] = value;
        }
        else
        {
            throw QueueoverflowException("Queue is full");
        }
    }

    void dequeue()
    {
        if (end > 0)
        {
            for (int i = 0; i < end - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            end--;
        }
        else
        {
            throw QueueunderflowException("Queue is empty");
        }
    }

    void display()
    {
        for (int i = 0; i < end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Queue after enqueuing 4 elements: ";
    q.display();

    q.dequeue();
    cout << "Queue after dequeuing 1 element: ";
    q.display();

    try
    {
        for (int i = 0; i < 10; i++)
        {
            q.enqueue(i);
        }
    }
    catch (const QueueoverflowException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}