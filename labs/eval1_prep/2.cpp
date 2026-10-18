
#include <iostream>
#include<cctype>
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

int len(char* P){
    int i =0, len=0;
    while(P[i]!='\0'){
        len++;
        i++;
    }
    return len;
}
int postfixcalculation(char* P){
    int length = len(P);
    P[length]=')';
    P[length+1]='\0';
    Stack<int> s(length);
    int i=0;
    while(P[i]!=')'){
        if(isdigit(P[i])){
            s.push(P[i]-'0');
        }
        else{
            int result;
            int op1 = s.pop();
            int op2 = s.pop();
            switch (P[i])
            {
            case '+':
                result = op2 + op1;
                s.push(result);
                break;
            case '-':
                result = op2 - op1;
                s.push(result);
                break;
            case '*':
                result = op2 * op1;
                s.push(result);
                break;
            case '/':
                if (op1 == 0)
                {
                    cout << "Division by zero!" << endl;
                    return -1;
                }

                result = op2 / op1;
                s.push(result);
                break;

            default:
                break;
            }
        }
        i++;

    }
    return s.peek();

}

int main()
{
    char arr[200] = "23*7+2*";
    cout<< postfixcalculation(arr);
    return 0;
}


