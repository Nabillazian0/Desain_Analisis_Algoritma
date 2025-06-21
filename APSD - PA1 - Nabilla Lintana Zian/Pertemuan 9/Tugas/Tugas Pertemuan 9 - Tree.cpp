#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
};
 
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}
 
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
 
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int values[] = {12, 16, 20, 24, 32};
 
    for (int i = 0; i < 5; i++) {
        root = insertNode(root, values[i]);
    }

    cout << "Traversal Pre-order  : ";
    preOrder(root);
    cout << endl;

    cout << "Traversal In-order   : ";
    inOrder(root);
    cout << endl;

    cout << "Traversal Post-order : ";
    postOrder(root);
    cout << endl;

    return 0;
}

