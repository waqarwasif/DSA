#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedQueue
{
private:
    Node *head;
    Node *tail;
    int count;
    int limit;

public:
    LinkedQueue(int maxSize = 0)
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
        limit = maxSize;
    }

    ~LinkedQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    // limit of 0 means no limit
    bool isFull()
    {
        return limit > 0 && count >= limit;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full, can't add " << value << endl;
            return;
        }

        Node *fresh = new Node(value);
        if (isEmpty())
        {
            head = fresh;
            tail = fresh;
        }
        else
        {
            tail->next = fresh;
            tail = fresh;
        }
        count++;
        cout << value << " added to the queue" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, nothing to remove" << endl;
            return -1;
        }

        Node *old = head;
        int value = old->data;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete old;
        count--;
        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, nothing to peek at" << endl;
            return -1;
        }
        return head->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue: (empty)" << endl;
            return;
        }
        cout << "Queue (front -> rear): ";
        for (Node *n = head; n != nullptr; n = n->next)
        {
            cout << n->data << " ";
        }
        cout << endl;
    }
};

int main()
{
    LinkedQueue q(4);

    cout << "Is empty at the start? " << (q.isEmpty() ? "Yes" : "No") << endl;
    q.peek();

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    cout << "Is full? " << (q.isFull() ? "Yes" : "No") << endl;
    q.enqueue(50);

    cout << "Front element: " << q.peek() << endl;
    cout << "Removed: " << q.dequeue() << endl;
    cout << "Removed: " << q.dequeue() << endl;
    q.display();

    cout << "Front element now: " << q.peek() << endl;
    cout << "Is full now? " << (q.isFull() ? "Yes" : "No") << endl;

    q.enqueue(60);
    q.display();

    while (!q.isEmpty())
    {
        cout << "Removed: " << q.dequeue() << endl;
    }
    q.display();
    q.dequeue();

    return 0;
}