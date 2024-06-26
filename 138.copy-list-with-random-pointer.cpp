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
        Node* dummy_head = new Node(0);
        dummy_head->next = head;
        // copy the node
        // and insert the new node after the original node
        while (head)
        {
            Node* new_node = new Node(head->val);
            new_node->next = head->next;
            head->next = new_node;
            head = new_node->next;
        }
        head = dummy_head->next;
        // update the copied node's random pointer
        while (head)
        {
            if (head->random)
            {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        // separate the copied node from the original node
        // recover the original node's next pointer
        Node* previous_ptr = dummy_head;
        while (previous_ptr->next)
        {
            Node* original_node = previous_ptr->next;
            Node* copied_node = original_node->next;
            // 1. recover the original node's next pointer
            original_node->next = copied_node->next;
            // 2. update copied node's next pointer
            previous_ptr->next = copied_node;
            previous_ptr = copied_node;
        }
        return dummy_head->next;
    }
};

int main() {
    Solution sol;
    Node* head = new Node(7);
    sol.copyRandomList(head);
}
// @lc code=end

