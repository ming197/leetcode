/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        int delta = 1;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                tmp.push_back(q.front()->val);
                if (q.front()->left) {
                    q.push_back(q.front()->left);
                }
                if (q.front()->right) {
                    q.push_back(q.front()->right);
                }
                q.pop_front();
            }
            if (delta == -1) {
                reverse(tmp.begin(), tmp.end());
            }
            delta *= -1;
            result.push_back(tmp);
        }
        return result;
    }
};
// @lc code=end

