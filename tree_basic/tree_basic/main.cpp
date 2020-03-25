//
//  main.cpp
//  tree_basic
//
//  Created by HorsonChan on 2020/3/7.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

class Node {
public:
    Node *left;
    Node *right;
    int data;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

void preOrderTree(Node *node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << endl;
    preOrderTree(node->left);
    preOrderTree(node->right);
}

void inOrderTree(Node *node) {
    if (node == NULL) {
        return;
    }
    inOrderTree(node->left);
    cout << node->data << endl;
    inOrderTree(node->right);
}

void postOrderTree(Node *node) {
    if (node == NULL) {
        return;
    }
    postOrderTree(node->left);
    postOrderTree(node->right);
    cout << node->data << endl;
}


