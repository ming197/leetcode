/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
class Solution {
public:
    void flatten(TreeNode* root) {
        DFS(root);
    }
    // return the last node of the flatten tree
    TreeNode* DFS(TreeNode* root) {
        if (!root) return root;
        TreeNode *left = DFS(root->left);
        TreeNode *right = DFS(root->right);
        if (left) {
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return right ? right : (left ? left : root);
    }
};
// @lc code=end

