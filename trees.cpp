#include "nodes.h"

// Node constructor
Node::Node(int v) {
    data = v;
    left = nullptr;
    right = nullptr;
}

// Tree constructor
Tree::Tree() {
    root = nullptr;
}

// Destructor
Tree::~Tree() {
    destroy(root);
}

// Free all nodes
void Tree::destroy(Node* n) {
    if (n == nullptr)
        return;

    destroy(n->left);
    destroy(n->right);
    delete n;
}

// Insert a value
Node* Tree::insert(Node* n, int v) {
    if (n == nullptr)
        return new Node(v);

    if (v < n->data)
        n->left = insert(n->left, v);
    else if (v > n->data)
        n->right = insert(n->right, v);

    return n;
}

// Search for a value
bool Tree::search(Node* n, int v) {
    if (n == nullptr)
        return false;

    if (n->data == v)
        return true;

    if (v < n->data)
        return search(n->left, v);

    return search(n->right, v);
}

// Find the smallest value
Node* Tree::findMin(Node* n) {
    if (n == nullptr)
        return nullptr;

    while (n->left != nullptr)
        n = n->left;

    return n;
}

// Delete a node
Node* Tree::deleteNode(Node* n, int v) {
    if (n == nullptr)
        return nullptr;

    if (v < n->data) {
        n->left = deleteNode(n->left, v);
    }
    else if (v > n->data) {
        n->right = deleteNode(n->right, v);
    }
    else {
        // Case 1: Leaf node
        if (n->left == nullptr &&
            n->right == nullptr) {
            delete n;
            return nullptr;
        }

        // Case 2: One child
        if (n->left == nullptr) {
            Node* temp = n->right;
            delete n;
            return temp;
        }

        if (n->right == nullptr) {
            Node* temp = n->left;
            delete n;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(n->right);
        n->data = temp->data;
        n->right = deleteNode(n->right, temp->data);
    }

    return n;
}

// In-order: Left, Root, Right
void Tree::inOrder(Node* n) {
    if (n == nullptr)
        return;

    inOrder(n->left);
    cout << n->data << " ";
    inOrder(n->right);
}

// Pre-order: Root, Left, Right
void Tree::preOrder(Node* n) {
    if (n == nullptr)
        return;

    cout << n->data << " ";
    preOrder(n->left);
    preOrder(n->right);
}

// Calculate height in edges
int Tree::height(Node* n) {
    if (n == nullptr)
        return -1;

    int leftHeight = height(n->left);
    int rightHeight = height(n->right);

    return 1 + max(leftHeight, rightHeight);
}

// Level-order traversal
void Tree::levelOrder() {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}