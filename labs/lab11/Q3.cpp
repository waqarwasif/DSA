#include <iostream>
#include <string>
using namespace std;

struct PNode
{
    string item;
    int priority;
    PNode *next;
    PNode(string i, int p)
    {
        item = i;
        priority = p;
        next = nullptr;
    }
};

// Higher number = higher priority. Ties leave in arrival order.
class PriorityQueue
{
private:
    PNode *head;
    int count;
    int capacity;

public:
    PriorityQueue(int maxSize = 10)
    {
        head = nullptr;
        count = 0;
        capacity = maxSize;
    }

    ~PriorityQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == capacity;
    }

    void enqueue(string item, int priority)
    {
        if (isFull())
        {
            cout << "Queue is full, can't add " << item << endl;
            return;
        }

        PNode *fresh = new PNode(item, priority);

        if (head == nullptr || priority > head->priority)
        {
            fresh->next = head;
            head = fresh;
        }
        else
        {
            PNode *walker = head;
            while (walker->next != nullptr && walker->next->priority >= priority)
            {
                walker = walker->next;
            }
            fresh->next = walker->next;
            walker->next = fresh;
        }
        count++;
        cout << "Added " << item << " (priority " << priority << ")" << endl;
    }

    string dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, nothing to remove" << endl;
            return "";
        }
        PNode *old = head;
        string item = old->item;
        head = head->next;
        delete old;
        count--;
        return item;
    }

    string peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, nothing to peek at" << endl;
            return "";
        }
        return head->item;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue: (empty)" << endl;
            return;
        }
        cout << "Queue (highest priority first): ";
        for (PNode *n = head; n != nullptr; n = n->next)
        {
            cout << n->item << "(" << n->priority << ") ";
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq(5);

    pq.enqueue("A", 2);
    pq.enqueue("B", 5);
    pq.enqueue("C", 1);
    pq.enqueue("D", 4);
    pq.display();

    cout << "Highest priority right now: " << pq.peek() << endl;

    cout << "Removal order: ";
    while (!pq.isEmpty())
    {
        cout << pq.dequeue();
        if (!pq.isEmpty())
            cout << " -> ";
    }
    cout << endl;

    cout << "\n--- extra tests ---" << endl;
    pq.enqueue("X", 3);
    pq.enqueue("Y", 3);
    pq.enqueue("Z", 9);
    pq.enqueue("P", 1);
    pq.enqueue("Q", 2);
    pq.enqueue("R", 7);
    pq.display();
    cout << "Is full? " << (pq.isFull() ? "Yes" : "No") << endl;

    while (!pq.isEmpty())
    {
        cout << "Removed: " << pq.dequeue() << endl;
    }
    pq.dequeue();

    return 0;
}