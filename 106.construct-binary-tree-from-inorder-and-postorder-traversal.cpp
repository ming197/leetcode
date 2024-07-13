/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end) {
        if (in_start > in_end) {
            return nullptr;
        }
        int root_val = postorder[post_end];
        int root_index = in_start;
        while (inorder[root_index] != root_val) {
            root_index++;
        }
        TreeNode *root = new TreeNode(root_val);
        int left_size = root_index - in_start;
        root->left = buildTree(inorder, in_start, root_index - 1, postorder, post_start, post_start + left_size - 1);
        root->right = buildTree(inorder, root_index + 1, in_end, postorder, post_start + left_size, post_end - 1);
        return root;
    }
};
// @lc code=end

