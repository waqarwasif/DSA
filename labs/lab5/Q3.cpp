#include <iostream>
#include <vector>

using namespace std;

bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void modifiedBinarySearch(vector<int>& data, int item) {
    int beg = 0;
    int end = data.size() - 1;
    int mid = 0;

    while (beg <= end) {
        mid = beg + (end - beg) / 2;

        if (data[mid] == item) {
            cout << "Item found at index " << mid << "\n";
            return;
        }
        if (item < data[mid]) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    // Item not found. 'beg' will be the correct index to insert the item
    // to keep the array sorted.
    cout << "Item not found. Inserting " << item << " into the array.\n";
    data.insert(data.begin() + beg, item);
}

void printArray(const vector<int>& data) {
    cout << "Array contents: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the initial number of elements: ";
    cin >> n;

    vector<int> data(n);
    bool valid = false;

    while (!valid) {
        cout << "Enter " << n << " sorted elements:\n";
        for (int i = 0; i < n; ++i) {
            cin >> data[i];
        }

        if (isSorted(data)) {
            valid = true;
        } else {
            cout << "The data entered is not sorted. Please try again.\n";
        }
    }

    char choice;
    do {
        int item;
        cout << "Enter an item to search for: ";
        cin >> item;

        modifiedBinarySearch(data, item);
        printArray(data);

        cout << "Do you want to search for another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
