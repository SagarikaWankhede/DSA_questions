#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void countAndDelete(int key) {
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
            if (prev == NULL) {
                head = temp->next;
                delete temp;
                temp = head;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Occurrences deleted: " << count << endl;
}

int main() {
    insert(2); insert(3); insert(2); insert(4); insert(2);
    cout << "Original list:\n";
    display();

    int key;
    cout << "Enter value to delete all occurrences: ";
    cin >> key;
    countAndDelete(key);

    cout << "List after deletion:\n";
    display();
    return 0;
}
