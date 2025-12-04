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
Node* createNode(int data) {
    return new Node(data);   
}
void preorder(Node* root) {
    if (root == NULL)       
        return;
    cout << root->data << " "; 
    preorder(root->left);      
    preorder(root->right);     
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);        
    cout << root->data << " ";  
    inorder(root->right);       
}
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);       
    postorder(root->right);     
    cout << root->data << " ";   
}
int main() {
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    cout << "Preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Inorder: ";
    inorder(root);
    cout << "\n";
    cout << "Postorder: ";
    postorder(root);
    cout << "\n";
    return 0;
}
