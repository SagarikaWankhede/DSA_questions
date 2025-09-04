#include <iostream>
using namespace std;
#define MAX 5   
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == MAX - 1);
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }
};
int main() {
    Stack s;
    int choice, value;
    do {
        cout << "\n---- Stack Menu ----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if (s.isEmpty())
                    cout << "Stack is Empty." << endl;
                else
                    cout << "Stack is not Empty." << endl;
                break;
            case 4:
                if (s.isFull())
                    cout << "Stack is Full." << endl;
                else
                    cout << "Stack is not Full." << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
