#include <iostream>
using namespace std;
#define SIZE 5
int cq[SIZE];
int front = -1, rear = -1;
bool isEmpty() {
    return (front == -1);
}
bool isFull() {
    return ((rear + 1) % SIZE == front);
}
void enqueue(int x) {
    if (isFull()) {
        cout << "Queue is FULL!\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    cq[rear] = x;
    cout << x << " inserted.\n";
}
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!\n";
        return;
    }
    cout << cq[front] << " removed.\n";
    if (front == rear) {
        front = rear = -1; // queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}
void peek() {
    if (isEmpty()) cout << "Queue is EMPTY!\n";
    else cout << "Front element: " << cq[front] << "\n";
}
void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!\n";
        return;
    }
    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << "\n";
}
int main() {
    int choice, value;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; enqueue(value); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
