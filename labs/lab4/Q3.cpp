#include <iostream>
#include <cmath>

using namespace std;

void storeTridiagonal(int** B, int* U, int n) {
    int i = 0;
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            if (abs(j - k) <= 1) {
                U[i] = B[j][k];
                i++;
            }
        }
    }
}

int main() {
    int n = 5;
    
    int** B = new int*[n];
    for (int i = 0; i < n; ++i) {
        B[i] = new int[n];
    }
    
    int tempB[5][5] = {
        {1, 2, 0, 0, 0},
        {3, 4, 5, 0, 0},
        {0, 6, 7, 8, 0},
        {0, 0, 9, 1, 2},
        {0, 0, 0, 3, 4}
    };
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B[i][j] = tempB[i][j];
        }
    }
    
    int size = 3 * n - 2;
    int* U = new int[size];
    
    storeTridiagonal(B, U, n);
    
    cout << "Stored 1D Array U:\n";
    for (int i = 0; i < size; ++i) {
        cout << U[i] << " ";
    }
    cout << "\n";
    
    for (int i = 0; i < n; ++i) {
        delete[] B[i];
    }
    delete[] B;
    delete[] U;
    
    return 0;
}
