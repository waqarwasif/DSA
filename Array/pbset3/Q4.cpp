#include<iostream>
using namespace std;

int arrayrev (int *A,int n){
    int temp;
    int start = 0;
    int end = n-1;
    for(int i=0;i<n;i++){
        if(end==start){
            return 0;
        }
        temp = A[start];
        A[start] = A[end];
        A[end]= temp;
        start++;
        end--;
    }

}

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int A[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    arrayrev(A, n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
