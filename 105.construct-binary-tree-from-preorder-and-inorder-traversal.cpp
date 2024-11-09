/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) return nullptr;
        int root_val = preorder[pre_start];
        int root_index = in_start;
        // find the root index in inorder
        while (inorder[root_index] != root_val) root_index++;
        int left_size = root_index - in_start;
        TreeNode *root = new TreeNode(root_val);
        root->left = buildTree(preorder, inorder, pre_start + 1, pre_start + left_size, in_start, root_index - 1);
        root->right = buildTree(preorder, inorder, pre_start + left_size + 1, pre_end, root_index + 1, in_end);
        return root;
    }
};
// @lc code=end

