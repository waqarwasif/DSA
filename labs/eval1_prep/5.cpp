#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
    int size;
    T *arr;
    int top;

public:
    // Constructor
    Stack(int n)
    {
        size = n;
        top = -1;
        arr = new T[n];
    }

    ~Stack()
    {
        delete[] arr;
    }

    // Check whether stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check whether stack is full
    bool isFull()
    {
        return top == size - 1;
    }

    // Insert an element
    void push(T value)
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
    T pop()
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
    T peek()
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

void occurence(int x, Stack<int> &p)
{
    Stack<int> q(6);

    while(!p.isEmpty()){
        if(p.peek() == x){
            p.pop();
        }
        else{
            q.push(p.pop());
        }

    }
    while(!q.isEmpty()){
        p.push(q.pop());
    }
    
}

int main(){
    Stack<int> p(6);
    p.push(2);
    p.push(4);
    p.push(2);
    p.push(8);
    p.push(2);
    p.push(5);

    occurence(2,p);
    p.display();
}