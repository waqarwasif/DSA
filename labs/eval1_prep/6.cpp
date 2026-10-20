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

bool matchingbraces(char a, char b){
    if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}'){
        return true;
    }
    return false;
}

bool checkbalance(char* a){

    Stack<char> s(len(a));
    int i=0;
    while(a[i]!='\0'){
        if (a[i] == '(' || a[i] == '[' || a[i] == '{' ){
            s.push(a[i]);
        }
        else if (a[i] == ')' || a[i] == ']' || a[i] == '}'){
            if(s.isEmpty()){
                return false;
            }
            else{
                if(matchingbraces(s.peek(),a[i])){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
        i++;
    }
    return(s.isEmpty());

}

int main(){
    char a[] = "{[()]}";
    char b[] = "([)]";
    char c[] = "{[]}";

    if(checkbalance(a)){
        cout<<"Balanced";

    }
    else{
        cout<<"Unbalanced";
    }

    if(checkbalance(b)){
        cout<<"Balanced";

    }
    else{
        cout<<"Unbalanced";
    }

    if(checkbalance(c)){
        cout<<"Balanced";

    }
    else{
        cout<<"Unbalanced";
    }
}