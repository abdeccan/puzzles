#include <iostream>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int data;
};


int height(Node *node, int &out) {
    // base condition
    if (node == nullptr) return 0;

    // hypothesis
    int left = height(node->left, out);
    int right = height(node->right, out);

    // induction
    out = max(out, 1 + left + right);
    
    // logic: height of any node is 1 + max of left or right
    return 1 + max(left, right);
}

int getDiameter(Node *root) {
    int dia = INT_MIN;
    
    // call the solve function recursively
    height(root, dia);

    return dia;
}

int main() {
    cout << "Diameter of binary tree" << endl;

    Node *root = new Node();
    root->data = 1;
    root->left = nullptr;
    root->right = nullptr;

    Node *newRtNode = new Node();    
    newRtNode->data = 2;
    newRtNode->left = nullptr;
    newRtNode->right = nullptr;

    Node *newLftNode = new Node();
    newLftNode->data = 4;
    newLftNode->left = nullptr;
    newLftNode->right = nullptr;

    root->right = newRtNode;
    root->left = newLftNode;
    
    int dia = getDiameter(root);
    cout << "Diameter is " << dia << endl;

    return 0;
}