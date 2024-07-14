/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        deque<Node*> q;
        q.push_back(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop_front();
                if (i < size - 1) {
                    node->next = q.front();
                }
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

