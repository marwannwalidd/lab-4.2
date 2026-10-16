
#include <iostream>
#include "nodes.h"
using namespace std;

int main() {
    Tree t;

    // Insert values
    for (int v : {50, 30, 70, 20, 40, 60, 80, 10, 35})
        t.root = t.insert(t.root, v);

    // Traversals
    cout << "InOrder: ";
    t.inOrder(t.root);
    cout << endl;

    cout << "PreOrder: ";
    t.preOrder(t.root);
    cout << endl;

    // Height
    cout << "Height: " << t.height(t.root) << endl;

    // Search
    cout << "Search 35: " << t.search(t.root, 35) << endl;
    cout << "Search 99: " << t.search(t.root, 99) << endl;

    // Delete leaf
    t.root = t.deleteNode(t.root, 10);
    cout << "After del 10: ";
    t.inOrder(t.root);
    cout << endl;

    // Delete one-child node
    t.root = t.deleteNode(t.root, 20);
    cout << "After del 20: ";
    t.inOrder(t.root);
    cout << endl;

    // Delete node 30
    t.root = t.deleteNode(t.root, 30);
    cout << "After del 30: ";
    t.inOrder(t.root);
    cout << endl;

    // Level-order traversal
    cout << "LevelOrder: ";
    t.levelOrder();
    cout << endl;

    return 0;
}