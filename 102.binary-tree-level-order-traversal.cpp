/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            // initialize the size
            vector<int> level(size, 0);
            // iterate the level
            for (int i = 0; i < size; ++i) {
                auto *node = q.front();
                if (node->left) {
                    q.push_back(node->left);
                }
                if (node->right)
                {
                    q.push_back(node->right);
                }
                level[i] = node->val;
                q.pop_front();
            }
            res.emplace_back(level);
        }
        return res;
    }
};
// @lc code=end

