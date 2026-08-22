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

int main()
{
    char a[] = "clearly";
    char b[] = "early";
    int found = index(a, b);
    if (found != -1)
    {
        cout << "Found at position: " << found;
    }
    else
    {
        cout << "No matching encountered";
    }
}
