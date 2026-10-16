
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int v);
};

// Tree class
class Tree {
public:
    Node* root;

    Tree();
    ~Tree();

    void destroy(Node* n);

    Node* insert(Node* n, int v);
    bool search(Node* n, int v);
    Node* findMin(Node* n);
    Node* deleteNode(Node* n, int v);

    void inOrder(Node* n);
    void preOrder(Node* n);
    int height(Node* n);
    void levelOrder();
};

#endif
