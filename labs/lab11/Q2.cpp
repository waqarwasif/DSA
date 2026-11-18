#include <iostream>
using namespace std;

class Queue
{
private:
    int *elements;
    int front;
    int rear;
    int maxlength;

    // A1
    int addone(int i)
    {
        return (i + 1) % maxlength;
    }

public:
    Queue(int size)
    {
        maxlength = size;
        elements = new int[maxlength];
        makenull();
    }

    ~Queue()
    {
        delete[] elements;
    }

    // A2
    void makenull()
    {
        front = 0;
        rear = maxlength - 1;
    }

    // A3
    bool empty()
    {
        return addone(rear) == front;
    }

    bool full()
    {
        return addone(addone(rear)) == front;
    }

    // A4
    int getFront()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return elements[front];
    }

    // A5
    void enqueue(int x)
    {
        if (full())
        {
            cout << "Queue is full (cannot insert " << x << ")" << endl;
            return;
        }
        rear = addone(rear);
        elements[rear] = x;
    }

    // A6
    int dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int removed = elements[front];
        front = addone(front);
        return removed;
    }

    void display()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (i != rear)
        {
            cout << elements[i] << " ";
            i = addone(i);
        }
        cout << elements[rear] << endl;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout << "Removed: " << q.dequeue() << endl;
    q.display();
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    return 0;
}