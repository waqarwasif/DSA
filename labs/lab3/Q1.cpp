#include <iostream>
using namespace std;

int **matMul(int **A, int **B, int n)
{
    int **C = new int *[n];

    for (int i = 0; i < n; i++)
        C[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main()
{
    int n;

    cout << "Enter the size of matrices: ";
    cin >> n;

    int **A = new int *[n];
    int **B = new int *[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
    }

    cout << "Enter elements of Matrix A:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    int **C = matMul(A, B, n);

    cout << "Product of matrices:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " " << C[i][j];
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}