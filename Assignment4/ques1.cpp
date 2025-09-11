#include <iostream>
using namespace std;
#define SIZE 5   
class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    bool isFull() {
        return (rear == SIZE - 1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot insert " << x << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        cout << x << " inserted into the queue." << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Nothing to delete." << endl;
            return;
        }
        cout << arr[front] << " removed from the queue." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No front element." << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int choice, value;
    do {
        cout << "\n=== Queue Menu ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if (q.isEmpty())
                    cout << "Queue is EMPTY." << endl;
                else
                    cout << "Queue is NOT empty." << endl;
                break;
            case 6:
                if (q.isFull())
                    cout << "Queue is FULL." << endl;
                else
                    cout << "Queue is NOT full." << endl;
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
