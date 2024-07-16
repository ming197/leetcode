/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    bool flag1 = false, flag2 = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        DFS(root, p, path1, flag1);
        DFS(root, q, path2, flag2);
        TreeNode* last_node = nullptr;
        int i = 0;
        while (i < min(path1.size(), path2.size()) && path1[i] == path2[i]) {
            last_node = path1[i];
            ++i;
        }
        return last_node;
    }

    // backtrack to record the path
    void DFS(TreeNode* root, TreeNode* node, vector<TreeNode*> &path, bool &flag) {
        if (root == nullptr || flag) return;
        if (root == node) {
            flag = true;
            path.emplace_back(root);
            return;
        }
        path.emplace_back(root);
        DFS(root->left, node, path, flag);
        DFS(root->right, node, path, flag);
        // if flag is true, it means find the node in the above 2 DFS
        // then we cannot pop back the last node
        if (!flag) path.pop_back();
    }
};
// @lc code=end

