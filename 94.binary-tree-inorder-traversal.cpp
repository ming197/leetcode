/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            // push all the left nodes into the stack
            // DFS(left)
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            // pop the top node from the stack
            // push the root->val into the result
            cur = stk.top();
            res.push_back(cur->val);
            stk.pop();
            // DFS(right)
            cur = cur->right;
        }
        return res;
    }
};
// @lc code=end

