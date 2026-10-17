#include <iostream>
using namespace std;

int BinSearch(int data[], int size,  int element)
{
    int beg = 0;
    int end = size - 1;
    int mid = int((beg + end) / 2);
    while (beg <= end && data[mid] != element)
    {
        if (element < data[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
        mid = int(beg + end / 2);
    }
    int location =  -1;
    if (data[mid] == element)
    {
        location = mid;
    }
    
    return location;
}

int main()
{
    int data[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    int size = sizeof(data) / sizeof(data[0]);
    int target = 23;

    int result = BinSearch(data, size, target);

    if (result != -1)
    {
        cout << "Element " << target << " found at index: " << result << endl;
    }
    else
    {
        cout << "Element " << target << " not found." << endl;
    }

    return 0;
}
