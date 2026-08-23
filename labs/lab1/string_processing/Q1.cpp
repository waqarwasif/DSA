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

int main()
{
    int choice;

    do
    {
        cout << "\n========== STRING OPERATIONS ==========\n";
        cout << "1. Algorithm A1 - Length\n";
        cout << "2. Algorithm A2 - Concatenate\n";
        cout << "3. Algorithm A3 - Substring\n";
        cout << "4. Algorithm A4 - Index / Search\n";
        cout << "5. Exit\n";
        cout << "=======================================\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            char s[200];

            cout << "Enter string: ";
            cin.getline(s, 200);

            cout << "Length = " << myLength(s) << endl;

            break;
        }

        case 2:
        {
            char s1[200];
            char s2[200];

            cout << "Enter first string: ";
            cin.getline(s1, 200);

            cout << "Enter second string: ";
            cin.getline(s2, 200);

            stringConcatenation(s1, s2);

            cout << "Concatenated string = " << s1 << endl;

            break;
        }

        case 3:
        {
            char s[200];
            int ip, len;

            cout << "Enter string: ";
            cin.getline(s, 200);

            cout << "Enter starting position (ip): ";
            cin >> ip;

            cout << "Enter length: ";
            cin >> len;

            char result[200];

            substring(s, ip, len, result);

            cout << "Substring = " << result << endl;

            break;
        }

        case 4:
        {
            char T[200];
            char P[200];

            cout << "Enter text string T: ";
            cin.getline(T, 200);

            cout << "Enter pattern string P: ";
            cin.getline(P, 200);

            int found = index(T, P);

            if (found != -1)
                cout << "Pattern found at position: " << found << endl;
            else
                cout << "Pattern not found." << endl;

            break;
        }

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}