/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> old2new;
        Node *node = head;
        while (node) {
            old2new[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while (node) {
            if (node->next)
            {
                old2new[node]->next = old2new[node->next];
            }
            if (node->random)
            {
                old2new[node]->random = old2new[node->random];
            }
            node = node->next;
        }
        return old2new[head];
    }
};

int main() {
    Solution sol;
    Node* head = new Node(7);
    sol.copyRandomList(head);
}
// @lc code=end

