#include <iostream>
using namespace std;

int main()
{
    int n;

    // Input array size
    cout << "Enter the number of elements: ";
    cin >> n;

    int *A = new int[n];

    // Input elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        int temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    delete[] A;

    return 0;
}