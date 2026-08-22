#include <iostream>
#include<cstring>
#include<chrono>
using namespace std;
using namespace chrono;


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

    cout << "pass\n";

    int count = 0;
    int i = ip;
    while (count < len)
    {
        cout << "pass\n";

        dest[count++] = s[i++];
    }
    dest[count] = '\0';
    cout << "pass\n";
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

            auto start1 = high_resolution_clock::now();
            int result1 = myLength(s);
            auto end1 = high_resolution_clock::now();

            auto duration1 = duration_cast<nanoseconds>(end1 - start1);

            auto start2 = high_resolution_clock::now();
            size_t result2 = strlen(s);
            auto end2 = high_resolution_clock::now();

            auto duration2 = duration_cast<nanoseconds>(end2 - start2);

            cout << "A1:\n";
            cout << "Length = " << result1 << endl;
            cout << "Execution time: " << duration1.count()
                 << " nanoseconds\n";

            cout << "STL strlen():\n";
            cout << "Length = " << result2 << endl;
            cout << "Execution time: " << duration2.count()
                 << " nanoseconds\n";

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

            char myResult[200];
            strcpy(myResult, s1);

            auto start1 = high_resolution_clock::now();
            stringConcatenation(myResult, s2);
            auto end1 = high_resolution_clock::now();

            auto duration1 = duration_cast<nanoseconds>(end1 - start1);

            char stlResult[200];
            strcpy(stlResult, s1);

            auto start2 = high_resolution_clock::now();
            strcat(stlResult, s2);
            auto end2 = high_resolution_clock::now();

            auto duration2 = duration_cast<nanoseconds>(end2 - start2);

            cout << "A2:\n";
            cout << "Concatenated string = " << myResult << endl;
            cout << "Execution time: " << duration1.count()
                 << " nanoseconds\n";

            cout << "STL strcat():\n";
            cout << "Concatenated string = " << stlResult << endl;
            cout << "Execution time: " << duration2.count()
                 << " nanoseconds\n";

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

            char result1[200];

            auto start1 = high_resolution_clock::now();
            substring(s, ip, len, result1);
            auto end1 = high_resolution_clock::now();

            auto duration1 = duration_cast<nanoseconds>(end1 - start1);

            string str(s);

            auto start2 = high_resolution_clock::now();
            string result2 = str.substr(ip, len);
            auto end2 = high_resolution_clock::now();

            auto duration2 = duration_cast<nanoseconds>(end2 - start2);

            cout << "A3:\n";
            cout << "Substring = " << result1 << endl;
            cout << "Execution time: " << duration1.count()
                 << " nanoseconds\n";

            cout << "STL substr():\n";
            cout << "Substring = " << result2 << endl;
            cout << "Execution time: " << duration2.count()
                 << " nanoseconds\n";

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

            auto start1 = high_resolution_clock::now();
            int found = index(T, P);
            auto end1 = high_resolution_clock::now();

            auto duration1 = duration_cast<nanoseconds>(end1 - start1);

            string text(T);
            string pattern(P);

            auto start2 = high_resolution_clock::now();
            size_t stlFound = text.find(pattern);
            auto end2 = high_resolution_clock::now();

            auto duration2 = duration_cast<nanoseconds>(end2 - start2);

            cout << "A4:\n";

            if (found != -1)
                cout << "Pattern found at position: " << found << endl;
            else
                cout << "Pattern not found." << endl;

            cout << "Execution time: " << duration1.count()
                 << " nanoseconds\n";

            cout << "STL find():\n";

            if (stlFound != string::npos)
                cout << "Pattern found at position: " << stlFound << endl;
            else
                cout << "Pattern not found." << endl;

            cout << "Execution time: " << duration2.count()
                 << " nanoseconds\n";

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