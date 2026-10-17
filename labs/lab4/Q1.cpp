#include <iostream>

using namespace std;

void storeLowerTriangular(int** A, int* U, int n) {
    int i = 0;
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k <= j; ++k) {
            U[i] = A[j][k];
            i++;
        }
    }
}

void retrieveLowerTriangular(int* U, int** A, int n) {
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            if (k > j) {
                A[j][k] = 0;
            } else {
                A[j][k] = U[(j * (j + 1)) / 2 + k];
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
    int n = 4;
    
    int** original = new int*[n];
    for (int i = 0; i < n; ++i) {
        original[i] = new int[n];
    }
    
    int tempOriginal[4][4] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            original[i][j] = tempOriginal[i][j];
        }
    }
    
    int size = n * (n + 1) / 2;
    int* U = new int[size];
    
    storeLowerTriangular(original, U, n);
    
    cout << "Stored 1D Array U:\n";
    for (int i = 0; i < size; ++i) {
        cout << U[i] << " ";
    }
    cout << "\n\n";
    
    int** retrieved = new int*[n];
    for (int i = 0; i < n; ++i) {
        retrieved[i] = new int[n];
    }
    
    retrieveLowerTriangular(U, retrieved, n);
    
    cout << "Retrieved Matrix A:\n";
    printMatrix(retrieved, n);
    
    for (int i = 0; i < n; ++i) {
        delete[] original[i];
        delete[] retrieved[i];
    }
    delete[] original;
    delete[] retrieved;
    delete[] U;
    
    return 0;
}
