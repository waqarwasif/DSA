#include<iostream>
using namespace std;

int ra,rb,ca,cb;
int **matMUL(int **A, int **B)
{
    if(ca!=rb){
        cout<<"Matrix multiplication not possible"<<endl;
        return 0;
    }
    int **C = new int*[ra];
    
    for(int i = 0; i < ra; i++)
        C[i] = new int[cb];

    for(int i=0;i<ra;i++){
        for(int j=0;j<cb;j++){
            C[i][j]= 0;
            for(int k=0;k<ca;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for(int i=0;i<ra;i++){
        for(int j=0;j<cb;j++){
            cout<<" "<<C[i][j];
        }
        cout<<endl;
    }
    for (int i = 0; i < ra; i++)
        delete[] C[i];

    delete[] C;
}

int main()
{
    cout << "Enter rows and columns of Matrix A: ";
    cin >> ra >> ca;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> rb >> cb;

    int **A = new int *[ra];
    int **B = new int *[rb];

    for (int i = 0; i < ra; i++)
        A[i] = new int[ca];

    for (int i = 0; i < rb; i++)
        B[i] = new int[cb];

    cout << "Enter elements of Matrix A:" << endl;

    for (int i = 0; i < ra; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;

    for (int i = 0; i < rb; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            cin >> B[i][j];
        }
    }

    matMUL(A, B);

    for (int i = 0; i < ra; i++)
        delete[] A[i];

    for (int i = 0; i < rb; i++)
        delete[] B[i];

    delete[] A;
    delete[] B;

    return 0;
}
