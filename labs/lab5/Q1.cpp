#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& data, int item) {
    int beg = 0;
    int end = data.size() - 1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;

        if (data[mid] == item) {
            return mid;
        }
        if (item < data[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> data(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    char choice;
    do {
        int item;
        cout << "Enter an item to search for: ";
        cin >> item;

        int result = binarySearch(data, item);

        if (result != -1) {
            cout << "Item found at index " << result << "\n";
        } else {
            cout << "Item not found in the array\n";
        }

        cout << "Do you want to search for another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
