#include<iostream>
using namespace std;

int myLength(const char s[])
{
    int len = 0;
    while (s[len]!= '\0')
    {
        len++;
    }
    return len;
}

int main()
{
    char s[100];
    cout<<"Enter the string\n";
    cin.getline(s,100);
    cout<<"The length is "<<myLength(s);
}