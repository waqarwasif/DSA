#include <iostream>
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

char* stringConcatenation(char* a, char* b){
    int i = myLength(a);
    int j = myLength(b);
    int count = 0;
    while (count < j){
        a[i++] = b[count++];
    }
    a[i] = '\0';
    return a;
}

int main(){
    char a[] = "hi ";
    char b[] = "waqar  .";

    stringConcatenation(a,b);
    cout<<a;
}