#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertBeforeValue(int value, int before) {
    if (head == NULL) return;
    if (head->data == before) {
        insertAtBeginning(value);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != before)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Value not found.\n";
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int value) {
    if (head == NULL) return;
    if (head->data == value) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Value not found.\n";
        return;
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found.\n";
}

void display() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, before;
    while (true) {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert Before a Value\n4.Delete from Beginning\n5.Delete from End\n6.Delete Specific Node\n7.Search\n8.Display\n0.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; insertAtBeginning(value); break;
            case 2: cout << "Enter value: "; cin >> value; insertAtEnd(value); break;
            case 3: cout << "Enter value and before which value: "; cin >> value >> before; insertBeforeValue(value, before); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: cout << "Enter value to delete: "; cin >> value; deleteSpecific(value); break;
            case 7: cout << "Enter value to search: "; cin >> value; search(value); break;
            case 8: display(); break;
            case 0: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
