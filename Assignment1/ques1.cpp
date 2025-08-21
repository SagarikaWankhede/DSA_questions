#include <iostream>
using namespace std;

#define MAX 100  

class ArrayOperations {
    int arr[MAX];
    int size;

public:
    ArrayOperations() {
        size = 0;
    }

    // 1. CREATE
    void create() {
        cout << "Enter the number of elements: ";
        cin >> size;
        if (size > MAX) {
            cout << "Size exceeds maximum limit!" << endl;
            size = 0;
            return;
        }
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // 2. DISPLAY
    void display() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        cout << "Array elements are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 3. INSERT
    void insert() {
        if (size == MAX) {
            cout << "Array is full, cannot insert!" << endl;
            return;
        }
        int pos, value;
        cout << "Enter position (1 to " << size + 1 << "): ";
        cin >> pos;
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        cout << "Enter value to insert: ";
        cin >> value;

        for (int i = size; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = value;
        size++;
        cout << "Element inserted successfully!" << endl;
    }

    // 4. DELETE
    void remove() {
        if (size == 0) {
            cout << "Array is empty, nothing to delete!" << endl;
            return;
        }
        int pos;
        cout << "Enter position (1 to " << size << "): ";
        cin >> pos;
        if (pos < 1 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        for (int i = pos - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted successfully!" << endl;
    }

    // 5. LINEAR SEARCH
    void linearSearch() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        int key;
        cout << "Enter element to search: ";
        cin >> key;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << i + 1 << endl;
                return;
            }
        }
        cout << "Element not found!" << endl;
    }
};

int main() {
    ArrayOperations obj;
    int choice;

    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: obj.create(); break;
        case 2: obj.display(); break;
        case 3: obj.insert(); break;
        case 4: obj.remove(); break;
        case 5: obj.linearSearch(); break;
        case 6: cout << "Exiting program..." << endl; break;
        default: cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 6);

    return 0;
}