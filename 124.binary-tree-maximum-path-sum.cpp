/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

    // return the max sum of the path that starts from root
    // it can be 0 if the path is negative
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        maxSum = max(maxSum, root->val + left + right);
        return max(0, root->val + max(left, right));
    }
};
// @lc code=end

