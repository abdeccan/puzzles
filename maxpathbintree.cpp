#include <iostream>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int data;
};

// logic: path between any two nodes can either pass through it to parent node or can
// be the path via itself from its left child to right child. we need to choose the best
// possible. Note how we are ignoring the negative paths returned from child nodes.
// NOTE: for path between 2 leaf nodes, we need to tweak the above condition that we can
// ignore the negative values returned by child nodes!
int getPathAny(Node *node, int &out) {
    // base condition
    if (node == nullptr) return 0;

    // hypothesis
    int left = getPathAny(node->left, out);
    int right = getPathAny(node->right, out);

    // induction
    out = max(out, node->data + left + right);
    
    // logic: path between any nodes is node->data + max of left or right
    return node->data + max(left, right);
}

int getMaxPathAny(Node *root) {
    int path = INT_MIN;
    
    // call the solve function recursively
    getPathAny(root, path);

    return path;
}

int main() {
    cout << "Maximum path sum between 2 nodes in binary tree" << endl;

    Node *root = new Node();
    root->data = -10;
    root->left = nullptr;
    root->right = nullptr;

    Node *newRtNode = new Node();    
    newRtNode->data = 20;
    newRtNode->left = nullptr;
    newRtNode->right = nullptr;

    Node *newLftNode = new Node();
    newLftNode->data = 9;
    newLftNode->left = nullptr;
    newLftNode->right = nullptr;

    root->right = newRtNode;
    root->left = newLftNode;

    newRtNode->left = new Node();
    newRtNode->left->data = 15;
    newRtNode->left->left =  nullptr;
    newRtNode->left->right =  nullptr;

    newRtNode->right = new Node();
    newRtNode->right->data = 7;
    newRtNode->right->left =  nullptr;
    newRtNode->right->right =  nullptr;

    int maxSum = getMaxPathAny(root);
    cout << "Max path between any 2 nodes is " << maxSum << endl;
    
    return 0;
}