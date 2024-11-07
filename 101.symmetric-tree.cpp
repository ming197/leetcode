/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop_front();
                if (node)
                {
                    level.push_back(node->val);
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
                else
                {
                    level.push_back(-1000);
                }
            }
            int left = 0, right = level.size() - 1;
            while (left < right)
            {
                if (level[left] != level[right])
                {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
// @lc code=end

