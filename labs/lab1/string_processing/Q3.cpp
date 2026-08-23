#include<iostream>
using namespace std;

int myLength(const char s[])
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

char *concatenate(char* S, int n){
    int i=0;
    int last=myLength(S);

    while(last<n){
        S[last]=S[i];
        last++;
        i++;
    }
    S[last]='\0';

    return S;
}

int main()
{
    char a[] = "hi ";
    char b[] = "waqar";

    concatenate(b, 10);
    cout << b;
}