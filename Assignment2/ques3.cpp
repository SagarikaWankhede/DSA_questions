#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;  
        }
    }
    return n;  
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[n - 1];
    cout << "Enter " << n - 1 << " sorted elements from 1 to " << n << ": ";
    for (int i = 0; i < n - 1; i++) cin >> arr[i];

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;

    return 0;
}
