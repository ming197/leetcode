/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    // use stk to store the path from root to the leftmost node
    stack<TreeNode*> stk;
    int kthSmallest(TreeNode* root, int k) {
        initialize(root);
        int res;
        while (k > 0) {
            res = getNext();
            k--;
        }
        return res;
    }
    void partialInorder(TreeNode* root){
        while(root != nullptr){
            stk.push(root);
            root = root->left;
        }
    }
    void initialize(TreeNode* root) {
        partialInorder(root);
    }
    int getNext() {
        TreeNode* node = stk.top();
        stk.pop();
        partialInorder(node->right);
        return node->val;
    }
};
// @lc code=end

