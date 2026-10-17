#include <iostream>
using namespace std;

void transpose(int A[][100], int B[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[j][i] = A[i][j];
        }
    }
}

int main()
{
    int m, n;
    int A[100][100], B[100][100];

    cout << "Enter rows and columns of matrix: ";
    cin >> m >> n;

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    transpose(A, B, m, n);

    cout << "Transpose of matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}