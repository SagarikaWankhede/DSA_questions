#include <iostream>
using namespace std;

// Binary Search function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;  // element found
        }
        else if (arr[mid] < key) {
            low = mid + 1;  // search in right half
        }
        else {
            high = mid - 1; // search in left half
        }
    }
    return -1; // element not found
}

int main() {
    int n, key;
    cout << "Enter size of sorted array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at position " << result + 1 << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
