//
//  main.cpp
//  edit_tree
//
//  Created by HorsonChan on 2020/3/7.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root);

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(5);
    TreeNode *root6 = new TreeNode(6);
    root->left = root2;
    root->right = root3;
    root2->left = root6;
    root3->left = root4;
    root3->right = root5;
    vector<vector<int>> reuslt = levelOrder(root);;
    return 0;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        queue<TreeNode *> recordq;
        vector<int> single;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            single.push_back(node->val);
            if (node -> left != NULL) {
                recordq.push(node->left);
            }
            if (node -> right != NULL) {
                recordq.push(node->right);
            }
        }
        result.push_back(single);
        single.clear();
        q = recordq;
    }
    return result;
}
