#include <iostream>
#include <cmath>

using namespace std;

void retrieveTridiagonal(int* U, int** B, int n) {
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            if (abs(j - k) <= 1) {
                B[j][k] = U[2 * j + k];
            } else {
                B[j][k] = 0;
            }
        }
    }
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int n = 5;
    int size = 3 * n - 2;
    
    int tempU[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4};
    int* U = new int[size];
    for (int i = 0; i < size; ++i) {
        U[i] = tempU[i];
    }
    
    int** B = new int*[n];
    for (int i = 0; i < n; ++i) {
        B[i] = new int[n];
    }
    
    retrieveTridiagonal(U, B, n);
    
    cout << "Retrieved Tridiagonal Matrix B:\n";
    printMatrix(B, n);
    
    for (int i = 0; i < n; ++i) {
        delete[] B[i];
    }
    delete[] B;
    delete[] U;
    
    return 0;
}
