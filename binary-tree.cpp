#include <iostream>
#include <queue>
using namespace std;
class Node{
  public:
  int data;
  Node*left;
  Node*right;
  Node(int d){
    data=d;
    left=NULL;
    right=NULL;
  }
};

Node* buildtree(){
  Node *rootNode = new Node(10);

  // cout<<"General tree created is as follows:"<<endl;
  // cout<<"\t\t\t "<<rootNode->data<<endl;
  // cout<<"\t\t\t "<<"/ "<<"\\"<<endl; 
  rootNode->left        = new Node(20); 
  rootNode->right       = new Node(30); 
  // cout<<"\t\t\t"<<rootNode->left->data<<"  "<<rootNode->right->data;
  // cout<<endl; 
  rootNode->left->left  = new Node(40); 
  rootNode->left->right = new Node(50);
  rootNode->right->left = new Node(60);
  rootNode->right->right = new Node(70);

  // cout<<"\t\t\t"<<"/"<<endl;
  // cout<<"\t\t      "<<rootNode->left->left->data;
  // cout << endl;
  return rootNode;
}

void printDFS(Node*root){
  if(root==NULL){
    return;
  }
  
  cout<<root->data<<" ";
  printDFS(root->left);
  printDFS(root->right);
}

void printBFS(Node * root) {
  if(root == nullptr) return;

  queue<Node *> q;
  q.push(root);
  while(!q.empty()) {
    Node *front = q.front();
    q.pop();
    cout << front->data << " ";

    if(front->left != nullptr) 
      q.push(front->left);
    
    if(front->right != nullptr) 
      q.push(front->right);
  }
}

int main() {
    Node *root = buildtree();
    if(root) {
        cout << "DFS: ";
        printDFS(root);

        cout << endl << "BFS: ";
        printBFS(root);
    }
    cout << endl;
    return 0;
    
}