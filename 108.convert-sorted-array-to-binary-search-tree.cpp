/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
#include "bits/stdc++.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // edge case for DFS
        if (nums.size() == 0) return nullptr;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        int half = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[half]);
        vector<int> left(half, 0);
        std::copy(nums.begin(), nums.begin() + half, left.begin());
        vector<int> right(nums.size() - half - 1, 0);
        std::copy(nums.begin() + half + 1, nums.end(), right.begin());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
// @lc code=end

