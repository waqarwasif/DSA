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

char *stringConcatenation(char *a, char *b)
{
    int i = myLength(a);
    int j = myLength(b);
    int count = 0;
    while (count < j)
    {
        a[i++] = b[count++];
    }
    a[i] = '\0';
    return a;
}

int index(char *T, char *P)
{
    int t = myLength(T);
    int p = myLength(P);
    int max = t - p + 1; // T = intelligence and P = tell so the positon of 'nce' are not required
                         //  for comparing bcz its smaller than the P string

    int i = 0;

    while (i < max)
    {
        for (int j = 0; j < p; j++)
        {
            if (P[j] != T[i + j])
                break;

            if (j == p - 1)
                return i;
        }
        i++;
    }

    if (i == max)
    {
        return -1;
    }
}

char *substring(char *s, int ip, int len, char *dest)
{

    int count = 0;
    int i = ip;
    while (count < len)
    {

        dest[count++] = s[i++];
    }
    dest[count] = '\0';
    return dest;
}

char *ins(char *T, int ip, char *P)
{
    char temp1[100];
    char temp2[100];
    substring(T, 0, ip, temp1);
    substring(T, ip - 1, myLength(T) - ip + 1, temp2);
    stringConcatenation(temp1, P);
    stringConcatenation(temp1, temp2);

    int i = 0;
    while (temp1[i] != '\0')
    {
        T[i] = temp1[i];
        i++;
    }
    T[i] = '\0';
    return T;
}
char *del(char *T,char *P, int L)
{
    char temp1[100];
    char temp2[100];
    while (index(T, P) != -1){
        int ip = index(T, P);
        substring(T, 0, ip, temp1);
        substring(T, ip + L, myLength(T) - ip - L + 1, temp2);
        stringConcatenation(temp1, temp2);
    
        int i = 0;
        while (temp1[i] != '\0')
        {
            T[i] = temp1[i];
            i++;
        }
        T[i] = '\0';
    }
    return T;
}

int main()
{
    char T[100] = "The founder of our country was Quaid - e - Azam";
    char S[100] = "and first Governor General";
    char X[100] = "Database Management Management Systems";
    char Y[100] = "Management";
    ins(T, 12, S);
    del(X,Y,myLength(Y));
    cout << "\n " << T << endl;
    cout << "\n " << X << endl;
}