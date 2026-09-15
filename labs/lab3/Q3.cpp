#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        data = new int *[rows];

        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }
    // Copy constructor
    Matrix(const Matrix &M)
    {
        rows = M.rows;
        cols = M.cols;

        data = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
                data[i][j] = M.data[i][j];
        }
    }

    void input()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }

    Matrix operator*(const Matrix &B)
    {
        if (cols != B.rows)
        {
            cout << "Matrix multiplication not possible" << endl;
            return Matrix(0, 0);
        }

        Matrix C(rows, B.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                C.data[i][j] = 0;

                for (int k = 0; k < cols; k++)
                {
                    C.data[i][j] += data[i][k] * B.data[k][j];
                }
            }
        }

        return C;
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];

        delete[] data;
    }
};

int main()
{
    int rA, cA, rB, cB;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> rA >> cA;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> rB >> cB;

    Matrix A(rA, cA);
    Matrix B(rB, cB);

    cout << "Enter elements of Matrix A:" << endl;
    A.input();

    cout << "Enter elements of Matrix B:" << endl;
    B.input();

    Matrix C = A * B;

    cout << "Product:" << endl;
    C.display();

    return 0;
}