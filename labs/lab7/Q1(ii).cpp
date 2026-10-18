
#include <iostream>
#include <cctype>
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

int len(char *P)
{
    int i = 0, len = 0;
    while (P[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
bool checkPrecedence(char opr1, char opr2)
{
    int p1, p2;

    if (opr1 == '+' || opr1 == '-')
        p1 = 1;
    else if (opr1 == '*' || opr1 == '/')
        p1 = 2;
    else
        return false;

    if (opr2 == '+' || opr2 == '-')
        p2 = 1;
    else if (opr2 == '*' || opr2 == '/')
        p2 = 2;
    else
        return false;

    return p1 > p2;
}
char *I_To_P(char *q)
{
    int length = len(q);
    char *p = new char[length + 1];
    int indq = 0;
    int indp = 0;
    Stack<char> s(length - 1);
    while (q[indq] != '\0')
    {
        if (q[indq] == '+' || q[indq] == '-' || q[indq] == '*' || q[indq] == '/')
        {
            if (s.isEmpty())
            {
                s.push(q[indq]);
            }
            else
            {
                if (checkPrecedence(q[indq], s.peek()))
                {
                    s.push(q[indq]);
                }
                else
                {
                    while (!s.isEmpty() && !(checkPrecedence(q[indq], s.peek())))
                    {
                        p[indp++] = s.pop();
                    }
                    s.push(q[indq]);
                }
            }
        }
        else
        {
            p[indp++] = q[indq];
        }
        indq++;
    }
    while (!(s.isEmpty()))
    {
        p[indp++] = s.pop();
    }
    p[indp] = '\0';
    return p;
}

int main()
{
    char arr[] = "7+3*4";
    cout << I_To_P(arr);
    return 0;
}
