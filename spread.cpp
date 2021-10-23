#include <iostream>
#include <string>
using namespace std;

/*
 Given a binary tree, assume when there is a node infected with virus, it takes "K" units
 of time to spread to all its connected edges (both parent and child nodes connected to 
 this infected node). For any given binary tree and reference to an infected node, find 
 out what is the minimum time it takes for entire tree to get infected.
*/

typedef struct Tree {

    string name;
    Tree *left;
    Tree *right;
    Tree *parent;
};

static const unsigned int k = 1;

int main() {
    // you can write to stdout for debugging purposes, e.g.
    std::cout << "This is a debug message" << std::endl;

    return 0;
}

/*
    TODO: remove root?
*/
int getMaxDistanceDown(Tree *root, Tree *city, int &distance) {

    if(city == nullptr || root == nullptr) {
        return 0;
    }

    int leftDist = getMaxDistanceDown(root,city->left, distance);
    int rightDist = getMaxDistanceDown(root,city->right, distance);

    return distance + max(leftDist, rightDist) + k;
}

/*
    helper method for recursion
*/
int getMaxPath(Tree *root, Tree *city, int& distance) {
    if(root == nullptr || city == nullptr) {
        return 0;
    }

    int leftDist = getMaxPath(root, city->left, distance);
    int rightDist = getMaxPath(root, city->right, distance);
    int upDist =   getMaxPath(root, city->parent, distance); // root may not be longest

    distance = max(upDist, max(leftDist, rightDist));

    return distance + leftDist + rightDist + k;
}

int getMaxDistanceOut(Tree *root, Tree *city) {
    if(root == nullptr || city == nullptr) {
        return 0;
    }

    int distance = 0;
    getMaxPath(root, city, distance);
    return distance;
}

/*
    this is the tree of cities
*/
int getMinTime(Tree *root, Tree *city) {

    // sanity testing 
    // TODO: add more conditions?
    if(root == nullptr || city == nullptr) {
        return 0;
    }
    // logic: split the problem into two parts - 
        // 1. find the distance to the farthest leaf node in subtree beneath this node
        // 2. find the distance to the farthest node in the rest of the tree from this node
        // 3. max of above two times - because infection propagates simultaneously

        int outDist = getMaxDistanceOut(root, city);

        int distance = 0;
        int downDist = getMaxDistanceDown(root, city, distance);

        return max(outDist, downDist);
}



