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

void findMiddle() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element is: " << slow->data << endl;
}

int main() {
    insert(5); insert(4); insert(3); insert(2); insert(1);
    findMiddle();
    return 0;
}
