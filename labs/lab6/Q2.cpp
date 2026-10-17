
#include <iostream>
using namespace std;

class Stack
{
private:
    static const int SIZE = 5;
    int arr[SIZE];
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check whether stack is full
    bool isFull()
    {
        return top == SIZE - 1;
    }

    // Insert an element
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push "
                 << value << endl;
            return;
        }

        arr[++top] = value;
        cout << value << " pushed onto the stack."
             << endl;
    }

    // Remove and return the top element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Stack is empty."
                 << endl;
            return -1;
        }

        return arr[top--];
    }

    // Return the top element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element."
                 << endl;
            return -1;
        }

        return arr[top];
    }

    // Display stack from top to bottom
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack (top to bottom): ";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    cout << boolalpha;

    cout << "Is stack empty? "
         << s.isEmpty() << endl;

    cout << "Is stack full? "
         << s.isFull() << endl;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element (peek): "
         << s.peek() << endl;

    cout << "Popped element: "
         << s.pop() << endl;

    s.display();

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70); // Tests overflow

    s.display();

    cout << "Is stack full? "
         << s.isFull() << endl;

    cout << "Popped element: "
         << s.pop() << endl;

    cout << "Top element (peek): "
         << s.peek() << endl;

    while (!s.isEmpty())
    {
        cout << "Popped element: "
             << s.pop() << endl;
    }

    cout << "Is stack empty? "
         << s.isEmpty() << endl;

    cout << "Attempting pop on empty stack:"
         << endl;

    s.pop(); // Tests underflow

    return 0;
}
