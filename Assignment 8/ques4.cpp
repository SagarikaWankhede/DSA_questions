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
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;
    if (root->data < minVal || root->data > maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, maxVal);
}
bool isBST(Node* root) {
    return isBSTUtil(root, -100000, 100000);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    if (isBST(root))
        cout << "Tree is a BST";
    else
        cout << "Tree is NOT a BST";
    return 0;
}
