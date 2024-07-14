/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        auto [sum, depth] = Recursion(root);
        return accumulate(sum.begin(), sum.end(), 0);
    }
    pair<vector<int>, vector<int>> Recursion(TreeNode* root) {
        if (!root) {
            return make_pair(vector<int>{}, vector<int>{});
        }
        if (!root->left && !root->right) {
            return make_pair(vector<int>{root->val}, vector<int>{1});
        }
        auto [leftSum, leftDepth] = Recursion(root->left);
        auto [rightSum, rightDepth] = Recursion(root->right);
        vector<int> sum;
        vector<int> depth;
        for (int i = 0; i < leftSum.size(); i++) {
            sum.push_back(leftSum[i] + root->val * pow(10, leftDepth[i]));
            depth.push_back(leftDepth[i] + 1);
        }
        for (int i = 0; i < rightSum.size(); i++) {
            sum.push_back(rightSum[i] + root->val * pow(10, rightDepth[i]));
            depth.push_back(rightDepth[i] + 1);
        }
        return make_pair(sum, depth);
    }
};

class Solution {
private:
    int totalSum = 0;

    void findSum(TreeNode* root, int currNum) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr)
            totalSum += (currNum * 10 + root->val);
        // update the current number by adding the current node's value
        currNum = currNum * 10 + root->val;
        findSum(root->left, currNum);
        findSum(root->right, currNum);
    }

public:
    int sumNumbers(TreeNode* root) {
        findSum(root, 0);
        return totalSum;
    }
};
// @lc code=end

