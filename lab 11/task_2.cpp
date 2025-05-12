#include <iostream>
using namespace std;

class QueueoverflowException : public exception
{};

class QueueunderflowException : public exception
{};

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
            throw QueueoverflowException();
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
            else
            {
                throw QueueunderflowException();
            }
            
            end--;
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
        cout << "Caught QueueoverflowException: Queue is full." << endl;
    }
    return 0;
}