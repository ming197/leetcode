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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *cur = root;
        stack<TreeNode*> stk;
        while (cur || !stk.empty()){
            // go to the leftmost node
            while (cur){
                stk.push(cur);
                cur = cur->left;
            }

            // pop the leftmost node
            cur = stk.top();
            stk.pop();
            // if k is 1, return the value
            if (--k == 0) return cur->val;

            // go to the right node
            cur = cur->right;
        }
        return -1;
    }
};
// @lc code=end

