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

void character_search(char *S, char a)
{
    for (int i=0;i<myLength(S);i++){
        if( S[i] == a){
            cout<<"- "<<i<<"\n";
        }
    }
}

int main()
{
    char a[] = "hi ";
    char b[] = "waqar";

    character_search(b,'a');
}