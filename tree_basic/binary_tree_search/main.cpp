//
//  main.cpp
//  binary_tree_search
//
//  Created by HorsonChan on 2020/3/7.
//  Copyright © 2020 Horson. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

TreeNode *searchBinaryTree(TreeNode *node, int value) {
    TreeNode *p = node;
    while (p != NULL) {
        if (p->val == value) {
            return p;
        } else if (p->val > value) {
            p = p -> left;
        } else {
            p = p -> right;
        }
    }
    return NULL;
}

//插入时把大于等于的都放在右树，所以查找时候大于等于目标值都往右树查，直到查到叶子节点
vector<TreeNode *> searchBinaryTreeIncludeSameValue(TreeNode *node, int value) {
    vector<TreeNode *> res;
    TreeNode *p = node;
    while (p != NULL) {
        if (value >= p->val) {
            if (p->val == value) {
                res.push_back(p);
            }
            p = p -> right;
        } else {
            p = p -> left;
        }
    }
    return res;
}

void insert(TreeNode *node, int value) {
    if (node == NULL) {
        node = new TreeNode(value);
        return;
    }
    TreeNode *p = node;
    while (p != NULL) {
        if (value > p->val) {
            if (p->right == NULL) {
                p->right = new TreeNode(value);
                return;
            }
            p = p->right;
        } else {
            if (p->left == NULL) {
                p->left = new TreeNode(value);
                return;
            }
            p = p->left;
            
        }
    }
}

void deleteNode(TreeNode *node, int value) {
    TreeNode *p = node;
    TreeNode *pp = NULL;
    //find target node
    while (p != NULL && p->val != value) {
        pp = p;
        if (p->val < value) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    if (p == NULL) return;
    
    //1.handle if the node has two child
    if (p->left != NULL && p->right != NULL) {
        TreeNode *minP = p->right;
        TreeNode *minPP = p;
        while (minP != NULL) {
            minPP = minP;
            minP = minP->left;
        }
        //replace value of the node need to be deleted
        p->val = minP->val;
        //so the node need to be deleted is minP now
        p = minP;
        pp = minPP;
    }
    
    //2.delete target node
    TreeNode *child;
    if (p->left == NULL) child = p->right;
    else child = p->left;
    
    //if target node is the root node
    if (pp == NULL) p = child;
    else if (p == pp->left) pp->left = child;
    else pp->right = child;
}

void deleteNodeIncludeSameNodes(TreeNode *node, int value) {
    TreeNode *p = node;
    TreeNode *pp = NULL;
    //find target node
    while (p != NULL && p->val != value) {
        pp = p;
        if (p->val < value) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    if (p == NULL) return;
    
    //detect same value and delete it
    TreeNode *dtP = p->right;
    TreeNode *dtPP = p;
    while (dtP != NULL) {
        if (value >= dtP->val) {
            if (value == dtP -> val) {
                TreeNode *child;
                if (dtP -> left != NULL) child = dtP -> left;
                else child = dtP -> right;
                if (dtPP -> left == dtP) dtPP -> left = child;
                else dtPP -> right = child;
                dtP = child;
            } else {
                dtPP = dtP;
                dtP = dtP->right;
            }
        } else {
            dtPP = dtP;
            dtP = dtP->left;
        }
    }
    
    //1.handle if the node has two child
    if (p->left != NULL && p->right != NULL) {
        TreeNode *minP = p->right;
        TreeNode *minPP = p;
        while (minP != NULL) {
            minPP = minP;
            minP = minP->left;
        }
        //replace value of the node need to be deleted
        p->val = minP->val;
        //so the node need to be deleted is minP now
        p = minP;
        pp = minPP;
    }
    
    //2.delete target node
    TreeNode *child;
    if (p->left == NULL) child = p->right;
    else child = p->left;
    
    //if target node is the root node
    if (pp == NULL) p = child;
    else if (p == pp->left) pp->left = child;
    else pp->right = child;
}
