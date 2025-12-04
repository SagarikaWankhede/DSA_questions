#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
Node* insert(Node* root, int value) {
    if (root == NULL)                          
        return new Node(value);
    if (value < root->data)                    
        root->left = insert(root->left, value);
    else if (value > root->data)              
        root->right = insert(root->right, value);
    return root;
}
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)     
        return root;
    if (key < root->data)                     
        return searchRecursive(root->left, key);
    else                                      
        return searchRecursive(root->right, key);
}
Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node* findMax(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}
Node* inorderSuccessor(Node* root, int key) {
    Node* succ = NULL;
    while (root != NULL) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}
Node* inorderPredecessor(Node* root, int key) {
    Node* pred = NULL;
    while (root != NULL) {
        if (key > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout << "Min: " << findMin(root)->data << endl;
    cout << "Max: " << findMax(root)->data << endl;
    Node* succ = inorderSuccessor(root, 40);
    if (succ) cout << "Successor of 40: " << succ->data << endl;
    Node* pred = inorderPredecessor(root, 40);
    if (pred) cout << "Predecessor of 40: " << pred->data << endl;
    return 0;
}
